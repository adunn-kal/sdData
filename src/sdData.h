/**
 * @file sdData.h
 * @author Alexander Dunn
 * @version 0.1
 * @date 2022-12-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Arduino.h>
#include "SD.h"
#include <utility>

class SD_Data
{
    protected:
        // Protected data
        gpio_num_t CS;

    public:
        // Public data

        SD_Data(gpio_num_t pin); ///< A constructor for the SD_Data class

        void writeHeader(void); ///< A method to check and format header files

        /// A method to open a new file
        File createFile(bool hasFix, uint32_t wakeCounter, String time);

        /// A method to write a log message
        void writeLog(String message, uint8_t month, uint8_t day,
                      uint8_t year, String time, uint32_t wakeCounter,
                      bool hasFix, float latitude, float longitude, float altitude);

        /// A method to write data to the sd card
        void writeData(File &data_file, int32_t distance, String unixTime, float temperature, float humidity, bool hasFix);

        void sleep(File &dataFile); ///< A method to close the current file and put the device to sleep
};