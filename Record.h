#pragma once
#include <string>

using namespace std;

class Record {
private:
	int accountNumber;
	string firstName;
	string lastName;
	int balance;
	int password;


public:
	Record();//default constructor
	Record(int, string, string, int, int); // parameterized constructor
	Record(const Record& r); // copy constructor
	~Record(); // destructor
	friend std::ostream& operator<<(std::ostream& out, const Record& toOut); // stream operator overload
	Record& operator =(const Record& r); // assignment operator overload
	int getAccountNumber();
	string getFirstName();
	string getLastName();
	int getBalance();
	void setAccountNumber(int);
	void setFirstName(string);
	void setLastName(string);
	void setBalance(int);
	void setPassword(int);
	void readRecord();


};
