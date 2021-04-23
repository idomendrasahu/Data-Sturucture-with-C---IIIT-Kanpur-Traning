#include<stdio.h>
void Sort(int arr[],int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
int main(){
	int arr[]={10,40,30,20};
	int n=sizeof(arr)/sizeof(arr[0]),i;
	Sort(arr,n);
	printf("Sorted Array ->\n");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
