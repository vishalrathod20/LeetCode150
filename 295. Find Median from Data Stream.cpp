class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        // Max heap to store the lower half
        // Min heap to store the upper half
    }
    
    void addNum(int num) {
        // Step 1: Add number to max heap (lower half)
        maxHeap.push(num);
        
        // Step 2: Balance the heaps
        if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
            int maxTop = maxHeap.top();
            maxHeap.pop();
            minHeap.push(maxTop);
        }

        // Ensure maxHeap can only have at most one more element than minHeap
        if (maxHeap.size() > minHeap.size() + 1) {
            int maxTop = maxHeap.top();
            maxHeap.pop();
            minHeap.push(maxTop);
        } else if (minHeap.size() > maxHeap.size()) {
            int minTop = minHeap.top();
            minHeap.pop();
            maxHeap.push(minTop);
        }
    }
    
    double findMedian() {
        // If maxHeap has more elements
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        // If both heaps are of equal size
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }

private:
    std::priority_queue<int> maxHeap; // Max heap for lower half
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // Min heap for upper half
};
