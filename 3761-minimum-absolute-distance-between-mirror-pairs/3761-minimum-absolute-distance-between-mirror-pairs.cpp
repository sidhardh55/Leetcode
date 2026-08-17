class Solution {
public:
    int reverseNum(int num){
        int res = 0;
        while(num > 0){
            res = res * 10 + num % 10;
            num /= 10;
        }
        return res;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> hm; 
        int mini = INT_MAX;
        for(int i = 0; i < (int)nums.size(); i++){
            if(hm.find(nums[i]) != hm.end()){
                mini = min(mini, i - hm[nums[i]]);
            }
            hm[reverseNum(nums[i])] = i;
        }

        return mini == INT_MAX ? -1 : mini;
    }
};