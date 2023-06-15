//Connect to thingspeak
#define BLYNK_TEMPLATE_ID "TMPL6RkMSFYpf"
#define BLYNK_TEMPLATE_NAME "SKRIPSI"
#define BLYNK_AUTH_TOKEN "SLo1I8qpEx5Go3Cs4CsVpCGMsdPOe3hp"

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "ThingSpeak.h"

#define RXp2 16
#define TXp2 17
LiquidCrystal_I2C lcd(0x27, 16, 2);  //

int Desired_temp = 24;
bool newDT = false;
int Measured_temp, AC_Temp, ACPower, FANPower, Swingmode_AC, Swingmode_FAN, Fanspeed_AC, Fanspeed_FAN;
int SysPower;
// FORMAT SEND DATA (AC, FAN, MT, ACT, SMAC, FSAC, SMFAN, FSFAN)

const char* ssid = "Kopi Satu Tujuan";
const char* pass = "shopeesatu7an";
// const char* ssid = "Kos Grey";
// const char* pass = "penghunitampan";
// char ssid[] = "creativelogy";
// char pass[] = "bentardulu";

//auth blynk
char auth[] = BLYNK_AUTH_TOKEN;

WiFiClient client;
BlynkTimer timer;
HTTPClient http;

unsigned long myChannelNumber = 2103002;
const char* serverName = "http://api.thingspeak.com/update";
String apiKey = "B8W4F5JCEKMB5MTS ";



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);
  WiFi.begin(ssid, pass);
  //timer.setInterval(2000L, checkBlynkStatus); // check if Blynk server is connected every 2 seconds
  Blynk.config(auth);
  pinMode(2, OUTPUT);
  //Initialize ThingSpeak library
  //ThingSpeak.begin(client);

  // Initialize the LCD connected
  lcd.begin();

  // Turn on the backlight on LCD.
  lcd.backlight();
  lcd.print("CEK SUHU RUANGAN");
  lcd.clear();
}

void loop() {
  timer.run();
  Blynk.run();  //for initiate blynk

  if (Serial2.available() > 0) {
    Serial.println("Message Received: ");
    String data = Serial2.readStringUntil('\n');  // Read the data until a newline character is received

    // FORMAT SEND DATA (AC, FAN, MT, ACT, SMAC, FSAC, SMFAN, FSFAN)
    //sscanf(data.c_str(), "%d,%f,%c", &value1, &value2, &value3);  // Parse the data and store it in variables
    sscanf(data.c_str(), "%d, %d, %d, %d, %d, %d, %d", &SysPower, &ACPower, &FANPower, &Measured_temp, &AC_Temp, &Fanspeed_AC, &Fanspeed_FAN);
    Serial.print(SysPower);
    Serial.print(",");
    Serial.print(ACPower);
    Serial.print(",");
    Serial.print(FANPower);
    Serial.print(",");
    Serial.print(Measured_temp);
    Serial.print(",");
    Serial.print(AC_Temp);
    Serial.print(",");
    Serial.print(Fanspeed_AC);
    Serial.print(",");
    Serial.print(Fanspeed_FAN);
    Serial.print(",");
    Serial.println(Desired_temp);

    //V1 dan V2 Measured temp 2 dan desired temp
    Blynk.virtualWrite(V0, Measured_temp);
    Blynk.virtualWrite(V2, Desired_temp);
    Blynk.virtualWrite(V3, ACPower);
    Blynk.virtualWrite(V4, FANPower);
    Blynk.virtualWrite(V6, SysPower);
    Blynk.virtualWrite(V5, AC_Temp);
    Blynk.virtualWrite(V7, Fanspeed_AC);
    Blynk.virtualWrite(V9, Fanspeed_FAN);

    // Your Domain name with URL path or IP address with path
    http.begin(client, serverName);
    // Specify content-type header
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    // Data to send with HTTP POST
    String httpRequestData = "api_key=" + apiKey + "&field1=" + String(Desired_temp) + "&field2=" + String(Measured_temp);
    // Send HTTP POST request
    int httpResponseCode = http.POST(httpRequestData);
    http.end();

    printLCD();
  }

  if (newDT == true) {
    // Example data to send, use data from blynk write v2
    Serial.print("Sending data: ");
    Serial.println(Desired_temp);
    Serial2.write(Desired_temp);  // Send data to Arduino Mega
    delay(1000);                  // Delay for demonstration purposes
    newDT = false;
    digitalWrite(2, HIGH);
    delay(2000);
    digitalWrite(2, LOW);
    delay(1000);
  }
}

void printLCD() {
  //Section LCD
  lcd.setCursor(0, 0);
  lcd.print("Suhu Ruangan : ");
  lcd.setCursor(12, 0);
  lcd.print(Measured_temp);
  lcd.write(0xDF);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Suhu Nyaman  : ");
  lcd.setCursor(12, 1);
  lcd.print(Desired_temp);
  lcd.write(0xDF);
  lcd.print("C");
}

BLYNK_WRITE(V2) {
  newDT = true;
  Desired_temp = param.asInt();
  Serial.print("Suhu nyaman baru: ");
  Serial.println(Desired_temp);
  Serial.println("-----------------------------");
}
