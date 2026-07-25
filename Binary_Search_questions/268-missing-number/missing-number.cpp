class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        sort(nums.begin(), nums.end());
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == mid){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
};