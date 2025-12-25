#include <Keypad.h>
#include <LiquidCrystal.h>

// LCD Setup (RS, EN, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, A0, A1, A2, A3);

// Password Configuration
#define Password_Length 5  // Password 4 digits + null terminator
char Password[Password_Length] = "1234";  // Default password
char Input[Password_Length];
byte inputPosition = 0;

// Buzzer Pin
const int buzzer = 13;

// Keypad Setup
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Password System");
  lcd.setCursor(0, 1);
  lcd.print("Ready...");
  
  pinMode(buzzer, OUTPUT);
  
  delay(2000);
  lcd.clear();
  displayPrompt();
}

void loop() {
  char key = keypad.getKey();
  
  if (key) {
    if (key >= '0' && key <= '9') {
      // Number input
      Input[inputPosition] = key;
      lcd.setCursor(inputPosition, 1);
      lcd.print('*');  // Display asterisk
      inputPosition++;
      
      // Check if password complete
      if (inputPosition == Password_Length - 1) {
        Input[inputPosition] = '\0';
        checkPassword();
      }
    }
    else if (key == '#') {
      // Submit password manually
      Input[inputPosition] = '\0';
      checkPassword();
    }
    else if (key == '*') {
      // Clear input
      clearInput();
      displayPrompt();
    }
  }
}

void checkPassword() {
  if (strcmp(Input, Password) == 0) {
    // Password CORRECT - Nothing happens
    lcd.clear();
    lcd.print("Password Correct");
    lcd.setCursor(0, 1);
    lcd.print("Access OK");
    
    // NO buzzer, NO LED - silent acceptance
    
    delay(2000);
    clearInput();
    displayPrompt();
  }
  else {
    // Password INCORRECT - Buzzer alert
    lcd.clear();
    lcd.print("WRONG PASSWORD!");
    lcd.setCursor(0, 1);
    lcd.print("Access Denied");
    
    // Buzzer alert - loud alarm sound
    for(int i = 0; i < 5; i++) {
      tone(buzzer, 1000, 200);  // 1kHz tone
      delay(250);
      tone(buzzer, 800, 200);   // 800Hz tone
      delay(250);
    }
    noTone(buzzer);
    
    delay(2000);
    clearInput();
    displayPrompt();
  }
}

void displayPrompt() {
  lcd.clear();
  lcd.print("Enter Password:");
  lcd.setCursor(0, 1);
}

void clearInput() {
  inputPosition = 0;
  for(int i = 0; i < Password_Length; i++) {
    Input[i] = '\0';
  }
}
