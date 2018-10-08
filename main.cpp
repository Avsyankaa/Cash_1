#include "detours.hpp"
int main() {
std::ofstream file;
file.open("Avsyanochka.txt");
unsigned capacity = 4096;
while (capacity !=35389440) {
unsigned* array = new unsigned[capacity];
		for (unsigned i = 0; i < capacity; i++) {
			array[i] = rand() % 3;
		}
		sum_straight_detour(array, capacity);
	    	auto start_time = std::chrono::high_resolution_clock::now();
		for (unsigned i = 0; i < 1000; i++)
		sum_straight_detour(array, capacity);
		auto end_time = std::chrono::high_resolution_clock::now();
		auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
		file<<"count_elements=" << capacity << " " << "time:" << diff << " " << "straight detour" << std::endl;
		file << std::endl;
		delete[] array;
		unsigned* array1 = new unsigned[capacity];
		for (unsigned i = 0; i < capacity; i++) {
			array1[i] = rand() % 3;
		}
		sum_reverse_detour(array1, capacity);
		start_time = std::chrono::high_resolution_clock::now();
		for (unsigned i = 0; i < 1000; i++)
		sum_reverse_detour(array1, capacity);
		end_time = std::chrono::high_resolution_clock::now();
		diff = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
		file<<"count_elements="<<capacity<<" "<< "time:"<<diff<<" "<<"reverse detour"<<std::endl;
		file<<std::endl;
		delete[] array1;
		unsigned* array2 = new unsigned[capacity];
		for (unsigned i = 0; i < capacity; i++) {
			array2[i] = rand() % 3;
		}
		sum_random_detour(array2, capacity);
		start_time = std::chrono::high_resolution_clock::now();
		for (unsigned i = 0; i < 1000; i++)
		sum_random_detour(array2, capacity);
		end_time = std::chrono::high_resolution_clock::now();
		diff = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
		file<<"count_elements="<<capacity<<" "<< "time:"<<diff<<" "<<"random detour"<<std::endl;
		file<<std::endl;
		delete[] array2;
		if (capacity == 16777216) capacity = 17694720;
		else capacity = capacity * 2;
	}
}
