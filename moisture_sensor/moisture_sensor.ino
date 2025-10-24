// Modified version of the code found at
// https://docs.sunfounder.com/projects/3in1-kit-v2/en/latest/iot_project/iot_plant_monitor.html

#include <DHT.h>

#define DHT_SENSOR_PIN 4       // Set the pin connected to the DHT11 data pin

#define LIGHT_SENSOR_PIN A0

#define MOISTURE_SENSOR_PIN A1
// Threshold value taken from
// https://lastminuteengineers.com/capacitive-soil-moisture-sensor-arduino/
#define WATERING_THRESHOLD 278
#define WATERING_DURATION (2 * 1000)

#define PUMP_PIN 8

#define TESTING_DELAY (1 * 1000)

DHT dht(DHT_SENSOR_PIN, DHT11);

void setup() {
  // Debug console
  Serial.begin(9600);

  dht.begin();

  pinMode(PUMP_PIN, OUTPUT);
}

void loop() {
  int moisture_level = analogRead(MOISTURE_SENSOR_PIN);
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  int light_level = analogRead(LIGHT_SENSOR_PIN);
  // 10k r2 voltage divider
  // Photo diode resistances taken from
  // https://www.sunfounder.com/products/100pcs-photoresistor-photo-light-sensitive-resistor-5516
  // 200kohm in darkness
  // 5-10kohm in bright light
  // Volts ~[0.24V, 3.3V]
  // ADC ~[74, 1024]
  light_level = map(light_level, 74, 1024, 0, 100);

  Serial.print("Moisture Level:");
  Serial.print(moisture_level);
  Serial.print(", Humidity: ");
  Serial.print(humidity);
  Serial.print("%, Temperature: ");
  Serial.print(temperature);
  Serial.print("deg C, Light Level: ");
  Serial.println(light_level);

  if(moisture_level < WATERING_THRESHOLD) {
    Serial.println("Watering!");

    digitalWrite(PUMP_PIN, HIGH);
    delay(WATERING_DURATION);
    digitalWrite(PUMP_PIN, LOW);

    Serial.println("Done");
  }

  delay(TESTING_DELAY);
}

