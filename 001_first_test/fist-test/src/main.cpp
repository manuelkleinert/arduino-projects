#include <Arduino.h>
// #include <Stepper.h>
#include <LiquidCrystal.h>

int SPU = 2048; // Schritte pro Umdrehung.
// Stepper Motor(SPU, 3,5,4,6); // Der Schrittmotor erhält die Bezeichnung "Motor" und es wird angegeben an welchen Pins der Motor angeschlossen ist.


LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
// LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

// int Led_Rot = 2; //select the pin for the red LED
// int Led_Blau = 3; // select the pin for the  blue LED
// int Led_Gruen = 4;// select the pin for the green LED
//
// int val;

void setup() {
  // pinMode(Led_Rot, OUTPUT);
  // pinMode(Led_Blau, OUTPUT);
  // pinMode(Led_Gruen, OUTPUT);
  // Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.print("Hallo Joerg");
  lcd.setCursor(0,1);
  lcd.print("Bis am Mittag");

  // Motor.setSpeed(10);
}

void loop() {
  // digitalWrite(2, 1);
  // digitalWrite(3, 0);
  // digitalWrite(4, 0);
  // delay(200);
  // digitalWrite(3, 1);
  // digitalWrite(2, 0);
  // digitalWrite(4, 0);
  // delay(200);
  // digitalWrite(3, 0);
  // digitalWrite(2, 0);
  // digitalWrite(4, 1);
  //
  // delay(200);

  // Motor.step(2048); // Der Motor macht 2048 Schritte, das entspricht einer Umdrehung.
  // delay(1000); // Durch diese Pause bleibt der Motor nach der Drehung für eine Sekunde stehen.
  // Motor.step(-2048); // Der Motor macht durch das Minuszeichen 2048 Schritte in die andere Richtung.
  // delay(1000); // Durch diese Pause bleibt der Motor nach der Drehung für eine Sekunde stehen.

  // Motor.step(analogRead(0)/100);

  //
  // lcd.setCursor(0, 1);
  // lcd.print(millis() / 1000);
}
