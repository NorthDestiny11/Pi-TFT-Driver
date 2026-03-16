// This file acts as the main driver/library

/*
  SDA: GPIO 3
  SDI: MOSI: 19
  SDO: MISO: 21
  SCLK: 23

  SPI_CE0: 24   TFT Chip Select
  SPI_CE1: 26   Touch Controller Chip Select

    ILI:
  GPIO 25:
  GPIO 24:
  GPIO 23: Switch 1: 16
  GPIO 22: Switch 2: 15
  GPIO 21: Switch 3: 13
  GPIO 18: Switch 4: 12
  GPIO 4:
*/

#include <iostream> // IO operations
#include <chrono>   // Time Utilities
#include <thread>   // For Pausing/Sleeping Purposes

#include <linux/spi/spidev.h>
#include <gpiod.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define CHIP_NAME "gpiochip0"

#define SWITCH_1 16
#define SWITCH_2 15
#define SWITCH_3 13
#define SWITCH_4 12

int main(int argc, char *argv[])
{
  return 0;
}