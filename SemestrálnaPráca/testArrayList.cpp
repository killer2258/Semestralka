#include "testArrayList.h"
#include "../structures/list/list.h"
#include "../structures/list/array_list.h"
#include "../structures/list/linked_list.h"
#include <chrono>
#include <iostream>

void testArrayList::testA()
{
	structures::List<int>* newArrayList = new structures::ArrayList<int>;
	srand(time(NULL));

	for (int i = 0; i < 1000000; ++i)
	{
		std::chrono::high_resolution_clock::time_point start;
		
		int operationChance = (rand() % 100) + 1;
		int randIndex = 0;

		if (newArrayList->size() == 0)
		{
			randIndex = 0;
		}
		else
		{
			randIndex = rand() % newArrayList->size();
		}

		if (operationChance <= 15)
		{
			int numberOfOperation = rand() % 3;
			int parameter = rand() % 1000000;

			if (numberOfOperation == 0)
			{
				newArrayList->insertFirst(parameter);
			}
			else if (numberOfOperation == 1)
			{
				newArrayList->add(parameter);
			}
			else if (numberOfOperation == 2)
			{
				newArrayList->insert(parameter, randIndex);
			}
		}
		else if (operationChance >= 16 && operationChance <= 30)
		{
			int numberOfOperation = rand() % 3;
			if (numberOfOperation == 0)
			{
				newArrayList->removeFirst();
			}
			else if (numberOfOperation == 1)
			{
				newArrayList->removeLast();
			}
			else if (numberOfOperation == 2)
			{
				newArrayList->removeAt(randIndex);
			}
		}
		else if (operationChance >= 31 && operationChance <= 90)
		{
			int numberOfOperation = rand() % 2;
			int parameter = rand() % 1000000;
			if (numberOfOperation == 0)
			{
				newArrayList->operator[](randIndex);
			}
			else if (numberOfOperation == 1)
			{
				newArrayList->set(parameter, randIndex);
			}
		}
		else if (operationChance >= 91 && operationChance <= 100)
		{
			int parameter = rand() % 1000000;
			newArrayList->getIndexOf(parameter);
		}
		std::chrono::high_resolution_clock::time_point end;
		std::chrono::duration<double> trvanie = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
		std::cout << "It took " << trvanie.count() << " seconds.";
	}

}

void testArrayList::testB()
{
	structures::List<int>* newArrayList = new structures::ArrayList<int>;
	srand(time(NULL));

	for (int i = 0; i < 1000000; ++i)
	{
		std::chrono::high_resolution_clock::time_point start;

		int operationChance = (rand() % 100) + 1;
		int randIndex = 0;

		if (newArrayList->size() == 0)
		{
			randIndex = 0;
		}
		else
		{
			randIndex = rand() % newArrayList->size();
		}

		if (operationChance <= 30)
		{
			int numberOfOperation = rand() % 3;
			int parameter = rand() % 1000000;

			if (numberOfOperation == 0)
			{
				newArrayList->insertFirst(parameter);
			}
			else if (numberOfOperation == 1)
			{
				newArrayList->add(parameter);
			}
			else if (numberOfOperation == 2)
			{
				newArrayList->insert(parameter, randIndex);
			}
		}
		else if (operationChance >= 31 && operationChance <= 60)
		{
			int numberOfOperation = rand() % 3;
			if (numberOfOperation == 0)
			{
				newArrayList->removeFirst();
			}
			else if (numberOfOperation == 1)
			{
				newArrayList->removeLast();
			}
			else if (numberOfOperation == 2)
			{
				newArrayList->removeAt(randIndex);
			}
		}
		else if (operationChance >= 61 && operationChance <= 90)
		{
			int numberOfOperation = rand() % 2;
			int parameter = rand() % 1000000;
			if (numberOfOperation == 0)
			{
				newArrayList->operator[](randIndex);
			}
			else if (numberOfOperation == 1)
			{
				newArrayList->set(parameter, randIndex);
			}
		}
		else if (operationChance >= 91 && operationChance <= 100)
		{
			int parameter = rand() % 1000000;
			newArrayList->getIndexOf(parameter);
		}
		std::chrono::high_resolution_clock::time_point end;
		std::chrono::duration<double> trvanie = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
		std::cout << "It took " << trvanie.count() << " seconds.";
	}
}

void testArrayList::testC()
{
	structures::List<int>* newArrayList = new structures::ArrayList<int>;
	srand(time(NULL));

	for (int i = 0; i < 1000000; ++i)
	{
		std::chrono::high_resolution_clock::time_point start;

		int operationChance = (rand() % 100) + 1;
		int randIndex = 0;

		if (newArrayList->size() == 0)
		{
			randIndex = 0;
		}
		else
		{
			randIndex = rand() % newArrayList->size();
		}

		if (operationChance <= 40)
		{
			int numberOfOperation = rand() % 3;
			int parameter = rand() % 1000000;

			if (numberOfOperation == 0)
			{
				newArrayList->insertFirst(parameter);
			}
			else if (numberOfOperation == 1)
			{
				newArrayList->add(parameter);
			}
			else if (numberOfOperation == 2)
			{
				newArrayList->insert(parameter, randIndex);
			}
		}
		else if (operationChance >= 41 && operationChance <= 80)
		{
			int numberOfOperation = rand() % 3;
			if (numberOfOperation == 0)
			{
				newArrayList->removeFirst();
			}
			else if (numberOfOperation == 1)
			{
				newArrayList->removeLast();
			}
			else if (numberOfOperation == 2)
			{
				newArrayList->removeAt(randIndex);
			}
		}
		else if (operationChance >= 81 && operationChance <= 90)
		{
			int numberOfOperation = rand() % 2;
			int parameter = rand() % 1000000;
			if (numberOfOperation == 0)
			{
				newArrayList->operator[](randIndex);
			}
			else if (numberOfOperation == 1)
			{
				newArrayList->set(parameter, randIndex);
			}
		}
		else if (operationChance >= 91 && operationChance <= 100)
		{
			int parameter = rand() % 1000000;
			newArrayList->getIndexOf(parameter);
		}
		std::chrono::high_resolution_clock::time_point end;
		std::chrono::duration<double> trvanie = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
		std::cout << "It took " << trvanie.count() << " seconds.";
	}
}
