# Arduino Joystick Direction Controller

An interactive embedded systems project built using Arduino Uno, an analog joystick, a MAX7219 LED matrix, a servo motor, and a buzzer.

The system detects joystick movement in real time and responds with directional arrows displayed on an 8×8 LED matrix, audible feedback through a buzzer, and servo motor movement.

## Features

* Real-time joystick direction detection
* Directional arrow display on MAX7219 LED matrix
* Servo motor control
* Direction-specific buzzer tones
* Joystick push-button interaction
* Smiley face display mode
* Modular and beginner-friendly code structure

## Hardware Components

* Arduino Uno
* Analog Joystick Module
* MAX7219 8×8 LED Matrix
* Servo Motor
* Passive/Active Buzzer
* Breadboard
* Jumper Wires

## Circuit Connections

### Joystick

| Pin  | Arduino |
| ---- | ------- |
| VCC  | 5V      |
| GND  | GND     |
| HORZ | A0      |
| VERT | A1      |
| SEL  | D2      |

### MAX7219 LED Matrix

| Pin | Arduino |
| --- | ------- |
| DIN | D11     |
| CS  | D10     |
| CLK | D13     |
| VCC | 3.3V    |
| GND | GND     |

### Servo Motor

| Pin    | Arduino |
| ------ | ------- |
| Signal | D9      |
| VCC    | 5V      |
| GND    | GND     |

### Buzzer

| Pin      | Arduino |
| -------- | ------- |
| Positive | D8      |
| Negative | GND     |

## System Behaviour

### Direction Controls

| Direction | LED Matrix | Servo | Buzzer           |
| --------- | ---------- | ----- | ---------------- |
| Up        | ↑          | 90°   | High tone        |
| Down      | ↓          | 90°   | Low tone         |
| Left      | ←          | 90°   | Medium tone      |
| Right     | →          | 90°   | Medium-high tone |

### Button Press

When the joystick button is pressed:

* Smiley face is displayed
* Double beep is played
* Servo performs a sweep motion

## Libraries Used

* Servo
* LedControl

Install both libraries through the Arduino IDE Library Manager before uploading the sketch.

## Future Improvements

* Bluetooth control
* OLED display integration
* Wireless communication using ESP32
* Mobile application control
* Gesture-based input
* IoT dashboard integration

## Author

Vishnu Vardhan Daram

Aspiring Engineer focused on Artificial Intelligence, Robotics, Embedded Systems, IoT, and Computer Vision.
