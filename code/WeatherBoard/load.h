// wifi.h
#include <ESPAsync_WiFiManager_Lite.h>
#include "./params.h"
#include <ArduinoJson.h>

ESPAsync_WiFiManager_Lite *wifiManager;
WiFiEventHandler wifiConnectHandler;
WiFiEventHandler wifiDisconnectHandler;
char board_name[32] = {0};

// mqtt.h
#include <AsyncMqttClient.h>
#include <Ticker.h>

AsyncMqttClient mqtt;
Ticker mqttReconnectTimer;
char will[40] = {0}; // has to be global variable
char will_topic[64] = {0}; // has to be global variable

void connectToMqtt();

// ota.h
#if defined(HTTP_OTA)
    #include <ESP8266httpUpdate.h>
    #include <ESP8266HTTPClient.h>
    bool do_http_update = false;
    char http_ota_url[100];

    void httpOtaUpdate();
#endif

#if defined(ARDUINO_OTA)
    #include <ArduinoOTA.h>
    bool ota_in_progess = false;
#endif

// sensors.h
#include <Wire.h>
#include "MeteoFunctions.h"
#include "MovingAverageFloat.h"

MeteoFunctions meteoFunctions;

struct sensorData {
    float humidity[2] = {NAN, NAN}; // rel, abs
    float temp[3] = {NAN, NAN, NAN}; // from baro, temp, humidity
    float pressure[2] = {NAN, NAN}; // rel, abs
};

#if defined(SENSOR_BMP280) || defined(SENSOR_BME280) || defined(SENSOR_LPS35HW)
    #define HAS_BARO
#endif

#if defined(SENSOR_HTU21D) || defined(SENSOR_SHT31)
    #define HAS_HUMIDITY
#endif

float round2(float value) {
    return round(value * 100.0) / 100.0;
}

#if defined(HAS_BARO)
    MovingAverageFloat <READ_SAMPLES> baro_filter[2];  // rel pressure, abs pressure
    MovingAverageFloat <READ_SAMPLES> baro_temp_filter;
#endif

#if defined(SENSOR_BME280) || defined(HAS_HUMIDITY)
    MovingAverageFloat <READ_SAMPLES> humidity_filter[2];  // rel humidity, abs humidity
    MovingAverageFloat <READ_SAMPLES> humidity_temp_filter;
#endif

#if defined(HAS_TEMP)
    MovingAverageFloat <READ_SAMPLES> temp_filter;
#endif

// button.h
#include <JC_Button.h>
Button button(BUTTON_PIN);
