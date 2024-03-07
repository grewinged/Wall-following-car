const int trig_side = 4;
const int echo_side = 3;
unsigned long distance_side ;
unsigned long time_side;

const int trig_front=11;
const int echo_front= 12;
unsigned long distance_front ;
unsigned long time_front;

const  int ena = 5;
const  int dir1a = 6;
const  int dir2a = 7;

const int enb = 10;
const  int dir1b = 9;
const  int dir2b = 8;

void In_In(int a,int b);
void In_Out(int a,int b);
void Out_In_close(int a,int b);
void Out_In_far(int a,int b);
void Out_Out(int a,int b);

void setup() {
  Serial.begin(9600);
  pinMode(trig_front, OUTPUT);
  pinMode(echo_front, INPUT);
  pinMode(trig_side, OUTPUT);
  pinMode(echo_side, INPUT);
  pinMode(ena,OUTPUT);
  pinMode(dir1a,OUTPUT);
  pinMode(dir2a,OUTPUT);
  pinMode(enb,OUTPUT);
  pinMode(dir1b,OUTPUT);
  pinMode(dir2b,OUTPUT);
}

void loop() {
  digitalWrite(trig_side,1);
  delayMicroseconds(10);
  digitalWrite(trig_side,0);

  time_side = pulseIn (echo_side, HIGH);
  distance_side = (time_side/2)*0.034;
  Serial.print("distace_side: ");
  Serial.println(distance_side);

  digitalWrite(trig_front,1);
  delayMicroseconds(10);
  digitalWrite(trig_front,0);

  time_front = pulseIn (echo_front, HIGH);
  distance_front = (time_front/2)*0.034;
  Serial.print("distace_front: ");
  Serial.println(distance_front);

  digitalWrite(dir1a,0);
  digitalWrite(dir2a,1);
  digitalWrite(dir1b,1);
  digitalWrite(dir2b,0);
  
  In_In(distance_front,distance_side);
  In_Out(distance_front,distance_side);
  Out_In_close(distance_front,distance_side);
  Out_In_far(distance_front,distance_side);
  Out_Out(distance_front,distance_side);

  delay(100);
}



void In_In(int a,int b)
{
    if( a < 10 and b < 10)
  {
  analogWrite(ena,90);
  delayMicroseconds(10);
  analogWrite(enb,10);
  }
  
}

void In_Out(int a,int b)
{
    if( a < 10 and b > 10)
  {
  analogWrite(ena,90);
  delayMicroseconds(10);
  analogWrite(enb,10);
  }
  
}

void Out_In_close(int a,int b)
{
    if( a > 10  and b < 5)
  {
  analogWrite(ena,90);
  delayMicroseconds(10);
  analogWrite(enb,110);
  }
 
}

void Out_In_far(int a,int b)
{
    if( a > 10 and b < 10 and b > 5)
  {
  analogWrite(ena,90);
  delayMicroseconds(10);
  analogWrite(enb,90);
  }
 
}

void Out_Out(int a,int b)
{
    if( a > 10 and b > 10)
  {
  analogWrite(ena,10);
  delayMicroseconds(10);
  analogWrite(enb,90);
  }

}