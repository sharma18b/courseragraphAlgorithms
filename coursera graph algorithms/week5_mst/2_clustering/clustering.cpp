#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>

using std::vector;
using std::pair;

struct vertex{
    int parent;
    int rank;
    int x;
    int y;
    vertex(int a,int b,int c=-1,int d = 0)
    {
        x = a;
        y = b;
        parent = c;
        rank = d;
    }
};
struct edge
{
    int end1;
    int end2;
    double weight;
    edge(int a,int b,double c)
    {
        end1 = a;
        end2 = b;
        weight = c;
    }
};
bool cmp(edge a,edge b)
{
    return a.weight < b.weight;
}
int getParent(int table,vector<vertex> &sets)
{
    if (table!=sets[table].parent)
    {
        sets[table].parent = getParent(sets[table].parent,sets);
    }
    return sets[table].parent;
}
void merge(int set1,int set2,vector<vertex> &sets)
{
    int root1 = getParent(set1,sets);
    int root2 = getParent(set2,sets);
    if (root1!=root2)
    {
        if (sets[root1].rank > sets[root2].rank)
        {
            sets[root2].parent = root1;
        }
        else
        {
            sets[root1].parent = root2;
            if (sets[root1].rank== sets[root2].rank)
            {

                sets[root2].rank++;
            }

        }
    }

}


double clustering(vector<int> x, vector<int> y, int k) {
  //write your code here
  int unionnum = 0;
  vector<vertex> vertices;
  vector<edge> edges;
  for (int i=0;i<x.size();i++)
  {
      vertices.push_back(vertex(x[i],y[i],i));
  }
  for (int i=0;i<x.size();i++)
  {
      for (int j=i+1;j<y.size();j++)
      {
          double weight = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
          edges.push_back(edge(i,j,weight));
      }

  }
  std::sort(edges.begin(),edges.end(),cmp);
  int i=0;
  while (unionnum<=x.size()-k)
  {
      int u = edges[i].end1;
      int v = edges[i].end2;
      i++;
      if (getParent(u,vertices)!= getParent(v,vertices))
      {
          merge(u,v,vertices);
          unionnum++;
      }

  }
  return edges[i-1].weight;
}

int main() {
  size_t n;
  int k;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cin >> k;
  std::cout << std::setprecision(10) << clustering(x, y, k) << std::endl;
}
