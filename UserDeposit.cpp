#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "UserDeposit.h"

UserDeposit::UserDeposit() {
	m_investment = 0;
	m_deposit = 0;
	m_interest = 0;
	m_years = 0;
}

UserDeposit::UserDeposit(double investmentAmount, double monthlyDeposit, int annualInterest, int YEARS){
	m_investment = investmentAmount;
	m_deposit = monthlyDeposit;
	m_interest = annualInterest;
	m_years = YEARS;
}

//Setters
void UserDeposit::SetInvestment(double investmentAmount) {
	m_investment = investmentAmount;
}
void UserDeposit::SetMonthlyDeposit(double monthlyDeposit) {
	m_deposit = monthlyDeposit;
}
void UserDeposit::SetAnnualInterest(int annualInterest) {
	m_interest = annualInterest;
}
void UserDeposit::SetYears(int YEARS) {
	m_years = YEARS;
}

//Getters
double UserDeposit::GetInvestment() const {
	return m_investment;
}
double UserDeposit::GetMonthlyDeposit() const{
	return m_deposit;
}
int UserDeposit::GetAnnualInterest() const{
	return m_interest;
}
int UserDeposit::GetYears() const {
	return m_years;
}
