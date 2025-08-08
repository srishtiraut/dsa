#include <iostream> 

using namespace std;

int subs(int index, int n, int arr[], int sum, int k) {
    
	if(index >= n ) {      
		if(sum==k){
    		return 1;
		}else return 0;
		
	}

	int l = subs(index+1, n, arr, sum+arr[index], k);
	

	int r = subs(index+1, n, arr, sum, k);
	
	return l+r;
}
int main() {
	int arr[] = {1,2,1};
	int n = 3;
	int count = subs(0, n, arr, 0, 2);
	cout<< count;
	return 0;
}