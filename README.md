# Smart Password Lock System with Keypad and LCD
Goal: Implement a secure password‑based lock system that uses a keypad for input and an LCD to guide the user, allowing access only when the correct code is entered.
## Features
A 4x4 keypad is used to enter digits for the password, along with clear/enter keys.
A 16x2 LCD displays prompts such as “Enter Password”, “Access Granted”, and “Access Denied”.
The microcontroller compares the entered sequence with a stored password and decides whether to unlock or trigger an alarm.
After a certain number of wrong attempts (for example, three), a buzzer alarm is activated or the system is locked for a short time.
The design can be extended with features like password change mode, master override code, or logging of failed attempts.
## Hardware & Tools
Arduino Uno or Arduino Nano (or similar microcontroller board).
4x4 matrix keypad for password input.
16x2 LCD display (parallel or I2C) for messages.
Buzzer, optional status LEDs for LOCK/UNLOCK indication.
Resistors, potentiometer (for LCD contrast), breadboard, jumper wires, and USB power supply.
## How It Works
The keypad is interfaced with the microcontroller, which scans and decodes each key press into a digit or command.
When the user types digits, they are stored in a buffer and optionally shown as asterisks (*) on the LCD.
On pressing the enter key, the microcontroller compares the entered digits with the predefined password.
If the password is correct, the system activates the “unlocked” state (e.g., turns on a green LED or drives a relay).
If the password is incorrect, the LCD shows an error message, increments the failed‑attempt counter, and, after the limit is reached, activates the buzzer or lockout mode.
## Simulation
Simulator project link: https://wokwi.com/projects/451324174446931969
## Code
Main code file: smart_keypad_lock.ino
