#include <zephyr/devicetree.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/kernel.h>
#include "hog.h"
#include <zephyr/rtio/rtio.h>
#include <zephyr/device.h>
#include <zephyr/drivers/sensor.h>

#define MY_SPI_NODE DT_NODELABEL(imu)

#define GYRO_X_CAL 0
#define GYRO_Y_CAL 0
#define GYRO_Z_CAL 0
#define ACCEL_X_CAL 0
#define ACCEL_Y_CAL 0
#define ACCEL_Z_CAL 0

struct values {
    float traX;
    float traY;
    float traZ;

    float rotX;
    float rotY;
    float rotZ;
};

int main(void) {


  static struct sensor_value accelX, accelY, accelZ;
  static struct sensor_value gyroX, gyroY, gyroZ;
  
  static struct values values;

  const struct device *dev = DEVICE_DT_GET_ANY(st_lsm6dsl);

  sensor_sample_fetch(dev);

  sensor_channel_get(dev, SENSOR_CHAN_ACCEL_X, &accelX);
  sensor_channel_get(dev, SENSOR_CHAN_ACCEL_Y, &accelY);
  sensor_channel_get(dev, SENSOR_CHAN_ACCEL_Z, &accelZ);

  sensor_channel_get(dev, SENSOR_CHAN_GYRO_X, &gyroX);
  sensor_channel_get(dev, SENSOR_CHAN_GYRO_Y, &gyroY);
  sensor_channel_get(dev, SENSOR_CHAN_GYRO_Z, &gyroZ);

  values.traX = (float) accelX.val1 +  (float) accelX.val2 * 1000000 + ACCEL_X_CAL;
  values.traY = (float) accelX.val1 +  (float) accelX.val2 * 1000000 + ACCEL_Y_CAL;
  values.traZ = (float) accelX.val1 +  (float) accelX.val2 * 1000000 + ACCEL_Z_CAL;

  values.rotX = (float) accelX.val1 +  (float) accelX.val2 * 1000000 + GYRO_X_CAL;
  values.rotY = (float) accelX.val1 +  (float) accelX.val2 * 1000000 + GYRO_Y_CAL;
  values.rotZ = (float) accelX.val1 +  (float) accelX.val2 * 1000000 + GYRO_Z_CAL;



}
