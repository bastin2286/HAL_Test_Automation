#include "spi.h"

#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

extern int fd;

int spi_init()
{

	if((fd = open("/dev/spidev0.0", O_RDWR))< 0)
	{
	
		printf("Failed to open SPI driver: \n");
		exit(0);
	}

   unsigned int speed = 1000000;
  if((ioctl (fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed)) <0)
  {
	printf("Failed to open SPI driver: \n");
	exit(0);
  }

	
}

int spiTxRx(unsigned char txDat)
{
 
  unsigned char rxDat=0;

  struct spi_ioc_transfer spi;

  memset (&spi, 0, sizeof (spi));

  spi.tx_buf        = (unsigned long)&txDat;
  spi.rx_buf        = (unsigned long)&rxDat;
  spi.len           = 1;
  


  if((ioctl (fd, SPI_IOC_MESSAGE(1), &spi) < 0))
  {
  	
	printf("Failed to open SPI driver\n");
	exit (0);
  }

	

  
  if( rxDat< 0)
  {
  	printf("failed SPI comminication\n");
	//return (-1);
	exit (0);
  }
	
  return rxDat;
}

int sendCommand(char command, int j, int k)
{

	unsigned char resultByte;
	typedef enum {false, true} bool;
	
	bool ack;

	/**********************************************************
	Unions allow variables to occupy the same memory space
	a convenient way to move back and forth between 8-bit and
	16-bit values etc.

	Here three unions are declared: two for parameters to be 
	passed in commands to the Arduino and one to receive
		the results
	***********************************************************/

	union p1Buffer_T       
	{
		int p1Int;
		unsigned char  p1Char [2];
	} 	p1Buffer;

	union p2Buffer_T      
	{
		int p2Int;
		unsigned char  p2Char [2];
	} p2Buffer;

	union resultBuffer_T     
	{
		int resultInt;
		unsigned char  resultChar [2];
	} resultBuffer;


	p1Buffer.p1Int = j;
	p2Buffer.p2Int = k;
	resultBuffer.resultInt = 0;

	/**********************************************************
	An initial handshake sequence sends a one byte start code
	('c') and loops endlessly until it receives the one byte 
	acknowledgment code ('a') and sets the ack flag to true.
	(Note that the loop also sends the command byte while 
	still in handshake sequence to avoid wasting a transmit
	cycle.)
	***********************************************************/

	do
	{
		ack = false;

		spiTxRx('c');
		usleep (10);


		resultByte = spiTxRx(command);
		if (resultByte < 0)
		{	
			printf("failed to establish communication\n");

			return (-1);
		}
		if (resultByte == 'a')
		{
			ack = true;
		}
		usleep (10);  

   }
	while (ack == false);

	/**********************************************************
	Send the parameters one byte at a time.
	***********************************************************/

	spiTxRx(p1Buffer.p1Char[0]);
	usleep (10);


	spiTxRx(p1Buffer.p1Char[1]);
	usleep (10);


	spiTxRx(p2Buffer.p2Char[0]);
	usleep (10);


	spiTxRx(p2Buffer.p2Char[1]);
	usleep (10);

	/**********************************************************
	Push two more zeros through so the Arduino can return the
	results
	***********************************************************/


	resultByte = spiTxRx(0);
	resultBuffer.resultChar[0] = resultByte;
	usleep (10);


	resultByte = spiTxRx(0);
	resultBuffer.resultChar[1] = resultByte;
	return resultBuffer.resultInt;

}