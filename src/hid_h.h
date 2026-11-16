#ifndef HID_H_H_
#define HID_H_H_
#include <stdbool.h>

struct values {
  float traX;
  float traY;
  float traZ;

  float rotX;
  float rotY;
  float rotZ;

  bool button;
};

void hids_init();

void send_hid_report(struct values values);
#endif