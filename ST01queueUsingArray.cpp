#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Q {
  int size = 10;
  int q[size];
  int currSize = 0;
  int start = -1, end = -1;

  void push(int n) {
    if (currSize == size) return;
    if (currSize == 0) start = 0, end = 0;
    else {
      end = (end+1) % size;
      q[end] = n;
    }
    currSize++;
  }

  int pop() {
    if (currSize == 0) return -1;
    int element = q[start];
    if (currSize == 1) {
      start = end = -1;
    }
    else {
      start = (start + 1) % size;
    }
    currSize--;
    return element;
  }

  int front() {
    if (currSize == 0) return -1;
    return q[start];
  }

  int size() {
    return currSize;
  }
};