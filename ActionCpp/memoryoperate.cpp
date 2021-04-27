#include "memoryoperate.h"

void memoryCopyDemo()
{
	char sd[100] = "abcde123456fgpoiuytrabcde123456fgpoiuytrabcde123456fgpoiuytrabcde123456fgpoiuytr";
	char sd20[20];
	string str_many = "abcde123456fgpoiuytrabcde123456fgpoiuytrabcde123456fgpoiuytrabcde123456fgpoiuyt";
	//memccpy(sd20, sd, sizeof(sd20), 20);
	memcpy(sd20, str_many.data(), sizeof(sd20));
	
}
