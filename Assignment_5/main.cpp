#include <iostream>
#include <cstdio>

using namespace std;

const int maxlength = 4;
typedef int elementtype;
typedef int position;
class Kolejka {
    protected:
        elementtype Queue[maxlength];
        position Front;                 // Indeks elementu czołowego
        position Rear;                  // Indeks ostatniego elementu

    public:
        Kolejka();
        int AddOne(int i);
        void Enqueue(elementtype x);
        void Dequeue();
        elementtype FrontElem();
        void Makenull();
        bool Empty();
};

Kolejka::Kolejka() {
    Front = 0;
    Rear = maxlength - 1;
}

int Kolejka::AddOne(int i) {
    return ((i + 1) % maxlength);
}

void Kolejka::Enqueue(elementtype x){
    if (AddOne(AddOne(Rear)) != Front) {
        Rear = AddOne(Rear);
        Queue[Rear] = x;
    }
}

void Kolejka::Dequeue() {
    if (!Empty()) {
        Front = AddOne(Front);
    }
}

elementtype Kolejka::FrontElem() {
    if (!Empty()) {
        return Queue[Front];
    }

    return -1;
}

void Kolejka::Makenull() {
    Front = 0;
    Rear = maxlength - 1;
}

bool Kolejka::Empty() {
    return (AddOne(Rear) == Front);
}

int main() {
    Kolejka k;

    if (k.Empty() == 1) {
        printf("Kolejka jest pusta\n");
    }
    else {
        printf("Kolejka nie jest pusta\n");
    }

    k.Enqueue(5);

    if (k.Empty() == 1) {
        printf("Kolejka jest pusta\n");
    }
    else {
        printf("Kolejka nie jest pusta\n");
    }

    if(k.FrontElem() == -1) {
        printf("Blad\n");
    }
    else {
        printf("%d\n", k.FrontElem());
    }
    
    k.Dequeue();

    if (k.Empty() == 1) {
        printf("Kolejka jest pusta\n");
    }
    else {
        printf("Kolejka nie jest pusta\n");
    }

    k.Enqueue(4);
    k.Enqueue(3);
    k.Enqueue(2);

    if(k.FrontElem() == -1) {
        printf("Blad\n");
    }
    else {
        printf("%d\n", k.FrontElem());
    }

    k.Enqueue(1);

    if(k.FrontElem() == -1) {
        printf("Blad\n");
    }
    else {
        printf("%d\n", k.FrontElem());
    }

    k.Dequeue();

    if(k.FrontElem() == -1) {
        printf("Blad\n");
    }
    else {
        printf("%d\n", k.FrontElem());
    }

    k.Enqueue(6);
    if(k.FrontElem() == -1) {
        printf("Blad\n");
    }
    else {
        printf("%d\n", k.FrontElem());
    }

    k.Dequeue();
    k.Dequeue();

    if(k.FrontElem() == -1) {
        printf("Blad\n");
    }
    else {
        printf("%d\n", k.FrontElem());
    }

    k.Makenull();

    if (k.Empty() == 1) {
        printf("Kolejka jest pusta\n");
    }
    else {
        printf("Kolejka nie jest pusta\n");
    }
}