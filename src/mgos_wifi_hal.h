/*
 * Copyright (c) 2014-2017 Cesanta Software Limited
 * All rights reserved
 */

#ifndef CS_MOS_LIBS_WIFI_SRC_MGOS_WIFI_HAL_H_
#define CS_MOS_LIBS_WIFI_SRC_MGOS_WIFI_HAL_H_

#include "mgos_net.h"
#include "mgos_wifi.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* HAL interface, to be implemented by ports. */

bool mgos_wifi_dev_ap_setup(const struct sys_config_wifi_ap *cfg);

bool mgos_wifi_dev_sta_setup(const struct sys_config_wifi_sta *cfg);
bool mgos_wifi_dev_sta_connect(void); /* To the previously _setup network. */
bool mgos_wifi_dev_sta_disconnect(void);
enum mgos_wifi_status mgos_wifi_dev_sta_get_status(void);

bool mgos_wifi_dev_get_ip_info(int if_instance,
                               struct mgos_net_ip_info *ip_info);

/* Invoke this when Wifi connection state changes. */
void mgos_wifi_dev_on_change_cb(enum mgos_net_event ev);

bool mgos_wifi_dev_start_scan(void);
/*
 * Invoke this when the scan is done. In case of error, pass num_res < 0.
 * If res is non-NULL, it must be heap-allocated and mgos_wifi takes it over.
 * It is explicitly allowed to invoke mgos_wifi_dev_scan_cb from within
 * mgos_wifi_dev_start_scan if results are available immediately.
 */
void mgos_wifi_dev_scan_cb(int num_res, struct mgos_wifi_scan_result *res);

void mgos_wifi_dev_init(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CS_MOS_LIBS_WIFI_SRC_MGOS_WIFI_HAL_H_ */
