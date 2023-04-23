//Jacob Lawrence Walker

#ifndef PROJECT4_INVESTMENTDATA_H
#define PROJECT4_INVESTMENTDATA_H

#include <vector>
#include<string>
using namespace std;

class InvestmentData
{
public:
	InvestmentData();
	void PrintData();
	void userInputRequest();
	void userInput(int varSet);
	void printInputHeader();
	void printWithMonthlyDepositHeader();
	void printWithoutMonthlyDepositHeader();
	void withoutMonthlyDeposits();
	void withMonthlyDeposits();
	double getInvestmentAmount();
	double getMonthlyDeposit();
	double getAnnualInterest();
	double getNumberOfYears();
	double getYear();
	double getYearEndBalance();
	double getYearEndEarnedInterest();
private:
	vector<double> detailList;		//used for storing information entered by user
	vector<double> moreInfo;		//for storing calculated information from user information
	double input;
	double openingBalance;
	double depositAmount;
	double interestRate;
	double closingBalance;
	double interest;
	void outputVariableDef(int questionNo);
	void setInvestmentAmount(double investmentAmount);
	void setMonthlyDeposit(double monthlyDeposit);
	void setAnnualInterest(double annualInterest);
	void setNumberOfYears(double numberOfYears);
	void setYear(double year);
	void setYearEndBalance(double yearEndBalance);
	void setYearEndEarnedInterest(double yearEndEarnedInterest);
};

#endif //PROJECT4_INVESTMENTDATA