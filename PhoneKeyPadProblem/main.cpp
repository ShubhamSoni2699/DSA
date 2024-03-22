#include <iostream>
#include <vector>
using namespace std;

void solve(string &input,vector<string>&maping,vector<string>&ans , string temp , int index , int &size){
	if(index>=size){
		ans.push_back(temp);
		return;
	}
	int digit = input[index] - '0';
	string s = maping[digit];
	int sSize = s.size();
	
	for(int i = 0  ; i<sSize ; i++){
		temp.push_back(s[i]);
		solve(input,maping,ans,temp,index+1,size);
		temp.pop_back();
	}
}

int main(){
	vector<string>maping{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	
	cout<<"Enter input digits :"<<endl;
	string input = "";
	cin>>input;
	vector<string>ans;
	int size = input.size();
	
	cout<<endl;
	
	solve(input,maping,ans,"",0,size);
	
	int ansSize = ans.size();
	
	for(int i = 0 ; i<ansSize ; i++){
		cout<<ans[i]<<" ";
	}
	
	return 0;
}