class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        int s =0;
        int e =nums.size()-1;
         int *arr1 = new int[n];
         int *arr2 = new int[n];
          
        int k =s;
        for(int i=0;i<n;i++){
           arr1[i]=nums[k++];
        }
        
         k =n;
        for(int i=0;i<n;i++){
           arr2[i]=nums[k++];
        }
        
        for(int i=0;i<n;i++){
            res.push_back(arr1[i]);
            res.push_back(arr2[i]);
        }
        return res;
    }
};