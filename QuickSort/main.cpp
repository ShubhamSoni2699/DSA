#include <iostream>

using namespace std;

int partition(int *arr , int s, int e ){
	int ele = arr[s];
	int count = 0;
	
	for(int i = s+1 ; i<=e ; i++ ){
		if(arr[i]<ele){
			count++;
		}
	}
	int pos = s+count;
	
	swap(arr[s],arr[pos]);
	
	int i = s;
	int j = e;
	
	while(i<pos && j>pos){
		while(arr[i]<ele && i<pos){
			i++;
		}
		while(arr[j]>=ele && j>pos){
			j--;
		}
		swap(arr[i++],arr[j--]);
	}
	
	return pos;
}

void quickSort(int *arr , int s , int e){
	if(s>=e){
		return;
	}
	int pos = partition(arr, s, e);
	quickSort(arr,s,pos-1);
	quickSort(arr,pos+1,e);
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
	
	cout<<endl<<endl;
	
	quickSort(arr,0,size-1);
	cout<<"After Quick Sorting :"<<endl;
	
	for(int i = 0; i<size ; i++){
		cout<<arr[i]<<" ";
	}
	
	return 0;
}