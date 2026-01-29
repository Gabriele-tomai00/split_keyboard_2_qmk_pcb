#pragma once

#define EE_HANDS                 // Sets the keyboard’s handedness using EEPROM
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP17
#define SERIAL_USART_RX_PIN GP16
#define SERIAL_USART_PIN_SWAP  // Swap TX and RX pins if keyboard is master halve. (Only available on some MCUs)
// #define SPLIT_MAX_CONNECTION_ERRORS 10 //per usare il master senza lo slave
#define SPLIT_USB_DETECT
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_RGB_MATRIX_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_TRANSPORT_SYNC_ENABLE

// oled
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP6
#define I2C1_SCL_PIN GP7
#ifdef OLED_ENABLE
  #define OLED_DISPLAY_128X32
  #define OLED_TIMEOUT 5000 //5 sec
  #define OLED_BRIGHTNESS 170
#endif

// encoders
#define NUM_ENCODERS 1
#define ENCODERS_PAD { GP14, GP15 } //vial requirements (but It sees that work with the next definitions too)
#define ENCODER_RESOLUTION 4


// rgb
#ifdef RGB_MATRIX_ENABLE
  #define RGB_MATRIX_VAL_STEP 3
  #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 220
  #define RGB_MATRIX_KEYPRESSES // reacts to keypresses
  #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
  #define RGB_MATRIX_SLEEP // turn off effects when suspended
  #define RGB_MATRIX_TIMEOUT 180000 // number of milliseconds to wait until rgb automatically turns off (180000 are 3 min)
#endif
