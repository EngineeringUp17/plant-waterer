# Plant Watering Starter Project

This project reads in data from a variety of sensors (temperature, humidity, light level, and soil moisture),
and automatically waters a plant when the soil humidity drops below a certain level.  
  
The code in this project is based on the code found [here](https://docs.sunfounder.com/projects/3in1-kit-v2/en/latest/iot_project/iot_plant_monitor.html).

# Setup
1. Assemble the components and wire them together as shown in the diagram [here](https://docs.sunfounder.com/projects/3in1-kit-v2/en/latest/iot_project/iot_plant_monitor.html)
2. Install the `DHT Sensor Library` in Arduino IDE
    1. Click on the library icon in the left sidebar  
    ![Library Icon](images/library_icon.png)
    2. Search for `DHT Sensor Library` in the search bar  
    ![Search Bar](images/search_bar.png)
    3. Click install  
    ![DHT Library Search Result](images/dht_library_entry.png)
    4. Click `Install All` (if this window shows up)  
    ![Install Library Dependencies Popup](images/dependency_dialog.png)
3. Flash the code in the `moisture_sensor/` directory
4. Open the serial monitor (in the top right corner) to see the sensor readings!  
![Serial Monitor Icon](images/serial_monitor_icon.png)
