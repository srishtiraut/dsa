#include <bits/stdc++.h>
using namespace std;

int getInvCount(int arr[], int n){
    int count = 0;
     //Traverse through the array, and for every index, find the number of smaller elements on its right side of the array.
    for(int i=0; i<n-1;i++){
         for(int j=i+1; j<n; j++){
          if (arr[i] > arr[j] && i < j ){
            count++;
          }
        }
    }
     //This can be done using a nested loop. Sum up the counts for all index in the array and print the sum.
return count;
}

int main()
{
    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << " Number of inversions are "
         << getInvCount(arr, n);
    return 0;
}


/*C:\Users\SRISHTI\Desktop\DSA\450 questions>g++ 15-Count-inversion.cpp

C:\Users\SRISHTI\Desktop\DSA\450 questions>a
 Number of inversions are 6
 
 Time Complexity: O(n^2), Two nested loops are needed to traverse the array from start to end, so the Time complexity is O(n^2)
 */