#ifndef __m1k_hal_hpp
#define __m1k_hal_hpp

#include <stdint.h>
#include <stddef.h>

#include <U8g2lib.h>

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
    M1K_HAL_BUTTON_MENU,
};

typedef enum m1k_hal_button m1k_hal_button_t;
typedef void (*m1k_hal_button_callback_t)(m1k_hal_button_t, bool);

m1k_hal_err_t m1k_hal_register_button_press(m1k_hal_button_t button, m1k_hal_button_callback_t cb);
m1k_hal_err_t m1k_hal_register_button_hold(m1k_hal_button_t button, m1k_hal_button_callback_t cb);


//=== PRESSURE READING

uint16_t m1k_hal_get_pressure_reading(void);


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
m1k_hal_err_t m1k_hal_set_device_serial(char *serial);

#endif