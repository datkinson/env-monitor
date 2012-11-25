//Authors: Daniel Atkinson
//Version: 0.1

//Imports
#include <stdio.h>
#include <string.h>

//Declare variables
String message ="";
int temperature_reading = 0;
int light_reading = 0;
int motion_reading = 0;

//Declare hardware assiciations
int temperature_pin = A0; //Analogue pin connected to temperature sensor
int light_pin = A1; //Analogue pin connected to light dependant resistor
int motion_pin = A2; //Analogue pin connected to the motion sensor

//Define magic numbers
int interval = 60;
int motion_trigger = 100; //input that is recieved when motion sensor is triggered
//end magic numbers

void setup(){
	Serial.begin(57600);
}

void loop(){
	check_motion();
	collect_data();
	post_data();
	delay(interval);
}

void check_motion(){
	motion_reading = analogRead(motion_pin);
	if(motion_reading > motion_trigger){
		collect_data();
		post_data();
		delay(interval);
	}
}

void collect_data(){
	temperature_reading = analogRead(temperature_pin);
	light_reading = analogRead(light_pin);
	motion_reading = analogRead(motion_pin);
}

//possibly have this as a boolean which requires a response from the recording software
void post_data(){
	// Letter  determings what data is coming, ":" means data follows, "," means end of current data, "\n" means end of current stream
	message = "T:" + temperature_reading + ",L:" + light_reading + ",M:" + motion_reading + "\n";
	Serial.write(message);
}
