struct Car
{
    uint32_t position;
    uint32_t speed;
    float totalTime;

    Car(uint32_t initPosition, uint32_t initSpeed)
    {
        position = initPosition;
        speed = initSpeed;
    }
};

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars;

        for (int carIdx = 0; carIdx < position.size(); ++carIdx)
        {
            cars.push_back(Car(position[carIdx], speed[carIdx]));
        }

        // Since the car that's furthest along will limit the progress of faster cars behind,
        // let's sort our cars array in descending order
        sort(cars.begin(), cars.end(), [](const Car& lhs, const Car& rhs) 
        {
            return lhs.position > rhs.position;
        });

        stack<Car> fleets;

        for (auto& car: cars)
        {
            car.totalTime = static_cast<float>(static_cast<uint32_t>(target) - car.position) / static_cast<float>(car.speed);
        }

        for (auto car: cars)
        {
            if (fleets.empty())
            {
                fleets.push(car);
                continue;
            }

            Car nextFleet = fleets.top();

            if (car.totalTime <= nextFleet.totalTime)
            {
                continue;
            }

            fleets.push(car);
        }

        return fleets.size();
    }
};
