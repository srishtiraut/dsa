#include<iostream>
using namespace std;

void linearSearch(int a[], int n){
    int temp = -1;
    for (int i = 0; i < 5; i++){
        if (a[i] == n){
           cout<<"Found "<<n<<" at position no. "<<i<<endl;
           temp = 0;
           break;
        }
    }
        if (temp == -1){
            cout<<"Number does not exist."<<endl;
        }        
    }
    



int main(){
    int arr[] = {1,22,34,5,7};
    cout<<"Please enter the number you want to retrieve: "<<endl;
    int num;
    cin>>num;

    linearSearch(arr,num);

    return 0;
}