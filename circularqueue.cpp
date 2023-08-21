#include<iostream>
#define size 5
int front = -1;
int rear = -1;
int queue[size];

using namespace std;

bool isFull() {
    if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
        return true;
    }
    return false;
}

bool isEmpty() {
    if (front == -1) {
        return true;
    }
    return false;
}

void Enqueue() {
    int val;
    if (isFull()) {
        cout << "QUEUE IS FULL!" << endl;
    } else {
        cout << "Enter a value: ";
        cin >> val;

        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == size - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }

        queue[rear] = val;
        cout << "Value enqueued successfully!" << endl;
    }
}

void Dequeue() {
    if (isEmpty()) {
        cout << "QUEUE IS EMPTY!" << endl;
    } else {
        int val = queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }
        cout << "Dequeued value: " << val << endl;
    }
}

void DisplayQueue() {
    if (isEmpty()) {
        cout << "QUEUE IS EMPTY" << endl;
    } else {
        cout << "QUEUE: ";
        int i = front;
        do {
            cout << queue[i] << " | ";
            if (i == rear && rear != front) {
                break;
            }
            if (i == size - 1) {
                i = 0;
            } else {
                i++;
            }
        } while (i != (rear + 1) % size);
        cout << endl;
    }
}

int main() {
    int ch;
    do {
        cout << "\n 1.Enqueue \n 2.Dequeue \n 3.Display \n 0.Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                Enqueue();
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                DisplayQueue();
                break;
            case 0:
                exit(0);
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    } while (ch != 0);

    return 0;
}
