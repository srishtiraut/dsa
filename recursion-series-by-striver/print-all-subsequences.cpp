#include <iostream> 
#include <vector> 
#include <bits/stdc++.h> 
using namespace std;
void subs(int index, vector<int> ds, int n, int arr[], int sum, int k) {
	if(index >= n and sum==k ) {       //print ds
		if(ds.size()==0) {
			cout<<"{}";
		}
		for(auto it: ds) {
			cout<<it<<" ";
		}
		cout<<endl;
		return;
	}
	ds.push_back(arr[index]);
	sum  = accumulate(ds.begin(), ds.end(), 1);
	subs(index+1, ds, n, arr, sum, k);
	ds.pop_back();
	sum  = accumulate(ds.begin(), ds.end(), 1);
	subs(index+1, ds, n, arr, sum, k);
}
int main() {
	int arr[] = {1,2,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	vector<int> ds;
	subs(0, ds, n, arr, 0, 2);
	return 0;
}