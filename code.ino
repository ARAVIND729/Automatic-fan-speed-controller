#include <LiquidCrystal.h>          // LCD library for 16x2 display

// LCD pin configuration: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

int tempPin = A0;                   // Analog pin connected to LM35 temperature sensor
int fan = 11;                       // PWM pin connected to fan (via transistor/relay)
int led = 8;                        // LED pin for over-temperature indication

int temp;                           // Stores temperature value in °C
int tempMin = 30;                   // Minimum temperature to start the fan
int tempMax = 60;                   // Temperature at which fan should run at full speed

int fanSpeed;                       // Actual PWM value sent to fan
int fanLCD;                         // Fan speed percentage displayed on LCD

void setup() {
  pinMode(fan, OUTPUT);             // Set fan pin as output
  pinMode(led, OUTPUT);             // Set LED pin as output
  pinMode(tempPin, INPUT);          // Set temperature sensor pin as input

  lcd.begin(16, 2);                 // Initialize 16x2 LCD
  Serial.begin(9600);               // Start serial communication for debugging
}

void loop() {

  temp = readTemp();                // Read temperature from LM35
  Serial.print(temp);               // Print temperature to Serial Monitor

  // Case 1: Temperature below minimum threshold
  if (temp < tempMin) {
    fanSpeed = 0;                   // Fan OFF
    analogWrite(fan, fanSpeed);     // Write 0 PWM to fan
    fanLCD = 0;                     // Display 0% fan speed
    digitalWrite(fan, LOW);         // Ensure fan is fully OFF
  }

  // Case 2: Temperature between minimum and maximum
  if ((temp >= tempMin) && (temp <= tempMax)) {

    fanSpeed = temp;                // Base fan speed on temperature
    fanSpeed = 1.5 * fanSpeed;      // Scale speed (approx. PWM range)
    
    fanLCD = map(temp, tempMin, tempMax, 0, 100);  // Convert to percentage for LCD
    analogWrite(fan, fanSpeed);     // Apply PWM to fan
  }

  // Case 3: Temperature exceeds maximum limit
  if (temp > tempMax) {
    digitalWrite(led, HIGH);        // Turn ON warning LED
  } else {
    digitalWrite(led, LOW);         // Turn OFF warning LED
  }

  // LCD display — first line
  lcd.print("TEMP: ");
  lcd.print(temp);                  // Show temperature in °C
  lcd.print("C ");

  // LCD display — second line
  lcd.setCursor(0, 1);
  lcd.print("FANS: ");
  lcd.print(fanLCD);                // Show fan speed percentage
  lcd.print("%");

  delay(200);                       // Small delay for stability
  lcd.clear();                      // Clear LCD for next update
}

// Function to read LM35 temperature and convert to Celsius
int readTemp() {
  temp = analogRead(tempPin);       // Read ADC value (0–1023)
  return temp * 0.48828125;         // Convert ADC value to °C (LM35 scale)
}
