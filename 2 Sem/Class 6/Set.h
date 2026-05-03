#pragma once
#include <iostream>

class Set {
private:
	int* data;
	int size;
	int capacity;
	void ensureCapacity();
public:
	Set();
	Set(int cap);
	Set(const Set& other);
	~Set();

	Set& operator=(const Set& other);

	void add(int value);
	bool contains(int value) const;
	void remove(int value);

	int& operator[](int index);
	const int& operator[](int index) const;

	operator int() const { return size; }
	Set operator*(const Set& other) const;

	friend std::istream& operator>>(std::istream& in, Set& s);
	friend std::ostream& operator<<(std::ostream& out, const Set& s);

	class Iterator {
	private:
		const Set* container;
		int currentIndex;
	public:
		Iterator(const Set* cont, int idx);
		bool operator!=(const Iterator& other) const;
		bool operator==(const Iterator& other) const;
		void operator++();
		void operator--();
		int operator*() const;
	};
	Iterator begin() const;
	Iterator end() const;
};