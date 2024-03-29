#ifndef __m1k_hal_hpp
#define __m1k_hal_hpp

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

#include "u8g2.h"


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
    M1K_HAL_ERR_NO_FEATURE,
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
    M1K_HAL_ACCESSORY_SLAVE,
    M1K_HAL_ACCESSORY_MASTER,
};

typedef enum m1k_hal_accessory_mode m1k_hal_accessory_mode_t;

m1k_hal_err_t m1k_hal_set_accessory_mode(m1k_hal_accessory_mode_t mode);
size_t m1k_hal_accessory_read_buffer(char* buffer, size_t buf_len);
size_t m1k_hal_accessory_write_buffer(char* buffer, size_t buf_len);
void m1k_hal_accessory_reset_tx_fifo(void);


//=== DISPLAY

u8g2_t *m1k_hal_get_display_ptr(void);
int m1k_hal_get_display_width(void);
int m1k_hal_get_display_height(void);
int m1k_hal_get_display_left(void);
void m1k_hal_send_display_screenshot(const char *label);
void m1k_hal_set_display_backlight(uint8_t brightness);

//=== EEPROM

m1k_hal_err_t m1k_hal_get_device_serial(char *dst, size_t len);

//=== Milker Control

void m1k_hal_hv_power_on(void);
void m1k_hal_hv_power_off(void);
void m1k_hal_set_drive_freq(uint32_t freq_hz);
int m1k_hal_hv_is_on();
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

#ifdef __cplusplus
}
#endif

#endif