string rearrangeString(string S) {
    // code here
    int sizeOfS = S.length();
    
    //use a map to count the frequency of each character of S
    unordered_map<char, int> mp;
    for(int i=0; i<sizeOfS; i++){
        mp[S[i]]++;
    }

    //use a pq. 
    priority_queue<pair<int, char>> pq;
    for(auto element:mp){
        pq.push({element.second, element.first});  //(frequency, character) pairs
    }
    
    string answer = "";     //initialize empty string
    while(pq.size()>1){

        //during each iteration, pick the top 2 chars with highest frequencies and add them to answer string
        pair<int,char> one = pq.top();
        pq.pop();
        answer = answer + one.second;
        one.first--;        //remember to decrease this character's frequency

        pair<int,char> two = pq.top();
        pq.pop();
        answer = answer + two.second;
        two.first--;   
        
        //Push these pairs again to the pq
        if(one.first) pq.push({one.first, one.second});
        if(two.first) pq.push({two.first, two.second});

    }

    //now once the while loop has ended, means one pair is still remaining in the pq. But this character's frequency is more than 1
    if((pq.size()==1) and (pq.top().first > 1)) return "-1";    //no solution is possible

    //ANother case is one pair is still remaining in the pq but it's frequency is exactly 1
    if((pq.size()==1) and (pq.top().first == 1)){
        ans = ans + pq.top().second;        //add it to the answer
    }

    return answer;
}