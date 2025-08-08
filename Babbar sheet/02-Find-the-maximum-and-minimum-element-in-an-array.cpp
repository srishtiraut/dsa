//https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/


#include <iostream>
using namespace std;

struct Pair{
    int min;
    int max;
};

//declare a getMinMax() function belonging to the struct named Pair
struct Pair getMinMax(int arr[], int n){

    struct Pair minmax;     //minmax is a variable of type struct Pair.
    
        // If there is only one element, then return it as min and max both
        if(n == 1){    //= (Assignment)operator and == (Equal to) operator
            minmax.min = arr[0];
            minmax.max = arr[0];
        }else{       
            // If there are more than one elements, then initialize min and max
            if(arr[0]>arr[1]){
                minmax.min = arr[1];
                minmax.max = arr[0]; 
            }else{
                minmax.min = arr[0];
                minmax.max = arr[1];
            }

        }

        //actual code to find the min and max elements from input array
        for(int i = 0; i<n; i++){
            if (arr[i] < minmax.min){
                minmax.min = arr[i];
            }else if (arr[i] > minmax.max){
                minmax.max = arr[i];
            }
        }
        return minmax;

       
}

int main(){
    int arr[] = {1000, 11, 445,
                  1, 330, 3000};
    int arr_size = 6;

    struct Pair minmax = getMinMax(arr, arr_size);   //minmax is a variable of type struct Pair. getMinMax() function returns 2 values: 1 each for
                                                     //the min and max elements found in arr
    
    cout<<"Minimum element in arr = "<<minmax.min<<endl;
    cout<<"Maximum element in arr = "<<minmax.max<<endl;


    return 0;
    

}

//Time Complexity: O(n)
//OUTPUT:
/*
C:\Users\SRISHTI\Desktop\DSA\450 questions>g++ 02-Find-the-maximum-and-minimum-element-in-an-array.cpp

C:\Users\SRISHTI\Desktop\DSA\450 questions>a
Minimum element in arr = 1
Maximum element in arr = 3000

C:\Users\SRISHTI\Desktop\DSA\450 questions>g++ 02-Find-the-maximum-and-minimum-element-in-an-array.cpp

C:\Users\SRISHTI\Desktop\DSA\450 questions>a
Minimum element in arr = 1
Maximum element in arr = 66666






*/