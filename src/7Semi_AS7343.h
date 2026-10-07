#ifndef _7SEMI_AS7343_H_ 
#define _7SEMI_AS7343_H_

#include <Arduino.h>
#include <Wire.h>

#include "7Semi_I2C_Interface.h"
#include "BusIO_7Semi.h"

#define AS7343_DEFAULT_ADDR 0x39
#define AS7343_DEVICE_ID 0x81

// AS7343 Register Map
#define AS7343_REG_AUXID        0x58  
#define AS7343_REG_REVID        0x59  
#define AS7343_REG_ID           0x5A 

#define AS7343_REG_CFG12        0x66 

#define AS7343_REG_ENABLE       0x80
#define AS7343_REG_ATIME        0x81  
#define AS7343_REG_WTIME        0x83 

#define AS7343_REG_SP_TH_L_LSB  0x84
#define AS7343_REG_SP_TH_L_MSB  0x85
#define AS7343_REG_SP_TH_H_LSB  0x86
#define AS7343_REG_SP_TH_H_MSB  0x87

#define AS7343_REG_STATUS       0x93
#define AS7343_REG_ASTATUS      0x94
#define AS7343_REG_DATA_0_L     0x95
#define AS7343_REG_DATA_0_H     0x96

#define AS7343_REG_DATA_1_L     0x97
#define AS7343_REG_DATA_1_H     0x98
#define AS7343_REG_DATA_2_L     0x99
#define AS7343_REG_DATA_2_H     0x9A

// Channel 3
#define AS7343_REG_DATA_3_L     0x9B
#define AS7343_REG_DATA_3_H     0x9C

// Channel 4
#define AS7343_REG_DATA_4_L     0x9D
#define AS7343_REG_DATA_4_H     0x9E

// Channel 5
#define AS7343_REG_DATA_5_L     0x9F
#define AS7343_REG_DATA_5_H     0xA0

// Channel 6
#define AS7343_REG_DATA_6_L     0xA1
#define AS7343_REG_DATA_6_H     0xA2

// Channel 7
#define AS7343_REG_DATA_7_L     0xA3
#define AS7343_REG_DATA_7_H     0xA4

// Channel 8
#define AS7343_REG_DATA_8_L     0xA5
#define AS7343_REG_DATA_8_H     0xA6

// Channel 9
#define AS7343_REG_DATA_9_L     0xA7
#define AS7343_REG_DATA_9_H     0xA8

// Channel 10
#define AS7343_REG_DATA_10_L    0xA9
#define AS7343_REG_DATA_10_H    0xAA

// Channel 11
#define AS7343_REG_DATA_11_L    0xAB
#define AS7343_REG_DATA_11_H    0xAC

// Channel 12
#define AS7343_REG_DATA_12_L    0xAD
#define AS7343_REG_DATA_12_H    0xAE

// Channel 13
#define AS7343_REG_DATA_13_L    0xAF
#define AS7343_REG_DATA_13_H    0xB0

// Channel 14
#define AS7343_REG_DATA_14_L    0xB1
#define AS7343_REG_DATA_14_H    0xB2

// Channel 15
#define AS7343_REG_DATA_15_L    0xB3
#define AS7343_REG_DATA_15_H    0xB4

// Channel 16
#define AS7343_REG_DATA_16_L    0xB5
#define AS7343_REG_DATA_16_H    0xB6

// Channel 17
#define AS7343_REG_DATA_17_L    0xB7
#define AS7343_REG_DATA_17_H    0xB8

#define AS7343_REG_STATUS2   0x90
#define AS7343_REG_STATUS3   0x91
#define AS7343_REG_STATUS4   0xBC
#define AS7343_REG_STATUS5   0xBB

#define AS7343_REG_CFG0      0xBF

