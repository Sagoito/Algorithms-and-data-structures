#include <iostream>
#include <cmath>

using namespace std;

int main()

{

  ios_base::sync_with_stdio(0);

  int t = 0; //liczba zestawów danych

  int n = 0; //liczba tropów

  int m = 0; //liczba metod badawczych

  int x = 0; //liczba zbadanych tropów

  int y = 0; //liczba nowych tropów

  cin >> t;

  while (t > 0) {


    int dif = 0; //różnica pomiedzy x - y

    int counter = 0; //zliczenie ilosci uzycia okreslonej metody

    int max = 0; //najwiekszy x

    cin >> n >> m;

    while (m > 0) {

      cin >> x >> y;

      if (x > max)

        max = x;

      if ((x - y) > dif) {
        dif = x - y; //szukanie najwiekszej roznicy

      }

      m--;

    }

    if (dif == 0 && n > max)
      cout << "BRAK METOD" << endl;
    else {

        n -= max;
        counter++;

        if(n>0) {
            counter += int(ceil(double(n) / double(dif))); //obliczanie ile razy od n trzeba bedzie odjac roznice
        }
      cout << counter << endl;

    }

    t--;

  }

  return 0;

}