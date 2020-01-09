const byte interruptPin = 3;
const int segment1 = 5;
const int segment2 = 6;
const int segment3 = 7;
const int segment4 = 8;
const int segment5 = 9;
const int segment6 = 10;
const int segment7 = 11;
int x = 0;
int songNumber = 0;

void setup() {
  pinMode(segment1, OUTPUT);
  pinMode(segment2, OUTPUT);
  pinMode(segment3, OUTPUT);
  pinMode(segment4, OUTPUT);
  pinMode(segment5, OUTPUT);
  pinMode(segment6, OUTPUT);
  pinMode(segment7, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  Serial.println(songNumber);
  songNumber = Serial.read();
  
  if(songNumber == 11) song1();
  if(songNumber == 12) song2();
  if(songNumber == 13) song3();
}

void song1(){
  //321ccccegfedc
  digitalWrite(segment1, LOW); digitalWrite(segment2, HIGH); digitalWrite(segment3, HIGH); digitalWrite(segment4, HIGH); digitalWrite(segment5, LOW); digitalWrite(segment6, HIGH); digitalWrite(segment7, HIGH); //3
  delay(500); 
  digitalWrite(segment1, HIGH); digitalWrite(segment2, HIGH); digitalWrite(segment3, LOW); digitalWrite(segment4, HIGH); digitalWrite(segment5, LOW); digitalWrite(segment6, HIGH); digitalWrite(segment7, HIGH); //2
  delay(500);
  digitalWrite(segment1, LOW); digitalWrite(segment2, LOW); digitalWrite(segment3, HIGH); digitalWrite(segment4, LOW); digitalWrite(segment5, LOW); digitalWrite(segment6, LOW); digitalWrite(segment7, HIGH); //1
  delay(500);
  digitalWrite(segment1, HIGH); digitalWrite(segment2, HIGH); digitalWrite(segment3, LOW); digitalWrite(segment4, LOW); digitalWrite(segment5, HIGH); digitalWrite(segment6, HIGH); digitalWrite(segment7, LOW); //c
  delay(1000);
  digitalWrite(segment1, HIGH); digitalWrite(segment2, HIGH); digitalWrite(segment3, LOW); digitalWrite(segment4, LOW); digitalWrite(segment5, HIGH); digitalWrite(segment6, HIGH); digitalWrite(segment7, LOW); //c
  delay(1000);
  digitalWrite(segment1, HIGH); digitalWrite(segment2, HIGH); digitalWrite(segment3, LOW); digitalWrite(segment4, LOW); digitalWrite(segment5, HIGH); digitalWrite(segment6, HIGH); digitalWrite(segment7, LOW); //c
  delay(1000);
  digitalWrite(segment1, HIGH); digitalWrite(segment2, HIGH); digitalWrite(segment3, LOW); digitalWrite(segment4, LOW); digitalWrite(segment5, HIGH); digitalWrite(segment6, HIGH); digitalWrite(segment7, LOW); //c
  delay(1000);
  digitalWrite(segment1, HIGH); digitalWrite(segment2, HIGH); digitalWrite(segment3, LOW); digitalWrite(segment4, HIGH); digitalWrite(segment5, HIGH); digitalWrite(segment6, LOW); digitalWrite(segment7, LOW); //e
  delay(1000);
  digitalWrite(segment1, HIGH); digitalWrite(segment2, HIGH); digitalWrite(segment3, HIGH); digitalWrite(segment4, HIGH); digitalWrite(segment5, HIGH); digitalWrite(segment6, HIGH); digitalWrite(segment7, LOW); //g
  delay(1000);
  digitalWrite(segment1, HIGH); digitalWrite(segment2, LOW); digitalWrite(segment3, LOW); digitalWrite(segment4, HIGH); digitalWrite(segment5, HIGH); digitalWrite(segment6, HIGH); digitalWrite(segment7, LOW); //f
  delay(1000);
  digitalWrite(segment1, HIGH); digitalWrite(segment2, HIGH); digitalWrite(segment3, LOW); digitalWrite(segment4, HIGH); digitalWrite(segment5, HIGH); digitalWrite(segment6, LOW); digitalWrite(segment7, LOW); //e
  delay(1000);
  digitalWrite(segment1, HIGH); digitalWrite(segment2, HIGH); digitalWrite(segment3, HIGH); digitalWrite(segment4, LOW); digitalWrite(segment5, HIGH); digitalWrite(segment6, HIGH); digitalWrite(segment7, HIGH); //d
  delay(1000);
  digitalWrite(segment1, HIGH); digitalWrite(segment2, HIGH); digitalWrite(segment3, LOW); digitalWrite(segment4, LOW); digitalWrite(segment5, HIGH); digitalWrite(segment6, HIGH); digitalWrite(segment7, LOW); //c
  delay(1000);
  
}

void song2(){
  digitalWrite(segment1, HIGH);
  digitalWrite(segment2, LOW); 
  digitalWrite(segment3, LOW); 
  digitalWrite(segment4, LOW); 
  digitalWrite(segment5, LOW);
  digitalWrite(segment6, LOW); 
  digitalWrite(segment7, LOW); 
}

void song3(){
  digitalWrite(segment1, LOW);
  digitalWrite(segment2, HIGH);
  digitalWrite(segment3, LOW);
  digitalWrite(segment4, LOW);
  digitalWrite(segment5, LOW);
  digitalWrite(segment6, LOW);
  digitalWrite(segment7, LOW);
}
