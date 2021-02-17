#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include "I2C.h"
#include "spi.h"


#define LENGTH_TIME_VAR		64
#define FILENAME			"/home/pi/HAL_Testing/interface_application/test.txt"
#define NEW_LINE			"\n"
#define SLAVE_ADDR 			0x08		/*SLAVE Address of the I2C*/
#define CMD_1				0x01	
#define CMD_2				0x02	
#define CMD_3				0x03	
#define CMD_4				0x04
#define CMD_5				0x05
#define SPI_CMD_1			'1'
#define SPI_CMD_2			'2'
#define SPI_CMD_3			'3'
#define SPI_CMD_4			'4'
#define SPI_CMD_5			'5'

char TimeString[LENGTH_TIME_VAR];
FILE *fp;
char Fill_Buffer[512];

char CreateOpenFile(void);
char GetCurrTime(void);

extern int fd;

char GetCurrTime(void)
{
	static int seconds_last = 99;
	struct timeval curTime;
	gettimeofday(&curTime, NULL);
	if (seconds_last == curTime.tv_sec)
	{
		return -1;
	}
	
	seconds_last = curTime.tv_sec;	
	strftime(TimeString, sizeof(TimeString), "|%d-%m-%Y::%H:%M:%S|", localtime(&curTime.tv_sec));
	
	return 0;
}

char CreateOpenFile(void)
{
	fp = fopen(FILENAME, "a+");
	if(fp == NULL)
	{
		fclose(fp);
		return -1;
	}
	return 0;
}

char WriteIntoFile(void)
{
	if(fp == NULL)
	{
		fclose(fp);
		return -1;
	}
	fputs(TimeString,fp);
	fputs(Fill_Buffer,fp);
	fputs(NEW_LINE,fp);
	return 0;
}

