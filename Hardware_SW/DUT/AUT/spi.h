#ifndef SPI_C
#define SPI_C


int fd;


int spi_init();
int spiTxRx(unsigned char txDat);
int sendCommand(char command, int j, int k);

#endif