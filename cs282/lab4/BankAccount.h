#pragma once

class BankAccount {

private: 
	int accountNum;
	double balance; 

public:
	BankAccount(int accountNumber, double& IBalance);

	inline double GetBalance() const { return balance; }

	double GetInterestRate() const;

	double ApplyInterest();

	bool operator< (BankAccount rhs) const;

};