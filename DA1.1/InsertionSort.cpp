#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<time.h>
#include <stdlib.h>
void Swap(int &a, int &b) {
	int tmp=a;
	a=b;
	b=tmp;
}
//sap xep giam dan
//void Insertion_Sort(int A[], int n) {
//	for(int i=0; i<n; i++) {
//		int last=A[i];
//		int j=i;
//		while((j>0) && (A[j-1]<last)) {
//			A[j]=A[j-1];
//			j--;
//		}
//		A[j]=last;
//	}
//}

//sap xep tang dan 
void Insertion_Sort(int A[], int n) {
	for(int i=0; i<n; i++) {
		int last=A[i];
		int j=i;
		while((j>0) && (A[j-1]>last)) {
			A[j]=A[j-1];
			j--;
		}
		A[j]=last;
	}
}

int main() {    
	int A[100000];
    int i,n;  
	printf("---------INSERTION SORT VERSION-------");
	while(1) {     
    	printf("\n Nhap n:");
    	scanf("%d",&n);
    	for(int i=0;i<n;i++)
			A[i]=rand()&999; 	
		printf("\n Day so ban dau la:\n");
		for(int i=0;i<n;i++)
		printf("%5d",A[i]);	       
		printf("\n\n Ket qua sau khi sap xep tang dan la:\n");
		clock_t start=clock();
		Insertion_Sort(A,n);
		clock_t finish=clock();
		double d= (double)(finish-start)/ CLOCKS_PER_SEC;
		for(int i=0;i<n;i++)
		printf("%5d",A[i]);
		printf("\n\n Thoi gian thuc hien thuat toan sap xep chen la:%.5f ", d);
	}
}	

