#include <esp_sleep.h>


int goToBed() {
    esp_sleep_enable_timer_wakeup(1000000);
    // Serial.flush();
    esp_deep_sleep_start();

}