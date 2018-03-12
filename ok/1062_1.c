#include <stdio.h>
#include <string.h>

#define MAXN 100
#define INF 0x7fffffff

int Gap, N;
int price[MAXN];
int level[MAXN];
int weightOri[MAXN][MAXN], weight[MAXN][MAXN];

int dis(int o, int min_level, int max_level)
{
	int i, j, k, min_j, min_price;
	int dist[MAXN], vis[MAXN];

	// init
	memset(vis, 0x00, sizeof(vis));
	vis[o]=1;
	for(j=0; j<N; j++)
	{
		if( weight[o][j]!=-1 ) dist[j]=weight[o][j];
		else dist[j] = INF;
	}
	
	for(i=0; i<N; i++)
	{
		// min j
		for(j=0; j<N; j++) if( !vis[j] ){ min_j = j; break; }
		for(   ; j<N; j++) if( !vis[j] ) min_j = dist[j] < dist[min_j] ? j : min_j;
		vis[min_j] = 1;

		// up dist 
		for(j=0; j<N; j++) if( !vis[j] && weight[min_j][j]!=-1 && dist[j] - dist[min_j] > weight[min_j][j])
			dist[j] = dist[min_j] + weight[min_j][j];
	}

	//find min price
	min_price = INF;
	for(i=0; i<N; i++) if(dist[i]!=INF)
	{
		min_price = dist[i]+price[i] < min_price ? dist[i]+price[i] : min_price;
	}
	return min_price;
}

int main()
{
	int i, j, k, w, min_price, min_level, max_level, cur, id;
	memset(weightOri, -1, sizeof(weightOri));

	// store data
	scanf("%d %d", &Gap ,&N);
	for(i=0; i<N; i++)
	{
		scanf("%d %d %d", price+i, level+i, &k);
		weightOri[i][i] = 0;
		for(j=0; j<k; j++)
		{
			scanf("%d %d", &id, &w);
			weightOri[i][id-1] = w;
		}
	}	

	k = Gap; min_price = INF;
	while(k>=0)
	{
		max_level = level[0]+k;
		min_level = max_level - Gap;

		//copy weight	
		for(i=0; i<N; i++) for(j=0; j<N; j++) 
		{
		if( level[i]>max_level||level[i]<min_level||level[j]>max_level||level[j]<min_level )
			weight[i][j]=-1;
		else weight[i][j]=weightOri[i][j];
		}

		j = dis(0, min_level, max_level);
		min_price = j<min_price?j:min_price;
		k--;
	}

	printf("%d\n", min_price);
}
