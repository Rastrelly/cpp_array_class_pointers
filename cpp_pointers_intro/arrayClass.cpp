#include "arrayClass.h"

using namespace std;

arrayCont::arrayCont(int nElements)
{
	makeArray(nElements);
}

void arrayCont::makeArray(int nElements)
{
	n = nElements;
	delete(dynArr);
	dynArr = new int[n];
}

void arrayCont::printArray()
{
	for (int i = 0; i < getn(); i++)
		cout << getElement(i) << endl;
}


void arrayCont::cloneArray(int * source, int *& dest, int nE)
{
	for (int i = 0; i < nE; i++)
	{
		dest[i] = source[i];
	}
}

void arrayCont::delElement(int nE)
{
	if (elementInRange(nE))
	{
		for (int i = nE; i < (n - 1); i++)
		{
			dynArr[i] = dynArr[i + 1];
		}

		n--;
		int * tempArr = new int[n];

		cloneArray(dynArr, tempArr, n);

		makeArray(n);

		cloneArray(tempArr, dynArr, n);
	}
}


void arrayCont::addElement(int val)
{
	int * tempArr = new int[n];

	cloneArray(dynArr, tempArr, n);

	n++;
	makeArray(n);
	cloneArray(tempArr, dynArr, n - 1);

	dynArr[n - 1] = val;

	delete(tempArr);
}

bool arrayCont::elementInRange(int nE)
{
	if ((nE >= 0) && (nE < n)) return true;
	else return false;
}

void arrayCont::swapElements(int e1, int e2)
{
	if ((elementInRange(e1)) && (elementInRange(e2)))
	{
		int buff = dynArr[e1];
		dynArr[e1] = dynArr[e2];
		dynArr[e2] = buff;
	}
}


void arrayCont::sortArray(int *& arr, int l)
{
	bool doneswaps = false;
	do
	{
		doneswaps = false;
		for (int i = 0; i < (n - 1); i++)
		{
			if (arr[i] > arr[i + 1])
			{
				int b = arr[i]; arr[i] = arr[i + 1]; arr[i + 1] = b;
				doneswaps = true;
			}
		}

	} while (doneswaps);
}

void arrayCont::sort()
{
	sortArray(dynArr, n);
}