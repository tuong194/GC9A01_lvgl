/********************************************************************************************************
 * @file	app_privacy_beacon.h
 *
 * @brief	for TLSR chips
 *
 * @author	telink
 * @date	Sep. 30, 2010
 *
 * @par     Copyright (c) 2017, Telink Semiconductor (Shanghai) Co., Ltd. ("TELINK")
 *          All rights reserved.
 *
 *          Licensed under the Apache License, Version 2.0 (the "License");
 *          you may not use this file except in compliance with the License.
 *          You may obtain a copy of the License at
 *
 *              http://www.apache.org/licenses/LICENSE-2.0
 *
 *          Unless required by applicable law or agreed to in writing, software
 *          distributed under the License is distributed on an "AS IS" BASIS,
 *          WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *          See the License for the specific language governing permissions and
 *          limitations under the License.
 *
 *******************************************************************************************************/
#ifndef APP_PRIVACY_BEACON_H
#define APP_PRIVACY_BEACON_H
#include "tl_common.h"
#include "mesh_lpn.h"
#include "mesh_fn.h"
#include "time_model.h"
#include "scheduler.h"
#include "mesh_property.h"

#define PRIVATE_BEACON_GET			0x11B7
#define PRIVATE_BEACON_SET			0x12B7
#define PRIVATE_BEACON_STATUS		0x13B7
#define PRIVATE_GATT_PROXY_GET		0x14B7
#define PRIVATE_GATT_PROXY_SET		0x15B7
#define PRIVATE_GATT_PROXY_STATUS	0x16B7
#define PRIVATE_NODE_IDENTITY_GET	0x18B7
#define PRIVATE_NODE_IDENTITY_SET		0x19B7
#define PRIVATE_NODE_IDENTITY_STATUS	0x1AB7

typedef struct{
	u8 beacon_sts;
	u8 random_inv_step;
}private_beacon_str_t;

typedef struct{
	u8 proxy_sts;
}private_gatt_proxy_str_t;

typedef struct{
	u16 netkey_idx;
	u8 private_identity;
}private_node_identity_set_str_t;

typedef struct{
	u16 netkey_idx;
}private_node_identity_get_str_t;

typedef struct{
	u8  sts;
	u16 netkey_idx;
	u8 private_identity;
}private_node_identity_sts_str_t;

typedef struct{
	model_common_t com;
	u8 beacon_sts;
	u8 random_inv_step;
	u8 proxy_sts;
	u8 identity_sts;
}model_private_beacon_ser_t;

typedef struct{
	model_common_t com;
	u8 rfu;
}model_private_beacon_cli_t;

enum{
	PRIVATE_BEACON_DISABLE =0,// default value 
	PRIVATE_BEACON_ENABLE,
	PRIVATE_BEACON_PROHIBIT
};
// random update interval steps 
enum{
	PRIVATE_PROXY_DISABLE =0,
	PRIVATE_PROXY_ENABLE,
	PRIVATE_PROXY_NOT_SUPPORT,
	PRIVATE_PROXY_PROHIBIT
};

enum{
	PRIVATE_NODE_IDENTITY_DISABLE =0,
	PRIVATE_NODE_IDENTITY_ENABLE,
	PRIVATE_NODE_IDENTITY_NOT_SUPPORT,
	PRIVATE_NODE_IDENTITY_PROHIBIT
};

typedef struct{
    #if MD_SERVER_EN
    model_private_beacon_ser_t srv[1];
    #endif
    #if MD_CLIENT_EN
    model_private_beacon_cli_t client[1];
    #endif
}model_private_beacon_t;
extern _align_4_ model_private_beacon_t model_private_beacon;
extern u32 mesh_md_pri_beacon_addr;
void mesh_node_identity_refresh_private();
void mesh_private_proxy_change_by_gatt_proxy(u8 private_sts,u8 *p_private_proxy);
int mesh_rc_data_beacon_privacy(u8 *p_payload, u32 t);
void mesh_key_add_trigger_beacon_send(u8 idx);


#if MD_SERVER_EN
void mesh_private_para_init();
int mesh_cmd_sig_beacon_sts(u8 *par, int par_len, mesh_cb_fun_par_t *cb_par);
int mesh_cmd_sig_beacon_get(u8 *par, int par_len, mesh_cb_fun_par_t *cb_par);
int mesh_cmd_sig_beacon_set(u8 *par, int par_len, mesh_cb_fun_par_t *cb_par);
int mesh_cmd_sig_gatt_proxy_sts(u8 *par, int par_len, mesh_cb_fun_par_t *cb_par);
int mesh_cmd_sig_gatt_proxy_get(u8 *par, int par_len, mesh_cb_fun_par_t *cb_par);
int mesh_cmd_sig_gatt_proxy_set(u8 *par, int par_len, mesh_cb_fun_par_t *cb_par);
int mesh_cmd_sig_private_node_identity_sts(u8 *par, int par_len, mesh_cb_fun_par_t *cb_par);
int mesh_cmd_sig_private_node_identity_get(u8 *par, int par_len, mesh_cb_fun_par_t *cb_par);
int mesh_cmd_sig_private_node_identity_set(u8 *par, int par_len, mesh_cb_fun_par_t *cb_par);
void mesh_prov_para_random_proc();
int mesh_tx_privacy_nw_beacon_all_net(u8 blt_sts);
void generate_non_reslov_mac(u8*p_mac);

#else
#define mesh_privacy_init            				(0)
#define mesh_cmd_sig_beacon_sts_rsp 				(0)
#define mesh_cmd_sig_beacon_sts 					(0)
#define mesh_cmd_sig_beacon_get 					(0)
#define mesh_cmd_sig_beacon_set 					(0)
#define mesh_cmd_sig_gatt_proxy_sts_rsp 			(0)
#define mesh_cmd_sig_gatt_proxy_sts					(0)
#define mesh_cmd_sig_gatt_proxy_get         		(0)
#define mesh_cmd_sig_gatt_proxy_set					(0)
#define mesh_cmd_sig_private_node_identity_sts		(0)
#define mesh_cmd_sig_private_node_identity_get   	(0)
#define mesh_cmd_sig_private_node_identity_set		(0)
#define mesh_prov_para_random_proc					(0)
#define mesh_tx_privacy_nw_beacon_all_net			(0)

#endif
// should add the cache filter to ignore the history private beacon 
#define MAX_SUPPORT_AUTH_TAG_CNT	20
typedef struct{
	u32 idx;
	u8  auth_tag[MAX_SUPPORT_AUTH_TAG_CNT][8];
}auth_tag_cache_t;


#if WIN32
#pragma pack(1)
#endif
#endif
