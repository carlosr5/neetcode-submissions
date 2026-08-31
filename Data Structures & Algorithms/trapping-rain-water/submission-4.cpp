class Solution {
public:
    int trap(vector<int>& height) {
        // Goal is to get a monotonic stack in both directions.
        // trapped_water[i] = min(left[i], right[i]) - height[i];
        // min(left[i], right[i]) is the maximum amount of trapped water for index i.
        // This is since we're looking for the lowest wall height of either side of the index.
        // Left and Right are monotonic stacks, meaning they just store the max element seen thus far, which gives us a guarantee of the two tallest wall heights on either side of i

        vector<int> leftWallHeight(height.size());
        vector<int> rightWallHeight(height.size());
        
        leftWallHeight[0] = height[0];
        for (int i = 1; i < height.size(); ++i)
        {
            leftWallHeight[i] = max(leftWallHeight[i-1], height[i]);
        }

        rightWallHeight[height.size()-1] = height[height.size()-1];
        for (int i = height.size() - 2; i >= 0; --i)
        {
            rightWallHeight[i] = max(rightWallHeight[i+1], height[i]);
        }

        int sum = 0;
        for (int i = 0; i < height.size(); ++i)
        {
            sum += max(min(leftWallHeight[i], rightWallHeight[i]) - height[i], 0);
        }

        return sum;
    }
};