#ifndef SERVO_DRIVE_H
#define SERVO_DRIVE_H

#include "command.h"

void init_servo(int servoPin);
// cmd_err_t servo_ctrl_cmd(int argc, char *argv[]);
cmd_err_t push_button_cmd(int argc, char *argv[]);
cmd_err_t adjust_push_angle_cmd(int argc, char *argv[]);

#endif
