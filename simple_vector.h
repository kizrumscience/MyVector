#pragma once

#include <cstdlib>
#include <algorithm>

using namespace std;

template <typename T>
class SimpleVector {
public:
	SimpleVector() {
		size_ = 0;
		capacity_ = 0;
		data = nullptr;
	}
	explicit SimpleVector(size_t size): size_(size) {
		capacity_ = 2 * size_;
		data = new T[capacity_];
	}
	SimpleVector(const SimpleVector<T>& rhs):
		data(new T[rhs.capacity_]),
		size_(rhs.size_),
		capacity_(rhs.capacity_)
	{
		copy(rhs.begin(), rhs.end(), begin());
	}

	void operator=(const SimpleVector& rhs) {
		if (size_ >= rhs.Size()) {
			copy(rhs.begin(), rhs.end(), begin());
			size_ = rhs.Size();
		}
		else {
			SimpleVector<T> tmp(rhs);
			swap(tmp.data, data);
			swap(tmp.size_, size_);
			swap(tmp.capacity_, capacity_);
		}
	}
	~SimpleVector() {
		if (data != nullptr) {
			delete[] data;
		}
	}

	T& operator[](size_t index) {
		return data[index];
	}

	T* begin() {
		return data;
	}
	T* end() {
		return data + size_;
	}

	const T* begin() const {
		return data;
	}
	const T* end() const {
		return data + size_;
	}

	size_t Size() const {
		return size_;
	}
	size_t Capacity() const {
		return capacity_;
	}
	void PushBack(const T& value) {
		if (capacity_ == 0) {
			capacity_ = 1;
			data = new T[capacity_];
		}
		if (size_ == capacity_) {
			capacity_ *= 2;
			T* tmp = new T[capacity_];
			for (size_t i = 0; i < size_; ++i) {
				tmp[i] = data[i];
			}
			swap(data, tmp);
			delete[] tmp;
		}
		data[size_] = value;
		++size_;
	}

private:
	T* data;
	size_t size_;
	size_t capacity_;
};
