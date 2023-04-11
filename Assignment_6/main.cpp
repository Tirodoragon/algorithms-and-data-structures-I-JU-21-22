#include <iostream>
#include <cstdio>

using namespace std;

typedef int elementtype;
struct celltype {
    elementtype element;
    celltype * next;
};
typedef celltype * position;
class Queue {
    protected:
        position Front;                 // wskaźnik do głowy listy
        position Rear;                  // wskaźnik do ostatniego elementu
    public:
        Queue();                        //konstruktor
        ~Queue();                       //destruktor
        void Enqueue(elementtype x);
        void Dequeue();
        elementtype FrontElem();
        bool Empty();
 };

Queue::Queue() {
    Front = new celltype;
    Rear = Front;
    Front -> next = NULL;
}

Queue::~Queue() {
    position tmp;

    while (Front -> next != NULL) {
        tmp = Front;
        Front = Front -> next;
        delete tmp;
    }
    delete Front;
}

void Queue::Enqueue(elementtype x) {
    position p = new celltype;
    p -> element = x;
    p -> next = NULL;
    Rear -> next = p;
    Rear = p;
}

void Queue::Dequeue() {
    if (!Empty()) {
        position p = Front;
        Front = Front -> next;
        delete p;
 }
}

elementtype Queue::FrontElem() {
    if (!Empty()) {
        return Front -> next -> element;
    }

    return -1;
}

bool Queue::Empty() {
    return (Front -> next == NULL);
}

int main() {
    Queue q;

    if (q.Empty() == 1) {
        printf("Kolejka jest pusta\n");
    }
    else {
        printf("Kolejka nie jest pusta\n");
    }

    q.Enqueue(5);

    if (q.Empty() == 1) {
        printf("Kolejka jest pusta\n");
    }
    else {
        printf("Kolejka nie jest pusta\n");
    }

    if(q.FrontElem() == -1) {
        printf("Blad\n");
    }
    else {
        printf("%d\n", q.FrontElem());
    }
    
    q.Dequeue();

    if (q.Empty() == 1) {
        printf("Kolejka jest pusta\n");
    }
    else {
        printf("Kolejka nie jest pusta\n");
    }

    q.Enqueue(4);
    q.Enqueue(3);
    q.Enqueue(2);

    if(q.FrontElem() == -1) {
        printf("Blad\n");
    }
    else {
        printf("%d\n", q.FrontElem());
    }

    q.Enqueue(1);

    if(q.FrontElem() == -1) {
        printf("Blad\n");
    }
    else {
        printf("%d\n", q.FrontElem());
    }

    q.Dequeue();

    if(q.FrontElem() == -1) {
        printf("Blad\n");
    }
    else {
        printf("%d\n", q.FrontElem());
    }

    q.Enqueue(6);
    if(q.FrontElem() == -1) {
        printf("Blad\n");
    }
    else {
        printf("%d\n", q.FrontElem());
    }

    q.Dequeue();
    q.Dequeue();

    if(q.FrontElem() == -1) {
        printf("Blad\n");
    }
    else {
        printf("%d\n", q.FrontElem());
    }
}