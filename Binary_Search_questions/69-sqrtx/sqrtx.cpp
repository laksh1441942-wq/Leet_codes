class Solution {
public:
    int mySqrt(int x) {
        int low = 0, high = x;
        if(x < 2){
            return x;
        }
        while(low<=high){
            int mid = (low+high)/2;
            if(mid == x/mid){
                return mid;
                break;
            }
            else if(mid < x/mid){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
            
        }
        return low-1;
    }
};