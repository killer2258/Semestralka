
#include "../structures/list/array_list.h"
#include "../structures/list/linked_list.h"
#include "../structures/heap_monitor.h"
#include <iostream>
#include "testArrayList.h"
#include "../structures/priority_queue/heap.h"
#include "../structures/priority_queue/priority_queue_unsorted_array_list.h"
#include "testLinkedList.h"

int main() {
	initHeapMonitor();
	structures::ArrayList<unsigned long>* newArray;
	structures::PriorityQueue<int>* heap = new structures::Heap<int>;
	structures::PriorityQueue<int>* arr = new structures::PriorityQueueUnsortedArrayList<int>;

	//testArrayList::call_test_list();
	//testLinkedList::call_test_list();

	//TODO
	//set a get - zle
	//remove - zle
}