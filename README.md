# Electric Train Control

## Project Summary
Taking a classic, battery operated, train set actuated using a small PMDC motor, the task is to add functionalty with numerous sensing and motor driver sub-systems. This is a group project in which my roal was testing all of the circuitry and writing of code.


## Features
- Control speed and direction of train with joystick and H-Bridge
- Communicate wirelessly between a Joystick and train motor
- Design a collision avoidance system
- Design a colour recognition system to stop on red and go on green
- Use PID control to apply a velocity motion profile

![image](https://github.com/user-attachments/assets/90e1f808-a9e2-4f66-9770-4674a90d2b69)


## Usage
#### Ardunio Nano Every
The `Transmitter` code for the Nano simply takes the forward/backward input from the joystick and wirelessly transmits it to the Reciver.

### Ardunio MEGA  
The `Reciever` code for the MEGA calls the functions to run the collision detectance and colour sensor, a series of `if` statements check there's no obsticles or red card displayed. If these tests are passed and a green card is show to the train a boolean value is made `True`, this allows the train to then operate indefinetly, until a red card or collision is present.
#### Code Function 
The code is broken down to 
- Colour Sensor
- Distance Sensor
- Motor Control
- Reciever
The seperation of each code allows for easy debugging and clean code, each segment refers to one of the sensors, the control of the motor or reciveing of wireless signal and is then all called in the main file of code.


## Code Variations
Each Folder will contrain one or two codes for the two arudinos used, whole folders should be downloaded for each microcontroller and ran in Arduino IDE

- `AllWiredTest`
  Includes code for Ardunio MEGA testing the motor and sensors without the use of wireless
- `WirelessTest`
  Includes code for Ardunio MEGA and Nano, this was to test motor control over wireless signal but doesn't include the use of sensors
