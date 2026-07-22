# Arduino 4DOF Robotic Arm
Embedded systems project built using an Arduino Uno, 4 servo motors, Joystick module, and rotary encoder control to create custom robotic arm 

## Overview
This project is a 4-DOF robotic arm designed and built using an Arduino Uno. The system uses a joystick and rotary encoder input to control the four SG90 servo motors. The joystick allows flexion of the arm, pressing down on the joystick allows the claw mechanism to close, releasing it opens the claw. The rotating base is controlled by the rotary encoder.  

## Demo Video

# Images

Additional Photos and Videos :
(Google Drive Folder) https://drive.google.com/drive/folders/1UfXdS34-JHdfkFk53FSP-i0DPNB1nJPj?usp=drive_link

<img width="528" height="704" alt="image" src="https://github.com/user-attachments/assets/ba18701d-c155-4b9c-9417-2ff5249ff5ca" />
<img width="519" height="658" alt="image" src="https://github.com/user-attachments/assets/ab57c3aa-bdbb-4907-9637-0d58a897c050" />
<img width="510" height="680" alt="image" src="https://github.com/user-attachments/assets/9160d4dc-9307-4993-a9f9-0b434ae3976b" />


# Features 

-4-axis servo control 
-Joystick based movement control and claw mechanism control
-Rotarty encoder controlled based rotation
-Custom Arduino Code (C++)

# Hardware Used

| Component | Quantity |
|-----------|----------|
| Arduino Uno | 1 |
| SG90 Servo Motors | 4 |
| Analog Joystick Module | 1 |
| Rotary Encoder Module | 1 |
| Breadboard | 1 |
| Jumper Wires | 24 |


# Wiring Diagram 
![Robotic Arm Wiring Diagram](https://github.com/user-attachments/assets/e0186581-dcc5-403a-8729-a86e49285516)

# Wokwi_Simulation

https://wokwi.com/projects/470276639610557441

## Pin Configuration

| Component | Pin Connection |
|-----------|----------------|
| Servo 1  | D12 |
| Servo 2  | D11 |
| Servo 3  | D10 |
| Servo 4  | D9 |
| Joystick VRx (X-axis) | A0 |
| Joystick VRy (Y-axis) | A1 |
| Joystick Button (SW) | D13 |
| Rotary Encoder CLK | D3 |
| Rotary Encoder DT | D4 |
| Rotary Encoder Switch (SW) | D2 |
| Rotary Encoder VCC | 5V |
| Rotary Encoder GND | GND |


# Mechanical Structure

Custom-built robotic arm frame using cardboard, rubber bands, and tape.

**Prototype Note:**  
This structure is currently a fully functional prototype. A future version will include a custom CAD-designed frame with 3D-printed components to improve durability and precision.  

# Software
The robotic arm was programmed using Arduino C++. The program reads the inputs of the analog joystick and rotary encoder inputs, and converts them into servo position changes.

# Challenges & Future Improvments 

Challenges
-The largest challenge was building the structure for the arm and finding a stable enough material that wouldn't weigh to much dragging the arm downward. Attaching the servo horn to the arm joints was also a large challenge. Input control was another important challenge, adjusting the joystick and encoder sensitivity to create smoother movement

Future Improvements 
-Create custom PCB
-Replace Arduino with ESP32
-Upgraded to higher torque servos
-Full 3D printer structure
