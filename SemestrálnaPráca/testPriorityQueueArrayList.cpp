#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <random>
#include "../structures/list/list.h"
#include "testPriorityQueueArrayList.h"
#include <chrono>
#include <fstream>
#include <thread>
#include <ratio>

#define MIL 1000

namespace testPriorityQueue {
	using namespace std;

	//zahrka pole
	void shuffle_array(int* arr)
	{
		random_shuffle(&arr[0], &arr[MIL]);
	}

	void fill_array(int* arr, int* limits, int amount)
	{

		int indent_1 = limits[0] + limits[1];
		int indent_2 = indent_1 + limits[2];

		//vlozi do pola pocet 1-tiek, 2-ok, 3-ok a 4-ok podla vypocitanych limitov
		for (int i = 0; i < MIL; i++)
		{
			if (i < limits[0])
				arr[i] = 1;
			else if (i < indent_1)
				arr[i] = 2;
			else if (i < indent_2)
				arr[i] = 3;
			else if (amount == 4)
				arr[i] = 4;
		}
	}

	//vygeneruje rand cislo od 1 po range
	int gen_number(int range)
	{
		return rand() % range + 1;
	}

	void test_adt_queue(int* arr)
	{
		std::ofstream outfile("operation_times_arraylist.txt");
		int operation_no;
		int randIndex;
		auto t1 = std::chrono::high_resolution_clock::now();
		auto t2 = std::chrono::high_resolution_clock::now();
		auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
		std::chrono::duration<double, std::milli> fp_ms;
		std::chrono::duration<long, std::micro> int_usec;

		structures::List<int>* newList = new structures::ArrayList<int>; // upravit na priority queue

		for (int i = 0; i < MIL; i++)
		{
			switch (arr[i]) {
			case(1):
				cout << "vloz" << endl;
				t1 = std::chrono::high_resolution_clock::now();
				
				//DOPLNIT OPERACIU VLOZ

				t2 = std::chrono::high_resolution_clock::now();
				fp_ms = t2 - t1;
				int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
				int_usec = int_ms;
				outfile << "get_index:" << fp_ms.count() << "ms" << std::endl;
				break;
			case(2):
				cout << "vyber" << endl;
				t1 = std::chrono::high_resolution_clock::now();

				//DOPLNIT OPERACIU VYBER

				t2 = std::chrono::high_resolution_clock::now();
				fp_ms = t2 - t1;
				int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
				int_usec = int_ms;
				outfile << "get_index:" << fp_ms.count() << "ms" << std::endl;
				break;
			case(3):

				cout << "getIndex" << endl;
				t1 = std::chrono::high_resolution_clock::now();

				//DOPLNIT OPERACIU UKAZ

				t2 = std::chrono::high_resolution_clock::now();
				fp_ms = t2 - t1;
				int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
				int_usec = int_ms;
				outfile << "get_index:" << fp_ms.count() << "ms" << std::endl;
				break;
			}
		}
	}

	void call_test_queue()
	{
		int* arr;
		arr = new int[MIL];

		int n = sizeof(arr) / sizeof(arr[0]);
		structures::List<int>* newList = new structures::ArrayList<int>;

		//0 - vloz, 1 - zrus, 2 - nastav, 3 - index
		int pomery[2][3] = {
				{45, 45, 10},
				{50, 25, 25}
		};

		int limits[2][3];
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				limits[i][j] = (MIL / 100) * pomery[i][j];
			}
		}

		for (int i = 0; i < 2; i++)
		{
			fill_array(arr, limits[i], 4);
			srand(time(NULL));
			shuffle_array(arr);
			test_adt_queue(arr);
		}
		delete newList;
	}
}
