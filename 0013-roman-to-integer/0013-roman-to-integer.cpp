class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> hm;
        hm['I'] = 1;
        hm['V'] = 5;
        hm['X'] = 10;
        hm['L'] = 50;
        hm['C'] = 100;
        hm['D'] = 500;
        hm['M'] = 1000;
        int res=0;
        int i=0;
        while(i<s.length()){
            if(hm[s[i]]<hm[s[i+1]]){
                res+=(hm[s[i+1]]-hm[s[i]]);
                i++;
            }else{
                res+=hm[s[i]];
            }
            i++;
            cout<<res<<endl;
        }
        return res;
    }
};