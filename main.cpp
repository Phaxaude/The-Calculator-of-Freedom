//Jacob Lawrence Walker

#include<iostream>
#include "InvestmentData.h"
#include<string>
using namespace std;
string key = "y";


int main() {
	while (key != "n")											//Loop for repreated input
	{
		InvestmentData investmentInfo;							//creates object
		investmentInfo.printInputHeader();
		investmentInfo.userInputRequest();
		investmentInfo.printWithoutMonthlyDepositHeader();
		investmentInfo.withoutMonthlyDeposits();
		investmentInfo.printWithMonthlyDepositHeader();
		investmentInfo.withMonthlyDeposits();
		do {													//checks user input
			cout << "Again? y/n" << endl;
			cin >> key;
			if (key != "n" and key != "y") {
				cout << "That was an invalid response, please try again..." << endl;
			}
		} while (key != "n" and key != "y");
	}
	cout << "Exiting program..." << endl;
}