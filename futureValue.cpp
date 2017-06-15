#include <iostream>
#include <math.h>


using namespace std;

double futureValue(double&, double, double& FV);
double presentValue (double FV , double Interest,double years, double& PV);
int main( ) {

	bool again = true; 
	
	do {

 
	double FV = 0;
	double PV = 0;
	double years = 0;
	double anualInterest = 0;
	double numMonth = 0 ;
	double fixedMonDeposite = 0;
	double Interest = 0;

	int
		userInput;

	cout<<"To monthly deposite (FV) press 1\n"<<endl;
	cout	<<"To leave a certain amount for a term (PV) press 2:\n "<<endl;
	cin>>userInput;
	cout<<endl;
	

	switch (userInput)
	{
	case 1:

		  futureValue(numMonth,fixedMonDeposite, FV);
		   cout<<endl;
		   cout<<"You would have $"<<FV<<" money by the end of "<<numMonth<<" months."<<endl;
		break;
	case 2:

		 presentValue  (FV, Interest, years, PV);
		  cout<<endl;
		  cout<<"You need to deposite $"<<PV <<endl;
		 break;
	}

	cout << endl;
		char ans;
 
       cout << "Press 'Q' to quit, 'C' to run it again\n";
        char q, Q, c, C;
     
        cin >> ans;
        
        if (ans == 'q' || ans == 'Q')
           {
			   again ==true; 
			   return 0;
           }     
        else if (ans == 'c' || ans == 'C')
           {
                 again = true;   
           }
        
	  cout<<endl<<endl;

} while( again == true );

system("pause");
return 0;
}


double futureValue(double&  numMonth,double fixedMonDeposite, double& FV) {
	 
	double anualInterest;

	 cout<<"Anual interest rate percentage ? ";
	cin>>anualInterest;

	bool correct_no = false;

	while (!correct_no)
	{
		if (anualInterest <= 100000000 && anualInterest > 0)
		{
		correct_no = true;
		}
			else
			{
			cout << "Invalid Input, try again :" << endl;
			cin >> anualInterest;	
			}
	}
	 


	 anualInterest = anualInterest / 100;
	 double monInterest = anualInterest / 12; 

	cout<<"How many moths you want to keep making deposite : ";
	cin>>numMonth;

	bool correct1 = false;
	while (!correct1)
	{
		if (numMonth <= 100000000 && numMonth > 0)
		{
		correct1 = true;
		}
			else
			{
			cout << "Invalid Input, try again :" << endl;
			cin >> numMonth;	
			}
	}

	cout<<"What is your fixed monthly deposite amount : ";
	cin>>fixedMonDeposite;

	bool correct2 = false;
	while (!correct2)
	{
		if (fixedMonDeposite <= 100000000 && fixedMonDeposite > 0)
		{
		correct2 = true;
		}
			else
			{
			cout << "Invalid Input,try again :" << endl;
			cin >> fixedMonDeposite;	
			}
	}


	FV = (fixedMonDeposite * ( pow ((1 + monInterest) , numMonth) - 1 )) / monInterest;

	  

	  return FV;
}


 double presentValue (double F, double Interest, double years, double& PV ) {
	 
	
	 cout<<"How many years would you want to money stay in your account ?";
	cin>>years;
	 
	bool correct3 = false;
	while (!correct3)
	{
		if (years <= 100000000 && years > 0)
		{
		correct3 = true;
		}
			else
			{
			cout << "Invalid Input, try again:" << endl;
			cin >> years;	
			}
	}



	cout<<"How much do you wanna have after "<<years<<" years ?";
	cin>>F;


	bool correct4 = false;
	while (!correct4)
	{
		if (F <= 100000000 && F > 0)
		{
		correct4 = true;
		}
			else
			{
			cout << "Invalid Input, try again :" << endl;
			cin >> F;	
			}
	}

	cout<<"Anual interest rate ?";
	cin>>Interest;

	bool correct5 = false;
	while (!correct5)
	{
		if (Interest <= 100000000 && Interest > 0)
		{
		correct5 = true;
		}
			else
			{
			cout << "Invalid Input, try again:" << endl;
			cin >> Interest;	
			}
	}
	Interest = Interest / 100;

	PV = (F /  pow ((1 + Interest) , years));

	 
	 
	return PV;
 }