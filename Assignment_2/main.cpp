#include <iostream>
#include <cstdio>

using namespace std;

typedef int elementtype, position;
const int maxlength = 10;
struct List {
	elementtype elements[maxlength];
	int last;                           // indeks ostatniego elementu listy
};

const int MIN = -10000000;

position END(List l) {
    return l.last + 1;
}

position First(List l) {
    return 0;
}

position Next(position p, List l) {
    if (p > l.last) {
        return -1;
    }

    return p + 1;
}


position Previous(position p, List l)  {
    if (p <= First(l)) {
            return -1;
    }

    return p - 1;
}

position Locate(elementtype x, List l) { // zwraca pozycje x w l, gdy nie ma x w l zwraca end(l)
    for (int i = 0; i < END(l); i++) {
        if (l.elements[i] == x) {
            return i;
        }
    }

    return END(l);
}

elementtype Retrieve(position p, List l) {
    if (p >= First(l) || p <= l.last) {
        return l.elements[p];
    }

    return MIN;
}

bool Insert(int x, position p, List &l) {
    if (l.last == maxlength) {
        return false;
    }

    if (p >= First(l) || p <= l.last) {
        if (p == END(l)) {
            l.elements[p] = x;

            l.last++;

            return true;
        }

        for (int i = END(l); i > p; i--) {
            l.elements[i] = Retrieve(Previous(i, l), l);
        }

        l.elements[p] = x;

        l.last++;

        return true;
    }

    return false;
}

bool Delete(position p, List &l) {
    if (p >= First(l) || p <= l.last) {
        for (int i = l.last; i != p; i--) {
            l.elements[Previous(i, l)] = Retrieve(i, l);
        }

        l.elements[l.last] = 0;

        l.last--;

        return true;
    }

    return false;
}

void print(List l) {
	position i = First(l);
	while (i != END(l)) {
		printf("  %d,", Retrieve(i, l));
		i = Next(i, l);
	}
	printf("\n");
}

void addDuplicates(List &l) {
    int end = END(l);
    for (int i = First(l); i < end; i++) {
        Insert(Retrieve(i, l), END(l), l);
    }
}

void removeDuplicates(List &l) {
    for (int i = First(l); i <= l.last; i++) {
        for (int j = First(l); j <= l.last; j++) {
            if(l.elements[i] == l.elements[j] && i != j) {
                Delete(j, l);
            }
        }
    }
}

int main() {
    List l;
    l.last = -1;

    Insert(100, First(l), l);
    print(l);

    for (int i = 0; i < 3; i++) {
        Insert(i, First(l), l);
    }
    print(l);

    Insert(20, Previous(END(l), l), l);
    print(l);
    
    Delete(Locate(20, l), l);
    print(l);

    addDuplicates(l);
    print(l);

    removeDuplicates(l);
    print(l);

    Insert(5, Locate(100, l), l);
    print(l);
}