// Configuration
#define AS7343_REG_CFG1        0xC6   
#define AS7343_REG_CFG3        0xC7  
#define AS7343_REG_CFG6        0xF5  
#define AS7343_REG_CFG8        0xC9  
#define AS7343_REG_CFG9        0xCA   
#define AS7343_REG_CFG20       0xD6  
#define AS7343_REG_CFG10       0x65 
#define AS7343_REG_PERS        0xCF   
#define AS7343_REG_GPIO        0x6B   

// Integration step
#define AS7343_REG_ASTEP_L       0xD4
#define AS7343_REG_ASTEP_H       0xD5

#define AS7343_REG_FD_TIME_1     0xE0
#define AS7343_REG_FD_TIME_2     0xE2
#define AS7343_REG_FD_STATUS     0xE3

#define AS7343_REG_INTENAB       0xF9
#define AS7343_REG_CONTROL       0xFA

#define AS7343_PERS_APERS_MASK   0x0F   
#define AS7343_PERS_FD_PERS_MASK 0x70   

#define AS7343_REG_LED         0xCD  
#define AS7343_REG_AGC_GAIN    0xD7   
#define AS7343_REG_AZ_CONFIG   0xDE 

#define AS7343_REG_FD_TIME_1   0xE0
#define AS7343_REG_FD_TIME_2   0xE2
#define AS7343_REG_FIFO_CFG0   0xDF
#define AS7343_REG_FD_STATUS   0xE3

#define AS7343_REG_INTENAB     0xF9
#define AS7343_REG_CONTROL     0xFA


#define AS7343_REG_FIFO_MAP    0xFC
#define AS7343_REG_FIFO_LVL    0xFD
#define AS7343_REG_FDATA_L     0xFE
#define AS7343_REG_FDATA_H     0xFF




/**
 * Power Mode (LPM)
 *
 * - Controls performance vs power consumption
 *
 * Modes:
 * - LPM0 → highest performance, fastest response
 * - LPM1 → balanced mode
 * - LPM2 → reduced power
 * - LPM3 → lowest power, slowest response
 *
 * Notes:
 * - Affects conversion time and accuracy
 */
enum AS7343_PowerMode
{
    LPM0    = 0,
    LPM1    = 1,
    LPM2    = 2,
    LPM3    = 3,
    LPM_MAX = 4
};

/**
 * Alert Channel Selection
 *
 * - Selects spectral channel used for threshold interrupt
 */
enum class Alert_Channel
{
    CH0 = 0,
    CH1,
    CH2,
    CH3,
    CH4,
    CH5
};

/**
 * Output Data Rate (ODR)
 *
 * - Defines measurement update rate
 *
 * Rates:
 * - 0.5Hz → slow, low power
 * - 10Hz  → fast, higher power
 */
enum AS7343_ODR
{
    ODR_0_5HZ = 0,
    ODR_1HZ,
    ODR_2HZ,
    ODR_4HZ,
    ODR_10HZ,
    ODR_MAX
};

/**
 * Power Control
 *
 * - Enables or disables sensor operation
 */
enum class AS7343_PowerOn
{
    POWER_OFF = 0,
    POWER_ON  = 1
};

/**
 * Gain Control
 *
 * - Adjusts sensor sensitivity
 *
 * Notes:
 * - Higher gain → more sensitivity, more noise risk
 */
enum class Gain
{
    GAIN_0_5X = 0,
    GAIN_1X,
    GAIN_2X,
    GAIN_4X,
    GAIN_8X,
    GAIN_16X,
    GAIN_32X,
    GAIN_64X,
    GAIN_128X,
    GAIN_256X,
    GAIN_512X,
    GAIN_1024X,
    GAIN_2048X
};

/**
 * FIFO Threshold Level
 *
 * - Defines interrupt trigger level for FIFO
 */
enum class FIFO_Level
{
    FIFO_TH_1  = 0,
    FIFO_TH_4,
    FIFO_TH_8,
    FIFO_TH_16
};

