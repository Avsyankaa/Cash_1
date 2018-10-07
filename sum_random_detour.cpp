#include "detours.hpp"
long sum_random_detour(int * array, int capacity) {
	long sum = 0;
	while (capacity != 0) {
		int delete_element = rand() % capacity; // тут мы получили элемент вектора
		sum += array[delete_element];
		std::swap(array[delete_element], array[capacity-1]);
		capacity--;
	}
}
