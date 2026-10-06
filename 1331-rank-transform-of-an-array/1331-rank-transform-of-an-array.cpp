class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;        
        for(int i=0;i<arr.size();i++){
            pq.push({arr[i],i});
        }
        vector<int> res(arr.size(),0);
        int rank=1;
        int prev;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            res[it.second] = rank;
            if(pq.top().first!=it.first){
                rank++;
            }
           
        }
        return res;
    }
};
