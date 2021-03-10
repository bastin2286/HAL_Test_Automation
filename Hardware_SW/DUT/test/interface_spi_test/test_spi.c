#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "/home/pi/HAL_Testing/interface_application/spi.h"

#include <sys/ioctl.h>
#include <stdlib.h>


#define SPI_CMD_1	'1'
#define SPI_CMD_2	'2'
#define SPI_CMD_3	'3'
#define SPI_CMD_4	'4'
#define SPI_CMD_5	'5'




int main(int argc, char *argv[])
{
	int chip_select;
	int length ;
	char command;
	int ret;
		
	int command_response;
	chip_select = atoi(argv[2]);
	command = *argv[1];
	length = atoi(argv[3]);

	
	//printf("command : %c", command);


	ret=spi_init();
	if(ret < 0)
	{
		printf("failed to open spi drive: \n");
		return 0;
	}


	if((command <= 1) && (command >= 5))
	{
		printf("Invalid command\n");
		return 0;
	}
	
	if(length != 1)
	{
		printf("Invalid command length\n");
		return 0;
	}
	
	if(chip_select != 0)
	{
		printf("failed to select proper slave\n:");
		return 0;
	}
	

	ret=spi_init();
	if(ret < 0)
	{
		printf("failed to open spi drive: \n");
		return 0;
	}

	
	//command_response = sendCommand(SPI_CMD_1, 1, 1);
	

	if (command == '1')
	{
		command_response = sendCommand(SPI_CMD_1, 1, 1);
		
		printf("%d\n", command_response);
	}
	else if(command == '2')
	{
		command_response = sendCommand(SPI_CMD_2, 1, 1);
		printf("%d\n", command_response);

	}
	else if(command == '3')
	{
		command_response = sendCommand(SPI_CMD_3, 1, 1);
		printf("%d\n", command_response);

	}
	else if(command == '4')
	{
		command_response = sendCommand(SPI_CMD_4, 1, 1);
		printf("%d\n", command_response);

	}
	else if(command == '5')
	{
		command_response = sendCommand(SPI_CMD_5, 1, 1);
		printf("%d\n", command_response);

	}



	
	
	
	
	
	if(command == '1')
	{
		if(command_response == 10)
		{
			printf("Pass\n");
		}
		else
		{
			printf("SPI read test failed\n");
		}
	}
	else if(command == '2')
	{
		if(command_response == 20)
		{
			printf("Pass\n");
		}
		else
		{
			printf("SPI read test failed\n");
		}
	}
	else if(command == '3')
	{
		if(command_response == 30)
		{
			printf("Pass\n");
		}
		else
		{
			printf("SPI read test failed\n");
		}
	}
	else if(command == '4')
	{
		if(command_response == 40)
		{
			printf("Pass\n");
		}
		else
		{
			printf("SPI read test failed\n");
		}
	}
	else if(command == '5')
	{
		if(command_response == 50)
		{
			printf("Pass\n");
		}
		else
		{
			printf("SPI read test failed\n");
		}
	}

	else
	{
		printf("Invalid input\n");
	}

	return 0;
}
