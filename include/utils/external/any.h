#ifndef INCLUDE_UTILS_EXTERNAL_ANY_H_
#define INCLUDE_UTILS_EXTERNAL_ANY_H_

#include <cassert>
#include <string>
#include <type_traits>
#include <typeinfo>
#include <utility>

template <class T>
using StorageType =
    typename std::decay<typename std::remove_reference<T>::type>::type;

struct Any {
  bool is_null() const { return !this->ptr; }
  bool not_null() const { return this->ptr; }

  template <typename U>
  Any(U &&value) : ptr(new Derived<StorageType<U>>(std::forward<U>(value))) {}

  template <class U>
  bool is() const {
    typedef StorageType<U> T;
    auto derived = dynamic_cast<Derived<T> *>(this->ptr);

    return derived;
  }

  template <class U>
  StorageType<U> &as() const {
    typedef StorageType<U> T;

    auto derived = dynamic_cast<Derived<T> *>(this->ptr);
    if (!derived) {
      throw std::bad_cast();
    }

    return derived->value;
  }

  template <class U>
  operator U() {
    return as<StorageType<U>>();
  }

  Any() : ptr(nullptr) {}

  Any(Any &that) : ptr(that.clone()) {}

  Any(Any &&that) : ptr(that.ptr) { that.ptr = nullptr; }

  Any(const Any &that) : ptr(that.clone()) {}

  Any(const Any &&that) : ptr(that.clone()) {}

  Any &operator=(const Any &a) {
    if (this->ptr == a.ptr) {
      return *this;
    }

    auto old_ptr = this->ptr;
    this->ptr = a.clone();

    if (old_ptr) {
      delete old_ptr;
    }

    return *this;
  }

  Any &operator=(Any &&a) {
    if (this->ptr == a.ptr) {
      return *this;
    }
    std::swap(this->ptr, a.ptr);

    return *this;
  }

  ~Any() {
    if (this->ptr) delete this->ptr;
  }

 private:
  struct Base {
    virtual ~Base() {}

    virtual Base *clone() const = 0;
  };

  template <typename T>
  struct Derived : Base {
    template <typename U>
    Derived(U &&value) : value(std::forward<U>(value)) {}

    T value;

    Base *clone() const { return new Derived<T>(value); }
  };

  Base *clone() const { return (this->ptr ? this->ptr->clone() : nullptr); }

  Base *ptr;
};

#endif  // INCLUDE_UTILS_EXTERNAL_ANY_H_
