class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-2;
        sort(nums.begin(), nums.end());
        if(nums.size()-1 == nums[high+1]){
            return nums.size();
        }
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == mid && nums[mid+1]==mid+2){
                return mid+1;
            }
            else if(nums[mid] == mid){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
};