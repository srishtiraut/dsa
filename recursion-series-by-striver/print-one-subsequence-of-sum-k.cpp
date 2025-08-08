#include <iostream>
#include <vector>
using namespace std;

bool subs(int index, vector<int> ds, int n, int arr[], int sum, int k) {
    if (index >= n) {
        if (sum == k) {
            if (ds.size() == 0) {
                cout << "{}";
            }
            for (auto it : ds) {
                cout << it << " ";
            }
            cout << endl;
            return true; // Found one!
        }
        return false; // Not found
    }
    // Pick
    ds.push_back(arr[index]);
    if (subs(index + 1, ds, n, arr, sum + arr[index], k)) return true;

    // Not pick
    ds.pop_back();
    if (subs(index + 1, ds, n, arr, sum, k)) return true;

    return false; // No valid subsequence in this path
}

int main() {
    int arr[] = {1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> ds;
    subs(0, ds, n, arr, 0, 2);
    return 0;
}
