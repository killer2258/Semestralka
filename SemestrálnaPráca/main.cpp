#include "../structures/list/array_list.h"
#include "../structures/list/linked_list.h"
#include "../structures/heap_monitor.h"
#include <iostream>
#include "podiely_operacii.h"


int main() {
	initHeapMonitor();
	structures::ArrayList<int> newArray;
	structures::LinkedList<int>* newLinkedList = new structures::LinkedList<int>;
	test::call_test_list(newArray);
}	
