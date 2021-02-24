#include <Wire.h>
#define SLAVE_ADDRESS 8



/******************************************************/
unsigned char receiveBuffer[5];
unsigned char dat;
byte marker = 0;
/****************************************************/
union       
  {
  int p1Int;
  unsigned char  p1Char [2];
  } p1Buffer;

union       
  {
  int p2Int;
  unsigned char p2Char [2];
  } p2Buffer;


union       
  {
  int resultInt;
  unsigned char  resultChar [2];
  } resultBuffer;
  
/****************************************************/






byte command= 0;
byte response= 0;
void setup() 
{
  Wire.begin(SLAVE_ADDRESS);
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
  
/**************************************************/
pinMode(MISO, OUTPUT);
  SPCR |= _BV(SPE);
/*************************************************/
}


void loop() { 
/**********************************************/
  if((SPSR & (1 << SPIF)) != 0)
  {
    spiHandler();
  }
/**********************************************/ 
 
 
}



void receiveData(int bytecount)
{
  for (int i = 0; i < bytecount; i++)
  {
    command = Wire.read();
  }
}

void sendData()
{
  switch (command)
  {
    case 0x01:
      response = 11;
      break;
     case 0x02:
        response = 22;
        break;
      case 0x03:
        response = 33;
        break;
        case 0x04:
        response = 44;
        break;
        case 0x05:
        response = 55;
        break;
      default:
        response = 0xff;
        break;
  }
  Wire.write(response);
  
  
}

/***************************************************/
void spiHandler()
{
  switch (marker)
  {
  case 0:
    dat = SPDR;
    if (dat == 'c')
    {
      SPDR = 'a';
      marker++;
    } 
    break;    
  case 1:
    receiveBuffer[marker-1] = SPDR;
    marker++;
    break;
  case 2:
    receiveBuffer[marker-1] = SPDR;
    marker++;
    break;
  case 3:
    receiveBuffer[marker-1] = SPDR;
    marker++;
    break;
  case 4:
    receiveBuffer[marker-1] = SPDR;
    marker++;
    break;
  case 5:
    receiveBuffer[marker-1] = SPDR;
    marker++;
    executeCommand();
    SPDR = resultBuffer.resultChar[0];    
    break;    
  case 6:
    marker++;
    SPDR = resultBuffer.resultChar[1]; 
    break;   
  case 7:
    dat = SPDR;
    marker=0;
  }

}

/***************************************************************  
 executeCommand
   When the complete 5 byte command sequence has been received
   reconstitute the byte variables from the receiveBuffer
   into integers, parse the command (add or subtract) and perform
   the indicated operation - the result will be in resultBuffer
****************************************************************/

  
void executeCommand(void)
{

 p1Buffer.p1Char[0]=receiveBuffer[1];
 p1Buffer.p1Char[1]=receiveBuffer[2];
 p2Buffer.p2Char[0]=receiveBuffer[3];
 p2Buffer.p2Char[1]=receiveBuffer[4];
 
 if(receiveBuffer[0] == '1')
 {
   //resultBuffer.resultInt = p1Buffer.p1Int + p2Buffer.p2Int;
   resultBuffer.resultInt = 10;
 }
 else if (receiveBuffer[0] == '2')
 {
  //resultBuffer.resultInt = p1Buffer.p1Int - p2Buffer.p2Int;
  resultBuffer.resultInt = 20;
 }
 else if (receiveBuffer[0] == '3')
 {
  //resultBuffer.resultInt = p1Buffer.p1Int - p2Buffer.p2Int;
  resultBuffer.resultInt = 30;
 }
 else if (receiveBuffer[0] == '4')
 {
  //resultBuffer.resultInt = p1Buffer.p1Int - p2Buffer.p2Int;
  resultBuffer.resultInt = 40;
 }
 else if (receiveBuffer[0] == '5')
 {
  //resultBuffer.resultInt = p1Buffer.p1Int - p2Buffer.p2Int;
  resultBuffer.resultInt = 50;
 }

} 
/*****************************************************************************/
