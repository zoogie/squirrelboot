#include <stdlib.h>
#include <stdio.h>
#include <3ds.h>

int main()
{
	Result res=0;
	gfxInitDefault();
	consoleInit(GFX_TOP,NULL);

	printf("squirrelboot - zoogie\n\n");
	
	res = nsInit();
	printf("ns %08X\n",(int)res);
	
	u64 tid=0x000480044b454e4a;
	
	res = NS_RebootToTitle(0, tid);
	printf("ns_rebootToTitle %08X\n\n",(int)res);
	
	if(!res)printf("Success!\nLaunching free dsiware game %016llX ...", tid);
	else
	        printf("Something went wrong, press Start to exit");

	while (aptMainLoop())
	{
		gspWaitForVBlank();
		hidScanInput();

		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break; 

	}

	nsExit();
	gfxExit();
	return 0;
}