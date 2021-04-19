# ArduinoModbus
Modbus interface on multiple port. 

# Note:
- Only Tested with Arduino Mega 2560 and RTU devices.

# OLD API
1. ModbusRTUClient.begin(int BaudRate);
2. ModbusRTUServer.begin(int SlaveID, int BaudRate);

# NEW API
1. ModbusRTUClient.begin(int SerialPortNo, int BaudRate);
2. ModbusRTUServer.begin(int SerialPortNo, int SlaveID, int BaudRate);


