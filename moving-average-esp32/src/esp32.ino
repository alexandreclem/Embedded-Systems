// LINK TO ACCESS THE PROJECT: https://wokwi.com/projects/353944127392283649 

#include "DHTesp.h"

// Task executed in core 0 (Read Values)
TaskHandle_t readValuesTask;

// Pin used for DHT22
const int DHT_PIN = 15;
DHTesp dhtSensor;


// Core 0 - Task that Read Values of Temperature and Humidity 
// Core 1 - Task to calculate the moving Average (loop())
void readValues(void * parameters);

// Variables to calculate the moving average using the last 5 values
float temperatureDHT22[5] = {0.0, 0.0, 0.0, 0.0, 0.0};
float humidityDHT22[5] = {0.0, 0.0, 0.0, 0.0, 0.0};
float averageTemperature = 0.0;
float averageHumidity = 0.0;
int arrIndex = 0; // If equals to 5 => Triggers the moving average calculation

bool isFull = false;
bool newOne = false;


void setup() {
  Serial.begin(115200);  
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);

  // Configuring the task executed on core 0
  xTaskCreatePinnedToCore(
      readValues,        // Function to implement the task 
      "readValuesTask",  // Name of the task 
      100000,            // Stack size in words 
      NULL,              // Task input parameter 
      1,                 // Priority of the task 
      &readValuesTask,   // Task handle. 
      0                  // Core where the task should run 
  ); 
}


// Core 0 - Reads the Temperature and Humidity Values 
void readValues(void * parameters) {   
  for (;;) {            
    TempAndHumidity  data = dhtSensor.getTempAndHumidity();       
    
    // Storing the data into arrays
    temperatureDHT22[arrIndex] = data.temperature;
    humidityDHT22[arrIndex] = data.humidity;    
    
    // A new item was allocated into the temperature and humidity arrays
    newOne = true; 
    
    Serial.println("v," + String(data.temperature, 2) + "," + String(data.humidity, 2));                    
    
    arrIndex += 1;    
    if (arrIndex == 5) {      
      isFull = true;
      arrIndex = 0;      
    }    
    
    delay(1000);  
  }  
}


// Core 1 - Calculates the Moving Average of Temperature and Humidity 
void loop() {      
  if (isFull && newOne) {
    averageTemperature = 0.0;
    averageHumidity = 0.0;
    for (int i = 0; i < 5; ++i) {
      averageTemperature += temperatureDHT22[i];
      averageHumidity += humidityDHT22[i];
    }
    averageTemperature /= 5;
    averageHumidity /= 5;          

    Serial.println("a," + String(averageTemperature, 2) + "," + String(averageHumidity, 2));        
    newOne = false;         
  }
}