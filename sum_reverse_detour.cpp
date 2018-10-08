#include "detours.hpp"
unsigned long sum_reverse_detour(unsigned*& array, unsigned capacity) {
	unsigned long sum = 0;
	for (unsigned i = capacity - 1; i > -1; i--)
		sum += array[i];
	return sum;
}
