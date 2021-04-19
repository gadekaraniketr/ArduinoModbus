// Arduino with more than 1 serial port
// example: Mega or Due

#include <ArduinoModbus.h>
const int numInputRegisters = 13;

void setup() {
	Serial.begin(19200);
	
	//Start Modbus client on Serial1
	//ModbusRTUClient.begin(int SerialPortNo, int BaudRate);
    ModbusRTUClient.begin(1, 19200);
    
    // start the Modbus RTU server, with serial port 2, (slave) id 1 and 19200 baud
    //ModbusRTUServer.begin(int SerialPortNo, int SlaveID, int BaudRate);
	ModbusRTUServer.begin(2, 1, 19200);
    ModbusRTUServer.configureInputRegisters(0x00, numInputRegisters);
}

void loop() {

	Serial.print("Reading input register values ... ");

	// read 10 dsicrete input values from (slave) id 1,
	if (!ModbusRTUClient.requestFrom(1, INPUT_REGISTERS, 0x00, numInputRegisters)) {
		Serial.print("failed! ");
		Serial.println(ModbusRTUClient.lastError());
	} else {
		Serial.println("success");
		
		int i = 0;
		while (ModbusRTUClient.available()) {
			word modReg = ModbusRTUClient.read();
			ModbusRTUServer.inputRegisterWrite(i++, modReg);
			Serial.print(modReg);
			Serial.print(' ');
		}
		Serial.println();
	}
	
	ModbusRTUServer.poll();
}
