#include <Arduino.h>
class Motor
{
public:
int speed;
int direction;
int stepCounter=0;
int Delay;
Motor(int speed, int direction)
{
this->speed=speed;
this->direction=direction;
}
int getDirection() const
{
  Serial.println("returning direction");
  Serial.println(direction);
return direction;
}
int getSpeed() const
{
  Serial.println("returning speed");
Serial.println(speed);
return speed;
}
int getDelay() const
{
  Serial.println("returning Delay");
Serial.println(Delay);
return Delay;
}
int getPosition() const
{
  Serial.println("returning position");
Serial.println(stepCounter);
return stepCounter;
}
int setDelay(int Delay) 
{
  Serial.println("setting Delay");
this->Delay=Delay;
Serial.println(this->Delay);
}
int setDirection(int dir) 
{
  Serial.println("setting direction");
 this->direction=dir;
 Serial.println(this->direction);

}
int setSpeed(int speed) 
{
  Serial.println("setting speed");
this->speed=speed;
Serial.println(this->speed);
}
void move(int direction, int steps)
{
  if (direction == this->direction) Serial.println("moving same direction");
  else
  {
Serial.println("moving reverse direction");
this->direction=direction;
  } 
/*  if(stepCounter<steps)
  {
    stepCounter++;
    Serial.println("required steps:");
    Serial.println(steps);
    Serial.println("counting steps:");
    Serial.println(stepCounter);
  }
  else{
    relative_position_steps=stepCounter;
    Serial.println("finished moving");
  } 
*/
    Serial.println("required steps:");
    Serial.println(steps);

  for (int counter =0; counter <= steps; counter++)
  {
    Serial.println("counting steps:");
    Serial.println(counter);
    if(counter==steps) stepCounter=counter;
  }
    Serial.println("finished moving");





}




};
