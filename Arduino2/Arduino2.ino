#include <LiquidCrystal.h>
#include <IRremote.h>
#include <TonePlayer.h>
#include <Wire.h>

TonePlayer tone1 (TCCR1A, TCCR1B, OCR1AH, OCR1AL, TCNT1H, TCNT1L);  // pin D9 (Uno), D11 (Mega)

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int potentiometer = A2;
const int ir = 7;
IRrecv irrecv(ir);
decode_results results;
unsigned long value = 0;
const int buzzer = 9;
int keyReading = 0;
int potentiometerValue = 0;

void setup() {
  lcd.begin(16, 2);
  irrecv.enableIRIn();
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  Wire.begin(9);
  Wire.onReceive(receiveEvent);
}
void receiveEvent(int bytes) {
  keyReading = Wire.read();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)){
    value = results.value;
    irrecv.resume(); 
  }
  potentiometerValue = analogRead(potentiometer);
  
  if(keyReading == 15 && value == 0xFF30CF) tone1.tone(131);
  else if(keyReading == 16 && value == 0xFF30CF) tone1.tone(149);
  else if(keyReading == 17 && value == 0xFF30CF) tone1.tone(165);
  else if(keyReading == 18 && value == 0xFF30CF) tone1.tone(175);
  else if(keyReading == 19 && value == 0xFF30CF) tone1.tone(196);
  else if(keyReading == 20 && value == 0xFF30CF) tone1.tone(220);
  else if(keyReading == 21 && value == 0xFF30CF) tone1.tone(247);
  else if(keyReading == 15 && value == 0xFF18E7) tone1.tone(262);
  else if(keyReading == 16 && value == 0xFF18E7) tone1.tone(294);
  else if(keyReading == 17 && value == 0xFF18E7) tone1.tone(330);
  else if(keyReading == 18 && value == 0xFF18E7) tone1.tone(349);
  else if(keyReading == 19 && value == 0xFF18E7) tone1.tone(392);
  else if(keyReading == 20 && value == 0xFF18E7) tone1.tone(440);
  else if(keyReading == 21 && value == 0xFF18E7) tone1.tone(494);
  else if(keyReading == 15 && value == 0xFF7A85) tone1.tone(523);
  else if(keyReading == 16 && value == 0xFF7A85) tone1.tone(587);
  else if(keyReading == 17 && value == 0xFF7A85) tone1.tone(659);
  else if(keyReading == 18 && value == 0xFF7A85) tone1.tone(698);
  else if(keyReading == 19 && value == 0xFF7A85) tone1.tone(784);
  else if(keyReading == 20 && value == 0xFF7A85) tone1.tone(880);
  else if(keyReading == 21 && value == 0xFF7A85) tone1.tone(988);
  else {
    tone1.noTone();
  }

  if(potentiometerValue >= 0 && potentiometerValue < 350){
    lcd.setCursor(0,0);
    lcd.print("Song1");
    Serial.write(11);
  }
  else if(potentiometerValue >= 350 && potentiometerValue < 700){
    lcd.setCursor(0,0);
    lcd.print("Song2");
    Serial.write(12);
  }
  else{
    lcd.setCursor(0,0);
    lcd.print("Song3");
    Serial.write(13);
  }

  if(value == 0xFF30CF){
    lcd.setCursor(0,1);
    lcd.print("first set of notes");
  }
  else if(value == 0xFF18E7){
    lcd.setCursor(0,1);
    lcd.print("second set of notes");
  }
  else {
    lcd.setCursor(0,1);
    lcd.print("third set of notes");
  }
  delay(100);
}

 
