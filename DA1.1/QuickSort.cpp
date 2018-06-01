#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
/*void docfile(int A[], int &n)
{
	FILE *f;
	f=fopen("Mangtest.txt","r");
	fscanf(f,"%d",&n);    
	for(int i=0;i<n;i++)
	fscanf(f,"%d",&A[i]);
	fclose(f);   
}*/
void Swap(int &x, int &y) {
	int tmp=x;
	x=y;
	y=tmp;
	return;
}
void Bubblesort(int A[], int n) {
	for(int i=0;i<n;i++)
    for(int j=n-1;j>=i;j--)
    if(A[j]>A[j-1])
    Swap(A[j],A[j-1]);
}

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
main() {    
	int A[100000];
    int i,n;
    printf("---------QUICK SORT VERSION-------");
	while(1) {      
		printf("\n Nhap n:");
		scanf("%d",&n);
		for (i=0;i<n;i++)
			A[i]=rand()%999;
		printf("\n Day so ban dau la:\n");
		for(int i=0;i<n;i++)
			printf("%5d",A[i]);	       
		printf("\n\n Ket qua sau khi sap xep tang dan la:\n");
		clock_t start=clock();
		Bubblesort(A, n);
		clock_t finish=clock();
		double d= (double)(finish-start)/ CLOCKS_PER_SEC;
		for(int i=0;i<n;i++)
			printf("%5d",A[i]);
		printf("\n\n Thoi gian thuc hien thuat toan quick sort la:%.5f ", d);
	}
}	
