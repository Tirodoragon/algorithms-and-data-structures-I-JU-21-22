#include <iostream>
#include <cstdio>

using namespace std;

typedef int elementtype;
struct celltype {
    elementtype element;
    celltype * next;
};

typedef celltype * position;

class Lista {
    protected:
        position l;                         // wskaźnik do głowy listy

    public:
    Lista();                                // konstruktor
    ~Lista();                               // destruktor
    void Insert(elementtype x, position p);
    void Delete(position p);
    elementtype Retrieve(position p);
    position Locate(elementtype x);
    position First();
    position Next(position p);
    position Previous(position p);
    position END();
};

Lista::Lista() {        // tworzy głowę
    l = new celltype;
    l -> next = NULL;
}

Lista::~Lista() {
    position tmp;
    if ((l != NULL) && (l -> next != NULL)) {
        while (l -> next != NULL) {
            tmp = l -> next;
            l -> next = tmp -> next;
            delete tmp;
        }
    }
}

void Lista::Insert(elementtype x, position p) {
    position tmp;
    tmp = p -> next;
    p -> next = new celltype;
    p -> next -> element = x;
    p -> next -> next = tmp;
}

void Lista::Delete(position p) {
    position tmp;
    tmp = p -> next;
    p -> next = p -> next -> next;
    delete tmp;
}

elementtype Lista::Retrieve(position p) {
    if (p -> next != NULL) {
        return p -> next -> element;
    }

    return -1;
}

position Lista::Locate(elementtype x) {
    position tmp;
    tmp = l;
    while (tmp -> next != NULL) {           // dopóki tmp nie wskazuje na ostatni rekord listy
        if (tmp -> next -> element == x) {
            return tmp;
        }
        tmp = tmp -> next;
    }

    return tmp;                             // zwraca ENDL, jeśli wcześniej nie został znaleziony rekord z elementem x
}

position Lista::First() {
    return l;
}

position Lista::Next(position p) {
    return p -> next;
}

position Lista::Previous(position p) {
    position tmp;
    tmp = l;
    while (tmp -> next != p) {
        tmp = tmp -> next;
    }

    return tmp;
}

position Lista::END() {
    position tmp;
    tmp = l;
    while (tmp -> next != NULL) {
        tmp = tmp -> next;
    }

    return tmp;
}

void print(Lista *l) {
    position i = l -> First() -> next;
    while (i != NULL) {
        printf(" %d,", i -> element);
        i = i -> next;
    }
    printf("\n");
}

int main() {
    Lista l;

    l.Insert(5, l.First());
    print(&l);

    l.Insert(2, l.First());
    print(&l);

    l.Insert(1, l.Next(l.First()));
    print(&l);

    l.Delete(l.Locate(1));
    print(&l);
}