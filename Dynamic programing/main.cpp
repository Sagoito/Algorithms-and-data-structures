#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n, s, d, l, m;
    int a, b, c;
    int counter = 1;
    cin >> n >> s >> d >> l >> m;
    int firstD = d;
    vector<pair<int, pair<int,int>>> vec[7];
    int arr[n][7] = {0};
    arr[s][d] = 1;
    while(m) {
        cin >> a >> b >> c >> d;
        vec[b].push_back(make_pair(a,make_pair(c,d)));

        m--;
    }
    for(int i=firstD+1; i<l+firstD; i++) {
        //wyzeruj obecna kolumne
        for(int j=0; j<n; j++)
            arr[j][i%7] = 0;

        for(auto it : vec[i%7]) {
            arr[it.first][i%7] += arr[it.second.first][it.second.second];
            arr[it.first][i%7] %= 100000007;
            counter += arr[it.second.first][it.second.second];
            counter %= 100000007;
        }
    }
    cout << counter % 100000007 << '\n';
    return 0;
}