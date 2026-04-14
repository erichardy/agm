// Amzer Gozh Monitor

#include <Arduino.h>
#include "temperature.h"

#include "sleep.h"
// #include "display.h"

#include <esp_sleep.h>
#include <WiFi.h>
#include <esp_bt.h>
#include <driver/gpio.h>

// variable conservée pendant le deep sleep
RTC_DATA_ATTR int wakeCount = 0;

#define DEBUG
// #undef DEBUG
#ifdef DEBUG
  #define debug(x) Serial.print(x)
  #define debugln(x) Serial.println(x)
#else
  #define debug(x)
  #define debugln(x)
#endif

// #define WAKEUP_GPIO 25
gpio_num_t WAKEUP_GPIO = GPIO_NUM_25;
gpio_num_t LEDX = GPIO_NUM_32;

int x;
float jj = 6.3;
u_int16_t nbLoops = 0;
/*
OneWire ds(DS18B20_PIN);
DallasTemperature sensors(&ds);
DeviceAddress insideThermometer;
*/

void blinkLED(int led, int nb, int fast){
  digitalWrite(led, LOW);
  for (int i = 0; i < nb; i++){
    digitalWrite(led, HIGH);
    delay(1000 / fast);
    digitalWrite(led, LOW);
    delay(1000 / fast);
  }
}


void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("--------------------");
  pinMode(WAKEUP_GPIO, INPUT);
  // digitalWrite(WAKEUP_GPIO, LOW);

  // Désactiver WiFi et Bluetooth pour réduire la consommation
  WiFi.mode(WIFI_OFF);
  WiFi.disconnect(true);
  btStop();

  pinMode(LEDX, OUTPUT);

  /*
  digitalWrite(LEDX, HIGH);
  delay(2000);
  digitalWrite(LEDX, LOW);
  delay(500);
*/
  wakeCount++;

  esp_sleep_wakeup_cause_t wakeup_reason = esp_sleep_get_wakeup_cause();
  if (wakeup_reason == ESP_SLEEP_WAKEUP_EXT0) {
    Serial.println("Réveillé par GPIO (niveau HIGH)");
    blinkLED(LEDX, 8, 5);
    // Serial.println(esp_sleep_get_gpio_wakeup_status());
  } else if (wakeup_reason == ESP_SLEEP_WAKEUP_TIMER) {
    Serial.println("Réveillé par TIMER");
    blinkLED(LEDX, 2, 2);
    } else {
    Serial.println("Démarrage normal");
  }

  Serial.println();
  Serial.println("Reveil ESP32");
  Serial.print("Nombre de reveils : ");
  Serial.println(wakeCount);

  // boucle 0 -> 30
  for(int i = 0; i < 30; i++)
  {
    Serial.print("i = ");
    Serial.print(i);
    x = digitalRead(WAKEUP_GPIO);
    Serial.print(" / WAKEUP_GPIO = ");
    if (x) {
      digitalWrite(LEDX, HIGH);
    } else {
      digitalWrite(LEDX, LOW);
    }
    Serial.println(x);
    delay(500);
  }

// Configure GPIO3 comme source de réveil (niveau HIGH)
  /*
  gpio_config_t io_conf = {};
  io_conf.intr_type = GPIO_INTR_DISABLE;
  io_conf.mode = GPIO_MODE_INPUT;
  io_conf.pin_bit_mask = (1ULL << WAKEUP_GPIO);
  io_conf.pull_down_en = GPIO_PULLDOWN_ENABLE; // important !
  // io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
  io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
  gpio_config(&io_conf);
  */
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_25, 1);

  // Activer le réveil sur GPIO (niveau HIGH)
  // esp_sleep_enable_gpio_wakeup();
  // gpio_wakeup_enable(WAKEUP_GPIO, GPIO_INTR_HIGH_LEVEL);
  // gpio_wakeup_enable(WAKEUP_GPIO, GPIO_INTR_HIGH_LEVEL);

  digitalWrite(LEDX, LOW);
  Serial.println("Deep sleep 8 secondes");

  // réveil par timer
  esp_sleep_enable_timer_wakeup(8ULL * 1000000ULL);

  Serial.println("...");
  Serial.flush();

  // passage en deep sleep
  esp_deep_sleep_start();
}

void loop() {
/*   
  display.clearDisplay();
  display.setCursor(0,0);
  tempC = getExternalTemp();
  // display.println(tempC);
  // display.print(jj);
  // display.print (" ");
  // display.println(motionSensorCurrentState);
  display.println(temperature);

  display.display();
  // jj -= .32;
  xl += 2;
*/
}
