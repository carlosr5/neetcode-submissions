class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> currAsteroids;

        for (int asteroid: asteroids)
        {
            if (currAsteroids.empty() || asteroid > 0)
            {
                currAsteroids.push(asteroid);
                continue;
            }

            if (!currAsteroids.empty() && currAsteroids.top() < 0 && asteroid < 0)
            {
                currAsteroids.push(asteroid);
                continue;
            }

            int asteroidSize = abs(asteroid);
            while (!currAsteroids.empty() && asteroidSize >= currAsteroids.top() && currAsteroids.top() > 0)
            {
                if (asteroidSize == currAsteroids.top())
                {
                    currAsteroids.pop();
                    asteroid = 0;
                    break;
                }

                if (asteroidSize < currAsteroids.top())
                {
                    break;
                }

                currAsteroids.pop();
            }

            if (asteroid != 0 && currAsteroids.empty())
            {
                currAsteroids.push(asteroid);
                continue;
            }

            if (asteroid != 0 && 
                !currAsteroids.empty() && 
                asteroidSize > currAsteroids.top())
            {
                currAsteroids.push(asteroid);
                continue;
            }

            if (asteroid != 0 && 
                !currAsteroids.empty() &&
                asteroidSize == currAsteroids.top())
            {
                currAsteroids.pop();
                continue;
            }
        }

        vector<int> finalList;
        while (!currAsteroids.empty())
        {
            finalList.push_back(currAsteroids.top());
            currAsteroids.pop();
        }

        reverse(finalList.begin(), finalList.end());

        return finalList;
    }
};