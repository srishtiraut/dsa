//https://www.tutorialcup.com/interview/array/minimize-the-maximum-difference-between-the-heights.htm

#include<iostream>
#include<algorithm>
using namespace std;

int getMinimizeHeights(int arr[], int n, int k){
    //1. Sort the given array.
    sort(arr, arr+n);
    //2. Set the diff to the difference between the least element of the array and the first element of an array.
    int diff = arr[n-1] - arr[0];
    //3. Set minimum to the first element of array + k and maximum to last element - k of the array.
    int minimum = arr[0]+k;
    int maximum = arr[n-1]-k;
    int temp = 0;
    if (minimum > maximum)
    {
        temp = minimum;
        minimum = maximum;
        maximum = temp;
    }
    // 4. Traverse the array from i=1 to i<n-1(one less than the length of the array).
    for(int i=0; i<n; i++){
        //   1. Set difference to arr[i]-k.
        int difference = arr[i] - k;
        //   2. Set sum to arr[i]+k.
        int sum = arr[i] + k;
        //   3. Check if the difference is greater than equal to minimum or sum is less than or equal to maximum.
        if(difference >= minimum || sum <= maximum){
            continue; //     1. If true, then continue and skip this traversal.
        } 
        //   4. Check if maximum-difference is less than or equal to sum-minimum.
        if(maximum - difference <= sum - minimum){
            minimum = difference; //     1. If true, then update minimum to difference.
        }else{
            //   5. Else set the maximum to sum.
            maximum = sum;
        }
        // 5. Return the minimum between the diff and maximum-minimum.
        return min(diff, maximum-minimum);
    }

}

int main()
{
    int arr[] = {7,12,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 8;
    cout << getMinimizeHeights(arr, n, k);
    return 0;
}