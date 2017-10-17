let Adafruit_CCS811 = {

    RES_FAIL: -100.0,

    _create: ffi('void *mgos_ccs811_create(void)'),
    _close: ffi('void mgos_ccs811_close(void *)'),
    _begin: ffi('int mgos_ccs811_begin(void *, int)'),
    _re: ffi('int mgos_ccs811_read_eco2(void *)'),
    _rt: ffi('int mgos_ccs811_read_tvoc(void *)'),

    _proto: {
        // Close Adafruit_CCS811 handle. Return value: none.
        close: function() {
          return Adafruit_CCS811._close(this.ccs);
        },
    
        // Initialize the sensor with given parameters/settings.
        // Returns 0 if the sensor not plugged or a checking failed,
        // i.e. the chip ID is incorrect.
        // Returns 1 otherwise.
        begin: function(addr) {
          return Adafruit_CCS811._begin(this.ccs, addr);
        },

        // Returns the eCO2 from the sensor in degrees ppm
        // or RES_FAIL if an operation failed.
        readeCO2: function() {
            return Adafruit_CCS811._re(this.ccs);
        },
  
        // Returns the TVOC from the sensor in ppb
        // or RES_FAIL if an operation failed.
        readTVOC: function() {
            return Adafruit_CCS811._rt(this.ccs);
        },
    },
    
    create: function() {
        let obj = Object.create(Adafruit_CCS811._proto);
        // Initialize Adafruit_CCS811 library.
        // Return value: handle opaque pointer.
        obj.ccs = Adafruit_CCS811._create();
        return obj;
    },
}