#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

unordered_map<char, bool> isOperator = {   
  {'+', true}, 
  {'-', true}, 
  {'*', true},
  {'/', true},
  {'(', true}, 
  {'^', true},
  {')', true}
}; 

unordered_map<char, int> operatorPrecedance = {   
  {'(', 0}, 
  {'^', 1}, 
  {'*', 2},
  {'/', 2},
  {'+', 3},
  {'-', 3}
};


string addSpaceBetween(string & s){
	int size = s.size();
	string ans = "";
	
	for(int i = 0 , j=i+1 ; j<size ; i++,j++){
		ans.push_back(s[i]);
		if(isOperator[s[i]] || isOperator[s[j]]){
			ans.push_back(' ');
		}
	}
	ans.push_back(s[size-1]);
	return ans;
}


string postFix(string &s){
	string ans = "";
	stack<char>st;
	
	int size = s.size();
	
	for(int i = 0 ; i<size ; i++){
		if(isOperator[s[i]]){
			
			if( s[i]!=')' && (st.empty() ||  st.top()=='('  || operatorPrecedance[st.top()] > operatorPrecedance[s[i]]) ){
				st.push(s[i++]);
				continue;
			}
			else if( s[i]==')'  || operatorPrecedance[st.top()] < operatorPrecedance[s[i]] ){
				while(!st.empty() && st.top()!='('){
					char opr = st.top();
					st.pop();
					//ans.push_back(' ');
					ans.push_back(opr);
				}
				if(s[i]==')'){
					st.pop();
					i++;
					continue;
				}else{
					st.push(s[i++]);
				}
			}else{
				char op = st.top();
				st.pop();
				//ans.push_back(' ');
				ans.push_back(op);
				st.push(s[i++]);
			}
			
		}else{
			ans.push_back(s[i]);
		}
	}
	int tempSize = ans.size();
	if(!isOperator[ans[tempSize-1]]){
		ans.push_back(' ');
	}
	while(!st.empty()){
		char opr = st.top();
		st.pop();
		//ans.push_back(' ');
		ans.push_back(opr);
	}
	
	return ans;
}

int cal(int left , int right , char op){
	if(op=='+'){
		return left+right;
	}else if(op=='-'){
		return left-right;
	}else if(op=='*'){
		return left*right;
	}else if(op=='/'){
		return left/right;
	}
	return -1;
};


int  calculate(string &s){
	string ans = "";
	int size = s.size();
	int value = 0;
	
	stack<int>st;
	
	for(int i = 0 ; i<size ; i++){
		if(s[i]==' '){
			st.push(value);
			value = 0;
		}else if(isOperator[s[i]]){
			char op = s[i];
			int right = st.top();
			st.pop();
			int left = st.top();
			st.pop();
			
			int ans = cal(left,right,op);
			st.push(ans);
		}else{
			value = value*10 + s[i] - '0';
		}
	}
	
	return st.top();
};

int main(){
	string input = "1000-(200*4/2)";
	
	string output = addSpaceBetween(input);
	cout<<output<<endl;
	
	string postForm = postFix(output);
	cout<<postForm<<endl;
	
	int ans = calculate(postForm);
	
	cout<<ans<<endl;
	return 0;
}