#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using namespace std;


int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //vector<int> vi(n);
  int n = adj.size();
  vector<int> dist(n,INT_MAX);
  dist[s] = 0;
  priority_queue<pair<int,int> > q;
  q.push(make_pair(0,s));
  while (!q.empty())
  {
      int tmp = q.top().second;
      q.pop();
      for (int i=0;i<adj[tmp].size();i++)
      {
          int v = adj[tmp][i];
          int c = cost[tmp][i];
          if ( dist[v] > dist[tmp] + c && dist[tmp]!=INT_MAX)
          {
              dist[v] = dist[tmp] + c;
              q.push(make_pair(dist[v],v));
          }
      }
  }
  if (dist[t]==INT_MAX) return -1;
  else return dist[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
