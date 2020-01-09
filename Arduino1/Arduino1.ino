//Team #39
//
//Olesia Danchuk - odanch2 - odanch2@uic.edu
//Narangoo Vanchin - nvanch2 - nvanch2@uic.edu
//Mateusz Sagula - msagul2 - msagul2@uic.edu
//
//Musical Instrument
//
//For this project we are going to build mini piano by using arduino. With this device, you press on 
//the capacitive sensor and buzzer will play a note, (we will have seven buttons for each note in a key) 
//and an IR remote that will allow you to customize the sounds available on the keyboard.
//
//Problems:
//1) One of the LEDs is not working
//2) Middle line in the seven segment display is not working(the dot is displaying instead)


// Import the CapacitiveSensor Library.
#include <CapacitiveSensor.h>
#include <Wire.h>

// Set the Send Pin & Receive Pin.
CapacitiveSensor   cs_2_3 = CapacitiveSensor(2,3);        
CapacitiveSensor   cs_2_4 = CapacitiveSensor(2,4);         
CapacitiveSensor   cs_2_5 = CapacitiveSensor(2,5);     
CapacitiveSensor   cs_2_6 = CapacitiveSensor(2,6);     
CapacitiveSensor   cs_2_7 = CapacitiveSensor(2,7);      
CapacitiveSensor   cs_2_8 = CapacitiveSensor(2,8);         
CapacitiveSensor   cs_2_9 = CapacitiveSensor(2,9);  

int led1 = 10;
int led2 = 11;
int led3 = 12;
int led4 = 13;
int led5 = A0;
int led6 = A1;
int led7 = A2;

void setup()                    
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);

  Wire.begin();
  
  cs_2_3.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  
  // Arduino start communicate with computer.
  Serial.begin(9600);
}

void loop()                    
{
  
  // Set a timer.
  long start = millis();
  
  // Set the sensitivity of the sensors.
  long total1 =  cs_2_3.capacitiveSensor(3000);
  long total2 =  cs_2_4.capacitiveSensor(3000);
  long total3 =  cs_2_5.capacitiveSensor(3000);
  long total4 =  cs_2_6.capacitiveSensor(3000);
  long total5 =  cs_2_7.capacitiveSensor(3000);
  long total6 =  cs_2_8.capacitiveSensor(3000);
  long total7 =  cs_2_9.capacitiveSensor(3000);  

  // I set a threshold for it, so that the sensor won't be too sensitive.
  if (total1 > 800){
    Wire.beginTransmission(9);
    Wire.write(15);
    Wire.endTransmission();
    digitalWrite(led1, HIGH);
  }
  else digitalWrite(led1, LOW);
  if (total2 > 800){
    Wire.beginTransmission(9);
    Wire.write(16);
    Wire.endTransmission();
    digitalWrite(led2, HIGH);
  }
  else digitalWrite(led2, LOW);
  if (total3 > 800){
    Wire.beginTransmission(9);
    Wire.write(17);
    Wire.endTransmission();
    digitalWrite(led3, HIGH);
  }
  else digitalWrite(led3, LOW);
  if (total4 > 800){
    Wire.beginTransmission(9);
    Wire.write(18);
    Wire.endTransmission();
    digitalWrite(led4, HIGH);
  }
  else digitalWrite(led4, LOW);
  if (total5 > 800){
    Wire.beginTransmission(9);
    Wire.write(19);
    Wire.endTransmission();
    digitalWrite(led5, HIGH);
  }
  else digitalWrite(led5, LOW);
  if (total6 > 800){
    Serial.write(20);
    Wire.beginTransmission(9);
    Wire.write(20);
    Wire.endTransmission();
  }
  else digitalWrite(led6, LOW);
  if (total7 > 800){
    digitalWrite(led7, HIGH);
    Wire.beginTransmission(9);
    Wire.write(21);
    Wire.endTransmission();
  }
  else digitalWrite(led7, LOW);

  if(total1 <= 800 && total2 <= 800 && total3 <= 800 && total4 <= 800 && total5 <= 800 && total6 <= 800 && total7 <= 800) {
        Wire.beginTransmission(9);
  Wire.write(0);
  Wire.endTransmission();
  }

  delay(10);                             // arbitrary delay to limit data to serial port 
}
