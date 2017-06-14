#pragma once

#include <iostream>

using namespace std;

const int DEFAULT_CAPACITY = 8;

template<typename T>
class Vector {
private:
	T* container;
	size_t size;
	size_t capacity;

	void copy(const Vector& other);
	void destroy();

	void resize(size_t newCapacity);
	void removeAt(size_t index);
	void swap(T& lhs, T& rhs);
public:
	Vector();
	Vector(const T* arr, size_t size);
	Vector(const Vector& other);
	Vector& operator=(const Vector& other);
	~Vector();

	int getSize() const;
	int getCapacity() const;

	bool isEmpty() const;

	void sort(bool increasing);
	bool isSorted(bool increasing) const;

	T& getAt(size_t index);
	void setAt(size_t index, const T& element);

	void add(const T& element);
	void remove(const T& element);

	Vector& operator+=(const Vector& other);
	Vector& operator-=(const Vector& other);
	Vector& operator*=(const Vector& other);
	Vector& operator/=(const Vector& other);

	friend Vector operator+(const Vector& v1, const Vector& v2);
	friend Vector operator-(const Vector& v1, const Vector& v2);
	friend Vector operator*(const Vector& v1, const Vector& v2);
	friend Vector operator/(const Vector& v1, const Vector& v2);

	const T& operator[](size_t index) const;
	T& operator[](size_t index);

	friend ostream& operator<<(ostream& os, const Vector& obj);
	friend istream& operator >> (istream& is, Vector& obj);
};

template<typename T>
void Vector<T>::copy(const Vector<T>& other) {
	this->container = new T[other.capacity];
	for (size_t i = 0; i < other.size; ++i) {
		this->container[i] = other.container[i];
	}
	this->size = other.size;
	this->capacity = other.capacity;
}

template<typename T>
void Vector<T>::destroy() {
	delete[] container;
}

template<typename T>
void Vector<T>::resize(size_t newCapacity) {
	T* temp = new T[newCapacity];
	for (size_t i = 0; i < this->size; ++i) {
		temp[i] = this->container[i];
	}

	delete[] this->container;
	this->container = temp;
	this->capacity = newCapacity;
}

template<typename T>
void Vector<T>::removeAt(size_t index) {
	for (size_t j = index; j < this->size - 1; ++j) {
		this->container[j] = this->container[j + 1];
	}

	this->size--;
}

template<typename T>
void Vector<T>::swap(T& lhs, T& rhs) {
	T temp = lhs;
	lhs = rhs;
	rhs = temp;
}

template<typename T>
Vector<T>::Vector() {
	this->container = new T[DEFAULT_CAPACITY];
	this->size = 0;
	this->capacity = DEFAULT_CAPACITY;
}

template<typename T>
Vector<T>::Vector(const T* arr, size_t size) {
	if (size >= DEFAULT_CAP)
	{
		this->capacity = size * 2;
	}
	else
	{
		this->capacity = DEFAULT_CAP;
	}

	this->container = new T[this->capacity];
	for (size_t i = 0; i < size; ++i) {
		this->container[i] = arr[i];
	}
	this->size = size;
}

template<typename T>
Vector<T>::Vector(const Vector<T>& other) {
	copy(other);
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T> &other) {
	if (this != &other) {
		destroy();
		copy(other);
	}
	return *this;
}

template<typename T>
Vector<T>::~Vector() {
	destroy();
}

template<typename T>
int Vector<T>::getSize() const {
	return this->size;
}

template<typename T>
int Vector<T>::getCapacity() const {
	return this->capacity;
}

template<typename T>
bool Vector<T>::isEmpty() const {
	return (this->size == 0);
}

template<typename T>
void Vector<T>::sort(bool increasing) {
	for (size_t i = 0; i < this->size - 1; ++i) {
		for (size_t j = 0; j < this->size - i - 1; ++j) {
			if (increasing) {
				if (this->container[i] > this->container[i + 1]) {
					swap(this->container[i], this->container[i + 1]);
				}
			}
			else {
				if (this->container[i] < this->container[i + 1]) {
					swap(this->container[i], this->container[i + 1]);
				}

			}
		}

	}
}

template<typename T>
bool Vector<T>::isSorted(bool increasing) const {
	if (increasing) {
		for (size_t i = 0; i < this->size - 1; ++i) {
			if (this->container[i] > this->container[i + 1]) {
				return false;
			}
		}
	}
	else {
		for (size_t i = 0; i < this->size - 1; ++i) {
			if (this->container[i] < this->container[i + 1]) {
				return false;
			}
		}
	}

	return true;
}

template<typename T>
T& Vector<T>::getAt(size_t index) {
	return this->container[index];
}

template<typename T>
void Vector<T>::setAt(size_t index, const T& element) {
	this->container[index] = element;
}

template<typename T>
void Vector<T>::add(const T& element) {
	if (this->size == this->capacity) {
		resize(this->capacity * 2);
	}

	this->container[this->size] = element;
	this->size++;
}

template<typename T>
void Vector<T>::remove(const T& element) {
	for (int i = 0; i < this->size; ++i) {
		if (this->container[i] != element) {
			continue;
		}
		else {
			removeAt(i);
			break; 
		}
	}
}

template<typename T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& other) {
	for (size_t i = 0; i < this->size && i < other.size; ++i) {
		this->container[i] += other.container[i];
	}

	return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator-=(const Vector<T>& other) {
	for (size_t i = 0; i < this->size && i < other.size; ++i) {
		this->container[i] -= other.container[i];
	}

	return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator*=(const Vector<T>& other) {
	for (size_t i = 0; i < this->size && i < other.size; ++i) {
		this->container[i] *= other.container[i];
	}

	return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator/=(const Vector<T>& other) {
	for (size_t i = 0; i < this->size && i < other.size; ++i) {
		this->container[i] /= other.container[i];
	}

	return *this;
}

template<typename T>
Vector<T> operator+(const Vector<T>& v1, const Vector<T>& v2) {
	Vector<T> newVector(v1);
	newVector += v2;

	return newVector;
}

template<typename T>
Vector<T> operator-(const Vector<T>& v1, const Vector<T>& v2) {
	Vector<T> newVector(v1);
	newVector -= v2;

	return newVector;
}

template<typename T>
Vector<T> operator*(const Vector<T>& v1, const Vector<T>& v2) {
	Vector<T> newVector(v1);
	newVector *= v2;

	return newVector;
}

template<typename T>
Vector<T> operator/(const Vector<T>& v1, const Vector<T>& v2) {
	Vector<T> newVector(v1);
	newVector /= v2;

	return newVector;
}

template<typename T>
const T& Vector<T>::operator[](size_t index) const {
	return this->container[index];
}

template<typename T>
T& Vector<T>::operator[](size_t index) {
	return this->container[index];
}

template<typename T>
ostream& operator<<(ostream& os, const Vector<T>& obj) {
	os << "[";
	for (size_t i = 0; i < obj.size; ++i) {
		os << obj.container[i];
		if (i != obj.size - 1) {
			os << ", ";
		}
	}
	os << "]";

	return os;
}

template<typename T>
istream& operator >> (istream& is, Vector<T>& obj) {
	cout << "Vector size: " << obj.size << endl;
	for (size_t i = 0; i < obj.size; ++i) {
		cout << "element[" << i << "] = ";
		is >> obj.container[i];
	}

	return is;
}