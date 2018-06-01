#include<stdio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>

void Swap(int &a, int &b) {
	int tmp=a;
	a=b;
	b=tmp;
}
void Bubblesort(int A[], int n) {
	for(int i=0;i<n;i++)
    for(int j=n-1;j>=i;j--)
    if(A[j]>A[j-1])
    Swap(A[j],A[j-1]);
}
void Tron(int A[],int first, int mid, int last) {
	int i1=first, i2=mid;
	int j1=mid+1, j2=last;
	int k=i1, tA[100000];
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

void Bsearch(int A[],int x, int y) {
	int mid;
	mid=(x+y)/2;
	if(mid=y) {
		if (A[mid]=y) return mid;
		else return false;
	}
	if(y=A[mid]) return mid;
	else {
		if(y<A[mid]) return Bsearch(A[],x,mid-1);
		else return Bsearch(A[],mid+1,y)
	}
	
int main() {    
	int A[300000];
    int i,n;  
	printf("---------MERGE SORT VERSION-------"); 
	while(1) {
		printf("\n Nhap n:");
		scanf("%d",&n);
		for (i=0;i<n;i++)
			A[i]=rand()%999;   
		printf("\n Day so ban dau la:\n");
		for(i=0;i<n;i++)
		printf("%5d",A[i]);	       
		printf("\n\n Ket qua sau khi sap xep tang dan la:\n");
		clock_t start=clock();
		Bubblesort(A, n);
		clock_t finish=clock();
		double d= (double)(finish-start)/ CLOCKS_PER_SEC;
		for(i=0;i<n;i++)
		printf("%5d",A[i]);
		printf("Nhap so can tim="); scanf("%d",&t);
		Bsearch(A[],0,n);
		printf("\n\n Thoi gian thuc hien thuat toan sap xep tron la:%.5f ", d);
	}
}	

