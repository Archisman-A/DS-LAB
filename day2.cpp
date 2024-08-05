#include <bits/stdc++.h>
using namespace std;



int main()
{
	int n;
	cout << "enter dimension\n";
	cin >> n;
	
	int A[n][n], B[n][n];
	
	int i,j;
	
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{
		A[i][j]=0;
		B[i][j]=0;
	}
	
	int q= n*n;
	int p= (int)(q/5); // sir told 5
	
	int k;
	for( k=1; k<=p;k++)
	{
		int loc1 = rand()%(q+1), loc2 = rand()%(q+1);
		
		int count =0;
		
		    
			for(i=0;i<n;i++)
			
			for (j=0;j<n;j++)
			{
				count ++;

                if(count == loc1) goto here;
			}	
			here:
			int row1=i, col1=j;
			
			
			
			
			count =0;
			
		
			for(i=0;i<n;i++)
			
			for (j=0;j<n;j++)
			{
				count ++;

                if(count == loc2) goto here1;
			}	
			
			here1:
			int row2=i, col2=j;
			
			int num1 = rand()%9 +1, num2= rand()%9 +1;
			
			A[row1][col1]= num1; B[row2][col2]=num2;
			
	}
	
	cout << "for A mat: \n\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		cout << A[i][j]<< " ";
		cout << "\n";
	}
	cout << "\n";
	cout << "for B mat: \n\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		cout << B[i][j]<< " ";
		cout << "\n";
	}
	cout << "\n";
	
	
		cout << "for A sp mat: \n\n";
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			if(A[i][j] !=0 )
			//cout << "i="<<i << "\tj="<< j << "\titem=" << A[i][j] << "\t";
			printf("(%d , %d) = %d   ", i,j,A[i][j]);
			cout <<endl;
		}
		cout << endl;
		cout << "for B sp mat: \n\n";
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			if(B[i][j] !=0 )
			//cout << "i="<<i << "\tj="<< j << "\titem=" << B[i][j] << "\t";
			printf("(%d , %d) = %d   ", i,j,B[i][j]);
			cout << endl;
		}
		
		
		int C[n][n];
		//sumA(C,A,B);
		//int i,j;
		
		/*	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{
		C[i][j]=0;
		//B[i][j]=0;
	}*/
	
	
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	C[i][j]= B[i][j]+A[i][j];
	cout <<endl;
	
	cout << "for C mat: \n\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		cout << C[i][j]<< " ";
		cout << "\n";
	}
	
	cout << endl;
	cout << "for C sp mat: \n\n";
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			if(C[i][j] !=0 )
			//cout << "i="<<i << "\tj="<< j << "\titem=" << C[i][j] << "\t";
			printf("(%d , %d) = %d   ", i,j,C[i][j]);
			cout << endl;
		}
	
	
}
