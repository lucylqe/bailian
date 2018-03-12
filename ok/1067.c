#include <stdio.h>
#include <math.h>


int main()
{
	int an, bn, tmp, n;
	double k = (sqrt(5)+1)/2;
	while(scanf("%d %d",&an,&bn)){ 
		tmp=(int)((bn-an)*k);
		if(an==tmp || bn==-tmp)printf("0\n");
		else printf("1\n");
	}
	return 0;
}
