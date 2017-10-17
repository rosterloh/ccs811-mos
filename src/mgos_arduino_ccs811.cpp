#include "mgos_arduino_ccs811.h"

Adafruit_CCS811 *mgos_ccs811_create() {
    return new Adafruit_CCS811();
}

void mgos_ccs811_close(Adafruit_CCS811 *ccs) {
    if (ccs != nullptr) {
        delete ccs;
        ccs = nullptr;
    }
}
  
int mgos_ccs811_begin(Adafruit_CCS811 *ccs, int addr) {
    if (ccs == nullptr) return 0;
    return ccs->begin(addr);
}

int mgos_ccs811_read_eco2(Adafruit_CCS811 *ccs) {
    if (ccs == nullptr) return MGOS_CCS811_RES_FAIL;
    if (!ccs->readData()) {
        return ccs->geteCO2();
    } else {
        return MGOS_CCS811_RES_FAIL;
    }
}

int mgos_ccs811_read_tvoc(Adafruit_CCS811 *ccs) {
    if (ccs == nullptr) return MGOS_CCS811_RES_FAIL;
    if (!ccs->readData()) {
        return ccs->getTVOC();
    } else {
        return MGOS_CCS811_RES_FAIL;
    }
}