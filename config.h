#ifndef GLOBAL_CONFIG_H
#define GLOBAL_CONFIG_H
#include <Arduino.h>

#define VERSION_STRING "0.1"
#define DEBUG 1

typedef struct config{  
  int servo_pin = 12;
  String ssid = "OPTUS_A2EE60N";     // WiFi SSID OPTUSVD3644ED0
  String password = "mohur52963mh";  // WiFi password   ALGAEBOMBS08954
  String telegram_botToken = "7720116454:AAF1zpU94JxyA3oUOIA2cB_FeBFb6uDE9Ow";    // **Telegram Bot Credentials**
  String telegram_chatID = "7108046311";                                          // **Telegram Bot Credentials**  
}config_t;

#endif