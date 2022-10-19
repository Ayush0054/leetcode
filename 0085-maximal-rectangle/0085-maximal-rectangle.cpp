class Solution {
public:
    vector<int> lsr(vector<int>h){
        stack<pair<int,int>> s;
        vector<int>v;
        int psueodo_idx = h.size();
        for(int i=h.size()-1;i>=0;i--){
            if(s.empty()){
                v.push_back(psueodo_idx);
            }
            else{
                if( s.top().first<h[i]){
                    v.push_back(s.top().second);
                }
                else{
                    while(!s.empty() && s.top().first>=h[i]){
                        s.pop();
                    }
                     
                    if(s.empty()){
                v.push_back(psueodo_idx);
                  }
                      else{
                   v.push_back(s.top().second);
                    }
                }
            }
            
            s.push({h[i],i});
        }
        reverse(v.begin(),v.end());
        return v;
    }
    
     vector<int> lsl(vector<int>h){
        stack<pair<int,int>> s;
        vector<int>v;
        int psueodo_idx = -1;
        for(int i=0;i<h.size();i++){
            if(s.empty()){
                v.push_back(psueodo_idx);
            }
            else{
                if( s.top().first<h[i]){
                    v.push_back(s.top().second);
                }
                else{
                    while(!s.empty() && s.top().first>=h[i]){
                        s.pop();
                    }
                     
                    if(s.empty()){
                v.push_back(psueodo_idx);
                  }
                      else{
                   v.push_back(s.top().second);
                    }
                }
            }
            
             s.push({h[i],i});
        }
        return v;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> l=lsl(heights);
        vector<int> r = lsr(heights);
        vector<int> width ;
        for(int i=0;i<heights.size();i++){
            width.push_back( r[i] - l[i] -1);
        }
        int area=0;
        
        for(int i =0;i<heights.size();i++){
           int tarea = heights[i]* width[i];
            area = max(tarea,area);
        }
        return area;
    }
    
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> v(matrix[0].size(), 0) ;
        // for(int j=0;j<matrix.size();j++){
        //     v.push_back(matrix[0][j]);
        // }
        int mx = 0;
        
        for(int i =0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='0'){
                    v[j]=0;
                }else{
                    v[j] = v[j] + matrix[i][j] - 48 ;
                }
            }
                mx = max(mx,largestRectangleArea(v));
        }
        return mx;
    }
};