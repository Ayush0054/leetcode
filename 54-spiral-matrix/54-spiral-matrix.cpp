class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans ;
        int row = matrix.size();
        int col = matrix[0].size();
        int count =0;
        
        int total = row*col;
        
        int strtrow = 0;
        int strtcol = 0;
        int endrow= row -1;
        int endcol = col-1;
        
        
        while(count<total){
             //print starting row
            
            for(int i = strtcol ; count<total && i<=endcol; i++){
                
                ans.push_back(matrix[strtrow][i]);
                count++;
            }
            strtrow++;                            //strtrow -> 1
            
              //print ending column
            for(int i = strtrow ; count<total && i<=endrow; i++){
                
                ans.push_back(matrix[i][endcol]);
                count++;
            }
            endcol--;                            //endcol ->1
            
             //print ending row
            for(int i = endcol ; count<total && i>=strtcol; i--){
                
                ans.push_back(matrix[endrow][i]);
                count++;
            }
            endrow--;                               //endrow ->1
            
            //print starting column
            for(int i = endrow; count<total && i>=strtrow; i--){
                
                ans.push_back(matrix[i][strtcol]);
                count++;
            }
            strtcol++;                                  //strtcol->1
            
            
        }
        return ans;
    }
};
// some explanation

// j           j             j 

// i     0,0       0,1       0,2

// i     1,0       1,1      1,2

// i     2,0       2,1       2,2