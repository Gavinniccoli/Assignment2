//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        data[size] = idx;
        size++;
        upheap(size-1, weightArr);
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        int temp = data[0];
        data[0] = data[size-1];
        size--;
        downheap(0, weightArr);
        return temp; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        while (pos > 0 && weightArr[data[pos]] < weightArr[data[(pos - 1) / 2]]) {
            int tmp = data[pos];
            data[pos] = data[(pos-1)/2];
            data[(pos-1)/2] = tmp;
            pos = (pos - 1) / 2;
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        while (pos * 2 + 1 < size) {
            int left = pos * 2 + 1;
            int right = pos * 2 + 2;
            int child;
            if (right < size && weightArr[data[left]] > weightArr[data[right]]) {
                child =  right;
            }else {
                child =  left;
            }
            if (weightArr[data[pos]] <= weightArr[data[child]]) {
                break;
            }
            int temp = data[pos];
            data[pos] = data[child];
            data[child] = temp;
            pos = child;

        }
    }
};

#endif