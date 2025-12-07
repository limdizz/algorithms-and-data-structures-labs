#include <iostream>
#include "tpriorityqueue.h"
#include "tstackqueue.h"

using namespace std;

int main()
{
    // PRIORITY QUEUE

    TPriorityQueue<int> p_queue(7);

    int arr[7] = { 10, 1, 5, 9, 4, 7, 3 };
    cout << "Array before turn to priority queue: ";
    for (auto i : arr) {
        cout << i << ' ';
    }
    cout << endl;

    for (int i = 0; i < 7; i++) {
        p_queue.push(arr[i]);
    }

    cout << "Priority queue: ";
    while (p_queue.getSize() > 1) {
        cout << p_queue.top() << ' ';
        p_queue.pop();
        if (p_queue.getSize() == 1) {
            int min = p_queue.getMinPriority();
            cout << p_queue.top() << endl;
            p_queue.pop();
            cout << "Element with min priority: " << min << endl << endl;
        }
    }

    // TWO STACKS QUEUE

    TStackQueue<int> st_queue;
    int arr_2[8] = { 9, 21, 14, 5, 43, 32, 52, 12 };
    cout << "Stack queue: ";
    for (auto i : arr_2) {
        cout << i << ' ';
    }

    for (int i = 0; i < 7; i++) {
        st_queue.push(arr_2[i]);
    }

    int minimum = st_queue.getMin();
    int maximum = st_queue.getMax();

    cout << endl << "Queue min = " << minimum << endl;
    cout << "Queue max = " << maximum << endl;

    while (st_queue.size() != 0) {
        st_queue.pop();
    }
}
