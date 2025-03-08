#include <ESP32Servo.h>
#include "servo_drive.h"

static Servo myServo;
static int servoPin=12;
static int deg_up = 80, deg_down = 110;

void init_servo(int _servoPin) {    
  servoPin = _servoPin;
}


cmd_err_t push_button_cmd(int argc, char *argv[]){    
  myServo.attach(servoPin);

  Serial.printf("Move servo position to: %d degrees\n\r", deg_up);
  myServo.write(deg_up);
  delay(500);
  vTaskDelay(1);
  Serial.printf("Move servo position to: %d degrees\n\r", deg_down);
  myServo.write(deg_down);
  delay(500);
  vTaskDelay(1);
  Serial.printf("Move servo position to: %d degrees\n\r", deg_up);
  myServo.write(0);
  delay(1000);
  vTaskDelay(1);
  myServo.detach();

  return ERR_CMD_OK;  
}


cmd_err_t adjust_push_angle_cmd(int argc, char *argv[]){
  if (1==argc){
    console_printf("Up angle %d deg, Down angle %d deg.", deg_up, deg_down);
    return ERR_CMD_OK;
  }
  
  int _deg_up, _deg_down;
  if ((3==argc) && (sscanf(argv[1], "%d", &_deg_up)==1) && (sscanf(argv[2], "%d", &_deg_down)==1) && (_deg_up < _deg_down)){
    console_printf("Setting Up angle to %d deg, Down angle to %d deg.", _deg_up, _deg_down);
    deg_up = _deg_up;
    deg_down = _deg_down;
    return ERR_CMD_OK;  
  }else{
    return ERR_BAD_ARG;
  }
}


/*
static Servo myServo;
static int current_degree = 0;

void init_servo(int servoPin) {    
    myServo.attach(servoPin);
    myServo.write(current_degree);
}

bool move_servo_to(int degree){
  if ((degree < 0) || (degree > 180)){
    Serial.printf("input has to be between 0 and 180 degrees.\n\r");
    return false;
  }
  myServo.write(degree);
  current_degree = degree;
  return true;
}

cmd_err_t servo_ctrl_cmd(int argc, char *argv[]){
  int deg;
  if (1 == argc){
    Serial.printf("Current servo position: %d degrees\n\r", current_degree);
    return ERR_CMD_OK;
  }else if ((2==argc) && (1 == sscanf(argv[1], "%d", &deg)) && (deg >= 0) && (deg <= 180)){
    Serial.printf("Setting servo position to: %d degrees\n\r", deg);
    move_servo_to(deg);
    return ERR_CMD_OK;
  }else{    
    return ERR_BAD_ARG;
  }
}

cmd_err_t push_button_cmd(int argc, char *argv[]){
  int deg_up = 0, deg_down = 30;
  
  Serial.printf("Move servo position to: %d degrees\n\r", deg_up);
  move_servo_to(deg_up);
  delay(500);
  vTaskDelay(1);
  Serial.printf("Move servo position to: %d degrees\n\r", deg_down);
  move_servo_to(deg_down);
  delay(500);
  vTaskDelay(1);
  Serial.printf("Move servo position to: %d degrees\n\r", deg_up);
  move_servo_to(deg_up);
  vTaskDelay(1);
  return ERR_CMD_OK;  
}*/