#include <iostream>

using namespace std;

typedef int Telement;
struct Node {
    Telement info;
    Node * left;
    Node * right;
};
typedef Node *PNode;

class BinaryTree {
    protected:
        PNode T;
    public:
        BinaryTree();
        PNode PARENT(PNode n);
        PNode PARENT1(PNode n,PNode T);
        PNode LEFT_CHILD(PNode n);
        PNode RIGHT_CHILD(PNode n);
        Telement GetLabel(PNode n);
        PNode BuildTree1(int m);
        void BuildTree(int m);
        PNode ROOT();
        void MAKENULL(PNode p);
        void PreOrder(PNode t);
        void InOrder(PNode t);
        void PostOrder(PNode t);
};

BinaryTree::BinaryTree() {
    T = NULL;
}

PNode BinaryTree::PARENT(PNode n) {
    if (n == T) {
        return NULL;
    }
    return PARENT1(n, T);
}

PNode BinaryTree::PARENT1(PNode n ,PNode T) {
    if ((T -> left == n) || (T -> right == n)) {
        return T;
    }
    PNode tmp1 = NULL;
    PNode tmp2 = NULL;
    if (T -> left != NULL) {
        tmp1 = PARENT1(n, T -> left);
    }
    if (T -> right != NULL) {
        tmp2 = PARENT1(n, T -> right);
    }
    return (tmp1 != NULL) ? tmp1 : tmp2;
}

PNode BinaryTree::LEFT_CHILD(PNode n) {
    return n -> left;
}

PNode BinaryTree::RIGHT_CHILD(PNode n) {
    return n -> right;
}

Telement BinaryTree::GetLabel(PNode n) {
    if (n != NULL) {
        return n -> info;
    }
    return -1;
}

PNode BinaryTree::BuildTree1(int m) {
    if (m == 0) {
        return NULL;
    }
    int ml, mp;
    Telement x;
    PNode tmp;
    ml = m / 2;
    mp = m - ml - 1;
    cout << "Podaj wartosc do wstawienia: ";
    cin >> x;
    tmp = new Node;
    tmp -> info = x;
    tmp -> left = BuildTree1(ml);
    tmp -> right = BuildTree1(mp);
    return tmp;
}

void BinaryTree::BuildTree(int m) {
    T = BuildTree1(m);
}

PNode BinaryTree::ROOT() {
    return T;
}

void BinaryTree::MAKENULL(PNode p) {
    if (p != NULL) {
        if (p -> left != NULL) {
            MAKENULL(p -> left);
        }
        if (p -> right != NULL) {
            MAKENULL(p -> right);
        }
        delete p;
        p = NULL;
    }
}

void BinaryTree::PreOrder(PNode t) {
    if (t != NULL) {
        cout << t -> info;
        PreOrder(t -> left);
        PreOrder(t -> right);
    }
}

void BinaryTree::InOrder(PNode t) {
    if (t != NULL) {
        InOrder(t -> left);
        cout << t -> info;
        InOrder(t -> right);
    }
}

void BinaryTree::PostOrder(PNode t) {
    if (t != NULL) {
        PostOrder(t -> left);
        PostOrder(t -> right);
        cout << t -> info;
    }
}

int main() {
    BinaryTree bt;

    bt.BuildTree(9);

    cout << bt.GetLabel(bt.ROOT()) << endl;
    cout << bt.GetLabel(bt.LEFT_CHILD(bt.ROOT())) << endl;
    cout << bt.GetLabel(bt.RIGHT_CHILD(bt.ROOT())) << endl;

    cout << bt.GetLabel(bt.PARENT(bt.LEFT_CHILD(bt.ROOT()))) << endl;

    cout << bt.GetLabel(bt.PARENT(bt.RIGHT_CHILD(bt.LEFT_CHILD(bt.ROOT())))) << endl;

    bt.PreOrder(bt.ROOT());
    cout << endl;
    bt.InOrder(bt.ROOT());
    cout << endl;
    bt.PostOrder(bt.ROOT());
    cout << endl;

    // rodzic prawego dziecka prawego dziecka korzenia
    cout << bt.GetLabel(bt.PARENT(bt.RIGHT_CHILD(bt.RIGHT_CHILD(bt.ROOT()))));
    cout << endl;
}