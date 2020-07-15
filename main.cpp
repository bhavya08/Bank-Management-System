#include<iostream>
#include<windows.h> //for Sleep function
#include<conio.h>
#include<stdlib.h> //for system("CLS") 
#include<map>
#include<fstream>
using namespace std;
#define MIN_BALANCE 1000
class InsufficientFunds{};
class Account
{
	private:
		long accountnumber; //Account Number
		string firstname; //First Name
		string lastname; //Last Name
		float balance; //Balance
		static long nextaccountnumber; //Next Account Number
	public:
		Account(){}
		Account(string fname,string lname,float balance);
		long getaccno(){return accountnumber;}
		string getfirstname(){return firstname;}
		string getlastname(){return lastname;}
		float getbalance(){return balance;}
		
		void deposit(float amount);
		void withdraw(float amount);
		static void setlastaccountnumber(long accountnumber);
		static long getlastaccountnumber();
		friend ofstream& operator<<(ofstream &ofs,Account &acc);
		friend ifstream& operator>>(ifstream &ifs,Account &acc);
		friend ostream& operator<<(ostream &os,Account &acc);		
};
long Account::nextaccountnumber=0;
class Bank
{
	private:
		map<long,Account>accounts;
	public:
		Bank();
		Account openaccount(string fname,string lname,float balance);
		Account balanceenquiry(long accountnumber);
		Account deposit(long accountnumber,float amount);
		Account withdraw(long accountnumber,float amount);
		void closeaccount(long accountnumber);
		void showallaccounts();
		~Bank();
};

//Main Function
int main()
{
	Bank b;
	Account acc;
	int choice;
	string fname,lname;
	long accountnumber;
	float balance;
	float amount;
	system("CLS");
	cout<<"\n\n\n\n                           -              ";
	Sleep(125);
	cout<<"\n                         - - -           ";
	Sleep(125);
	cout<<"\n                       -   -   -          ";
	Sleep(125);
	cout<<"\n                     -     -     -        ";
	Sleep(125);
	cout<<"\n                   -       -       -      ";
	Sleep(125);
	cout<<"\n                 -         -         -    ";
	Sleep(125);
	cout<<"\n               -           -           -  ";
	Sleep(125);
	cout<<"\n             - - - - - - - - - - - - - - -";
	Sleep(125);
	cout<<"\n            |                             |";
    Sleep(125);
	cout<<"\n            |                             |";
	Sleep(125);
	cout<<"\n            |                             |";
	Sleep(125);
	cout<<"\n            |                             |";
	Sleep(25);
	cout<<"\n            |     -------------------     |";
	Sleep(25);
	cout<<"\n            |    |  Bank Management  |    |";
	Sleep(25);
	cout<<"\n            |     -------------------     |";
	Sleep(125);
	cout<<"\n            |                             |";
	Sleep(125);
	cout<<"\n            |                             |";
	Sleep(125);
	cout<<"\n            |                             |";
	Sleep(125);
	cout<<"\n            |                             |";
	Sleep(125);
	cout<<"\n             - - - - - - - - - - - - - - -";
	cout<<"\n\n\n                    Made by: BHAVYA SHARMA";
	Sleep(2000);
	cout<<endl;
	system("CLS");
	do{
		cout<<"\n\n\t - - - - - - - - - ";
		Sleep(125);
		cout<<"\n\t|    MAIN MENU    |";
		Sleep(125);
		cout<<"\n\t - - - - - - - - - ";
		Sleep(125);
    	cout<<"\n\n\t1. Open a New Account";
    	cout<<"\n\t2. Balance Enquiry";
    	cout<<"\n\t3. Deposit";
    	cout<<"\n\t4. Withdrawl";
    	cout<<"\n\t5. Close Account";
    	cout<<"\n\t6. Show all Accounts";
    	cout<<"\n\t7. Quit";
    	cout<<"\n\n\nEnter your choice: ";
    	cin>>choice;
    	switch(choice)
    	{
    		case 1:
    			cout<<"Enter First Name: ";
    			cin>>fname;
    			cout<<"Enter Last Name: ";
    			cin>>lname;
    			cout<<"Enter initial Balance: ";
    			cin>>balance;
    			acc=b.openaccount(fname,lname,balance);
    			cout<<"**Congratulation! Account is Created**\n\n";
    			cout<<"**********************************************\n";
    			cout<<acc;
    			cout<<"**********************************************\n\n";
    			break;
    		case 2:
    			cout<<"Enter Account Number: ";
    			cin>>accountnumber;
    			acc=b.balanceenquiry(accountnumber);
    			cout<<endl<<"**Account Details**\n"<<endl;
    			cout<<"**********************************************\n";
    			cout<<acc;
    			cout<<"**********************************************\n\n";
    			break;
    		case 3:
    			cout<<"Enter Account Number: ";
    			cin>>accountnumber;
    			cout<<"Enter Balance: ";
    			cin>>amount;
    			acc=b.deposit(accountnumber,amount);
    			cout<<"**Amount is Deposited**\n\n";
    			cout<<"**********************************************\n";
    			cout<<acc;
    			cout<<"**********************************************\n\n";
    			break;
    		case 4:
    			cout<<"Enter Account Number: ";
    			cin>>accountnumber;
    			cout<<"Enter Balance: ";
    			cin>>amount;
    			acc=b.withdraw(accountnumber,amount);
    			cout<<"**Amount Withdrawn**\n\n";
    			cout<<"**********************************************\n";
    			cout<<acc;
    			cout<<"**********************************************\n\n";
    			break;
			case 5:
				cout<<"Enter Account Number: ";
				cin>>accountnumber;
				b.closeaccount(accountnumber);
				cout<<endl<<"**Account is Closed**\n\n";
			case 6:
				b.showallaccounts();
				break;  
			case 7:
				break;
			default:
				cout<<"**Enter Correct Choice**";
				break;  			
	 	}		
	}
	while(choice<7);
	return 0;
}

