/*Given: three arrays sorted in increasing order. 
To Find: Which elements are common in all three arrays.
My approach: Traverse all arrays one by one
if arr[i] == arr[j] == arr[k] then output that arr[i]
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int commonElements(int A[], int B[], int C[], int n1,int n2, int n3){
    int commonsArray[] = {}; //empty array for collecting commons
    for(int i = 0; i<n1; i++){ 
        for(int j = 0; j<n2; j++){ 
            for(int k = 0; k<n3; k++){    
                if(A[i] == B[j] == C[k]){
                    //insert this arr[i] into commonsArray
                  cout<< A[i];
                }
            }  
        }
       }
    //returns an array containing the common element present in all the 3 arrays in sorted order. 
}

int main(){
    int A[] = {1, 5, 10, 20, 40, 80};
    int n1 = 6;
    int B[] = {6, 7, 20, 80, 100};
    int n2 = 5;
    int C[] = {3, 4, 15, 20, 30, 70, 80, 120};
    int n3 = 8;
    
    commonElements(A,B,C,n1,n2,n3);

    return 0;
}