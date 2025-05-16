#include "vars.h"
#include <esp_lvgl_port.h>
#include <string.h>
#include <stdio.h>
#include "screens.h"
#include "images.h"


char temper_data[5] = "--";

const char *get_var_temper_data() {
    return temper_data;
}
void set_var_temper_data(float *value) {
   sprintf(temper_data,"%.0f",*value);
}

char humidity_data[5] = "--";

const char *get_var_humidity_data() {
    return humidity_data;
}

void set_var_humidity_data(float *value) {
    sprintf(humidity_data,"%.0f",*value);
}


char weather_var[12] = "unknown";

const char *get_var_weather_var() {
    return weather_var;
}

void set_var_weather_var(WEATHER weather)
{
    lv_obj_t *obj = objects.weather_icon;
    switch (weather)
    {
    case WEATHER_SUNNY:
        strcpy(weather_var, "Sunny");
        lv_img_set_src(obj, &img_sunny);
        break;
    case WEATHER_CLOUDY:
        strcpy(weather_var, "Cloudy");
        lv_img_set_src(obj, &img_cloudy);
        break;
    case WEATHER_PART_CLOUDY:
        strcpy(weather_var, "Partcloudy");
        lv_img_set_src(obj, &img_part_cloudy);
        break;
    case WEATHER_RAINY:
        strcpy(weather_var, "Rainy");
        lv_img_set_src(obj, &img_rainy);
        break;
    case WEATHER_SNOWY:
        strcpy(weather_var, "Snowy");
        lv_img_set_src(obj, &img_snowy);
        break;
    default:
        strcpy(weather_var, "Unknown");
        lv_img_set_src(obj, &img_unknown);
        break;
        break;
    }
}
