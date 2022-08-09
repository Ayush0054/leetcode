class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0;i<numRows;i++){
            vector<int> row(i+1,1);
             // initailize first row with 1
            for(int j=1;j<i;j++){
                row[j]=ans[i-1][j] + ans[i-1][j-1];
                // for every row use this formula
            }
            ans.push_back(row);
        }
        return ans;
    }
};