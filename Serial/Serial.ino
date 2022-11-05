#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2, 3); //RX | TX
int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()){    
    char r = Serial.read();
    Serial.println(r);
    if (r == 'C'){
      digitalWrite(ledPin, HIGH);
     }
     if (r =='D'){
      digitalWrite(ledPin, LOW);
     }
    bluetooth.print(r);     
  } 

  if(bluetooth.available()){
     char r = bluetooth.read();
     Serial.print(r);
     if (r == 'A'){
      digitalWrite(ledPin, HIGH);
     }
     if (r =='B'){
      digitalWrite(ledPin, LOW);
     }
   }

}
