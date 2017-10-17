#ifndef CS_MOS_LIBS_ARDUINO_ADAFRUIT_CCS811_H_
#define CS_MOS_LIBS_ARDUINO_ADAFRUIT_CCS811_H_

#include "Adafruit_CCS811.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MGOS_CCS811_RES_FAIL -10000

// Initialize Adafruit_CCS811 library.
// Return value: OneWire handle opaque pointer.
Adafruit_CCS811 *mgos_ccs811_create();

// Close Adafruit_CCS811 handle. Return value: none.
void mgos_ccs811_close(Adafruit_CCS811 *ccs);

// Initialize the sensor with given parameters/settings.
// Returns 0 if the sensor not plugged or a checking failed,
// i.e. the chip ID is incorrect.
// Returns 1 otherwise.
int mgos_ccs811_begin(Adafruit_CCS811 *ccs, int addr);


int mgos_ccs811_read_eco2(Adafruit_CCS811 *ccs);

int mgos_ccs811_read_tvoc(Adafruit_CCS811 *ccs);

#ifdef __cplusplus
}
#endif


#endif /* CS_MOS_LIBS_ARDUINO_ADAFRUIT_CCS811_H_ */