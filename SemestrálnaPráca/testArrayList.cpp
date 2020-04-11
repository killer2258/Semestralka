#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <random>
#include "../structures/list/list.h"
#include "../structures/list/array_list.h"
#include "../structures/list/linked_list.h"
#include <chrono>
#include <fstream>
#include <thread>
#include <ratio>

#define MIL 1000

namespace testArrayList {
	using namespace std;

	//zahrka pole
	void shuffle_array(int* arr)
	{
		random_shuffle(&arr[0], &arr[MIL]);
	}

	//vyplni pole, ako argumenty berie pointer na prvy prvok pola arr, pole "limitov", kde su ulozene pocty,
	//kolkokrat sa ma podla zadanych percentazi vykonat jednotlive operacie.
	void fill_array(int* arr, int* limits, int amount)
	{
		//zarazky, aby cyklus vedel odkial pokial vyplnat pole 1kou, 2kou, alebo 3kou
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
	//pouzita funkcia rand je zo stdlib
	int gen_number(int range)
	{
		return rand() % range + 1;
	}

	//test pre ADT zoznam
	void test_adt_list(int* arr) {
		/*for (int i = 0; i < 100; i++)
			newList.insertFirst(5);*/
		
		std::ofstream outfile("operation_times_arraylist.txt");
		
		int operation_no;
		int randIndex;
		
		//inicializacie premennych pre funkciu casovania
		auto t1 = std::chrono::high_resolution_clock::now();
		auto t2 = std::chrono::high_resolution_clock::now();
		auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
		std::chrono::duration<double, std::milli> fp_ms;
		std::chrono::duration<long, std::micro> int_usec;
		
		structures::List<int>* newList = new structures::ArrayList<int>;
		
		//cyklus, ide od nuly po milion, prechadza pole, v ktorom su ulozene uz random poprehadzovane
		//ciselka a podla tychto ciselok sa vyberie operacia, resp. kategoria operacii, ktora sa ma vykonat
		for (int i = 0; i < MIL; i++)
		{
			//cout << arr[i] << endl;
			if (newList->size() == 0)
			{
				randIndex = 0;
			}
			else
			{
				randIndex = rand() % newList->size();
			}

			switch (arr[i]) {
			case(1):
				//vygeneruje cislo od jedna po 3, lebo 3 su operacie, ktore spadaju pod tuto kategoriu
				operation_no = gen_number(3);
				switch (operation_no) {
				case(1):
					//operacia_vloz_prvy(gen_number(range));
					//cout << newList->size() << endl;
					cout << "insertFirst" << endl;
					//akutalny cas pred vykonanim operacie
					t1 = std::chrono::high_resolution_clock::now();
					newList->insertFirst(gen_number(10000));
					//aktualny cas po vykonani operacie
					t2 = std::chrono::high_resolution_clock::now();
					//nemam sajnu ako toto funguje, to som skopcil :D
					int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
					int_usec = int_ms;
					outfile << "insert_first:" << fp_ms.count() << "ms" << std::endl;

					//outfile << "insert_first:" << fixed << time_span << setprecision(20);
					break;
				case(2):
					//operacia_vloz_posledny(gen_number(range));
					//cout << newList->size() << endl;
					cout << "insertLast" << endl;
					t1 = std::chrono::high_resolution_clock::now();
					newList->add(gen_number(10000));
					t2 = std::chrono::high_resolution_clock::now();
					fp_ms = t2 - t1;
					int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
					int_usec = int_ms;
					outfile << "insert_last:" << fp_ms.count() << "ms" << std::endl;
					break;
				case(3):
					//operacia_vloz_na_index(gen_number(range), gen_number(range))
					//cout << randIndex << endl;
					//cout << newList->size() << endl;
					cout << "insertOn" << endl;
					t1 = std::chrono::high_resolution_clock::now();
					newList->insert(gen_number(10000), randIndex);
					t2 = std::chrono::high_resolution_clock::now();
					fp_ms = t2 - t1;
					int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
					int_usec = int_ms;
					outfile << "insert_on:" << fp_ms.count() << "ms" << std::endl;
					break;
				}
				break;
			case(2):
				operation_no = gen_number(3);
				switch (operation_no) {
				case(1):
					//operacia_zrus_prvy();
					if (newList->size() == 0)
					{
						cout << "chyba" << endl;
						continue;
					}
					//cout << newList->size() << endl;
					cout << "removeFirst" << endl;
					t1 = std::chrono::high_resolution_clock::now();
					newList->removeFirst();
					t2 = std::chrono::high_resolution_clock::now();
					fp_ms = t2 - t1;
					int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
					int_usec = int_ms;
					outfile << "remove_first:" << fp_ms.count() << "ms" << std::endl;
					break;
				case(2):
					//operacia_zrus_posledny();
					if (newList->size() == 0)
					{
						cout << "chyba" << endl;
						continue;
					}
					//cout << newList->size() << endl;
					cout << "removeLast" << endl;
					t1 = std::chrono::high_resolution_clock::now();
					newList->removeLast();
					t2 = std::chrono::high_resolution_clock::now();
					fp_ms = t2 - t1;
					int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
					int_usec = int_ms;
					outfile << "remove_last:" << fp_ms.count() << "ms" << std::endl;

					break;
				case(3):
					//operacia_zrus_na_indexe(gen_number(range));
					if (newList->size() == 0)
					{
						cout << "chyba" << endl;
						continue;
					}
					//cout << newList->size() << endl;
					cout << "removeOn" << endl;
					t1 = std::chrono::high_resolution_clock::now();
					newList->removeAt(randIndex);
					t2 = std::chrono::high_resolution_clock::now();
					fp_ms = t2 - t1;
					int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
					int_usec = int_ms;
					outfile << "remove_on:" << fp_ms.count() << "ms" << std::endl;

					break;
				}
				break;
			case(3):
				operation_no = gen_number(2);
				switch (operation_no) {
				case(1):
					//operacia_spristupni(index);

					if (newList->size() == 0)
					{
						cout << "chyba" << endl;
						continue;
					}
					cout << "get" << endl;
					t1 = std::chrono::high_resolution_clock::now();
					newList[(randIndex)];
					t2 = std::chrono::high_resolution_clock::now();
					fp_ms = t2 - t1;
					int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
					int_usec = int_ms;
					outfile << "get:" << fp_ms.count() << "ms" << std::endl;

					break;
				case(2):
					//operacia_nastav(gen_number(range), gen_number(range));
					if (newList->size() == 0)
					{
						//cout << "chyba" << endl;
						continue;
					}
					cout << "set" << endl;
					t1 = std::chrono::high_resolution_clock::now();
					newList->set(randIndex, gen_number(5));
					t2 = std::chrono::high_resolution_clock::now();
					fp_ms = t2 - t1;
					int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
					int_usec = int_ms;
					outfile << "set:" << fp_ms.count() << "ms" << std::endl;

					break;
				}
				break;
			case(4):
				//operacia_index_prvku
				cout << "getIndex" << endl;
				t1 = std::chrono::high_resolution_clock::now();
				newList->getIndexOf(gen_number(10000));
				t2 = std::chrono::high_resolution_clock::now();
				fp_ms = t2 - t1;
				int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
				int_usec = int_ms;
				outfile << "get_index:" << fp_ms.count() << "ms" << std::endl;

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

		//toto bolo tusim kvoli tomu hrkaniu, alebo random cislo, ale to uz je asi prec, ci ?
		int n = sizeof(arr) / sizeof(arr[0]);
		
		structures::List<int>* newList = new structures::ArrayList<int>;

		//vytvori 2d pole, riadky su jednotlive scenare, stlpce su podiely operacii
		int pomery[3][4] = {
				{15, 15, 60, 10},
				{30, 30, 30, 10},
				{40, 40, 5, 5}
		};
		
		//vypocita, kolkokrat sa maju jednotlive operacie vykonat a prislusne pocty vyplni do rovnako velkeho
		//pola limits
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
			srand(time(NULL));
			shuffle_array(arr);
			test_adt_list(arr);
		}
		delete newList;

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
			shuffle_array(arr);
			test_adt_queue(arr);
		}
	}
}
