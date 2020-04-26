#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t;
    unsigned int n;
    long int a, b;
    int counter;

    cin >> t;
    while(t) {
        vector<pair<long int,long int>> vec;

        cin >> n;
        for(unsigned int i = 0; i<n; i++) {
            cin >> a;
            cin >> b;
            vec.push_back(make_pair(b,a));
        }

        sort(vec.begin(), vec.end());

        counter = 1;
        unsigned int j = 0;
        unsigned int i = 1;
        while(i<n) {
            if(vec[i].second >= vec[j].first) {
                counter++;
                j = i;
            }
            i++;
        }

        cout << counter << '\n';
        t--;
    }
    return 0;
}