#include <stdio.h>
#include <stdlib.h>
#include "string.h"
int main()
{
	int i;
	float f, l, fn[300+1];
	memset(fn, 0x00, sizeof(fn));
	for(i=1; i<=300;i++)
	{
		fn[i] += fn[i-1]+1.0/i;
	}

	while(1)
	{
		scanf("%f", &l);
		if (l < 0.0001) break;
		for(i=1; i<300; i++)
		{
			if ( fn[i+1] >= l+1 )
			{
				printf("%d card(s)\n", i);
				break;
			}
		}
	}

}
