#include"BankDatabase.h"
#include<string>
#include<iostream>
#include<vector>

BankDatabase::BankDatabase() {
	numberofAccounts = 0;
}

BankDatabase::BankDatabase(const BankDatabase& b) {
	this->numberofAccounts = b.numberofAccounts;
	this->database = b.database;
}

BankDatabase::~BankDatabase() {
	for (int i = 0; i < database.size(); i++) {
		
		if (database.at(i) != nullptr) {
			
			delete database.at(i);
			database.at(i) = nullptr;
		}
	}
}

BankDatabase& BankDatabase :: operator =(const BankDatabase& b) // assignment operator overload
{
	this->numberofAccounts = b.numberofAccounts;
	this->database = b.database;

	return *this;
}

int BankDatabase::getNumberOfAccounts() {
	return numberofAccounts;
}

void BankDatabase::addAccount(Record* r) {
	database.push_back(r);
	numberofAccounts++;
}

void BankDatabase::deleteAccount(int accountNumber) {

	int accountTobeDeleted = accountNumber;

	for (int i = 0; i < database.size(); i++) {

		Record* r = database.at(i);

		if (accountTobeDeleted == r->getAccountNumber()) {
			delete r;
			r = nullptr;
			database.erase(database.begin() + (i)-1);
		}
		else {
			delete r;
			r = nullptr;
		}
	
	
	}

	numberofAccounts--;
}

Record* BankDatabase::getAccount(int number) {
	
	int accountTobeSelected = number;

	for (int i = 0; i < database.size(); i++) {

		Record* r = database.at(i);

		if (accountTobeSelected == r->getAccountNumber()) {
			return r;
		}
		else {
			delete r;
			r = nullptr;
			return nullptr;
		}


	}
}

void BankDatabase::sortDatabase() {
	this->divide(0, this->database.size() - 1);
}

void BankDatabase::divide(int startIndex, int endIndex) {
	// Divide until you break down the vector to a single element
	if (startIndex < endIndex && (endIndex - startIndex) >= 1) {
		
		int mid = (endIndex - startIndex) / 2;
		this->divide(startIndex, mid);
		this->divide(mid, endIndex);

		// merge the vector into one vector
		this->merger(startIndex, mid, endIndex);
	}
}

void BankDatabase::merger(int startIndex, int midIndex, int endIndex) {

	vector<Record*> merged; // creating a new vector

	//Merging the vector

	int leftIndex = startIndex;
	int rightIndex = midIndex +1;

	while (leftIndex < midIndex && rightIndex <= endIndex) {

		if (this->database.at(leftIndex)->getAccountNumber() < this->database.at(rightIndex)->getAccountNumber()) {
			merged.push_back(this->database.at(leftIndex));
			leftIndex++;
		}
		else {
			merged.push_back(this->database.at(rightIndex));
			rightIndex++;
		}
	}

	// One of the two while loop will be executed
	while (leftIndex <= midIndex) {

		merged.push_back(this->database.at(leftIndex));
		leftIndex++;
	}

	while (rightIndex <= endIndex) {

		merged.push_back(this->database.at(rightIndex));
		rightIndex++;

	}

	int i = 0;
	int j = startIndex;

	// Inserting all the elements into the original vector 
	while (i < merged.size()) {
		database.push_back(merged.at(i++));
		j++;
	}
}

void BankDatabase::readData() {
	cout << "Here is some information about this database" << endl;
	cout << " The number of accounts presently inside is " << this->getNumberOfAccounts() << endl;

	if (database.size() == 0) {
		cout << "There are no accounts in this database" << endl;
	}
	else {
		for (int i = 0; i < database.size(); i++) {
			cout << "The number of the account is :" << database.at(i)->getAccountNumber() << endl;
			cout << "The first name of the customer is :" << database.at(i)->getFirstName() << endl;
			cout << "The last name of the customer is :" << database.at(i)->getLastName() << endl;
			cout << "The current balance inside this account is :" << database.at(i)->getBalance() << endl;

			cout << endl;
			cout << endl;

		}
	}
}

void BankDatabase::createAccount() {
	cout << "You are now creating a new Account !" << endl;
	cout << endl;

	Record* account = new Record();
	cout << "Enter the account number " << endl;
	int number;
	cin >> number;

	cout << "Setting the account number..." << endl;
	account->setAccountNumber(number);

	cout << "Enter the first name of the account's owner " << endl;
	string fName;
	cin >> fName;

	cout << "Setting the first name of the account's owner..." << endl;
	account->setFirstName(fName);

	cout << "Enter the last name of the account's owner " << endl;
	string lName;
	cin >> lName;

	cout << "Setting the last name of the account's owner..." << endl;
	account->setLastName(lName);

	cout << "The balance of this new account is zero, you can set it now..." << endl;
	int balance;
	cin >> balance;

	cout << "Setting the balance of this new account..." << endl;
	account->setBalance(balance);

	cout << "There is no password for this account, set one now" << endl;
	int password;
	cin >> password;

	cout << "Setting the password of this account..." << endl;
	account->setPassword(password);

	this->addAccount(account); // adds account to database

	cout << "Account creation completed !" << endl;



}