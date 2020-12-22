#include"Record.h"
#include"BankDatabase.h"
#include<string>
#include<iostream>
#include<vector>

using namespace std;


bool start() {
	cout << "=========================================================================================\n\n\n" << endl;
	cout << "****                         WELCOME TO THE BANK RECORD SYSTEM!                            ****\n\n\n" << endl;
	cout << "=========================================================================================\n\n\n" << endl;

	int choice; 

	cout << "Do you want to enter into the system ? Press 1 to do so. To terminate the program press 0 " << endl;
	cin >> choice;

	while (choice != 1 && choice!=0) {
		cout << "Do you want to enter into the system ? Press 1 to do so " << endl;
		cin >> choice;
	}

	if (choice == 1) {
		return true;
	}

	if (choice == 0) {
		return false;
	}

}

int menu() {

	cout << "1. Read the data inside the database " << endl;
	cout << "2. Create an account " << endl;
	cout << "3. Read an account " << endl;
	cout << "4. Modify an account " << endl;
	cout << "5. Delete an account " << endl;
	cout << "6. Leave the system " << endl;
	int choice;
	cin >> choice;

	return choice;

}

void changeAccountNumber(Record* r) {

	int number;
	cout << "Here is the current account number " << r->getAccountNumber() << endl;
	cout << "Enter the new account number " << endl;


	cin >> number;

	cout << "The new account number for this account is now :" << number << endl;

	cout << "changing the account number..." << endl;

	r->setAccountNumber(number);

	cout << "Account number changed !!" << endl;

	delete r;
	r = nullptr;



}

void changeAccountFirstName(Record* r) {

	string fName;
	cout << "Here is the current account's owner first name " << r->getFirstName() << endl;
	cout << "Enter the new account's owner first name " << endl;


	cin >> fName;

	cout << "The new account's owner first name for this account is now :" << fName << endl;

	cout << "changing the account's owner first name..." << endl;

	r->setFirstName(fName);

	cout << "Account's owner first name changed !!" << endl;

	delete r;
	r = nullptr;



}


void changeAccountLastName(Record* r) {

	string lName;
	cout << "Here is the current account's owner last name " << r->getLastName() << endl;
	cout << "Enter the new account's owner last name " << endl;


	cin >> lName;

	cout << "The new account's owner last name for this account is now :" << lName << endl;

	cout << "changing the account's owner last name..." << endl;

	r->setLastName(lName);

	cout << "Account's owner last name changed !!" << endl;

	delete r;
	r = nullptr;



}


void changeAccountBalance(Record* r) {

	int  money;
	cout << "Here is the current account balance " << r->getBalance() << endl;
	cout << "Enter the new account balance " << endl;


	cin >> money;

	cout << "The new account balance for this account is now :" << money << endl;

	cout << "changing the account balance..." << endl;

	r->setBalance(money);

	cout << "Account balance changed !!" << endl;

	delete r;
	r = nullptr;



}

void deleteAccount(Record* r, BankDatabase* b , int n) {

	cout << "This account with the account number :" << r->getAccountNumber() << " will be deleted" << endl;
	cout << "Deleting account ...." << endl;

	int number = r->getAccountNumber();


	b->deleteAccount(n);
	
	cout << "Account deleted !!" << endl;
}

int main() {

	bool starting = start();

	if (starting == false) {
		exit(0);
		cout << "The program has been terminated" << endl;
	}
	else {
		bool inUse = true;

		cout << "Welcome to the Banking Record System !" << endl;
		cout << "What do you want to do ? An empty database has been created for you !" << endl;
		cout << endl;

		BankDatabase* bank = new BankDatabase();

		while(inUse){

			
			cout << "1. Read the data inside the database " << endl;
			cout << "2. Create an account " << endl;
			cout << "3. Read an account " << endl;
			cout << "4. Modify an account " << endl;
			cout << "5. Delete an account " << endl;
			cout << "6. Leave the system " << endl;

			int choice;
			cin >> choice;

			while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6) {

				choice = menu();
			}

			switch (choice)
			{
			case 1:
				bank->readData();
				break;
			case 2:
				bank->createAccount();
				break;
			case 3:
				cout << "Enter an account number please" << endl;
				int accountNumber;
				cin >> accountNumber;
				{Record* r = bank->getAccount(accountNumber);

				if (r == nullptr) {
					cout << "Sorry no account has been found under that number";
					continue;
				}
				else {
					r->readRecord();
				}

				delete r;
				r = nullptr;
				}
				break;
			case 4:
				cout << "Enter an account number please" << endl;
				int accountNumber1;
				cin >> accountNumber1;
				cout << "fetching the account ..." << endl;
				{Record* s = bank->getAccount(accountNumber1);

				if (s == nullptr) {
					cout << "Sorry this account doesn't exist" << endl;
					continue;
				}
				cout << "What do you want to do with this account ?" << endl;
				cout << "1. Change the account number " << endl;
				cout << "2. Change the owner's first name " << endl;
				cout << "3. Change the owner's last name" << endl;
				cout << "4. Modify the balance " << endl;

				int option;

				cin >> option;

				if (option == 1) {
					// change the account number

					changeAccountNumber(s);

				}

				if (option == 2) {
					// change the owner's first name

					changeAccountFirstName(s);
				}

				if (option == 3) {
					//change the owner's last name

					changeAccountLastName(s);
				}

				if (option == 4) {
					//change the balance

					changeAccountBalance(s);
				}

				
				}
				break;

			case 5:
				cout << "Enter an account number please" << endl;
				int accountNumber2;
				cin >> accountNumber2;
				cout << "fetching the account ..." << endl;
				{Record* t = bank->getAccount(accountNumber2);

				if (t == nullptr) {
					cout << "Sorry this account doesn't exist" << endl;
					continue;
				}

				cout << "The account " << t->getAccountNumber() << " will be deleted" << endl;
				cout << "Such decision is irreversible, are you sure ?" << endl;
				cout << "If yes enter 1, if no enter 0" << endl;

				int confirm;

				cin >> confirm;

				if (confirm == 1) {

					deleteAccount(t, bank, accountNumber);
				}

				if (confirm == 0) {
					cout << "Now account will be deleted" << endl;
					continue;
				}

				while (confirm != 1 && confirm != 0) {
					cout << "The account " << t->getAccountNumber() << " will be deleted" << endl;
					cout << "Such decision is irreversible, are you sure ?" << endl;
					cout << "If yes enter 1, if no enter 0" << endl;

					int confirm;

					cin >> confirm;
				}

				delete t;
				t = nullptr;
				}
				break;

			case 6:

				cout << "You will now leave the system..." << endl;
				break;


			default:
				cout << "Invalid option ,you will be leaving the system.." << endl;
				break;
			}

			cout << "Is there anything you want to do ? " << endl;
			cout << "If yes enter 1, if no enter 0" << endl;

			int more;
			cin >> more;

			if (more == 1) {
				continue;
			}

			if (more == 0) {
				break;
			}
			
			if (more != 1 && more != 0) {
				cout << "Is there anything you want to do ? " << endl;
				cout << "If yes enter 1, if no enter 0" << endl;

				int more;
				cin >> more;
			}
		
		
		
		
		
		
		
		}


		inUse = false;
		delete bank;
		bank = nullptr;

		cout << "Thank you for using the Banking Recording System " << endl;
		cout << "The program will now terminate" << endl;
		

	}


	return 0;
}