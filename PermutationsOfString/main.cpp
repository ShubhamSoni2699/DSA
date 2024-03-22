#include <iostream>
#include <vector>
using namespace std;

void permutations(string &input , vector<string>&ans , int index , int &size){
	if(index>=size){
		ans.push_back(input);
		return;
	}
	
	for(int i = index ; i<size ; i++){
		swap(input[index],input[i]);
		permutations(input,ans,index+1,size);
		swap(input[index],input[i]);
	}
	
}

int main(){
	cout<<"Enter string here:"<<endl;
	string input = "";
	cin>>input;
	
	cout<<endl;
	
	vector<string>ans;
	int size = input.size();
	
	permutations(input,ans,0,size);
	
	int ansSize = ans.size();
	
	cout<<"All permutations are:"<<endl;
	for(int i = 0 ; i<ansSize ; i++){
		cout<<ans[i]<<" ";
	}
	
	return 0;
}