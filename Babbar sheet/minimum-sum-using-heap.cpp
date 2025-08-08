class Solution {
  public:
    string removeLeadingZeroes(string &result){
       size_t position = result.find_first_not_of('0');
       if(position == string::npos){
        return "0";
       }else{
        return str.substr(position);
       }
    }

    string addStrings(string &a, string &b){
        int sizeOfa = a.size()-1;
        int sizeOfb = b.size()-1;
        int carry = 0;
        string result;

        // Perform digit-by-digit addition from right to left
        while(sizeOfa>=0 or sizeOfb>=0  or carry){
            int digit1 = 0;
            int digit2 = 0;
            if(sizeOfa>=0){
                digit1 = a[i]-'0';
                sizeOfa--;
            }
            if(sizeOfb>=0){
                digit2 = b[i]-'0';
                sizeOfb--;
            }

            int sum = digit1+digit2+carry;
            int digit = sum%10;
            carry = sum/10;

            result.push_back(digit+'0');
        }

        reverse(result.begin(), result.end());

        return result;
    }

    string minSum(vector<int> &arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>> minheap(arr.begin(), arr.end());

        string num1String = "";
        string num2String = "";

        while(minheap.size()>0){
            num1String = num1String + to_string(minheap.top());
            minheap.pop();
            if(minheap.size()>0){
                num2String = num2String + to_string(minheap.top());
                minheap.pop();
            }
        }

        string result = addStrings(num1String, num2String);
        return removeLeadingZeroes(result);
    }
};