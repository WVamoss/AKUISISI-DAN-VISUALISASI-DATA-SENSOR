#include <LiquidCrystal.h>
#include <Encoder.h>
#define ENCODER_OPTIMIZE_INTERRUPTS

Encoder encMotor(50, 52);
Encoder encModule(24, 25);  // Potensio Encoder

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

const int dirMotor = 2;
const int pwmMotor = 3;
const int PULSE_PER_REV = 600;

// Variabel sistem
unsigned long lastTime = 0;
long oldPosition = 0;
float rpm = 0;
int pwmValue = 0;
long potValue = 0;

// Timing
unsigned long lastSerialPrint = 0;
const unsigned long SERIAL_INTERVAL = 1000;

void setup() {
  lcd.begin(16, 2);
  lcd.print("SISTEM MOTOR DC");
  lcd.setCursor(0, 1);
  lcd.print("MODUL DAY 6");
  delay(2000);
  lcd.clear();
  
  pinMode(dirMotor, OUTPUT);
  pinMode(pwmMotor, OUTPUT);
  pinMode(26, INPUT_PULLUP);
  
  digitalWrite(dirMotor, LOW);
  
  Serial.begin(9600);
  
  // Header sederhana
  Serial.println();
  Serial.println("=== SISTEM MONITORING MOTOR DC ===");
  Serial.println("Kontrol: Putar Potensio | Reset: Tombol Pin 26");
  Serial.println("-----------------------------------");
}

void loop() {
  unsigned long currentTime = millis();
  
  // Baca potensio encoder
  long newPotValue = encModule.read();
  
  // Update jika perubahan signifikan
  if (abs(newPotValue - potValue) >= 5) {
    potValue = newPotValue;
    pwmValue = map(abs(potValue), 0, 800, 0, 255);
    pwmValue = constrain(pwmValue, 0, 255);
    analogWrite(pwmMotor, pwmValue);
    
    // Tampilkan perubahan potensio langsung
    Serial.print("Potensio: ");
    Serial.print(potValue);
    Serial.print(" -> PWM: ");
    Serial.println(pwmValue);
  }
  
  // Hitung RPM setiap 1 detik
  if (currentTime - lastTime >= 1000) {
    long newPosition = encMotor.read();
    long pulseCount = newPosition - oldPosition;
    rpm = (abs(pulseCount) * 60.0) / PULSE_PER_REV;
    oldPosition = newPosition;
    lastTime = currentTime;
  }
  
  // Baca tegangan
  int adcValue = analogRead(A10);
  float voltage = (adcValue * 3.3 / 1024.0) * (30000 + 3300) / 3300;
  
  // Update LCD
  lcd.setCursor(0, 0);
  lcd.print("POT:");
  lcd.print(potValue);
  lcd.print("    ");
  
  lcd.setCursor(0, 1);
  lcd.print("PWM:");
  lcd.print(pwmValue);
  lcd.print(" RPM:");
  lcd.print((int)rpm);
  
  // Print ke Serial Monitor setiap 1 detik - FORMAT SIMPLE
  if (currentTime - lastSerialPrint >= SERIAL_INTERVAL) {
    Serial.print("PWM: ");
    Serial.print(pwmValue);
    
    Serial.print("  |  RPM: ");
    Serial.print((int)rpm);
    
    Serial.print("  |  Tegangan: ");
    Serial.print(voltage, 1);
    Serial.print("V");
    
    // Tambahan: status singkat
    if (pwmValue == 0) {
      Serial.print("  |  MOTOR DIAM");
    } else if (rpm < 500) {
      Serial.print("  |  PUTARAN RENDAH");
    } else if (rpm < 1500) {
      Serial.print("  |  PUTARAN SEDANG");
    } else {
      Serial.print("  |  PUTARAN TINGGI");
    }
    
    Serial.println(); // Pindah baris
    
    lastSerialPrint = currentTime;
  }
  
  // Reset sistem
  if (digitalRead(26) == LOW) {
    delay(50);
    if (digitalRead(26) == LOW) {
      encModule.write(0);
      encMotor.write(0);
      pwmValue = 0;
      analogWrite(pwmMotor, 0);
      potValue = 0;
      rpm = 0;
      
      lcd.clear();
      lcd.print("SISTEM DI-RESET");
      delay(1000);
      lcd.clear();
      
      Serial.println();
      Serial.println("*** SYSTEM RESET ***");
      Serial.println("-----------------------------------");
    }
  }
  
  delay(100);
}
