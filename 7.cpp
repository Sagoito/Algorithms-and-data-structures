#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    int t, n, m;
    string nazwisko, nazwisko2;

    bool is;
    cin >> t;

    while(t) {
        is = true;

        cin >> n >> m;
        map<string, vector<string>> mapa;
        map<string, int> stopien;
        for(int i = 0; i<n; i++) {
            cin >> nazwisko;
            stopien[nazwisko] = 0;
        }
        for(int i = 0; i<m; i++) {
            cin >> nazwisko;
            cin >> nazwisko2;
            mapa[nazwisko].push_back(nazwisko2);
            //zapisywac stopien elementu w mapie
            stopien[nazwisko2]++;

        }
        for(int j = 0; j<n; j++) {
           cin >> nazwisko;

           if(stopien[nazwisko] != 0) {
               for(;j+1<n;j++)
                   cin >> nazwisko;
               is = false;
               break;
           }
           for(auto it = mapa[nazwisko].begin(); it != mapa[nazwisko].end(); ++it) {
                    stopien[*it]--;
               }
           }
        if(is)
            cout << "TAK" << "\n";
        else
            cout << "NIE" << "\n";
        t--;
    }
    return 0;
}