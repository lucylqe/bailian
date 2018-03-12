#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int count[10000000];
int main()
{ 
	int i,j,n,v,a[7],map[128];
	char tmp[200+1];
	memset(count, 0x00, sizeof(count));
	map['0'] = 0; map['1']=1;
	map['2'] = map['A'] = map['B'] = map['C'] = 2;
	map['3'] = map['D'] = map['E'] = map['F'] = 3;
	map['4'] = map['G'] = map['H'] = map['I'] = 4;
	map['5'] = map['J'] = map['K'] = map['L'] = 5;
	map['6'] = map['M'] = map['N'] = map['O'] = 6;
	map['7'] = map['P'] = map['R'] = map['S'] = 7;
	map['8'] = map['T'] = map['U'] = map['V'] = 8;
	map['9'] = map['W'] = map['X'] = map['Y'] = 9;
	scanf("%d", &n);
	while(n-->0)
	{   
		scanf("%s",tmp);
		for(i=0,j=0; tmp[i] !='\0'; i++)
		{   
			if( tmp[i]!='-' ) a[j++] = map[tmp[i]];
		}   
		count[a[0]*1000000 + a[1]*100000 + a[2]*10000 + a[3]*1000 + a[4]*100 + a[5]*10 + a[6]]++;
	}      
	for(i=0,j=0; i<10000000;i++)
	{
		v = count[i];
		if ( v > 1 )
		{
			printf("%.3d-%.4d %d\n", i/10000, i%10000, v);
			j = 1;
		}
	}
	if ( j == 0 )
		printf("No duplicates.");
	return 0;
}
