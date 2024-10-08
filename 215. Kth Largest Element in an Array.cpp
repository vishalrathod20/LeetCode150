class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Create a min heap
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {  // Corrected from 'num' to 'nums'
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();  // Return the top element of the min heap
    }
};
