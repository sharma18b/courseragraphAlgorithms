#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using std::vector;
using std::queue;


int distance(vector<vector<int> > &adj, int s, int t) {
  int n = adj.size();
  vector<int> dist(n,n+1);
  dist[s] = 0;
  vector<int> vi(n,false);
  queue<int> q;
  q.push(s);
  while (!q.empty())
  {
      int temp = q.front();
      q.pop();
      for (int i =0;i<adj[temp].size();i++){
            if (dist[adj[temp][i]] == n+1)
            {
                dist[adj[temp][i]] = dist[temp] + 1;
                q.push(adj[temp][i]);
                }
      }

  }
  if (dist[t]>=n+1) return -1;
  else return dist[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
