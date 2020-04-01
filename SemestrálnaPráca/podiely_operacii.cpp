#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <random>
#include "podiely_operacii.h"
#include "../structures/list/list.h"
#include "../structures/list/array_list.h"
#include "../structures/list/linked_list.h"
#include <chrono> 

#define MIL 1000

namespace test {
	using namespace std;
	using namespace std::chrono;
	//zahrka pole
	void shuffle_array(int arr[], int n)
	{
		unsigned seed = 0;
		shuffle(arr, arr + n, default_random_engine(seed));
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
		srand(time(NULL));
		return rand() % range;
	}

	//test pre ADT zoznam
	void test_adt_list(int* arr) {
		/*for (int i = 0; i < 100; i++)
			newList.insertFirst(5);*/

		int operation_no;
		int randIndex;
		structures::List<int>* newList = new structures::ArrayList<int>;
		for (int i = 0; i < MIL; i++)
		{
			cout << arr[i] << endl;
			if (newList->size() == 0)
			{
				randIndex = 0;
			}
			else
			{
				randIndex = gen_number(newList->size());
			}

			switch (arr[i]) {
			case(1):
				operation_no = gen_number(3);
				switch (operation_no) {
				case(0):
					//operacia_vloz_prvy(gen_number(range));
					//cout << newList->size() << endl;
					//cout << "insertFirst" << endl;
					newList->insertFirst(gen_number(10000));
					break;
				case(1):
					//operacia_vloz_posledny(gen_number(range));
					//cout << newList->size() << endl;
					//cout << "insertLast" << endl;
					newList->add(gen_number(10000));
					
					break;
				case(2):
					//operacia_vloz_na_index(gen_number(range), gen_number(range))
					//cout << randIndex << endl;
					//cout << newList->size() << endl;
					//cout << "insertOn" << endl;
					newList->insert(gen_number(10000), randIndex);
					
					break;
				}
				break;
			case(2):
				operation_no = gen_number(3);
				switch (operation_no) {
				case(0):
					//operacia_zrus_prvy();
					//cout << "removeFirst" << endl;
					newList->removeFirst();
					
					break;
				case(1):
					//operacia_zrus_posledny();
					//cout << "removeLast" << endl;
					newList->removeLast();
					
					break;
				case(2):
					//operacia_zrus_na_indexe(gen_number(range));
					//cout << "removeOn" << endl;
					newList->removeAt(randIndex);
					
					break;
				}
				break;
			case(3):
				operation_no = gen_number(2);
				switch (operation_no) {
				case(0):
					//operacia_spristupni(index);
					
					if (newList->size() == 0)
					{
						//cout << "chyba" << endl;
						continue;
					}
					//cout << "get" << endl;
					newList[gen_number(randIndex + 1)];
					
					break;
				case(1):
					//operacia_nastav(gen_number(range), gen_number(range));
					if (newList->size() == 0)
					{
						//cout << "chyba" << endl;
						continue;
					}
					//cout << "set" << endl;
					newList->set(gen_number(randIndex + 1), gen_number(5));
					
					break;
				}
				break;
			case(4):
				//operacia_index_prvku
				//cout << "getIndex" << endl;
				newList->getIndexOf(gen_number(10000));
				
				break;
			}
		}
		delete newList;
	}

	void test_adt_queue(int* arr)
	{
		for (int i = 0; i < MIL; i++)
		{
			switch (arr[i]) {
			case(1):
				//operacia_vloz(gen_number(range), gen_number(range));
				break;
			case(2):
				//operacia_vyber();
				break;
			case(3):
				//operacia_ukaz();
				break;
			}
		}
	}

	void call_test_list()
	{
		int* arr;
		arr = new int[MIL];
		structures::List<int>* newList = new structures::ArrayList<int>;
		int n = sizeof(arr) / sizeof(arr[0]);

		//0 - vloz, 1 - zrus, 2 - nastav, 3 - index
		int pomery[3][4] = {
				{15, 15, 60, 10},
				{30, 30, 30, 10},
				{40, 40, 5, 5}
		};

		int limits[3][4];
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				limits[i][j] = (MIL / 100) * pomery[i][j];
			}
		}

		for (int i = 0; i < 3; i++)
		{
			fill_array(arr, limits[i], 4);
			shuffle_array(arr, n);
			auto start = high_resolution_clock::now();
			test_adt_list(arr);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			cout << duration.count() << endl;
		}
		delete newList;
		delete[] arr;
	}

	void call_test_queue()
	{
		int arr[MIL];
		int n = sizeof(arr) / sizeof(arr[0]);

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
				printf("\n%i", limits[i][j]);
			}
		}

		for (int i = 0; i < 2; i++)
		{
			fill_array(arr, limits[i], 3);
			shuffle_array(arr, n);
			auto start = high_resolution_clock::now();
			test_adt_queue(arr);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			cout << duration.count() << endl;
		}
	}
}