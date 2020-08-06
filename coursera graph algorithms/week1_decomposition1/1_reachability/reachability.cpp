#include <iostream>
#include <vector>

using std::vector;
using std::pair;
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

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
