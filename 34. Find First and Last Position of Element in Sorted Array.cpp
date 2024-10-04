#include <vector>
using namespace std;

class Solution {
    int findFirstPosition(vector<int>& nums, int target) {
        int left = 0; 
        int right = nums.size() - 1;
        int firstPos = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {  // Use '==' instead of '='
                firstPos = mid;  // Update the first position
                right = mid - 1; // Continue to search in the left half
            } else if (nums[mid] > target) {
                right = mid - 1; // Move left
            } else {
                left = mid + 1;  // Move right
            }
        }
        return firstPos;
    }

    int findLastPosition(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int lastPos = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) { 
                lastPos = mid;  // Update the last position
                left = mid + 1; // Continue to search in the right half
            } else if (nums[mid] > target) {
                right = mid - 1; // Move left
            } else {
                left = mid + 1;  // Move right
            }
        }
        return lastPos;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1); // Initialize the vector with two elements set to -1
        result[0] = findFirstPosition(nums, target);
        result[1] = findLastPosition(nums, target);
        return result;
    }
};
