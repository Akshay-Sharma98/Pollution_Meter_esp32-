/*
   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_bt.h"
#include "esp_log.h"
#include "esp_err.h"
#include "nvs_flash.h"

#include "esp_bt.h"
#include "esp_bt_main.h"
#include "esp_gap_ble_api.h"
static const char *tag = "BLE_ADV";


/*static uint8_t example_service_uuid128[32] = {
     LSB <--------------------------------------------------------------------------------> MSB
    //first uuid, 16bit, [12],[13] is the value
    0xfb, 0x34, 0x9b, 0x5f, 0x80, 0x00, 0x00, 0x80, 0x00, 0x10, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00,
};

static esp_ble_adv_data_t example_adv_data = {
    .set_scan_rsp = false,
    .include_name = true,
    .include_txpower = true,
    .min_interval = 0x0006, //slave connection min interval, Time = min_interval * 1.25 msec
    .max_interval = 0x0010, //slave connection max interval, Time = max_interval * 1.25 msec
    .appearance = 0x00,
    // .manufacturer_len = 13,
    //.p_manufacturer_data = mandata,
    .service_data_len = 0,
    .p_service_data = NULL,
    .service_uuid_len = 16,
    .p_service_uuid = example_service_uuid128,
    .flag = 0x6,
};*/

static esp_ble_adv_params_t ble_adv_params = {
		.adv_int_min = 0x20,
		.adv_int_max = 0x40,
		.adv_type = 0x03,
		.own_addr_type = BLE_ADDR_TYPE_PUBLIC,
		.channel_map = ADV_CHNL_ALL,
		.adv_filter_policy = ADV_FILTER_ALLOW_SCAN_ANY_CON_ANY,
};

/*static void esp_gap_cb(esp_gap_ble_cb_event_t event , esp_ble_gap_cb_param_t *param)
{
	switch (event){

	case ESP_GAP_BLE_ADV_DATA_SET_COMPLETE_EVT:
		printf("ESP_GAP_BLEADV_DATA_RAW_SET_COMPLETE_EVT\n");
		esp_ble_gap_start_advertising(&ble_adv_params);
		break;

	case ESP_GAP_BLE_ADV_START_COMPLETE_EVT:
		printf("ESP_GAP_BLE_ADV_START_COMPLETE_EVT\n");
				if(param->adv_start_cmpl.status == ESP_BT_STATUS_SUCCESS) {
					printf("Advertising started\n\n");
				}
				else printf("Unable to start advertising process, error code %d\n\n", param->scan_start_cmpl.status);
				break;

			default:

				printf("Event %d unhandled\n\n", event);
				break;
	}
}*/

/*void bleAdvtTask()
{   static uint8_t *advertdata ={0};
	uint8_t i = 0 ;
	static uint8_t advDATA1 = 0; // , advDATA2 =255;

    while (1) {

    	advertdata[i++] = 0x02;
    	advertdata[i++] = 0xFF;
    	advertdata[i++] = advDATA1;
    	//advertdata[i++] = advDATA2;

    	advDATA1++;
    	//advDATA2--;

    	if (advDATA1 ==10){
    			advDATA1 = 0;}
    	// (advDATA2 == 0)
    		//	{advDATA2 = 255;}


    	esp_ble_gap_config_adv_data_raw(&advertdata,sizeof(advertdata));
    	esp_ble_gap_start_advertising(&ble_adv_params);

    	printf("Adv started");
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        esp_ble_gap_stop_advertising();

        }

    }*/


void app_main()
{
    /* Initialize NVS — it is used to store PHY calibration data */
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK( ret );
    esp_bt_controller_config_t bt_cfg = BT_CONTROLLER_INIT_CONFIG_DEFAULT();

    ret = esp_bt_controller_mem_release(ESP_BT_MODE_CLASSIC_BT);
    if (ret) {
        ESP_LOGI(tag, "Bluetooth controller release classic bt memory failed: %s", esp_err_to_name(ret));
        return;
    }

    if ((ret = esp_bt_controller_init(&bt_cfg)) != ESP_OK) {
        ESP_LOGI(tag, "Bluetooth controller initialize failed: %s", esp_err_to_name(ret));
        return;
    }

    if ((ret = esp_bt_controller_enable(ESP_BT_MODE_BLE)) != ESP_OK) {
        ESP_LOGI(tag, "Bluetooth controller enable failed: %s", esp_err_to_name(ret));
        return;
    }
    esp_bluedroid_init();
    esp_bluedroid_enable();
   printf("Bluedroid initialized and enabled/n");
   //uint8_t adv_raw_data[31] ={2,0x01,0x06,2,0xFF,0,3,0x03,0xAA,0xFE,19,0x16,0xAA,0xFE,0x10,0x20,0x03,0x67,0x6F,0x6F,0x2E,0x67,0x6C,0x2F,0x32,0x79,0x43,0x36,0x4B,0x58};
   uint8_t adv_raw_data[30] = {27,255,170,254,190,172,19,22,170,254,97,107,57,56,111,111,46,103,108,47,50,121,67,54,75,88,-122,0};
   esp_ble_gap_config_adv_data_raw(adv_raw_data,31);
   esp_ble_gap_start_advertising(&ble_adv_params);
   uint8_t i = 255;
   while(1)
   {

	adv_raw_data[5] = i;
	i--;
	if (i == 0)
	{
		i= 255 ;
	}
	esp_ble_gap_stop_advertising();
	esp_ble_gap_config_adv_data_raw(adv_raw_data,31);
    esp_ble_gap_start_advertising(&ble_adv_params);
	vTaskDelay(1000/ portTICK_PERIOD_MS);

   }
   //bleAdvtTask();
}
