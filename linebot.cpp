//MOTOR DRIVER
int lf = 2;
int lb = 3;
int rf = 4;
int rb = 5;

//SPEED CONTROL
int enR = 10;   //enA
int enL = 11;   //enB

//SENSOR INPUTS
int SenER = A1;
int SenR = A2;
int SenM=A3;                                                                               
int SenL = A4;
int SenEL = A5;

//OBJECT SENSOR
int ObjLeft = 6;
int ObjRight = 7;
int LEDLEFT = 8;
int LEDRIGHT = 9;

void Straight();
void left_turn();
void right_turn();

void setup() 
{
  //MOTOR DRIVER
  pinMode(lf, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(rb, OUTPUT);
  
  //SPEED CONTROL
  pinMode(enR, OUTPUT);
  pinMode(enL, OUTPUT);

  //SENSOR INPUTS
  pinMode(SenM, INPUT);
  pinMode(SenL, INPUT);
  pinMode(SenEL, INPUT);
  pinMode(SenR, INPUT);
  pinMode(SenER, INPUT);

  //OBJECT DETECTOR
  pinMode(ObjLeft, INPUT);
  pinMode(ObjRight, INPUT);
  pinMode(LEDLEFT, OUTPUT);
  pinMode(LEDRIGHT, OUTPUT);
  
  Serial.begin(9600);
}

void loop() 
{
  /*Straight();
  delay(500);
  right_turn();
  delay(200);
  left_turn();
  delay(200);
  left_turn();
  delay(200);
  right_turn();
  delay(200);*/
  int ObjValL = digitalRead(ObjLeft);
  int ObjValR = digitalRead(ObjRight);
  int SenValM = analogRead(SenM); //black = 37 white = 28
  int SenValL = analogRead(SenL); // black = 41  white = 31
  int SenValR = analogRead(SenR); //black = 50 white = 33
  int SenValEL = analogRead(SenEL); //black = 60 white = 34
  int SenValER = analogRead(SenER); //black = 41 white = 31
  int EL,L,M,R,ER;
  //Sensor (ANALOG TO BINARY)
  if(SenValEL >= 33) {EL = 1;}
  if(SenValEL < 33) {EL = 0;}
  if(SenValL >= 32) {L = 1;}
  if(SenValL < 32) {L = 0;}
  if(SenValM >= 30) {M = 1;}               //1 == black; 0 == white;
  if(SenValM < 30) {M = 0;}
  if(SenValR >= 36) {R = 1;}
  if(SenValR < 36) {R = 0;}
  if(SenValER >= 33) {ER = 1;}
  if(SenValER < 33) {ER = 0;}

  Serial.print(EL);
  Serial.print(SenValEL);
  Serial.print(L);
  Serial.print(SenValL);
  Serial.print(M);
  Serial.print(SenValM);
  Serial.print(R);
  Serial.print(SenValR);
  Serial.print(ER);
  Serial.println(SenValER);
  delay(100);

  if(ObjValL == 0){
    digitalWrite(LEDLEFT, HIGH);
  }
  if(ObjValL == 1){
    digitalWrite(LEDLEFT, LOW);
  }
  if(ObjValR == 0){
    digitalWrite(LEDRIGHT, HIGH);
  }
  if(ObjValR == 1){
    digitalWrite(LEDRIGHT, LOW);
  }
  

  // Cases
  if(EL == 0 && L == 0 && M == 0 && R == 0 && ER == 0)
  {
    Straight();
  }
  if(EL == 0 && L == 0 && M == 0 && R == 0 && ER == 1)
  {
    right_turn();
  }
  if(EL == 0 && L == 0 && M == 0 && R == 1 && ER == 0)
  {
    right_turn();
  }
  if(EL == 0 && L == 0 && M == 0 && R == 1 && ER == 1)
  {
    right_turn();
    //delay();
  }
  if(EL == 0 && L == 0 && M == 1 && R == 0 && ER == 0)
  {
    Straight();
  }
  if(EL == 0 && L == 0 && M == 1 && R == 1 && ER == 0)
  {
    left_turn();
    //delay();
  }
  if(EL == 0 && L == 1 && M == 0 && R == 0 && ER == 0)
  {
    left_turn();
  }
  if(EL == 0 && L == 1 && M == 0 && R == 0 && ER == 1)
  {
    left_turn();
  }
  if(EL == 0 && L == 1 && M == 1 && R == 1 && ER == 1)
  {
    left_turn();
  }
  if(EL == 1 && L == 0 && M == 0 && R == 1 && ER == 0)
  {
    right_turn();
  }
  if(EL == 1 && L == 0 && M == 0 && R == 1 && ER == 1)
  {
    left_turn();    
  }
  if(EL == 1 && L == 1 && M == 0 && R == 0 && ER == 0)
  {
    right_turn();
  }
  if(EL == 1 && L == 1 && M == 0 && R == 0 && ER == 1)
  {
    right_turn();
  }
  if(EL == 1 && L == 1 && M == 0 && R == 1 && ER == 1)
  {
    Straight();
  }
  if(EL == 1 && L == 1 && M == 1 && R == 0 && ER == 0)
  {
    right_turn();
  }
  if(EL == 0 && L == 0 && M == 0 && R == 0 && ER == 0)
  {
    right_turn();
  }
  if(EL == 1 && L == 1 && M == 1 && R == 1 && ER == 0)
  {
    right_turn();
  }
  if(EL == 1 && L == 1 && M == 1 && R == 1 && ER == 1)
  {
    stop();
  }

}
  
//GO Stright(FULL SPEED)(MENTION DELAY TIME)
void Straight()
{
  analogWrite(enR, 200);
  analogWrite(enL, 170);
  digitalWrite(lb, LOW);
  digitalWrite(lf, HIGH);
  digitalWrite(rb, HIGH);
  digitalWrite(rf, LOW);
}
//TAKE LEFT (MENTION DELAY TIME)

void left_turn()
{
  analogWrite(enR, 200);
  analogWrite(enL, 150);
  digitalWrite(lb, HIGH);
  digitalWrite(lf, LOW);
  digitalWrite(rb, HIGH);
  digitalWrite(rf, LOW);
}
//TAKE RIGHT (MENTION DELAY TIME)
void right_turn()
{
  analogWrite(enR, 200);
  analogWrite(enL, 150);
  digitalWrite(lb, LOW);
  digitalWrite(lf, HIGH);
  digitalWrite(rb, LOW);
  digitalWrite(rf, HIGH);
}

void stop()
{
  digitalWrite(lf, LOW);
  digitalWrite(rb, LOW);
}