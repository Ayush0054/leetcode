class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int n =nums.size();
        vector<int> res;
        for(int i =0;i<n;i+=2){
          for(int j=0 ;j<nums[i];j++)
              res.push_back(nums[i+1]);
              
        }
        return res;
    }
};