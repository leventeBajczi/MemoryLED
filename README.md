# MemoryLED
Memory game implementation on an Arduino with Yakindu SCT.

# Requirements

* Eclipse IDE with Yakindu SCT (with a working license) and [Arduino SCT Tools](https://github.com/wendehals/arduino_sct_tools) installed
* An Arduino (We used an ATMega328P with Arduino bootloader, but any arduino should work, just pay attention to the pin numbering)

# Project setup

* Create a new Arduino Project with YAKINDU Statechart
* Copy the SCT file you've downloaded into the model folder (you need to rename it both inside the editor and on the folder tree)
* Right-click on the .sgen file and Generate Code Artifacts
* Paste the following lines into the ArduinoMain.cpp (instead of the setup() already there):
```C++
void setup() {
	statemachine = new Memoryled();
	connector = new MemoryledConnector(statemachine);
	timer = new ATmega_Timer2(statemachine, connector);
	connector->customHandler = new CustomHandler;
	statemachine->setSCI_LED_OCB(connector->customHandler);

	statemachine->setTimer(timer);
	timer->start();
}
```
* Paste the files from the src folder into your src folder
* Rename the statemachine if needed (I used `memoryled` but it is up to you)

If you've done everything correctly, you should be able to [add a new target](https://github.com/wendehals/arduino_sct_tools/blob/master/plugins/org.yakindu.sct.arduino.help/md/ArduinoToolchainSetup.md), and then click `launch`.
