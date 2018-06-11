#include "CircularQueue.h"
#include <iostream>

using namespace std;

int main() {

    CircularQueue<int> intQueue(4);
    cout << "CircularQueue intQueue created" << endl;
    cout << "is the queue empty? " << intQueue.empty() << endl;
    cout << "is the queue full? " << intQueue.full() << endl;
    cout << "depth of? " << intQueue.depth() << endl;
    cout << "Adding int 3 to intQueue : " << intQueue.enqueue(3) << endl;
    cout << "Adding int 23 to intQueue : " << intQueue.enqueue(23) << endl;
    cout << "Adding int 99 to intQueue : " << intQueue.enqueue(99) << endl;
    cout << "Adding int 1 to intQueue : " << intQueue.enqueue(1) << endl;
    cout << "depth of? " << intQueue.depth() << endl;
    cout << "Adding int 92 to intQueue : " << intQueue.enqueue(92) << endl;
    cout << "is the queue empty? " << intQueue.empty() << endl;
    cout << "is the queue full? " << intQueue.full() << endl;
    cout << "dequeueing: " << intQueue.dequeue() << endl;
    cout << "depth of? " << intQueue.depth() << endl;
    cout << "Adding int 1 to intQueue : " << intQueue.enqueue(1) << endl;
    cout << "Adding int 92 to intQueue : " << intQueue.enqueue(92) << endl;
    cout << "is the queue empty? " << intQueue.empty() << endl;
    cout << "is the queue full? " << intQueue.full() << endl;
    cout << "dequeueing: " << intQueue.dequeue() << endl;
    cout << "Peek at next dequeue value: " << intQueue.peek() << endl;
    cout << "is the queue empty? " << intQueue.empty() << endl;
    cout << "is the queue full? " << intQueue.full() << endl;
    cout << "depth of? " << intQueue.depth() << endl;
    cout << "dequeueing: " << intQueue.dequeue() << endl;

    CircularQueue<int> intQueue2(intQueue);
    cout << "intQueue2 created by copying intQueue" << endl;
    cout << "the original intQueue is dequeued: " << intQueue.dequeue() << endl;
    cout << "intQueue depth of? " << intQueue.depth() << endl;
    cout << "intQueue2 depth: " << intQueue2.depth() << endl;

    CircularQueue<int> intQueue3(move(intQueue));
    cout << "intQueue3 created by moving intQueue" << endl;
    cout << "intQueue depth of? " << intQueue.depth() << endl;
    cout << "intQueue3 depth: " << intQueue3.depth() << endl;

    CircularQueue<int> intQueue4;
    intQueue4 = intQueue3;
    cout << "intQueue4 created then = intQueue3" << endl;
    cout << "enqueue 77 to intQueue3: " << intQueue3.enqueue(77) << endl;
    cout << "intQueue3 depth of? " << intQueue3.depth() << endl;
    cout << "intQueue4 depth: " << intQueue4.depth() << endl;

    CircularQueue<int> intQueue5;
    intQueue5 = move(intQueue3);
    cout << "intQueue5 created then = move(intQueue3)" << endl;
    cout << "intQueue3 depth of? " << intQueue3.depth() << endl;
    cout << "intQueue5 depth: " << intQueue5.depth() << endl;

    cout << "-------int test main done!----------" << endl;

    CircularQueue<double> doubleQueue(4);
    cout << "CircularQueue doubleQueue created" << endl;
    cout << "is the queue empty? " << doubleQueue.empty() << endl;
    cout << "is the queue full? " << doubleQueue.full() << endl;
    cout << "depth of? " << doubleQueue.depth() << endl;
    cout << "Adding double 3 to doubleQueue : " << doubleQueue.enqueue(3.0) << endl;
    cout << "Adding double 23 to doubleQueue : " << doubleQueue.enqueue(23.0) << endl;
    cout << "Adding double 99 to doubleQueue : " << doubleQueue.enqueue(99.0) << endl;
    cout << "Adding double 1 to doubleQueue : " << doubleQueue.enqueue(1.0) << endl;
    cout << "depth of? " << doubleQueue.depth() << endl;
    cout << "Adding double 92 to doubleQueue : " << doubleQueue.enqueue(92.0) << endl;
    cout << "is the queue empty? " << doubleQueue.empty() << endl;
    cout << "is the queue full? " << doubleQueue.full() << endl;
    cout << "dequeueing: " << doubleQueue.dequeue() << endl;
    cout << "depth of? " << doubleQueue.depth() << endl;
    cout << "Adding double 1 to doubleQueue : " << doubleQueue.enqueue(1.0) << endl;
    cout << "Adding double 92 to doubleQueue : " << doubleQueue.enqueue(92.0) << endl;
    cout << "is the queue empty? " << doubleQueue.empty() << endl;
    cout << "is the queue full? " << doubleQueue.full() << endl;
    cout << "dequeueing: " << doubleQueue.dequeue() << endl;
    cout << "Peek at next dequeue value: " << doubleQueue.peek() << endl;
    cout << "is the queue empty? " << doubleQueue.empty() << endl;
    cout << "is the queue full? " << doubleQueue.full() << endl;
    cout << "depth of? " << doubleQueue.depth() << endl;
    cout << "dequeueing: " << doubleQueue.dequeue() << endl;

    CircularQueue<double> doubleQueue2(doubleQueue);
    cout << "doubleQueue2 created by copying doubleQueue" << endl;
    cout << "the original doubleQueue is dequeued: " << doubleQueue.dequeue() << endl;
    cout << "doubleQueue depth of? " << doubleQueue.depth() << endl;
    cout << "doubleQueue2 depth: " << doubleQueue2.depth() << endl;

    CircularQueue<double> doubleQueue3(move(doubleQueue));
    cout << "doubleQueue3 created by moving doubleQueue" << endl;
    cout << "doubleQueue depth of? " << doubleQueue.depth() << endl;
    cout << "doubleQueue3 depth: " << doubleQueue3.depth() << endl;

    CircularQueue<double> doubleQueue4;
    doubleQueue4 = doubleQueue3;
    cout << "doubleQueue4 created then = doubleQueue3" << endl;
    cout << "enqueue 77 to doubleQueue3: " << doubleQueue3.enqueue(77) << endl;
    cout << "doubleQueue3 depth of? " << doubleQueue3.depth() << endl;
    cout << "doubleQueue4 depth: " << doubleQueue4.depth() << endl;

    CircularQueue<double> doubleQueue5;
    doubleQueue5 = move(doubleQueue3);
    cout << "doubleQueue5 created then = move(doubleQueue3)" << endl;
    cout << "doubleQueue3 depth of? " << doubleQueue3.depth() << endl;
    cout << "doubleQueue5 depth: " << doubleQueue5.depth() << endl;

    cout << "----- double test code done ------" << endl;
    return 0;
}
