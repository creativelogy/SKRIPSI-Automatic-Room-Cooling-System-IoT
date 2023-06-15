#include <IRLibSendBase.h>
#include <IRLib_HashRaw.h>
#include "data.h"
#define RAW_DATA_LEN 137
#define RAW_DATA_LEN_FAN 71


int setdelaytime = 5000;
IRsendRaw mySender;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(" Starting system...");
  delay(setdelaytime);

  Serial.println(" Mulai pengujian fungsionalitas: FAN");
  Serial.println("--------------------");
  //----------------- FAN ---------------------
  Serial.println("Menyalakan FAN...");
  mySender.send(rawDataON, RAW_DATA_LEN_FAN, 38);
  delay(setdelaytime);

  Serial.println("Menambahkan fitur: Fan Speed FAN kini 2");
  mySender.send(rawDataspeed, RAW_DATA_LEN_FAN, 38);
  delay(setdelaytime);

  Serial.println("Menyalakan fitur: Swing Mode FAN");
  mySender.send(rawDataSWING, RAW_DATA_LEN_FAN, 38);
  delay(setdelaytime);

  //----------------- AC ---------------------
  Serial.println("--------------------------------------");
  Serial.println(" Mulai pengujian fungsionalitas: AC");
  Serial.println("--------------------------------------");

  Serial.println("Menyalakan AC: 27°C - FS Low - SW On");
  mySender.send(rawon_27Flow_swon, RAW_DATA_LEN_AC, 38);
  delay(setdelaytime);

  Serial.println("Menyalakan AC: 26°C - FS Low - SW On");
  mySender.send(rawon_26Flow_swon, RAW_DATA_LEN_AC, 38);
  delay(setdelaytime);

  Serial.println("Menyalakan AC: 25°C - FS Low - SW On");
  mySender.send(rawon_25Flow_swon, RAW_DATA_LEN_AC, 38);
  delay(setdelaytime);

  Serial.println("Menyalakan AC: 24°C - FS Low - SW On");
  mySender.send(rawon_24Flow_swon, RAW_DATA_LEN_AC, 38);
  delay(setdelaytime);

  Serial.println("Menyalakan AC: 23°C - FS Low - SW On");
  mySender.send(rawon_23Flow_swon, RAW_DATA_LEN_AC, 38);
  delay(setdelaytime);

  Serial.println("Menyalakan AC: 22°C - FS Low - SW On");
  mySender.send(rawon_22Flow_swon, RAW_DATA_LEN_AC, 38);
  delay(setdelaytime);

  Serial.println("Menyalakan AC: 21°C - FS Low - SW On");
  mySender.send(rawon_21Flow_swon, RAW_DATA_LEN_AC, 38);
  delay(setdelaytime);

  Serial.println("Menyalakan AC: 20°C - FS Low - SW On");
  mySender.send(rawon_20Flow_swon, RAW_DATA_LEN_AC, 38);
  delay(setdelaytime);

  Serial.println("Menyalakan AC: 19°C - FS Low - SW On");
  mySender.send(rawon_19Flow_swon, RAW_DATA_LEN_AC, 38);
  delay(setdelaytime);

  Serial.println("Menyalakan AC: 18°C - FS Low - SW On");
  mySender.send(rawon_18Flow_swon, RAW_DATA_LEN_AC, 38);
  delay(setdelaytime);

  Serial.println("Menyalakan AC: 17°C - FS Low - SW On");
  mySender.send(rawon_17Flow_swon, RAW_DATA_LEN_AC, 38);
  delay(setdelaytime);

  Serial.println("Menyalakan AC: 16°C - FS Low - SW On");
  mySender.send(rawon_16Flow_swon, RAW_DATA_LEN_AC, 38);
  delay(setdelaytime);

  Serial.println("Mematikan AC...");
  mySender.send(rawoff_24Flow_swon, RAW_DATA_LEN_AC, 38);
  delay(setdelaytime);

  Serial.println("Menyalakan AC: 16°C - FS Low - SW On");
  mySender.send(rawon_16Flow_swon, RAW_DATA_LEN_AC, 38);
  delay(setdelaytime);

  Serial.println("Menaikan Fan Speed AC: MEDIUM - 16°C");
  mySender.send(rawon_16Fmed_swon, RAW_DATA_LEN_AC, 38);
  delay(setdelaytime);

  Serial.println("Menaikan Fan Speed AC: HIGH - 16°C");
  mySender.send(rawon_16Fhigh_swon, RAW_DATA_LEN_AC, 38);
  delay(setdelaytime);

}