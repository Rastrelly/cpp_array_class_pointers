#pragma once

#include <iostream>


template <class arrTp> class arrayCont
{
private:
	arrTp * dynArr;
	int n;
public:
	arrayCont<arrTp>(int nElements);
	void makeArray(int nElements);
	void printArray();
	void cloneArray(arrTp * source, arrTp *& dest, int nE);
	void delElement(int nE);
	void addElement(arrTp val);
	bool elementInRange(int nE);
	void swapElements(arrTp e1, arrTp e2);
	void sortArray(arrTp *& arr, int l);
	void sort();

	int getn() { return n; }
	arrTp getElement(arrTp nE) { return dynArr[nE]; }
	void SetElement(int nE, arrTp val) { dynArr[nE] = val; }
};


using namespace std;

template <class arrTp> arrayCont<arrTp>::arrayCont(int nElements)
{
	makeArray(nElements);
}

template <class arrTp> void arrayCont<arrTp>::makeArray(int nElements)
{
	n = nElements;
	delete(dynArr);
	dynArr = new arrTp[n];
}

template <class arrTp> void arrayCont<arrTp>::printArray()
{
	for (int i = 0; i < getn(); i++)
		cout << getElement(i) << endl;
}


template <class arrTp> void arrayCont<arrTp>::cloneArray(arrTp * source, arrTp *& dest, int nE)
{
	for (int i = 0; i < nE; i++)
	{
		dest[i] = source[i];
	}
}

template <class arrTp> void arrayCont<arrTp>::delElement(int nE)
{
	if (elementInRange(nE))
	{
		for (int i = nE; i < (n - 1); i++)
		{
			dynArr[i] = dynArr[i + 1];
		}

		n--;
		arrTp * tempArr = new arrTp[n];

		cloneArray(dynArr, tempArr, n);

		makeArray(n);

		cloneArray(tempArr, dynArr, n);
	}
}


template <class arrTp> void arrayCont<arrTp>::addElement(arrTp val)
{
	arrTp * tempArr = new arrTp[n];

	cloneArray(dynArr, tempArr, n);

	n++;
	makeArray(n);
	cloneArray(tempArr, dynArr, n - 1);

	dynArr[n - 1] = val;

	delete(tempArr);
}

template <class arrTp> bool arrayCont<arrTp>::elementInRange(int nE)
{
	if ((nE >= 0) && (nE < n)) return true;
	else return false;
}

template <class arrTp> void arrayCont<arrTp>::swapElements(arrTp e1, arrTp e2)
{
	if ((elementInRange<arrTp>(e1)) && (elementInRange<arrTp>(e2)))
	{
		arrTp buff = dynArr[e1];
		dynArr[e1] = dynArr[e2];
		dynArr[e2] = buff;
	}
}


template <class arrTp> void arrayCont<arrTp>::sortArray(arrTp *& arr, int l)
{
	bool doneswaps = false;
	do
	{
		doneswaps = false;
		for (int i = 0; i < (n - 1); i++)
		{
			if (arr[i] > arr[i + 1])
			{
				arrTp b = arr[i]; arr[i] = arr[i + 1]; arr[i + 1] = b;
				doneswaps = true;
			}
		}

	} while (doneswaps);
}

template <class arrTp> void arrayCont<arrTp>::sort()
{
	sortArray(dynArr, n);
}