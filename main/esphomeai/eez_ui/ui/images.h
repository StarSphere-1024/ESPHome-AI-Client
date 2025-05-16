#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <esp_lvgl_port.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_cloudy;
extern const lv_img_dsc_t img_sunny;
extern const lv_img_dsc_t img_rainy;
extern const lv_img_dsc_t img_part_cloudy;
extern const lv_img_dsc_t img_snowy;
extern const lv_img_dsc_t img_unknown;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[6];


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/