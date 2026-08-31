class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);

        uint32_t numDays = temperatures.size();
        if (numDays == 1)
        {
            return {0};
        }

        for (int currTempIdx = numDays - 2; currTempIdx >= 0; --currTempIdx)
        {
            uint32_t futureTempIdx = currTempIdx + 1;
            bool largerFutureTempExists = true;
            bool todayIsHotterThanFuture = temperatures[futureTempIdx] <= temperatures[currTempIdx];

            while (largerFutureTempExists && todayIsHotterThanFuture)
            {
                if (result[futureTempIdx] == 0)
                {
                    largerFutureTempExists = false;
                    break;
                }

                // Jump to where the current result has potentially found a hotter day
                futureTempIdx += result[futureTempIdx];
                todayIsHotterThanFuture = temperatures[futureTempIdx] <= temperatures[currTempIdx];
            }

            if (largerFutureTempExists)
            {
                uint32_t daysUntilHotterDay = futureTempIdx - currTempIdx;
                result[currTempIdx] = daysUntilHotterDay;
            }
        }
            
        return result;
    }
};
