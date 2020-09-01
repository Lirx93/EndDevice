#include <stdio.h>
#include <iv.h>
#include <stdlib.h>
#include <math.h>

extern int Bus422Write(unsigned int msgNo, void* pBuf, unsigned int buffSize);
extern int Bus422Read(unsigned int msgNo, void* pBuf, unsigned int buffSize);
extern int Bus429Write(unsigned int msgNo, void* pBuf, unsigned int buffSize);
extern int Bus429Read(unsigned int msgNo, void* pBuf, unsigned int buffSize);
extern int BusFCWrite(unsigned int msgNo, void* pBuf, unsigned int buffSize);
extern int BusFCRead(unsigned int msgNo, void* pBuf, unsigned int buffSize);
extern int Bu1553BCWrite(unsigned int rtId, unsigned int subaddr, void* pBuf, unsigned int buffSize);
extern int Bu1553BCRead(unsigned int rtId, unsigned int subaddr, void* pBuf, unsigned int buffSize);
extern int Bu1553RTWrite(unsigned int subaddr, void* pBuf, unsigned int buffSize);
extern int Bu1553RTRead(unsigned int subaddr, void* pBuf, unsigned int buffSize);

typedef struct
{
	unsigned int longitude;
	unsigned int latitude;
	unsigned int altitude;
}Position;

void usrapp1()
{
	Position position;
	position.longitude = 119;
	position.latitude = 20;
	position.altitude = 5000;
	double longitude = 119;
	double latitude = 20;
	double altitude = 5000;
	while(1)
	{
		
		Bus422Write(2, (void*)&position, sizeof(Position)); //to dc
		
		longitude += 0.01;
		latitude += 0.01;
		altitude += 0.2;
		position.longitude = (unsigned int)longitude;
		position.latitude = (unsigned int)latitude;
		position.altitude = (unsigned int)altitude;
		
		taskDelay(90);
	}
}