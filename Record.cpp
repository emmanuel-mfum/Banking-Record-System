#include"Record.h";
#include<iostream>;
#include<string>;

using namespace std;

Record::Record() {
	accountNumber = 0;
	firstName = "";
	lastName = "";
	balance = 0;
	password = 0;

}

Record::Record(int number, string fName, string lName, int b, int p) {

	accountNumber = number;
	firstName = fName;
	lastName = lName;
	balance = b;
	password = p;
}

Record::Record(const Record& r) {
	accountNumber = r.accountNumber;
	firstName = r.firstName;
	lastName = r.lastName;
	balance = r.balance;
	password = r.password;

}

Record::~Record() {}

Record& Record :: operator =(const Record& r) // assignment operator overload
{
	this->accountNumber = r.accountNumber;
	this->firstName = r.firstName;
	this->lastName = r.lastName;
	this->balance = r.balance;
	this->password = r.password;


	return *this;
}


int Record::getAccountNumber() {
	return this->accountNumber;
}

string Record::getFirstName() {
	return this->firstName;
}

string Record::getLastName() {
	return this->lastName;
}

int Record::getBalance() {
	return this->balance;
}

void Record::setAccountNumber(int number) {
	this->accountNumber = number;
}

void Record::setFirstName(string fName) {
	this->firstName = fName;
}

void Record::setLastName(string lName) {
	this->lastName = lName;
}

void Record::setBalance(int b) {
	this->balance = b;
}

void Record::setPassword(int p)
{
	this->password = p;
}

void Record::readRecord() {

	cout << "The number of the account is :" << this->getAccountNumber() << endl;
	cout << "The first name of the customer is :" << this->getFirstName() << endl;
	cout << "The last name of the customer is :" << this->getLastName() << endl;
	cout << "The current balance inside this account is :" << this->getBalance() << endl;

	cout << endl;
	cout << endl;


}
