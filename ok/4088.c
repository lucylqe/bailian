#include <stdio.h>
#include <string.h>

#define N 1000000
int la,A[N],lb,B[N];
int main()
{
	int i,j,k,v,n,*pl,*p,stop;
	k=2;
	while(k-->0)
	{
		if(k==1) { pl=&la; p=A;}
		else { pl=&lb; p=B;}
		scanf("%d", &j);
		while(j-->0)
		{
			scanf("%d", &v);
			p[(*pl)++]=v;
		}
		stop=0;n=*pl;
		while(1)
		{
			stop=1;
			for(i=0;i<n-1;i++)
			{
				if(p[i] > p[i+1])
				{
					p[i]^=p[i+1];
					p[i+1]^=p[i];
					p[i]^=p[i+1];
					stop=0;
				}
			}
			n--;
			if(stop)break;
		}
	}
	i=j=0;
	while(i<la||j<lb)
	{
		if(i<la&&j<lb)
		{
			if     (A[i]>B[j]) printf("%d ",B[j++]);
			else if(A[i]<B[j]) printf("%d ",A[i++]);
			else { i++;j++;}
		}
		else if (i<la){ while(i<la) printf("%d ",A[i++]);}
		else if (j<lb){ while(j<lb) printf("%d ",B[j++]);}
	}
}
