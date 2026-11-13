#include <zephyr/device.h>
#include <bluetooth/services/hids.h>
#include "hid_h.h"
#include "iiiriomote.h"

#define CONN_DEF()

struct bt_hids hids_obj;
struct bt_conn_ctx conn_ctx;

void hids_init()
{
    struct bt_hids_init_param init_param = {0};

    init_param.info.bcd_hid = 0x0111;
    init_param.info.b_country_code = 0x00;
    init_param.info.flags = BT_HIDS_REMOTE_WAKE | BT_HIDS_NORMALLY_CONNECTABLE | BT_HIDS_SCI_SUPPORTED;

    init_param.inp_rep_group_init.reports[0].id = 1;
    init_param.inp_rep_group_init.reports[0].size = 3;

    init_param.rep_map.data = reportMap;
    init_param.rep_map.size = sizeof(reportMap);

    init_param.is_mouse = true;

    bt_hids_init(&hids_obj, &init_param);
}

void send_hid_report(int pitch, int roll, int yaw, int plusX, int plusY, int highZ)
{
    uint8_t rep[] = {
        0x01,
    };

    bt_hids_inp_rep_send(&hids_obj, conn_ctx.conn, 0, rep, 3, NULL);
}
