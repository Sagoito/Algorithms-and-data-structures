#include <iostream>
#include <vector>
using namespace std;

int main() {
    unsigned int x, y, t;
    unsigned int xmin = 1, ymin = 1;
    cin >> x >> y >> t;

    unsigned int xmax = x, ymax = y;
    unsigned int a = xmax/2, b = ymax/2;

    unsigned int n = 0;
    string direction = "";

    vector<unsigned int> result;
    while(n != t) {

        direction = test(a,b,n);

        if(direction.length() == 0) {
            result.push_back(a);
            result.push_back(b);
            n++;
            a = xmax/2;
            b = ymax/2;
            xmax = x;
            ymax = y;
            xmin = 1;
            ymin = 1;
        } else if(direction == "N") {
            ymin = b + 1;
        } else if(direction == "NE") {
            ymin = b + 1;
            xmin = a + 1;
        } else if(direction == "E") {
            xmin = a + 1;
        } else if(direction == "SE") {
            ymax = b;
            xmin = a + 1;
        } else if(direction == "S") {
            ymax = b;
        } else if(direction == "SW") {
            ymax = b;
            xmax = a;
        } else if(direction == "W") {
            xmax = a;
        } else if(direction == "NW") {
            ymin = b + 1;
            xmax = a;
        }
        b = (ymin + ymax)/2;
        a = (xmin + xmax)/2;
    }
    for(vector<unsigned int>::const_iterator i = result.begin(); i != result.end(); i+=2) {
        cout << *i << " " << *(i+1) << "\n";
    }
}s