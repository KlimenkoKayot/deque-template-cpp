#include "deque-template-cpp.h"

#include <stdexcept>

template <typename T>
bool Deque<T>::Empty() const {
	return head.empty() && tail.empty();
}

template <typename T> 
size_t Deque<T>::Size() const {
	return head.size() + tail.size();
}

template <typename T>
void Deque<T>::Clear() {
	head.clear();	
	tail.clear();
}

template <typename T>
const T& Deque<T>::operator [] (size_t i) const {
	if (i < tail.size()) {
		return tail[tail.size() - i - 1];
	} else {
		return head[i - tail.size()];
	}
}

template <typename T> 
T& Deque<T>::operator [] (size_t i) {
	if (i < tail.size()) {
		return tail[tail.size() - i - 1];
	} else {
		return head[i - tail.size()];
	}
}

template <typename T>
const T& Deque<T>::At(size_t i) const {
	if (i >= Size()) {
		throw std::out_of_range("incorrect index");
	}
	return (*this)[i];
}

template <typename T>
T& Deque<T>::At(size_t i) {
	if (i >= Size()) {
		throw std::out_of_range("incorrect index");
	}
	return (*this)[i];
}

template <typename T>
const T& Deque<T>::Front() const {
	if (!tail.empty()) {
		return tail.back();
	} else {
		return head[0];
	}
}

template <typename T>
T& Deque<T>::Front() {
	if (!tail.empty()) {
		return tail.back();
	} else {
		return head[0];
	}
}

template <typename T>
const T& Deque<T>::Back() const {
	if (!head.empty()) {
		return head.back();
	} else {
		return tail[0];
	}
}

template <typename T>
T& Deque<T>::Back() {
	if (!head.empty()) {
		return head.back();
	} else {
		return tail[0];
	}
}

template <typename T>
void Deque<T>::PushFront(const T& elem) {
	tail.push_back(elem);
}

template <typename T>
void Deque<T>::PushBack(const T& elem) {
	head.push_back(elem);
}