#include "Iterator.h"

template <typename T> Iterator<T>::Iterator(T* first) : current(first) { }

template<typename T> T& Iterator<T>::operator+ (int n) { return *(current + n); }
template<typename T> T& Iterator<T>::operator- (int n) { return *(current - n); }

template<typename T> T& Iterator<T>::operator++(int) { return *current++; }
template<typename T> T& Iterator<T>::operator--(int) { return *current--; }
template<typename T> T& Iterator<T>::operator++() { return *current++; }
template<typename T> T& Iterator<T>::operator--() { return *current--; }

template<typename T> bool Iterator<T>::operator!=(const Iterator& it) { return current != it.current; }
template<typename T> bool Iterator<T>::operator==(const Iterator& it) { return current == it.current; }
template<typename T> T& Iterator<T>::operator*() { return *current; }
