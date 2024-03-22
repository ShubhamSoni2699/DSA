#include <iostream>

using namespace std;

void merge(int *arr , int s , int mid , int e){
	int size = e-s+1;
	int *cp = new int [size];
	
	int i = s;
	int j = mid+1;
	int index = 0;
	
	while(i<=mid && j<=e){
		if(arr[i]<=arr[j]){
			cp[index++] = arr[i++];
		}else{
			cp[index++] = arr[j++];
		}
	}
	
	while(i<=mid){
		cp[index++] = arr[i++];
	}
	while(j<=e){
		cp[index++] = arr[j++];
	}
	
	for(int i = s, j = 0; i<=e ; i++,j++){
		arr[i] = cp[j];
	}
	
	delete []cp;
	
}

void mergeSort(int *arr , int s , int e){
	
	if(s>=e){
		return;
	}
	
	int mid = s+(e-s)/2;
	
	mergeSort(arr,s,mid);
	mergeSort(arr,mid+1,e);
	
	merge(arr,s,mid,e);
}

int main(){
	cout<<"Enter size of the array"<<endl;
	int size = 0;
	cin>>size;
	
	cout<<"Enter elements in the array"<<endl;
	int *arr = new int[size];
	for(int i = 0; i<size ; i++){
		cin>>arr[i];
	}
	
	mergeSort(arr,0,size-1);
	
	cout<<endl<<endl;
	
	cout<<"After merge sorting:"<<endl;
	
	for(int i = 0; i<size ; i++){
		cout<<arr[i]<<" ";
	}
	
	delete []arr;
	return 0;
}