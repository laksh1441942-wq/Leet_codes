class Solution {
public:
    int mySqrt(int x) {
        vector<int>num;
        for(long long i=0; i*i<=x; i++){
            num.push_back(i);
        }
        int n = num.size()-1;
        return num[n];
    }
};