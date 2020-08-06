#include <iostream>
#include <vector>

using std::vector;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  int n = adj.size();
  vector<int> dist(n,100000);
  dist[0]=0;
  int m=0;
  int u,v,c;
  for (int k=0;k<n;k++)
  for (int i =0; i < n;i++)
  {
      for (int j =0;j<adj[i].size();j++)
      {
          u = i;
          v = adj[i][j];
          c = cost[i][j];
          if (dist[u] + c < dist[v])
          {
              dist[v] = dist[u] + c;
              if (k==n-1) m++;
          }
      }
  }
  if (m>0) return 1;
  else return 0;
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
  std::cout << negative_cycle(adj, cost);
}
/*
5 8
1 2 -1
1 3 4
2 3 3
2 4 2
2 5 2
4 3 5
4 2 1
5 4 -3
*/
