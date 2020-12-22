#pragma once
#include<string>
#include<iostream>
#include<vector>
#include"Record.h"

using namespace std;

class BankDatabase {
private:
	int numberofAccounts;
	vector<Record*> database;

public:
	BankDatabase();
	BankDatabase(const BankDatabase& b);
	~BankDatabase();
	friend std::ostream& operator<<(std::ostream& out, const BankDatabase& toOut); // stream operator overload
	BankDatabase& operator =(const BankDatabase& b); // assignment operator overload
	int getNumberOfAccounts();
	void addAccount(Record* c);
	void deleteAccount(int);
	Record* getAccount(int);
	void sortDatabase();
	void divide(int,int);
	void merger(int, int, int);
	void readData();
	void createAccount();

};
