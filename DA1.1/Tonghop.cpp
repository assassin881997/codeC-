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

//Noi bot
void Bubblesort(int A[], int n) {
	for(int i=0;i<n;i++)
    for(int j=n-1;j>=i;j--)
    if(A[j]<A[j-1])
    Swap(A[j],A[j-1]);
}

//Chen
void Intertion_Sort(int A[], int n) {
	for(int i=0; i<n; i++) {
		int last=A[i];
		int j=i;
		while(j>0&&last<A[j-1]) {
			A[j]=A[j-1];
			j--;
		}
		A[j]=last;
	}
}

//Tron
void Tron(int A[],int first, int mid, int last) {
	int i1=first, i2=mid;
	int j1=mid+1, j2=last;
	int k=i1, tA[500000];
	for(;(i1<=i2)&&(j1<=j2);) {
		if(A[i1]<A[j1]) {
			tA[k]=A[i1];
			i1++;
		}
		else {
			tA[k]=A[j1];
			j1++;
		}
		k++;
	}
	for(;i1<=i2;) {
		tA[k]=A[i1];
		i1++;
		k++;
	}
	for(;j1<=j2;) {
		tA[k]=A[j1];
		j1++;
		k++;
	}
	for(int i=first;i<=last;i++) {
		A[i]=tA[i];
	}
	return;
}
void Sapxep(int A[],int first, int last) {
	int mid;
	if(first<last) {
		mid=(first+last)/2;
		Sapxep(A, first, mid);
		Sapxep(A, mid+1, last);
		Tron(A, first, mid, last);
	}
	return;
}

//Nhanh
int Partition(int A[], int left, int right) {
	int i=left, j=right, pivot=A[left];
	while(i<j) {
		while(i<=right&&A[i]<=pivot) {
			i++;
		}
		while(j>=left&&A[j]>pivot) {
			j--;
		}
		if(i<j) {
			Swap(A[i],A[j]);
		}
	}
	Swap(A[left],A[j]);
	return j;
}

void Quick_Sort(int A[], int left, int right) {
	if(left<right) {
		int p=Partition(A,left,right);
		Quick_Sort(A, left, p-1);
		Quick_Sort(A, p+1, right);
	}
	return;
}

//Vun dong
void Max_Heapify(int A[], int i, int n) {
	int largest;
	int left=2*i;
	int right=2*i+1;
	if(left<=n&&A[left]>A[i]) {
		largest=left;
	}
	else {
		largest=i;
	}
	if(right<=n&&A[right]>A[largest]) {
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

main() {    
	int A[500000];
    int i,n;      
    while(1) {
		printf("\n Nhap n:");
    	scanf("%d",&n);
    	for(int i=1;i<n;i++)
			A[i]=rand()&1000; 	
	
//		clock_t start1=clock();
//		Intertion_Sort(A, n);
//		clock_t finish1=clock();
//		double d1= (double)(finish1-start1)/ CLOCKS_PER_SEC;
//		printf("\n Thoi gian thuc hien thuat toan sap xep chen la:%.5f ", d1);
//		
//		clock_t start2=clock();
//		Bubblesort(A,n);
//		clock_t finish2=clock();
//		double d2= (double)(finish2-start2)/ CLOCKS_PER_SEC;
//		printf("\n Thoi gian thuc hien thuat toan sap xep noi bot la:%.5f ", d2);
	
		clock_t start3=clock();
		Sapxep(A,0,n-1);
		clock_t finish3=clock();
		double d3= (double)(finish3-start3)/ CLOCKS_PER_SEC;
		printf("\n Thoi gian thuc hien thuat toan sap xep tron la:%.5f ", d3);
	
		clock_t start4=clock();
		Quick_Sort(A,0,n-1);
		clock_t finish4=clock();
		double d4= (double)(finish4-start4)/ CLOCKS_PER_SEC;
		printf("\n Thoi gian thuc hien thuat toan sap xep nhanh la:%.5f ", d4);
	
//		clock_t start5=clock();
//		Heap_Sort(A,n);
//		clock_t finish5=clock();
//		double d5= (double)(finish5-start5)/ CLOCKS_PER_SEC;
//		printf("\n Thoi gian thuc hien thuat toan sap xep vun dong la:%.5f ", d5);
	}
}	
