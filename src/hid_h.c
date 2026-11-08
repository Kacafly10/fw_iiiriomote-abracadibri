#include <zephyr/devicetree.h>
#include <zephyr/device.h>
#include <bluetooth/gatt_pool.h>
#include <bluetooth/services/hogp.h>
#include <bluetooth/services/hids.h>
#include "hid_h.h"

hids

void hids_init() {
    struct bt_hids hids_obj;
    struct bt_hids_init_param init_param;

    bt_hids_init(&hids_obj, &init_param);
}

void send_hid_report(int *reportMap, int plusX, int plusY, int highY) {

}
