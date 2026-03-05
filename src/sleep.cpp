#include <esp_sleep.h>

// sleepTime_us : _us == microsecondes
int goToBed(u_int64_t sleepTime_us) {
    esp_sleep_enable_timer_wakeup(sleepTime_us);
    // Serial.flush();
    esp_deep_sleep_start();

}