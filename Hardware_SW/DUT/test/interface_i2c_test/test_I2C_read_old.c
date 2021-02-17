#include <stdio.h>
#include "I2C.h"
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include "I2C.h"

#if 1
#define SLAVE_ADDR 			0x08		/*SLAVE Address of the I2C*/
#define CMD_1				0x01	
#define CMD_2				0x02	
#define CMD_3				0x03	
#endif

int main()
{
	char slave_addr ;
	int length ;
	char command[10];
	#if 0
		slave_addr =  *argv[1];
		command[0] =  *argv[2];
		length =  *argv[3];
	#else
		
		slave_addr =  SLAVE_ADDR;
		command[0] =  CMD_1;
		length =  1;
	#endif
//	slave_addr = 8;
//	length = 1;
//	command[0]= 
	
	char command_response[length];
	
	I2C_write(slave_addr,command, length);

	I2C_read(slave_addr,command_response,length);
	
	//printf("length = %c",*argv[3]);

	if(command[0] == 0x01)
	{
		if(command_response[0] == 11)
		{
			printf("I2C read test successful!!\n");
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
			printf("I2C read test successful!!\n");
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
			printf("I2C read test successful!!\n");
		}
		else
		{
			printf("I2C read test failed\n");
		}
	}
	else
	{
		printf("Invalid input\n");
	}

		
}