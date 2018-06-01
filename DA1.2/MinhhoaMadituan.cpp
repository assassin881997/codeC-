#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<cmath>
#include<windows.h>
using namespace std;
const int kichthuoc = 5;
int KhungCo[kichthuoc+1][kichthuoc+1];
 // int x[8] = {2,2,1,-1,-2,-2,-1,1};  // Di nguoc chieu kim dong ho.
 // int y[8] = {1,-1,-2,-2,-1,1,2,2};
int x[8] = {2,1,-1,-2,-2,-1,1,2}; // Di theo chieu kim dong ho.
int y[8] = {1,2,2,1,-1,-2,-2,-1};
bool thang = FALSE;
void gotoxy(int x, int y)
{
    static HANDLE h = NULL;  
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };  
    SetConsoleCursorPosition(h,c);
};
void Di(int x_m,int y_m,int n){
	int x_t,y_t;
	for(int i = 0;i <= 7;i++){
		x_t = x_m + x[i];
		y_t = y_m + y[i];
		if(0 < x_t &&x_t <= kichthuoc &&0 < y_t &&y_t <= kichthuoc && KhungCo[x_t][y_t] == 0)
		{
			KhungCo[x_t][y_t] = n;
			gotoxy(5 + x_t*4,3 + y_t*2);
			Sleep(200);  cout<<n;
			gotoxy(6 + n*3,10 + kichthuoc*2);
			cout<<n;
			if(n == kichthuoc*kichthuoc){
				thang = TRUE;
				putchar(7);
			}
		    if(thang == FALSE)
		    	Di(x_t,y_t,n+1);
		    if(thang == TRUE )
				return ;
		    KhungCo[x_t][y_t] = 0;
			gotoxy(5 + x_t*4,3 + y_t*2);
		    Sleep(100);  cout<<"   ";
		    gotoxy(6 + n*3,10 + kichthuoc*2);
		    cout<<"   ";
		}
	}
};
int main(){
	int x_chon,y_chon;
	cout<<"thuat toan quay lui \n";
	cout<<"\n Moi ban nhap vi tri xuat phat x - y : ";  cin>>x_chon>>y_chon;
	if(x_chon < 1 ||x_chon > kichthuoc)
		x_chon = 1;
	if(y_chon < 1 ||y_chon > kichthuoc)
		y_chon = 1;
	gotoxy(4,4);
	cout<<"\t+---+---+---+---+---+ \n";
	cout<<"\t|   |   |   |   |   | \n";
	cout<<"\t+---+---+---+---+---+ \n";
	cout<<"\t|   |   |   |   |   | \n";
	cout<<"\t+---+---+---+---+---+ \n";
	cout<<"\t|   |   |   |   |   | \n";
	cout<<"\t+---+---+---+---+---+ \n";
	cout<<"\t|   |   |   |   |   | \n";
	cout<<"\t+---+---+---+---+---+ \n";
	cout<<"\t|   |   |   |   |   | \n";
	cout<<"\t+---+---+---+---+---+ \n";
	gotoxy(0,10 + kichthuoc*2);
	cout<<"Buoc di :";
	Di(x_chon - 2,y_chon - 1,1);
	gotoxy(0,5+kichthuoc*2);
	if(thang == TRUE)
		cout<<"Thanh cong !";
	else
		cout<<"Khong co loi giai.";
	return 1;
};
