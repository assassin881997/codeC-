#include<stdio.h>
#include<math.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

void Swap(int &a, int &b) {
	int tmp=a;
	a=b;
	b=tmp;
}

void Max_Heapify(int A[], int i, int n) {
	int largest;
	int left=2*i;
	int right=2*i+1;
	if((left<=n) && (A[left]>A[i])) {
		largest=left;
	}
	else {
		largest=i;
	}
	if((right<=n) && (A[right]>A[largest])) {
		largest=right;
	}
	if(largest!=i) {
		Swap(A[largest],A[i]);
		Max_Heapify(A,largest,n);
	}
	return;
}
void Build_Max_Heap(int A[], int n) {
	for(int i=n/2-1; i>=0; i--) {
		Max_Heapify(A, i, n);
	}
	return;
}

void Heap_Sort(int A[], int n) {
	Build_Max_Heap(A, n);
	for(int i=n-1; i>=1; i--) {
		Swap(A[i],A[0]);
		Max_Heapify(A, 0, i-1);
	}
	return;
}	
int main() {    
	int A[100000];
    int i,n;
    printf("---------HEAP SORT VERSION-------");
	while(1) {
		printf("\n Nhap n:");
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			A[i]=rand()&999;      
		printf("\n Day so ban dau la:\n");
		for(int i=0;i<n;i++)
			printf("%5d",A[i]);	       
		printf("\n Ket qua sau khi sap xep tang dan la:\n");
		clock_t start=clock();
		Heap_Sort(A,n);
		clock_t finish=clock();
		double d= (double)(finish-start)/ CLOCKS_PER_SEC;
		for(i=0;i<n	;i++)
			printf("%5d",A[i]);
		printf("\n\n Thoi gian thuc hien thuat toan heap sort la:%.5f ", d);
	}
}	

