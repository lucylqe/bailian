#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BEGIN 0
#define END 1
typedef struct _linkNode{
	int ok;
	int v[2];
	struct _linkNode *next[2];
} LinkNode;

int main()
{
	int _n, n;
	int i;
	LinkNode *pHead[2], *pNode, *pNode1, *pNode2;
while( (scanf("%d",&_n)==1) && _n )
{
	pHead[BEGIN]=pHead[END]=NULL;
	pNode=pNode1=pNode2=NULL;
	i=n=0;
	while(n++<_n)
	{
		pNode = (LinkNode *)malloc(sizeof(LinkNode));
		memset(pNode, 0x00, sizeof(LinkNode));
		pNode->ok = 1;

		scanf("%d %d", &pNode->v[BEGIN], &pNode->v[END]);
		if(pNode->v[BEGIN] > pNode->v[END] ){
			i = pNode->v[END];
			pNode->v[END] = pNode->v[BEGIN];
			pNode->v[BEGIN]=i;
		}
		// begin
		for(i=BEGIN; i<=END; i++)
		{
			pNode1=pNode2=pHead[i];
			while( pNode2 && pNode->v[i] > pNode2->v[i] )
			{
				pNode1 = pNode2;
				pNode2 = pNode2->next[i];
			}
			if(pNode1==pNode2)
			{
				if(pHead[i]==NULL) pHead[i]=pNode;
				else
				{
					pNode->next[i] = pHead[i];
					pHead[i] = pNode;
				}
			}
			else
			{
				pNode->next[i]=pNode2;
				pNode1->next[i]=pNode;
			}
		}
		//printf("pHead[%d] pNode->next[%d, %d] pNode->v[%d,%d]\n", 
		//		pHead[BEGIN], pNode->next[BEGIN], pNode->next[END], pNode->v[BEGIN], pNode->v[END]);
	}

	int j=0;
	pNode1=pHead[BEGIN];
	pNode2=pHead[END];
	while(pNode2)
	{
		if(!pNode2->ok) 
		{
			pNode2 = pNode2->next[END];
			continue;
		}

		while( pNode1 && pNode1->v[BEGIN] < pNode2->v[END] )
		{
			//输出可以看到电影
			//if(pNode1==pNode2)
			//{
			//	printf("[%d,%d]\n", pNode1->v[BEGIN], pNode1->v[END]);
			//}
			pNode1->ok = 0;
			pNode1 = pNode1->next[BEGIN];
		}
		j++;
		pNode2 = pNode2->next[END];
	}	
	printf("%d\n", j);

	pNode1=pNode2=pHead[BEGIN];
	while(pNode2)
	{
		//printf("BEGIN[%d] next[%d,%d] v[%d,%d]\n", pNode, pNode->next[BEGIN], pNode->next[END], pNode->v[BEGIN], pNode->v[END]);
		pNode1=pNode2;
		pNode2 = pNode2->next[BEGIN];
		free(pNode1);
	}
}
	return 0;
}
