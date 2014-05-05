/* Hi Speed Logger Project - MTK33x9 chipset
* Author: Arvind Govindaraj (arvind.govindaraj@gmail.com)
* GPS_Conf.cpp
* Rev History
* V0.1 - 04/13/2013
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <wiringSerial.h>


int main(int argc, char **argv)
{
	int serFd,datachar,i;
	serFd = serialOpen("/dev/ttyUSB0",115200);
	serialFlush(serFd);
	usleep(1*1000*1000);//sleep for 1s 
	serialPrintf(serFd,"010C\n"); 
	usleep(100*1000);//sleep for 100ms
	datachar = serialDataAvail(serFd);
	printf("%d \n",datachar);
	for(i=0,i<datachar,i++)
	{
		printf("%c\n",serialGetchar(serFd));	
	};
	serialClose(serFd);
	

	
    return 0;
}