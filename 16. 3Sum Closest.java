class Solution {
    public static int threeSumClosest(int[] nums, int target) {
        if (nums == null || nums.length < 3) {
            return 0;
        }

        int len = nums.length;

        Arrays.sort(nums);

        int ans = nums[0] + nums[1] + nums[2];

        if (nums[0] > target && target > 0) {
            return ans;
        } else if (nums[len - 1] <= target && target < 0) {
            return nums[len - 3] + nums[len - 2] + nums[len - 1];
        }

        for (int i = 0; i < len; i++) {
            if (i > 1 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = len - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (Math.abs(sum - target) < Math.abs(ans - target)) {
                    ans = sum;
                }

                if (sum == target) {
                    return target;
                } else if (sum > target) {
                    right--;
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                } else {
                    left++;
                    while (left > right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                }
            }
        }

        return ans;
    }
}
