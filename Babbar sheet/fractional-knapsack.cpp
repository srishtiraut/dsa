struct Item{
    int value;
    int weight;
};


class Solution {
  public:
  static bool cmp(pair<double, Item> a, pair<double, Item> b){
return a.first > b.first;
}
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n) {
        // Your code here
        vector<pair<double, Item>> v;
 
    for(int i=0; i<n; i++){
        double costPerKg = (1.0*arr[i].value)/arr[i].weight;
        pair<double, Item> triplet = make_pair(costPerKg, arr[i]);
        v.push_back(triplet);
    }
 
    sort(v.begin(), v.end(), cmp);
 
    double totalCost = 0;      //we have to maximise this and return
 
    //traverse the array of triplets
    for (int i = 0; i < n; i++)
    {
        //if current item ka weight is more, take only a part aka fraction of that item
        if(v[i].second.weight > W){
            totalCost = totalCost + W*v[i].first;
            W = 0;
 
        }else{
            //if current item ka weight knapsack ki capacity se kum hai, take it as a whole
            totalCost = totalCost + v[i].second.value;
            W = W - v[i].second.weight;
 
        }
    }
    return totalCost;


    }
};