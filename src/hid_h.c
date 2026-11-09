#include <zephyr/devicetree.h>
#include <zephyr/device.h>
#include <bluetooth/gatt_pool.h>
#include <bluetooth/services/hogp.h>
#include <bluetooth/services/hids.h>
#include "hid_h.h"

void hids_init() {
    struct bt_hids hids_obj;
    struct bt_hids_init_param init_param;

    struct bt_hids_info info;
    struct bt_hids_inp_rep inp_rep;
    struct bt_hids_rep_map rep_map;

    info.bcd_hid = 0x0111;
    info.b_country_code = 0x00;

    inp_rep.id = 1;
    inp_rep.size = 3;

    rep_map.data = reportMap;
    rep_map.size = sizeof(reportMap);
    
    init_param.info = info;
    init_param.rep_map = rep_map;
    init_param.is_mouse = true;

    bt_hids_init(&hids_obj, &init_param);
}

void send_hid_report(int *reportMap, int plusX, int plusY, int highY) {

}
