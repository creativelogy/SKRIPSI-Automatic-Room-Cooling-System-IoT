#include <OneWire.h>
#include <DallasTemperature.h>
#include "RTClib.h"
#include <IRLibSendBase.h>
#include <IRLib_HashRaw.h>
#include "myIRData.h"

// Define to which pin of the Arduino the 1-Wire bus is connected:
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

RTC_DS3231 rtc;
IRsendRaw mySender;

//define variable

#define setDelayTime 300000
int Desired_temp = 24;
int newDesired_temp;
int Measured_temp;
int AC_Temp, sendACTemp;
bool AC = false;
bool FAN = false;
bool Swingmode_AC = false;
bool Swingmode_FAN = false;
int Fanspeed_AC = 1;
int Fanspeed_FAN = 1;
int khz = 38;
int ACBool, FANBool;
int SysPower = 0;
//IR raw data codes are in myIRData.h file

void setup() {
  // Begin Serial1 communication at a baud rate of 9600:
  Serial.begin(9600);
  Serial1.begin(9600);
  // Start up the library:
  sensors.begin();
  pinMode(LED_BUILTIN, OUTPUT);

  //initialize RTC
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC module");
    while (1)
      ;
  }
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));  // set RTC to compile time
  }
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));  // set RTC to compile time
}

void loop() {
  DateTime now = rtc.now();  // get current time from RTC module

  if (now.hour() >= 8 && now.hour() < 17 && now.dayOfTheWeek() != 6 && now.dayOfTheWeek() != 7) {
    sensors.requestTemperatures();
    Measured_temp = sensors.getTempCByIndex(0);
    SysPower = 1;
    TurnOnAC();
    TurnOnFAN();

    sensors.requestTemperatures();
    Measured_temp = sensors.getTempCByIndex(0);

    if (Measured_temp != Desired_temp) {
      Serial.println("-------------------------------------");
      Serial.println("Suhu belum sesuai nih, Menyesuaikan..");
      Serial.println("-------------------------------------");
      Serial.print("Suhu ruangan:");
      Serial.println(Measured_temp);
      matchTemperature();
    } else if (Measured_temp == Desired_temp) {
      Serial.println("-------------------------------------");
      Serial.println("Suhu sudah sesuai :) Have A Nice Day!");
      Serial.println("-------------------------------------");
      Serial.print("Suhu ruangan:");
      Serial.println(Measured_temp);
    }

    checkNewTemp();  //function untuk cek suhu nyaman baru
    sendDataToESP();

  } else {
    Serial.println("----------------");
    Serial.println("DILUAR JAM KERJA");
    Serial.println("----------------");

    SysPower = 0;

    sensors.requestTemperatures();
    Measured_temp = sensors.getTempCByIndex(0);

    checkNewTemp();
    sendDataToESP();
  }
  delay(setDelayTime);
}

void TurnOnAC() {
  if (AC == false) {
    Serial.print("Protocol: ");
    Serial.println("Turning ON AC...");
    //nyalain ac
    mySender.send(rawon_24Flow_swon, RAW_DATA_LEN_AC, 38);
    Serial.print("Suhu ruangan:");
    Serial.println(Measured_temp);
    AC = true;
    AC_Temp = 24;
    delay(setDelayTime);
  } else {
    //do nothing
  }
}

void TurnOnFAN() {
  if (FAN == false) {
    //Serial1.println("nyalain...");
    //nyalain ac
    mySender.send(rawDataON, RAW_DATA_LEN_FAN, 38);
    FAN = true;
  } else {
    //do nothing
  }

  if (Swingmode_FAN == false) {
    //Serial1.println("nyalain...");
    //nyalain ac
    mySender.send(rawDataSWING, RAW_DATA_LEN_FAN, 38);
    Swingmode_FAN = true;
  } else {
    //do nothing
  }

  Serial.print("Protocol: ");
  Serial.println("FAN: ON | Swing Mode: ON");
}

void TurnOffFAN() {
  if (FAN == true) {
    //Serial1.println("nyalain...");
    //nyalain ac
    mySender.send(rawDataON, RAW_DATA_LEN_FAN, 38);
  } else {
    //do nothing
  }
  FAN = false;
  Swingmode_FAN = false;
  Fanspeed_AC = 1;
  Fanspeed_FAN = 1;
}

void kipasAnginFanSpeed() {
  if (Fanspeed_FAN <= 3) {
    mySender.send(rawDataspeed, RAW_DATA_LEN_FAN, 38);
    Fanspeed_FAN++;
    Serial.print("Protocol: ");
    Serial.println("Increase FAN Fanspeed");
  } else if (Fanspeed_FAN > 3) {
    //Fanspeed_FAN = 0;
    Serial.print("Protocol: ");
    Serial.println("FAN Fanspeed = Low");
  }
}

