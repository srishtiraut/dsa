/*
Print this
* * * *
* * * *
* * * *
* * * *
*/

#include<iostream>
using namespace std;

int main(){
    int starsInOneRow;
    cin>>starsInOneRow;

    int row = 1;

    while(row<=starsInOneRow){
        int column = 1;
        while(column<=starsInOneRow){
            cout<<"*";
            column++;
        }
        cout<<endl;
        row++;
        
    }
}