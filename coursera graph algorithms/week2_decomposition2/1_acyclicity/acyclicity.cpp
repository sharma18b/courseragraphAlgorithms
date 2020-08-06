#include <iostream>
#include <vector>

using std::vector;
using std::pair;

bool iscyclic(vector<vector<int> > &adj,int x,vector<bool> &vi,vector<bool> &rec )
{
        vi[x] = true;
        rec[x] = true;
        for (vector<int>::const_iterator it = adj[x].begin(); it != adj[x].end(); ++it) {
    if (!vi[*it] && iscyclic(adj, *it, vi, rec))
	  return true;
	else if(rec[*it])
	  return true;
  }
        rec[x]=false;
        return false;

    }





int acyclic(vector<vector<int> > &adj) {
    int n = adj.size();
    vector<bool> vi(n,false);
    vector<bool> recs(n,false);
    for (int i=0;i<n;i++)
    {
        if (!vi[i])
        if (iscyclic(adj,i,vi,recs)) return true;
    }
    return false;
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
  std::cout << acyclic(adj);
}
