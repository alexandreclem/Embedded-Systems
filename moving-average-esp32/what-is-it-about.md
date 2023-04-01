## Simple Semaphore using Arduino-Uno
An ESP32 microcontroller and a DHT22 temperature and humidity sensor were used. In one core, the values of temperature and humidity were taken and in the second core, the moving average was calculated.

### Source Code
The source code can be found in the **src** directory.
- **esp32.ino** file
- **data.csv** file
    - Data gathered from the Woki Platform (was get manually)
- **graphs.py** file
    - Used to make analysis in the data gathered from the Woki Platform

### Assembly using the Woki Platform
<p align="center" width="100%">
    <img width="70%" src="./images/woki-sim.png">    
</p>

### Practical Assembly
<p align="center" width="100%">
    <img width="40%" src="./images/assembly-in-practice.png">    
</p>

### Temperature Analysis
<p align="center" width="100%">
    <img width="90%" src="./images/moving-average-temp.png">    
</p>

### Humidity Analysis
<p align="center" width="100%">
    <img width="90%" src="./images/moving-average-hum.png">    
</p>
