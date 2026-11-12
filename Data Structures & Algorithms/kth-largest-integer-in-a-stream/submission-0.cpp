
class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        // Maintain only the k largest elements
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }
    int add(int val) {
        // If heap has fewer than k elements
        if (minHeap.size() < k) {
            minHeap.push(val);
        }
        // If new value is larger than the smallest element
        else if (val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }
        // Root represents the kth largest element
        return minHeap.top();
    }
};

