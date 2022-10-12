#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {

    priority_queue<int, vector<int>, greater<int> > minHeap;
    
    for(int i=0; i<k; i++) {
        minHeap.push(nums[i]);
    }

    for(int i=k; i<nums.size(); i++) {
        if(nums[i] > minHeap.top()) {
            minHeap.pop();
            minHeap.push(nums[i]);
        }
    }

    return minHeap.top();
}

int main() {
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;

    cout << findKthLargest(nums, k);

    return 0;
}
