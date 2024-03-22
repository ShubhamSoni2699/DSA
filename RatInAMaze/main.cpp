#include <iostream>
#include <vector>
using namespace std;

void solveMaze(int *maze , vector<string>&ans , string output , int rowIndex , int colIndex , int &row , int &col ){
	if(rowIndex==row-1 && colIndex==col-1){
		ans.push_back(output);
		return;
	}
	if(colIndex==col || rowIndex==row){
		return;
	}
	if(colIndex < 0 || rowIndex < 0){
		return;
	}
	if(*(maze+rowIndex*col+colIndex)==0){
		return;
	}
	
	*(maze + rowIndex*col + colIndex) = 0;
	output.push_back('D');
	solveMaze(maze ,ans,output,rowIndex+1,colIndex,row,col);
	output.pop_back();
	
	output.push_back('R');
	solveMaze(maze ,ans,output,rowIndex,colIndex+1,row,col);
	output.pop_back();
	
	output.push_back('U');
	solveMaze(maze ,ans,output,rowIndex-1,colIndex,row,col);
	output.pop_back();
	
	output.push_back('L');
	solveMaze(maze ,ans,output,rowIndex,colIndex-1,row,col);
	output.pop_back();
	
	*(maze + rowIndex*col + colIndex) = 1;
	
}

int main(){
	cout<<"Enter no. of rows and cols"<<endl;
	int row = 0;
	int col = 0;
	
	cin>>row;
	cin>>col;
	
	int size = row*col;
	
	int *maze = new int[size];
	
	cout<<"Enter values in the maze"<<endl;
	
	for(int i = 0 ; i<row ; i++){
		for(int j = 0 ; j<col ; j++){
			cin>>*(maze+i*col+j);
		}
	}
	
	
	vector<string>ans;
	
	if(*(maze+(size-1))==0){
		cout<<"-1"<<endl;
	}else{
		
		solveMaze(maze,ans,"",0,0,row,col);
	
		int ansSize = ans.size();
		
		cout<<"All possible paths are :"<<endl;
		
		if(ans.size()==0){
			cout<<"-1"<<endl;
		}else{
			for(int i = 0 ; i<ansSize ; i++){
				cout<<ans[i]<<" ";
			}
		}
	
		
	}
	
	delete []maze;
	return 0;
}