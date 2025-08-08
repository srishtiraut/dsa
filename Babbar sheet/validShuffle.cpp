#include <bits/stdc++.h>
using namespace std;
 
bool validShuffle(string str1, string str2, string shuffle)
{   
    int n1 = str1.length();
    int n2 = str2.length();
    int n3 = n1+n2;

    int n = shuffle.size();

    if(n!=n3){
        return false;
    }

    //use an unordered map to track frequency of each character.
    unordered_map<int, int> freq;

    //record count of each character in str1 and str2
    for(int i=0; i<n1; i++){
        freq[str1[i]]++;
    }
    for(int i=0; i<n2; i++){
        freq[str2[i]]++;
    }
    //traverse on the string shuffle and search for each character in hashmap
    for(int i=0; i<n; i++){
        if(freq.find(shuffle[i]) != freq.end()){ //  if found continue to traverse
            freq[shuffle[i]]--;
        }else{ //  else return false
            return false;
        }
    }
    return true;
   
}
 
// Drivers code
int main()
{
    string str1 = "BA", str2 = "XY", shuffle = "ABYiX";
 
    (validShuffle(str1, str2, shuffle) == true)
        ? printf("YES")
        : printf("NO");
    cout << endl;
 
    return 0;
}