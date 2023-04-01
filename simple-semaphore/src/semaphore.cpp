#include <Arduino.h>

#define BUTTON 2
#define DRIVER_RED_LED 13
#define DRIVER_YELLOW_LED 12
#define DRIVER_GREEN_LED 11
#define PEDEST_RED_LED 9
#define PEDEST_YELLOW_LED 8
#define PEDEST_GREEN_LED 7

// Function that defines the configuration for the driver and pedestrian LEDs
void setLeds(int driverRedLed, int driverYellowLed, int driverGreenLed, int pedestRedLed, int pedestYellowLed, int pedestGreenLed) {
  digitalWrite(DRIVER_RED_LED, driverRedLed);
  digitalWrite(DRIVER_YELLOW_LED, driverYellowLed);
  digitalWrite(DRIVER_GREEN_LED, driverGreenLed);
  digitalWrite(PEDEST_RED_LED, pedestRedLed);
  digitalWrite(PEDEST_YELLOW_LED, pedestYellowLed);
  digitalWrite(PEDEST_GREEN_LED, pedestGreenLed);
}

void setup() {
  pinMode(BUTTON, INPUT);
  pinMode(DRIVER_RED_LED, OUTPUT);  
  pinMode(DRIVER_YELLOW_LED, OUTPUT);
  pinMode(DRIVER_GREEN_LED, OUTPUT);  
  pinMode(PEDEST_RED_LED, OUTPUT);  
  pinMode(PEDEST_YELLOW_LED, OUTPUT);
  pinMode(PEDEST_GREEN_LED, OUTPUT);
  
  // Intial Configuration
  setLeds(LOW, LOW, HIGH, HIGH, LOW, LOW);
}

void loop() {  
  int button_status = digitalRead(BUTTON);

  // If the button is pressed -> The sequences start
  // Sequence -> Configurations for the driver and pedestrian LEDs
  if(button_status) {    
    setLeds(LOW, HIGH, LOW, HIGH, LOW, LOW);
    delay(5000);
    setLeds(HIGH, LOW, LOW, LOW, LOW, HIGH);
    delay(10000);
    setLeds(HIGH, LOW, LOW, LOW, HIGH, LOW);
    delay(5000);
    setLeds(LOW, LOW, HIGH, HIGH, LOW, LOW);
    delay(10000);
  }
}