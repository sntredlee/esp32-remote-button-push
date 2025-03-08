#include "time.h"
#include "config.h"
#include "command.h"
#include "wifi_manager.h"
#include "telegram.h"
#include "time_utils.h"
#include "servo_drive.h"


config_t sys_config;

static const command_t init_commands[] =
{   
  // {"pos", servo_ctrl_cmd, 0, NULL, NULL, NULL, "pos [0-180]"}, 
  {"p", push_button_cmd, 0, NULL, NULL, NULL, "p"}, \
  {"angles", adjust_push_angle_cmd, 0,NULL, NULL, NULL, "angles [up_deg, down_deg]"}, \
  CMD_TABLE_END
};


void setup() {
  
  pinMode(sys_config.servo_pin, OUTPUT);
  digitalWrite(sys_config.servo_pin, LOW);  

  Serial.begin(115200);
  init_cmd(init_commands);
   
  init_wifi(sys_config.ssid, sys_config.password); 
  turn_on_wifi(); 
  sync_clock();

  init_servo(sys_config.servo_pin);
  init_telegram(sys_config.telegram_botToken, sys_config.telegram_chatID);
}


void loop() {      
  if (!is_wifi_on() && !turn_on_wifi()) {
    Serial.printf("Can NOT connect to WiFi!\n\r");
  }
  command_console_task();  
  process_telegram_messages();
}

/*
#include <ESP32Servo.h>

// Define the servo object
Servo myServo;

// Define the servo control pin
const int servoPin = 18;  // Use any PWM-capable pin

void setup() {
    Serial.begin(115200);
    
    // Attach the servo to the defined pin
    myServo.attach(servoPin);
}

void loop() {
    // Move servo to 0 degrees
    Serial.println("Moving to 0 degrees");
    myServo.write(0);
    delay(1000);  // Wait 1 second

    // Move servo to 90 degrees
    Serial.println("Moving to 90 degrees");
    myServo.write(90);
    delay(1000);

    // Move servo to 180 degrees
    Serial.println("Moving to 180 degrees");
    myServo.write(180);
    delay(1000);
}
*/