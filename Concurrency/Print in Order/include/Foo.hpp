#pragma once

#include <atomic>
#include <chrono>
#include <functional>
#include <iostream>
#include <thread>

class Foo {
public:
  Foo() : isFirstDone(false), isSecondDone(false) {}

  void first(std::function<void()> printFirst) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    isFirstDone.store(true, std::memory_order_release);
  }

  void second(std::function<void()> printSecond) {
    while (isFirstDone.load(std::memory_order_acquire) == false) {
      std::this_thread::sleep_for(std::chrono::nanoseconds(5));
    }

    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    isSecondDone.store(true, std::memory_order_release);
  }

  void third(std::function<void()> printThird) {
    while (isSecondDone.load(std::memory_order_acquire) == false) {
      std::this_thread::sleep_for(std::chrono::nanoseconds(10));
    }
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }

private:
  std::atomic_int64_t isFirstDone, isSecondDone;
};