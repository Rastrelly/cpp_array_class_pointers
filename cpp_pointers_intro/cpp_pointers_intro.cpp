#include <iostream>
#include "arrayClass.h"

using namespace std;

arrayCont * AC;

int main()
{
	AC = new arrayCont(10);
	for (int i = 0; i < AC->getn(); i++)
		AC->SetElement(i,i);

	AC->printArray();

	cout << endl;

	AC->makeArray(10);
	for (int i = 0; i < AC->getn(); i++)
		AC->SetElement(i, i+10);

	AC->printArray();

	cout << endl;

	AC->addElement(365);
	AC->printArray();

	cout << endl;

	AC->delElement(3);
	AC->printArray();

	cout << endl;
	AC->makeArray(0);
	AC->addElement(7);
	AC->addElement(1);
	AC->addElement(70);
	AC->addElement(3);
	AC->addElement(17);
	AC->addElement(21);
	AC->addElement(11);
	AC->addElement(2);
	AC->addElement(19);
	AC->addElement(36);
	cout << "\nUnsorted:\n";
	AC->printArray();
	AC->sort();
	cout << "\nSorted:\n";
	AC->printArray();
	system("pause");
}