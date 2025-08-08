#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void findFine(int arr[], int n, int date){
    int count = 0, fineTotal = 0;
    //traverse the loop
    // if(date%2 == 0){
    //     for(int i=0;i<n;i++){
    //         if(arr[i]%2 == 1){
    //             count++;
    //         }
    //     } 
    // }else{
    //     for(int i=0;i<n;i++){
    //         if(arr[i]%2 == 0){
    //             count++;
    //         }
    // }
    for(int i=0;i<n;i++){
     if (date%2 != 0 && arr[i]%2 == 0){
            count++;
        }else if (date%2 == 0 && arr[i]%2 != 0){
            count++;
        }else{
            continue;
        }}
//}

    fineTotal = count*250;
    cout<<fineTotal<<"  "<<count;

}

int main(){
    int arr[] = {4, 13,17,1, 2,6,8,12};
    int date = 2;
    int n = sizeof(arr)/sizeof(arr[0]);
    findFine(arr,n,date);
    return 0;
}

/*        if (date%2 != 0 && arr[i]%2 == 0){
            count++;
        }else if (date%2 == 0 && arr[i]%2 != 0){
            count++;
        }else{
            continue;
        }*/