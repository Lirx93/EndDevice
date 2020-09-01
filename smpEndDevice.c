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
	unsigned int type;
	unsigned int num;
}Weapon;

void usrapp1()
{
	Weapon weapons[6];
	Weapon weapon;
	
	
	weapons[0].type = 1;
	weapons[0].num = 1;
	weapons[1].type = 2;
	weapons[1].num = 1;
	
	
	
	
	while(1)
	{
		
		Bus422Write(6, (void*)&weapons, 6*sizeof(Weapon)); //to dc
		
		
		if (Bus422Read(4, &weapon, sizeof(Weapon)) == 0) //from DC
		{
			
			if(weapons[weapon.type].num > 0)
			{
				weapons[weapon.type].num--;
				if(weapon.type == 0)
				{
					printf("Shoot PL_10!");
				}
				if(weapon.type == 1)
				{
					printf("Shoot PL_12!");
				}
			}
		}
		
		taskDelay(2);
	}
}