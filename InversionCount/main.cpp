#include <iostream>

using namespace std;

int merge(int *arr , int s, int e ){
	int mid = s+((e-s)>>1);
	int inv = 0;
	int len1 = mid-s+1;
	int len2 = e-mid;
	
	int *first = new int[len1];
	int *second = new int[len2];
	
	int mainArrayIndex=s;
	for(int i=0;i<len1;i++){
		first[i]=arr[mainArrayIndex++];
	}
	
	mainArrayIndex=mid+1;
	for(int i=0;i<len2;i++){
		second[i]=arr[mainArrayIndex++];
    }
	
	int index1=0;
    int index2=0;
	
    mainArrayIndex=s;
    while(index1<len1 && index2<len2){
		if(first[index1]<second[index2]){
            arr[mainArrayIndex++]=first[index1++];
        }
		else{
            arr[mainArrayIndex++]=second[index2++];
            inv+=len1-index1;
        }
    }
    while(index1<len1)
    {
        arr[mainArrayIndex++]=first[index1++];
    }
    while(index2<len2)
    {
        arr[mainArrayIndex++]=second[index2++];
    }
    delete[] first;
    delete[] second;

    return inv;
}

int countInversions(int *arr , int s , int e){
	int inv = 0;
	if(s>=e){
		return inv;
	}
	int mid = s+((e-s)>>1);
	inv+=countInversions(arr,s,mid);
	inv+=countInversions(arr,mid+1,e);
	inv+=merge(arr,s,e);
	return inv;
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
	
	cout<<"No. of inversions are"<<endl;
	int inversion = countInversions(arr,0,size-1);
	cout<<inversion<<endl;
	
	
	return 0;
}