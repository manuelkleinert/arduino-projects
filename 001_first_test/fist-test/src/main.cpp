#include <Arduino.h>
#include <dht.h>
#include <Servo.h>
// #include <Stepper.h>
// #include <LiquidCrystal.h>

// int SPU = 2048; // Schritte pro Umdrehung.
// Stepper Motor(SPU, 3,5,4,6); // Der Schrittmotor erhält die Bezeichnung "Motor" und es wird angegeben an welchen Pins der Motor angeschlossen ist.


// LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
// LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

// int Led_Rot = 2; //select the pin for the red LED
// int Led_Blau = 3; // select the pin for the  blue LED
// int Led_Gruen = 4;// select the pin for the green LED
//
// int val;

const int ledPin = 13;
int incomingByte;


int temp, chk, light, volum;
float R1 = 10000;
float logR2, R2, T, Tc, Tf;
Servo servo;

dht DHT;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode (2, INPUT) ;

  servo.attach(5);
  servo.write(0);

  // pinMode(Led_Rot, OUTPUT);
  // pinMode(Led_Blau, OUTPUT);
  // pinMode(Led_Gruen, OUTPUT);
  // Serial.begin(9600);

  // lcd.begin(16, 2);
  // lcd.print("Hallo Joerg");
  // lcd.setCursor(0,1);
  // lcd.print("Bis am Mittag");

  // Motor.setSpeed(10);
}

void loop() {
  // Serial.println("Hello world from Ardunio!"); // write a string


  if (Serial.available() > 0) {
      // read the oldest byte in the serial buffer:
      incomingByte = Serial.read();
      // if it's a capital H (ASCII 72), turn on the LED:
      if (incomingByte == 'H') {
        digitalWrite(ledPin, HIGH);
      }
      // if it's an L (ASCII 76) turn off the LED:
      if (incomingByte == 'L') {
        digitalWrite(ledPin, LOW);
      }
    }


    light = analogRead(5);
    temp = analogRead(0);
    volum = analogRead(2);
    // volum = digitalRead(2);

    R2 = R1 * (1023.0 / (float)temp - 1.0);
    logR2 = log(R2);
    T = 1 / (0.001129148 + (0.000234125 * logR2) + (0.0000000876741 * logR2 * logR2 * logR2));
    Tc = T - 273.15;
    Tf = (Tc * 9.0)/ 5.0 + 32.0;

    Serial.print("Temperature: ");
    Serial.print(Tf);
    Serial.print(" F; ");
    Serial.print(Tc);
    Serial.print(" C");


    chk = DHT.read11(7);

    Serial.print(" ---- ");

    Serial.print("Temperature = ");
    Serial.print(DHT.temperature - 4);
    Serial.print(" Humidity = ");
    Serial.print(DHT.humidity);

    Serial.print(" light = ");
    Serial.print(light);

    Serial.print(" volum = ");
    Serial.println(volum);


    if (light < 500) {
      digitalWrite(ledPin, HIGH);
      servo.write(0);
    } else {
      digitalWrite(ledPin, LOW);
      servo.write(120);
    }

    delay(2000);

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
