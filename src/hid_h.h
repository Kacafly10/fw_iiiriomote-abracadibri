#ifndef HID_H_H_
#define HID_H_H_

#include <stdint.h>

void hids_init();

void send_hid_report(int pitch, int roll, int yaw, int plusX, int plusY, int highY);
#endif