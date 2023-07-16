// LC HARD 

int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
{
    // make an array of station-->buses
    // idea is to check on all the buses
    if (source == target)
        return 0;
    unordered_map<int, vector<int>> bus;
    for (int i = 0; i < routes.size(); i++)
    {
        for (auto stop : routes[i])
        {
            bus[stop].push_back(i); // find the buses for each stop
        }
    }
    vector<bool> bus_taken(routes.size());
    queue<int> q;
    // take all the buses from the source
    for (auto take : bus[source])
    {
        bus_taken[take] = 1;
        q.push(take);
    }
    int ans = 0;
    while (!q.empty())
    {
        ans++;
        for (int s = q.size(); s > 0; s--)
        {
            int current = q.front(); // current bus
            q.pop();
            for (auto route : routes[current])
            {
                if (route == target)
                    return ans;
                for (int i = 0; i < bus[route].size(); i++)
                {
                    if (!bus_taken[bus[route][i]])
                    {
                        bus_taken[bus[route][i]] = 1;
                        q.push(bus[route][i]);
                    }
                }
            }
        }
    }
    return -1;
}