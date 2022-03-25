#include "DigitalOut.h"
#include "PinNameAliases.h"
#include "PinNamesTypes.h"
#include "ThisThread.h"
#include "mbed.h"
#include "pinmap.h"
#include <cstdio>
#include "mbed.h"

DigitalOut testled(PC_7);
DigitalOut testled2(PB_6);

typedef struct {
uint32_t counter;
int SBEU;
int SBEU2;
} message_t;
/*здесь используется объект класса MemoryPool, для определения и
управления пулом памяти фиксированного размера, информацию об этом
классе изучите в документации */
MemoryPool<message_t, 16> mpool;
Queue<message_t, 16> queue;
Thread thread;
/* поток отправитель */
void send_thread(void)
{
uint32_t i = 0;
while (true) {

testled = !testled;

i++; /* так как настоящие данные брать неоткуда здесь они
генерируются*/
if (i % 3 == 0)
testled2 = !testled2;
message_t *message = mpool.alloc();
message->counter = i;
message->SBEU = testled;
message->SBEU2 = testled2;


ThisThread::sleep_for(1s);


queue.put(message);
ThisThread::sleep_for(1000);
}
}

int main(void)
{
thread.start(callback(send_thread));
while (true) {
osEvent evt = queue.get();
if (evt.status == osEventMessage) {
message_t *message = (message_t *)evt.value.p;
mpool.free(message);

testled = message->SBEU;
testled2 = message->SBEU2;
}

//oled1 = !oled1; // Включение/выключение светодиода
ThisThread::sleep_for(1s);

}
}