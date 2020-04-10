#include <iostream>
#include <string>
using namespace std;
#define max 1000

/*
address book
*/


void show_menu();                            // function to show the basic menu
void addperson(struct addressbook* ab);      // function to add person to address book
void show_person(struct addressbook* ab);      // function to all the existed persons
int search_person(string * search_name, struct addressbook * ab);      // function to search person
void delete_person(int person_order, struct addressbook* ab);                           // delete person
void show_one_person(int person_order,struct addressbook* ab);                          // show one person
void modify_person(int person_order, struct addressbook* ab);                          // modify one person
void clear_addressbook(struct addressbook* ab);                                        // clear all persons

struct person {
	string m_name;
	int m_gender = 0;                       // 1-> male; 2-> female
	int m_age = 0;
	string m_phone;
	string m_address;
};


struct addressbook {
	struct person person_array[max];
	int m_size=0;
};

void show_menu()                        // function to show the basic menu
{   
	cout << "PLEASE ENTER YOUR COMMAND:" << endl;
	cout << "\n";

	cout << "************************************" << endl;
	cout << "*****  1 --> add person        *****" << endl;
	cout << "*****  2 --> show person       *****" << endl;
	cout << "*****  3 --> delete person     *****" << endl;
	cout << "*****  4 --> find person       *****" << endl;
	cout << "*****  5 --> modify person     *****" << endl;
	cout << "*****  6 --> clear all person  *****" << endl;
	cout << "*****  0 --> exit system       *****" << endl;
	cout << "************************************" << endl;
}

void addperson(struct addressbook *ab)                       // function to add person to address book
{
	if (ab->m_size == max)
	{
		cout << "The address book is full" << endl;
	}else{
		string name;
		int gender = 0;;
		int age = 0;;
		string phone;
		string address;

		cout << "please enter the person's name: " << endl;                 //add name
		cin >> name;
		ab->person_array[ab->m_size].m_name= name;

		cout << "please choose the person's gender:"<<endl;                 // add gender
		cout << "1 -> male" << endl;
		cout << "2 -> female" << endl;

		while (true)
		{
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				ab->person_array[ab->m_size].m_gender = gender;
				break;
			}
			else {
				cout << "please enter the correct gender: " << endl;
			}
		}

		cout << "please choose the person's age:" << endl;                  //add age
		while (true)
		{
			cin >> age;
			if ((age > 0) & (age < 150))
			{
				ab->person_array[ab->m_size].m_age = age;
				break;
			}
			else {
				cout << "please enter the correct age: " << endl;
			}
		}

		cout << "please choose the person's phone:" << endl;                  //add phone
		cin >> phone;
		ab->person_array[ab->m_size].m_phone = phone;

		cout << "please choose the person's address:" << endl;                  //add address
		cin >> address;
		ab->person_array[ab->m_size].m_address = address;

		ab->m_size++;
		cout << endl;
		cout << "Congratulations! The adding process is finished." << endl;                 // finish one person input

		cout << endl;
		system("pause");
		system("cls");                          // clear the screen
	}
}

void show_person(struct addressbook* ab)
{
	if (ab->m_size > 0)
	{
		for (int i = 1; i <= ab->m_size; i++)
		{
			cout << "Person No. " << i << ":" << endl;                                     // show person's order
			cout << "\tName: " << ab->person_array[i - 1].m_name << "\t";                  // show name

			if (ab->person_array[i - 1].m_gender == 1)
			{
				cout << "\tGender: " << "Male" << "\t";
			}
			else {
				cout << "\tGender: " << "Female" << "\t";
			}

			cout << "\tAge: " << ab->person_array[i - 1].m_age << "\t";                 // show age
			cout << "\tPhone: " << ab->person_array[i - 1].m_phone << "\t";             // show phone
			cout << "\tAddress: " << ab->person_array[i - 1].m_address << endl;             // show address
	   }
		cout << endl;
		system("pause");
		system("cls");                                                                   // clear screen
	}
	else {
		cout << "There is no person in the address book" << endl;
		cout << endl;
		system("pause");
		system("cls");                                                                  //clear screen
	}
}

int search_person(string* search_name, struct addressbook * ab)
{
	for (int i = 0; i < (ab->m_size); i++)
	{
		if (ab->person_array[i].m_name == *search_name)
		{
			return i;                                                                 // return the person's order 
		}

	}
	cout << "There is no such person, please check the name again." << endl;

	cout << endl;
	system("pause");
	system("cls");                                         // clear screen
	return -1;                                             // return -1 to indicate there is no such person

}

