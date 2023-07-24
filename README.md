# Biped-robot-arduino-project-

Here is a link to the video that I made of the project:
https://www.youtube.com/watch?v=hyNF8KC1o14&t=7s

Better footage of its motion:
https://www.youtube.com/watch?v=mndZKeckFIY

Libraries: The code includes two libraries: "Adafruit_PWMServoDriver.h" and "Wire.h". The "Adafruit_PWMServoDriver.h" library is used to control the servo motors via a servo motor driver, and the "Wire.h" library is used for I2C communication.

Object Creation: An object of the "Adafruit_PWMServoDriver" class is created with the name "PWM". This object will be used to control the servo motors.

Servo motor range: The minimum and maximum tick values for the servo motors are defined using "#define" statements. These tick values represent the duty cycle range for the servo motors, which control their movement from 0 to 180 degrees.

User-defined function: A user-defined function called "servowrite" is created to set the angle of a servo motor. It takes two parameters: "servonum" which represents the channel number of the servo motor connected to the servo motor driver, and "angle" which represents the desired angle of the servo motor. The "map" function is used to map the angle value from 0 to 180 to the corresponding tick value within the defined range of duty cycles. Finally, the "PWM.setPWM" function is called to set the servo motor to the calculated tick value.

Initialization: The "setup" function is called once at the start of the code. Serial communication is initialized at a baud rate of 9600. The "PWM" object is also initialized using the "PWM.begin()" function. The communication frequency of the servo motor driver is set to 60Hz using the "PWM.setPWMFreq" function. The "zeroset" function is called to set all servo motors to their initial position of 90 degrees.

Movement steps: The "loop" function is called repeatedly in a loop after the "setup" function. This is where the movement steps for the biped robot are defined. The code uses a gait algorithm to mimic human walking, with a series of steps for each leg.

Step 1: The ankle servo motors of both legs are moved from 90 degrees to 45 degrees for the left leg and 70 degrees for the right leg, with a delay of 200 milliseconds between each step. This simulates lifting the feet off the ground.

Step 2: The knee servo motors of both legs are moved from 90 degrees to 150 degrees for the left leg and 120 degrees for the right leg, with a delay of 200 milliseconds between each step. This simulates extending the legs forward.

Step 3: The ankle servo motors of both legs are moved from their lifted position back to 90 degrees, with a delay of 200 milliseconds between each step. This simulates placing the feet back on the ground.

Step 4: The knee servo motors of both legs are moved back to 90 degrees, with a delay of 200 milliseconds between each step. This simulates bending the knees and preparing for the next step.

Step 5: The entire sequence of steps 1-4 is repeated a desired number of times, as determined by the "numsteps" variable.

Step 6: The "servowrite" function is called to set all servo motors to their initial position of 90 degrees, with a delay of 1000 milliseconds between each step. This resets the robot to its starting position.

The loop then repeats these steps indefinitely, creating a walking motion for the biped robot.

Note: It's important to note that the specific angles and delays used in the code may need to be adjusted depending on the physical characteristics and mechanical design of the biped robot being controlled. Proper calibration and testing should be done to achieve the desired walking motion.
