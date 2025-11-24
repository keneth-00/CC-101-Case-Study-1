#include <iostream>
#include <cstdlib>

using namespace std;
 
double computeSalary(double hours, double hourlyRate, double otPay, double grossPay)
 {
 	grossPay = (hours * hourlyRate) + otPay;
 	
 	return grossPay;
 }
 
void displaySummary(string id, string name, double hours, double hourlyRate, double grossPay, double otPay, double sssContri, double pagibigContri, double philHealth, double cashAdvance, double sssLoan, double pagibigLoan, double others, double totalDeduction, double netPay)
 {
 	cout<<endl<<"====SALARY PAYSLIP===="<<endl<<endl;
 	cout<<"Employee ID Number: "<<id<<endl;
 	cout<<"Employee Name: "<<name<<endl<<endl;
 	cout<<"Hours Worked: "<<hours<<endl;
 	cout<<"Hourly Rate: "<<hourlyRate<<endl<<endl;
 	cout<<"Gross Pay: "<<grossPay<<endl;
 	cout<<"Overtime Pay: "<<otPay<<endl<<endl;
 	
 	cout<<"DEDUCTIONS"<<endl;
 	cout<<endl<<"SSS Contribution: "<<sssContri<<endl;
 	cout<<"Pag-Ibig Contribution: "<<pagibigContri<<endl;
 	cout<<"PhilHealth: "<<philHealth<<endl;
 	cout<<"Cash Advance: "<<cashAdvance<<endl;
 	cout<<"SSS Loan: "<<sssLoan<<endl;
 	cout<<"Pag-Ibig MPL: "<<pagibigLoan<<endl;
 	cout<<"Others:  "<<others<<endl<<endl;
 	
 	cout<<"Total Deductions: "<<totalDeduction<<endl<<endl;
 	
 	cout<<"Net Pay: "<<netPay<<endl<<endl;
 	cout<<"======================"<<endl<<endl;
 }
 	
int main()
{
	int n;
	
	cout<<"SALARY PAYSLIP"<<endl<<endl;
	cout<<"Enter number of employees to process: ";
	cin>>n;
	
	for (int l = 0; l < n; l++)
	{
		string id, name;
		double hours, hourlyRate, grossPay, otHours, otRate, otPay, netPay;
		double cashAdvance, sssContri, pagibigContri, philHealth, sssLoan, pagibigLoan, others, totalDeduction;
		
		cout<<"ENTER EMPLOYEE "<<l + 1<<" DETAILS: "<<endl<<endl;
		cout<<"ID Number: ";
		cin>>id;
		cout<<"Employee Name: ";
		cin.ignore();
		getline(cin, name);
		
		cout<<endl<<"Enter hours worked: ";
		cin>>hours;
		cout<<"Enter hourly rate: ";
		cin>>hourlyRate;
		
		if (hours > 160)
 	{
 		otHours = hours - 160;
 		otRate = hourlyRate * 1.25;
 		otPay = otHours * otRate;
 	}
 		else 
 		{
 			otPay = 0;
 		}		
 
		grossPay = computeSalary(hours, hourlyRate, otPay, grossPay);
			
		cout<<endl<<"Employee Loans (0 if none)"<<endl;
		cout<<"SSS Contribution: ";
		cin>>sssContri;
		cout<<"Pag-Ibig Contribution: ";
		cin>>pagibigContri;
		cout<<"PhilHealth: ";
		cin>>philHealth;
		cout<<"Cash Advance: ";
		cin>>cashAdvance;
		cout<<"SSS Loan: ";
		cin>>sssLoan;
		cout<<"Pag-Ibig MPL: ";
		cin>>pagibigLoan;
		cout<<"Others: ";
		cin>>others;

		totalDeduction = sssContri + pagibigContri + philHealth + cashAdvance + sssLoan + pagibigLoan + others;
		
		netPay = grossPay - totalDeduction;
		
		displaySummary(id, name, hours, hourlyRate, grossPay, otPay, sssContri, pagibigContri, philHealth, cashAdvance, sssLoan, pagibigLoan, others, totalDeduction, netPay);

	}
			
	return EXIT_SUCCESS;
}