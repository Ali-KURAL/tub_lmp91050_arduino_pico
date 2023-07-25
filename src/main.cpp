#include <Arduino.h>
#include "SPI.h"
#include "lmp91050.h"

#define PIN_SPI_TX  19
#define PIN_SPI_RX  16
#define PIN_SPI_SCK 18
#define PIN_SPI_CS  17

lmp91050 lmp;

void setup() {
    Serial.begin(9600);
    pinMode(LED_BUILTIN,OUTPUT);
    SPI.setTX(PIN_SPI_TX);
    SPI.setRX(PIN_SPI_RX);
    SPI.setSCK(PIN_SPI_SCK);
    lmp.begin(&SPI,PIN_SPI_CS);
    delay(5);
    lmp.writeDevConf(LMP_CONFIG_DEFAULT);
    delay(5);
    Serial.println("Configuration done");

}

void loop() {
    digitalWrite(LED_BUILTIN,HIGH);
    delay(200);
    digitalWrite(LED_BUILTIN,LOW);
    delay(200);
}