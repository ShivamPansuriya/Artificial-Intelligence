#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, target;
    cin >> a >> b >> target;
    queue<vector<int>> q;
    set<vector<int>> visited;
    map<vector<int>, vector<int>> parent;
    vector<vector<int>> path;
    vector<int> lastNode = {-1};

    function<void(int, int, vector<int>)> insertIntoQ = [&](int x, int y, vector<int> curr)
    {
        if (visited.find({x, y}) == visited.end())
        {
            visited.insert({x, y});
            parent[{x, y}] = curr;
            q.push({x, y});
        }
    };

    q.push({0, 0});
    parent[{0, 0}] = {-1};
    visited.insert({0, 0});
    while (!q.empty())
    {
        int s = q.size();
        while (s--)
        {
            vector<int> curr = q.front();
            q.pop();

            if (curr[0] + curr[1] == target)
            {
                lastNode = curr;
                break;
            }

            insertIntoQ(a, curr[1], curr);
            insertIntoQ(curr[0], b, curr);
            insertIntoQ(0, curr[1], curr);
            insertIntoQ(curr[0], 0, curr);
            int req = min(curr[0], b - curr[1]);
            insertIntoQ(curr[0] - req, curr[1] + req, curr);
            req = min(curr[1], a - curr[0]);
            insertIntoQ(curr[0] + req, curr[1] - req, curr);
        }
        if (lastNode[0] != -1)
        {
            break;
        }
    }

    if (lastNode[0] == -1)
    {
        cout << "NOT POSSIBLE" << endl;
        return 0;
    }

    while (lastNode[0] != -1)
    {
        path.push_back(lastNode);
        lastNode = parent[lastNode];
    }

    reverse(path.begin(), path.end());
    for (auto i : path)
    {
        cout << i[0] << " " << i[1] << endl;
    }

    return 0;
}