#include <iostream>

using namespace std;

void insertionSort(int *arr , int size,int len){
	if(len==size){
		return;
	}
	int temp = arr[len];
	
	int index = 0;
	int i = len-1;
	while(i>=0 && arr[i]>temp){
		if(arr[i]<temp){
			break;
		}
		i--;
	}
	
	index = i+1;
	
	for(int j = len-1 ; j>=index ; j--){
		arr[j+1] = arr[j];
	}
	
	arr[index] = temp;
	
	insertionSort(arr,size,len+1);
	
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
	
	insertionSort(arr,size,1);
	
	cout<<endl<<endl;
	
	cout<<"Sorted array:"<<endl;
	
	for(int i = 0; i<size ; i++){
		cout<<arr[i]<<" ";
	}
	delete []arr;
	return 0;
}