void delete_person(int person_order, struct addressbook* ab)
{
	for (int i = person_order; i < (ab->m_size); i++)
	{
		ab->person_array[i] = ab->person_array[i + 1];        // delete data
	}
	ab->m_size--;                                             // array size = array size -1
	cout << "Delete successfully!" << endl;

	cout << endl;
	system("pause");
	system("cls");                         // clear screen
}

void show_one_person(int person_order,struct addressbook *ab)
{
	cout << "Person No. " << person_order << ":" << endl;                                     // show person's order
	cout << "\tName: " << ab->person_array[person_order].m_name << "\t";                  // show name

	if (ab->person_array[person_order].m_gender == 1)
	{
		cout << "\tGender: " << "Male" << "\t";
	}
	else {
		cout << "\tGender: " << "Female" << "\t";
	}

	cout << "\tAge: " << ab->person_array[person_order].m_age << "\t";                 // show age
	cout << "\tPhone: " << ab->person_array[person_order].m_phone << "\t";             // show phone
	cout << "\tAddress: " << ab->person_array[person_order].m_address << endl;             // show address

	cout << endl;
	system("pause");
	system("cls");                         // clear screen
}

void modify_person(int person_order, struct addressbook* ab)
{
	string name;
	int gender = 0;;
	int age = 0;;
	string phone;
	string address;

	cout << endl;
	cout << "please enter the person's new name: " << endl;                 //add name
	cin >> name;
	ab->person_array[person_order].m_name = name;

	cout << "please choose the person's new gender:" << endl;                 // add gender
	cout << "1 -> male" << endl;
	cout << "2 -> female" << endl;

	while (true)
	{
		cin >> gender;
		if (gender == 1 || gender == 2)
		{
			ab->person_array[person_order].m_gender = gender;
			break;
		}
		else {
			cout << "please enter the correct gender: " << endl;
		}
	}

	cout << "please choose the person's new age:" << endl;                  //add age
	while (true)
	{
		cin >> age;
		if ((age > 0) & (age < 150))
		{
			ab->person_array[person_order].m_age = age;
			break;
		}
		else {
			cout << "please enter the correct age: " << endl;
		}
	}

	cout << "please choose the person's new phone:" << endl;                  //add phone
	cin >> phone;
	ab->person_array[person_order].m_phone = phone;

	cout << "please choose the person's new address:" << endl;                  //add address
	cin >> address;
	ab->person_array[person_order].m_address = address;

	cout << endl;
	cout << "Congratulations! The modification process is finished." << endl;                 // finish one person input

	cout << endl;
	system("pause");
	system("cls");                         // clear screen
}

void clear_addressbook(struct addressbook* ab)
{
	ab->m_size = 0;                                             // make the array size to 0, thus we achieve the clear function
	cout << endl;
	cout << "Congratulations! The clear process is finished." << endl;                 // finish clear

	cout << endl;
	system("pause");
	system("cls");                         // clear screen
}


int main() {
	int select;
	string search_name;
	int search_result = 0;
	struct addressbook ab;
	ab.m_size = 0;

	while (true)                                     // use a fake permanent loop to run the main system again and again (when exit 0, exit)
	{
		show_menu();
		cin >> select;

		switch (select)
		{
		case 1:                                      // add person
			addperson(&ab);
			break;
		case 2:                                      // show person
			show_person(&ab);
			break;
		case 3:                                                       // delete person
			cout<<"please enter the person's name: "<< endl;
			cin >> search_name;
			search_result=search_person(&search_name,&ab);           // search firstly
			if (search_result != -1)
			{
				delete_person(search_result,&ab);
			}
			break;
		case 4:                                                       // find person
			cout << "please enter the person's name: " << endl;
			cin >> search_name;
			search_result = search_person(&search_name, &ab);         // search firstly
			if (search_result != -1)
			{
				show_one_person(search_result,&ab);                  // show the specific person
			}
			break;
		case 5:                                                       // modify person
			cout << "please enter the person's name: " << endl;
			cin >> search_name;
			search_result = search_person(&search_name, &ab);         // search firstly
			if (search_result != -1)
			{
				modify_person(search_result, &ab);                  // modify the specific person
			}
			break;
		case 6:                                                      // clear addressbook
			clear_addressbook(&ab);
			break;
		case 0:                                     // exit
			cout << "Goodbye!" << endl;
			system("pause");
			return 0;
			break;
		default:                                   // others
			cout << "Please enter the correct command" << endl;
			break;
		}

	}
	return 0;
}