#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using std::vector;
using std::pair;
void dfs(vector<vector<int> > &adj,vector<bool> &vi,vector<int> &po,int x)
{
    vi[x] = true;
    for (int i=0;i<adj[x].size();i++)
    {
        if (!vi[adj[x][i]])
            {
                vi[adj[x][i]] = true;dfs(adj,vi,po,adj[x][i]);}

    }
    po.push_back(x);
    return ;
}

int number_of_strongly_connected_components(vector<vector<int> > adj,vector<vector<int> > adjr) {
  int result = 0;
  vector<bool> vi(adjr.size(),false);
  vector<int> po;
  for (int i = 0;i<adjr.size();i++)
  {
      if (!vi[i]) dfs(adjr,vi,po,i);
  }
  //for(int i =0;i<adj.size();i++) cout << po[i] << " ";

  for (int i =0;i<adjr.size();i++)
  {
      vi[i] =false;
  }
  reverse(po.begin(),po.end());
  vector<int > ans;
  for (int i=0;i<po.size();i++)
  {
     if (!vi[po[i]])
     {dfs(adj,vi,ans,po[i]);
     result++;}
     /*for (int j=0;j<adj.size();j++) cout << vi[j] << " ";
     cout << endl;*/
  }
  //cout << "4946416464" << endl;
  //for(int i=0;i<ans.size();i++) cout << ans[i] << " ";
  //result = po[0];
    //cout << result << endl;
  return result;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > adjr(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adjr[y - 1].push_back(x - 1);
  }
  //number_of_strongly_connected_components(adj,adjr);
  std::cout << number_of_strongly_connected_components(adj,adjr);
}
