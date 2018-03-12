#include <stdio.h>


int main()
{
	float sn,n;
	int line;
	sn=n=0.00;line=12;
	while(line-->0)
	{
					scanf("%f", &n);
					sn += n;
	}
	printf("$%.2lf", sn/12.0);
		return 0;
}
