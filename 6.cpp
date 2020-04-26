#include <iostream>
#include <queue>
using namespace std;


struct el {
    int x, y;

    el(int x, int y):x(x),y(y) {}
};

int main()
{
    //kolejka

    queue<el> myQueue;

    int x, y;
    int SposX, SposY;
    cin >> x >> y;

    string line;

    char a[x][y];
    bool b[x][y];
    for(int i = 0; i<x; i++) {
        cin >> line;

        for(int j = 0; j<y; j++) {

            a[i][j] = line[j];
            b[i][j] = false;

            if(a[i][j] == *"#") {
                b[i][j] = true;
            } else if(a[i][j] == *"S") {
                b[i][j] = true;
                SposX = i;
                SposY = j;
            }
        }
    }


    myQueue.push(el(SposX,SposY));

    int dest[x][y];
    int mon[x][y];

    for(int i=0; i<x; i++)
        for(int j=0; j<y; j++)
            dest[i][j] = mon[i][j] = 0;

    el temp = el(0,0);

    while(!myQueue.empty()) {

        temp = myQueue.front();


        if(a[temp.x][temp.y] == *"X")
            cout << dest[temp.x][temp.y] << " " << mon[temp.x][temp.y] << "\n";

        //w gore
        if(temp.x - 1 >= 0) {
            if(b[temp.x - 1][temp.y] == false) {
                b[temp.x - 1][temp.y] = true;
                if(a[temp.x - 1][temp.y] == *"M") {
                    myQueue.push(el(temp.x-1, temp.y));
                    dest[temp.x-1][temp.y] = dest[temp.x][temp.y] + 1;
                    mon[temp.x-1][temp.y] = mon[temp.x][temp.y] + 1;
                }
                else {
                    myQueue.push(el(temp.x-1, temp.y));
                    dest[temp.x-1][temp.y] = dest[temp.x][temp.y] + 1;
                    mon[temp.x-1][temp.y] = mon[temp.x][temp.y];
                }
            } else if(a[temp.x - 1][temp.y] != *"#"
                      && dest[temp.x - 1][temp.y] >= dest[temp.x][temp.y]+1
                      && mon[temp.x - 1][temp.y] >= mon[temp.x][temp.y]) {
                if(a[temp.x - 1][temp.y] == *"M"){
                    if(mon[temp.x - 1][temp.y] >= mon[temp.x][temp.y] + 1) {
                        dest[temp.x-1][temp.y] = dest[temp.x][temp.y] + 1;
                        mon[temp.x-1][temp.y] = mon[temp.x][temp.y] + 1;
                    }
                } else {
                    dest[temp.x-1][temp.y] = dest[temp.x][temp.y] + 1;
                    mon[temp.x-1][temp.y] = mon[temp.x][temp.y];
                    }
            }
        }
        //w dol
        if(temp.x + 1  < x) {
            if(b[temp.x + 1][temp.y] == false) {
                b[temp.x + 1][temp.y] = true;
                if(a[temp.x + 1][temp.y] == *"M") {
                    myQueue.push(el(temp.x+1, temp.y));
                    dest[temp.x+1][temp.y] = dest[temp.x][temp.y] + 1;
                    mon[temp.x+1][temp.y] = mon[temp.x][temp.y] + 1;
                }
                else {
                    myQueue.push(el(temp.x+1, temp.y));
                    dest[temp.x+1][temp.y] = dest[temp.x][temp.y] + 1;
                    mon[temp.x+1][temp.y] = mon[temp.x][temp.y];
                }
            } else if(a[temp.x + 1][temp.y] != *"#"
                      && dest[temp.x + 1][temp.y] >= dest[temp.x][temp.y]+1
                      && mon[temp.x + 1][temp.y] >= mon[temp.x][temp.y]) {
                if(a[temp.x + 1][temp.y] == *"M"){
                    if(mon[temp.x + 1][temp.y] >= mon[temp.x][temp.y] + 1) {
                        dest[temp.x+1][temp.y] = dest[temp.x][temp.y] + 1;
                        mon[temp.x+1][temp.y] = mon[temp.x][temp.y] + 1;
                    }
                } else {
                    dest[temp.x+1][temp.y] = dest[temp.x][temp.y] + 1;
                    mon[temp.x+1][temp.y] = mon[temp.x][temp.y];
                    }
            }
        }
        //w prawo
        if(temp.y + 1 < y) {
            if(b[temp.x][temp.y + 1] == false) {
                b[temp.x][temp.y + 1] = true;
                if(a[temp.x][temp.y + 1] == *"M") {
                    myQueue.push(el(temp.x, temp.y + 1));
                    dest[temp.x][temp.y + 1] = dest[temp.x][temp.y] + 1;
                    mon[temp.x][temp.y + 1] = mon[temp.x][temp.y] + 1;
                }
                else {
                    myQueue.push(el(temp.x, temp.y + 1));
                    dest[temp.x][temp.y + 1] = dest[temp.x][temp.y] + 1;
                    mon[temp.x][temp.y + 1] = mon[temp.x][temp.y];
                }
            } else if(a[temp.x][temp.y + 1] != *"#"
                      && dest[temp.x][temp.y + 1] >= dest[temp.x][temp.y]+1
                      && mon[temp.x][temp.y + 1] >= mon[temp.x][temp.y]) {
                if(a[temp.x][temp.y + 1] == *"M"){
                    if(mon[temp.x][temp.y + 1] >= mon[temp.x][temp.y] + 1) {
                        dest[temp.x][temp.y + 1] = dest[temp.x][temp.y] + 1;
                        mon[temp.x][temp.y + 1] = mon[temp.x][temp.y] + 1;
                    }
                } else {
                    dest[temp.x][temp.y + 1] = dest[temp.x][temp.y] + 1;
                    mon[temp.x][temp.y + 1] = mon[temp.x][temp.y];
                    }
            }
        }
        //w lewo
        if(temp.y - 1 >= 0) {
            if(b[temp.x][temp.y - 1] == false) {
                b[temp.x][temp.y - 1] = true;
                if(a[temp.x][temp.y - 1] == *"M") {
                    myQueue.push(el(temp.x, temp.y - 1));
                    dest[temp.x][temp.y - 1] = dest[temp.x][temp.y] + 1;
                    mon[temp.x][temp.y - 1] = mon[temp.x][temp.y] + 1;
                }
                else {
                    myQueue.push(el(temp.x, temp.y - 1));
                    dest[temp.x][temp.y - 1] = dest[temp.x][temp.y] + 1;
                    mon[temp.x][temp.y - 1] = mon[temp.x][temp.y];
                }
            } else if(a[temp.x][temp.y - 1] != *"#"
                      && dest[temp.x][temp.y - 1] >= dest[temp.x][temp.y]+1
                      && mon[temp.x][temp.y - 1] >= mon[temp.x][temp.y]) {
                if(a[temp.x][temp.y - 1] == *"M"){
                    if(mon[temp.x][temp.y - 1] >= mon[temp.x][temp.y] + 1) {
                        dest[temp.x][temp.y - 1] = dest[temp.x][temp.y] + 1;
                        mon[temp.x][temp.y - 1] = mon[temp.x][temp.y] + 1;
                    }
                } else {
                    dest[temp.x][temp.y - 1] = dest[temp.x][temp.y] + 1;
                    mon[temp.x][temp.y - 1] = mon[temp.x][temp.y];
                    }
            }
        }
        myQueue.pop();
    }


    return 0;
}