class Solution {
public:
    int minOperations(vector<int>& nums) {
        // Map with num : count of num. If any has val of 1, remove. Otherwise, tally up
        int totalOps = 0;
        map<int, int> numCounts;
        for (auto num: nums)
        {
            if (numCounts.find(num) == numCounts.end())
            {
                numCounts[num] = 1;
            }
            else
            {
                numCounts[num]++;
            }
        }

        for (auto numCount = numCounts.begin(); numCount != numCounts.end(); numCount++)
        {
            int count = numCount->second;
            if (count == 1)
            {
                return -1;
            }
            else
            {
                totalOps += (count + 2) / 3;
            }
        }

        return totalOps == 0 ? -1 : totalOps;
    }
};