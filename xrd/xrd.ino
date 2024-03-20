/*
 Name:		xrd.ino
 Created:	3/20/2024 4:12:13 PM
 Author:	Deci
*/
#include <IRremote.hpp>

const uint_fast8_t p = 3;
// the setup function runs once when you press reset or power the board
void setup()
{
	Serial.begin(9600);
	IrReceiver.begin(p, ENABLE_LED_FEEDBACK);
	IrReceiver.enableIRIn();
}

// the loop function runs over and over again until power down or reset
void loop()
{
	if (IrReceiver.decode()) {
		auto data = IrReceiver.decodedIRData;
		Serial.println(data.address, HEX);
		Serial.println(data.command, HEX);
		IrReceiver.resume();
	}
	// delay(3000);
}
