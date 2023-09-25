#pragma once
#include <iostream>

template<typename T>
class Heap {
public:
	Heap(int capa = 12) {
		capacity = capa;
		size = 0;
		heap = new T[capacity + 1];
		for (int i = 0; i < capacity + 1; ++i) {
			heap[i] = 0;
		}
	}

	void Resize(int new_capacity) {
		T* newHeap = new T[new_capacity];
		memcpy(newHeap, heap, sizeof(T) * (size + 1));
		if (heap) delete[] heap;
		heap = newHeap;
		capacity = new_capacity;
	}

	T Top() const {
		return heap[1];
	}

	bool IsEmpty() const {
		return size == 0;
	}

	void Print() const {
		using namespace std;
		cout << "Index: ";
		for (int i = 1; i <= size; ++i)
			cout << " " << i;
		cout << endl;

		cout << "Value: ";
		for (int i = 1; i <= size; ++i)
			cout << " " << heap[i];
		cout << endl << endl;
	}

	void Push(const T& item) {

		using namespace std;
		cout << "Push " << item << endl;

		if (size == capacity)
			Resize(capacity * 2);

		++size;
		int current = size;
		
		while (current > 1 && item > heap[current / 2]) {
			heap[current] = heap[current / 2];
			current /= 2;
		}

		heap[current] = item;
	}
	
	void Pop() {
		if (IsEmpty()) return;
		
		using namespace std;
		cout << "Pop()" << endl;

		const T lastItem = heap[size];
		size--;
		
		int current = 1;
		int child = 2;
		while (child <= size) {

			if (child < size && heap[child] < heap[child + 1])
				child = child + 1;

			if (lastItem >= heap[child]) break;

			heap[current] = heap[child];
			current = child;
			child *= 2;
		}

		heap[current] = lastItem;
	}

private:
	T* heap = nullptr;
	int size = 0;
	int capacity = 0;
};