#include "I2C.h"
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include <unistd.h>



int I2C_read(char address, char *command_data, int len)
{
    int fd;
	char buffer[64];
	char i; 
	
	if ((fd = open("/dev/i2c-1", O_RDWR)) < 0)
	{
		/*ERROR HANDLING; you can check errno to see what went wrong*/
		printf("Failed to open the i2c bus");
		return(-1); 
	}
	/*Acquire bus access and/or talk to slave*/
	if (ioctl(fd, I2C_SLAVE,address) < 0)
	{
		/*ERROR HANDLING; you can check errno to see what went wrong*/
		printf("Failed to acquire bus access and/or talk to slave.\n");
		return(-1);
	}
	/*read() returns the number of bytes actually read, if it doesn't match 
	then an error occurred (e.g. no response from the device)*/
	if (read(fd, buffer, len) != len)		
	{
		//ERROR HANDLING: i2c transaction failed
		printf("Failed to read from the i2c bus.\n");
		return(-1); 
	}
	else
	{
	for(i = 0; i<= len; i++)
	{
		*command_data = buffer[i];
		command_data++;
	}
		//printf("\nData read: ");
		for(i = 0; i<len; i++)
		{
			//printf("%d\t", buffer[i]);
		}		
	}	
    int close(int fd); 
    return 0; 
}


int I2C_write(char address, char *command_data, int len)
{
    int fd; 
	char buffer[64];
	char i;
	
	//printf ("len %c\n",len);
	for(i = 0; i<= len; i++)
	{
		buffer[i] = *command_data;
		
		command_data++;
	}
	
	if ((fd = open("/dev/i2c-1", O_RDWR)) < 0)
	{
		/*ERROR HANDLING; you can check errno to see what went wrong*/
		printf("Failed to open the i2c bus");
		int close(int fd); 
		return(-1); 
	}
	/*Acquire bus access and/or talk to slave*/
	if (ioctl(fd, I2C_SLAVE,address) < 0)
	{
		/*ERROR HANDLING; you can check errno to see what went wrong*/
		printf("Failed to acquire bus access and/or talk to slave.\n");
		int close(int fd); 
		return(-1);
	}
	/*read() returns the number of bytes actually read, if it doesn't match 
	then an error occurred (e.g. no response from the device)*/

	if (write(fd, buffer, len) != len)
	
	{
		//ERROR HANDLING: i2c transaction failed
		printf("Failed to write from the i2c bus.\n");
		int close(int fd); 
		return(-1); 
	}
	else
	{
		//printf("\nData written to the Slave");		
	}	
    int close(int fd); 
    return 0; 
}