/**
 * SMUX Command
 *
 * - Controls SMUX operation
 */
enum class AS7343_SMUX_Command
{
    SMUX_INIT      = 0,
    READ_RAM       = 1,
    SMUX_WRITE_RAM = 2
};

/**
 * Auto SMUX Mode
 *
 * - Configures automatic channel sequencing
 *
 * Modes:
 * - AUTO_6CH  → single cycle (6 channels)
 * - AUTO_12CH → 2 cycles (12 channels)
 * - AUTO_18CH → 3 cycles (18 channels)
 */
enum class AS7343_Auto_SMUX : uint8_t
{
    AUTO_6CH  = 0,
    AUTO_12CH = 2,
    AUTO_18CH = 3
};

/**
 * Interrupt Persistence
 *
 * - Filters interrupt triggering over multiple cycles
 */
enum class AS7343_Persistence : uint8_t
{
    EVERY_CYCLE = 0,
    CYCLES_1,
    CYCLES_2,
    CYCLES_3,
    CYCLES_5,
    CYCLES_10,
    CYCLES_15,
    CYCLES_20,
    CYCLES_25,
    CYCLES_30,
    CYCLES_35,
    CYCLES_40,
    CYCLES_45,
    CYCLES_50,
    CYCLES_55,
    CYCLES_60
};

/**
 * Flicker FIFO Mode
 *
 * - Enables flicker data in FIFO
 */
enum class AS7343_Fifo_8_Bit_Flicker_Mode : uint8_t
{
    DISABLE = 0,
    ENABLE  = 1
};

/**
 * Spectral Data Structure
 *
 * - Holds all 18 spectral channel values
 */
struct AS7343_SpectralData
{
    uint16_t BLUE_450;  // FZ Blue region (450nm)
    uint16_t GREN_555;  // FY Green wide band (555nm) 
    uint16_t YELLOW_600;// FXL Yellow region (600nm) 
    uint16_t NIR_855;   // NIR Near IR (855nm) - infrared sensing
    uint16_t BRITNESS_1;// Visible light (broad)
    uint16_t FLICKER_1; // Flicker channel - used for 100/120Hz detection

    uint16_t BLUE_425;  // F2 Deep blue (425nm) 
    uint16_t BLUE_475;  // F3 Blue (475nm)
    uint16_t GREEN_515; // F4 Blue-green (515nm) 
    uint16_t RED_640;   // F6 Red (640nm) 
    uint16_t BRITNESS_2;// Visible light (broad) 
    uint16_t FLICKER_2; // Flicker channel (cycle 2)

    uint16_t VIOLET_405; // F1 Violet (405nm) 
    uint16_t RED_690;    // F7 Red (690nm) 
    uint16_t RED_745;    // F8 Deep red (745nm)
    uint16_t GREEN_550;  // F5 Green narrow (550nm)
    uint16_t BRITNESS_3; // Visible light (broad) 
    uint16_t FLICKER_3;  // Flicker channel (cycle 3)
};

/**
 * Sensor Status Structure
 *
 * - Contains all runtime status flags and error indicators
 */
struct AS7343_Status
{
    // Global flags
    bool spectral_saturation;
    bool valid_data;
    bool fifo_interrupt;
    bool system;
    bool init_busy;
    uint8_t gain;
    bool spectral_int;

    // Saturation details
    struct Saturation
    {
        bool analog;
        bool digital;
        bool flicker_analog;
        bool flicker_digital;
    } saturation;

    // Interrupt flags
    struct Interrupt
    {
        bool fifo_level;
        bool high_alert;
        bool low_alert;
        bool flicker_detect;
        bool smux_done;
    } interrupt;

    // Error flags
    struct Error
    {
        bool fifo_overflow;
        bool over_temp;
        bool flicker_trigger_error;
        bool spectral_trigger_error;
        bool sleep_active;
    } error;

