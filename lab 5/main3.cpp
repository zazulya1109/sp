/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */


#include "DigitalOut.h"
#include "PinNameAliases.h"
#include "PinNamesTypes.h"
#include "ThisThread.h"
#include "mbed.h"
#include "pinmap.h"
#include <cstdio>
#define FLAG 2

DigitalOut oled1(LED1);
DigitalOut testled(PC_7);
// Задержка, 1 секунда == 1000 мс
Thread thread;

int main()
{
testled = 1;
//thread.start(print_term);
ThisThread::sleep_for(5s);
// Задаем потоку значение флага PRINT_FLAG
thread.flags_set(FLAG);
while (true) {
oled1 = !oled1;
testled = !testled; // Включение/выключение светодиода
ThisThread::sleep_for(1s);
}
}
