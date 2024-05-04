// ini merupakan cript mengirim angka ke esp32 melalui boletooth
// basis untuk kontrol robot beroda namun dapat diaplay untuk smarthome
#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
#include <MQ2.h>
 int BTData;
 int pinAout = 12; // pin MQ2
 int lpg_gas, co_gas, smoke_gas;
 int buzzer = 12;
  int led = 14;
  MQ2 mq2(pinAout);

  int LED1 = 26; //IO 26
  int LED2 = 27; //IO 27
  int LED3 = 25; //IO 25
  int LED4 = 33; //IO 33

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
     Serial.begin(115200);
     pinMode(buzzer,OUTPUT);
       pinMode(led,OUTPUT);
       mq2.begin();
       pinMode(LED2, OUTPUT);
       pinMode(LED3, OUTPUT);
       pinMode(LED4, OUTPUT);
       pinMode(17, OUTPUT);
         }

 void loop() {
float* values= mq2.read(true); //jika diset "false" tidak akan dimunculkan di serial monitor
  lpg_gas = mq2.readLPG();
  co_gas = mq2.readCO();
  smoke_gas = mq2.readSmoke();
  Serial.println (lpg_gas);
  Serial.println (co_gas);
  Serial.println (smoke_gas);

  SerialBT.print("LPG =   ");
SerialBT.println(co_gas);

  SerialBT.print("co_gas =  ");
SerialBT.println(co_gas);

  SerialBT.print("Smoke_gas=  ");
SerialBT.println(co_gas);

  digitalWrite(led,LOW);

  if(SerialBT.available())
   {
BTData = SerialBT.read();
//Serial.write(BTData);
digitalWrite(17, HIGH);
Serial.println (BTData);
Serial.println (BTData);

}

if (BTData == 48) {
digitalWrite(LED1, HIGH); // perangkat 1 On
} else if (BTData == 49) {
digitalWrite(LED1, LOW);
} 

else if (BTData == 50) {
digitalWrite(LED2, HIGH);
} else if (BTData == 51) {
digitalWrite(LED2, LOW);
} 

else if (BTData == 52) {
digitalWrite(LED3, HIGH);
 } else if (BTData == 53) {
digitalWrite(LED3, LOW);
} 

else if (BTData == 54) {
digitalWrite(LED4, HIGH);
} else if (BTData == 55) {
digitalWrite(LED4, LOW);
 } 

if (lpg_gas<=140){
  digitalWrite(buzzer, LOW);
  digitalWrite(led, LOW);
}

else if (lpg_gas==0.00){
  digitalWrite(buzzer, LOW);
  digitalWrite(led, LOW);

}
else if (lpg_gas>=150){
  digitalWrite(buzzer, HIGH);
  digitalWrite(led, HIGH);
     // delay(1500);
}
// else {
// digitalWrite(buzzer,LOW);
// digitalWrite(led,LOW);
// digitalWrite(25, LOW);
// digitalWrite(26, LOW);
// digitalWrite(14, LOW);
// digitalWrite(12, LOW);
// }
}


