#include <string>

#define UV '1'
#define INFRARED '2'

void setup() {
    Serial.begin(9600);
}

void loop() {
    if (Serial.available() > 0) {
        std::string msg = Serial.readStringUntil('\n');
        // Read and send back requested sensor data
        switch (msg[0]) {
            case UV:
                break;
            case INFRARED:
                break;
        }
    }
}
