Spark Core compatible Dallas DS2438 sensor library
===

This library is a port of the Arduino Dallas DS2438 Sensor library. Some includes have been fixed, but the libary is otherwise untouched.

_**Note:** This library depends on the OneWire library, so be sure to include it in your project too._

Original repository by Joe Bechter: [arduino-onewire-DS2438](https://github.com/jbechter/arduino-onewire-DS2438).

> This library supports the following devices:
> 
> * DS2438

> You will need a pull-up resistor of about 5 KOhm between the 1-Wire data line
> and your 5V power. 

### Example code
**!! _Make sure to include the libraries !!_**

       // define the 1-Wire address of the DS2438 battery monitor here (lsb first)
       uint8_t DS2438_address[] = { 0x26, 0x45, 0xe6, 0xf7, 0x00, 0x00, 0x00, 0x4e };

	// Init Dallas on pin digital pin 3
	OneWire ow(D3);
        DS2438 ds2438(&ow, DS2438_address);
	
	void setup(){
		ds2438.begin();
	}
	
	void loop(){
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
