class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        int n = s.length();
        if(n<=10) return ans;
        int hash = 0,mask = (1<<20)-1;
        unordered_map<int,int> hm;
        for(int i=0;i<9;i++){
            hash = ( hash << 2 ) | (s[i]>>1 & 3);
        }

        for(int i=9;i<n;i++){
            hash = ( (hash << 2) | (s[i]>>1 & 3) ) & mask;
            hm[hash]++;
            if(hm[hash]==2){
                ans.push_back(s.substr(i-9,10));
            }
        }
        return ans;
    }
};