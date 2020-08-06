#include <iostream>
#include <vector>
#include <queue>
using namespace std;


using std::vector;
using std::queue;


bool bip(vector<vector<int> > &adj,vector<int> &color,int src)
{
    queue<int> q;
    q.push(src);
    color[src] = 1;
    while (!q.empty())
    {
      int temp = q.front();
      q.pop();
      for (int i =0 ;i<adj[temp].size();i++)
      {
          if (color[adj[temp][i]]==color[temp]) return false;
          else if (color[adj[temp][i]]==-1)
          {
              color[adj[temp][i]] = (color[temp] + 1)%2;
              q.push(adj[temp][i]);
          }
      }
    }
  return true;

}

int bipartite(vector<vector<int> > &adj) {
    int n = adj.size();
    vector<int> color(n,-1);
    for(int i=0;i<n;i++)
    {
        if (color[i]==-1) if (bip(adj,color,i)==false) return false;
    }
    return true;
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
  std::cout << bipartite(adj);
}
