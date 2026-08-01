class Solution {
public:
    int minimumPushes(string word) {
        vector<int> hash(26,0);
        for(int i=0;i<word.length();i++){
            hash[word[i]-'a']++;
        }
        int n = word.length();

        sort(hash.begin(),hash.end(),greater<int>());

        int count = 0;
        for(int i=0;i<26 && hash[i]>0;i++){
            count += hash[i]*(i/8 + 1);
        }
        return count;
    }
};