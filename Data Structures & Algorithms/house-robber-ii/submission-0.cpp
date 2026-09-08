class Solution {
public:
    int origHouseRobber(vector<int> nums, int startIdx, int endIdx)
    {
        if (startIdx + 1 > endIdx ||
            startIdx < 0 ||
            endIdx >= nums.size())
        {
            return -1;
        }

        if (nums.size() == 1)
        {
            return nums[0];
        }
        else if (nums.size() == 2)
        {
            return max(nums[0], nums[1]);
        }

        vector<int> maxAmount(nums.size());
        maxAmount[startIdx] = nums[startIdx];
        maxAmount[startIdx + 1] = max(nums[startIdx], nums[startIdx + 1]);

        for (int houseIdx = startIdx + 2; houseIdx <= endIdx; ++houseIdx)
        {
            int currHouseVal = nums[houseIdx];

            maxAmount[houseIdx] = max(currHouseVal + maxAmount[houseIdx - 2], maxAmount[houseIdx - 1]);
        }

        return maxAmount[endIdx];
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        else if (nums.size() == 2)
        {
            return max(nums[0], nums[1]);
        }
        
        int firstSum = origHouseRobber(nums, 0, nums.size() - 2);
        int secondSum = origHouseRobber(nums, 1, nums.size() - 1);

        return max(firstSum, secondSum);
    }
};