    // Flicker detection
    struct Flicker
    {
        bool valid;
        bool saturate;
        bool valid_120Hz;
        bool valid_100Hz;
        bool detected_120Hz;
        bool detected_100Hz;
    } flicker;
};

class AS7343_7Semi
{
public:
    AS7343_7Semi();

    ~AS7343_7Semi();

    /**
     * Initialize Sensor
     *
     * - Initializes I2C communication with the AS7343 sensor
     * - Assigns user-defined I2C address and interface
     * - Configures I2C clock speed
     * - Performs soft reset to ensure clean startup
     * - Enables power and spectral measurement engine
     * - Verifies device identity using Device ID register
     *
     * Parameters:
     * - i2cAddress → I2C address of the sensor (default: 0x39)
     * - i2cPort    → Reference to TwoWire interface (Wire, Wire1, etc.)
     * - i2cClock   → I2C clock frequency (e.g., 100000, 400000)
     *
     * Returns:
     * - true  → Sensor initialized and verified successfully
     * - false → Initialization failed or incorrect device detected
     */
    bool begin(uint8_t address = AS7343_DEFAULT_ADDR,
               TwoWire &port = Wire,
               uint32_t clock = 400000);

    /**
     * getDeviceID
     *
     * - Reads device ID from sensor
     * - Used to verify correct device connection
     *
     * Parameters:
     * - id → reference to store device ID value
     *
     * Returns:
     * - true  → Read successful
     * - false → Communication failed
     */
    bool getDeviceID(uint8_t &id);

    /**
     * setPower
     *
     * - Enables or disables sensor power
     * - Controls PON bit (Power ON)
     *
     * Parameters:
     * - powerOn → POWER_ON or POWER_OFF
     *
     * Returns:
     * - true  → Operation successful
     * - false → Communication failed
     */
    bool setPower(AS7343_PowerOn powerOn);

    /**
     * setSpectralEnable
     *
     * - Enables or disables spectral measurement engine
     * - Controls SP_EN bit
     *
     * Parameters:
     * - enableSpectral → true = enable measurement, false = disable
     *
     * Returns:
     * - true  → Operation successful
     * - false → Communication failed
     */
    bool setSpectralEnable(bool enableSpectral);

    /**
     * getPower
     *
     * - Reads current power state of sensor
     *
     * Parameters:
     * - powerOn → reference to store power state
     *
     * Returns:
     * - true  → Read successful
     * - false → Communication failed
     */
    bool getPower(bool &powerOn);

    /**
     * getSpectralEnable
     *
     * - Reads spectral engine enable state
     *
     * Parameters:
     * - enableSpectral → reference to store state
     *
     * Returns:
     * - true  → Read successful
     * - false → Communication failed
     */
    bool getSpectralEnable(bool &enableSpectral);

    /**
     * setSMUX
     *
     * - Enables or disables SMUX operation
     * - Used for channel configuration and sequencing
     *
     * Parameters:
     * - enableSMUX → true = enable SMUX, false = disable
     *
     * Returns:
     * - true  → Operation successful
     * - false → Communication failed
     */
    bool setSMUX(bool enableSMUX);

    /**
     * softReset
     *
     * - Performs a soft reset of the sensor
     * - Restores default configuration and clears internal state
     *
     * Returns:
     * - true  → Reset command sent successfully
     * - false → I2C communication failed
     */
    bool softReset();

    /**
     * setLED
     *
     * - Controls onboard LED state and brightness
     * - Brightness range is internally mapped to register value
     *
     * Parameters:
     * - ledOn     → true = LED ON, false = LED OFF
     * - brightness → LED current in mA (range: 4 to 258)
     *
     * Returns:
     * - true  → Operation successful
     * - false → Communication failed
     */
    bool setLED(bool ledOn, uint16_t brightness = 4);

