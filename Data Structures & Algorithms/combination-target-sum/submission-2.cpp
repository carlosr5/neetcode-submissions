class Solution {
public:

bool calcSumPossibilities(vector<int>& nums, int& currNum, int target, int currSum, int currIdx, vector<int>& workArray, vector<vector<int>>& resultArray)
{
    if (currSum == target)
    {
        return true;
    }

    if (currSum > target)
    {
        return false;
    }

    for (int idx = currIdx; idx < nums.size(); ++idx)
    {
        int num = nums[idx];
        workArray.push_back(num);
        currSum += num;

        if (calcSumPossibilities(nums, num, target, currSum, idx, workArray, resultArray))
        {
            resultArray.push_back(workArray);
        }

        workArray.pop_back();
        currSum -= num;
    }

    return false;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

    vector<int> workArray;
    vector<vector<int>> resultArray;

    sort(candidates.begin(), candidates.end());
    calcSumPossibilities(candidates, candidates[0], target, 0, 0, workArray, resultArray);

    return resultArray;
    }
};