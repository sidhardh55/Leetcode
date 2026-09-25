class Solution {
public:
    int digs(int num){
        int res=0;
        while(num>0){
            res+=num%10;
            num/=10;
        }
        return res;
    }
    int smallestIndex(vector<int>& nums) {
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            if(digs(nums[i])==i){
                ans = i;
                break;
            }
        }
        return ans;
    }
};