class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
             for(int j=0;j<i;j++){
                 swap(matrix[i][j],matrix[j][i]);
             }
         }
        
        for(int i=0;i<matrix.size();i++){
        int ptr1=0;
        int ptr2=matrix.size()-1;
             while(ptr1<ptr2){
                 swap(matrix[i][ptr1],matrix[i][ptr2]);
                  ptr1++;
                  ptr2--;
             }
         }
    }
    
    
};