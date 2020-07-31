#include <bits/stdc++.h>
#define int long long

using namespace std;
const int INF = 1e18;

struct edge
{
    int to;
    int cost;
};
using Graph = vector<vector<edge>>;

#define WHITE 0
#define GRAY 1
#define BLACK 2

int n;
Graph G;

void dijkstra(int start)
{
    int seen[10010];
    int dist[10010];

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++)
    {
        seen[i] = (i == start) ? GRAY : WHITE;
        dist[i] = (i == start) ? 0 : INF;
        pq.push(make_pair(dist[i], i));
    }

    while (!pq.empty())
    {
        auto now = pq.top();
        pq.pop();
        int u = now.second;
        int distU = now.first;

        seen[u] = BLACK;

        for (auto ne : G[u])
        {
            int v = ne.to;
            int cv = ne.cost;
            if (dist[u] + cv < dist[v])
            {
                dist[v] = dist[u] + cv;
                pq.push(make_pair(dist[v], v));
                seen[v] = GRAY;
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << i << " " << dist[i] << endl;
}

void solve()
{

    // remove the bottom 3 lines when you submit this code.
    std::ifstream in("sample.txt");
    std::cin.rdbuf(in.rdbuf());

    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    G.resize(n);

    for (int i = 0; i < n; i++)
    {
        int u, k;
        cin >> u >> k;
        for (int j = 0; j < k; j++)
        {
            int v, c;
            cin >> v >> c;
            G[u].push_back((edge){v, c});
        }
    }

    dijkstra(0);
}

signed main()
{
    solve();
    return 0;
}
