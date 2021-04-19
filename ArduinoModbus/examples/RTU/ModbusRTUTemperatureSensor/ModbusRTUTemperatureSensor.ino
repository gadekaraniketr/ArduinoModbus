/*
  Modbus RTU Temeperature Sensor

  This sketch shows you how to interact with a Modbus RTU temperature and humidity sensor.
  It reads the temperature and humidity values every 5 seconds and outputs them to the
  serial monitor.
*/

#include <ArduinoModbus.h>

float temperature;
float humidity;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("Modbus Temperature Humidity Sensor");
  // start the Modbus RTU client
  if (!ModbusRTUClient.begin(0, 9600)) {
    Serial.println("Failed to start Modbus RTU Client!");
    while (1);
  }
}

void loop() {

  // send a Holding registers read request to (slave) id 1, for 2 registers
  if (!ModbusRTUClient.requestFrom(1, HOLDING_REGISTERS, 0x00, 2)) {
    Serial.print("failed to read registers! ");
    Serial.println(ModbusRTUClient.lastError());
  } else {
    // If the request succeeds, the sensor sends the readings, that are
    // stored in the holding registers. The read() method can be used to
    // get the raw temperature and the humidity values.
    short rawtemperature = ModbusRTUClient.read();
    short rawhumidity = ModbusRTUClient.read();

    // To get the temperature in Celsius and the humidity reading as
    // a percentage, divide the raw value by 10.0.
    temperature = rawtemperature / 10.0;
    humidity = rawhumidity / 10.0;
    Serial.println(temperature);
    Serial.println(humidity);
  }

  delay(5000);
}
