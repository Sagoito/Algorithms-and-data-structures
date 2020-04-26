#include <iostream>

using namespace std;

class stack {
    friend class queue;
    class node {
        int i;
        int max_el;
        int min_el;
        node * next;
    public:
        node(int i, int max_el, int min_el):i(i),max_el(max_el),min_el(min_el) {}
        int getI() {
            return i;
        }
        friend class stack;
    };
    int sum = 0;
    int size = 0;

    node * el = nullptr;
public:

    void push(int i) {
        if(size == 0) {
            node * a = new node(i,i,i);
            a->next = el;
            el = a;
        }
        else {
            int max_el = getMax(), min_el = getMin();
            if(getMax() < i)
                max_el = i;
            if(getMin() > i)
                min_el = i;
            node * a = new node(i, max_el, min_el);
            a->next = el;
            el = a;
        }
        sum += i;
        size++;
    }
    int pop() {
        if(el == nullptr)
            return NULL;
        int i = el->i;

        node * temp = el;

        el = el->next;

        delete temp;
        size--;
        sum-=i;

        return i;
    }
    int getSum() {
        return sum;
    }
    node * top() {
        return el;
    }
    bool empty() {
        return size == 0;
    }
    int getMin() {
        if(el == nullptr)
            return 0;
        return el->min_el;
    }
    int getMax() {
        if(el == nullptr)
            return 0;
        return el->max_el;
    }
};

class queue {
public:
    stack * s1;
    stack * s2;

public:
    queue() {
        s1 = new stack();
        s2 = new stack();
    }
    void enqueue(int x) {
        s1->push(x);
    }
    int dequeue() {
        if(s2->empty())
            while(!s1->empty())
                s2->push(s1->pop());
        return s2->pop();
    }
    int front() {
        if(s2->empty())
           while(!s1->empty())
               s2->push(s1->pop());

        if(s2->empty())
            return NULL;
        return s2->top()->getI();
    }
    int getSum() {
        return s1->sum + s2->sum;
    }
    int min() {
        if(s1->getMin()<s2->getMin())
            return s1->getMin();
        else
            return s2->getMin();
    }
    int max() {
        if(s1->getMax() > s2->getMax())
            return s1->getMax();
        else
            return s2->getMax();
    }
};
int main()
{
    queue q1, q2;

    int n, n2, v;

    cin >> n >> v;

    n2 = 0;


    int i;
    string name[n];
    string f, s;
    while(n > n2) {
        cin >> f >> s;
        name[n2] = f;
        name[n2] += " ";
        name[n2] += s;

        cin >> i;

        if(n2 < 0.5*n)
            q1.enqueue(i);
        else
            q2.enqueue(i);

        n2++;
    }


    int index = -1;
    int sum = 2147483647;


    for(int i=0; i<n/2; i++) {
        if(abs(q1.max() - q1.min()) <= v && abs(q2.max() - q2.min()) <= v) {
            if(sum > abs(q1.getSum() - q2.getSum())) {
                    index = i;
                    sum = abs(q1.getSum() - q2.getSum());
            }
        }
        q1.enqueue(q2.front());
        q2.dequeue();
        q2.enqueue(q1.front());
        q1.dequeue();
    }


    if(index >= 0) {
        for(int i=0; i<n; i++) {
            cout << name[index%n] << '\n';
            index++;
        }
    }
    else
        cout << "NIE";
    return 0;
}