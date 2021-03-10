#include <stdio.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include "/home/pi/HAL_Testing/interface_application/I2C.h"


int main(int argc, char *argv[])
{
	char slave_addr ;
	int length ;
	char command[10];
	slave_addr = atoi(argv[1]);
	command[0] = atoi(argv[2]);
	length = atoi(argv[3]);
//	slave_addr = 8;
//	length = 1;
//	command[0]= 
	
	
	char command_response[length];

	if((slave_addr != 8) || ((command[0]<1)||(command[0]>5)) || (length != 1 ))
	{
		printf("Invalid Input\n");
		return 0;
	}
	
	I2C_write(slave_addr,&command[0], length);

	I2C_read(slave_addr,&command_response[0],length);
	
	
	if(command[0] == 0x01)
	{
		if(command_response[0] == 11)
		{
			printf("Pass\n");
		}
		else
		{
			printf("I2C read test failed\n");
		}
	}
	else if(command[0] == 0x02)
	{
		if(command_response[0] == 22)
		{
			printf("Pass\n");
		}
		else
		{
			printf("I2C read test failed\n");
		}
	}
	else if(command[0] == 0x03)
	{
		if(command_response[0] == 33)
		{
			printf("Pass\n");		}
		else
		{
			printf("I2C read test failed\n");
		}
	}
	else if(command[0] == 0x04)
	{
		if(command_response[0] == 44)
		{
			printf("Pass\n");		}
		else
		{
			printf("I2C read test failed\n");
		}
	}
	else if(command[0] == 0x05)
	{
		if(command_response[0] == 55)
		{
			printf("Pass\n");		}
		else
		{
			printf("I2C read test failed\n");
		}
	}

	else
	{
		printf("Invalid input\n");
	}

	return 0;
}
