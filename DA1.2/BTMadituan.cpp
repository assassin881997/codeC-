#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

using namespace std;
//buoc di cua con ma
int p[8] = {-2,-2,-1,-1,1,1,2,2};
int q[8] = {-1,1,-2,2,-2,2,-1,1};
int d=0,x,y,n,a[50][50];
//in ket qua
void inkq()
{
	cout << "Cach di thu " << ++d << ":" << endl;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
   		printf("%3d",a[i][j]);
  		cout << endl;
 	}
 	getch();
}

void tim(int x, int y, int k)
{
	if (k>n*n) inkq(); //neu vi tri nhay den nam ngoai ban co thi in ket qua
	else for (int i=0;i<8;i++)
	{
   		int x1=x+p[i],y1=y+q[i]; //vi tri nhay den tiep cua quan ma
   		if (x1>=0 && x1<n && y1>=0 && y1<n) //dieu kien nuoc di ke tiep
    	if (a[x1][y1]==0)
   		{
     		a[x1][y1]=k;
     		tim(x1,y1,k+1);
     		a[x1][y1]=0;
    	}
  	}
}

int main()
{
 	cout << "-----------KNIGHT'S TOUR----------\n";
	cout << "Kich thuoc ban co : ";
	cin >> n;
	cout << "Nhap vi tri xuat phat (x,y) :";
	cin >> x >> y;
	for (int i=0;i<n;i++)
  		for (int j=0;j<n;j++)
   			a[i][j]=0;
 			a[x][y]=1; //vi tri quan ma nhap vao
 			tim(x,y,2); //tim vi tri nhay den tiep theo
	if (d==0) cout << "Khong ton tai cach di thoa man";
	else cout << "Co tat ca " << d << " cach di thoa man";
	getch();
	return 0;  
}
