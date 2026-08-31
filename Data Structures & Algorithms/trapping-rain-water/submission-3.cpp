class Solution {
public:
    int trap(vector<int>& height) {
        // Invariant: trapped_water[i] = min(prefix_max[i], suffix_max[i]) - height[i]
        // The prefix max is the maxes to the left of index i, while suffix max is the maxes to right of index i
        // In order to get this invariant, we have to make our prefix and suffix arrays by iterating through the array twice
        // We can then calculate the total trapped water by sum += max(trapped_water[i], 0)
        vector<int> prefix_max(height.size());
        vector<int> suffix_max(height.size());
        int curr_max = -1;
        int sum = 0;

        if (height.size() < 2)
        {
            return 0;
        }
        
        if (height.size() == 2)
        {
            return max(height[0], height[1]);
        }

        // First, let's create our prefix and suffix arrays
        // Prefix array
        for (int i = 0; i < height.size(); i++)
        {
            if (i == 0)
            {
                curr_max = height[i];
                prefix_max[i] = curr_max;
                continue;
            }

            curr_max = max(curr_max, height[i-1]);
            prefix_max[i] = curr_max;
        }

        // Suffix array
        curr_max = -1;
        for (int i = height.size()-1; i >= 0; i--)
        {
            if (i == height.size()-1)
            {
                curr_max = height[i];
                suffix_max[i] = curr_max;
                continue;
            }

            curr_max = max(curr_max, height[i+1]);
            suffix_max[i] = curr_max;
        }

        // Now that we have our prefix and suffix arrays, let's calculate all the water heights using our invariant
        // Invariant: trapped_water[i] = min(prefix_max[i], suffix_max[i]) - height[i]
        for (int i = 0; i < height.size(); i++)
        {
            // We'll evaluate trapped_water[i] directly instead of making a separate array
            sum += max(min(prefix_max[i], suffix_max[i]) - height[i], 0);
        }

        return sum;
    }
};
