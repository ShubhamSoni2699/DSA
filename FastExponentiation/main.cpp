#include <iostream>

using namespace std;

int fastExponentiation(int base ,  int power){
	if(power==0){ 
		return 1;
	}
	if(power==1){
		return base;
	}
	int ans = fastExponentiation(base,power/2);
	if(power&1){
		return base*ans*ans;
	}else{
		return ans*ans;
	}
}

int main(){
	cout<<"Enter Base and Its Power"<<endl;
	int base =0, power=0;
	cin>>base>>power;
	
	cout<<endl<<endl;
	
	int ans = fastExponentiation(base,power);
	cout<<ans<<endl;
	
	return 0;
}