/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"
#include "C:\Users\12153\pico\pico-sdk\src\rp2_common\hardware_gpio\include\hardware\gpio.h"
#include "C:\Users\12153\pico\pico-sdk\src\boards\include\boards\adafruit_qtpy_rp2040.h"

#define gpio_out_pinn 23
#define gpio_out_pinn2 22
#define gpio_out_pinnboot 21

#define IS_RGBW true
#define NUM_PIXELS 150

#ifdef PICO_DEFAULT_WS2812_PIN
#define WS2812_PIN PICO_DEFAULT_WS2812_PIN
#else
// default to pin 2 if the board doesn't have a default WS2812 pin defined
#define WS2812_PIN 2
#endif

static inline void put_pixel(uint32_t pixel_grb) {
    pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);
}

static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b) {
    return
            ((uint32_t) (r) << 8) |
            ((uint32_t) (g) << 16) |
            (uint32_t) (b);
}

void pattern_snakes(uint len, uint t) {
    for (uint i = 0; i < len; ++i) {
        uint x = (i + (t >> 1)) % 64;
        if (x < 10)
            put_pixel(urgb_u32(0xff, 0, 0));
        else if (x >= 15 && x < 25)
            put_pixel(urgb_u32(0, 0xff, 0));
        else if (x >= 30 && x < 40)
            put_pixel(urgb_u32(0, 0, 0xff));
        else
            put_pixel(0);
    }
}

void pattern_random(uint len, uint t) {
    if (t % 8)
        return;
    for (int i = 0; i < len; ++i)
        put_pixel(rand());
}

void pattern_sparkle(uint len, uint t) {
    if (t % 8)
        return;
    for (int i = 0; i < len; ++i)
        put_pixel(rand() % 16 ? 0 : 0xffffffff);
}

void pattern_greys(uint len, uint t) {
    int max = 100; // let's not draw too much current!
    t %= max;
    for (int i = 0; i < len; ++i) {
        put_pixel(t * 0x10101);
        if (++t >= max) t = 0;
    }
}

typedef void (*pattern)(uint len, uint t);
const struct {
    pattern pat;
    const char *name;
} pattern_table[] = {
        {pattern_snakes,  "Snakes!"},
        {pattern_random,  "Random data"},
        {pattern_sparkle, "Sparkles"},
        {pattern_greys,   "Greys"},
};




int main() {
    stdio_init_all();
    gpio_init(gpio_out_pinn);
    gpio_set_dir(gpio_out_pinn, GPIO_OUT);
    gpio_init(gpio_out_pinn2);
    gpio_set_dir(gpio_out_pinn2, GPIO_OUT);
    stdio_init_all();
    //int t;
    int ip1;
    int ip2;
    int ip3;
    int ip4;

    while(!stdio_usb_connected());
    
    while (true) {
        printf("start\n");
        
        sleep_ms(500);
        
        printf("Name the largest planet in the solar system\n");
        printf("1 Jupiter\n");
        printf("2 Neptune\n");
        
    
        scanf("%d",&ip1);
        printf("%d",ip1);

       
        if(ip1==1){
           printf("correct!\n");
           gpio_put(gpio_out_pinn, 1);
           sleep_ms(500);
           gpio_put(gpio_out_pinn, 0);
           sleep_ms(500); 
        }
        else {
          
            printf("uh oh, better luck next time\n");
            gpio_put(gpio_out_pinn2, 1);
            sleep_ms(500);
            gpio_put(gpio_out_pinn2, 0);
            sleep_ms(500); 
          
        }
       
        printf("Which is the largest continent in the world\n");
        printf("1 Antarctica\n");
        printf("2 Asia\n");
        
        
       
        sleep_ms(500);
        scanf("%d", &ip2);
        printf("%d",ip2);
        if(ip2==2){
           printf("correct!\n");
           gpio_put(gpio_out_pinn, 1);
           sleep_ms(500);
           gpio_put(gpio_out_pinn, 0);
           sleep_ms(500); 
        }
        else {
           
           printf("uh oh, better luck next time\n");
           gpio_put(gpio_out_pinn2, 1);
           sleep_ms(500);
           gpio_put(gpio_out_pinn2, 0);
           sleep_ms(500); 
           
        }
        
        printf("What is the 4th letter of the greek alphabet\n");
        printf("1 Gamma\n");
        printf("2 Delta\n");
        
        
        
        scanf("%d", &ip3);
        printf("%d",ip3);
        if(ip3==2){
           printf("correct!\n");
           gpio_put(gpio_out_pinn, 1);
           sleep_ms(500);
           gpio_put(gpio_out_pinn, 0);
           sleep_ms(500); 
        }
        else {
           // flag=1;
           printf("uh oh, better luck next time\n");
           gpio_put(gpio_out_pinn2, 1);
           sleep_ms(500);
           gpio_put(gpio_out_pinn2, 0);
           sleep_ms(500); 
        }
        
        printf("What animal is covered in quills\n");
        printf("1 Porcupine\n");
        printf("2 Camel\n");
        
       
       
        sleep_ms(500);
        scanf("%d", &ip4);
        printf("%d",ip4);
        if(ip4==1){
           printf("correct!\n");
           gpio_put(gpio_out_pinn, 1);
           sleep_ms(500);
           gpio_put(gpio_out_pinn, 0);
           sleep_ms(500); 
        }
        else {
           // flag=1;
           printf("uh oh, better luck next time\n");
           gpio_put(gpio_out_pinn2, 1);
           sleep_ms(500);
           gpio_put(gpio_out_pinn2, 0);
           sleep_ms(500); 
        }
       
        printf("Well played!");
        sleep_ms(500);
        exit(0);
        }
      return 0;  
    }
  

