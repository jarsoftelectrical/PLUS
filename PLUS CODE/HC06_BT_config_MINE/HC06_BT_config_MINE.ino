/*
	http://giltesa.com/?p=11738
	09/08/2012
	(CC) BY-NC-SA: giltesa.com

ConfigBluetooth HC-06 from Arduino.
Change name, password and baud using serial port, only configurate one time
After upload code you have 10 seconds to connect the module
BT ---- Arduino
TX ----> RX
RX <---- TX

Once the LED off configuration will start and at the end LED will blink
After this you can pair your module
*/
// Options:

	char ssid[10]		= "Zowi";	// Name for Bluetooth.
	char baudios		 = '5';		   // 1=>1200 baudios, 2=>2400, 3=>4800, 4=>9600 (default), 5=>19200, 6=>38400, 7=>57600, 8=>115200
	char password[10]	= "1234";		// Password for pairing
#include <SoftwareSerial.h>

SoftwareSerial mySerial(8, 9); // RX, TX
void setup()
{
	mySerial.begin(9600);
	
	// Waiting time (10 seconds):
		pinMode(13,OUTPUT);
		digitalWrite(13,HIGH);
		delay(10000);
		digitalWrite(13,LOW);
	
mySerial.print("AT"); delay(1000); // Now configuration start

mySerial.print("AT+NAME"); mySerial.print(ssid); delay(1000);   // Change Name of BT

mySerial.print("AT+BAUD"); mySerial.print(baudios); delay(1000);    // Change Baud

mySerial.print("AT+PIN"); mySerial.print(password); delay(1000);	    // Change Password
}

void loop()
{
	// After LED Blinking is finish.
	digitalWrite(13, !digitalRead(13));
	delay(500);
}
