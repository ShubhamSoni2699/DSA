#include <iostream>
#include <vector>
using namespace std;

void subsequence(string &input, vector<string>&ans , string temp , int index , int &size ){
	if(index>=size){
		if(temp==""){
			return;
		}
		ans.push_back(temp);
		return;
	}
	subsequence(input,ans,temp,index+1,size);
	temp.push_back(input[index]);
	subsequence(input,ans,temp,index+1,size);
}

int main(){
	
	cout<<"Enter the string"<<endl;
	
	string input = "";
	
	cin>>input;
	
	vector<string>ans;
	string temp;
	int size = input.size();
	
	subsequence(input,ans,temp,0,size);

	int ansSize = ans.size();
	
	for(int i = 0; i<ansSize ; i++){
		cout<<"[";
		if(i==ansSize-1){
			cout<<ans[i];
		}else{
			cout<<ans[i]<<" ";
		}
		cout<<"] ";
	}
	
	
	
	
	return 0;
}