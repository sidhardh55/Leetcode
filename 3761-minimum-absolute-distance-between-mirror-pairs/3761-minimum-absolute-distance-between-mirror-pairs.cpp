class Solution {
public:
    int reverse(int num){
        int res =0;
        while(num>0){
            res *= 10;
            res += num%10;
            num /=10;
        }
        return res;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> hm;
        int mini = INT_MAX;
        for(int i=0;i<nums.size();i++){
            int rev = reverse(nums[i]);
            if(hm.find(rev)!=hm.end() && nums[i]%10!=0){
                mini = min(mini,abs(i-hm[rev]));
            }
                int num = nums[i];
                while(num%10==0){
                    num /=10;
                }
                hm[num] = i;
            
        }
        if(mini == INT_MAX) return -1;
        return mini;
           
    }
};