#include <iostream>
#include <cstdlib>

using namespace std;
 
double computeSalary(double hours, double hourlyRate, double otPay, double bonusPay, double grossPay)
{
    double regularHours;
    
    if (hours > 160)
    {
    	regularHours = 160;
    }
    	else
    	{
    		regularHours = hours;
    	}
    	
    grossPay = (regularHours * hourlyRate) + otPay + bonusPay;
    
    return grossPay;
}
 
void displaySummary(string id, string name, double hours, double hourlyRate, double grossPay, double otPay, double bonusPay, double cashAdvance, double sssContri, double sssLoan, double pagibigContri, double pagibigLoan, double philHealth, double others, double totalDeduction, double netPay)
 {
 	cout<<endl<<"======SALARY PAYSLIP======"<<endl<<endl;
 	cout<<"Employee ID Number: "<<id<<endl;
 	cout<<"Employee Name: "<<name<<endl<<endl;
 	cout<<"Hours Worked: "<<hours<<endl;
 	cout<<"Hourly Rate: "<<hourlyRate<<endl<<endl;
 	cout<<"Gross Pay: "<<grossPay<<endl;
 	cout<<"Overtime Pay: "<<otPay<<endl;
 	cout<<"Bonus: "<<bonusPay<<endl<<endl;
 	
 	cout<<"DEDUCTIONS"<<endl;
 	cout<<endl<<"Cash Advance: "<<cashAdvance<<endl;
 	cout<<"SSS Contribution: "<<sssContri<<endl;
 	cout<<"SSS Loan: "<<sssLoan<<endl;
 	cout<<"Pag-Ibig Contribution: "<<pagibigContri<<endl;
 	cout<<"Pag-Ibig MPL: "<<pagibigLoan<<endl;
 	cout<<"PhilHealth: "<<philHealth<<endl;
 	cout<<"Others:  "<<others<<endl<<endl;
 	
 	cout<<"Total Deductions: "<<totalDeduction<<endl<<endl;
 	
 	cout<<"Net Pay: "<<netPay<<endl<<endl;
 	cout<<"=========================="<<endl<<endl;
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
		double hours, hourlyRate, grossPay, otHours, otRate, otPay, bonusPay, netPay;
		double cashAdvance, sssContri, pagibigContri, philHealth, sssLoan, pagibigLoan, others, totalDeduction;
		int category;
		
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
 		
 		cout<<endl<<"Select a bonus category (1 - Standard, 2 - Premium, 3 - None): ";
 		cin>>category;
 		
 		switch (category)	
 		{
	 		case 1:
 				bonusPay = 500;
 				break;
 			case 2:
 				bonusPay = 1000;
 				break;
 			case 3:
 				bonusPay = 0;
 				break;
 			default:
 				cout<<"Invalid category. No bonus applied.";
 				bonusPay = 0;
 				break;
 		}
 
		grossPay = computeSalary(hours, hourlyRate, otPay, bonusPay, grossPay);
			
		cout<<endl<<"———Enter Deductions (0 if none)———"<<endl;
		cout<<"Cash Advance: ";
		cin>>cashAdvance;
		cout<<"SSS Contribution: ";
		cin>>sssContri;
		cout<<"SSS Loan: ";
		cin>>sssLoan;
		cout<<"Pag-Ibig Contribution: ";
		cin>>pagibigContri;
		cout<<"Pag-Ibig MPL: ";
		cin>>pagibigLoan;
		cout<<"PhilHealth: ";
		cin>>philHealth;
		cout<<"Others: ";
		cin>>others;

		totalDeduction = cashAdvance + sssContri + sssLoan + pagibigContri + pagibigLoan + philHealth + others;
		
		netPay = grossPay - totalDeduction;
		
		displaySummary(id, name, hours, hourlyRate, grossPay, otPay, bonusPay, cashAdvance, sssContri, sssLoan, pagibigContri, pagibigLoan, philHealth, others, totalDeduction, netPay);

	}
			
	return EXIT_SUCCESS;
}