class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Stack storing indices of heights
        // Monotonic property enforced via height lookup
        stack<int> monoStack;
        monoStack.push(-1);

        int largestArea = -1;
        for (int heightIdx = 0; heightIdx < heights.size(); ++heightIdx)
        {
            int height = heights[heightIdx];

            if (monoStack.size() == 1)
            {
                monoStack.push(heightIdx);
                continue;
            }

            if (height > heights[monoStack.top()])
            {
                monoStack.push(heightIdx);
                continue;
            }
            else // heights[heightIdx] <= heights[monoStack.top()]
            {
                while (monoStack.size() >= 2 && height <= heights[monoStack.top()])
                {
                    // Let's calculate the max for the top before we get rid of it
                    int currMaxIdx = monoStack.top();
                    monoStack.pop();
                    
                    int rightBound = heightIdx;
                    int leftBound = monoStack.top();

                    int currMaxWidth = rightBound - leftBound - 1;

                    int currMax = heights[currMaxIdx] * currMaxWidth;

                    largestArea = max(largestArea, currMax);
                }

                monoStack.push(heightIdx);
            }
        }

        // Check any remaining items in the stack
        while (monoStack.top() != -1)
        {
            int currMaxIdx = monoStack.top();
            monoStack.pop();
            
            int rightBound = heights.size();
            int leftBound = monoStack.top();

            int currMaxWidth = rightBound - leftBound - 1;

            int currMax = heights[currMaxIdx] * currMaxWidth;

            largestArea = max(largestArea, currMax);
        }

        return largestArea;
    }
};