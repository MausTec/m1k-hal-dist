#ifndef __m1k_hal_strings_hpp
#define __m1k_hal_strings_hpp

#include "m1k-hal.hpp"

/**
 * Automatically generated string value array for the m1k_hal_err enum.
 */
static const char *m1k_hal_err_str[] = {
    "M1K_HAL_OK",
    "M1K_HAL_FAIL",
    "M1K_HAL_ERR_HARDWARE_LOCKED",
    "M1K_HAL_ERR_NO_STORAGE",
    "M1K_HAL_ERR_NO_FEATURE",
};

/**
 * Automatically generated string value array for the m1k_hal_hardware_type enum.
 */
static const char *m1k_hal_hardware_type_str[] = {
    "M1K_HAL_HARDWARE_TYPE_MERCURY_1000",
};

/**
 * Automatically generated string value array for the m1k_hal_button enum.
 */
static const char *m1k_hal_button_str[] = {
    "M1K_HAL_BUTTON_ANY",
    "M1K_HAL_BUTTON_MENU",
    "M1K_HAL_BUTTON_BOOT",
    "M1K_HAL_BUTTON_AIROUT",
    "M1K_HAL_BUTTON_AIRIN",
};

/**
 * Automatically generated string value array for the m1k_hal_button_evt enum.
 */
static const char *m1k_hal_button_evt_str[] = {
    "M1K_HAL_BUTTON_EVT_DOWN",
    "M1K_HAL_BUTTON_EVT_UP",
    "M1K_HAL_BUTTON_EVT_PRESS",
    "M1K_HAL_BUTTON_EVT_HOLD",
};

/**
 * Automatically generated string value array for the m1k_hal_accessory_mode enum.
 */
static const char *m1k_hal_accessory_mode_str[] = {
    "M1K_HAL_ACCESSORY_DISABLED",
    "M1K_HAL_ACCESSORY_SLAVE",
    "M1K_HAL_ACCESSORY_MASTER",
};

/**
 * Automatically generated string value array for the m1k_hal_air_direction enum.
 */
static const char *m1k_hal_air_direction_str[] = {
    "M1K_HAL_AIR_OUT",
    "M1K_HAL_AIR_IN",
    "M1K_HAL_AIR_CLOSED",
    "M1K_HAL_AIR_CHAOS",
};

#endif
