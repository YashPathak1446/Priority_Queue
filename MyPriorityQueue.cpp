#ifndef __PROJ5_PRIORITY_QUEUE_HPP
#define __PROJ5_PRIORITY_QUEUE_HPP

#include "runtimeexcept.hpp"

class PriorityQueueEmptyException : public RuntimeException {
 public:
  PriorityQueueEmptyException(const std::string& err) : RuntimeException(err) {}
};

template <typename Object>
class MyPriorityQueue {
 private:
  // fill in private member data here
  // Object o; // this is only here for use in a stub, you probably want to
  // delete this.
  std::vector<Object> priorityQueue;
  size_t sizePQ;

  unsigned extractMinHelperLeft(unsigned x);
  unsigned extractMinHelperRight(unsigned x);

 public:
  // You also need a constructor and a destructor.
  MyPriorityQueue();
  ~MyPriorityQueue();

  size_t size() const noexcept;
  bool isEmpty() const noexcept;

  void insert(const Object& elem);

  // Note:  no non-const version of this one.  This is on purpose because
  // the interior contents should not be able to be modified due to the
  // heap property.  This isn't true of all priority queues but
  // for this project, we will do this.
  // min and extractMin should throw PriorityQueueEmptyException if the queue is
  // empty.
  const Object& min() const;

  void extractMin();

  // print helper
  void print();
};

template <typename Object>
MyPriorityQueue<Object>::MyPriorityQueue() {
  sizePQ = 0;
}

template <typename Object>
MyPriorityQueue<Object>::~MyPriorityQueue() {}

template <typename Object>
size_t MyPriorityQueue<Object>::size() const noexcept {
  return this->sizePQ;
}

template <typename Object>
bool MyPriorityQueue<Object>::isEmpty() const noexcept {
  if (sizePQ == 0) return true;
  return false;
}

template <typename Object>
void MyPriorityQueue<Object>::insert(const Object& elem) {
  priorityQueue.push_back(elem);
  sizePQ += 1;
  // x is first set to the last index of the PQ (newly inserted element).
  unsigned x = priorityQueue.size() - 1;
  bool isMinHeap = false;
  // i is the index of the parent of current child at index x.
  unsigned i = 0;
  while (!isMinHeap && x != 0) {
    // finding index i based on the child.
    // if x is even, then right child.
    if (x % 2 == 0) i = (x / 2) - 1;
    // if x is odd, then left child.
    else
      i = (x - 1) / 2;

    // extra case to check if x == 2 as it is an exception case where parent is
    // 0 not 1:
    if (x == 2) i = 0;

    if (priorityQueue[i] < priorityQueue[x])
      isMinHeap = true;
    else {
      Object temp = priorityQueue[i];
      priorityQueue[i] = priorityQueue[x];
      priorityQueue[x] = temp;
    }
    x = i;
  }
  return;
}

template <typename Object>
const Object& MyPriorityQueue<Object>::min() const {
  if (this->isEmpty()) {
    throw PriorityQueueEmptyException("Queue is empty!");
  }
  return priorityQueue[0];
}

template <typename Object>
unsigned MyPriorityQueue<Object>::extractMinHelperLeft(unsigned x) {
  Object temp = priorityQueue[x];
  priorityQueue[x] = priorityQueue[2 * x + 1];
  priorityQueue[2 * x + 1] = temp;
  x = 2 * x + 1;
  return x;
}

template <typename Object>
unsigned MyPriorityQueue<Object>::extractMinHelperRight(unsigned x) {
  Object temp = priorityQueue[x];
  priorityQueue[x] = priorityQueue[2 * x + 2];
  priorityQueue[2 * x + 2] = temp;
  x = 2 * x + 2;
  return x;
}

template <typename Object>
void MyPriorityQueue<Object>::extractMin() {
  if (this->isEmpty()) {
    throw PriorityQueueEmptyException("Queue is empty!");
  }
  // then repllace the first element with the last element, then remove the last
  // element.
  priorityQueue[0] = priorityQueue[priorityQueue.size() - 1];
  priorityQueue.pop_back();
  sizePQ -= 1;

  // x is first set to the first index of the PQ (new root).
  unsigned x = 0;
  bool isMinHeap = false;
  // i is the index of the parent of current child at index x.
  while (!isMinHeap && (2 * x + 2 < priorityQueue.size() - 1)) {
    // when both children are smaller than parent
    if (priorityQueue[2 * x + 1] < priorityQueue[x] &&
        priorityQueue[2 * x + 2] < priorityQueue[x]) {
      // if left child is smaller than right child, make left child new parent
      if (priorityQueue[2 * x + 1] < priorityQueue[2 * x + 2]) {
        x = extractMinHelperLeft(x);
      }
      // else if right child is smaller than left child, make right child new
      // parent
      else {
        x = extractMinHelperRight(x);
      }
    }
    // when only left child smaller than parent
    else if (priorityQueue[2 * x + 1] < priorityQueue[x]) {
      x = extractMinHelperLeft(x);
    }
    // when only right child is smaller than parent
    else if (priorityQueue[2 * x + 2] < priorityQueue[x]) {
      x = extractMinHelperRight(x);
    }
    // otherwise both children are greater than parent
    else {
      isMinHeap = true;
    }
  }
  return;
}

template <typename Object>
void MyPriorityQueue<Object>::print() {
  for (int i = 0; i < priorityQueue.size(); i++) {
    std::cout << i << ": " << priorityQueue[i] << std::endl;
  }
  return;
}

#endif
