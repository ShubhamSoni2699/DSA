#include <iostream>

using namespace std;

int main()
{   int row ;
    cout<<"Enter no of rows"<<endl;
    cin>>row;
    int **array = new int*[row];

    int *col = new int [row];

    cout<<"Enter size of the cols"<<endl;
    for(int i= 0; i<row ; i++){
        cin>>col[i];
    }

    for(int i = 0 ; i<row ; i++){
        array[i] = new int [col[i]];
    }

    cout<<"enter elements here: "<<endl;
    for(int i = 0 ; i<row ; i++){
        for(int j = 0; j<col[i];j++){
            cin>>array[i][j];
        }
    }
	cout<<endl<<endl;
    for(int i = 0 ; i<row ; i++){
        for(int j = 0; j<col[i];j++){
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
