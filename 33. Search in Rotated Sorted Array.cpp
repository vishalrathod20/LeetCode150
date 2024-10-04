class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            // If the target is found
            if (nums[mid] == target) {
                return mid;
            }

            // Check if the left half is sorted
            if (nums[start] <= nums[mid]) {
                // If target is in the left half
                if (target >= nums[start] && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            // Otherwise, the right half must be sorted
            else {
                // If target is in the right half
                if (target > nums[mid] && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        // If target is not found
        return -1;
    }
};
