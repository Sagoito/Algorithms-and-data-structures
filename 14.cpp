#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &vec, size_t k) {
    srand( time_t( NULL ) );

    vector<int> vec1, vec2, vec3;
    int a = vec[rand()%vec.size()];

    for(size_t i=0; i<vec.size(); i++) {
        if(a > vec[i])
            vec1.push_back(vec[i]);
        else if(a == vec[i])
            vec2.push_back(vec[i]);
        else
            vec3.push_back(vec[i]);

    }

    size_t b = vec1.size();
    size_t c = vec2.size();

    if(k <= b)      return solve(vec1, k);
    if(k <= b + c)  return a;
    return solve(vec3, k - (b+c));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int p, w;
    vector<pair<int, int>> vec_pair;
    vector<int> vec;

    for(int i=0; i<n; i++) {
        cin >> p >> w;
        vec.push_back(w);
        vec_pair.push_back(make_pair(p, w));
    }
    int m;

    cin >> m;
    size_t k;
    while(m) {
        cin >> k;
        int a = solve(vec,k);
        int b = INT_MAX;
        for(size_t i=0; i<vec_pair.size(); i++)
            if(a == vec_pair[i].second && b > vec_pair[i].first)
                    b = vec_pair[i].first;

        cout << b << '\n';
        m--;
    }

    return 0;
}