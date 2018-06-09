#include <iostream>
#include "CircularQueue.h"

using namespace std;

int main()
{
    CircularQueue<int> c1(17);

    cout << "Circular test" << endl;

    for (int i = 0; i < 10; i++)
    {
        c1.enqueue(i);
    }
    for (int i = 0; i < 10; i++)
    {
        cout << c1.dequeue();
    }
    for (int i = 0; i < 10; i++)
    {
        c1.enqueue(i);
    }
    for (int i = 0; i < 10; i++)
    {
        cout << c1.dequeue();
    }
    cout << endl << "01234567890123456789 expected" << endl << endl;

    for (int i = 10; i > 0; i--)
    {
        c1.enqueue(i);
    }

    cout << "Peek test" << endl;

    cout << c1.peek() << endl;

    cout << "10 expected" << endl << endl << "Depth test" << endl;

    cout << c1.depth() << endl;

    cout << "10 expected" << endl << endl << "Copy Constructor test" << endl;

    CircularQueue<int> c2(c1);
    for (int i = 0; i < 10; i++)
    {
        cout << c2.dequeue();
    }

    cout << endl << "10987654321 expected" << endl << endl << "Empty test" << endl;

    if (c2.empty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }

    cout << endl << "Full test" << endl;
    int k = 1;
    while (c1.enqueue(22))
    {
        cout << k;
        k++;
    }

    cout << endl << "1234567 expected" << endl;
    if (c1.full())
    {
        cout << "Queue is full" << endl;
    }
    else
    {
        cout << "Queue is not full" << endl;
    }

    cout << endl << "Copy Assignment test" << endl;
    c2 = c1;
    for (int i = 0; i < 17; ++i)
    {
        cout << c2.dequeue();
    }

    cout << endl << "1098765432122222222222222 expected" << endl << endl << "Move Constructor test" << endl;

    CircularQueue<int> c3 = move(c1);
    if(c3.full() && c1.empty())
    {
        cout << "Queue is moved" << endl;
    }
    else
    {
        cout << "Queue is not moved" << endl;
    }

    cout << endl << "Move Assignment test" << endl;
    c1 = move(c3);
    if(c1.full() && c3.empty())
    {
        cout << "Queue is moved" << endl;
    }
    else
    {
        cout << "Queue is not moved" << endl;
    }

    return 0;
}