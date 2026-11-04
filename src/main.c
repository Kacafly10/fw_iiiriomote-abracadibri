#include <zephyr/kernel.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/rtio/rtio.h>
#include <zephyr/devicetree.h>

#include <zephyr/device.h>
#include <zephyr/drivers/sensor.h>

#define MY_SPI_NODE DT_NODELABEL(imu)

static struct sensor_value accelX, accelY, accelZ;
static struct sensor_value gyroX, gyroY, gyroZ;

/* Define the iodev for the SPI device node */
SPI_DT_IODEV_DEFINE(imu, MY_SPI_NODE, SPI_WORD_SET(8) | SPI_TRANSFER_MSB | SPI_MODE_CPOL | SPI_MODE_CPHA);

/* Define an RTIO context with 4 SQE slots and 4 CQE slots */
RTIO_DEFINE(spi_rtio_ctx, 4, 4);

int main(void) {
    struct rtio_sqe *sqe;
    struct rtio_cqe *cqe;
    int err;

    sqe = rtio_sqe_acquire(&spi_rtio_ctx);
    if (sqe == NULL) {
        return -ENOMEM;
    }
    rtio_sqe_prep_transceive(sqe, &imu, RTIO_PRIO_NORM,
                             tx_data, rx_data, sizeof(tx_data), NULL);
    
    sensor_stream_data_opt();
}

