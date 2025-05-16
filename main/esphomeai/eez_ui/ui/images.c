#include "images.h"

const ext_img_desc_t images[6] = {
    { "cloudy", &img_cloudy },
    { "sunny", &img_sunny },
    { "rainy", &img_rainy },
    { "part_cloudy", &img_part_cloudy },
    { "snowy", &img_snowy },
    { "unknown", &img_unknown },
};
