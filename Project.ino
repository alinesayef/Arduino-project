int start = 0;
int LM35 = A1; //The LM35 temprature sensor.
int gaugetemp = 0; //Reads the temprature.
int fan = 11; //fan
int ledgreen = 8; //green led
int ledwhite = 7; //white led
int ledyellow = 5; //yellow led
int Min = 20; //The temprature at which the fan starts.
int Max = 35; //The temprature at which the fan reaches its maximum speed.
int fanSpeed;

float volts = 0;
float Celsius = 0;
float Fahrenheit = 0;

void setup() {
    pinMode(LM35, INPUT);
    pinMode(fan, OUTPUT);
    pinMode(ledgreen, OUTPUT);
    pinMode(ledwhite, OUTPUT);
    pinMode(ledyellow, OUTPUT);
    Serial.begin(9600);
}

void Tempread() { //to convert temperature.
    gaugetemp = analogRead(LM35);
    volts = (gaugetemp * 5.0) / 1024.0;
    Celsius = (volts - 0.5) * 100;
    Fahrenheit = Celsius * 9 / 5 + 32;


    Serial.print(Celsius); //This prints the text of the temprature and the fan speed on the serial monitor.
    delay(1000);
    Serial.println(fanSpeed);
    delay(1000);
}

void loop() {
    Tempread();
    if (Celsius < Min) { //If the temprature is below Min turn everything off but green led.
        digitalWrite(fan, LOW);
        digitalWrite(ledgreen, HIGH);
        digitalWrite(ledwhite, LOW);
        digitalWrite(ledyellow, LOW);

        fanSpeed = 0;
    }

    if ((Celsius >= Min) && (Celsius < Max)) { //If the temprature is the same or above Min and under Max then turn the on fan(50% speed)and white led.
        digitalWrite(fan, HIGH);
        digitalWrite(ledgreen, LOW);
        digitalWrite(ledwhite, HIGH);
        digitalWrite(ledyellow, LOW);

        fanSpeed = 50;
    }

    if (Celsius > Max) { //If the temprature is more than Max then turn on the fan(100% speed)and the yellow led.
        digitalWrite(fan, HIGH);
        digitalWrite(ledgreen, LOW);
        digitalWrite(ledwhite, LOW);
        digitalWrite(ledyellow, HIGH);

        fanSpeed = 100;
    }
}