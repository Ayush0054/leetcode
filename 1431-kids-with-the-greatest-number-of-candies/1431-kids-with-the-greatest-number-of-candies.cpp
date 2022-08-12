class Solution {
    private:
     int maxii(vector<int>& candies){
        int maxi = INT_MIN;
        for(int i=0;i<candies.size();i++){
         if( candies[i]>maxi){
         maxi = candies[i];
         }
        }
              return maxi;
    }

public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
           int maxi =maxii(candies);
          vector<bool> ans;
        for(int i=0;i<candies.size();i++){
            if((candies[i]+extraCandies)>=maxi){
               ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};