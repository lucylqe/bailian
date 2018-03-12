#include <stdio.h>
#include <string.h>

#define N 100
int n,G[N][N],ind[N];
int main()
{
	int i,j,u,v;
	memset(G, 0x00, sizeof(G));
	memset(ind,0x00, sizeof(ind));
	scanf("%d %d", &n, &i);
	while(i-->0)
	{
		scanf("%d %d",&u, &v);
		G[u-1][v-1]=1;
		ind[v-1]++;
	}
	for(u=0;u<n;u++)
	{
		if(ind[u]==0)
		{
			printf("v%d ", u+1);
			ind[u]=-1;
			for(v=0;v<n;v++) if (G[u][v])
			{
				G[u][v]=0;
				ind[v]--;
			}
			u=0;
		}
	}
}
