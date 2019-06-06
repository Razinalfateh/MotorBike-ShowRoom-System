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
