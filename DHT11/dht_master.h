/*
DHT Library 0x03

copyright (c) Davide Gironi, 2012

Released under GPLv3.
Please refer to LICENSE file for licensing information.

References:
  - DHT-11 Library, by Charalampos Andrianakis on 18/12/11
*/


#ifndef _DHT_H_
#define _DHT_H_

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <mega16.h>

#pragma used+

//setup port
#define DHT_DDR DDRA
#define DHT_PORT PORTA
#define DHT_PIN PINA
#define DHT_INPUTPIN 0

//sensor type
#define DHT_DHT11 1
#define DHT_DHT22 2
#define DHT_TYPE DHT_DHT11

//enable decimal precision (float)
#if DHT_TYPE == DHT_DHT11
#define DHT_FLOAT 0
#elif DHT_TYPE == DHT_DHT22
#define DHT_FLOAT 1
#endif

//timeout retries
#define DHT_TIMEOUT 200

//functions
#if DHT_FLOAT == 1
extern uint8_t dht_gettemperature(float *temperature);
extern uint8_t dht_gethumidity(float *humidity);
extern uint8_t dht_gettemperaturehumidity(float *temperature, float *humidity);
#elif DHT_FLOAT == 0
extern uint8_t dht_gettemperature(uint8_t *temperature);
extern uint8_t dht_gethumidity(uint8_t *humidity);
extern uint8_t dht_gettemperaturehumidity(uint8_t *temperature, uint8_t *humidity);
#endif


#pragma used-

#pragma library dht_master.lib


#endif
