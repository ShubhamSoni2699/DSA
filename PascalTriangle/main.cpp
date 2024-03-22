#include <iostream>
#include <vector>
using namespace std;

int sum(vector<vector<int>>&ans , int i , int j,int currentRow){
	if(i==-1){
		return ans[currentRow-1][j];
	}
	if(j==currentRow){
		return ans[currentRow-1][i];
	}
	return ans[currentRow-1][i] + ans[currentRow-1][j];
}

void pascalTriangle(int row , vector<vector<int>>&ans, int currentRow){
	if(currentRow>row){
		return;
	}
	vector<int>temp(currentRow+1,0); 
	for(int i = 0 ; i<=currentRow ; i++){
		int addition = sum(ans,i-1,i,currentRow);
		temp[i]=addition;
	}
	ans.push_back(temp);
	pascalTriangle(row,ans,currentRow+1);
}

int main(){
	
	int n = 0;
	cout<<"Enter the row no :"<<endl;
	cin>>n;
	
	vector<vector<int>>ans;
	ans.push_back({1});
	ans.push_back({1,1});
	
	pascalTriangle(n-1,ans,2);
	
	for(int i = 0; i<n ; i++){
		int sizeCol = ans[i].size();
		for(int k = 0 ; k<n-i-1 ; k++){
			cout<<" ";
		}
		for(int j = 0 ; j<sizeCol ; j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}