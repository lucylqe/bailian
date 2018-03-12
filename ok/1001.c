#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int multi(char *s1, int s1_len, char *s2, int s2_len, char *tmp)
{
	int i, j;
	int num1, num2, num3, carry;
	char num;
	for(i=0; i<s1_len; i++)
	{
			num1 = s1[i] - '0';
			carry = 0;
			for(j=0; j<s2_len; j++)
			{
				num2 = s2[j] - '0';
				num3 = tmp[i+j];
				if ( num3 != 0 )
					num3 -= '0';
				else
					num3 = 0;
				num =  num1*num2 + num3;
		    // printf("[%d][%d][%d][%d][%d][%d]\n", i, j, num1, num2, num3, num);
				tmp[i+j] = num%10 + '0';
				carry = num/10;
				if(carry > 0)
				{
					num3 = tmp[i+j+1];
					if (num3 != 0)
						num3 -= '0';
					else
						num3 = 0;
					num3 += carry;
					tmp[i+j+1] = num3 + '0';
				}
			}
			}
}

int main()
{
	char strN[6+1];
	int R;
	char s1[2*25+1], s2[2*25+1];// revered[strN]
	size_t s1_len, s2_len;			// 
	char res[2*25+1], tmp[2*25+1];
	int i,j,decimal_num;

	while(scanf("%s%d", strN, &R)==2){
		memset(s1, 0x00, sizeof(s1));
		memset(s2, 0x00, sizeof(s2));
		memset(tmp, 0x00, sizeof(tmp));
		memset(res, 0x00, sizeof(res));
		s1_len = s2_len = i = j= decimal_num = -1;

		s1_len = strlen(strN);
		for(i=0,j=0; i<s1_len; i++){
			s1[j] = strN[s1_len-1-i];
			if (strN[s1_len-1-i] == '.'){
				decimal_num = i * R;
				continue;
			}
			s2[j] = s1[j];
			j++;
		}	
		s1_len = s2_len = strlen(s1);

//		printf("%s\n", s1);
		if ( R == 0 ){ 
			printf("1");
			continue;
		}
		
		if ( R == 1 )
		{
	strcpy(tmp, s1);
		}
		else
		{
	while( R-- > 1){
		memset(tmp, 0x00, sizeof(tmp));
			//		printf("[%s] [%s] [%s]\n", s1, s2, tmp);
		multi(s1, s1_len, s2, s2_len, tmp);
		strcpy(s1, tmp);
		s1_len = strlen(s1);
	}
		}
	//	printf("%d[%s]\n", decimal_num, tmp);
	  for(i=0,j=0; i<s1_len;i++){
	if ( i==decimal_num ){
			tmp[j++] = '.';
	}
	tmp[j++] = s1[i];
		}
		if ( decimal_num > 0)
		{
			strcpy(s1, tmp);
			s1_len = strlen(tmp);
			memset(tmp, 0x00, sizeof(tmp));
			for(i=0,j=0; i<s1_len;i++){
		if ( s1[i] == '0' && j==0 ){
				if (s1[i+1]=='.'){
					i++;
					strcpy(tmp, s1+i+1);
					break;
				}
				continue;
		}
		tmp[j++] = s1[i];
			}
		}

		s1_len = strlen(tmp);
		for(i=0,j=0; i<s1_len; i++)
		{
	if (j==0 && tmp[s1_len-1-i] == '0')
			continue;
		res[j++] = tmp[s1_len-1-i];
		}

		if (res[0] != 0)
			printf(res);
		else
			printf("0");
		printf("\n");
	}
}