//Account Class Function Definition
Account::Account(string fname,string lname,float balance)
{
	nextaccountnumber++;
	accountnumber=nextaccountnumber;
	firstname=fname;
	lastname=lname;
	this->balance=balance;
}

void Account::deposit(float amount)
{
	balance=balance+amount;
}

void Account::withdraw(float amount)
{
	if(balance-amount<MIN_BALANCE)
		throw InsufficientFunds();
	balance=balance-amount;
}

void Account::setlastaccountnumber(long accountnumber)
{
	nextaccountnumber=accountnumber;
}

long Account::getlastaccountnumber()
{
	return nextaccountnumber;
}

ofstream& operator<<(ofstream &ofs,Account &acc)
{
	ofs<<acc.accountnumber<<endl;
	ofs<<acc.firstname<<endl;
	ofs<<acc.lastname<<endl;
	ofs<<acc.balance<<endl;
	return ofs;
}

ifstream& operator>>(ifstream &ifs,Account &acc)
{
	ifs>>acc.accountnumber;
	ifs>>acc.firstname;
	ifs>>acc.lastname;
	ifs>>acc.balance;
	return ifs;
}

ostream& operator<<(ostream &os,Account &acc)
{
	os<<"First Name: "<<acc.getfirstname()<<endl;
	os<<"Last Name: "<<acc.getlastname()<<endl;
	os<<"Account Number: "<<acc.getaccno()<<endl;
	os<<"Balance: "<<acc.getbalance()<<endl;
	return os;
}

Bank::Bank()
{
	Account account;
	ifstream infile;
	infile.open("Bank.data");
	if(!infile)
	{
		cout<<"Error in Opening! File Not Found!!"<<endl;
		return;
	}
	while(!infile.eof())
	{
		infile>>account;
		accounts.insert(pair<long,Account>(account.getaccno(),account));
	}
	Account::setlastaccountnumber(account.getaccno());
	infile.close();
}

Account Bank::openaccount(string fname,string lname,float balance)
{
	ofstream outfile;
	Account account(fname,lname,balance);
	accounts.insert(pair<long,Account>(account.getaccno(),account));
	outfile.open("Bank.data",ios::trunc);
	map<long,Account>::iterator itr;
	for(itr=accounts.begin();itr!=accounts.end();itr++)
	{
		outfile<<itr->second;
	}
	outfile.close();
	return account;	
} 

Account Bank::balanceenquiry(long accountnumber)
{
	map<long,Account>::iterator itr=accounts.find(accountnumber);
	return itr->second;
}

Account Bank::deposit(long accountnumber,float amount)
{
	map<long,Account>::iterator itr=accounts.find(accountnumber);
	itr->second.deposit(amount);
	return itr->second;
}

Account Bank::withdraw(long accountnumber,float amount)
{
	map<long,Account>::iterator itr=accounts.find(accountnumber);
	itr->second.withdraw(amount);
	return itr->second;
}

void Bank::closeaccount(long accountnumber)
{
	map<long,Account>::iterator itr=accounts.find(accountnumber);
	cout<<"Account Deleted"<<itr->second;
	accounts.erase(accountnumber);
}

void Bank::showallaccounts()
{
	map<long,Account>::iterator itr;
	for(itr=accounts.begin();itr!=accounts.end();itr++)
	{
		cout<<"\n**********************************************\n";
		cout<<"Account "<<itr->first<<endl<<itr->second;
		cout<<"**********************************************\n";
	}
}

Bank::~Bank()
{
	ofstream outfile;
	outfile.open("Bank.data",ios::trunc);
	map<long,Account>::iterator itr;
	for(itr=accounts.begin();itr!=accounts.end();itr++)
	{
		outfile<<itr->second;
	}
	outfile.close();
}
