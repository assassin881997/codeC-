#include <iostream>
#include <iomanip>

#include <stdio.h>
#include <conio.h>
#include <windows.h>
using namespace std;
#define N 8

int C[N]; //Cot da bi kiem soat
int D1[2*N]; // Duong cheo / (i+j=const, 0 <= i+j <= 2*N-2) da bi kiem soat
int D2[2*N]; // Duong cheo \ (i-j=const, -N+1 <= i+j <= N-1)da bi kiem soat
int A[N][N]; //Ban co, neu Board[i][j]!=0 la da duoc dat

void chessboard() //Ham tao cho ban co
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		C[i] = 0;
		D1[i] = 0;
		D1[N+i] = 0;
		D2[i] = 0;
		D2[N+i] = 0;
	}
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			A[i][j] = 0;
}

void printBoard() //In ban co tu ma tran A[N][N]
{
	int i, j;
	static int n = 1;
	cout<<"\n\nCach "<<n<<":\n"<<endl;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			cout<<setw(3)<<A[i][j];
		cout<<endl;
	}
	cout<<endl;
	n++;
	getch();
}

void Set(int m, int n,int unset=1) //Thu di quan co vao A[m][n]
{
	if (unset == 1) //Danh dau la da di
	{
		C[n] = 1;
		D1[m+n] = 1;
		D2[m-n+N-1] = 1;
	}
	else //Quay tro lai, khong di buoc do nua
	{
		C[n] = 0;
		D1[m+n] = 0;
		D2[m-n+N-1] = 0;
		A[m][n] = 0; //Van de do bieu dien du lieu dau ra
	}
}

int checkBoard(int i, int j) //Kiem tra xem nuoc di co duoc khong
{
	if ((C[j]==0) && (D1[i+j]==0) && (D2[i-j+N-1]==0))
		return 1;
	return 0;
}

void setBoard(int k=0)
{
	int i;
	for (i = 0; i < N; i++) //Voi moi cot
		if (checkBoard(k, i)) //Kiem tra xem co the dat quan hau o hang
		//thu k vao cot thu i hay ko
		{
			A[k][i] = k + 1; //Luu thong tin vao ban co
			if (k == N-1) //Neu dat cau hinh cuoi   
			{
				printBoard(); //Hien thi ban co
				A[k][i] = 0; //Van de ve cach bieu dien du lieu dau ra
			}
			else
			{
				Set(k, i, 1); //Danh dau la da di
				setBoard(k + 1); //Di quan co tiep theo
				Set(k, i, 0); //Quay tro lai vi tri truoc, bo danh dau
				// coi nhu chua di quan nay
			}
		}
}


main()
{
	printf("--------------QUEEN PUZZLE--------------");
	//printf("\n Kich thuoc ban co: 8x8");
	chessboard();
	setBoard();
	cout<<endl;
	return 0;
}
