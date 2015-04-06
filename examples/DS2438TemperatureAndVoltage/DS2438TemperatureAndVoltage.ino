// define the 1-Wire address of the DS2438 battery monitor here (lsb first)
uint8_t DS2438_address[] = { 0x26, 0x45, 0xe6, 0xf7, 0x00, 0x00, 0x00, 0x4e };

OneWire ow(D3);
DS2438 ds2438(&ow, DS2438_address);

void setup() {
    Serial.begin(9600);
    ds2438.begin();
}

void loop() {
    ds2438.update();
    if (ds2438.isError()) {
        Serial.println("Error reading from DS2438 device");
    } else {
        Serial.print("Temperature = ");
        Serial.print(ds2438.getTemperature(), 1);
        Serial.print("C, Channel A = ");
        Serial.print(ds2438.getVoltage(DS2438_CHA), 1);
        Serial.print("v, Channel B = ");
        Serial.print(ds2438.getVoltage(DS2438_CHB), 1);
        Serial.println("v.");
    }
    delay(500);
}
