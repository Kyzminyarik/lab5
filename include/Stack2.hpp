// Copyright 2022 kyzminyarik <Yaroslav_kuzmin2002@mail.ru>

#ifndef INCLUDE_STACK2_HPP_
#define INCLUDE_STACK2_HPP_

#include <utility>

template <typename T>
class Stack2 {
 public:
  Stack2() : _tail(nullptr), _size(0) {}

  Stack2(const Stack2 &) = delete;
  Stack2(Stack2 &&) = delete;

  Stack2 &operator=(const Stack2 &) = delete;
  Stack2 &operator=(Stack2 &&) = delete;

  ~Stack2() {
    while (_tail != nullptr) {
      auto tmp = _tail;
      _tail = _tail->prev;
      delete tmp;
    }
  }

  void push(const T &value) {
    auto new_node = new _list_node(value);
    _add_new_node(new_node);
  }

  void push(T &&value) {
    auto new_node = new _list_node(std::move(value));
    _add_new_node(new_node);
  }

  template <typename... args_t>
  void emplace(args_t &&...args) {
    auto new_node = new _list_node(std::forward<args_t>(args)...);
    _add_new_node(new_node);
  }

  T pop() {
    if (!_tail) throw std::runtime_error("pop from empty stack");
    auto tmp = _tail;
    auto ret_value = tmp->value;
    _tail = _tail->prev;
    delete tmp;
    --_size;
    return ret_value;
  }

  std::size_t size() const { return _size; }

  bool empty() const { return _tail == nullptr; }

 private:
  struct _list_node {
    explicit _list_node(const T &val) : value(val), prev(nullptr) {}
    explicit _list_node(T &&val) : value(std::move(val)), prev(nullptr) {}
    template <typename... args_t>
    explicit _list_node(args_t &&...args)
        : value(std::forward<args_t>(args)...), prev(nullptr) {}

    T value;
    _list_node *prev;
  };

  void _add_new_node(_list_node *new_node) {
    new_node->prev = _tail;
    _tail = new_node;
    ++_size;
  }

  _list_node *_tail;
  std::size_t _size;
};

#endif  // INCLUDE_STACK2_HPP_
