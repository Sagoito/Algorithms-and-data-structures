#include <bits/stdc++.h>
using namespace std;
struct data {
    int arr[6];
};

void bucket(vector<data> &dane, int k) {
        int max = -1;
        size_t n = dane.size();
        int bucket = 10;
        int j = 0;
        vector<pair<int,int>> pom[10];
        vector<data> dane_sort(n);
            for(size_t i = 0; i<n; i++)
                if(max < dane[i].arr[k])
                    max = dane[i].arr[k];

        int divider = int(ceil((double)(max+1)/bucket));

        for(size_t i = 0; i<n; i++) {
            j = floor((double)dane[i].arr[k]/divider);
            if(j<0)
                j = 0;
            pom[j].push_back(make_pair(dane[i].arr[k], i));
        }
            for(int i = 0; i<bucket; i++)
                sort(pom[i].begin(), pom[i].end());

        int m = 0;
        for(int i = 0; i<bucket; i++) {
            for(auto it = pom[i].begin(); it != pom[i].end(); ++it) {
                dane_sort[m] = dane[it->second];
                m++;
            }
        }
        dane = dane_sort;
}

int main()
{
    ios_base::sync_with_stdio(false);
    size_t n, m;
    cin >> n;
    size_t j = 0;
    vector<data> dane(n);

    while(n) {
        cin >> j;
        j--;
        cin >> dane[j].arr[0] >> dane[j].arr[1];
        cin >> m;
        for(size_t i=2; i<6; i++) {
            if(m) {
                cin >> dane[j].arr[i];
                m--;
            }
            else
                dane[j].arr[i] = -1;
        }
        n--;
    }
    int sortowanie[4];
    for(int i=3; i>=0; i--) {
        cin >> sortowanie[i];
    }
    bool is = false;
    for(int i=0; i<4; i++) {
        if(is && sortowanie[i] == 4) {
            bucket(dane,5);
            bucket(dane,4);
            bucket(dane,3);
            bucket(dane,2);
        }
        else if(is)
            bucket(dane, sortowanie[i]-2);
        else if(sortowanie[i] == 1)
            is = true;
    }

    long long int result = 0;

    for(size_t i=0; i<dane.size(); i++) {
        result += (dane[i].arr[1] * i);
    }

    cout << result%100000007;
    return 0;
}