#include <Adafruit_MPU6050.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>

#define BUZZER_PIN 18 // Replace with the actual pin connected to the buzzer
#define TREMOR_THRESHOLD 15.0 // Adjust this threshold based on your requirements

int melody[] = {
  1500, 0, 1500, 0, 1500, 0, 1500, 0, 1500, 0, // Adjust the frequencies as needed
  0, // This 0 represents a pause
};

int noteDurations[] = {
  500, 200, 500, 200, 500, 200, 500, 200, 500, 200, // Adjust the durations as needed
  200, 
};

Adafruit_MPU6050 mpu;
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire);

void setup() {
  Serial.begin(115200);
  Serial.println("MPU6050 OLED demo");

  pinMode(BUZZER_PIN, OUTPUT);

  if (!mpu.begin()) {
    Serial.println("Sensor init failed");
    while (1)
      yield();
  }
  Serial.println("Found an MPU-6050 sensor");

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }
  display.display();
  delay(500);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setRotation(0);
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  // Check for hand tremor
  if (abs(a.acceleration.x) > TREMOR_THRESHOLD || 
      abs(a.acceleration.y) > TREMOR_THRESHOLD || 
      abs(a.acceleration.z) > TREMOR_THRESHOLD) {
    // Trigger alarm-like sound
    for (int thisNote = 0; thisNote < sizeof(melody) / sizeof(melody[0]); thisNote++) {
      int noteDuration = noteDurations[thisNote];
      int frequency = melody[thisNote];
      
      if (frequency == 0) {
        // Pause
        delay(noteDuration);
      } else {
        // Play the note
        tone(BUZZER_PIN, frequency, noteDuration);
        delay(noteDuration); // Wait for the note to complete
        noTone(BUZZER_PIN); // Stop the tone
      }
    }

    // Display tremor message on OLED
    display.setCursor(0, 20);
    display.println("Tremor Detected!");
    display.display();
    delay(2000); // Display message for 2 seconds
  }

  // Display accelerometer and gyroscope readings
  display.clearDisplay();
  display.setCursor(0, 0);

  Serial.print("Accelerometer ");
  Serial.print("X: ");
  Serial.print(a.acceleration.x, 1);
  Serial.print(" m/s^2, ");
  Serial.print("Y: ");
  Serial.print(a.acceleration.y, 1);
  Serial.print(" m/s^2, ");
  Serial.print("Z: ");
  Serial.print(a.acceleration.z, 1);
  Serial.println(" m/s^2");

  display.println("Accel - m/s^2");
  display.print(a.acceleration.x, 1);
  display.print(", ");
  display.print(a.acceleration.y, 1);
  display.print(", ");
  display.print(a.acceleration.z, 1);
  display.println("");

  display.display();
  delay(10);
}