    /**
     * getLED
     *
     * - Reads LED state and brightness
     *
     * Parameters:
     * - ledOn     → reference to store LED state
     * - brightness → reference to store brightness in mA
     *
     * Returns:
     * - true  → Read successful
     * - false → Communication failed
     */
    bool getLED(bool &ledOn, uint16_t &brightness);

    /**
     * readSpectralData
     *
     * - Reads all spectral channel data (18 channels)
     * - Combines LSB and MSB into 16-bit values
     *
     * Parameters:
     * - data → reference to store spectral readings
     *
     * Returns:
     * - true  → Read successful
     * - false → Communication failed
     */
    bool readSpectralData(AS7343_SpectralData &data);

    /**
     * setGain
     *
     * - Sets sensor gain (sensitivity)
     *
     * Parameters:
     * - gain → gain level (enum)
     *
     * Returns:
     * - true  → Operation successful
     * - false → Communication failed
     */
    bool setGain(Gain gain);

    /**
     * getGain
     *
     * - Reads current gain setting
     *
     * Parameters:
     * - gain → reference to store gain value
     *
     * Returns:
     * - true  → Read successful
     * - false → Communication failed
     */
    bool getGain(uint8_t &gain);

    /**
     * setIntegrationTime
     *
     * - Configures integration time using ATIME and ASTEP
     *
     * Parameters:
     * - atime → integration cycles
     * - astep → step size
     *
     * Returns:
     * - true  → Operation successful
     * - false → Communication failed
     */
    bool setIntegrationTime(uint8_t atime, uint16_t astep);

    /**
     * getIntegrationTime
     *
     * - Reads integration time configuration
     *
     * Parameters:
     * - atime → reference to store ATIME
     * - astep → reference to store ASTEP
     *
     * Returns:
     * - true  → Read successful
     * - false → Communication failed
     */
    bool getIntegrationTime(uint8_t &atime, uint16_t &astep);

    /**
     * setInterruptEnable
     *
     * - Enables or disables interrupt sources
     * - Preserves reserved bits in register
     *
     * Parameters:
     * - asien → saturation interrupt enable
     * - sp_ien → spectral interrupt enable
     * - f_ien  → FIFO interrupt enable
     * - sien   → system interrupt enable
     *
     * Returns:
     * - true  → Operation successful
     * - false → Communication failed
     */
    bool setInterruptEnable(bool asien, bool sp_ien, bool f_ien, bool sien);

    /**
     * getInterruptEnable
     *
     * - Reads interrupt enable configuration
     *
     * Parameters:
     * - asien → saturation interrupt state
     * - sp_ien → spectral interrupt state
     * - f_ien  → FIFO interrupt state
     * - sien   → system interrupt state
     *
     * Returns:
     * - true  → Read successful
     * - false → Communication failed
     */
    bool getInterruptEnable(bool &asien, bool &sp_ien, bool &f_ien, bool &sien);

    /**
     * setAutoZero
     *
     * - Configures and triggers auto-zero calibration
     *
     * Parameters:
     * - enableAutoZero → true = trigger auto-zero
     * - autoZeroFrequency → iteration frequency
     *
     * Returns:
     * - true  → Operation successful
     * - false → Communication failed
     */
    bool setAutoZero(bool enableAutoZero, uint8_t autoZeroFrequency);

    /**
     * flushFIFO
     *
     * - Clears FIFO buffer and related flags
     *
     * Returns:
     * - true  → Operation successful
     * - false → Communication failed
     */
    bool flushFIFO();

    /**
     * wakeFromInterrupt
     *
     * - Clears sleep-after-interrupt state
     *
     * Returns:
     * - true  → Operation successful
     * - false → Communication failed
     */
    bool wakeFromInterrupt();

    /**
     * setWaitTime
     *
     * - Sets wait time between measurements
     *
     * Parameters:
     * - wtime → raw register value
     *
     * Returns:
     * - true  → Operation successful
     * - false → Communication failed
     */
    bool setWaitTime(uint8_t wtime);

