// Best time to buy and Sell stock

#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

int maxProfit(int arr[], int sizeOfArray){
//find cheapest price from prices array
    // initialize the 1st element as cheapestPrice
    // int cheapestPrice = arr[0];
    // // traverse the array
    // for(int i=0; i<=sizeOfArray;i++){
    //     if(arr[i+1]<arr[i]){
    //         cheapestPrice = arr[i+1]; 
    //     }else{
    //         continue;
    //     }
    //}
//forget anything ever existed before this cheapest price 
// consider only the array AFTER this cheapest price
//from this remaining array find the costliest price
//return the difference between costliest price & cheapest price


//solved instead using Kadane'e algorithm
int maxSoFar = 0, maxCur = 0;
for(int i = 1; i < sizeOfArray; i++) {
            maxCur = max(0, maxCur += arr[i] - arr[i-1]);
            maxSoFar = max(maxCur, maxSoFar);
        }
        cout<< maxSoFar;
}

int main(){
    int prices[] = {7,6,4,3,1}; //initialise a 1D array named prices
    int size = sizeof(prices)/sizeof(prices[0]);

    return maxProfit(prices, size);  //call the maxProfit() function on it
}