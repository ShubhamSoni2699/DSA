#include <iostream>
#include "nStacksInAnArray.cpp"
using namespace std;

int main(){
	cout<<"Enter size of the container and No. of the stacks :"<<endl;
	int size = 0 , noStacks = 0;
	cin>>size;
	cin>>noStacks;
	
	
	nStacks<int> nS(size , noStacks);
	
	nS.push(1,1);
	nS.push(1,2);
	nS.push(2,1);
	nS.push(1,1);
	
	
	
	
	
	
	
	
	
	return 0;
}