#include <iostream>
#include <string.h>
#include <stdbool.h>
using namespace std;

bool isPalindrome(char s[]){
    int len = strlen(s);
    if(len==1)
        return true;
    else{
        //check for palindrome
        for(int i=0;i<len/2;i++){
            if(s[i] == s[len-i-1]){
                return true;
            }else{
                return false;
            }
        }
    }
}

int noOfAppends(char s[]){
    if(isPalindrome(s)){
        return 0;
    }
    s++;
    return 1+noOfAppends(s);
}


int main()
{
    char s[] = "fgfhggp";
    cout<<noOfAppends(s);
    return 0;
}