#include<iostream>
using namespace std;
void merge(int A[],int mid,int low,int high)
{
int i,j,k,B[25];
i=low;
j=mid+1;
k=low;
while(i<=mid && j<=high)
{
if(A[i]<A[j])
{
B[k]=A[i];
i++;
k++;
}
else
{
 B[k]=A[j];
 j++;
 k++;
}
}
while(i<=mid)
{
 B[k]=A[i];
 k++;
 i++;
}
while(j<=high)
{
 B[k]=A[j];
 k++;
 j++;
 }
for(i=low;i<=high;i++)
{
 A[i]=B[i];
}
}
void msort(int A[],int low,int high)
{
int mid;
if(low<high)
{
 mid=(low+high)/2;
 msort(A,low,mid);
 msort(A,mid+1,high);
 merge(A,mid,low,high);
}
}
void printarr(int *A,int n)
{
int i;
for(i=0;i<n;i++)
{
cout<<A[i]<<"\t";
}
cout<<"\n";
}
int main()
{
int A[]={3,5,2,13,12,10,3};
int n=7;

printarr(A,n);
msort(A,0,n-1);
cout<<"---------------After MergeSort---------------\n";
printarr(A,n);
}
