class Solution {
public:
    int reverseDegree(string s) {
        int res=0;
        for(int i=0;i<s.length();i++){
            res = res + (i+1)*((int('z')-int(s[i]))+1);
        }
        return res;
    }
};