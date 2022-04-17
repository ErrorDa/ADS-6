// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
  T arr[100];
  int start;
  int stop;
 public:
TPQueue() :start(0), stop(0) { }
  void push(T x) {
      int i = stop++;
      while ((--i >= start) && (arr[i % size].prior < x.prior)) {
        arr[(i + 1) % size] = arr[i % size];
      }
      arr[(i + 1) % size] = x;
  }
  T pop() {
    return arr[(start++) % size];
  }
};
struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
