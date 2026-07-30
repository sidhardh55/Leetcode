class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        if(n<=8) return n;
        int p = floor(n/8);
        int ans = 8*((p*(p+1))/2)+(n%8)*(p+1);
        return ans;
    }
};