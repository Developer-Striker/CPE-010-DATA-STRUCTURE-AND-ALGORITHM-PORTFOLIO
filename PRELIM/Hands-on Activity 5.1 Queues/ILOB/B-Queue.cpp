#include <iostream>
#include "queueLL.h"
#include "queueArr.h"
#include <queue>

int main() {
    qNode<int>* front = nullptr;
    qNode<int>* back = nullptr;

    std::cout << "enqueueing..." << std::endl;

    enqueue(1, &front, &back);
    std::cout << "front: " << front->data << " back: " << back->data << std::endl; // Output: 1
    enqueue(2, &front, &back);
    enqueue(3, &front, &back);
    std::cout << "front: " << front->data << " back: " << back->data << std::endl; // Output: 1

    display(front);

    std::cout << "dequeueing..." << std::endl;

    dequeue(&front, &back);
    std::cout << "front: " << front->data << " back: " << back->data << std::endl; // Output: 2
    dequeue(&front, &back);
    std::cout << "front: " << front->data << " back: " << back->data << std::endl; // Output: 3
    dequeue(&front, &back);
    dequeue(&front, &back); // Output: Queue is empty

    display(front);

    std::cout << std::endl;
    std::cout << std::endl;

    queueArr<int> q(6);

    q.Enqueue(1);
    std::cout << "Front: " << q.Front() << " Back: " << q.Back() << " Size: " << q.Size() << std::endl;
    q.Enqueue(2);
    std::cout << "Front: " << q.Front() << " Back: " << q.Back() << " Size: " << q.Size() << std::endl;
    q.Enqueue(3);
    std::cout << "Front: " << q.Front() << " Back: " << q.Back() << " Size: " << q.Size() << std::endl;
    q.Enqueue(4);
    std::cout << "Front: " << q.Front() << " Back: " << q.Back() << " Size: " << q.Size() << std::endl;
    q.Enqueue(5);
    std::cout << "Front: " << q.Front() << " Back: " << q.Back() << " Size: " << q.Size() << std::endl;
    q.Enqueue(6);
    std::cout << "Front: " << q.Front() << " Back: " << q.Back() << " Size: " << q.Size() << std::endl;
    q.Enqueue(7);
    q.Dequeue();
    std::cout << "Front: " << q.Front() << " Back: " << q.Back() << " Size: " << q.Size() << std::endl;
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    std::cout << "Front: " << q.Front() << " Back: " << q.Back() << " Size: " << q.Size() << std::endl;


    return 0;
}
