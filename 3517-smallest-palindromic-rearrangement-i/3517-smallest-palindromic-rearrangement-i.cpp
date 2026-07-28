class Solution {
public:
    string smallestPalindrome(string s) {
        string ans = "";
        if(s.length()==1) return s;
        map<char,int> mp;
        for(int i=0;i<=(s.size()/2)-1;i++){
            mp[s[i]] += 2;
        }

        if(s.size()%2!=0) mp[s[s.size()/2]]++;

        for(auto it :mp){
            cout<<it.first<<" : "<<it.second<<endl;
        }
        char odd;
        for(auto it : mp){
            int val = it.second;
            for(int i=0;i<val/2;i++) ans += it.first;

            if(val%2!=0){
                odd = it.first;
            }
        }
        string str = ans;

        reverse(str.begin(),str.end());

        if(s.size()%2!=0){
             ans += odd;
        }
         
        return ans+str;
            
        
        // return ans+ans2;
    }
};