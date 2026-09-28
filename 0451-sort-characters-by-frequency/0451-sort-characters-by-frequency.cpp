class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> hm;
        for(int i=0;i<s.length();i++){
            hm[s[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto it : hm){
            pq.push({it.second,it.first});
        }
        string ans="";
        while(!pq.empty()){
            auto it = pq.top();
            char s = it.second;
            int n = it.first;
            pq.pop();

            while(n--){
                ans += s;
            }
        }
        return ans;
    }
};