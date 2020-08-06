#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::pair;

void dfs(vector<vector<int> > &adj, vector<bool> &vi, vector<int> &order, int x) {
  //write your code here
  vi[x] = true;
  for (int i=0;i<adj[x].size();i++)
  {
      if (!vi[adj[x][i]]) {
            vi[adj[x][i]] = true;
            dfs(adj,vi,order,adj[x][i]);}
  }
  order.push_back(x);
}

vector<int> toposort(vector<vector<int> > adj) {
  vector<bool> vi(adj.size(), 0);
  vector<int> order;
  for (int i = 0;i<adj.size();i++)
  {
      if (!vi[i])
      dfs(adj,vi,order,i);
  }
  reverse(order.begin(),order.end());
  //write your code here
  return order;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
