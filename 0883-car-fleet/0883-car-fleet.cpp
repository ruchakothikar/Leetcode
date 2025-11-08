class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        stack<float> times;
        int fleet = 0;
        float arrival = 0.0;
        for(int i=0; i<position.size(); i++)
        {
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.rbegin(), cars.rend());
        
        for(int i=0; i<cars.size(); i++)
        {
            arrival = float(target-cars[i].first)/cars[i].second;
            if(times.empty() || arrival>times.top())
            {
                times.push(arrival);
            }
        }
        while(!times.empty())
        {
            fleet++;
            times.pop();
        }
        return fleet;
    }
};