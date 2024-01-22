#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#include <Servo.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define DHT_PIN 2    // Pin untuk sensor DHT11
#define FAN_PIN_ENA 3 // Pin Enable Motor Driver untuk kipas
#define FAN_PIN_IN1 4 // Pin Input 1 Motor Driver untuk kipas
#define FAN_PIN_IN2 5 // Pin Input 2 Motor Driver untuk kipas

#define ULTRASONIC_TRIG_PIN 8
#define ULTRASONIC_ECHO_PIN 7
#define SERVO_PIN_1 10
#define SERVO_PIN_2 13
#define LDR_PIN A0
#define LED_PIN 12

Servo myServo_1;
Servo myServo_2;
DHT dht(DHT_PIN, DHT11);

void setup() {
  Serial.begin(9600);

  // Motor driver setup
  pinMode(FAN_PIN_ENA, OUTPUT);
  pinMode(FAN_PIN_IN1, OUTPUT);
  pinMode(FAN_PIN_IN2, OUTPUT);

  // OLED Display setup
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }

  delay(2000);
  display.clearDisplay();
  display.display();
  dht.begin();

  // Ultrasonic sensor and servo setup
  pinMode(ULTRASONIC_TRIG_PIN, OUTPUT);
  pinMode(ULTRASONIC_ECHO_PIN, INPUT);
  pinMode(SERVO_PIN_1, OUTPUT);
  myServo_1.attach(SERVO_PIN_1);

  // LDR and LED setup for window control
  pinMode(LDR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(SERVO_PIN_2, OUTPUT);
   myServo_2.attach(SERVO_PIN_2);
}

void loop() {
  delay(1000);

  // Read temperature from DHT sensor
  float suhu = dht.readTemperature();
  float humi = dht.readHumidity();

  if (isnan(suhu)) {
    Serial.println(F("Gagal Baca Data DHT sensor!"));
    return;
  }

  // Display temperature on OLED
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Temp: ");
  display.print(suhu);
  display.print(" C");
  display.setCursor(0, 10);
  display.print("Humidity: ");
  display.print(humi);
  display.print(" %");
  display.setCursor(0, 20);
  display.print("UPCI UYEE");
  display.display();

  Serial.print("Temp: ");
  Serial.println(suhu);
  Serial.print("Humi: ");
  Serial.println(humi);

  // Check if temperature is above 35 degrees
  if (suhu < 30.0) {
    startFan();  // Function to start the fan
  } else {
    stopFan();   // Function to stop the fan
  }

  // Ultrasonic sensor control for door
  long duration, distance;
  // Send ultrasonic pulse
  digitalWrite(ULTRASONIC_TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASONIC_TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_TRIG_PIN, LOW);
  // Receive bounce-back time
  duration = pulseIn(ULTRASONIC_ECHO_PIN, HIGH);
  // Calculate distance based on bounce-back time
  distance = duration/58.2;

  Serial.print("Jarak(cm): ");
  Serial.println(distance);

  // Control door based on distance
  if (distance < 10) {  // Adjust the distance value as needed
    openDoor();
  } else {
    closeDoor();
  }

  // LDR sensor control for window
  int ldrValue = analogRead(LDR_PIN);
  Serial.print("Nilai LDR: ");
  Serial.println(ldrValue);

  // Control window and LED based on LDR value
  if (ldrValue < 500) {  // Adjust the LDR value as needed
    openWindow();
    digitalWrite(LED_PIN, LOW);  // Turn off LED when it's bright
  } else {
    closeWindow();
    digitalWrite(LED_PIN, HIGH); // Turn on LED when it's dark
  }

  delay(1000); // Delay 5 seconds between readings
}

void startFan() {
  Serial.println("Menyalakan Kipas");

  // Turn on the motor by providing PWM signal to the Enable pin
  analogWrite(FAN_PIN_ENA, 255);

  // Set motor driver inputs to rotate the fan
  digitalWrite(FAN_PIN_IN1, HIGH);
  digitalWrite(FAN_PIN_IN2, LOW);
}

void stopFan() {
  Serial.println("Mematikan Kipas");

  // Turn off the motor by providing PWM signal to the Enable pin
  analogWrite(FAN_PIN_ENA, 0);

  // Set motor driver inputs to stop the fan
  digitalWrite(FAN_PIN_IN1, LOW);
  digitalWrite(FAN_PIN_IN2, LOW);
}

void openDoor() {
  Serial.println("Membuka pintu");
  myServo_1.write(90); // Servo position to open the door
  delay(1000);       // Wait for 1 second to ensure the door is fully open
}

void closeDoor() {
  Serial.println("Menutup pintu");
  myServo_1.write(0); // Servo position to close the door
  delay(1000);      // Wait for 1 second to ensure the door is fully closed
}

void openWindow() {
  Serial.println("Membuka jendela");
  myServo_2.write(90);  // Servo position to open the window
  delay(1000);        // Wait for 1 second to ensure the window is fully open
}

void closeWindow() {
  Serial.println("Menutup jendela");
  myServo_2.write(0);   // Servo position to close the window
  delay(1000);        // Wait for 1 second to ensure the window is fully closed
}
