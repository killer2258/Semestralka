#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//zahrka pole
void shuffle_array(int arr[], int n)
{
        unsigned seed = 0;

        shuffle(arr, arr + n, default_random_engine(seed));
}

int main()
{
        int arr[1000000];

        //podiely jednotlivych operacii, operacie reprezentuju cisla 1-4
        int pomer_vloz = 15;    //      1
        int pomer_zrus = 15;    //      2
        int pomer_nastav = 60;  //      3
        int pomer_index = 10;   //      4

        //percentaze
        int lim_1 = (1000000 / 100) * pomer_vloz;
        int lim_2 = (1000000 / 100) * pomer_zrus;
        int lim_3 = (1000000 / 100) * pomer_nastav;
        int lim_4 = (1000000 / 100) * pomer_index;

        //zarazky pre for
        int indent_1 = lim_1 + lim_2;
        int indent_2 = indent_1 + lim_3;

        //vlozi do pola pocet 1-tiek, 2-ok, 3-ok a 4-ok podla vypocitanych limitov
        for(int i = 0; i < 1000000; i++)
        {
                if(i < lim_1)
                        arr[i] = 1;
                else if(i < indent_1)
                        arr[i] = 2;
                else if(i < indent_2)
                        arr[i] = 3;
                else
                        arr[i] = 4;
        }


        int n = sizeof(arr) / sizeof(arr[0]);
        //zahrka pole haha
        shuffle_array(arr, n);

        //premenne pre overenie poctu vyskytov jednotlivych cisel v poli
        int counter1, counter2, counter3, counter4;

        for(int i = 0; i < 1000000; i++)
        {
                switch(arr[i]) {
                        case 1:
                        counter1++;
                        break;
                        case 2:
                        counter2++;
                        break;
                        case 3:
                        counter3++;
                        break;
                        case 4:
                        counter4++;
                        break;
                }
        }
        cout <<"1: "<< counter1 << "\n2: " << counter2 << "\n3: " << counter3 << "\n4: " << counter4;

    return 0;
}