void checkNewTemp() {
  if (Serial1.available() > 0) {       // Check if data is available to read
    newDesired_temp = Serial1.read();  // Read the incoming data

    if (newDesired_temp == 0) {  //kalau yang kebaca 0, berarti suhu nyaman default
      Desired_temp = 24;
    } else {
      // Do something with the received data
      Serial.println("");
      Serial.print("New Desired Temperature: ");
      Serial.println(newDesired_temp);
      Serial.println("");
      Desired_temp = newDesired_temp;
    }
    digitalWrite(LED_BUILTIN, HIGH);
    delay(2000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
  }
}

void matchTemperature() {
  if (Measured_temp > Desired_temp) {
    decreaseTemperature();
  } else if (Measured_temp < Desired_temp) {
    increaseTemperature();
  }
}

void decreaseTemperature() {
  if (AC_Temp == 16 && Fanspeed_AC < 4) {
    //Fanspeed_AC initial value = 1
    //delay(setDelayTime);
    Fanspeed_AC++;
    if (Fanspeed_AC == 2) {
      mySender.send(rawon_16Fmed_swon, RAW_DATA_LEN_AC, 38);
      kipasAnginFanSpeed();
    } else if (Fanspeed_AC == 3) {
      mySender.send(rawon_16Fhigh_swon, RAW_DATA_LEN_AC, 38);
      kipasAnginFanSpeed();
    } else {
      mySender.send(rawon_16Flow_swon, RAW_DATA_LEN_AC, 38);
      kipasAnginFanSpeed();
      kipasAnginFanSpeed();
    }
    Serial.print("Protocol: ");
    Serial.print("AC Fanspeed Increase, is now: ");
    Serial.println(Fanspeed_AC);
  } else if (Measured_temp != Desired_temp && AC_Temp != 16) {
    AC_Temp--;
    decideIR();
  } else if (AC_Temp == 16 && Fanspeed_AC > 3) {
    delay(setDelayTime);
    Serial.print("Protocol: ");
    Serial.println("Suhu mentok.......");
    Serial.print("Protocol: ");
    Serial.println("AC Temp is now 16°C");
  }
}

void increaseTemperature() {
  TurnOnAC();
  TurnOffFAN();
  if (Measured_temp != Desired_temp && AC_Temp != 27) {
    AC_Temp++;
    decideIR();

  } else if (AC_Temp == 27) {
    delay(setDelayTime);
    Serial.print("Protocol: ");
    Serial.println("Suhu mentok.......");
    Serial.print("Protocol: ");
    Serial.println("AC Temp is now 27°C");
  }
}

void decideIR() {
  switch (AC_Temp) {
    case 16:
      Serial.print("Protocol: ");
      Serial.println("AC Temp is now 16°C");
      mySender.send(rawon_16Flow_swon, RAW_DATA_LEN_AC, 38);
      delay(setDelayTime);
      break;
    case 17:
      Serial.print("Protocol: ");
      Serial.println("AC Temp is now 17°C");
      mySender.send(rawon_17Flow_swon, RAW_DATA_LEN_AC, 38);
      delay(setDelayTime);
      break;
    case 18:
      Serial.print("Protocol: ");
      Serial.println("AC Temp is now 18°C");
      mySender.send(rawon_18Flow_swon, RAW_DATA_LEN_AC, 38);
      delay(setDelayTime);
      break;
    case 19:
      Serial.print("Protocol: ");
      Serial.println("AC Temp is now 19°C");
      mySender.send(rawon_19Flow_swon, RAW_DATA_LEN_AC, 38);
      delay(setDelayTime);
      break;
    case 20:
      Serial.print("Protocol: ");
      Serial.println("AC Temp is now 20°C");
      mySender.send(rawon_20Flow_swon, RAW_DATA_LEN_AC, 38);
      break;
    case 21:
      Serial.print("Protocol: ");
      Serial.println("AC Temp is now 21°C");
      mySender.send(rawon_21Flow_swon, RAW_DATA_LEN_AC, 38);
      break;
    case 22:
      Serial.print("Protocol: ");
      Serial.println("AC Temp is now 22°C");
      mySender.send(rawon_22Flow_swon, RAW_DATA_LEN_AC, 38);
      break;
    case 23:
      Serial.print("Protocol: ");
      Serial.println("AC Temp is now 23°C");
      mySender.send(rawon_23Flow_swon, RAW_DATA_LEN_AC, 38);
      break;
    case 24:
      Serial.print("Protocol: ");
      Serial.println("AC Temp is now 24°C");
      mySender.send(rawon_24Flow_swon, RAW_DATA_LEN_AC, 38);
      break;
    case 25:
      Serial.print("Protocol: ");
      Serial.println("AC Temp is now 25°C");
      mySender.send(rawon_25Flow_swon, RAW_DATA_LEN_AC, 38);
      break;
    case 26:
      Serial.print("Protocol: ");
      Serial.println("AC Temp is now 26°C");
      mySender.send(rawon_26Flow_swon, RAW_DATA_LEN_AC, 38);
      break;
    case 27:
      Serial.print("Protocol: ");
      Serial.println("AC Temp is now 27°C");
      mySender.send(rawon_27Flow_swon, RAW_DATA_LEN_AC, 38);
      break;
  }
}

void convertBoolVal() {
  if (AC == true) {
    ACBool = 1;
  } else {
    ACBool = 0;
  }
  if (FAN == true) {
    FANBool = 1;
  } else {
    FANBool = 0;
  }
}

void sendDataToESP() {
  // Print the temperature readings to the Serial1 monitor
  //&SysPower, &AC, &FAN, &Measured_temp, &AC_Temp, &Fanspeed_AC, &Fanspeed_FAN

  convertBoolVal();

  Serial.print("Sending data: ");
  Serial.print(SysPower);
  Serial.print(",");
  Serial.print(ACBool);
  Serial.print(",");
  Serial.print(FANBool);
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

  Serial1.print(SysPower);  // Send value1 over Serial1
  Serial1.print(",");
  Serial1.print(ACBool);  // Send value1 over Serial1
  Serial1.print(",");
  Serial1.print(FANBool);  // Send value2 over Serial1
  Serial1.print(",");
  Serial1.print(Measured_temp);  // Send value2 over Serial1
  Serial1.print(",");
  Serial1.print(AC_Temp);  // Send value2 over Serial1
  Serial1.print(",");
  Serial1.print(Fanspeed_AC);  // Send value2 over Serial1
  Serial1.print(",");
  Serial1.println(Fanspeed_FAN);  // Send value2 over Serial1
}