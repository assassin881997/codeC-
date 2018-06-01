#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
void Swap(int &a, int &b) {
	int tmp=a;
	a=b;
	b=tmp;
}

//giam dan
//void Bubblesort(int A[], int n) {
//	for(int i=0;i<n;i++)
//    	for(int j=n-1;j>=i;j--)
//    		if(A[j]>A[j-1])
//    			Swap(A[j],A[j-1]);
//}

//tang dan
void Bubblesort(int A[], int n) {
	for(int i=0;i<n;i++)
    	for(int j=n-1;j>=i;j--)
    		if(A[j]<A[j-1])
    			Swap(A[j],A[j-1]);
}

int main() {    
	int A[100000];
    int i,n;
    printf("---------BUBBLE SORT VERSION-------");
	while(1) {      
		printf("\n Nhap n:");
		scanf("%d",&n);
		for(i=0;i<n;i++)
			A[i]=rand()%1000;
		printf("\n Day so ban dau la:\n");
		for(i=0;i<n;i++)
			printf("%5d",A[i]);	       
		printf("\n\n Ket qua sau khi sap xep la:\n");
		clock_t start=clock();
		Bubblesort(A,n);
		clock_t finish=clock();
		double d= (double)(finish-start)/ CLOCKS_PER_SEC;
		for(i=0;i<n;i++)
		printf("%5d",A[i]);
		printf("\n\n Thoi gian thuc hien thuat toan sap xep noi bot la:%.5f ", d);
	}
}	
