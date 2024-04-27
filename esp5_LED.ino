// ini merupakan cript mengirim angka ke esp32 melalui boletooth
// basis untuk kontrol robot beroda namun dapat diaplay untuk smarthome
#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
                int BTData;

                byte LED1 = 26; //IO 26
                byte LED2 = 27; //IO 27
                byte LED3 = 25; //IO 25
                byte LED4 = 33; //IO 33

                /* Check  Bluetooth configurations are enabled in the SDK */
                #if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
                #error // Bluetooth is not enabled! Please run `make menuconfig` to and enable it
                #endif

                void setup()
                {
                  Serial.begin(115200);
                  SerialBT.begin("ESP32 WROOM BOARD");
                  Serial.println("Bluetooth siap untuk di SAMBUNGKAN...");
                  pinMode(LED1, OUTPUT);
                  pinMode(LED2, OUTPUT);
                  pinMode(LED3, OUTPUT);
                  pinMode(LED4, OUTPUT);
                  pinMode(17, OUTPUT);
                }

                void loop()
                {
                  if(SerialBT.available())
                  {
BTData = SerialBT.read();
//Serial.write(BTData);
digitalWrite(17, HIGH);
Serial.println (BTData);
                  }

                  if (BTData == 48) {
// left start
digitalWrite(LED1, HIGH);
digitalWrite(LED2, LOW);
digitalWrite(LED3, LOW);
digitalWrite(LED4, HIGH);
                  } else if (BTData == 49) {
// left stop
digitalWrite(LED1, LOW);
digitalWrite(LED2, LOW);
digitalWrite(LED3, LOW);
digitalWrite(LED4, LOW);
                  } else if (BTData == 50) {
// forward start
digitalWrite(LED1, HIGH);
digitalWrite(LED2, LOW);
digitalWrite(LED3, HIGH);
digitalWrite(LED4, LOW);
                  } else if (BTData == 51) {
// forward stop
digitalWrite(LED1, LOW);
digitalWrite(LED2, LOW);
digitalWrite(LED3, LOW);
digitalWrite(LED4, LOW);
                  } else if (BTData == 52) {
// right start
digitalWrite(LED1, LOW);
digitalWrite(LED2, HIGH);
digitalWrite(LED3, HIGH);
digitalWrite(LED4, LOW);
                  } else if (BTData == 53) {
// right stop
digitalWrite(LED1, LOW);
digitalWrite(LED2, LOW);
digitalWrite(LED3, LOW);
digitalWrite(LED4, LOW);
                  } else if (BTData == 54) {
// backward start
digitalWrite(LED1, LOW);
digitalWrite(LED2, HIGH);
digitalWrite(LED3, LOW);
digitalWrite(LED4, HIGH);
                  } else if (BTData == 55) {
// backward stop
digitalWrite(LED1, LOW);
digitalWrite(LED2, LOW);
digitalWrite(LED3, LOW);
digitalWrite(LED4, LOW);
                  } else {
digitalWrite(25, LOW);
digitalWrite(26, LOW);
digitalWrite(14, LOW);
digitalWrite(12, LOW);
                  }
                }


