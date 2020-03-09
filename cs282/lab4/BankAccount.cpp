#include "BankAccount.h"
using namespace std; 


BankAccount::BankAccount(int accountNumber, double IBalance) 
:accountNum(accountNum), balance(IBalance){

}

double BankAccount::GetInterestRate() const{
	//double& balance = BankAccount::GetBalance;
	if ( balance > 100000) {
		return 0.005;
	}
	else if (balance >= 10000 && balance <= 100000) {
		return 0.003;
	}
	else {
		return 0.001;
	}
}

double BankAccount::ApplyInterest() {
	return balance + balance * GetInterestRate();
}
bool BankAccount::operator< (BankAccount rhs) const {
	return balance < rhs.balance;
}