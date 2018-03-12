#include <stdio.h>

#define MAX_PRI_NUM 20
int priFactor[MAX_PRI_NUM];
int priN=-1;

int main()
{
	long long unsigned i,j,k,n,m,tot,factor,symbol, delta;
	scanf("%d %d", &n, &m);

	// 因式分解
	k = m;
	for(i=2; k>=2&&i<=k; )
	{
		if(k%i == 0)
		{
			k /= i;
			//put i in priFact
			if(priN==-1 || priFactor[priN] != i)  priFactor[++priN] = i;
		}
		else i++;
	}

	for(i=0;i<=priNum;i++) printf("%d ", priFactor[i]);
	printf("\n");

	tot = 1;
	for(i=1; i<=n; i++) tot *= m;
	printf("[%d]\n", tot);

	// i 因子的个数
	for(i=1; i<1<<priN; i++)
	{
		//	printf("%d\n", k);
		//获取k中一个的个数
		factor = 1;
		symbol = 0; // 0+ 1-
		for(j=0; j<=priN; j++)if( i&(1<<j) )
		{
			symbol = !symbol;
			factor *= priFactor[j];
		}
	//	printf("symbol[%d] %d\n", symbol,factor);
		
		delta = 1; k = m/factor;
		for(i=1; i<=n; i++) delta*=k;

		if(symbol) tot -= delta;
		else	   tot += delta;
	}
	printf("%d\n", tot);
}
