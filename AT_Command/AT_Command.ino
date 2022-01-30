#include <SoftwareSerial.h>

SoftwareSerial bluetooth(10, 11); //RX | TX

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  bluetooth.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (bluetooth.available()){
    Serial.write(bluetooth.read());
     
  }    

  if (Serial.available())
    bluetooth.write(Serial.read());

}
