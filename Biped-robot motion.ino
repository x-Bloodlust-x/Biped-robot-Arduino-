/// Adafruit PWM Servo Driver Library - Version: Latest
/*
//SCL and SDA used for I2C communication between servo & IDE //inter integrated circuit (I2C)
(serial clock pin & serial data pin) - 2 commands to send to master
//. I2C is a form of communication where there is a master and slave device
master can send commands to slave to perform a certain task, slave can only follow, not communicate with anything
1 master can communicate with numerous slave devices
masters can communicate with each other
can control 16 servos at same time
servo motor driver increases power efficiency and cobtrol of more motors
*/

#include <Adafruit_PWMServoDriver.h>
#include <Wire.h> // for I2C

Adafruit_PWMServoDriver PWM = Adafruit_PWMServoDriver();//created an object
//duty cycle is the width of the pulse
//every duty cycle has a certain no. of ticks (specifiecd by manufacturer for servo)
//every step is broken down into angles
//certain no. of ticks correspong
//0 degree = narrow pulse = 150 ticks sent from arduino to motor
//180 degree = 520 ticks
//range of ticks will control where each servo motor moves

#define servomin 150
#define servomax 520 // tick value range for duty cycles

//user defined function (we make it) & predefined function (made by Arduino  uses dots)

void servowrite(int servonum, int angle) //governed by 2 parameters - which pin no. servo connected to & 'angle' will be generated from map function
{
 int tick = map(angle, 0, 180, servomin, servomax);
 PWM.setPWM(servonum, 0,tick); //specifies PWM set to values given stored in tick //servo num is no. of channels connected to servos
}
int i = 0;
void zeroset()
{
  //must start at 90 deg, so it can rotate back too
 
  for(i=0; i<6; i++) //3 parametrs: initial position, no. of times to run, increment value
  {
    servowrite(2*i,90); //initially starts with 0, once 1st cycle is complete, no. 2 starts, then, no.4 etc. a multiple of 2
    delay(200);
  }
}


int flag = 0;

void setup() {
  Serial.begin(9600);
  PWM.begin();
  //must specify communication frequency
  PWM.setPWMFreq(60); //operational frequency of servo driver is between 24Hz to 1024Hz
  delay(200);
 
  zeroset();
  delay(200);
}
// biped walks with the gait algorithm to mimic how humans walk(6 steps) -- 1 everything to 0th position, 2 tilt angle sideways, 3 left step forward, repeat 3 steps again but for right leg now
//1st cycle goes from 0 to 6, then 2A to 6
///each step has 3 steps broken down - to improve stability

void loop() {
 /*
 Step 1
 left ankle - 90 -> 45
 Right ankle - 90 -> 70
 */
 
  for(int i=0;i<4;i++)
  {
    servowrite(0,90-15*i);
    delay(200);
   
    if(i<3) // right ankle
    {
      servowrite(10,90-10*i);
      delay(200);
    }
  }
 
  //flags count how many times the entire cycle is running
  if(flag=0)
{

  /*
  Step 2
 left knee -> 90 -> 105
 Right knee - 90 -> 105
left hip -> 90 -> 105
 Right hip - 90 -> 105
 */
 
  for(int i=0;i<4;i++)
  {
    servowrite(2,90+5*i);
    servowrite(4,90+5*i);
    servowrite(6,90+5*i);
    servowrite(8,90+5*i);
    delay(200);
   
  }
}
else
{
   /*
  Step 2A
 left knee -> 75 -> 105
 Right knee - 75 -> 105
left hip -> 75 -> 105
 Right hip - 75 -> 105
 */
 
  for(int i=0;i<7;i++)
  {
    servowrite(2,75+5*i);
    servowrite(4,75+5*i);
    servowrite(6,75+5*i);
    servowrite(8,75+5*i);
    delay(200);
   
  }
}
/*
 Step 3
 left ankle - 45 -> 90
 Right ankle - 70 -> 90
 */
 
  for(int i=0;i<4;i++)
  {
    servowrite(0,45+15*i);
    delay(200);
   
    if(i<3) // right ankle
    {
      servowrite(10,70+10*i);
      delay(200);
    }
  }
 
  /*
 Step 4
 left ankle - 90 -> 110
 Right ankle - 90 -> 135
 */
 
  for(int i=0;i<4;i++)
  {
    servowrite(10,90+15*i);
    delay(200);
   
    if(i<3) // right ankle
    {
      servowrite(0,90+10*i);
      delay(200);
    }
  }

 /*
  Step 5
 left knee -> 105 -> 75
 Right knee - 105 -> 75
left hip -> 105 -> 75
 Right hip - 105 -> 75
 */
 
  for(int i=0;i<7;i++)
  {
    servowrite(2,105-5*i);
    servowrite(4,105-5*i);
    servowrite(6,105-5*i);
    servowrite(8,105-5*i);
    delay(200);
 
  }
 
  /*
 Step 6
 left ankle - 110 -> 90
 Right ankle - 135 -> 90
 */
 
  for(int i=0;i<4;i++)
  {
    servowrite(10,135-15*i);
    delay(200);
   
    if(i<3) // right ankle
    {
      servowrite(0,110-10*i);
      delay(200);
    }  
   
    flag++;
   
  }
}
