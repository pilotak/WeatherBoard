#define FW_VERSION "1.0.0"

#define CONFIG_PORTAL_SSID "WeatherBoard_config"
#define CONFIG_PORTAL_PWD  "StrongPasswordHere"

#define MAX_MQTT_SERVER_LEN 48
#define MAX_MQTT_PORT_LEN   5
#define MAX_MQTT_USER_LEN   32
#define MAX_MQTT_PASS_LEN   32
#define MAX_HEIGHT_LEN      5

#define MQTT_QOS                   1
#define MQTT_RETAIN                true
#define MQTT_CHECK_INTERVAL        5000
#define MQTT_STATUS_INTERVAL       30000
#define MQTT_STATUS_TOPIC          "status"  // will result ie. DEVICE_NAME/status
#define MQTT_UPGRADE_TOPIC         "upgrade"  // will result ie. DEVICE_NAME/upgrade
#define MQTT_UPGRADE_STATUS_TOPIC  "status"  // will result ie. DEVICE_NAME/upgrade/status
#define MQTT_RESTART_TOPIC         "restart"  // will result ie. DEVICE_NAME/restart
#define MQTT_SENSORS_TOPIC         "sensors"  // will result ie. DEVICE_NAME/sensors
#define MQTT_WIND_TOPIC            "wind"  // will result ie. DEVICE_NAME/wind
#define MQTT_RAIN_TOPIC            "rain"  // will result ie. DEVICE_NAME/rain
#define MQTT_STATUS_ALIVE          1
#define MQTT_STATUS_DEAD           0

#define BUTTON_PIN D3
#define LONG_PRESS 1000  // ms

#define READ_INTERVAL 3750  // ms
#define READ_SAMPLES 16  // READ_INTERVAL*SAMPLES=sending time of sensors in ms
#define METERS_INTERVAL 60  // how ofter send data from meters in sec
#define METERS_DIR_FILTERING 16  // filter last 16 samples of wind vane

#define I2C_SPEED 100000
#define BMP280_ADDR BME280I2C::I2CAddr_0x76  // or BME280I2C::I2CAddr_0x77
#define MCP9808_ADDR 0x18
#define HTU21D_ADDR 0x40
#define SHT31D_ADDR 0x44
#define MCP3021_ADDRESS 0x48
#define ANEMOMETER_PIN D6
#define RAIN_GAUGE_PIN D5

uint8_t sensor_state = 0b000;  // 0b(Humidity)(Temperature)(Barometer)
