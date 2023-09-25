#pragma once
#include <iostream>

template<typename T>
class Heap {
public:
	Heap(int capa = 12) {
		capacity = cap;
		size = 0;
		heap = new T[capacity + 1];
		for (int i = 0; i < capacity + 1; ++i) {
			heap[i] = 0;			
		}
	}

	void Resize(int new_capacity) {
		T* newHeap = new T[new_capacity];
		memcpy(newHeap, heap, sizeof(T) * (size + 1));
		if(heap) delete[] heap;
		heap = newHeap;
		capacity = new_capacity;
	}

	T Top() const {
		return heap[1];
	}
	
	bool isEmpty() const {
		return size == 0;
	}

private:
	T* heap = nullptr;
	int size = 0;
	int capacity = 0;
};