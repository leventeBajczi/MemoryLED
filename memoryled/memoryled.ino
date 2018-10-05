#include <Arduino.h>

#include "MemoryledRequired.h"
#include "Memoryled.h"

#include "statetimer.h"

Memoryled handle;

void delay3(int milli)
{
  delay(milli*2);
}


void setup() {
    for(int i = 0; i < 5; i++) {
        pinMode(i, INPUT);
    }
    for(int i = 8; i < 13; i++) {
        pinMode(i, OUTPUT);
    }

	initTimers();

	memoryled_init(&handle);
	memoryled_enter(&handle);
}

int lights[5];
void memoryledIfaceLED_kikapcs(const Memoryled* handl){
	for(int i = 8; i <= 12; i++) {
			digitalWrite(i, LOW);
	}
}

void memoryledIfaceLED_indulj(const Memoryled* handl){
	digitalWrite(10, HIGH);
	delay3(75);
	digitalWrite(10, LOW);
	for(int i = 0; i < 25; i++) {
		digitalWrite(10, HIGH);
		delay3(1);
		digitalWrite(10, LOW);
		digitalWrite(9, HIGH);
		delay3(1);
		digitalWrite(9, LOW);
		digitalWrite(11, HIGH);
		delay3(1);
		digitalWrite(11, LOW);
	}

	for(int i = 0; i < 25; i++) {
		for(int n = 8; n <= 12; n++) {
			digitalWrite(n, HIGH);
			delay3(1);
			digitalWrite(n, LOW);
		}
	}
}
void memoryledIface_del(const Memoryled* handl, sc_integer milli)
{
	delay3(milli);
}

void memoryled_setTimer(Memoryled* handl, const sc_eventid evid, sc_integer time_ms,
		const sc_boolean periodic) {

//	setTimer(&handl, evid, time_ms, periodic,(raiseEventCallback_t)memoryled_raiseTimeEvent);
}

void memoryled_unsetTimer(Memoryled* handl, const sc_eventid evid) {
	unsetTimer(evid);
}
static unsigned long lastCallTime = 0;
static void checkTimersWrapper(void){
	
	unsigned long now = millis();

	int deltaT_ms = now - lastCallTime;
	lastCallTime = now;

	if(deltaT_ms)
		checkTimers(deltaT_ms);
}


void memoryledIfaceLED_veletlenVillanasok(const Memoryled* handl, sc_integer curLevel){
	randomSeed(analogRead(28));
	lights[curLevel]=random(1,6);
	for(int i = 0; i <= curLevel; i++) {
		digitalWrite(lights[i]+7, HIGH);
		delay3(100);
		digitalWrite(lights[i]+7, LOW);
		delay3(150);
	}
}

void memoryledIfaceLED_partyTime(const Memoryled* handl)
{
	 //sorfeny
	for(int i = 0; i < 5; i++) {
		for(int n = 8; n <= 12; n++) {
			digitalWrite(n, HIGH);
			delay3(100);
			digitalWrite(n, LOW);
			delay3(1);
		}
	}

	//paros-paratlan
	for(int i = 0; i < 5; i++) {
		for(int n = 0; n < 100; n++) {
			digitalWrite(9, HIGH);
			delay3(1);
			digitalWrite(9, LOW);
			digitalWrite(11, HIGH);
			delay3(1);
			digitalWrite(11, LOW);
		}

		for(int n = 0; n < 100; n++) {
			digitalWrite(8, HIGH);
			delay3(1);
			digitalWrite(8, LOW);
			digitalWrite(10, HIGH);
			delay3(1);
			digitalWrite(10, LOW);
			digitalWrite(12, HIGH);
			delay3(1);
			digitalWrite(12, LOW);
		}
	}

	//oda-vissza
	for(int i = 0; i < 3; i++) {
		int tmp;
		for(int n = 12; n >= 8; n--) {
			for(int m = 0; m < 100; m++) {
				tmp = n;
				while(tmp >= 8) {
					digitalWrite(tmp, HIGH);
					delay3(1);
					digitalWrite(tmp, LOW);
					tmp--;
				}
			}
		}
		delay3(50);
		for(int n = 8; n <= 12; n++) {
			for(int m = 0; m < 100; m++) {
				tmp = n;
				while(tmp <= 12) {
					digitalWrite(tmp, HIGH);
					delay3(1);
					digitalWrite(tmp, LOW);
					tmp++;
				}
			}
		}
		delay3(50);
	}

	//paros-paratlan
	for(int i = 0; i < 5; i++) {
		for(int n = 0; n < 100; n++) {
			digitalWrite(9, HIGH);
			delay3(1);
			digitalWrite(9, LOW);
			digitalWrite(11, HIGH);
			delay3(1);
			digitalWrite(11, LOW);
		}

		for(int n = 0; n < 100; n++) {
			digitalWrite(8, HIGH);
			delay3(1);
			digitalWrite(8, LOW);
			digitalWrite(10, HIGH);
			delay3(1);
			digitalWrite(10, LOW);
			digitalWrite(12, HIGH);
			delay3(1);
			digitalWrite(12, LOW);
		}
	}
}

