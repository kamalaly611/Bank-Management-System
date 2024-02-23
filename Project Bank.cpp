#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <conio.h>

using namespace std;

struct name{
	char first_name[20];    //user first name     
	char last_name[20];	    //user last name	  
};
struct acc_op{
	name NA;		//struct name
	char pass[16];  //storing pin code
};
	acc_op AO;		//struct variabe Account open
	string AT; 		 //Account Type
	unsigned int AB,CB,DM,WM; //Account Balance,Current Balance,Depost_Money,Withdraw_Money
	int ACN,AN; //Account Number

void intro(void);
void account_open(void);
void check_balance(void);
void display_account_details(void);  //FUNCTIONS PROTOTYPE
void withdraw_amount(void);
void deposit_amount(void);

main()
{
	system("color 5e");  //system_color
	
	char op;
	char r;
	intro();
	do
	{
	    system("cls");
	    cout<<"\n\n\n";
		cout<<"\t*******************************";
		cout<<"\n\t* B A N K I N G   S Y S T E M *";
		cout<<"\n\t*******************************\n\n";
	    cout<<setw(25)<<"MAIN MENU\n"<<endl;
		cout<<setw(32)<<"* Press  1 to open account "<<endl;
		cout<<setw(41)<<"* Press  2 to check account balance "<<endl;
		cout<<setw(43)<<"* Press  3 to display account details "<<endl;
		cout<<setw(35)<<"* Press  4 to withdraw amount "<<endl;
		cout<<setw(34)<<"* Press  5 to deposit amount "<<endl;
		cout<<setw(25)<<"* Press  6 to Exit \n"<<endl;
		cout<<" => Select any operation: "<<endl;	
		cin>>op; 
		cout<<"---------------------------------"<<endl;
		switch(op)
		{
			case '1':
				account_open();
				getch();          
				break;
			case '2':
				check_balance();
				getch();
				break;
			case '3':
			    display_account_details();         // FUNCTIONS CALL
			    getch();
			    break;
		    case '4':
			    withdraw_amount();
			    getch();
				break;
		    case '5':
			    deposit_amount();
			    getch();
				break;
				
			default:
				cout<<"\n**********************************"<<endl;
				cout<<"*------Thanks for visiting-------*"<<endl;
				cout<<"**********************************"<<endl;
		}
    }
    while(op !='6');
 }


