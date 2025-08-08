//https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/

#include <iostream>
using namespace std;

void printarray(int arr[], int n){
    for(int i=0;i<n; i++){
        cout<<arr[i]<<" ";
    }
}


int sort012(int arr[], int n){
    int c1 = 0, c2 = 0, c0 = 0, i = 0;
    // Count the number of 0s, 1s and 2s in the array
    while(i<n){
        if (arr[i] == 0){
            c0++;
        }else if (arr[i] == 1){
            c1++;
        }else if (arr[i] == 2){
            c2++;
        }
        i++;
    }

    i = 0;
     // Store all the 0s in the beginning
     while(c0 > 0){
         arr[i] = 0;
         i++;
         c0--;
     } //now store all 1s
     while(c1 > 0){
         arr[i] = 1;
         i++;
         c1--;
     }//now store all 2s
     while(c2 > 0){
         arr[i] = 2;
         i++;
         c2--;
     }
 printarray(arr,n);

}


int main(){

    int arr[] = {0,1,2,1,2,0,2,1,2,0,1,2,1,1,0,1,1,0,0};
    int n = sizeof(arr)/sizeof(arr[0]);

    sort012(arr,n);
   
    return 0;
}

/*OUTPUT:
C:\Users\SRISHTI\Desktop\DSA\450 questions>g++ 04-Sort-an-array-of-0s-1s-and-2s.cpp

C:\Users\SRISHTI\Desktop\DSA\450 questions>a
0 0 1 1 2 2 2
C:\Users\SRISHTI\Desktop\DSA\450 questions>g++ 04-Sort-an-array-of-0s-1s-and-2s.cpp

C:\Users\SRISHTI\Desktop\DSA\450 questions>a
0 0 0 0 0 0 1 1 1 1 1 1 1 1 2 2 2 2 2 
*/