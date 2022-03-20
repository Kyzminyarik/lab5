// Copyright 2022 kyzminyarik <Yaroslav_kuzmin2002@mail.ru>

#ifndef INCLUDE_STACK_HPP_
#define INCLUDE_STACK_HPP_

#include <memory>
#include <utility>

#include "Stack2.hpp"

template <typename T>
class Stack1 {
 public:
  Stack1() : _impl(new Stack2<T>()) {}

  Stack1(const Stack1 &) = delete;

  Stack1(Stack1 &&other) noexcept : _impl(std::move(other._impl)) {}

  Stack1 &operator=(const Stack1 &) = delete;

  Stack1 &operator=(Stack1 &&other) noexcept {
    if (this == &other) return *this;
    _impl = std::move(other._impl);
    return *this;
  }

  ~Stack1() = default;

  void push(const T &value) { _impl->push(value); }

  void push(T &&value) { _impl->push(std::move(value)); }

  template <typename... args_t>
  void emplace(args_t &&...args) {
    _impl->emplace(std::forward<args_t>(args)...);
  }

  T pop() { return _impl->pop(); }

  bool empty() const { return _impl->empty(); }

  std::size_t size() const { return _impl->size(); }

 private:
  std::unique_ptr<Stack2<T>> _impl;
};

#endif  // INCLUDE_STACK_HPP_
