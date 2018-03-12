#include <stdio.h>
#include <string.h>

#define MAXN 100


int Gap, N;
int price[MAXN];
int level[MAXN];
int weight[MAXN][MAXN];

int result[MAXN][MAXN][MAXN];

int HASH[MAXN];
int convLevel(int l)
{
	int i, id = l%MAXN;
	for(i=id; i!=id-1; i = (i+1)%MAXN )
	{
		if ( HASH[i] == -1 ) 
		{
			HASH[i]=l;
			//printf("new HASH[%d]=%d\n", i, l);
			return i;
		}
		else if( HASH[i] == l)
		{
			//printf("hit HASH[%d]=%d\n", i, l);
			return i;
		}
	}
	return -1;
}

int dfs(int cur, int min_level, int max_level)
{
	int i, j, l1, l2, cur_price, min_price=price[cur];
	int *pr;
	for(j=0; j<N; j++) if( weight[cur][j] > 0)
	{
		l1 =  level[j] < min_level ? level[j] : min_level;
		l2 =  level[j] > max_level ? level[j] : max_level;
		if( l2 - l1 > Gap ) continue;
		
		pr = &result[j][convLevel(l1)][convLevel(l2)] ;
		if ( *pr == -1 )
		{
			*pr = dfs(j, l1, l2);
			//printf("new result[%d][%d][%d]=%d\n", j, convLevel(l1), convLevel(l2), *pr);
		}
		else
		{
			//printf("hit result[%d][%d][%d]=%d\n", j, convLevel(l1), convLevel(l2), *pr);
		}
		cur_price = weight[cur][j] + *pr;
		if(cur_price < min_price)
			min_price = cur_price;
	}
	return min_price;
}

int main()
{
	int i, j, k, w, cur, id;
	
	i = j = k = w = cur = id = 0;
	memset(price, -1, sizeof(price));
	memset(level, -1, sizeof(level));
	memset(weight,-1, sizeof(weight));
	memset(result,-1, sizeof(result));
	memset(HASH,  -1, sizeof(HASH));

	// store data
	scanf("%d %d", &Gap ,&N);
	for(i=0; i<N; i++)
	{
		scanf("%d %d %d", price+i, level+i, &k);
		for(j=0; j<k; j++)
		{
			scanf("%d %d", &id, &w);
			weight[i][id-1] = w;
		}
	}	
	printf("%d\n", dfs(0, level[0], level[0]));
}