    /**
     * getWaitTime
     *
     * - Reads wait time register
     *
     * Parameters:
     * - wtime → reference to store value
     *
     * Returns:
     * - true  → Read successful
     * - false → Communication failed
     */
    bool getWaitTime(uint8_t &wtime);

    /**
     * setWaitTimeMs
     *
     * - Sets wait time in milliseconds
     *
     * Parameters:
     * - time_ms → wait time in ms
     *
     * Returns:
     * - true  → Operation successful
     * - false → Communication failed
     */
    bool setWaitTimeMs(uint16_t time_ms);

    /**
     * getWaitTimeMs
     *
     * - Converts wait register value to milliseconds
     *
     * Parameters:
     * - wtime → register value
     *
     * Returns:
     * - wait time in milliseconds
     */
    float getWaitTimeMs(uint8_t wtime);

    /**
     * setGPIOMode
     *
     * - Configures GPIO input mode
     *
     * Parameters:
     * - inputEnable → true = input enabled
     *
     * Returns:
     * - true  → Operation successful
     * - false → Communication failed
     */
    bool setGPIOMode(bool inputEnable);

    /**
     * getGPIOInput
     *
     * - Reads GPIO input state
     *
     * Parameters:
     * - state → reference to store input state
     *
     * Returns:
     * - true  → Read successful
     * - false → Communication failed
     */
    bool getGPIOInput(bool &state);

    /**
     * setGPIOInvert
     *
     * - Enables or disables GPIO inversion
     *
     * Parameters:
     * - invert → true = invert output
     *
     * Returns:
     * - true  → Operation successful
     * - false → Communication failed
     */
    bool setGPIOInvert(bool invert);

    /**
     * setFIFOLevelThreshold
     *
     * - Sets FIFO interrupt threshold level
     *
     * Parameters:
     * - th → FIFO threshold level (enum)
     *
     * Returns:
     * - true  → Operation successful
     * - false → Communication failed
     */
    bool setFIFOLevelThreshold(FIFO_Level th);

    /**
     * getFIFOLevelThreshold
     *
     * - Reads FIFO threshold level
     *
     * Parameters:
     * - th → reference to store threshold
     *
     * Returns:
     * - true  → Read successful
     * - false → Communication failed
     */
    bool getFIFOLevelThreshold(uint8_t &th);

    /**
     * setLowAlert
     *
     * - Sets low threshold for spectral interrupt
     *
     * Parameters:
     * - lowTH → 16-bit low threshold value
     *
     * Returns:
     * - true  → Operation successful
     * - false → Communication failed
     */
    bool setLowAlert(uint16_t lowTH);

    /**
     * getLowAlert
     *
     * - Reads low threshold value
     *
     * Parameters:
     * - lowTH → reference to store threshold
     *
     * Returns:
     * - true  → Read successful
     * - false → Communication failed
     */
    bool getLowAlert(uint16_t &lowTH);

    /**
     * setHighAlert
     *
     * - Sets high threshold for spectral interrupt
     *
     * Parameters:
     * - highTH → 16-bit high threshold value
     *
     * Returns:
     * - true  → Operation successful
     * - false → Communication failed
     */
    bool setHighAlert(uint16_t highTH);

    /**
     * getHighAlert
     *
     * - Reads high threshold value
     *
     * Parameters:
     * - highTH → reference to store threshold
     *
     * Returns:
     * - true  → Read successful
     * - false → Communication failed
     */
    bool getHighAlert(uint16_t &highTH);

    /**
     * setAlertChannel
     *
     * - Selects channel used for threshold interrupt
     *
     * Parameters:
     * - ch → alert channel (enum)
     *
     * Returns:
     * - true  → Operation successful
     * - false → Communication failed or invalid channel
     */
    bool setAlertChannel(Alert_Channel ch);

