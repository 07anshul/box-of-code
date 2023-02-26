#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> v(9);
map<int, bool> visited;

void DFS(int x)
{

    visited[x] = true;
    cout << x << " ";


    vector<int>::iterator i;
    for (i = v[x].begin(); i != v[x].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

int main() {

  for (int i = 0; i < 9; i++) {
    v[i].push_back(1);
  }

  for (int i = 0; i < 9; i++) {
    DFS(i);
  }
}
