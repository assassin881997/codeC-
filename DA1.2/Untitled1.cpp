#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <iomanip>

int A[100][100],n;
void docfile(int A[][], int &n)
{
	FILE *f;
	f=fopen("test.txt","r");
	fscanf(f,"%d",&n);    
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		fscanf(f,"\n%d",&A[i][j]);
	fclose(f);   
}
main() {
	docfile(A,n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		printf("%d",&A[i]);
}
