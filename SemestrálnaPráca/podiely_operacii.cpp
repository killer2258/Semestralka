#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <random>
#include "podiely_operacii.h"
#include "../structures/list/array_list.h"
#include "../structures/list/linked_list.h"

#define MIL 1000000

using namespace std;

//zahrka pole
void podiely_operacii::shuffle_array(int arr[], int n)
{
	unsigned seed = 0;
	shuffle(arr, arr + n, default_random_engine(seed));
}

void podiely_operacii::fill_array(int* arr, int* limits, int amount)
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
int podiely_operacii::gen_number(int range)
{
	srand(time(NULL));
	return rand() % range + 1;
}

//test pre ADT zoznam
void podiely_operacii::test_adt_list(int* arr, int adt_number) {
	int operation_no;
	for (int i = 0; i < MIL; i++)
	{
		switch (arr[i]) {
		case(1):
			operation_no = gen_number(3);
			switch (operation_no) {
			case(1):
				//operacia_vloz_prvy(gen_number(range));
				if (adt_number == 0) 
				{
					structures::ArrayList<int>().insertFirst(gen_number(5));
				}
				else if (adt_number == 1)
				{
					structures::LinkedList<int>().insertFirst(gen_number(5));
				}
				else
				{
					cout << "Chybne cislo ADT." << endl;
				}
				break;
			case(2):
				//operacia_vloz_posledny(gen_number(range));
				if (adt_number == 0)
				{
					structures::ArrayList<int>().add(gen_number(5));
				}
				else if (adt_number == 1)
				{
					structures::LinkedList<int>().add(gen_number(5));
				}
				else
				{
					cout << "Chybne cislo ADT." << endl;
				}
				break;
			case(3):
				//operacia_vloz_na_index(gen_number(range), gen_number(range))
				if (adt_number == 0)
				{
					structures::ArrayList<int>().insert(gen_number(5),gen_number(5));
				}
				else if (adt_number == 1)
				{
					structures::LinkedList<int>().insert(gen_number(5),gen_number(5));
				}
				else
				{
					cout << "Chybne cislo ADT." << endl;
				}
				break;
			}
			break;
		case(2):
			operation_no = gen_number(3);
			switch (operation_no) {
			case(1):
				//operacia_zrus_prvy();
				if (adt_number == 0)
				{
					structures::ArrayList<int>().removeFirst();
				}
				else if (adt_number == 1)
				{
					structures::LinkedList<int>().removeFirst();
				}
				else
				{
					cout << "Chybne cislo ADT." << endl;
				}
				break;
			case(2):
				//operacia_zrus_posledny();
				if (adt_number == 0)
				{
					structures::ArrayList<int>().removeLast();
				}
				else if (adt_number == 1)
				{
					structures::LinkedList<int>().removeLast();
				}
				else
				{
					cout << "Chybne cislo ADT." << endl;
				}
				break;
			case(3):
				//operacia_zrus_na_indexe(gen_number(range));
				if (adt_number == 0)
				{
					structures::ArrayList<int>().removeAt(gen_number(5));
				}
				else if (adt_number == 1)
				{
					structures::LinkedList<int>().removeAt(gen_number(5));
				}
				else
				{
					cout << "Chybne cislo ADT." << endl;
				}
				break;
			}
			break;
		case(3):
			operation_no = gen_number(2);
			switch (operation_no) {
			case(1):
				//operacia_spristupni(index);
				if (adt_number == 0)
				{
					structures::ArrayList<int>().operator[];
				}
				else if (adt_number == 1)
				{
					structures::LinkedList<int>().operator[];
				}
				else
				{
					cout << "Chybne cislo ADT." << endl;
				}
				break;
			case(2):
				//operacia_nastav(gen_number(range), gen_number(range));
				if (adt_number == 0)
				{
					structures::ArrayList<int>().set(gen_number(5), gen_number(5));
				}
				else if (adt_number == 1)
				{
					structures::LinkedList<int>().set(gen_number(5), gen_number(5));
				}
				else
				{
					cout << "Chybne cislo ADT." << endl;
				}
				break;
			}
			break;
		case(4):
			//operacia_index_prvku
			if (adt_number == 0)
			{
				structures::ArrayList<int>().getIndexOf(gen_number(5));
			}
			else if (adt_number == 1)
			{
				structures::LinkedList<int>().getIndexOf(gen_number(5));
			}
			else
			{
				cout << "Chybne cislo ADT." << endl;
			}
			break;
		}
	}
}

void podiely_operacii::test_adt_queue(int* arr)
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

int podiely_operacii::metoda()
{
	int arr[MIL];
	int pomer_vloz_zoznam = 15;
	int pomer_zrus_zoznam = 15;
	int pomer_nastav_zoznam = 60;
	int pomer_index_zoznam = 10;

	int limits[4];

	limits[0] = (MIL / 100) * pomer_vloz_zoznam;
	limits[1] = (MIL / 100) * pomer_zrus_zoznam;
	limits[2] = (MIL / 100) * pomer_nastav_zoznam;
	limits[3] = (MIL / 100) * pomer_index_zoznam;

	//vyplni pole hodnotami
	fill_array(arr, limits, 4);

	int n = sizeof(arr) / sizeof(arr[0]);

	//zahrka pole haha
	shuffle_array(arr, n);

	int pomer_vloz_front = 45;
	int pomer_vyber_front = 45;
	int pomer_ukaz_front = 10;

	limits[0] = (MIL / 100) * pomer_vloz_front;
	limits[1] = (MIL / 100) * pomer_vyber_front;
	limits[2] = (MIL / 100) * pomer_ukaz_front;
	limits[3] = 0;

	//vyplni pole hodnotami
	fill_array(arr, limits, 3);

	//zahrka pole haha
	shuffle_array(arr, n);


	return 0;
}
