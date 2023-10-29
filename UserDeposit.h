#ifndef USER_DEPOSIT_H_
#define USER_DEPOSIT_H_

#include<string>
using namespace std;

class UserDeposit {
public:

	
	UserDeposit();
	UserDeposit(double investmentAmount, double monthlyDeposit, int annualInterest, int YEARS);


	void SetInvestment(double investmentAmount);
	double GetInvestment() const;
	void SetMonthlyDeposit(double monthlyDeposit);
	double GetMonthlyDeposit() const;
	void SetAnnualInterest(int annualInterest);
	int GetAnnualInterest() const;
	void SetYears(int YEARS);
	int GetYears() const;

private:
	double m_investment;
	double m_deposit;
	int m_interest;
	int m_years;
};


#endif 
