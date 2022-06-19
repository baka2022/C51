#ifndef __DS1302_H__
#define __DS1302_H__


void DS1302_init(void);
unsigned char DS1302_readbyte(unsigned char command);
void DS1302_writebyte(unsigned char command,Data);

#endif