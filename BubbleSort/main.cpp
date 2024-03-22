#include <iostream>

using namespace std;

void bubbleSort(int *arr , int size , bool swaped){
	if(size==1){
		return;
	}
	int i = 0;
	int j = 1;
	
	while(j<size){
		if(arr[i]>arr[j]){
			swap(arr[i],arr[j]);
			swaped = true;
		}
		i++;
		j++;
	}
	if(swaped==false){
		return;
	}
	bubbleSort(arr,size-1,swaped);
	
}

int main(){
	cout<<"Enter size of the array"<<endl;
	int size = 0;
	cin>>size;
	
	int *arr = new int[size];
	
	cout<<"Enter Elements in the array"<<endl;
	for(int i = 0; i<size ; i++){
		cin>>arr[i];
	}
	
	cout<<endl<<endl;
	
	bubbleSort(arr,size,false);
	
	for(int i = 0; i<size ; i++){
		cout<<arr[i]<<" ";
	}
	
	delete []arr;
	return 0;
}