#include "mbed.h"
#include "BME280.h"

BME280 sensor(PB_9,   PB_8);
DigitalOut oled1(LED1);
//           (I2C_SDA, I2C_SCL, I2C_Address);
// change those pins with respect to your board

int main() {
    oled1 = 0;
    while(1) {
        oled1 = 0;
        printf(
            "%d degC, %d hPa, %d %%\n",
            (int)sensor.getTemperature(),
            (int)sensor.getPressure(),
            (int)sensor.getHumidity()
            );
        if ((int)sensor.getHumidity() > 30)
        {
            oled1 = 1;
        }
        wait_us(2000000);

    }
}
