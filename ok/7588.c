#include <stdio.h>
#include <string.h>


#define MaxN 10


int main(int argc, char **argv)
{
	int i,j,n;
	int N[MaxN+1], pri[MaxN+1], priNum;

	// generate prime ltq maxN
	priNum = 0;
	memset(N, 0x00, sizeof(N));
	memset(pri, 0x00, sizeof(pri));
	for(i=2; i<=MaxN; i++)
		for(j=i; i*j<MaxN; j++)
			N[i*j]=1;
	for(i=1; i<=MaxN; i++) if(!N[i])
		pri[priNum++]=i;

	// cal factor
	scanf("%d", &n);
	memset(N, 0x00, sizeof(N));
	while(n>1)
	{
		for(i=1; i<priNum; i++)
		{
			j = pri[i];
			if(n%j==0)
			{
				N[j]++;
				n /= j;
			}
		}
	}
	
	//print result
	j = 1; //first flag
	for(i=0; i<MaxN; i++) if(N[i])
	{
		if(j) j = 0;
		else printf("*");

		if( N[i] == 1) printf("%d", i);
		else printf("%d^%d", i, N[i]);
	}
		
	return 0;
}
