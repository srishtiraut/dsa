class Solution {
    public:
        vector<vector<string>> partition(string s) {
            vector<vector<string>> result;      //all paths are stored in this
            vector<string> path;        //stores individual list of substrings
            
            func(0, s, path, result);
            return s;
        }

        void func(int index, string s, vector<string> &path, vector<vector<string>> &res){
            if(index == s.size){        //means partitioning has been inserted and we have reached the end
                res.push_back(path);
                return;
            }

            //loop through s and mk partitions
            for(int i=0; i<s.size(); ++i){
                if(isPalindrome()){
                    path.push_back(s.substr(index, i-index+1));
                    func(i+1, s, path, res);
                    path.pop_back();
                }
            }
        }

        bool isPalindrome(string s, int start, int end){
            while(start <= end){
                if(s[start++]!=s[end--]) return false;
            }
            return true;
        }
    };