class Solution {
public:
    int minimumPushes(string word) {
        vector<int> hash(26,0);
        for(int i=0;i<word.length();i++){
            hash[word[i]-'a']++;
        }
        int n = word.length();
        vector<int> sorted;
        for(int i=0;i<26;i++){
            if(hash[i]!=0){
                sorted.push_back(hash[i]);
            }
        }
        sort(sorted.begin(),sorted.end());
        int mapsize = sorted.size();
        if(mapsize<=8) return n;
        int count = 0;
        int p = 1;
        for(int i=mapsize-1;i>=0;i--){

            if(p<=8){
                count += sorted[i];
            }else if(p>8 && p<=16){
                count += sorted[i]*2;
            }else if(p>16 && p<=24){
                count += sorted[i]*3;
            }else{
                count += sorted[i]*4;
            }

            p++;
        }
    
        return count;
    }
};