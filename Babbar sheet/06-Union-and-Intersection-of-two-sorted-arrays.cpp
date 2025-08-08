#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int unionOfaAndb(int a[], int b[], int size_a, int size_b){
    int i = 0, j = 0;   
    while(i<size_a && j< size_b){

        if(a[i] < b[j]){        //If arr1[i] is smaller than arr2[j] then print arr1[i] and increment i. 
            cout << a[i++] << " ";
        }else if(a[i] > b[j]){     //If arr1[i] is greater than arr2[j] then print arr2[j] and increment j. 
            cout << b[j++] << " ";
        }else{  //If both are same then print any of them and increment both i and j.
            cout << a[i] << " ";
            i++;
            j++;
        }   
    }
    //Print remaining elements of the larger array.
    while(i < size_a){
         cout << a[i++] << " ";
    }
    while(j < size_b){
         cout << b[j++] << " ";
    }
cout<<endl;
}

int intersectionOfaAndb(int a[], int b[], int size_a, int size_b){
    int i = 0, j = 0;
    while(i<size_a && j<size_b){
        if(a[i]<b[j]){
        i++;
    }else if(a[i]>b[j]){
        j++;
    }else if(a[i] == b[j]){
        cout << a[i] << " ";
        i++;
        j++;
    }
    }
}

int main(){
    int a[] = {1,2,3,4,5,6,33,47,55,85,330,787,6562};
    int b[] = {2,4,5,6,90,6562};

    int size_a = sizeof(a)/sizeof(a[0]);
    int size_b = sizeof(b)/sizeof(b[0]);

    unionOfaAndb(a, b, size_a, size_b);
    intersectionOfaAndb(a, b, size_a, size_b);

}

/* OUTPUT:

C:\Users\SRISHTI\Desktop\DSA\450 questions>a
1 2 3 4 5 6 90 
2 4 5
C:\Users\SRISHTI\Desktop\DSA\450 questions>g++ 06-Union-and-Intersection-of-two-sorted-arrays.cpp

C:\Users\SRISHTI\Desktop\DSA\450 questions>a
1 2 3 4 5 6 33 47 55 85 90 330 787 6562 
2 4 5 6 6562

*/