int main()
{
	char command[64] = {0};
	char response[64] = {0};
	int ret;
	char spi_cmd ;
	int spi_response;
	int ret;
	
	ret=spi_init();
	if(ret < 0)
	{
		printf("failed to open spi drive: \n");
		return 0;
	}

	
	if(GetCurrTime() >= 0)
	{
		printf("The Date & time is : ");
		printf(TimeString);
		printf("\n");
	}
	else
	{
		printf("Error in getting Time!!!!\n");
	}
	
	printf("creating file\n");
	if(CreateOpenFile() >= 0)
	{
		printf("File created : %s\n", FILENAME);
	}
	else
	{
		printf("Error in creating/opening File!!!!\n");
	}
	
	printf("after creating file\n");
	command[0] = CMD_1;
	printf("\nThe command is : %x\n",command[0]);
	I2C_write(SLAVE_ADDR,&command[0], 1);
	I2C_read(SLAVE_ADDR,&response[0], 1);
	if(response[0] == 11)
	{
		snprintf(Fill_Buffer, sizeof(Fill_Buffer), "The  I2C communication replied with '%c' as expected for the command0", response[0]); 
	}
	else
	{
		snprintf(Fill_Buffer, sizeof(Fill_Buffer), "The  I2C communication replied with '%c' as not expected for the command0", response[0]); 
	}
	
	if(WriteIntoFile() >= 0)
	{
		printf("\n In file : %s written the timings\n", FILENAME);
	}
	else
	{
		printf("\n File : %s is not exist/not opened\n", FILENAME);
	}
	
	command[0] = CMD_2;
	printf("\nThe command is : %x\n",command[0]);
	I2C_write(SLAVE_ADDR,&command[0], 1);
	I2C_read(SLAVE_ADDR,&response[0], 1);
	if(response[0] == 22)
	{
		snprintf(Fill_Buffer, sizeof(Fill_Buffer), "The  I2C communication replied with '%c' as expected for the command1", response[0]); 
	}
	else
	{
		snprintf(Fill_Buffer, sizeof(Fill_Buffer), "The  I2C communication replied with '%c' as not expected for the command1", response[0]); 
	}	
	if(WriteIntoFile() >= 0)
	{
		printf("\n In file : %s written the timings\n", FILENAME);
	}
	else
	{
		printf("File : %s is not exist/not opened\n", FILENAME);
	}
	
	command[0] = CMD_3;
	printf("\nThe command is : %x\n",command[0]);
	I2C_write(SLAVE_ADDR,&command[0], 1);
	I2C_read(SLAVE_ADDR,&response[0], 1);
	if(response[0] == 33)
	{
		snprintf(Fill_Buffer, sizeof(Fill_Buffer), "The  I2C communication replied with '%c' as expected for the command2", response[0]); 
	}
	else
	{
		snprintf(Fill_Buffer, sizeof(Fill_Buffer), "The  I2C communication replied with '%c' as not expected for the command2", response[0]); 
	}
	
	if(WriteIntoFile() >= 0)
	{
		printf("\n In file : %s written the timings\n", FILENAME);
	}
	else
	{
		printf("File : %s is not exist/not opened\n", FILENAME);
	}
	command[0] = CMD_4;
	printf("\nThe command is : %x\n",command[0]);
	I2C_write(SLAVE_ADDR,&command[0], 1);
	I2C_read(SLAVE_ADDR,&response[0], 1);
	if(response[0] == 44)
	{
		snprintf(Fill_Buffer, sizeof(Fill_Buffer), "The  I2C communication replied with '%c' as expected for the command2", response[0]); 
	}
	else
	{
		snprintf(Fill_Buffer, sizeof(Fill_Buffer), "The  I2C communication replied with '%c' as not expected for the command2", response[0]); 
	}
	
	if(WriteIntoFile() >= 0)
	{
		printf("\n In file : %s written the timings\n", FILENAME);
	}
	else
	{
		printf("File : %s is not exist/not opened\n", FILENAME);
	}
	command[0] = CMD_5;
	printf("\nThe command is : %x\n",command[0]);
	I2C_write(SLAVE_ADDR,&command[0], 1);
	I2C_read(SLAVE_ADDR,&response[0], 1);
	if(response[0] == 55)
	{
		snprintf(Fill_Buffer, sizeof(Fill_Buffer), "The  I2C communication replied with '%c' as expected for the command0", response[0]); 
	}
	else
	{
		snprintf(Fill_Buffer, sizeof(Fill_Buffer), "The  I2C communication replied with '%c' as not expected for the command0", response[0]); 
	}
	
	if(WriteIntoFile() >= 0)
	{
		printf("\n In file : %s written the timings\n", FILENAME);
	}
	else
	{
		printf("\n File : %s is not exist/not opened\n", FILENAME);
	}
	
	spi_cmd = SPI_CMD_1;
	spi_response = sendCommand(SPI_CMD_1, 1, 1);
	if(spi_response <0)
	{
		printf("failed to send command\n");
		return (-1);
	}

	printf("The command to SPI device is %c\n",spi_cmd);
	printf("The response from SPI device is %d\n",spi_response);
	
	spi_cmd = SPI_CMD_2;
	spi_response = sendCommand(SPI_CMD_2, 1, 1);
	printf("The command to SPI device is %c\n",spi_cmd);
	printf("The response from SPI device is %d\n",spi_response);
	
	spi_cmd = SPI_CMD_3;
	spi_response = sendCommand(SPI_CMD_3, 1, 1);
	printf("The command to SPI device is %c\n",spi_cmd);
	printf("The response from SPI device is %d\n",spi_response);

	spi_cmd = SPI_CMD_4;
	spi_response = sendCommand(SPI_CMD_4, 1, 1);
	printf("The command to SPI device is %c\n",spi_cmd);
	printf("The response from SPI device is %d\n",spi_response);
	
	spi_cmd = SPI_CMD_5;
	spi_response = sendCommand(SPI_CMD_5, 1, 1);
	printf("The command to SPI device is %c\n",spi_cmd);
	printf("The response from SPI device is %d\n",spi_response);




	
	

	fclose(fp);
}