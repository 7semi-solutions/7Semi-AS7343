/**
 * 7Semi AS7343 Web Plotter Example
 *
 * Library:
 * - Name    : 7Semi_AS7343
 * - Platform: Arduino / Embedded (I2C)
 *
 * Description:
 * - Initializes AS7343 spectral sensor
 * - Reads multi-channel spectral data (F1–F8, VIS, NIR)
 * - Streams data in CSV format for real-time plotting
 * - Compatible with Serial Plotter and Web-based plot tools
 *
 * Web Plotter:
 * - Live Visualization Tool:
 *   https://7semi.com/7semivlab/7semi-as7343-web-serial-plotter.html
 *
 * Connections:
 * -----------------------------
 * AS7343    →   MCU
 * -----------------------------
 * VCC       →   3.3V / 5V
 * GND       →   GND
 * SDA       →   SDA (Wire)
 * SCL       →   SCL (Wire)
 * INT       →   Optional (Interrupt pin)
 *
 * Notes:
 * - Default I2C Address: 0x39
 * - Requires pull-up resistors on SDA/SCL (4.7kΩ–10kΩ)
 * - Use stable lighting for accurate spectral readings
 * - Data output format: CSV (comma-separated values)
 *
 * Output Channels:
 * - F1, F2, FZ, F3, F4, F5, FY, FXL, F6, F7, F8, VIS, NIR
 */
#include <7Semi_AS7343.h>

AS7343_7Semi sensor;

void setup()
{
    Serial.begin(115200);
    delay(100);

    if (!sensor.begin())
    {
        Serial.println("Init Failed");
        while (1);
    }

    sensor.setAutoSMUX(AS7343_Auto_SMUX::AUTO_18CH);
    sensor.setGain(Gain::GAIN_512X);
    sensor.setIntegrationTime(100, 999);
    sensor.setSMUXCommand(AS7343_SMUX_Command::SMUX_INIT);

    sensor.setLED(false);

    // Header for plotter
    Serial.println("F1,F2,FZ,F3,F4,F5,FY,FXL,F6,F7,F8,VIS,NIR");
}

void loop()
{
    AS7343_SpectralData data;

    if (sensor.readSpectralData(data))
    {
        Serial.print(data.VIOLET_405); Serial.print(','); // F1
        Serial.print(data.BLUE_425);  Serial.print(','); // F2
        Serial.print(data.BLUE_450);  Serial.print(','); // FZ
        Serial.print(data.BLUE_475);  Serial.print(','); // F3
        Serial.print(data.GREEN_515);  Serial.print(','); // F4
        Serial.print(data.GREEN_550); Serial.print(','); // F5
        Serial.print(data.GREN_555);  Serial.print(','); // FY
        Serial.print(data.YELLOW_600);  Serial.print(','); // FXL
        Serial.print(data.RED_640);  Serial.print(','); // F6
        Serial.print(data.RED_690); Serial.print(','); // F7
        Serial.print(data.RED_745); Serial.print(','); // F8
        Serial.print(data.BRITNESS_1);  Serial.print(','); // VIS
        Serial.println(data.NIR_855);                  // NIR
    }
    delay(200);
}