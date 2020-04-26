#include <iostream>
#include <vector>
using namespace std;

bool solve(vector<pair<unsigned int, unsigned int>> & vec, vector <bool> & visited, unsigned int m, int r, unsigned int i) {


    if(r == 0 || i == m) {
        if(i != m) {
            for(; i<m; i++) {
                if(!(visited[vec[i].first] || visited[vec[i].second]))
                    return false;
            }
            return true;
        }
        else {
            for(unsigned int j = 0; j<m; j++) {
                if(!(visited[vec[j].first] || visited[vec[j].second]))
                    return false;
            }
                return true;
        }
    }


    for(; i<m; i++) {
      if(!(visited[vec[i].first] || visited[vec[i].second])) {
          visited[vec[i].first] = true;

          if (solve(vec, visited, m, r-1, i+1)) return true;

          visited[vec[i].first] = false;
          visited[vec[i].second] = true;

           if(solve(vec, visited, m, r-1, i+1)) return true;
           visited[vec[i].second] = false;
           return false;
      }
    } return true;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    int t;
    cin >> t;
    while(t) {

        unsigned int n, m;
        int r;
        unsigned int a, b;
        cin >> n >> m >> r;
        vector<pair<unsigned int, unsigned int>> vec;

        vector <bool> visited(n + 1);
        for(unsigned int i=0; i<m; i++) {
            cin >> a >> b;
            visited[a] = false;
            visited[b] = false;
            vec.push_back(make_pair(a,b));
        }
        unsigned int i=0;
        if(solve(vec, visited, m, r, i))
            cout << "TAK" << "\n";
        else
            cout << "NIE" << "\n";
        t--;
    }
    return 0;
}