class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        else if (nums.size() == 2)
        {
            return max(nums[0], nums[1]);
        }

        vector<int> maxAmount(nums.size());
        maxAmount[0] = nums[0];
        maxAmount[1] = max(nums[0], nums[1]);
        for (int houseIdx = 2; houseIdx < nums.size(); ++houseIdx)
        {
            int currHouseVal = nums[houseIdx];

            maxAmount[houseIdx] = max(currHouseVal + maxAmount[houseIdx - 2], maxAmount[houseIdx - 1]);
        }

        return maxAmount[nums.size() - 1];
    }
};
