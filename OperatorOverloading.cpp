#include<iostream>
using namespace std;

class complex
{
	float real;
	float img;
	
	public:
	complex()
	{
		real=0.0;
		img=0.0;
	}
	complex(float freal, float fimg)
	{
		real=freal;
		img=fimg;
	}	
	~complex()
	{
	}
	complex operator + (complex &obj)
	{
		cout<<endl<<"------Operator + Overloading------"<<endl;
		 complex res; 
         res.real = real + obj.real; 
         res.img = img + obj.img; 
         cout<<endl<<"Successfully Overloaded"<<endl;
         return res;
	}
	complex operator * (complex &obj)
	{
		cout<<endl<<"------Operator * Overloading------"<<endl;
		complex res;
		res.real=(real*obj.real)-(img*obj.img);
		res.img=(real*obj.img)+(img*obj.real);
		cout<<endl<<"Successfully Overloaded"<<endl;
		return res;
	}
		complex operator - (complex &obj)
	{
		cout<<endl<<"------Operator - Overloading------"<<endl;
		 complex res; 
         res.real = real - obj.real; 
         res.img = img - obj.img; 
         cout<<endl<<"Successfully Overloaded"<<endl;
         return res;
	}
	complex operator ++()
	{
		cout<<endl<<"------Pre Increment Operator Overloading------"<<endl;
		complex res;
		res.real=++real;
		res.img=++img;
		cout<<endl<<"Successfully Overloaded"<<endl;
		return res;
	}
	complex operator ++(int)
	{
		cout<<endl<<"------Post Increment Operator Overloading------"<<endl;
		complex res;
		res.real=real++;
		res.img=img++;
		cout<<endl<<"Successfully Overloaded"<<endl;
		return res;
	}
	
	friend ostream & operator <<(ostream &O, complex &obj);
	friend istream & operator >>(istream &I, complex &obj);
};

ostream & operator <<(ostream &O, complex &obj)
{
	cout<<endl<<"------Operator << Overloading------"<<endl;
	O<<obj.real<<"+i"<<obj.img;
	return O;
}
istream & operator >>(istream &I, complex &obj)
{
	cout<<endl<<"------Operator >> Overloading------"<<endl;
	cout<<"Enter the real part of the complex number:  ";
	cin>>obj.real;
	cout<<"Enter the imaginary part of the complex number:  ";
	cin>>obj.img;
	return I;
}

int main()
{
	int choice2,choice3;
	char choice1;
	complex c1,c2,c3;
	while(true)
	{
		cout<<endl<<endl<<"--------Enter your choice:-------- "<<endl;
		cout<<"A. To Overload Unary Operator:  "<<endl;
		cout<<"B. To Overload Binary Operator: "<<endl;
		cout<<"C. To Exit "<<endl;
		cin>>choice1;
		
		if(choice1=='A' || choice1=='a')
		{
			cout<<endl<<"One operand is needed to be entered: "<<endl;
			cin>>c1;
			
			cout<<endl<<"--------Enter your choice:-------- "<<endl;
			cout<<"1. For Pre Increment Overloading "<<endl;
			cout<<"2. For Post Increment Overloading"<<endl;
			fflush(stdin);
			cin>>choice2;
			if(choice2==1)
			{
				++c1;
			}
			else
			{
				c1++;
			}
			cout<<c1;
		}
		else if(choice1=='B' || choice1=='b')
		{
			cout<<endl<<"Two Operands needed to be entered :"<<endl;
			cout<<"Enter the first operand:"<<endl;
			fflush(stdin);
			cin>>c1;
			cout<<"Enter the second operand:"<<endl;
			fflush(stdin);
			cin>>c2;
			
			cout<<endl<<"--------Enter your choice:-------- "<<endl;
			cout<<endl<<"1. For + Overloading "<<endl;
			cout<<"2. For - Overloading "<<endl;
			cout<<"3. For * Overloading "<<endl;
			fflush(stdin);
			cin>>choice2;
			
			if(choice2==1)
			{
				c3=c1+c2;
				cout<<c3;
			}
			else if(choice2==2)
			{
				c3=c1-c2;
				cout<<c3;
			}
			else if(choice2==3)
			{
				c3=c1*c2;
				cout<<c3;
			}
			else
			{
				
			}
		}
		else if (choice1=='C' || choice1=='c')
		{
			cout<<endl<<"Exiting!";
			break;
		}
		else
			cout<<endl<<"Wrong choice!";
	}
	return 0;
}