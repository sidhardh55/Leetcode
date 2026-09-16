class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        if(nums.size()==2){
            if(nums[0]!=nums[1]){
                return 1;
            }
        }
        long long firstsum=0;
        long long secondsum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i<n/2){
                firstsum+=nums[i];
            }else{
                secondsum+=nums[i];
            }
        }
        int res=0;
        int midind = n/2;
        int stind = 0;
        
        for (int i = 0; i < n; i++) {
            if(firstsum>secondsum){
                res++;
            }
            secondsum-=nums[midind];
            firstsum+=nums[midind];
            midind=(midind+1)%n;
            firstsum-=nums[stind];
            secondsum+=nums[stind];
            stind=(stind+1)%n;
        }
        return res;
    }
};