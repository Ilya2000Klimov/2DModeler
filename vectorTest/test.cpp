#include <iostream>
#include <string>
#include "vector.h"
using namespace std;
int main()
{
	cs1c::vector<double> myVector;
	cs1c::vector<double> myVector2(20);
	cs1c::vector<double>::iterator ptr;
	for (int i = 0; i < 11; i++)
	{
		myVector2.push_back(i);
	}
	for (int i = 11; i < 20; i++)
	{
		myVector.push_back(i);
	}

	cout << "The vector elements are : ";
	for (ptr = myVector.begin(); ptr < myVector.end(); ptr++)
		cout << *ptr << " ";

	cout <<endl << myVector.size() << endl;
	cout << myVector.capacity() << endl;

	ptr = myVector.begin();

	//advance(ptr, 3);

	myVector.erase(myVector.begin());

	cout << "The vector elements are : ";
	for (ptr = myVector.begin(); ptr < myVector.end(); ptr++)
		cout << *ptr << " ";

	cout <<endl << myVector.size() << endl;
	cout << myVector.capacity() << endl;

	ptr = myVector.begin();
	advance(ptr, 1);
	myVector.insert(ptr, myVector2[5]);

	cout << "The vector elements are : ";
	for (ptr = myVector.begin(); ptr < myVector.end(); ptr++)
		cout << *ptr << " ";

	cout <<endl << myVector.size() << endl;
	cout << myVector.capacity() << endl;
	cs1c::vector<string> stringVector(11);
	stringVector.push_back("1. Hello");
	stringVector.push_back("2. String 0ne");
	stringVector.push_back("3. Hello");
	stringVector.push_back("4. Hello");
	stringVector.push_back("5. Hello");
	stringVector.push_back("6. Hello");


	cs1c::vector<string> stringVector2 = stringVector;
	cs1c::vector<string>::iterator ptrS;

	cout << "The vector elements are : ";
	for (ptrS = stringVector2.begin(); ptrS < stringVector2.end(); ptrS++)
		cout << "["<< *ptrS << "] ";
	cout << endl;

	ptrS = &(stringVector2[1]);
	//advance(ptrS, 1);
	//stringVector2.insert(ptrS, stringVector[5]);
	stringVector2.erase(stringVector2.begin());

	cout << "The vector elements are : ";
	for (ptrS = stringVector2.begin(); ptrS < stringVector2.end(); ptrS++)
		cout << "["<< *ptrS << "] ";
	cout << endl;

	//cs1c::vector<int> myVector3;
	//myVector3.erase(myVector3.begin());

	//cout << "The vector elements are : ";
	//for (ptr = myVector3.begin(); ptr < myVector3.end(); ptr++)
	//	cout << *ptr << " ";


}