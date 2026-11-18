#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int LDR_PIN = A0;

const int LED1 = 9;
const int LED2 = 10;
const int LED3 = 11;

const int BUTTON_PIN = 7;

unsigned long lastTime = 0;
unsigned long lastDisplay = 0;

float energyWh = 0.0;

int brightness = 0;
String condition = "BRIGHT";

void setup() {

  pinMode(LDR_PIN, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  lcd.begin(16, 2);
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("AUTO STREET");

  lcd.setCursor(0, 1);
  lcd.print("LIGHT SYSTEM");

  delay(2000);
  lcd.clear();

  lastTime = millis();
}

void loop() {

  int ldrValue = analogRead(LDR_PIN);

  // Determine brightness
  if (ldrValue > 700) {

    brightness = 0;
    condition = "BRIGHT";

  }
  else if (ldrValue > 500) {

    brightness = 30;
    condition = "MEDIUM";

  }
  else if (ldrValue > 350) {

    brightness = 60;
    condition = "LOW LIGHT";

  }
  else {

    brightness = 100;
    condition = "DARK";

  }

  // Convert percentage to PWM
  int pwmValue = map(brightness, 0, 100, 0, 255);

  analogWrite(LED1, pwmValue);
  analogWrite(LED2, pwmValue);
  analogWrite(LED3, pwmValue);

  // Calculate estimated power
  // Approximate total LED power at 100% brightness
  float maxPower = 0.90;

  float power = maxPower * (brightness / 100.0);

  // Calculate elapsed time
  unsigned long currentTime = millis();

  float elapsedHours = (currentTime - lastTime) / 3600000.0;

  energyWh += power * elapsedHours;

  lastTime = currentTime;

  // Push button resets energy
  if (digitalRead(BUTTON_PIN) == LOW) {

    energyWh = 0.0;

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("ENERGY RESET");

    lcd.setCursor(0, 1);
    lcd.print("0.00 Wh");

    delay(1000);
  }

  // Change LCD screen every 2 seconds
  if (currentTime - lastDisplay >= 2000) {

    lastDisplay = currentTime;

    static bool screen = false;

    screen = !screen;

    lcd.clear();

    if (screen == false) {

      lcd.setCursor(0, 0);
      lcd.print("LDR:");
      lcd.print(ldrValue);

      lcd.setCursor(0, 1);
      lcd.print(condition);
      lcd.print(" ");
      lcd.print(brightness);
      lcd.print("%");

    }
    else {

      lcd.setCursor(0, 0);
      lcd.print("POWER:");
      lcd.print(power, 2);
      lcd.print("W");

      lcd.setCursor(0, 1);
      lcd.print("ENERGY:");
      lcd.print(energyWh, 2);
      lcd.print("Wh");
    }
  }

  delay(100);
}