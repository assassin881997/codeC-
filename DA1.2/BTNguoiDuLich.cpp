#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <iomanip>
#define TRUE 1
#define FALSE 0

typedef int hanhtrinh[100];
typedef int cuocphi[100][100];
int xp,n,t,min,max;
char ch;
hanhtrinh p,pm;
cuocphi c;
char b[100];

int init() {
	int i,j;
    for(i=0;i<n;i++) {
        b[i]=TRUE;// danh dau thanh pho di qua
        p[i]=xp;
    }
    min=100;
    max=0;
    for(i=0;i<n;i++)
     	for(j=0;j<n;j++) {
        	if(c[i][j]<min)
        	min=c[i][j];
        	if(c[i][j]>max)
        	max=c[i][j];
     	}
    printf("min=%d\n",min);
    printf("max=%d\n",max);
    t=n*max;
    printf("t=%d",t);
    b[xp]=FALSE;
    return 0;
}

void inkq() {
    int i;
    printf("\nHanh trinh toi uu:\n");
    for(i=0;i<n;i++) printf("%d=>",pm[i]);
    printf("%d\nChi phi:%d",xp,t);
    return;
}

void nhapdl() {
    int i,j;
    printf("\nSo thanh pho:");     
	scanf("%d",&n);
    printf("\nThanh pho xuat phat(0...%d):",n-1);
	scanf("%d",&xp);
	printf("MA TRAN CHI PHI\n");
    for(i=0;i<n;i++)
     	for(j=0;j<n;j++) c[i][j]=rand()%10;
    for(i=0;i<n;i++)
	 	c[i][i]=0; 
    for(i=0;i<n;i++) {
       for(j=0;j<n;j++)	printf("%10d",c[i][j]); 
		printf("\n");
    }
    return;
}
void Try(int k,int s) {
    int i,j,tg;
    for(i=0;i<n;i++) {
        tg=s+c[p[k-1]][i];
        if((b[i])&&(tg+min*(n-k)<t)) {
            p[k]=i;
            b[i]=FALSE;
            if((k==n-1)&&(tg+c[i][xp]<t)) {
                for(j=0;j<n;j++) pm[j]=p[j];
                t=tg+c[i][xp];
            }
            else if(k<n-1) Try(k+1,tg);
            b[i]=TRUE;
        }
    }
    return;
}

main() {
    printf("    BAI TOAN NGUOI DU LICH\n");
    nhapdl();
    init();
    Try(1,0);
    inkq();
    getch();
}
