// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
private:
  T arr[size];
  int start;
  int stop;
public:
  TPQueue() :start(0), stop(0) { }
  void push(T x) {
    if ((stop - start) >= size)
      throw std::string("fail");
    else {
      int i = stop++;
      while ((i > start) && (arr[i % size].prior < x.prior)) {
        arr[(i + 1) % size] = arr[i % size];
        i--;
      }
      arr[(i + 1) % size] = x;
      }
  }
  T pop() {
    return arr[(start++) % size];
  }
  void show() {
    for (int i = 0;i < size;i++) {
      std::cout << arr[i].ch << ' ';
    }
    std::cout << "\n";
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
