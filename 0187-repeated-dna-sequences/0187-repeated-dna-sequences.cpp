class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> hm;
        int j=9;
        for(int i=0;i<s.length();i++){
            hm[s.substr(i,10)]++;
            j++;
            if(j>=s.length()) break;
        }
        vector<string> ans;
        for(auto it : hm){
            if(it.second>1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};