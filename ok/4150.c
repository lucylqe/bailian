#include <stdio.h>
#include <stdlib.h>

#define N 10000
int n, maxV, A[N], B[N], C[N], S[N][4];
int P[N], V[N];

void permutation(int cur)
{
	int i,j,ok,v;
	if(cur==n)
	{
		v=0;
		if (P[0]>P[1]) v+=B[0];
		else v+=A[0];

		if (P[n-1]>P[n-2]) v+=B[n-1];
		else v+=A[n-1];

		for(i=1;i<n-1;i++)
		{
			if( P[i]>P[i+1] && P[i]>P[i-1])
				v = C[i];
			else if ( P[i]<P[i+1] && P[i]>P[i-1])
				v += A[i];
			else
				v += B[i];
		}

		maxV =maxV > v ? maxV : v;
		return;
	}

	for(i=0;i<n;i++) if(!V[i])
	{
		V[i]=1;
		P[cur]=i;
		permutation(cur+1);
		V[i]=0;
	}
}


void permutation1()
{
	int i, j, k, v;
	for(i=0; i<n; i++) P[i]=i;

	while(1)
	{
		v=0;
		if (P[0]>P[1]) v+=B[0];
		else v+=A[0];

		if (P[n-1]>P[n-2]) v+=B[n-1];
		else v+=A[n-1];

		for(i=1;i<n-1;i++)
		{
			if( P[i]>P[i+1] && P[i]>P[i-1]) v = C[i];
			else if ( P[i]<P[i+1] && P[i]>P[i-1]) v += A[i];
			else v += B[i];
		}
		maxV = maxV > v ? maxV : v;

		//find swap point
		i=n-2;
		while( i>=0 && P[i]>P[i+1] ) i--;
		if(i==-1) break;
		
		//find swap value
		j=n-1;
		while( j>=0 && P[j]<P[i] ) j--;

		// swap
		P[i]^=P[j];P[j]^=P[i];P[i]^=P[j];

		// rever
		for(i=i+1,j=n-1; i<j; i++,j--)
		{
			P[i]^=P[j];P[j]^=P[i];P[i]^=P[j];
		}
	}
}


int main(int argc, char *argv[])
{
	int i,j,k;
	scanf("%d", &n);
	i=0; while(i<n)scanf("%d", &A[i++]);
	i=0; while(i<n)scanf("%d", &B[i++]);
	i=0; while(i<n)scanf("%d", &C[i++]);
	
	S[0][0]=A[0];
	S[0][1]=0;
	S[0][2]=B[0];
	S[0][3]=0;

	for(i=1;i<n;i++)
	{
		S[i][0]=( S[i-1][2] > S[i-1][3] ? S[i-1][2] : S[i-1][3]) + A[i]; 
		S[i][1]=( S[i-1][0] > S[i-1][1] ? S[i-1][0] : S[i-1][1]) + B[i]; 
		S[i][2]=( S[i-1][2] > S[i-1][3] ? S[i-1][2] : S[i-1][3]) + B[i]; 
		S[i][3]=( S[i-1][0] > S[i-1][1] ? S[i-1][0] : S[i-1][1]) + C[i]; 
	}
	

	printf("%d", S[n-1][0] > S[n-1][1] ? S[n-1][0] : S[n-1][1] );
	return 0;
}
