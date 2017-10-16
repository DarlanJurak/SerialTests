/*
*	@author:		Darlan Alves Jurak
*	@created:		16 oct 2017
*	@brief:			Tests with serial.
*/

#include <iostream>
#include <typeinfo>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <string.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    
    int fd = open("/dev/ttyAMC2", O_RDWR);
	if (fd == -1) {
	  perror("/dev/ttyAMC2");
	  return 1;
	}

	// int fd = open(argv[1], O_RDWR);
	// if (fd == -1) {
	//   perror("%s", argv[1]);
	//   return 1;
	// }

	struct termios tios;
	tcgetattr(fd, &tios);
	// disable flow control and all that, and ignore break and parity errors
	tios.c_iflag = IGNBRK | IGNPAR;
	tios.c_oflag = 0;
	tios.c_lflag = 0;
	cfsetspeed(&tios, B9600);
	tcsetattr(fd, TCSAFLUSH, &tios);

	// the serial port has a brief glitch once we turn it on which generates a
	// start bit; sleep for 1ms to let it settle
	usleep(1000);    

	// output to serial port
	char msg[] = "3";
	write(fd, msg, strlen(msg));

}