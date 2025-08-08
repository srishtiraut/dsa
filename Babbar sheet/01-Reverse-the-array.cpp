//https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/

#include <bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int start, int end){
    while(start<end){                   //without the while loop the output is ----> 923456781
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    start++;
    end--;
}
}
void printArray(int array[], int size){
    for(int i = 0; i<size; i++){
        cout<<array[i]<<endl;
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,0};
    //find the number of elements in arr
    int n = sizeof(arr)/sizeof(arr[0]); //sizeof(arr) returns the entire quantity of memory occupied by arr
                                       //sizeof(arr[0]) returns only the quantity of memory occupied by a single element of arr, say 0th element
                                       //thus n contains the total number of elements that live inside arr

    reverseArray(arr, 0, n-1);
    printArray(arr,n);

string stringer = "SrishtiR";
int m = sizeof(stringer)/sizeof(stringer[0]);
cout<<m;
    // reverseArray(stringer, 0, m-1);
    // printArray(stringer, m);
}

//i learned: 
//how to traverse an array
//how to print elements of an array
//how to swap numbers
/*C:\Users\SRISHTI\Desktop\DSA\450 questions>g++ Reverse-the-array.cpp

C:\Users\SRISHTI\Desktop\DSA\450 questions>a
0
9
8
7
6
5
4
3
2
1*/