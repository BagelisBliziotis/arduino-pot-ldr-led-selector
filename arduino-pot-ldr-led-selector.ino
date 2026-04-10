int b1 =6;
int b2 = 9;
int b3 = 10;
int b4 = 11;
int readpin1 = A3;
int readpin2 = A4; 
int buzzpin = 5;
int buttonpin = 8;
int readV;
int readBR;
int readBU;
int bright1;
int bright2;
int mode=0;
void setup() {
  pinMode(b1,OUTPUT);
  pinMode(b2,OUTPUT);
  pinMode(b3,OUTPUT);
  pinMode(b4,OUTPUT);
  pinMode(readpin1,INPUT);
  pinMode(readpin2,INPUT);
  pinMode(buttonpin,INPUT);
  pinMode(buzzpin,OUTPUT);
  Serial.begin(9600);
  digitalWrite(buttonpin,HIGH);
}

void loop() {
  readBU = digitalRead(buttonpin);
  readV = analogRead(readpin1);
  readBR = analogRead(readpin2);
  Serial.println(bright1);
  bright1 = (255.0/62)*readBR-3940.16129;
  bright2= (255.0/1023)*readV;
  if(readBU==0 && mode==0){
    mode=1;
    while(readBU!=1){
      readBU = digitalRead(buttonpin);
    }
  }
  if(readBU==0 && mode==1){
    mode=0;
    while(readBU!=1){
      readBU = digitalRead(buttonpin);
    }
  }
  if(mode==1){
    analogWrite(b4,bright2);
    analogWrite(b3,bright2);
    analogWrite(b2,bright2);
    analogWrite(b1,bright2);
    analogWrite(buzzpin,255);
  }

  
  
  else if(readV<=256){
    digitalWrite(buzzpin,LOW);
    analogWrite(b4,bright1);
    analogWrite(b3,0);
    analogWrite(b2,0);
    analogWrite(b1,0);}
  else if(readV>256 && readV<=512){
    digitalWrite(buzzpin,LOW);
    analogWrite(b4,0);
    analogWrite(b3,bright1);
    analogWrite(b2,0);
    analogWrite(b1,0);}
  else if(readV>512 && readV<=768){
    digitalWrite(buzzpin,LOW);
    analogWrite(b4,0);
    analogWrite(b3,0);
    analogWrite(b2,bright1);
    analogWrite(b1,0);}
  else {
    digitalWrite(buzzpin,LOW);
    analogWrite(b4,0);
    analogWrite(b3,0);
    analogWrite(b2,0);
    analogWrite(b1,bright1);
  }

  
 
}
