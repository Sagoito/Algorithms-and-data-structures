#include <iostream>
#include <string>
using namespace std;

struct lane {
    string name;
    int x;
};

void InsertionSort(lane tab[], int n) {


    lane temp;
    int j;
    for (int i = 1; i < n; i++) {
      temp = tab[i];

      for (j = i - 1; j >= 0 && ((tab[j].x < temp.x) || ((tab[j].x == temp.x) && tab[j].name > temp.name)); j--) {
        tab[j + 1] = tab[j];
      }

      tab[j + 1]= temp;

    }
}
int main()
{
    ios_base::sync_with_stdio(0);

    int t = 0; //zestaw danych
    int n = 0; //liczba nazwisk
    int p = 0; //liczba nazwisk do wyświetlenia

    cin >> t;






        while(t)
        {

            cin >> n >> p;
            lane arr[n];
            for(int i=0; i<n; i++) {
                cin>>arr[i].name>>arr[i].x;
            }
        InsertionSort(arr, n);

        long long int sum = 1;
        int counter = 0;


        for(int i=0; i<n; i++) {
            sum += (arr[i].x * counter) + 1;
            counter++;
            if(p>0)
                cout<<arr[i].name<<" ";
            p--;
        }
            sum--;
            cout << endl;
            cout << sum%1000003 << endl;

                t--;
        }


    return 0;
}