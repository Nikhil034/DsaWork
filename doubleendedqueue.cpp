#include<iostream>
#define size 5
int f = -1;
int r = -1;
int queue[size];
using namespace std;

int isEmpty() {
    if (f == -1 && r == -1 || f == r + 1) {
        return 1;
    } else {
        return 0;
    }
}

int isFull() {
    if ((f == 0 && r == size - 1) || f == r + 1) {
        return 1;
    } else {
        return 0;
    }
}

void EnqueuFront() {
    int val;
    if (isFull()) {
        cout << "QUEUE IS ALREADY FULL!";
    } else {
        cout << "Enter a value: ";
        cin >> val;
        if (f == -1) {
            f = 0;
            r = 0;
        } else if (f == 0) {
            f = size - 1;
        } else {
            f--;
        }
        queue[f] = val;
    }
}

void EnqueuBack() {
    int val;
    if (isFull()) {
        cout << "QUEUE IS ALREADY FULL!";
    } else {
        cout << "Enter a back value: ";
        cin >> val;
        if (r == -1) {
            f = 0;
            r = 0;
        } else if (r == size - 1) {
            r = 0;
        } else {
            r++;
        }
        queue[r] = val;
    }
}

void DequeuFront() {
    if (isEmpty()) {
        cout << "QUEUE IS EMPTY!";
    } else {
        cout << "QUEUE VALUE FROM FRONT=" << queue[f];
        if (f == r) {
            f = -1;
            r = -1;
        } else if (f == size - 1) {
            f = 0;
        } else {
            f++;
        }
    }
}

void DequeueBack() {
    if (isEmpty()) {
        cout << "QUEUE IS EMPTY!";
    } else {
        cout << "BACK VALUE=" << queue[r];
        if (f == r) {
            f = -1;
            r = -1;
        } else if (r == 0) {
            r = size - 1;
        } else {
            r--;
        }
    }
}

void DisplayQueue() {
    if (isEmpty()) {
        cout << "QUEUE IS EMPTY";
    } else {
        int i = f;
        while (true) {
            cout << queue[i] << " | ";
            if (i == r) {
                break;
            }
            if (i == size - 1) {
                i = 0;
            } else {
                i++;
            }
        }
    }
}

int main() {
    int ch;
    do {
        cout << "\n 1.Enqueue Front \n 2.Enqueue Back \n 3.Dequeue Front \n 4.Dequeue Back \n 5.Display \n 0.Exit\n";
        cout << "PASS YOUR USE CASE=";
        cin >> ch;

        switch (ch) {
        case 1:
            EnqueuFront();
            break;
        case 2:
            EnqueuBack();
            break;
        case 3:
            DequeuFront();
            break;
        case 4:
            DequeueBack();
            break;
        case 5:
            DisplayQueue();
            break;
        case 0:
            exit(0);
        default:
            cout << "CASE NOT FOUND!";
            break;
        }
    } while (ch != 0);

    return 0;
}
