#include<iostream>
#include<string.h>
using namespace std;
class BankAccounts
{
	int accNo;
	char custName[30];
	char accType[15];
	int pin;
	float balance;
	public:
		BankAccounts()
		{
			int itemp;
			accNo=0;
			for(itemp=0;itemp<30;itemp++)
				custName[itemp]='\0';
			for(itemp=0;itemp<15;itemp++)
				accType[itemp]='\0';
			pin=0;
			balance=0;
		}
		void GetData(int accNo1)
		{
			int itemp=0,flag=1;
			accNo=accNo1;
			cout<<"Enter the customer name:    ";
			fflush(stdin);
			cin.getline(custName,30);
			for(itemp=0;itemp<30;itemp++)
			{
				if(((int)custName[itemp]>=(int)'A'&&(int)custName[itemp]<=(int)'Z')||((int)custName[itemp]>=(int)'a'&&(int)custName[itemp]<=(int)'z')||(int)custName[itemp]==(int)' '||(int)custName[itemp]==(int)'\0')
					continue;
				else
				{
					cout<<"Enter the customer name correctly:";
					for(itemp=0;itemp<30;itemp++)
						custName[itemp]='\0';
					cin.getline(custName,30);
					fflush(stdin);
					itemp=0;
				}
			}
			for(itemp=0;itemp<30;itemp++)
			{
				custName[itemp]=toupper(custName[itemp]);
			} 
			cout<<"Enter the type of account:    ";
			cin.getline(accType,15);
			for(itemp=0;itemp<15;itemp++)
			{
				accType[itemp]=toupper(accType[itemp]);

			}
			while(flag==1){
			if((strcmp(accType,"SAVINGS")==0)||(strcmp(accType,"CUREENT")==0)||(strcmp(accType,"FIXED DEPOSIT")==0)||(strcmp(accType,"RECURRING")==0))
			{
				flag=0;
			}
			else
			{
				cout<<"Enter the account type correctly:    ";
				cin.getline(accType,15);
				for(itemp=0;itemp<15;itemp++)
				{
					accType[itemp]=toupper(accType[itemp]);
				}
				flag=1;
			}
		    }
			cout<<"Enter the 4 digits pin :    ";
			cin>>pin;
			while(pin<1000 && pin>9999)
			{
				cout<<"Enter the pin correctly:   ";
				cin>>pin;
			}
			cout<<"Enter the balance :    ";
			cin>>balance;
			if(strcmp("SAVINGS",accType)==0)
			{
				while(balance<500)
				{
					cout<<"Enter the minimum balance of 500 or more:  ";
					cin>>balance;
				}
			}
			else
			{
				while(balance<1000)
				{
					cout<<"Enter the minimum balance of 1000 or more:  ";
					cin>>balance;
				}
			}
		}
		void PrintData()
		{
			cout<<endl<<"The required informations are:  "<<endl;
			cout<<"The account number is:    "<<accNo<<endl;
			cout<<"The account type:     "<<accType<<endl;
			cout<<"The balance you have in the account is :    "<<balance<<endl;
		}
		void DepositBalance()
		{
			float depbal;
			cout<<endl<<"Enter the amount you want to deposit:   ";
			cin>>depbal;
			while(depbal<5000 && ((strcmp(accType,"RECURRING")==0)||(strcmp(accType,"CURRENT")==0)))
			{
				cout<<"Enter minimum amount of Rs 5000 or more:  ";
				cin>>depbal;
			}
			while(depbal<1000 && ((strcmp(accType,"SAVINGS")==0)||(strcmp(accType,"FIXED")==0)))
			{
				cout<<"Enter minimum amount of Rs. 1000 or more:   ";
				cin>>depbal;
			}
			balance=balance+depbal;
			cout<<"Your amount has been successfully deposited!"<<endl;
			
		}
		void WithdrawBalance()
		{
			float withamt;
			char choice='Y';
			while(choice=='Y' || choice=='y')
			{
			cout<<endl<<"Enter the amount you want to withdraw:   ";
			cin>>withamt;
			if(withamt>balance)
			{
				cout<<"You do not have sufficient amount! "<<endl;
				cout<<"Your balance left is :  "<<balance<<endl;
				cout<<"Do you want to retry? Enter Y for yes:   ";
				fflush(stdin);
				cin>>choice;
			}
			else
			{
				if((balance-withamt)<1000)
				{
					cout<<"Withdrawal cant be made as you will be left with less than 1000!"<<endl;
					cout<<"Do you want to retry? Enter Y for yes:  ";
					fflush(stdin);
					cin>>choice;
				}
				else
				{
					balance=balance-withamt;
					cout<<"Withdrawal successful!"<<endl;
					cout<<"Your left over balance is :  "<<balance<<endl;
					choice='N';
				}
			}
			}
		}
			void UpdatePassword()
		{
			cout<<"Enter the new password:   ";
			cin>>pin;
			while(pin<1000 && pin>>9999)
			{
				cout<<"Enter the password correctly of 4 digits:   ";
				cin>>pin;
			}
			cout<<"Your password is updated!"<<endl;
		}
			int search(int id,int choice)
		{
			if(accNo==id)
			{
				if(choice==2)
				{
					cout<<"Hello! "<<custName<<endl;	
				}
				return 1;
			}
			else
			return 0;
		}
		int check(int pass)
		{
			if(pass==pin)
			return 1;
			else
			return 0;
		}
};
main()
{
	int choice1,choice2,inum=0,temp1,temp2,i,userid,pass,accNo1,cnt=0;
	char choice='Y';
	BankAccounts *ba=new BankAccounts[50];
	while(choice=='Y'|| choice=='y')
	{
		cout<<endl<<"Enter	1	for adding new customers: "<<endl;
		cout<<"Enter	2	for accessing a bank account:  "<<endl;
		cout<<"Enter  any other number to exit the bank: "<<endl;
		cin>>choice1;
		if(choice1==1)
		{
				cout<<endl<<"Enter for the customer :"<<inum+1<<endl;
				cout<<"Enter the 5 or more digits account number:   ";
				cin>>accNo1;
				while(accNo1<10000)
				{
					cout<<"Enter the account number correctly:  ";
					cin>>accNo1;
				}
				if(inum!=0)
				{
				for(i=0;i<inum;i++)
				{
				temp1=ba[i].search(accNo1,choice1);
				if(temp1==1)
				break;
			    }
				if(temp1==1)
				{
					cout<<"This account already exists!"<<endl;
				}
				else
				{
				ba[inum].GetData(accNo1);
				inum=inum+1;
			    }
				}
				else if(inum==0)
				{
					ba[inum].GetData(accNo1);
					inum++;
				}
		}
		else if(choice1==2 && inum!=0)
		{
			cout<<"Enter the user input or account number:    ";
			cin>>userid;
			while(userid<10000)
			{
				cout<<"Enter the userid or account number correctly:  ";
				cin>>userid;
			}
			for(i=0;i<inum;i++)
			{
				temp1=ba[i].search(userid,choice1);
					if(temp1==1)
					{
						break;
					}
			}
			if(temp1==1)
			{
				cout<<"Enter the 4 digits password or pin number:   ";
				cin>>pass;	
				while(pass<1000 && pass>9999)
				{
					cout<<"Enter the password or pin number correctly:  ";
					cin>>pass;
				}
				temp2=ba[i].check(pass);
				cnt=0;
				while(cnt<2)
				{
					if(temp2==1)
					{
						break;	
					}	
					else
					{
						cout<<"You have entered a wrong password!";
						cnt=cnt+1;
						cout<<"Try again! "<<endl;
						cout<<"Enter the correct password:  ";
						cin>>pass;
						temp2=ba[i].check(pass);
					}
				}
				if(cnt==2)
					cout<<"You have reached the maximum limit! "<<endl;
			}
			if(temp2==1)
			{
			cout<<endl<<"Enter   1   for viewing the account details "<<endl;
			cout<<"Enter   2   for depositing balance "<<endl;
			cout<<"Enter   3   for withdrawal of balance "<<endl;
			cout<<"Enter   4   for updating pin "<<endl;
			cout<<"Enter   any other number   to exit"<<endl;
			cin>>choice2;
			if(choice2==1)
			{
				ba[i].PrintData();
			 } 
			 else if(choice2==2)
			 {
			 	ba[i].DepositBalance();
			 }
			 else if(choice2==3)
			 {
			 	ba[i].WithdrawBalance();
			 }
			 else if(choice==4)
			 {
			 	ba[i].UpdatePassword();
			 }
			}
		}
		else if(choice1==2 && inum==0)
		{
			cout<<"You have no customers in the bank!"<<endl;
		}
		else
		{
			cout<<"Thank You!"<<endl;
			break;
		}
		cout<<"Do you want to continue? Enter Y for yes or N for no:  ";
		fflush(stdin);
		cin>>choice;
	}
}