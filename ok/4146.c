#include <stdio.h>
#include <stdlib.h>


int main()
{
	int ans[101], res,i, j, n, a,b,c,d[3];
for(n=1; n<=100; n++)
{
	res=-1;
	for(a=0; a<=n; a++)
	{
		for(b=0; b<=n; b++)
		{
			if( (a+b) % 2 )
				continue;
			for(c=0;c<=n;c++)
			{
				if( (b+c)%3 || (a+b+c)%5 )
					continue;
				res = a+b+c > res ? a+b+c : res;
			}
		}
	}
	ans[n]=res;
}
	while( scanf("%d", &n) == 1 )
		printf("%d\n", ans[n]);
}
