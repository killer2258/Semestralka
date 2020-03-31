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

void podiely_operacii::call_test_list(int array_or_list)
{
        int arr[MIL];
        int n = sizeof(arr) / sizeof(arr[0]);

        //0 - vloz, 1 - zrus, 2 - nastav, 3 - index
        int pomery[3][4] = {
                {15, 15, 60, 10},
                {30, 30, 30, 10},
                {40, 40, 5, 5}
        };

        int limits[3][4];
        for(int i = 0; i < 3; i++)
        {
                for(int j = 0; j < 4; j++)
                {
                        limits[i][j] = (MIL / 100) * pomery[i][j];
                        printf("\n%i", limits[i][j]);
                }
        }

        for(int i = 0; i < 3; i++)
        {
                fill_array(arr, limits[i], 4);
                shuffle_array(arr, n);
                test_adt_list(arr, array_or_list);
        }
}

void podiely_operacii::call_test_queue(int array_or_list)
{
        int arr[MIL];
        int n = sizeof(arr) / sizeof(arr[0]);

        //0 - vloz, 1 - zrus, 2 - nastav, 3 - index
        int pomery[2][3] = {
                {45, 45, 10},
                {50, 25, 25}
        };

        int limits[2][3];
        for(int i = 0; i < 2; i++)
        {
                for(int j = 0; j < 3; j++)
                {
                        limits[i][j] = (MIL / 100) * pomery[i][j];
                        printf("\n%i", limits[i][j]);
                }
        }

        for(int i = 0; i < 2; i++)
        {
                fill_array(arr, limits[i], 3);
                shuffle_array(arr, n);
                test_adt_queue(arr, array_or_list);
        }
}

int podiely_operacii::metoda()
{
        call_test_list(0);
        call_test_list(1);
        call_test_queue();
        return 0;
}

                              
