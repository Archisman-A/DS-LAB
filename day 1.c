#include <stdio.h>

void main()
{
	int m,n;
	printf("Enter rows and columns respectively: \n");
	
	scanf("%d %d", &m, &n);
	
	int i,j;
	int a[m][n];
	
	printf("Fill the array...\n");
	for(i=0;i<m;i++)
	for(j=0;j<n;j++)
	scanf("%d", &a[i][j]);
	int k,temp;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n-1;j++)
		for(k=0;k<n-j-1;k++)
		if((i+1)%2 == 1)
		{
			if(a[i][k]>a[i][k+1])
			{
				temp = a[i][k];
				a[i][k]= a[i][k+1];
				a[i][k+1]= temp;
			}
		}
		else {
			if(a[i][k]<a[i][k+1])
			{
				temp = a[i][k];
				a[i][k]= a[i][k+1];
				a[i][k+1]= temp;
			}
			
		}
	}
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		printf("%d ", a[i][j]);
		printf("\n");
	}

	
}
