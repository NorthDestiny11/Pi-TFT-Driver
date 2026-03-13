// This file acts as the main driver/library

#include <iostream> // IO operations
#include <chrono>   // Time Utilities
#include <thread>   // For Pausing/Sleeping Purposes

#include <fcntl.h>    // For open()
#include <sys/mman.h> // For mmap()
#include <unistd.h>   // For close()

//
// NOTE TO SELF: Query about missing operations and library!
//

// The following code was copied from https://www.codeembedded.com/blog/raspberry_pi_gpio/

void setup_gpio()
{
  int mem_fd;
  void *gpio_map;

  // /dev/mem represents the location of the Pi's physical memory
  if ((mem_fd = open("/dev/mem", O_RDWR | O_SYNC)) < 0)
  {
    std::cout << "Failed to open /dev/mem. Please run the file as root" << std::cout;
    exit(EXIT_FAILURE);
  }

  // Map GPIO memory to address space
  gpio_map = mmap(
      NULL,
      BLOCK_SIZE,
      PROT_READ | PROT_WRITE,
      MAP_SHARED,
      mem_fd,
      GPIO_BASE);

  close(mem_fd);

  if (gpio_map == MAP_FAILED)
  {
    std::cout << "An unidentified mmap error has occured." << std::cout;
    exit(EXIT_FAILURE);
  }

  // Use a volatile pointer to stop compiler optimisation interference
  gpio = (volatile unsigned int *)gpio_map;
}

int main(int argc, char *argv[])
{
  std::cout << "Hello, World!" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  std::cout << "Slept for 500 ms!" << std::endl;

  return 0;
}