clean:
	rm -r bin/*

test:
	gcc -o bin/insertion_sort_tests tests/insertion_sort_tests.c -I src/
	gcc -o bin/merge_sort_tests tests/merge_sort_tests.c -I src/
	gcc -o bin/bubble_sort_tests tests/bubble_sort_tests.c -I src/
	gcc -o bin/heapsort_tests tests/heapsort_tests.c -I src/
	gcc -o bin/max_priority_queue_tests tests/max_priority_queue_tests.c -I src/
	gcc -o bin/quicksort_tests tests/quicksort_tests.c -I src/
	gcc -o bin/maximum_crossing_subarray_tests tests/maximum_crossing_subarray_tests.c -I src/
