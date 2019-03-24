const int trigPin1 = 11;
const int echoPin1 = 10;
const int trigPin2 = A3; 
const int echoPin2 = A4;
const int trigPin3 = A2;
const int echoPin3 = A5;
int LS=13 ;   // left sensor
int RS=12 ;   // right sensor
int DIS=15;
/*-------definning Outputs------*/
int LM1=3;  // left motor
int LM2=5;      // left motor
int RM1=6;      // right motor
int RM2=7;       // right motor
int c=1;
void setup()
{
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  Serial.begin(9600);
 pinMode(trigPin1, OUTPUT);
 pinMode(echoPin1, INPUT);

 pinMode(trigPin2, OUTPUT);
 pinMode(echoPin2, INPUT);
 pinMode(trigPin3, OUTPUT);
 pinMode(echoPin3, INPUT);
 pinMode(8,OUTPUT);
 pinMode(9,OUTPUT);
 digitalWrite(8,HIGH);
 digitalWrite(9,HIGH);
};

void loop()
  {
  while (1)
  {
  if(!digitalRead(LS) && !digitalRead(RS))     // Move Forward
  {
    
    analogWrite(LM1, 110);
    analogWrite(LM2, 0);
    analogWrite(RM1, 110);
    analogWrite(RM2, 0);
    
  }
  
  else if((digitalRead(LS)) && !digitalRead(RS))     // Turn left
  {
    
    analogWrite(LM1, 0);
    analogWrite(LM2, 160);
    
    analogWrite(RM1, 160);
    analogWrite(RM2, 0);
    
  }
  
  else if(!digitalRead(LS) && (digitalRead(RS)))     // turn right
  {
  
    analogWrite(LM1, 160);
    analogWrite(LM2, 0);
    
    analogWrite(RM1, 0);
    analogWrite(RM2, 160);
    delay(200);
  }
  
  else if((digitalRead(LS)) && (digitalRead(RS)))     // stop
  
   {
    if(FrontSensor() <DIS || RightSensor() <DIS || LeftSensor()<DIS )
       { break;}
    else {
      
      analogWrite(LM1,0);
    analogWrite(LM2, 0);
    analogWrite(RM1, 0);
    analogWrite(RM2, 0);
    delay(150);
    analogWrite(LM1,160);
    analogWrite(LM2, 0);
    analogWrite(RM1, 0);
    analogWrite(RM2, 160);
    delay(150);
   }
  }
  }
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  delay(1000);
  
  while (1){
    if ( FrontSensor() < DIS && RightSensor () <DIS && LeftSensor
()<DIS) // obstacle infront of all 3 sides
 {
 reverse ();
//then reverse
 }
 else if (FrontSensor() <DIS && RightSensor () <DIS && LeftSensor
()>DIS) // obstacle on right and front sides
 {
 turn_left ();
 Serial.println("left");
// turn left side
 }
 else if (FrontSensor() <DIS && RightSensor () >DIS && LeftSensor
()<DIS) // obstacle on left and front sides
 {
 turn_right ();
// turn right side
 }
 else if (FrontSensor() <DIS && RightSensor () >DIS && LeftSensor
()>DIS) // obstacle on front sides
 {
 turn_right ();
// then turn right
 }
 else if (FrontSensor() >DIS && RightSensor () >DIS && LeftSensor
()<DIS) // obstacle on left sides
 {
 turn_right ();
// then turn right and then forward

 }
 else if (FrontSensor() >DIS && RightSensor () <DIS && LeftSensor
() >DIS) // obstacle on right sides
 {
 forward();
// then turn left and then right
 }
 else
 {
 forward();
 }
  }
}


void forward ()
{
 analogWrite(LM1, 160);
 digitalWrite(LM2, LOW);
 analogWrite(RM1, 160);
 digitalWrite(RM2, LOW);

}
void turn_right ()
{
 analogWrite(LM1, 160);
 digitalWrite(LM2, LOW);
 digitalWrite(RM1, LOW);
 analogWrite(RM2, 160);

}
void turn_left ()
{
 digitalWrite(LM1, LOW);
 analogWrite(LM2, 160);
 analogWrite(RM1, 160);
 digitalWrite(RM2, LOW);

}
void reverse ()
{
 digitalWrite(LM1, LOW);
 analogWrite(LM2, 160);
 digitalWrite(RM1, LOW);
 analogWrite(RM2, 160);

}
void stop()
{
 digitalWrite(LM1, LOW);
 digitalWrite(LM2, LOW);
 digitalWrite(RM1, LOW);
 digitalWrite(RM2, LOW);

}
long FrontSensor ()
{
long dur;
 digitalWrite(trigPin1, LOW);
 delayMicroseconds(5); // delays are required for a succesful sensor
//operation.
 digitalWrite(trigPin1, HIGH);
 delayMicroseconds(10); //this delay is required as well!
 digitalWrite(trigPin1, LOW);
 dur = pulseIn(echoPin1, HIGH);
 return (dur/58);// convert the distance to centimeters.
}
long RightSensor ()
{
long dur;
 digitalWrite(trigPin2, LOW);
 delayMicroseconds(5); // delays are required for a succesful sensor
//operation.
 digitalWrite(trigPin2, HIGH);
 delayMicroseconds(10); //this delay is required as well!
 digitalWrite(trigPin2, LOW);
 dur = pulseIn(echoPin2, HIGH);
 return (dur/58);// convert the distance to centimeters.
}
long LeftSensor () 
{
long dur;
 digitalWrite(trigPin3, LOW);
 delayMicroseconds(5); // delays are required for a succesful sensor
//operation.
 digitalWrite(trigPin3, HIGH);
 delayMicroseconds(10); //this delay is required as well!
 digitalWrite(trigPin3, LOW);
 dur = pulseIn(echoPin3, HIGH);
 return (dur/58);// convert the distance to centimeters.
}
