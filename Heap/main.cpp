#include <bits/stdc++.h>
using namespace std;



int main()
{

    ios_base::sync_with_stdio(false);
    vector<pair<int, int>> vec;
    int n;
    int p, w;
    cin >> n;
    int arr[1001] = {0};
    for(int i=0; i<n; i++) {
        cin >> p >> w;
        vec.push_back(make_pair(p, w));
        arr[vec[i].first] = i;
    }

    int m;
    cin >> m;
    unsigned long long int k;
    int counter = 0;

    while(m) {
        cin >> p >> w;
        k = arr[p];
        if(w - vec[k].second > 0) {
            vec[k].second = w;

            //przesiewanie w gore

            while(k>0 && vec[(k-1)/2].second <  vec[k].second) {

                swap(arr[vec[(k-1)/2].first], arr[vec[k].first]);
                swap(vec[(k-1)/2], vec[k]);

                counter++;
                k = (k-1)/2;
            }
        }
        //przesiewanie w dol

        else if(w - vec[k].second < 0) {
            vec[k].second = w;


            while(2*k+1 < n) {
                unsigned long long int j = 2 * k + 1;

                if(j+1 < n) {
                    if(vec[j].second < vec[j+1].second)
                        j++;
                }
                if(vec[k].second >= vec[j].second) break;

                swap(vec[j], vec[k]);
                swap(arr[vec[j].first], arr[vec[k].first]);

                counter++;
                k = j;
            }
        }

        m--;
    }
    cout << counter << "\n";
    return 0;
}