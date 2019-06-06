// MotorBike-ShowRoom-System
//C++ language that apply class and object,linked list,searching and sorting. 
//This program have several function such as insert,delete,search,refresh and delete.
//This program also have computer security technique when try to insert password, the word of password was encrypt using coding technique.
//This program about model of motorbike and learning process in data structure and algorithm.



//Main.cpp

//************Thiasan,Razin,Aimi,Omar************
#include<iostream>
#include<string>
#include<conio.h>
#include<stdlib.h>
#include <cstdlib>
#define _CRT_SECURE_NO_WARNINGS
#define getch() _getch()
#include "motor.h"
using namespace std;

int main()
{	
	system("color 60");
	// here has 2 exit type, first is exit selecting page(admin only) but not close the program, second is close program
	char select = '6'; 		// In the switch below, 6 means non-admin can only search result in student-mode
	char admin;
	string name;
	List<int> x;
start:
	x.getData();

	system("CLS");
	

cout << "_________________________________________Welcome_______________________________________________";

	cout << "\n\n\n\n\n\t\t\t  Are you a admin ? \n\n\n\n\t\t\t\t Yes[y]\t\t  No[n]\n\n";
	cout << "\t\t\t\t   ";
	cin >> admin;

	if (admin == 'Y' || admin == 'y') 
	{		
		
		string userId = "admin";//user id name
		system("CLS");
	d:
		cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t---------------------";
		cout << "\n\t\t\t\t\t\t\tEnter Login Id = ";
		cin >> userId;
		cout << "\t\t\t\t\t\t\t---------------------";
		if (userId != "admin")
		{
			cout << "\nDon't try to be smart.....Enter correct id\n";
			goto d;
		}
		else
			cout << "\n\n\n\t\t\t\t\t\t\tHello Admin,\n";
	z:
		string pwd = "pass";  //password
		string pass = "";
		char c;
		cout << "\n\n\n\t\t\t\t\t\t\tPassword = ";
	p:
		c = getch();
		cout << "*";   //for printing * instead for password(encrypt)
		if (c != 13)
		{
			pass = pass + c;
			goto p;
		}

		if (pass == pwd)
		{
			cout << "\n\n\t\t\t\t\t\t\tAccess Granted. Welcome to our system\n\n\n";
			system("PAUSE");
			system("CLS");
			goto e;
		}
		else
		{
			cout << "\n\n\t\t\t\t\t\t\tWrong Password\n";
			goto z;
		}
	}
	e:
	while (1)
	{
		if (admin == 'y' || admin == 'Y') {

		reselect:
			cout << "\n----------------Menu-------------------------\n";
			cout << "\nPress 1 for insert new data" << endl; // THIASAN CHANDRAN
			cout << "Press 2 for update the data" << endl; // AIMI ZAINUDIN
			cout << "Press 3 for deleting the certain data" << endl; // AHMAD RAZIN
			cout << "Press 4 for deleting all data" << endl;
			cout << "Press 5 for printing the list" << endl; // THIASAN CHANDRAN
			cout << "Press 6 for searching" << endl; //  AHMAD RAZIN
			cout << "Press 7 to refresh the page" << endl;
			cout << "Press 8 to exit your account" << endl; // OMAR
			cout << "\n*If you want to close this program, Press any button else\n\n: ";
			cin >> select;
		}
		else if (admin == 'n' || admin == 'N') select = '6';
		else {
			cout << "\n\n------You have entered an invalid input...!--------\n";
			x.finish();
			x.deleteall();	//******Notice! any time exit also need to clear the storage, bsc if not clear but use the program again, it will read data again from txt again and cause two same data store in the link list (exp: if has 3 data, the second time run will have 6 node!)
			goto start;
		}

		system("CLS");
		switch (select)
		{
		case '1':
			x.append();
			system("CLS");
			break;
		case '2':
			x.list();
			x.updata();
			x.finish();
			break;
		case '3':
			x.del();
			x.finish();
			break;
		case '4':
			x.deleteall();
			cout << "\n\n----------------All Data Is Deleted Successfully-----------------------\n\n";
			x.finish();
			break;
		case '5':
			x.list();
			break;
		case '6':
			x.search(admin);
			if (admin != 'y') {
				system("pause");
				//cout << "\n\n----------Thankyou for using this system-----------\n\n";
				goto  end;
        
        //motor.cpp
        

#include <conio.h>
#include <windows.h>
#include<iostream>
#include<string>
#include<stdlib.h>
#include <iomanip>
#include<fstream>
#include "motor.h"

using namespace std;

template <class T>
List<T>::List() {
	head = NULL;
	numItem = 0;

}

template <class T>
void List<T>::getData() {

	ifstream of;
	of.open("record2.txt");
	of.ignore(1, '\n');

	while (of) {
		ListNode* pNew = new ListNode;

		getline(of, pNew->model, ':');
		of >> pNew->id;
		for (int i = 0; i < 3; i++) {
			of >> pNew->price[i];
		}

		of.ignore(1, '\n');

		pNew->next = head;
		head = pNew;

		numItem++;
	}
	of.close();
	if (numItem >= 2)sorting();	// if only one item, no need sorting
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ********* THIASAN CHANDRAN ********

template <class T>
void List<T>::append()
{
	char choose = 'y';
	//head = NULL;

	while (choose == 'y' || choose == 'Y') {
		system("CLS");
		cout << "---------------Insert New Item--------------------------\n";
		ListNode* pNew = new ListNode;
		cout << "\nEnter MotorBike Id:  ";
		cin >> pNew->id;
		cin.ignore();

		cout << "\nEnter MotorBike's Model :  ";
		getline(std::cin, pNew->model);

		cout << "\nEnter price(RM) :  \n";
		for (int i = 0; i < 3; i++) {
			cout << "Price of " << priceof[i] << "\t: ";
			cin >> pNew->price[i];
		}
		pNew->next = head;
		head = pNew;
		cout << "\n-----------------New data is created successfully--------------\n";
		numItem++;

		cout << "\n\nContinue?\n\nIf yes, please enter y/Y\n\nOr enter any key to exit\n\n: ";
		cin >> choose;
	}
	if (numItem >= 2)sorting();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ********* AIMI ZAINUDIN *********

template <class T>
int List<T>::del() {
	if (head == NULL) {
		cout << "\n\n--------------Nothing can be deleted------------\n"; return 0;
	}
	list();
	char del_based;
choose_again:
	cout << "-----------------------------------------\n";
	cout << "Delete Item\n";
	cout << "You want to delete the data based on model or id?\n[1] Model\n[2] ID\n";
	cin >> del_based;
	if (del_based == '1')deletename();
	else if (del_based == '2')deleteid();
	else {
		cout << "\n------You have entered an invalid input...!--------\n";
		goto choose_again;
	}
	return 0;
}
template <class T>
void List<T>::deleteid()
{

	pCur = head;
	ListNode* pPre = NULL;
	ListNode* pNext = NULL;
	int value;

	cout << "------------------Delete Item (Based Id)-----------------------\n";
	cout << "\nPlease Enter The Id Number: ";
	cin >> value;

	while (pCur->id != value && pCur->next != NULL)
	{
		pPre = pCur;
		pCur = pCur->next;

	}

	if (pCur->id != value)
	{
		cout << "\n--------------Sorry no data found!!!---------------------------\n";
	}
	else if (pPre == NULL)
	{
		pNext = pCur->next;
		head = pNext;
		delete pCur;
		numItem--;
		cout << "\n--------------Deleted successfully---------------------------\n";
	}
	else
	{
		pNext = pCur->next;
		pPre->next = pNext;
		delete pCur;
		numItem--;
		cout << "\n--------------Deleted successfully---------------------------\n";
	}

}
template <class T>
void List<T>::deletename()
{
	ListNode* temp = head;
	ListNode* prev = NULL;
	ListNode* tempnext = NULL;
	string value;
	cout << "-----------------Delete Item (Based Model)------------------------\n";
	cout << "Please enter the model: ";
	cin.ignore(10000, '\n');
	getline(cin, value);

	while (temp->model != value && temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp->model != value)
	{
		cout << "\n--------------Sorry no data found!!!---------------------------\n";
	}
	else if (prev == NULL)
	{
		tempnext = temp->next;
		head = tempnext;
		delete temp;
		numItem--;
		cout << "\n--------------Deleted successfully---------------------------\n";
	}
	else
	{
		tempnext = temp->next;
		prev->next = tempnext;
		delete temp;
		numItem--;
		cout << "\n--------------Deleted successfully---------------------------\n";
	}
}
template <class T>
void List<T>::deleteall()
{
	ListNode* temphead = head, * temp;
	while (temphead != NULL)
	{
		temp = temphead->next;
		delete temphead;
		temphead = temp;
		numItem--;
	}
	head = NULL;


}////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ************* THIASAN CHANDRAN**********

template <class T>
void List<T>::list()
{
	if (numItem >= 2)sorting();	//if only one item, no need sorting
	cout << "--------------Printing Information----------------------\n\n";
	if (head == NULL)
	{
		cout << "" << endl;
		cout << "---------------There is nothing to print-------------------\n\n";
		return;
	}
	pCur = head;
	cout << "Id\tName\t\t";
	for (int i = 0; i < 3; i++) {
		cout << "price(" << priceof[i] << left << setw(5) << ")";
	}
	cout << "    Total_price\n";
	while (pCur)
	{
		T total = 0;

		cout << pCur->id << "\t" << pCur->model << "\t\t  ";
		for (int i = 0; i < 3; i++) {
			cout << left << setw(20) << pCur->price[i];
			total += pCur->price[i];
		}
		cout << " " << total << endl;
		pCur = pCur->next;
	}
	cout << "\nTotal  Data : " << numItem << endl;
	cout << "-----------------------------------------\n";
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// ******** AHMAD RAZIN **********
template <class T>

void List<T>::search(char admin) {		// *in admin mode if you search '5', you can get all data contain the '5', exp: '12345', '54'... 

	//int num = 1;
	int found = 0;
	int target;
	//if (numItem == 0) goto no_data;
	pCur = head;
	cout << "----------------Searching-------------------------\n";
	cout << "\nPlease enter your target id : ";
	cin >> target;
	while (pCur != NULL) {

		bool result = false;
		if (admin == 'y' || admin == 'Y') {		//------------if you are admin------------
			string from = to_string(pCur->id);
			string tar = to_string(target);
			size_t pos = from.find(tar);
			if (pos != std::string::npos)result = true;
		}
		else {			//---------------if you are normal staff------------
			if (target == pCur->id) { result = true; }
		}

		if (result) {
			T total = 0;

			cout << "\n\nId : " << pCur->id;
			cout << "\t\tmodel : " << pCur->model;
			for (int i = 0; i < 3; i++) {
				cout << "\n\tprice " << priceof[i] << "\t: " << pCur->price[i];
				total += pCur->price[i];
			}
			cout << "\n\tTotal Price\t: " << total << endl << endl;

			found++;
		}
		pCur = pCur->next;
		//num++;

	}
	if (found == 0) {

		cout << "\n--------------Sorry no data found!!!---------------------------\n\n";
	}
	else if (admin == 'y' || admin == 'Y')cout << "\n\n----Found " << found << " result(s)---";

}

/////////////////////////////////////////////////////////////////////////////////////////////////////

// ********* AHMAD RAZIN ******************
template <class T>
void List<T>::sorting() {

	pCur2 = head;
	while (pCur2->next != NULL) {
		pCur = head;
		while (pCur->next != NULL) {
			if (pCur->id > pCur->next->id) {
				//---------------reversing data---------------------- 
				int id = pCur->id;
				pCur->id = pCur->next->id;
				pCur->next->id = id;

				string model = pCur->model;
				pCur->model = pCur->next->model;
				pCur->next->model = model;

				for (int i = 0; i < 3; i++) {
					T  tempprice = pCur->price[i];
					pCur->price[i] = pCur->next->price[i];
					pCur->next->price[i] = tempprice;
				}
			}
			pCur = pCur->next;
		}
		pCur2 = pCur2->next;
	}
}


////////////////////////////////////////////////////////////////////////////////////////////


//********** AIMI ZAINUDIN *************
template <class T>

void List<T>::updata() {

	int target;

	pCur = head;
	cout << "\n--------------------Update Information---------------------\n";
	cout << "\nPlease enter your target id exactly : ";
	cin >> target;
	while (pCur != NULL) {

		if (target == pCur->id) {
			char changeItem;
		again:
			cout << "\nWhat you want to update?\n1 - Id\n2 - Model\n3 - Price\nYour Choice : ";
			cin >> changeItem;

			if (changeItem == '1') {
				cout << "\n\nPlease enter the new Id : ";
				cin >> pCur->id;
				cout << "\n--------------------Update successfully---------------------\n";
			}
			else if (changeItem == '2') {
				cout << "\n\nPlease enter the new model : ";
				cin.ignore();
				getline(cin, pCur->model);
				cout << "\n--------------------Update successfully---------------------\n";
			}
			else if (changeItem == '3') {
				int select_priceof;
			again2:
				cout << "\nWhich country's price  you want to make change?\n1- Original Price\t2- Service Tax\t 3- SST\n: ";
				cin >> select_priceof;
				if (select_priceof == 1 || select_priceof == 2 || select_priceof == 3) {

					cout << "Please enter the new data: ";

					cin >> pCur->price[select_priceof - 1];

					cout << "\n--------------------Update successfully---------------------\n";
					break;
				}
				else { cout << "\n------You have entered an invalid input...!--------\n\n"; goto again2; }
			}
			else {
				cout << "\n------You have entered an invalid input...!--------\n";
				goto again;
			}
			break;
		}
		pCur = pCur->next;
		if (pCur == NULL) {
			cout << "\n--------------Sorry no data found!!!---------------------------\n\n";
		}
	}
}

template <class T>
void List<T>::exitprog(char admin)
{
	if (admin == 'y' || admin == 'Y')saveChange();
	system("CLS");
	cout << "\n---------Thank you for using this system-----------\n\n";
	deleteall();

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

// ************* Omar ************

template <class T>
void List<T>::saveChange() {
	char save;
	ofstream of;
	cout << "---------------------Exit Page---------------------------------";
	cout << "******\n\n[1] Save and Exit\n[2] Save in another file, the content of original record will not be change\n\n*Any button else to exit without saving\n\n\n: ";
	cin >> save;
	if (save == '1') {

		of.open("record2.txt");
	saving:

		pCur = head;


		if (pCur == NULL) {
			of.close();
			remove("record2.txt");
		}
		else {

			while (pCur) {
				of << endl << pCur->model + ":";
				of << " " << pCur->id;
				for (int i = 0; i < 3; i++) {
					of << " " << pCur->price[i];
				}

				pCur = pCur->next;
			}
			of.close();

		}
		cout << "\n\n------------Data is stored-------------------\n\n";
		system("pause");
	}

	else if (save == '2') {
		string save_new_file;
		cout << "\n\nPlease enter the model that you want to save inside \n: ";
		cin.ignore();
		getline(cin, save_new_file);
		save_new_file += ".txt";
		of.open(save_new_file);
		goto saving;
	}

}

template <class T>
void List<T>::refresh() {
	deleteall();
	getData();
	cout << "\n\n-----------------Refresh is completed-----------------\n\n";
	finish();
}
template <class T>
void List<T>::finish() {
	cout << endl;
	system("pause");
	system("CLS");
}
template class List<int>;

template class List<double>;


			}

			x.finish();
			break;
		case '7':
			x.refresh();
			goto reselect;
		case '8':
		end:
			x.exitprog(admin);
			x.finish();
			goto start;
			break;

		default:
			return 0;
		}
	}

}

//motor.cpp


#include <conio.h>
#include <windows.h>
#include<iostream>
#include<string>
#include<stdlib.h>
#include <iomanip>
#include<fstream>
#include "motor.h"

using namespace std;

template <class T>
List<T>::List() {
	head = NULL;
	numItem = 0;

}

template <class T>
void List<T>::getData() {

	ifstream of;
	of.open("record2.txt");
	of.ignore(1, '\n');

	while (of) {
		ListNode* pNew = new ListNode;

		getline(of, pNew->model, ':');
		of >> pNew->id;
		for (int i = 0; i < 3; i++) {
			of >> pNew->price[i];
		}

		of.ignore(1, '\n');

		pNew->next = head;
		head = pNew;

		numItem++;
	}
	of.close();
	if (numItem >= 2)sorting();	// if only one item, no need sorting
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ********* THIASAN CHANDRAN ********

template <class T>
void List<T>::append()
{
	char choose = 'y';
	//head = NULL;

	while (choose == 'y' || choose == 'Y') {
		system("CLS");
		cout << "---------------Insert New Item--------------------------\n";
		ListNode* pNew = new ListNode;
		cout << "\nEnter MotorBike Id:  ";
		cin >> pNew->id;
		cin.ignore();

		cout << "\nEnter MotorBike's Model :  ";
		getline(std::cin, pNew->model);

		cout << "\nEnter price(RM) :  \n";
		for (int i = 0; i < 3; i++) {
			cout << "Price of " << priceof[i] << "\t: ";
			cin >> pNew->price[i];
		}
		pNew->next = head;
		head = pNew;
		cout << "\n-----------------New data is created successfully--------------\n";
		numItem++;

		cout << "\n\nContinue?\n\nIf yes, please enter y/Y\n\nOr enter any key to exit\n\n: ";
		cin >> choose;
	}
	if (numItem >= 2)sorting();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ********* AIMI ZAINUDIN *********

template <class T>
int List<T>::del() {
	if (head == NULL) {
		cout << "\n\n--------------Nothing can be deleted------------\n"; return 0;
	}
	list();
	char del_based;
choose_again:
	cout << "-----------------------------------------\n";
	cout << "Delete Item\n";
	cout << "You want to delete the data based on model or id?\n[1] Model\n[2] ID\n";
	cin >> del_based;
	if (del_based == '1')deletename();
	else if (del_based == '2')deleteid();
	else {
		cout << "\n------You have entered an invalid input...!--------\n";
		goto choose_again;
	}
	return 0;
}
template <class T>
void List<T>::deleteid()
{

	pCur = head;
	ListNode* pPre = NULL;
	ListNode* pNext = NULL;
	int value;

	cout << "------------------Delete Item (Based Id)-----------------------\n";
	cout << "\nPlease Enter The Id Number: ";
	cin >> value;

	while (pCur->id != value && pCur->next != NULL)
	{
		pPre = pCur;
		pCur = pCur->next;

	}

	if (pCur->id != value)
	{
		cout << "\n--------------Sorry no data found!!!---------------------------\n";
	}
	else if (pPre == NULL)
	{
		pNext = pCur->next;
		head = pNext;
		delete pCur;
		numItem--;
		cout << "\n--------------Deleted successfully---------------------------\n";
	}
	else
	{
		pNext = pCur->next;
		pPre->next = pNext;
		delete pCur;
		numItem--;
		cout << "\n--------------Deleted successfully---------------------------\n";
	}

}
template <class T>
void List<T>::deletename()
{
	ListNode* temp = head;
	ListNode* prev = NULL;
	ListNode* tempnext = NULL;
	string value;
	cout << "-----------------Delete Item (Based Model)------------------------\n";
	cout << "Please enter the model: ";
	cin.ignore(10000, '\n');
	getline(cin, value);

	while (temp->model != value && temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp->model != value)
	{
		cout << "\n--------------Sorry no data found!!!---------------------------\n";
	}
	else if (prev == NULL)
	{
		tempnext = temp->next;
		head = tempnext;
		delete temp;
		numItem--;
		cout << "\n--------------Deleted successfully---------------------------\n";
	}
	else
	{
		tempnext = temp->next;
		prev->next = tempnext;
		delete temp;
		numItem--;
		cout << "\n--------------Deleted successfully---------------------------\n";
	}
}
template <class T>
void List<T>::deleteall()
{
	ListNode* temphead = head, * temp;
	while (temphead != NULL)
	{
		temp = temphead->next;
		delete temphead;
		temphead = temp;
		numItem--;
	}
	head = NULL;


}////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ************* THIASAN CHANDRAN**********

template <class T>
void List<T>::list()
{
	if (numItem >= 2)sorting();	//if only one item, no need sorting
	cout << "--------------Printing Information----------------------\n\n";
	if (head == NULL)
	{
		cout << "" << endl;
		cout << "---------------There is nothing to print-------------------\n\n";
		return;
	}
	pCur = head;
	cout << "Id\tName\t\t";
	for (int i = 0; i < 3; i++) {
		cout << "price(" << priceof[i] << left << setw(5) << ")";
	}
	cout << "    Total_price\n";
	while (pCur)
	{
		T total = 0;

		cout << pCur->id << "\t" << pCur->model << "\t\t  ";
		for (int i = 0; i < 3; i++) {
			cout << left << setw(20) << pCur->price[i];
			total += pCur->price[i];
		}
		cout << " " << total << endl;
		pCur = pCur->next;
	}
	cout << "\nTotal  Data : " << numItem << endl;
	cout << "-----------------------------------------\n";
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// ******** AHMAD RAZIN **********
template <class T>

void List<T>::search(char admin) {		// *in admin mode if you search '5', you can get all data contain the '5', exp: '12345', '54'... 

	//int num = 1;
	int found = 0;
	int target;
	//if (numItem == 0) goto no_data;
	pCur = head;
	cout << "----------------Searching-------------------------\n";
	cout << "\nPlease enter your target id : ";
	cin >> target;
	while (pCur != NULL) {

		bool result = false;
		if (admin == 'y' || admin == 'Y') {		//------------if you are admin------------
			string from = to_string(pCur->id);
			string tar = to_string(target);
			size_t pos = from.find(tar);
			if (pos != std::string::npos)result = true;
		}
		else {			//---------------if you are normal staff------------
			if (target == pCur->id) { result = true; }
		}

		if (result) {
			T total = 0;

			cout << "\n\nId : " << pCur->id;
			cout << "\t\tmodel : " << pCur->model;
			for (int i = 0; i < 3; i++) {
				cout << "\n\tprice " << priceof[i] << "\t: " << pCur->price[i];
				total += pCur->price[i];
			}
			cout << "\n\tTotal Price\t: " << total << endl << endl;

			found++;
		}
		pCur = pCur->next;
		//num++;

	}
	if (found == 0) {

		cout << "\n--------------Sorry no data found!!!---------------------------\n\n";
	}
	else if (admin == 'y' || admin == 'Y')cout << "\n\n----Found " << found << " result(s)---";

}

/////////////////////////////////////////////////////////////////////////////////////////////////////

// ********* AHMAD RAZIN ******************
template <class T>
void List<T>::sorting() {

	pCur2 = head;
	while (pCur2->next != NULL) {
		pCur = head;
		while (pCur->next != NULL) {
			if (pCur->id > pCur->next->id) {
				//---------------reversing data---------------------- 
				int id = pCur->id;
				pCur->id = pCur->next->id;
				pCur->next->id = id;

				string model = pCur->model;
				pCur->model = pCur->next->model;
				pCur->next->model = model;

				for (int i = 0; i < 3; i++) {
					T  tempprice = pCur->price[i];
					pCur->price[i] = pCur->next->price[i];
					pCur->next->price[i] = tempprice;
				}
			}
			pCur = pCur->next;
		}
		pCur2 = pCur2->next;
	}
}


////////////////////////////////////////////////////////////////////////////////////////////


//********** AIMI ZAINUDIN *************
template <class T>

void List<T>::updata() {

	int target;

	pCur = head;
	cout << "\n--------------------Update Information---------------------\n";
	cout << "\nPlease enter your target id exactly : ";
	cin >> target;
	while (pCur != NULL) {

		if (target == pCur->id) {
			char changeItem;
		again:
			cout << "\nWhat you want to update?\n1 - Id\n2 - Model\n3 - Price\nYour Choice : ";
			cin >> changeItem;

			if (changeItem == '1') {
				cout << "\n\nPlease enter the new Id : ";
				cin >> pCur->id;
				cout << "\n--------------------Update successfully---------------------\n";
			}
			else if (changeItem == '2') {
				cout << "\n\nPlease enter the new model : ";
				cin.ignore();
				getline(cin, pCur->model);
				cout << "\n--------------------Update successfully---------------------\n";
			}
			else if (changeItem == '3') {
				int select_priceof;
			again2:
				cout << "\nWhich country's price  you want to make change?\n1- Original Price\t2- Service Tax\t 3- SST\n: ";
				cin >> select_priceof;
				if (select_priceof == 1 || select_priceof == 2 || select_priceof == 3) {

					cout << "Please enter the new data: ";

					cin >> pCur->price[select_priceof - 1];

					cout << "\n--------------------Update successfully---------------------\n";
					break;
				}
				else { cout << "\n------You have entered an invalid input...!--------\n\n"; goto again2; }
			}
			else {
				cout << "\n------You have entered an invalid input...!--------\n";
				goto again;
			}
			break;
		}
		pCur = pCur->next;
		if (pCur == NULL) {
			cout << "\n--------------Sorry no data found!!!---------------------------\n\n";
		}
	}
}

template <class T>
void List<T>::exitprog(char admin)
{
	if (admin == 'y' || admin == 'Y')saveChange();
	system("CLS");
	cout << "\n---------Thank you for using this system-----------\n\n";
	deleteall();

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

// ************* Omar ************

template <class T>
void List<T>::saveChange() {
	char save;
	ofstream of;
	cout << "---------------------Exit Page---------------------------------";
	cout << "******\n\n[1] Save and Exit\n[2] Save in another file, the content of original record will not be change\n\n*Any button else to exit without saving\n\n\n: ";
	cin >> save;
	if (save == '1') {

		of.open("record2.txt");
	saving:

		pCur = head;


		if (pCur == NULL) {
			of.close();
			remove("record2.txt");
		}
		else {

			while (pCur) {
				of << endl << pCur->model + ":";
				of << " " << pCur->id;
				for (int i = 0; i < 3; i++) {
					of << " " << pCur->price[i];
				}

				pCur = pCur->next;
			}
			of.close();

		}
		cout << "\n\n------------Data is stored-------------------\n\n";
		system("pause");
	}

	else if (save == '2') {
		string save_new_file;
		cout << "\n\nPlease enter the model that you want to save inside \n: ";
		cin.ignore();
		getline(cin, save_new_file);
		save_new_file += ".txt";
		of.open(save_new_file);
		goto saving;
	}

}

template <class T>
void List<T>::refresh() {
	deleteall();
	getData();
	cout << "\n\n-----------------Refresh is completed-----------------\n\n";
	finish();
}
template <class T>
void List<T>::finish() {
	cout << endl;
	system("pause");
	system("CLS");
}
template class List<int>;

template class List<double>;

//motor.h
//**********THIASAN,RAZIN,AIMI,OMAR***********
#ifndef MOTOR_H 
#define MOTOR_H

template <class T>
class List {
private:
	struct ListNode
	{
		int id;
		std::string model;
		T price[5]; ;

		ListNode* next;
	};

	ListNode* head, * pCur, * pCur2;
	int numItem;
	std::string priceof[3] = { "Original ","Service Tax","SST" };


public:
	List();
	void getData();  		// * read data from the record.txt
	void append();		// * add new data
	int del();
	void deleteid();
	void deletename();		// *name-based and id-based to delete certain data
	void deleteall();
	void list();
	void search(char);
	void sorting();
	void updata();
	void saveChange();		// *for admin only, can save changein either original txt or new txt
	void exitprog(char);		// *exit the current page to the admin_determined page and clear the stored data 
	void finish();		// *combination of the function of "Please enter any key to continue" & clear the screen
	void refresh();		// *Assume that in reality, two users are open at same time, and one of them make change of the data and save, so that another user can get the newest updating data by refresh the data without exit the page

};
#endif


