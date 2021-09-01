#ifndef __m1k_hal_hpp
#define __m1k_hal_hpp

#include <stdint.h>
#include <stddef.h>

#include <U8g2lib.h>

#define M1K_HAL_ERRCHK(statement) { \
    auto __err_ = statement; \
    if (M1K_HAL_OK != __err_) ESP_LOGE(TAG, "%s returned %s", #statement, m1k_hal_err_str[__err_]); \
}

//=== COMMON

enum m1k_hal_err {
    M1K_HAL_OK,
    M1K_HAL_FAIL,
    M1K_HAL_ERR_HARDWARE_LOCKED,
    M1K_HAL_ERR_NO_STORAGE,
};

typedef enum m1k_hal_err m1k_hal_err_t;

enum m1k_hal_hardware_type {
    M1K_HAL_HARDWARE_TYPE_MERCURY_1000,
};

typedef enum m1k_hal_hardware_type m1k_hal_hardware_type_t;

m1k_hal_hardware_type_t m1k_hal_get_hardware_type(void);
const char *m1k_hal_get_version(void);

m1k_hal_err_t m1k_hal_init(void);
m1k_hal_err_t m1k_hal_tick(void);
m1k_hal_err_t m1k_hal_deinit(void);


//=== BUTTONS AND CONTROL

enum m1k_hal_button {
    M1K_HAL_BUTTON_ANY,
    M1K_HAL_BUTTON_MENU,
    M1K_HAL_BUTTON_BOOT,
    M1K_HAL_BUTTON_AIROUT,
    M1K_HAL_BUTTON_AIRIN,
};

typedef enum m1k_hal_button m1k_hal_button_t;

enum m1k_hal_button_evt {
    M1K_HAL_BUTTON_EVT_DOWN,
    M1K_HAL_BUTTON_EVT_UP,
    M1K_HAL_BUTTON_EVT_PRESS,
    M1K_HAL_BUTTON_EVT_HOLD,
};

typedef enum m1k_hal_button_evt m1k_hal_button_evt_t;

typedef void (*m1k_hal_button_callback_t)(m1k_hal_button_t, m1k_hal_button_evt_t);
typedef void (*m1k_hal_encoder_callback_t)(int);

m1k_hal_err_t m1k_hal_register_button_cb(m1k_hal_button_t button, m1k_hal_button_callback_t cb);
m1k_hal_err_t m1k_hal_register_encoder_change(m1k_hal_encoder_callback_t cb);


//=== PRESSURE READING

/**
 * Returns current pressure value in approximate kPa
 */
double m1k_hal_get_pressure_reading(void);


//=== RJ ABSTRACTION

enum m1k_hal_accessory_mode {
    M1K_HAL_ACCESSORY_DISABLED,
    M1K_HAL_ACCESSORY_SOURCE,
    M1K_HAL_ACCESSORY_TARGET,
};

typedef enum m1k_hal_accessory_mode m1k_hal_accessory_mode_t;


//=== DISPLAY

typedef U8G2_ST7920_192X32_F_SW_SPI m1k_hal_display_t;
m1k_hal_display_t *m1k_hal_get_display_ptr(void);
int m1k_hal_get_display_width(void);
int m1k_hal_get_display_height(void);
int m1k_hal_get_display_left(void);

//=== EEPROM

m1k_hal_err_t m1k_hal_get_device_serial(char *dst, size_t len);

//=== Milker Control

void m1k_hal_hv_power_on(void);
void m1k_hal_hv_power_off(void);
bool m1k_hal_hv_is_on();
void m1k_hal_set_milker_speed(uint8_t speed);
uint8_t m1k_hal_get_milker_speed(void);

//=== Pressure Management

enum m1k_hal_air_direction {
    M1K_HAL_AIR_OUT,
    M1K_HAL_AIR_IN,
    M1K_HAL_AIR_CLOSED,
    M1K_HAL_AIR_CHAOS,
};

typedef enum m1k_hal_air_direction m1k_hal_air_direction_t;

void m1k_hal_air_out(void);
void m1k_hal_air_in(void);
void m1k_hal_air_stop(void);
m1k_hal_air_direction_t m1k_hal_air_get_direction(void);

#endif