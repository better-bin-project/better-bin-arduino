#define UV '1'
#define INFRARED '2'

int readUV();

void setup() {
    Serial.begin(9600);
}

void loop() {
    if (Serial.available() > 0) {
        char msg = Serial.readStringUntil('\n')[0];
        // Read and send back requested sensor data
        switch (msg) {
            case UV:
                // todo: UV light on
                Serial.print(readUV());
                // todo: UV light off
                break;
            case INFRARED:
                break;
        }
    }
}

int readUV() {
    int val = 0;
    for (int i = 0; i < 1024; i++) {
        val += analogRead(A0);
        delay(2);
    }
    return val / 1024; // todo: Return percentage of maximum intensity
}
