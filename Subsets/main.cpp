#include <iostream>
#include <vector>
using namespace std;

void subsets(vector<int>&arr , int index , vector<vector<int>>&ans,vector<int>temp ,int size){
	if(index==size){
		ans.push_back(temp);
		return;
	}
	subsets(arr,index+1,ans,temp,size);
	temp.push_back(arr[index]);
	subsets(arr,index+1,ans,temp,size);
}

int main(){
	cout<<"Enter size of the array"<<endl;
	int size = 0;
	cin>>size;
	
	cout<<"Enter elements in the array"<<endl;
	vector<int> arr(size,0);
	for(int i = 0; i<size ; i++){
		cin>>arr[i];
	}
	
	vector<int> temp;
	vector<vector<int>>ans;
	
	subsets(arr,0,ans,temp,size);
	
	
	int ansSize = ans.size();
	
	for(int i = 0 ; i<ansSize ; i++){
		int tempSize = ans[i].size();
		cout<<"[";
		for(int j = 0 ; j<tempSize ; j++){
			if(j==tempSize-1){
				cout<<ans[i][j];
			}else{
				cout<<ans[i][j]<<" ";
			}
		}
		cout<<"] ";
	}
	
	return 0;
}