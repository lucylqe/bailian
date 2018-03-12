#include <stdio.h>
#include <string.h>

#define MAXN 100
int row, col;
int h[MAXN][MAXN];
int vis[MAXN][MAXN];

int dx[]={-1, 0, 1,  0};
int dy[]={ 0, 1, 0, -1};

int getL(int x, int y)
{
	int i, newX, newY, l, curL;

	if(vis[x][y])
		return vis[x][y];

	curL = 1;
	for(i=0; i<sizeof(dx); i++)
	{
		newX = x+dx[i];
		newY = y+dy[i];

		if(newX<0||newX>=row||newY<0||newY>=col)
			continue;
		if( h[x][y] > h[newX][newY] )
		{
			l = getL(newX, newY)+1;
			if(l > curL )curL = l;
		}
	}
	vis[x][y]=curL;
	return curL;
}

int main()
{
	int i, j, k, l, maxL;

	scanf("%d %d", &row, &col);
	for(i=0; i<row; i++)
		for(j=0; j<col; j++)
			scanf("%d", &h[i][j]);
	maxL = 1;
	for(i=0; i<row; i++)
		for(j=0; j<col; j++)
		{
			l = getL(i,j);
			if(l>maxL) maxL = l;
		}

	printf("%d\n", maxL);			
}
