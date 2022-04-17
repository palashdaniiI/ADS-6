// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
  T arr[5];
    int start, end;
 public:
    TPQueue() : start(0), end(0) {}
    void push(T value) {
      int x = end;
      while (--x >= start && value.prior > (*(arr + x % size)).prior)
        *(arr + (x + 1) % size) = *(arr + x % size);
      *(arr + (x + 1) % size) = value;
      end++;
      }
  T pop() {
    return *(arr + (start++) % size);
  }
};

#endif  // INCLUDE_TPQUEUE_H_
