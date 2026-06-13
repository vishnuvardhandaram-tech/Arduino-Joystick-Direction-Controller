#include <LedControl.h>
#include <Servo.h>

// MAX7219
LedControl lc = LedControl(11, 13, 10, 1);

// Joystick
#define HORZ A0
#define VERT A1
#define SEL 2

// Servo
Servo myServo;

// Buzzer
#define BUZZER 8

// -------------------- ARROWS --------------------

byte UP[8] = {
  B00011000,
  B00111100,
  B01111110,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00000000
};

byte DOWN[8] = {
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B01111110,
  B00111100,
  B00011000
};

byte LEFT[8] = {
  B00010000,
  B00110000,
  B01111111,
  B11111111,
  B01111111,
  B00110000,
  B00010000,
  B00000000
};

byte RIGHT[8] = {
  B00001000,
  B00001100,
  B11111110,
  B11111111,
  B11111110,
  B00001100,
  B00001000,
  B00000000
};

byte SMILE[8] = {
  B00111100,
  B01000010,
  B10100101,
  B10000001,
  B10100101,
  B10011001,
  B01000010,
  B00111100
};

// -------------------- SETUP --------------------

void setup()
{
  Serial.begin(9600);

  pinMode(BUZZER, OUTPUT);
  pinMode(SEL, INPUT_PULLUP);

  myServo.attach(9);
  myServo.write(0);

  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}

// -------------------- LOOP --------------------

void loop()
{
  int x = analogRead(HORZ);
  int y = analogRead(VERT);

  // Button Press
  if (digitalRead(SEL) == LOW)
  {
    showPattern(SMILE);

    tone(BUZZER, 1200);
    delay(100);

    tone(BUZZER, 1800);
    delay(100);

    noTone(BUZZER);

    myServo.write(90);
    delay(500);
    myServo.write(0);

    delay(300);
    return;
  }

  // UP
  if (y > 800)
  {
    showPattern(UP);

    tone(BUZZER, 1800);
    delay(100);
    noTone(BUZZER);

    myServo.write(90);
  }

  // DOWN
  else if (y < 200)
  {
    showPattern(DOWN);

    tone(BUZZER, 800);
    delay(100);
    noTone(BUZZER);

    myServo.write(90);
  }

  // LEFT
  else if (x < 200)
  {
    showPattern(LEFT);

    tone(BUZZER, 1200);
    delay(100);
    noTone(BUZZER);

    myServo.write(90);
  }

  // RIGHT
  else if (x > 800)
  {
    showPattern(RIGHT);

    tone(BUZZER, 1500);
    delay(100);
    noTone(BUZZER);

    myServo.write(90);
  }

  // CENTER
  else
  {
    lc.clearDisplay(0);
    myServo.write(0);
  }

  delay(100);
}

// -------------------- FUNCTIONS --------------------

void showPattern(byte pattern[])
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0, i, pattern[i]);
  }
}