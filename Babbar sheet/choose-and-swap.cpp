string chooseandswap(string str) {
        // Code Here
        set<char> s;
        for(int i=0; i<str.length(); i++) s.insert(str[i]);

        for(int i=0; i<str.length(); i++ ){
            if(s.erase(str[i]))

            if(s.empty()) break;

            char firstElementOfSet = *s.begin();   //first element of set
            char alphabet1 = firstElementOfSet;

            if(alphabet1 < str[i]){
                char alphabet2 = str[i];
                // swap(alphabet1, alphabet2) for all occurrences
                for(int j=0; j<str.length(); j++){
                    if(str[j] == alphabet1)
                        str[j] = alphabet2;
                    else if(str[j]==alphabet2)
                        str[j] = alphabet1;
                }
                break;       
        }
    }
    return str;
}