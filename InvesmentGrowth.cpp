#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <limits>
#include "UserDeposit.h"

using namespace std;

// To print '*'
void PrintHeader() {
	int n = 34;
	char c = '*';
	cout << string(n, c) << endl;
}
void PrintSubHeader() {
	int n = 10;
	char c = '*';
	cout << string(n, c);
}

// Display Menu
void DisplayMenu(double t_Input1, double t_Input2, int t_Input3, int t_Input4) {
	PrintHeader();
	PrintSubHeader();
	cout << " Data Input ";
	PrintSubHeader();
	cout << "**" << endl;

	cout << "Initial Investment Amount: $" << fixed << setprecision(2) << t_Input1 << endl;
	cout << "Monthly Deposit: $" << fixed << setprecision(2) << t_Input2 << endl;
	cout << "Annual Interest: %" << t_Input3 << endl;
	cout << "Number of years: " << t_Input4 << endl;
}

// Prompt User:investment
double UserInvestment(UserDeposit& userDeposit) {
	double investmentAmount;

	while (true) {
		if (cin >> investmentAmount && investmentAmount >= 0) {
			userDeposit.SetInvestment(investmentAmount);
			return investmentAmount;
		}
		else {
			cout << "Input a non-negative value please." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}

//Prompt User: Deposit
double UserMonthlyDeposit(UserDeposit& userDeposit) {
	double monthlyDeposit;
	while (true) {
		if (cin >> monthlyDeposit && monthlyDeposit >= 0) {
			userDeposit.SetMonthlyDeposit(monthlyDeposit);
			return monthlyDeposit;
		}
		else {
			cout << "Input a non-negative value please." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}

// Prompt User: Annual Interest
int UserAnnualInterest(UserDeposit& userDeposit) {
	int annualInterest;
	while (true) {
		if (cin >> annualInterest && annualInterest >= 0) {
			userDeposit.SetAnnualInterest(annualInterest);
			return annualInterest;
		}
		else {
			cout << "Input a non-negative value please." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}

//Prompt User: Years
int UserYears(UserDeposit& userDeposit) {
	int numYears;
	while (true) {
		if (cin >> numYears && numYears > 0) {
			userDeposit.SetYears(numYears);
			return numYears;
		}
		else {
			cout << "Input a non-negative and greater than 0 value please." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}

// Static Reports
void PrintDash() {
	int n = 66;
	char c = '=';
	cout << string(n, c) << endl;
}
void PrintSubDash() {
	int n = 66;
	char c = '-';
	cout << string(n, c) << endl;
}

// Compounded interest when there is no monthly deposit
void PrintData_1(const UserDeposit& userDeposit) {
	int i;
	double initialInvestment = userDeposit.GetInvestment();
	double annualInterestRate = (static_cast<double>(userDeposit.GetAnnualInterest())) / 100.0;
	int numYears = userDeposit.GetYears();
	double monthlyInterestRate = annualInterestRate / 12.0;

	for (i = 1; i <= numYears; ++i) {
		double totalEarnedInterest = 0.0;
		for (int month = 1; month <= 12; ++month) {
			double earnedInterest = (initialInvestment)* monthlyInterestRate;
			initialInvestment += earnedInterest;
			totalEarnedInterest += earnedInterest;
		}
		cout << setw(4) << i << setw(20) << fixed << setprecision(2) << "$" << initialInvestment << setw(20) << "$" << totalEarnedInterest << endl;
		cout << endl;
	}
}

// Compounded interest when there IS monthly deposit
void PrintData_2(const UserDeposit& userDeposit) {
	int i;
	double initialInvestment = userDeposit.GetInvestment();
	double monthlyDeposit = userDeposit.GetMonthlyDeposit();
	int numYears = userDeposit.GetYears();
	double annualInterestRate = static_cast<double>(userDeposit.GetAnnualInterest()) / 100.0;
	double monthlyInterestRate = annualInterestRate / 12.0;

	for (i = 1; i <= numYears; ++i) {
		double totalEarnedInterest = 0.0;

		for (int month = 1; month <= 12; ++month) {
			double earnedInterest = (initialInvestment + monthlyDeposit) * monthlyInterestRate;
			initialInvestment += monthlyDeposit;
			initialInvestment += earnedInterest;
			totalEarnedInterest += earnedInterest;
		}
		cout << setw(4) << i << setw(20) << fixed << setprecision(2) << "$" << initialInvestment << setw(20) << "$" << totalEarnedInterest << endl;
		cout << endl;
	}
} 

// No Monthly Deposit
void DisplayStaticReport1(const UserDeposit& userDeposit) {
	cout << "     Balance and Interest Without Additional Monthly Deposits" << endl;
	PrintDash();
	cout << "  Year         Year End Balance       Year End Earned Interest    " << endl;
	PrintSubDash();
	PrintData_1(userDeposit);
}
// Monthly Deposit
void DisplayStaticReport2(const UserDeposit& userDeposit) {
	cout << "       Balance and Interest With Additional Monthly Deposits" << endl;
	PrintDash();
	cout << "  Year         Year End Balance       Year End Earned Interest    " << endl;
	PrintSubDash();
	PrintData_2(userDeposit);
}



// MAIN()
int main() {
	UserDeposit userDeposit;
	char userInput;

	do {
	cout << "Welcome!" << " Please input amount for each category to get started." << endl;

	//Prompt User: Investment
	cout << "Investment Amount...?" << endl;
	UserInvestment(userDeposit);
	// Prompt User: Deposit
	cout << "Monthly Deposit...?" << endl;
	UserMonthlyDeposit(userDeposit);
	// Prompt User: Annual Interest
	cout << "Annual Interest...?" << endl;
	UserAnnualInterest(userDeposit);
	// Prompt User: Years
	cout << "How many years...?" << endl;
	UserYears(userDeposit);

	DisplayMenu(userDeposit.GetInvestment(), userDeposit.GetMonthlyDeposit(), userDeposit.GetAnnualInterest(), userDeposit.GetYears());

	system("pause");

	
	// Static Reports
	cout << endl << endl << endl;
	DisplayStaticReport1(userDeposit);
	PrintDash();
	DisplayStaticReport2(userDeposit);

	cout << "Would you like to input new values? (Y/N): " << endl;
	cin >> userInput;
	} while (userInput == 'Y' || userInput == 'y');

	return 0;
}
