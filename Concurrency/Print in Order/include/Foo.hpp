#pragma once

#include <condition_variable>
#include <functional>
#include <mutex>

class Foo {
public:
  Foo() {}

  void first(std::function<void()> printFirst) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    firstReady = true;
    cv.notify_all();
  }

  void second(std::function<void()> printSecond) {
    std::unique_lock<std::mutex> guard(mtx);
    cv.wait(guard, [this] { return firstReady; });
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    secondReady = true;
    guard.unlock();
    cv.notify_one();
  }

  void third(std::function<void()> printThird) {
    std::unique_lock<std::mutex> guard(mtx);
    cv.wait(guard, [this] { return secondReady; });
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }

private:
  bool firstReady = false, secondReady = false;
  std::mutex mtx;
  std::condition_variable cv;
};