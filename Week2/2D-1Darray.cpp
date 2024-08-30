#include<iostream>
using namespace std;

// upperTriangular

int main()
{
	int upperTriangular[4][4] =
	{
		{ 0 , 1 , 2 , 3 },
		{ 0 , 0 , 4 , 5 },
		{ 0 , 0 , 0 , 6 },
		{ 0 , 0 , 0 , 0 }
		
	};
	int i=4 ; int j=4;
	cout<<"The elements of the Upper Triangular matrix in 1D \t :";
	for(i=0;i<j;i++)
	{
		for(j=0;j<4;j++)
		{
			if(upperTriangular[i][j]!=0)
			{
				
				cout<<upperTriangular[i][j];
				cout<<"\t";
			}
		}
	}
	cout<<"\n";
	
	
//	lowerTriangular


	int lowerTriangular[4][4] =
	{
		{ 0 , 0 , 0 , 0 },
		{ 7 , 0 , 0 , 0 },
		{ 8 , 9 , 0 , 0 },
		{ 10 , 11 , 12 , 0 }
		
	};
	cout<<"The elements of the Lower Triangular matrix in 1D \t :";
	for(i=0;i<j;i++)
	{
		for(j=0;j<4;j++)
		{
			if(lowerTriangular[i][j]!=0)
			{
				cout<<lowerTriangular[i][j];
				cout<<"\t";
			}
		}
	}
		cout<<"\n";
		
// 	diagonalMatrix

	int diagonalMatrix[4][4] =
	{
		{ 1 , 0 , 0 , 0 },
		{ 0 , 2 , 0 , 0 },
		{ 0 , 0 , 3 , 0 },
		{ 0 , 0 , 0 , 4 }
		
	};
	cout<<"The elements of the diagonal Matrix in 1D \t :";
	for(i=0;i<j;i++)
	{
		for(j=0;j<4;j++)
		{
			if(diagonalMatrix[i][j]!=0)
			{
				cout<<diagonalMatrix[i][j];
				cout<<"\t";
			}
		}
	}
		cout<<"\n";
		
		
		
//	tridiagonalMatrix
	
	
	int tridiagonalMatrix[4][4] =
	{
		{ 1 , 8 , 0 , 0 },
		{ 5 , 2 , 9 , 0 },
		{ 0 , 6 , 3 , 10 },
		{ 0 , 0 , 7 , 4 }
		
	};
	cout<<"The elements of the Tri-diagonal Matrix in 1D \t :";
	for(i=0;i<j;i++)
	{
		for(j=0;j<4;j++)
		{
			if(tridiagonalMatrix[i][j]!=0)
			{
				cout<<tridiagonalMatrix[i][j];
				cout<<"\t";
			}
		}
	}
			cout<<"\n";
			
			
//	rowmajorMatrix		
	
	int rowmajorMatrix[4][4] =
	{
		{ 1 , 2 , 3 , 4 },
		{ 5 , 6 , 7 , 8 },
		{ 9 , 10 , 11 , 12 },
		{ 13 , 14 , 15 , 16 }
		
	};
	cout<<"The elements of the Row-Major Matrix in 1D \t :";
	for(i=0;i<j;i++)
	{
		for(j=0;j<4;j++)
		{
			{
				cout<<rowmajorMatrix[i][j];
				cout<<"\t";
			}
		}
	}
	cout<<"\n";
	
//columnmajorMatrix
	
	int columnmajorMatrix[4][4] =
	{
		{ 1 , 2 , 3 , 4 },
		{ 5 , 6 , 7 , 8 },
		{ 9 , 10 , 11 , 12 },
		{ 13 , 14 , 15 , 16 }
		
	};
	cout<<"The elements of the Column-Major Matrix in 1D \t :";
	for(j=0;j<4;j++)
	{
		for(i=0;i<4;i++)
		{
			{
				cout<<columnmajorMatrix[i][j];
				cout<<"\t";
			}
		}
	}
	cout<<"\n";
	
	
}



