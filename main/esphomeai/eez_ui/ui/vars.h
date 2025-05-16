#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// enum declarations
typedef enum {
    WEATHER_UNKNOWN = 0,
    WEATHER_SUNNY,
    WEATHER_CLOUDY,
    WEATHER_PART_CLOUDY,
    WEATHER_RAINY,
    WEATHER_SNOWY
} WEATHER;


// Flow global variables

enum FlowGlobalVariables {
    FLOW_GLOBAL_VARIABLE_WEATHER_VAR = 0
};

// Native global variables

extern const char * get_var_humidity_data();
extern void set_var_humidity_data(float * value);
extern const char * get_var_temper_data();
extern void set_var_temper_data(float * value);
extern const char *get_var_weather_var();
extern void set_var_weather_var(WEATHER weather);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/