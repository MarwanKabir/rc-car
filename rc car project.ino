//initialize all pins
int pins[] = {2, 3, 4, 5, 6, 7};
//initialize input
int input = 0;

void setup()
{
  //set all pins
  for (int i = 0; i < 6; i++)
  {
    pinMode(pins[i], OUTPUT);
  }
  Serial.begin(9600);
  //set car in rest
  digitalWrite(7, 1);
  digitalWrite(6, 0);
  analogWrite(5, 0);
  digitalWrite(4, 0);
  digitalWrite(3, 1);
  analogWrite(2, 0);
  //display control options to user
  Serial.println("1 - FORWARD");
  Serial.println("2 - SLOW");
  Serial.println("3 - SWING TURN RIGHT");
  Serial.println("4 - POINT TURN LEFT");
  Serial.println("5 - BRAKE");
  Serial.println("6 - COAST");
}

void loop()
{
  //loop serial input
  sinput();
}

//move foward
void mf()
{
  digitalWrite(7, 1);
  digitalWrite(6, 0);
  analogWrite(5, 255);
  digitalWrite(4, 0);
  digitalWrite(3, 1);
  analogWrite(2, 255);
}

//move slow
void ms()
{
  digitalWrite(7, 1);
  digitalWrite(6, 0);
  analogWrite(5, 130);
  digitalWrite(4, 0);
  digitalWrite(3, 1);
  analogWrite(2, 130);
}

//swing turn right
void str()
{
  digitalWrite(7, 1);
  digitalWrite(6, 0);
  analogWrite(5, 0);
  digitalWrite(4, 0);
  digitalWrite(3, 1);
  analogWrite(2, 255);
}

//point turn left
void ptl()
{
  digitalWrite(7, 0);
  digitalWrite(6, 1);
  analogWrite(5, 255);
  digitalWrite(4, 0);
  digitalWrite(3, 1);
  analogWrite(2, 128);
}

//brake
void b()
{
  digitalWrite(7, 1);
  digitalWrite(6, 0);
  analogWrite(5, 0);
  digitalWrite(4, 0);
  digitalWrite(3, 1);
  analogWrite(2, 0);
}

//coast
void c()
{
  for (int i = 0; i <= 255; i++)
  {
  	analogWrite(5, i);
  	analogWrite(2, i);
    
    if (i == 255)
    {
      analogWrite(5, 0);
      analogWrite(2, 0);
    }
  }
}

//serial input from user
void sinput()
{
  //take input from serial monitor
  while(Serial.available() == 0){}
  input = Serial.parseInt();
  
  //run the corresponding control
  if (input == 1)
  {
    mf();
  }
  else if (input == 2)
  {
    ms();
  }
  else if (input == 3)
  {
    str();
  }
  else if (input == 4)
  {
    ptl();
  }
  else if (input == 5)
  {
    b();
  }
  else if (input == 6)
  {
    c();
  }
  else
  {
    Serial.println("Not an option!");
  }
}