    /**
     * getAlertChannel
     *
     * - Reads current alert channel
     *
     * Parameters:
     * - ch → reference to store channel
     *
     * Returns:
     * - true  → Read successful
     * - false → Communication failed
     */
    bool getAlertChannel(uint8_t &ch);

    /**
     * readStatus
     *
     * - Reads full sensor status including interrupts, errors, and saturation
     *
     * Parameters:
     * - status → reference to structured status data
     *
     * Returns:
     * - true  → Read successful
     * - false → Communication failed
     */
    bool readStatus(AS7343_Status &status);

    /**
     * setLowPowerMode
     *
     * - Enables or disables low power mode
     *
     * Parameters:
     * - enable → true = low power enabled
     *
     * Returns:
     * - true  → Operation successful
     * - false → Communication failed
     */
    bool setLowPowerMode(bool enable);

    /**
     * setWLong
     *
     * - Enables or disables long integration mode
     *
     * Parameters:
     * - enable → true = long integration enabled
     *
     * Returns:
     * - true  → Operation successful
     * - false → Communication failed
     */
    bool setWLong(bool enable);

    /**
     * setSleepAfterInterrupt
     *
     * - Enables sleep after interrupt mode
     *
     * Parameters:
     * - enable → true = enable SAI mode
     *
     * Returns:
     * - true  → Operation successful
     * - false → Communication failed
     */
    bool setSleepAfterInterrupt(bool enable);

    /**
     * setSMUXCommand
     *
     * - Sends SMUX command to sensor
     *
     * Parameters:
     * - cmd → SMUX command (enum)
     *
     * Returns:
     * - true  → Operation successful
     * - false → Communication failed
     */
    bool setSMUXCommand(AS7343_SMUX_Command cmd);

    /**
     * enableInterrupt
     *
     * - Enables flicker and SMUX interrupts
     *
     * Parameters:
     * - flickerDetect → flicker interrupt enable
     * - smuxDone → SMUX done interrupt enable
     *
     * Returns:
     * - true  → Operation successful
     * - false → Communication failed
     */
    bool enableInterrupt(bool flickerDetect, bool smuxDone);

    /**
     * setAutoSMUX
     *
     * - Configures automatic SMUX mode
     *
     * Parameters:
     * - mode → SMUX mode (enum)
     *
     * Returns:
     * - true  → Operation successful
     * - false → Communication failed or invalid mode
     */
    bool setAutoSMUX(AS7343_Auto_SMUX mode);

    /**
     * getAutoSMUX
     *
     * - Reads automatic SMUX mode
     *
     * Parameters:
     * - mode → reference to store mode
     *
     * Returns:
     * - true  → Read successful
     * - false → Communication failed
     */
    bool getAutoSMUX(uint8_t &mode);

    /**
     * setFlickerFIFOMode
     *
     * - Enables or disables flicker FIFO mode
     *
     * Parameters:
     * - enable → enable/disable mode
     *
     * Returns:
     * - true  → Operation successful
     * - false → Communication failed
     */
    bool setFlickerFIFOMode(AS7343_Fifo_8_Bit_Flicker_Mode enable);

    /**
     * getFlickerFIFOMode
     *
     * - Reads flicker FIFO mode state
     *
     * Parameters:
     * - enable → reference to store state
     *
     * Returns:
     * - true  → Read successful
     * - false → Communication failed
     */
    bool getFlickerFIFOMode(bool &enable);

    /**
     * setInterruptPersistence
     *
     * - Sets interrupt persistence filter
     *
     * Parameters:
     * - pers → persistence setting (enum)
     *
     * Returns:
     * - true  → Operation successful
     * - false → Communication failed
     */
    bool setInterruptPersistence(AS7343_Persistence pers);

    /**
     * getInterruptPersistence
     *
     * - Reads interrupt persistence setting
     *
     * Parameters:
     * - pers → reference to store value
     *
     * Returns:
     * - true  → Read successful
     * - false → Communication failed
     */
    bool getInterruptPersistence(uint8_t &pers);

