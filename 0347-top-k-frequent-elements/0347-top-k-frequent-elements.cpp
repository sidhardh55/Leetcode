class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hm;
        for(int i=0;i<nums.size();i++){
            hm[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto it:hm){
            pq.push({it.second,it.first});
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            auto it = pq.top();
            ans.push_back(it.second);
            pq.pop();
        }
        return ans;
    }
};