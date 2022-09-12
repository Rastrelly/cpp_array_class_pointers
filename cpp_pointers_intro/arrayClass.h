#pragma once

#include <iostream>


class arrayCont
{
private:
	int * dynArr;
	int n;
public:
	arrayCont(int nElements);
	void makeArray(int nElements);
	void printArray();
	void cloneArray(int * source, int *& dest, int nE);
	void delElement(int nE);
	void addElement(int val);
	bool elementInRange(int nE);
	void swapElements(int e1, int e2);
	void sortArray(int *& arr, int l);
	void sort();

	int getn() { return n; }
	int getElement(int nE) { return dynArr[nE]; }
	void SetElement(int nE, int val) { dynArr[nE] = val; }
};