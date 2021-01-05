#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

int main(){
	double loan, ir, pay;	
	cout << "Enter initial loan: ";
	cin >> loan;
	cout << "Enter interest rate per year (%): ";
	cin >> ir;
	cout << "Enter amount you can pay per year: ";
	cin >> pay;

	//use 'setw' to set width of table and 'left' to set left-alignment
	//you can change input argument of 'setw()' to see the effect
	//Try to change from 'left' to 'right' and see the effect
	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";
	int year =1;
	//use 'fixed' and 'setprecision' to fix the number of decimal digits for displaying
	//you can change input argument of 'setprecision()' to see the effect
	cout << fixed << setprecision(2); 
	while( loan > 0){
		cout << setw(13) << left << year; 
		//prevbalance
		cout << setw(13) << left << loan;
		double irp = (loan*ir)/100;
		//interest
		cout << setw(13) << left << irp;
		//total
		double total = loan + irp;
		cout << setw(13) << left << total;
		//payment
		if(loan+irp >= pay ){
			cout << setw(13) << left << pay;
		}else{
			cout << setw(13) << left << total;
		}
		//newbalance
		double nb;
		if((loan + irp) - pay>=0){
			nb = total - pay;
			cout << setw(13) << left << nb;
		}else{
			nb = 0;
			cout << setw(13) << left << nb;
		}
		loan = nb;
		cout << "\n";
		year++;
		if(loan == 0) break;
	}
	
	return 0;
}
