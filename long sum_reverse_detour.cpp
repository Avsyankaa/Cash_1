long sum_reverse_detour (int *&array, int capacity) {
	long sum = 0;
	for (int i = capacity-1; i > -1; i--)
		sum += array[i];
	return sum;
}
