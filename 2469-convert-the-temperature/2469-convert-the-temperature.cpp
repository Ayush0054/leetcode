class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double>s;
         double k = celsius + 273.15 ;
         s.push_back(k);
        double f = celsius * 1.80 + 32.00;
           s.push_back(f);
        return s;
    }
    
};