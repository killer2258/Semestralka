#pragma once

#include "../structures/structure.h"
#include "../structures/list/list.h"

namespace test {
	void shuffle_array(int arr[], int n);
	void fill_array(int* arr, int* limits, int amount);
	int gen_number(int range);
	void test_adt_list(int* arr); //arraylist - 0, linkedlist - 1
	void test_adt_queue(int* arr);
	void call_test_list();
	int metoda();
}