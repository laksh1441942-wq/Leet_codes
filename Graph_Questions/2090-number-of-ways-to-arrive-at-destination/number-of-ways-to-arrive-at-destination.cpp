class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        vector<long long>dist(n, LLONG_MAX);
        vector<int>ways(n, 0);
        int mod = (int)(1e9 + 7);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        while(!pq.empty()){
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int adjnode = it.first;
                int adjdis = it.second;
                if(dis > dist[node]) continue;
                if( dis + adjdis < dist[adjnode]){
                    pq.push({dis + adjdis, adjnode});
                    dist[adjnode] = dis + adjdis;
                    ways[adjnode] = ways[node];
                }
                else if (dis + adjdis == dist[adjnode]){
                    ways[adjnode] =( ways[adjnode] + ways[node])%mod;
                }
            }

        }
        return ways[n-1]%mod;

    }
};