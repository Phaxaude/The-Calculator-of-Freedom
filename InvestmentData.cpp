//Jacob Lawrence Walker

#include<iostream>
#include<string>
#include<vector>
#include "InvestmentData.h"
#include<iomanip>
using namespace std;

InvestmentData::InvestmentData() {															//Default constructor
	detailList.resize(4);
	setInvestmentAmount(0);
	setMonthlyDeposit(0);
	setAnnualInterest(0);
	setNumberOfYears(0);

	moreInfo.resize(3);
	setYear(1);
	setYearEndBalance(0);
	setYearEndEarnedInterest(0);
}

void InvestmentData::printInputHeader() {													//prints the data input header
	cout << string(40, '*') << endl;
	cout << string(14, '*') << " Data Input " << string(14, '*') << endl;
}

void InvestmentData::printWithoutMonthlyDepositHeader() {									//prints header for investment information without deposits
	cout << "     Balance and Interest Without Additional Monthly Deposits     " << endl;
	cout << string(66, '=') << endl;
	cout << "  Year        Year End Balance       Year End Earned Interest     " << endl;
	cout << string(66, '-') << endl;
}

void InvestmentData::printWithMonthlyDepositHeader() {										//prints header for investment information with deposits
	cout << "      Balance and Interest With Additional Monthly Deposits       " << endl;
	cout << string(66, '=') << endl;
	cout << "  Year        Year End Balance       Year End Earned Interest     " << endl;
	cout << string(66, '-') << endl;
}

void InvestmentData::userInputRequest() {													//gets input for user investments
		for (int i = 0; i < 4; ++i) {
			outputVariableDef(i);
			cin >> input;
			while (cin.fail()) {																//while loop for checking correct input
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter a number" << endl;
				outputVariableDef(i);
				cin >> input;
			}
			userInput(i);
		}
}

void InvestmentData::userInput(int varSet) {
	switch (varSet) {
	case 0:
		setInvestmentAmount(input);
		break;
	case 1:
		setMonthlyDeposit(input);
		break;
	case 2:
		setAnnualInterest(input);
		break;
	case 3:
		setNumberOfYears(input);
		break;
	}
}

void InvestmentData::outputVariableDef(int questionNo) {
	switch (questionNo) {
	case 0:
		cout << "Initial Investment Amount: $";
		break;
	case 1:
		cout << "Monthly Deposit: $";
		break;
	case 2:
		cout << "Annual Interest: %";
		break;
	case 3:
		cout << "Number of years: ";
		break;
	}
}

void InvestmentData::PrintData() {															//testing function created for printing data
	cout << getInvestmentAmount() << endl;
	cout << getMonthlyDeposit() << endl;
	cout << getAnnualInterest() << endl;
	cout << getNumberOfYears() << endl;
	cout << string(20, '-') << endl;
	cout << getYear() << endl;
	cout << getYearEndBalance() << endl;
	cout << getYearEndEarnedInterest() << endl;
}

void InvestmentData::withoutMonthlyDeposits() {												//calculates and prints data without montly deposits
	openingBalance = getInvestmentAmount() * 1.0;
	interestRate = getAnnualInterest() / 100.00;
	setYear(1);
	for (int i = 0; i < getNumberOfYears(); ++i) {
		cout << fixed << setprecision(0) << string(3, ' ') << getYear() << " ";
		for (int j = 0; j < 12; ++j) {
			interest = (openingBalance) * (interestRate / 12.00);
			closingBalance = openingBalance + interest;
			openingBalance = closingBalance;
		}
		openingBalance = closingBalance;
		cout << fixed << setprecision(2) << string(10, ' ') << "$" << closingBalance << string(19, ' ') << "$" << (interest * 10.00) << endl << endl;
		setYear(i + 2);
	}
	cout << endl;
}

void InvestmentData::withMonthlyDeposits() {												//calculates and prints data with monthly deposits
	openingBalance = getInvestmentAmount() * 1.0;
	depositAmount = getMonthlyDeposit() * 1.0;
	interestRate = getAnnualInterest() / 100.00;
	setYear(1);
	for (int i = 0; i < getNumberOfYears(); ++i) {
		cout << fixed << setprecision(0) << string(3, ' ') << getYear() << " ";
		for (int j = 0; j < 12; ++j) {
			interest = (openingBalance + depositAmount) * (interestRate / 12.00);
			closingBalance = openingBalance + interest + depositAmount;
			openingBalance = closingBalance;
		}
		openingBalance = closingBalance;
		cout << fixed << setprecision(2) << string(10, ' ') << "$" << closingBalance << string(19, ' ') << "$" << (interest * 10.00) << endl << endl;
		setYear(i + 2);
	}
	cout << endl;
}
																							//setter and getter functions for all variables in vector
void InvestmentData::setInvestmentAmount(double investmentAmount) {
	detailList.at(0) = investmentAmount;
}
double InvestmentData::getInvestmentAmount() {
	return detailList.at(0);
}

void InvestmentData::setMonthlyDeposit(double monthlyDeposit) {
	detailList.at(1) = monthlyDeposit;
}
double InvestmentData::getMonthlyDeposit() {
	return detailList.at(1);
}

void InvestmentData::setAnnualInterest(double annualInterest) {
	detailList.at(2) = annualInterest;
}
double InvestmentData::getAnnualInterest() {
	return detailList.at(2);
}

void InvestmentData::setNumberOfYears(double numberOfYears) {
	detailList.at(3) = numberOfYears;
}
double InvestmentData::getNumberOfYears() {
	return detailList.at(3);
}

void InvestmentData::setYear(double year) {
	moreInfo.at(0) = year;
}
double InvestmentData::getYear() {
	return moreInfo.at(0);
}

void InvestmentData::setYearEndBalance(double yearEndBalance) {
	moreInfo.at(1) = yearEndBalance;
}
double InvestmentData::getYearEndBalance() {
	return moreInfo.at(1);
}

void InvestmentData::setYearEndEarnedInterest(double yearEndEarnedInterest) {
	moreInfo.at(2) = yearEndEarnedInterest;
}
double InvestmentData::getYearEndEarnedInterest() {
	return moreInfo.at(2);
}