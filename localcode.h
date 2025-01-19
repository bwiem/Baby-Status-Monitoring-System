#include <Wire.h>
#include <LiquidCrystal_I2C.h>


#define POT_PIN 34    // GPIO 34 for Potentiometer output
#define GREEN_LED 18  // GPIO 18 for Green LED (baby is sleeping)
#define YELLOW_LED 19 // GPIO 19 for Yellow LED (baby is awake)
#define RED_LED 23    // GPIO 23 for Red LED (baby is crying)


// Initialize the LCD: I2C address 0x27, 16 columns, 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);


  // Initialize Serial Monitor
  Serial.begin(9600);
  Serial.println("ESP32 Potentiometer with LCD and LEDs");


  // Initialize the LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Initializing...");
  delay(2000);
}


void loop() {
  int potValue = analogRead(POT_PIN);  // Read potentiometer value
  Serial.print("Potentiometer Value: ");
  Serial.println(potValue);           // Print value for debugging


  // Determine baby's status
  if (potValue <= 400) { // Baby is sleeping
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);


    // Display on LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Baby is sleeping");
    Serial.println("Baby is sleeping (Green LED ON)");
  } else if (potValue > 400 && potValue <= 2500) { // Baby is awake
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, LOW);


    // Display on LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Baby is awake");
    Serial.println("Baby is awake (Yellow LED ON)");
  } else { // Baby is crying
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, HIGH);


    // Display on LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Baby is crying");
    Serial.println("Baby is crying (Red LED ON)");
  }


  delay(500); // Small delay for stability
}
