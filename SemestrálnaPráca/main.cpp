#include "../structures/list/array_list.h"
#include "../structures/list/linked_list.h"
#include "../structures/heap_monitor.h"
#include <iostream>


int main() {
	initHeapMonitor();
	structures::ArrayList<int>* newArray = new structures::ArrayList<int>;
	structures::LinkedList<int>* newLinkedList = new structures::LinkedList<int>;
}