#include <SoftwareSerial.h>

SoftwareSerial bluetooth(10, 11); 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bluetooth.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()){    
    char r = Serial.read();
    bluetooth.print(r); 
    Serial.println("Serial command: " + r);
  } 

  if(bluetooth.available()){
     bluetooth.print("Disponivel");
     char r = bluetooth.read();
     Serial.print(r);
   }

}
