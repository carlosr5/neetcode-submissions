class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left_max(height.size());
        vector<int> right_max(height.size());
        int curr_left_max = -1;
        int curr_right_max = -1;
        int water_stored = 0;
        
        if (height.size() < 2)
        {
            return 0;
        }

        if (height.size() == 2)
        {
            return max(height[0], height[1]) - min(height[0], height[1]);
        }

        // I can make arrays storing the highest points from either side of any given point
        // Construct left_max
        left_max[0] = height[0];
        for (int i = 1; i < height.size(); i++)
        {
            left_max[i] = max(curr_left_max, height[i-1]);
            curr_left_max = max(curr_left_max, height[i-1]);
        }

        // Construct right_max
        right_max[height.size()-1] = height[height.size()-1];
        for (int i = height.size() - 2; i >= 0; i--)
        {
            right_max[i] = max(curr_right_max, height[i+1]);
            curr_right_max = max(curr_right_max, height[i+1]);
        }

        // Sanity check: Print out left and right maxes
        for (int i = 0; i < height.size(); i++)
        {
            cout << left_max[i] << " ";
        }
        cout << endl;

        for (int i = 0; i < height.size(); i++)
        {
            cout << right_max[i] << " ";
        }
        cout << endl;

        // Now let's figure out the total water trapped
        for (int i = 0; i < height.size(); i++)
        {
            cout << max(min(left_max[i], right_max[i]) - height[i], 0) << " ";
            water_stored += max(min(left_max[i], right_max[i]) - height[i], 0);
        }
        cout << endl;

        return water_stored;
    }
};
