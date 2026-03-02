#include <iostream>
#include <string>
using namespace std;

struct Deque {
    int* data;
    int capacity;
    int front;
    int rear;
    int size;

    void init(int cap) {
        capacity = cap;
        data = new int[capacity];
        front = 0;
        rear = 0;
        size = 0;
    }

    void destroy() {
        delete[] data;
    }

    bool isEmpty() { return size == 0; }
    bool isFull()  { return size == capacity; }

    bool push_front(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity;
        data[front] = value;
        size++;
        return true;
    }

    bool push_back(int value) {
        if (isFull()) return false;
        data[rear] = value;
        rear = (rear + 1) % capacity;
        size++;
        return true;
    }

    bool pop_front() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    bool pop_back() {
        if (isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity;
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return data[front];
    }

    int getBack() {
        if (isEmpty()) return -1;
        return data[(rear - 1 + capacity) % capacity];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    Deque dq;
    dq.init(10005);\

    string cmd;
    while (N--) {
        cin >> cmd;

        if (cmd == "push_front") {
            int x; cin >> x;
            dq.push_front(x);
        } else if (cmd == "push_back") {
            int x; cin >> x;
            dq.push_back(x);
        } else if (cmd == "pop_front") {
            if (dq.isEmpty()) cout << -1 << '\n';
            else {
                cout << dq.getFront() << '\n';
                dq.pop_front();
            }
        } else if (cmd == "pop_back") {
            if (dq.isEmpty()) cout << -1 << '\n';
            else {
                cout << dq.getBack() << '\n';
                dq.pop_back();
            }
        } else if (cmd == "size") {
            cout << dq.size << '\n';
        } else if (cmd == "empty") {
            cout << (dq.isEmpty() ? 1 : 0) << '\n';
        } else if (cmd == "front") {
            cout << dq.getFront() << '\n';
        } else if (cmd == "back") {
            cout << dq.getBack() << '\n';
        }
    }

    dq.destroy();
    return 0;
}