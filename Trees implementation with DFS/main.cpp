#include <iostream>

using namespace std;
struct node{
    int i;
    node *l_son, *r_brother;
};

struct node * newNode(int i) {
    struct node * temp = new node;
    temp->i = i;
    temp->l_son = nullptr;
    temp->r_brother = nullptr;
    return temp;

}
struct node* insert(struct node * Node, int i) {
    if(Node == nullptr)
        return newNode(i);
    if(Node->l_son == nullptr) {
        node * l_son = insert(Node->l_son, i);
        Node->l_son = l_son;
        return l_son;
    }
    if(Node->l_son->i == i)
        return Node->l_son;

    if(Node->l_son->r_brother != nullptr) {
        Node = Node->l_son;
        while(Node->r_brother != nullptr) {
            Node = Node->r_brother;
            if(Node->i == i)
                return Node;
        }
        node * r_brother = insert(Node->r_brother, i);
        Node->r_brother = r_brother;
        return r_brother;
    } else {
        Node = Node->l_son;
        node * r_brother = insert(Node->r_brother, i);
        Node->r_brother = r_brother;
        return r_brother;
    }
}
void preorder(node * Node){
        cout << Node->i << ' ';
    if(Node != nullptr) {
        if(Node->l_son!=nullptr) {
            preorder(Node->l_son);
        }
        if(Node->r_brother!=nullptr) {
            preorder(Node->r_brother);
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    int n, x, y;

    struct node *root = nullptr;

    root = insert(root, 0);

    struct node * temp = root;

   cin >> n;

    while(n) {
        cin >> x;
        while(x) {
            cin >> y;
            root = insert(root, y);
            x--;
        }
        root = temp;
        n--;
    }

    preorder(root->l_son);

    return 0;
}