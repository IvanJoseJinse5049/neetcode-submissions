class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // this is a standard solution with a logic bug. what if nums[left]==nums[mid]? doesnt that incorrectly assume that the left half is sorted? but the current logic works which checks if all three left,mid and right are same and shrink the boundaries accordingly.
        int left=0, right=nums.size()-1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
        
            if (nums[mid] == target) {
                return true;
            }
            if (nums[left] == nums[mid] &&
                nums[mid] == nums[right]) {
                left++;
                right--;
                continue;
            }
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; 
                } else {
                    left = mid + 1; 
                }
            }
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;  
                } else {
                    right = mid - 1; 
                }
            }
	    }
	    return false; 
    }
};