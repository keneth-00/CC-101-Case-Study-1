#include <iostream>
#include <cstdlib>

using namespace std;
 
double computeSalary(double hoursWorked, double hourlyPay, double overTime, double bonus)
{
    double regularHours;
    double grossPay;
    
    if (hoursWorked > 160)
    {
    	regularHours = 160;
    }
    	else
    	{
    		regularHours = hoursWorked;
    	}
    	
    grossPay = (regularHours * hourlyPay) + overTime + bonus;
    
    return grossPay;
}
 
void displaySummary(string idNum, string eName, double hoursWorked, double hourlyPay, double grossPay, double overTime, double bonus, double cashLoan, double sss, double sssL, double pagibig, double pagibigL, double philH, double otherDeduct, double totalDeduct, double netSalary)
 {
 	cout<<endl<<endl<<"========SALARY PAYSLIP========"<<endl<<endl;
 	cout<<"Employee ID Number: "<<idNum<<endl;
 	cout<<"Employee Name: "<<eName<<endl<<endl;
 	cout<<"Hours Worked: "<<hoursWorked<<endl;
 	cout<<"Hourly Rate: "<<hourlyPay<<endl<<endl;
 	cout<<"Gross Salary: "<<grossPay<<endl;
 	cout<<endl<<"ADDITIONAL (already added in Gross Salary)"<<endl;
 	cout<<"Overtime Pay: "<<overTime<<endl;
 	cout<<"Bonus: "<<bonus<<endl<<endl;
 	
 	cout<<"DEDUCTIONS"<<endl;
 	cout<<"Cash Advance: "<<cashLoan<<endl;
 	cout<<"SSS Contribution: "<<sss<<endl;
 	cout<<"SSS Loan: "<<sssL<<endl;
 	cout<<"Pag-Ibig Contribution: "<<pagibig<<endl;
 	cout<<"Pag-Ibig MPL: "<<pagibigL<<endl;
 	cout<<"PhilHealth: "<<philH<<endl;
 	cout<<"Others:  "<<otherDeduct<<endl<<endl;
 	
 	cout<<"Total Deductions: "<<totalDeduct<<endl<<endl;
 	
 	cout<<"Net Pay: "<<netSalary<<endl<<endl;
 	cout<<"=============================="<<endl<<endl;
 }
 	
int main()
{
	int n, category;
	string id, name;
		double hours, hourlyRate, grossSalary, otPay, bonusPay, netPay;
		double cashAdvance, sssContri, pagibigContri, philHealth, sssLoan, pagibigLoan, others, totalDeduction;
	
	cout<<"SALARY PAYSLIP"<<endl<<endl;
	cout<<"Enter number of employees to process: ";
	cin>>n;
	
	for (int l = 0; l < n; l++)
	{
		cout<<endl<<"ENTER EMPLOYEE "<<l + 1<<" DETAILS: "<<endl;
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
 		otPay = (hours - 160) * (hourlyRate * 1.25);
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
 
		grossSalary = computeSalary(hours, hourlyRate, otPay, bonusPay);
			
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
		
		netPay = grossSalary - totalDeduction;
		
		displaySummary(id, name, hours, hourlyRate, grossSalary, otPay, bonusPay, cashAdvance, sssContri, sssLoan, pagibigContri, pagibigLoan, philHealth, others, totalDeduction, netPay);

	}
			
	return EXIT_SUCCESS;
}