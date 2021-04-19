# ArduinoModbus
Modbus interface on multiple port.

# OLD API
ModbusRTUClient.begin(int BaudRate);
ModbusRTUServer.begin(int SlaveID, int BaudRate);

# NEW API
ModbusRTUClient.begin(int SerialPortNo, int BaudRate);
ModbusRTUServer.begin(int SerialPortNo, int SlaveID, int BaudRate);

Only Tested with Arduino Mega 2560
