#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _node{
	struct _node *next[10];
}Node;

void delete(Node *root)
{
	Node *p = root;
	//printf("free[%d]\n", p);
	int i;
	for(i=0; i<10;i++)
	{
		if(p->next[i]!=NULL)
		{
			delete(p->next[i]);
			p->next[i]=NULL;
		}
	}
	free(p);
}
int main()
{
	int i,j,k,n,t,ok;
	Node *root, *p;
	char str[11],*pStr;
	scanf("%d", &k);
	while(k--)
	{
		scanf("%d", &n);
		ok=1;
		root = (Node *)malloc(sizeof(Node));
		memset(root, 0x00, sizeof(root));
		//printf("malloc[%d]\n", root);
		while(n--)
		{
			scanf("%s", str);
			p=root; pStr=str;
			while(ok&&*pStr)
			{
				i= *pStr-'0';
				if(p->next[i]==NULL)
				{
					p->next[i] = (Node *)malloc(sizeof(Node));
					memset(p->next[i], 0x00, sizeof(p->next[i]));
					//printf("malloc[%d]\n", p->next[i]);
					p=p->next[i];
				}
				else
				{
					/* str[-1]不用创建新结点 说明str肯定是前缀*/
					if( *(pStr+1)=='\0') ok = 0;
					
					/* 旧结点为某个串的结尾 说明str包含以前的某个串*/
					p=p->next[i];
					for(j=0;j<10;j++)
					{
						//printf("----[%d][%d][%d]\n",p,j,p->next[j]);
						if(p->next[j]!=NULL) break;
					}
					if(j==10) ok=0; 
					printf("old[%d][%d][%d]\n", p->next[i],j,ok);
				}
				pStr++;
			}
		}
		if(ok)printf("YES\n");
		else printf("NO\n");
		delete(root);
		root=NULL;
	}
}
