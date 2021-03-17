#ifndef I2C_H
#define I2C_H

int I2C_read(char address, char *command_data, int len);
int I2C_write(char address, char *command_data, int len);


#endif