//  **************************
//	** FUNCTIONS DEFINATION **
//  **************************	

	void account_open(void)		//takes data from user.
	{
		cout << "Enter your first name\t\t  : ";
		cin>>AO.NA.first_name;
		cout << "Enter last your name\t\t  : ";
		cin>>AO.NA.last_name;
		cout<<"Account type saving=s, current=c  : ";
		cin>>AT;
		cout<<"Enter your account number\t  : ";
		cin>>AN;
		NEW_AMOUNT:
		cout<<"Account opening balance >= 500 PKR: ";
		cin>>AB;
		if(AB<500)
		{
	 		cout<<"\nYour amount is less then criteria please enter more then PKR 499. \n\n";
			goto NEW_AMOUNT; //if amount is less then criteria.
	    }	
		cout<<"Set your account pin\t\t  : ";
		cin>>AO.pass;
		
		cout<<"\nwait account is in process.\n"<<endl;
		for(int i=0; i<=40; i++)
		{		
			cout<<"\xb2";
			for(long y=0; y<=16000000; y++)
			{
			}
		}
		cout<<"\n\n**Congratulations your account is opened.**\n"<<endl;
		cout<<"\nPress any key to continue."<<endl;
	}
	
	void check_balance(void)	//checking account balance
	{
		AGAIN:
		cout<<"Enter your account number : ";
		cin>>ACN;	
		if(ACN==AN) 
		{
	   		cout<<"\n\nYour account balance is PKR."<<AB<<endl;
	   		cout<<"\n\nEnter any key to continue."<<endl;
        }
		else
		{
        	cout<<"\nAccount does not exists."<<endl;
        	cout<<"\nTry again!\n"<<endl;
        	goto AGAIN;	
		}
	}
	
	void display_account_details(void)  //Displays account details.
	{	
		cout<<"\n-------------------------\n";
		cout<<"User name\t\t: " << strcat(AO.NA.first_name,AO.NA.last_name)<<endl;
		cout<<"-------------------------\n";
		cout<<endl;
		cout<<"-------------------------\n";
		cout<<"Your Account type\t: "<<AT<<endl;
		cout<<"-------------------------\n";
		cout<<endl;
		cout<<"-------------------------\n";
		cout<<"Your account number is  : "<<AN<<endl;
		cout<<"-------------------------\n";
		cout<<endl;
		cout<<"-------------------------\n";
		cout<<"Your account balance is : "<<AB<<" PKR."<<endl;
		cout<<"-------------------------\n";
		cout<<"\n\nEnter any key to continue."<<endl;
    }
		
	void withdraw_amount(void) //performs account withdrawn functionality.
	{
		TRY_NEW:	//goto label
		cout<<"Enter your account number to withdraw amount :";
		cin>>ACN;
		if(ACN==AN)
	    {
	    	newww:
	    	cout<<"\nYour Current balance is PKR."<<AB<<endl;
		    cout<<endl;
		    cout<<"How much money do you want to withdraw? ";
		    cin>>WM;
		    if(WM>AB)
			{	
				cout<<"\nSorry! invalid amount."<<endl;
				goto newww;
			}
			else if(WM<=AB) 
			{
			   AB-=WM; 		//subtracting withdrawing money from account balance
			   cout<<"\nYour remaining balance is PKR."<<AB<<endl;
			   cout<<"\n\n\nEnter any key to continue."<<endl;
			}
		}
		else
		{
	    	cout<<"\nAccount does not exists."<<endl;
			cout<<"\nTry again!\n"<<endl;
	    	goto TRY_NEW;
		}
	
    }
    
	void deposit_amount(void) //displays amount/Account banance
	{	
		TRY_NEW:
		cout<<"Enter your account number to deposit amount : ";
		cin>>ACN;
		if(ACN==AN)
	    {
			cout<<"\nYour Current balance is : "<<AB<<" PKR"<<endl;
			cout<<endl;
			cout<<"How much money do you want to deposit? : ";
			cin>>DM;
		    AB+=DM;
			cout<<"\nYour New balance is: "<<AB<<" PKR."<<endl;
			cout<<"\n\n\nEnter any key to continue."<<endl;
		}
	    else
		{
	    	cout<<"\nAccount does not exists."<<endl;
			cout<<"\nTry again!\n"<<endl;
	    	goto TRY_NEW;
		}
	}
	
void intro() //opening title
{
	cout<<"\n\n\t*********************************************************** \n"<<endl;
	cout<<"\t----      /\\      |\\    |  |  / ----- |\\    |  (````````         "<<endl;
	cout<<"\t|   )    /  \\     | \\   |  | /    |   | \\   |  (                 "<<endl;
	cout<<"\t|__/    /    \\    |  \\  |  |/     |   |  \\  |  ( |``````|        "<<endl;
	cout<<"\t|  \\   /------\\   |   \\ |  |\\     |   |   \\ |  (  ```)  |        "<<endl;
	cout<<"\t|___) /        \\  |    \\|  | \\  ----- |    \\|  (_____)  |       "<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"\t      (````\\ \\  / (````\\  ----- ______  |\\    /|   "<<endl;
	cout<<"\t      |____   \\/  |____     |   |       | \\  / |     "<<endl;
	cout<<"\t           )   |       )    |   |-----  |  \\/  | 	   "<<endl;
	cout<<"\t      \\,,,,|   |  \\,,,,|    |   |_____  |      |     "<<endl;
	cout<<"\n\n\t*********************************************************** "<<endl;
	cout<<"\n\n\t\t  PROJECT DESIGNED BY:\n";
	cout<<"\n\t\t-> hajra\n";
	cout<<"\n\t\t MARYAM\n";
	cout<<"\n\t\tHAZIQ\n";
	cout<<"\n\t\tMUSLIH"<<endl;
	cout<<"\n\n\n\n\n\t\t\tWait project is loading.\n\n";
	for(int i=0; i<=115; i++)
	{		
		cout<<"\xb1";
		for(long y=0; y<=16000000; y++)
		{
		}
	}
	cout<<"\n\n\t\t\tProject is loaded.\n";
	cout<<"\n\t\t\tPress any key to proceed.";
	getch();
}