    /**
     * setFIFOMap
     *
     * - Configures FIFO data mapping
     *
     * Parameters:
     * - mapMask → channel mask (7-bit)
     *
     * Returns:
     * - true  → Operation successful
     * - false → Communication failed
     */
    bool setFIFOMap(uint8_t mapMask);

    /**
     * getFIFOMap
     *
     * - Reads FIFO mapping configuration
     *
     * Parameters:
     * - mapMask → reference to store mask
     *
     * Returns:
     * - true  → Read successful
     * - false → Communication failed
     */
    bool getFIFOMap(uint8_t &mapMask);

    /**
     * setFifoFlicker
     *
     * - Enables flicker data in FIFO
     *
     * Parameters:
     * - EnableFifoFlicker → enable/disable
     *
     * Returns:
     * - true  → Operation successful
     * - false → Communication failed
     */
    bool setFifoFlicker(bool EnableFifoFlicker);

    /**
     * getFifoFlicker
     *
     * - Reads FIFO flicker mode state
     *
     * Parameters:
     * - EnableFifoFlicker → reference to store state
     *
     * Returns:
     * - true  → Read successful
     * - false → Communication failed
     */
    bool getFifoFlicker(bool &EnableFifoFlicker);

    /**
     * getFifoLevel
     *
     * - Reads current FIFO level
     *
     * Parameters:
     * - fifoLevel → reference to store level
     *
     * Returns:
     * - true  → Read successful
     * - false → Communication failed
     */
    bool getFifoLevel(uint8_t &fifoLevel);

    /**
     * readFifo
     *
     * - Reads data from FIFO buffer
     *
     * Parameters:
     * - fifoData → buffer to store data
     * - len → number of bytes to read
     *
     * Returns:
     * - true  → Read successful
     * - false → Communication failed
     */
    bool readFifo(uint8_t *fifoData, uint8_t len);

    /**
     * setFlickerEnable
     *
     * - Enables or disables flicker detection engine
     *
     * Parameters:
     * - enable → true = enable flicker detection
     *
     * Returns:
     * - true  → Operation successful
     * - false → Communication failed
     */
    bool setFlickerEnable(bool enable);

    /**
     * readFlickerFrequency
     *
     * - Reads detected flicker frequency
     *
     * Parameters:
     * - freq → detected frequency (0, 100, 120 Hz)
     *
     * Returns:
     * - true  → Read successful
     * - false → Communication failed
     */
    bool readFlickerFrequency(uint16_t &freq);

    /**
     * isFlickerValid
     *
     * - Checks if flicker data is valid
     *
     * Parameters:
     * - valid → true if valid flicker data available
     *
     * Returns:
     * - true  → Read successful
     * - false → Communication failed
     */
    bool isFlickerValid(bool &valid);

    /**
     * getFlickerInfo
     *
     * - Returns full flicker detection result
     *
     * Parameters:
     * - detected → true if flicker detected
     * - freq → detected frequency (100 / 120 Hz)
     *
     * Returns:
     * - true  → Read successful
     * - false → Communication failed
     */
    bool getFlickerInfo(bool &detected, uint16_t &freq);

    /**
     * getRGB
     *
     * - Converts spectral data to approximate RGB values
     * - Uses weighted channel mapping
     *
     * Parameters:
     * - r → reference to store red value
     * - g → reference to store green value
     * - b → reference to store blue value
     *
     * Returns:
     * - true  → Conversion successful
     * - false → Read failed
     */
    bool getRGB(uint16_t &r, uint16_t &g, uint16_t &b);

private:

    I2C_Interface i2c;
    BusIO_7Semi<I2C_Interface> *bus;

    bool setRegisterBank(bool bank1);

    bool getRegisterBank(bool &bank1);

    bool getBit(uint8_t reg, uint8_t position, bool &value);

    AS7343_Status status;
};

#endif
