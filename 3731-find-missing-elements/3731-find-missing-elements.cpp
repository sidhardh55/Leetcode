class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> vec;
        sort(nums.begin(),nums.end());
        int j = 0;
        for(int i = nums[0];i<=nums[nums.size()-1];i++){
            if(j>=nums.size()){
                vec.push_back(i);
            }
            if(i !=nums[j] ){
                vec.push_back(i);
            }else{
                j++;
            }
        }

        return vec;
    }
};