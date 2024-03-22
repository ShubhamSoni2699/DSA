#include <iostream>

using namespace std;

void selectionSort(int *arr , int size){
	if(size == 1){
		return;
	}
	
	int miniIndex = 0;
	for(int i = 1 ; i<size ; i++){
		if(arr[i]<arr[miniIndex]){
			miniIndex = i;
		}
	}
	swap(arr[0],arr[miniIndex]);
	selectionSort(arr+1,size-1);
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
	
	selectionSort(arr,size);
	
	cout<<endl<<endl;
	
	cout<<"Sorted array:"<<endl;
	
	for(int i = 0; i<size ; i++){
		cout<<arr[i]<<" ";
	}
	
	delete []arr;
	
	return 0;
}