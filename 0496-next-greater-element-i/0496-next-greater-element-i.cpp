class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
         stack<int> s;
        vector<int> v;
        unordered_map<int,int>mp;
        for(int i=nums2.size()-1;i>=0;i--){
            if(s.size()==0){
               mp[nums2[i]] =-1;
            }
            else {
                if(s.top()>nums2[i]){
                mp[nums2[i]]=s.top();
                 }
             else{
                 while(s.size()>0 && s.top() <=nums2[i]){
                     s.pop();
                 }
                 if(s.size()== 0){
                     mp[nums2[i]] =-1;
                 }
                 else{
                     mp[nums2[i]]=s.top();
                 }
             }
            
        }
        
        s.push(nums2[i]);
    }
    
    for(int i =0;i<nums1.size();i++){
        v.push_back(mp[nums1[i]]);
    }
        
    
    return v;
    
    }
};