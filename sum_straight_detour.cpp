#include "detours.hpp"
unsigned long sum_straight_detour(unsigned*& array, unsigned capacity) {
    unsigned long sum = 0;
    for (unsigned i = 0; i < capacity; i++)
        sum += array[i];
    return sum;
}
