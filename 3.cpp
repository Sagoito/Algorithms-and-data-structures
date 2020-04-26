#include <iostream>



using namespace std;

class list {
    class node {
    public:
        string data = "";
        long long int x = 0;
        node *next = nullptr, *prev = nullptr;

        //konstruktor node
        node(string data, long long int x):data(data),x(x) {
                next = prev = this;
        }
    };
public:
    node * el = nullptr;
    long long int size = 0;

    void add(string data, long long int x) {
        node * a = new node(data, x); //stworzenie nowego elementu

        if(size == 0)
            el = a; //jesli nie ma elementow wystarczy dodac stworzony element do listy
        else {
            node * l = el->prev; // element z lewej
                //poprzedni i następny wskazuje na nowy
                //nowy wskazuje na nastepny i poprzedni
                // l a el

                el->prev = a;
                l->next = a;

                a->next = el;
                a->prev = l;
                if(size==1)
                    el->next = a;
        }
        size++;
    }
    void erase() {
        if(size == 1){
            delete el;
        }
        else {
            node * temp = el;
            el = el->next;
            el->prev = temp->prev;
            temp->prev->next = el;
            delete temp;
        }
        size--;
    }
};



long long int check(long long int s, long long int size) {
    long long int c = s%size;
    if(abs(c) > size/2) {
        if(c > 0)
            c -=size;
        else if(c < 0)
            c = size + c;
    }
    return c;
}



int main()
{
    long long int n, s; //rozmiar listy slow oraz s numer slowa startowego

    string result = "";

    string data = "";
    long long int x = 0;
    long long int y = 0;
    long long int p = 0; //rozmiar drugiej listy
    list * List = new list();

    cin >> n >> s;

    while(n) {
        cin >> data >> x;
        List->add(data, x);
        n--;
    }

cin >> p;
while(List->size) {

    s = check(s, List->size);
    while(s != 0) {
        if(s<0) {
            List->el = List->el->prev;
            s++;
        }
        else if(s>0) {
            List->el = List->el->next;
            s--;
        }
    }

    if(List->el->x == 0) {
        cin >> data >> x >> y;
        s = List->el->x = y;
        List->add(data, x);
        s = List->el->x;

    } else {
        result += List->el->data;
        result += " ";
        if(List->el->x > 0)
            List->el->x--;
        s = List->el->x;
        List->erase();
    }
}

    cout << result;
    return 0;
}