#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
void explore(vector<vector<int> > &adj,int x,vector<bool> &visited)
{
    visited[x] = true;
    for (int i=0;i<adj[x].size();i++)
    {
        if (!visited[adj[x][i]]) explore(adj,adj[x][i],visited);
    }
    return;

}

int reach(vector<vector<int> > &adj, int x, int y) {
  int n = adj.size();
  int m = adj[x].size();
  vector<bool> visited(n,false);
  explore(adj,x,visited);
  if (visited[y]==false) return 0;
  else return 1;
  //return 0;
}

void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &dist, vector<int> &reachable, vector<int> &shortest) {
  //write your code here
  int n = adj.size();
  //vector<int> dist(n,100000);
  dist[s]=0;
  //int m=0;
  int u,v,c;
  queue<int> q;
  for (int k=0;k<n;k++)
  for (int i =0; i < n;i++)
  {
      for (int j =0;j<adj[i].size();j++)
      {
          u = i;
          v = adj[i][j];
          c = cost[i][j];
          if (dist[u] + c < dist[v] && dist[u]!= std::numeric_limits<long long>::max())
          {
              dist[v] = dist[u] + c;
              if (k==n-1) q.push(v);
          }
      }
  }
  reachable[s] = 1;
  for (int i =0;i<n;i++)
  {
      reachable[i] = reach(adj,s,i);
  }
  vector<bool> vi(n,false);
  while(!q.empty())
  {
      int tmp = q.front();
      q.pop();
      vi[tmp] = true;
      if (tmp!=s) shortest[tmp] =0;
      for (int i=0;i<adj[tmp].size();i++)
      {
          v = adj[tmp][i];
          if (!vi[v])
          {
              vi[v] = true;
              q.push(v);
              shortest[v] = 0;
          }
      }
  }
}


int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> dist(n, std::numeric_limits<long long>::max());
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, dist, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << dist[i] << "\n";
    }
  }
}
