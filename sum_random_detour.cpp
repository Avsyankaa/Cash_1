#include "detours.hpp"
unsigned long sum_random_detour(unsigned* array, unsigned capacity) {
    unsigned long sum = 0;
    while (capacity != 0) {
        unsigned delete_element = rand() % capacity;
        sum += array[delete_element];
        std::swap(array[delete_element], array[capacity - 1]);
        capacity--;
    }
}
