class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> hm;
        vector<string> ans;
        // int j=9;
        for(int i=0;i<s.length();i++){

            if(++hm[s.substr(i,10)]==2){
                ans.push_back(s.substr(i,10));
            }
            // j++;
            if(i+9>=s.length()) break;
        }
       

        return ans;
    }
};