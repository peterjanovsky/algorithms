clean:
	rm -r bin/*

test:
	gcc -o bin/random_number_generation_tests tests/random_number_generation_tests.c -I src/
	gcc -o bin/binary_search_tree_tests tests/binary_search_tree_tests.c -I src/
	gcc -o bin/bubble_sort_tests tests/bubble_sort_tests.c -I src/
	gcc -o bin/bucket_sort_tests tests/bucket_sort_tests.c -I src/
	gcc -o bin/counting_sort_tests tests/counting_sort_tests.c -I src/
	gcc -o bin/direct_address_table_tests tests/direct_address_table_tests.c -I src/
	gcc -o bin/hash_table_tests tests/hash_table_tests.c -I src/
	gcc -o bin/heapsort_tests tests/heapsort_tests.c -I src/
	gcc -o bin/insertion_sort_tests tests/insertion_sort_tests.c -I src/
	gcc -o bin/merge_sort_tests tests/merge_sort_tests.c -I src/
	gcc -o bin/maximum_crossing_subarray_tests tests/maximum_crossing_subarray_tests.c -I src/
	gcc -o bin/max_priority_queue_tests tests/max_priority_queue_tests.c -I src/
	gcc -o bin/min_priority_queue_tests tests/min_priority_queue_tests.c -I src/
	gcc -o bin/radix_sort_tests tests/radix_sort_tests.c -I src/
	gcc -o bin/red_black_tree_tests tests/red_black_tree_tests.c -I src/
	gcc -o bin/quicksort_tests tests/quicksort_tests.c -I src/
