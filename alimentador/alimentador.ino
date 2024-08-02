/*************************************************************
  Blynk is a platform with iOS and Android apps to control
  ESP32, Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build mobile and web interfaces for any
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: https://www.blynk.io
    Sketch generator:           https://examples.blynk.cc
    Blynk community:            https://community.blynk.cc
    Follow us:                  https://www.fb.com/blynkapp
                                https://twitter.com/blynk_app

  Blynk library is licensed under MIT license
 *************************************************************
  Blynk.Edgent implements:
  - Blynk.Inject - Dynamic WiFi credentials provisioning
  - Blynk.Air    - Over The Air firmware updates
  - Device state indication using a physical LED
  - Credentials reset using a physical Button
 *************************************************************/

/* Fill in information from your Blynk Template here */
/* Read more: https://bit.ly/BlynkInject */

#define BLYNK_TEMPLATE_ID "tu_template_id"
#define BLYNK_TEMPLATE_NAME "tu_template_nombre"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"
int led_rojo = 14;
int led_azul = 12;

int estado_rojo;
int estado_azul;

void setup()
{
  Serial.begin(115200);
  delay(100);
  pinMode(led_rojo,OUTPUT);
  pinMode(led_azul,OUTPUT);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
  }
  BLYNK_WRITE(V0){
    estado_rojo = param.asInt();
    digitalWrite(led_rojo,estado_rojo);
    }
    BLYNK_WRITE(V1){
    estado_azul = param.asInt();
    digitalWrite(led_azul,estado_azul);
    }
