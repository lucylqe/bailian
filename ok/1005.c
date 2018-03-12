#include <stdio.h>
#define PI_DIV_10 0.03141592653589793
float map[N];
int main()
{
	int n,i;
	float x,y;
	scanf("%d", &n);
	i=1;
	while(n-->0)
	{
					scanf("%f %f", &x, &y);
					printf("Property %d: This property will begin eroding in year %d.\n", i++, (int)((x*x+y*y)*PI_DIV_10)+1);
	}
	printf("END OF OUTPUT.");
}
