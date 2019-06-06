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
	system("color 09");
	// here has 2 exit type, first is exit selecting page(admin only) but not close the program, second is close program
	char select = '6'; 		// In the switch below, 6 means non-admin can only search result in student-mode
	char admin;
	string name;
	List<int> x;
start:
	x.getData();

	system("CLS");
	cout << "---------------------------------Welcome----------------------------------------";
	cout << "\n\n\n\n\n\t\t\t  Are you a admin ? \n\n\n\n\t\t\t\t Yes[y]\t\t  No[n]\n\n";
	cout << "\t\t\t\t   ";
	cin >> admin;

	if (admin == 'Y' || admin == 'y') {		// if use admin , need password, but here i ignore the password function, enter any string also can
		
		
		string userId = "admin";
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
		cout << "*";   //for printing * instead for password
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