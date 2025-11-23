#include <iostream>
#include <cstdlib>

using namespace std;

void TITLE()
{
	cout<<"SALARY PAYSLIP"<<endl<<endl;
}

int tax(long x)
{
	int y;
	
	if (x > 20900)
	{
		y = x * 0.0125;
		
		cout<<"You have a 15% tax rate."<<endl<<endl;
			
		return y;
	}
		else if (x > 33400)
		{
			y = x * 0.0166;
			
			cout<<"You have a 20% tax rate."<<endl<<endl;
			
			return y;
		}
			else if (x > 66700)
			{
				y = x * 0.020;
				
				cout<<"You have a 25% tax rate."<<endl<<endl;
				
				return y;
			}
				else if (x > 166700)
				{
					y = x * 0.025;
					
					cout<<"You have a 30% tax rate."<<endl<<endl;
				
					return y;
				}
					else if (x > 666700)
					{
						y = x * 0.029;
						
						cout<<"You have a 35% tax rate."<<endl<<endl;
				
						return y;
					}
						else
						{
							cout<<"You have a 0% tax rate."<<endl<<endl;
							
							return 0;
						}
}

int addTaxes(int a, int b, int c, int d)
{
	int sum = a + b + c + d;
	
	return sum;
}

int main()
{
	string name;
	int pay;
	int hours;
	int grossSalary;
	int totalSalary;
	double otPay;
	int otHours;
	double sss;
	double pagibig;
	double philhealth;
	int taxRate;
	int totalDeduction;
	int netPay;
	char answer = 'Y';

	TITLE();
	
	while (answer == 'Y' || answer == 'y')
	{
		cout<<"Enter your name: ";
		getline(cin, name);
		cout<<"Enter your pay per hour: ";
		cin>>pay;
		cout<<"Enter your hours worked: ";
		cin>>hours;
		
		grossSalary = pay * hours;
		
		cout<<endl<<"Gross Pay: "<<grossSalary<<endl;
		
		if (hours > 160) 
		{
			otHours = hours - 160;
			otPay = otHours * (pay * 0.25);
			
			cout<<"Overtime Pay: "<<otPay<<endl<<endl;
		}
			else 
			{
				cout<<"You did not work overtime."<<endl<<endl;
			}
		
		totalSalary = grossSalary + otPay;
		
		cout<<"Total Salary: "<<totalSalary<<endl;
		
		taxRate = tax(totalSalary);
		
		sss = totalSalary * 0.10;
		pagibig = totalSalary * 0.02;
		philhealth = totalSalary * 0.05;
		
		totalDeduction = addTaxes(sss, pagibig, philhealth, taxRate);
				
		cout<<"DEDUCTIONS"<<endl;
		cout<<"SSS Contribution: "<<sss<<endl;
		cout<<"PAG-IBIG Contribution: "<<pagibig<<endl;
		cout<<"PhilHealth: "<<philhealth<<endl;
		cout<<"Tax Deduction: "<<taxRate<<endl<<endl;

		cout<<"Total Deduction: "<<totalDeduction<<endl<<endl;
		
		netPay = totalSalary - totalDeduction;

		cout<<"Net Pay: "<<netPay<<endl<<endl;
		
		cout<<"Do you want another payslip (Y/N)?: ";
		cin>>answer;
		cin.ignore();
	}
	
	cout<<endl<<endl;
	
	return EXIT_SUCCESS;
}