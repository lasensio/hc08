#include <SoftwareSerial.h>

SoftwareSerial bluetooth(0, 1); //RX | TX

int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (bluetooth.available()){
    //Serial.write(bluetooth.read());
    char r = bluetooth.read();
    Serial.write(r);
    if (r == '0')
      digitalWrite(ledPin, HIGH);      
    if (r == '1')
      digitalWrite(ledPin, LOW);     
  }
    

  if (Serial.available())
    bluetooth.write(Serial.read());

}
