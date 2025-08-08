#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Interval{
    int start, end;
};

// Function used in sort
bool compare(Interval a, Interval b){
    return a.start < b.start;
}

//merge function
void mergeIntervals(Interval arr[], int n){
    sort(arr, arr+n, compare); // Sort Intervals in increasing order of start time
    int index = 0; // Stores index of last element in output array (modified arr[])
     
    // Traverse all input Intervals
    //intervals = [[1,3],[2,6],[8,10],[15,18]]
    for(int i=1;i<n;i++){
        if(arr[index].end > arr[i].start){
            //merge arr[index] with arr[i]
            arr[index].start = min(arr[index].start, arr[i].start);
            arr[index].end = max(arr[index].end,arr[i].end); 
            //[[1,6], [8,10], [15,18]]
        }else{
            index++;
            arr[index] = arr[i];
        }
    }
  cout << "The Merged Intervals are: ";
  for(int i=0; i<=index;i++){
      cout<<"["<<arr[i].start<<", "<< arr[i].end<<"] ";
  }

}

int main(){
    Interval arr[] = {{1,3}, {8,10}, {2,6}, {15,18}}; 
    int n = sizeof(arr)/sizeof(arr[0]);

    mergeIntervals(arr, n);
    return 0;

}

/*
C:\Users\SRISHTI\Desktop\DSA\450 questions>g++ 13-Merge-intervals.cpp

C:\Users\SRISHTI\Desktop\DSA\450 questions>a
The Merged Intervals are: [1, 6] [8, 10] [15, 18] 
*/