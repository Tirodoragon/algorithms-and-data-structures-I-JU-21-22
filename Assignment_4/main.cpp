#include <iostream>
#include <cstdio>

using namespace std;

const int maxlength = 3;
typedef int elementtype;
typedef int position;
class Stos {
        int S[maxlength];
        position Top;               //szczyt stosu
    public:
        Stos();
        void Push(elementtype x);
        void Pop();
        bool Empty();
        elementtype TopElem();
        void Makenull();
};

Stos::Stos() {
    Top = -1;
}

void Stos::Push(elementtype x) {
    if (Top < maxlength - 1) {
        Top++;
        S[Top]= x;
    }
}

void Stos::Pop() {
    if (Top >= 0) {
        Top--;
    }
}

bool Stos::Empty() {
    return (Top == -1);
}

elementtype Stos::TopElem() {
    if (Top >= 0) {
        return S[Top];
    }
    return -1;
}

void Stos::Makenull() {
    Top = -1;
}

int main() {
    Stos s;

    if (s.Empty() == 1) {
        printf("Stos jest pusty\n");
    }
    else {
        printf("Stos nie jest pusty\n");
    }

    s.Push(5);

    if(s.TopElem() == -1) {
        printf("Blad\n");
    }
    else {
        printf("%d\n", s.TopElem());
    }

    if (s.Empty() == 1) {
        printf("Stos jest pusty\n");
    }
    else {
        printf("Stos nie jest pusty\n");
    }

    s.Pop();
    
    if (s.Empty() == 1) {
        printf("Stos jest pusty\n");
    }
    else {
        printf("Stos nie jest pusty\n");
    }

    s.Push(2);
    s.Push(3);

    if(s.TopElem() == -1) {
        printf("Blad\n");
    }
    else {
        printf("%d\n", s.TopElem());
    }

    //s.Makenull();
    s.Push(7);
    s.Push(9);

    if(s.TopElem() == -1) {
        printf("Blad\n");
    }
    else {
        printf("%d\n", s.TopElem());
    }

    if (s.Empty() == 1) {
        printf("Stos jest pusty\n");
    }
    else {
        printf("Stos nie jest pusty\n");
    }
}