void memoryledIfaceLED_szomoru(const Memoryled* handl)
{
	for(int i = 0; i < 25; i++) {
		for(int n = 8; n <= 12; n++) {
			digitalWrite(n, HIGH);
			delay3(1);
			digitalWrite(n, LOW);
		}
	}

	for(int i = 0; i < 25; i++) {
		digitalWrite(10, HIGH);
		delay3(1);
		digitalWrite(10, LOW);
		digitalWrite(9, HIGH);
		delay3(1);
		digitalWrite(9, LOW);
		digitalWrite(11, HIGH);
		delay3(1);
		digitalWrite(11, LOW);
	}

	digitalWrite(10, HIGH);
	delay3(75);
	digitalWrite(10, LOW);

	delay3(75);
}

void memoryledIfaceLED_ujSzintKezdes(const Memoryled* handl)
{
	delay3(50);
	for(int n = 0; n < 25; n++) {
		for(int i = 8; i <= 12; i++) {
			digitalWrite(i, HIGH);
			delay3(1);
			digitalWrite(i, LOW);
		}
	}
}

void raiseEvents() {
// e.g.
// if (buttonPressed) {
//     statemachine->raiseXYZEvent();
// }


	if(digitalRead(0)==HIGH) {

		delay3(20);
		if(digitalRead(0)==HIGH){
			digitalWrite(8, HIGH);
			delay3(200);
			handle.ifaceGMB.gmb1_raised = bool_true;
		}
		digitalWrite(8, LOW);
	}
	else if(digitalRead(1)==HIGH) {

		delay3(20);
		if(digitalRead(1)==HIGH){
			digitalWrite(9, HIGH);
			delay3(200);
			handle.ifaceGMB.gmb2_raised = bool_true;

		}
		digitalWrite(9, LOW);
	}
	else if(digitalRead(2)==HIGH) {

		delay3(20);
		if(digitalRead(2)==HIGH){
			digitalWrite(10, HIGH);
			delay3(200);
			
			handle.ifaceGMB.gmb3_raised = bool_true;		
		}
		digitalWrite(10, LOW);
	}
	else if(digitalRead(3)==HIGH) {

		delay3(20);
		if(digitalRead(3)==HIGH){
			digitalWrite(11, HIGH);
			delay3(200);
			handle.ifaceGMB.gmb4_raised = bool_true;
		}
		digitalWrite(11, LOW);
	}
	else if(digitalRead(4)==HIGH) {

		delay3(20);
		if(digitalRead(4)==HIGH){
			digitalWrite(12, HIGH);
			delay3(200);
			handle.ifaceGMB.gmb5_raised = bool_true;
		}
		digitalWrite(12, LOW);
	}
}

void loop() {
  memoryledIfaceVLSZ_set_kov(&handle, lights[memoryledIface_get_szml(&handle)]);
	raiseEvents();
	checkTimersWrapper();

	memoryled_runCycle(&handle);
}
