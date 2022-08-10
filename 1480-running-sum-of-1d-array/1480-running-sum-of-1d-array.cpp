class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int ans=0;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            ans=ans + nums[i];
            res.push_back(ans);  
        }
        return res;
    }
};