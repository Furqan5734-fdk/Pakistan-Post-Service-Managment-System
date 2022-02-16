#include<iostream>
#include<string>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

class PostOffice;

class GPO
{
	string GPOname;
	string GPOcity;
	PostOffice* array[5];
	 
	public:
		GPO(){
			GPOname="\0";
			GPOcity="\0";
		
		}
			
		//GPONAME	
		void setGPOname(string GPOname){	
			this->GPOname=	GPOname;
		}
		
		string getGPOname(){	
			return this->GPOname;
		}
	    //GPOCity	
		void setGPOcity(string GPOcity){	
			this->GPOcity=	GPOcity;
		}
		
		string getGPOcity(){	
			return this->GPOcity;
		}	

		void PostOfficeDetail(){
			
			cout<<"GPO Name: "<<getGPOname()<<endl;
			
			cout<<"GPO City: "<<getGPOcity()<<endl;
		}
		
};




class PostOffice
{
	string username;
	string password;
	public:
		PostOffice(){
			username="\0";
			password="\0";
			
		}
		
		//GETTER AND SETTER
		
	//USERNAME	
		void setusername(string username){	
			this->username=	username;
		}
		
		string getusername(){	
			return this->username;
		}
	//PASSWORD	
		void setpassword(string password){	
			this->password=	password;
		}
		
		string getpassword(){	
			return this->password;
		}
		
		void Display(){
			cout<<"Username: "<<username<<endl;
			cout<<"Password: "<<password<<endl;
		}
};

///*****************************************************************MAILS************************************************************************************


class Mail
{
	string mailtype;
 	public:
 		
 		Mail(){
 			mailtype="\0";
		 }
		 
		 //SETTER AND GETTER
		 
		//mailtype	
		void setmailtype(string mailtype){	
			this->mailtype=	mailtype;
		}
		
		string getmailtype(){	
			return this->mailtype;
		}
		
		//Function for checking mail service
		
		int checkmail(){
			
			int mails=0;
			
			again:
				
			cout<<"\n\n1. Bounced Mails\n2. Returned Mail\nWhich type of Mails you check: \n"<<endl;
			cin>>mails;
	
			if(mails==3){
				cout<<"Wrong Input"<<endl;
				goto again;
			}
			
			return mails;
		}
};

class BouncedMail: public Mail
{
 	int noofmailbounced;
	
 	public:
 		
		 BouncedMail(){
 			noofmailbounced=0;
		 }
 		
		//SETTER AND GETTER
		
			//noofmailbounced	
		void setnoofmailbounced(int noofmailbounced){	
			this->noofmailbounced=	noofmailbounced;
		}
		
		int getnoofmailbounced(){	
			return this->noofmailbounced;
		}	
				//Show Detail

		void Bounced(){
			
			cout<<"Bounced Mails: "<<this->getnoofmailbounced()<<endl;
		}
		
};

class ReturnedMail: public Mail
{
	int noofmailreturned;
	
 	public:
 		
		 ReturnedMail(){
 			noofmailreturned=0;
		 }
 		
		//SETTER AND GETTER
		
			//noofmailreturned	
		void setnoofmailreturned(int noofmailreturned){	
			this->noofmailreturned=	noofmailreturned;
		}
		
		int getnoofmailreturned(){	
			return this->noofmailreturned;
		}	
		
		//Show Detail
		void Returned(){
			
			cout<<"Bounced Mails: "<<this->getnoofmailreturned()<<endl;
		}
};

class MailService
{
	
	Mail* mail;
	int mailprice;
	
	public:
		
		//COnstructor
		MailService(){
			mailprice=0;
				mail =new Mail; 	
		}
		
		//GETTER AND SETTER
		
		void setmailprice(int mailprice){	
			this->mailprice=	mailprice;
		}
		
		int getmailprice(){	
			return this->mailprice;
		}
		
		//Checking mail is same_day,urgent or so on.
		
		int CheckMailService(int temp){
			
			int delivery,result,tax=0;
			cout<<"1.Same day\n2.One Day\n3.Urgent\n4.Regular\n";
			cout<<"Send Delivery Time: ";
			cin>>delivery;
			
			if(!delivery==3)
			result=temp;
			
			if(delivery==3){
				cout<<"Urgent Mail has an extra charges which is: "<<endl;
				tax = temp*(20/100);  
				result = getmailprice()  + tax;
				
			}
				
			return result;
		}
		
		int check(){
		
			int mails=0;
			
			again:
				
			cout<<"\n\n1. Urgent Mails\n2. Regular Mail\nWhich type of Mails you check: \n"<<endl;
			cin>>mails;
	
			if(mails==3){
				cout<<"Wrong Input"<<endl;
				goto again;
			}
			
			return mails;
		}	
		~MailService(){
			delete mail;
		}
};

class UrgentMail : public MailService
{
		int noofmailurgent;
	
 	public:
 		
		 UrgentMail(){
 			noofmailurgent=0;
		 }
 		
		//SETTER AND GETTER
		
			//noofmailbounced	
		void setnoofmailurgent(int noofmailurgent){	
			this->noofmailurgent=	noofmailurgent;
		}
		
		int getnoofmailurgent(){	
			return this->noofmailurgent;
		}	
				//Show Detail

		void Urgent(){
			
			cout<<"Urgent Mails: "<<this->getnoofmailurgent()<<endl;
		}	
};


class RegularMail : public MailService
{
			int noofmailregular;
	
 	public:
 		
		 RegularMail(){
 			noofmailregular=0;
		 }
 		
		//SETTER AND GETTER
		
			//noofmailbounced	
		void setnoofmailregular(int noofmailregular){	
			this->noofmailregular=	noofmailregular;
		}
		
		int getnoofmailregular(){	
			return this->noofmailregular;
		}	
				//Show Detail

		void Regular(){
			
			cout<<"Regular Mails: "<<this->getnoofmailregular()<<endl;
		}
};



///*****************************************************************MAILS************************************************************************************



//*********************************************************************//*********************************************************************//*********************************************************************
class Address
{
//	protected:
		int house_no;
		int street_no;
		string city;
		
	public:
	
		Address(){
			house_no=0;
			street_no=0;
			city="\0";			
		}
			
//GETTERS AND SETTERS	
		
		//HOUSE NO	
		void sethouse_no(int house_no){
			
				this->house_no=	house_no;
		}
		
		int gethouse_no(){
			
			return this->house_no;
		}
		
		//Street NO
		void setstreet_no(int street_no){
			
				this->street_no=	street_no;
		}
		
		int getstreet_no(){
			
			return this->street_no;
		}
		
		//City
		void setcity(string city){
			
				this->city=	city;
		}
		
		string getcity(){
			
			return this->city;
		}
		
		void Showdetail(){
			
			cout<<"House: "<<house_no<<endl;
			cout<<"Street: "<<street_no<<endl;
			cout<<"City: "<<city<<endl;
			
		}
};

///////////////////////////////////CUSTOMER CLASS//////////////////////////////////


class Customer
{
	Address* Add;
	int cust_id;
	string cust_name;
	
	public:
			Customer(){
				
				cust_id=0;
				cust_name="\0";	
		}
			
//GETTERS AND SETTERS	
		
		//ID NO	
		void setcust_id(int cust_id){
			
				this->cust_id=	cust_id;
		}
		
		int getcust_id(){
			
			return this->cust_id;
		}
		
		//Name
		void setcust_name(string cust_name){
			
				this->cust_name=	cust_name;
		}
		
		string getcust_name(){
			
			return this->cust_name;
		}	
		
};

///////////////////////////////////INVOICE CLASS//////////////////////////////////

class Invoice
{
	double weight;
	string AddressSender;
	string AddressReceiver;
	string ContactSender;
	string ContactReceiver;
	string Receivername;	
	
	
	public:
		Invoice(){
			weight=0;
			AddressSender="\0";
			AddressReceiver="\0";
			ContactSender="\0";
			ContactReceiver="\0";
			Receivername="\0";
		}
			
		//GETTERS AND SETTERS FOR ABOVE INFORMATION FORM
		
//FOR WEIGHT
		void setweight(double weight){
			this->weight=weight;
		}
		double getweight(){
			return this->weight;
		}
		
//FOR Sender Address 
		void setAddressSender(string AddressSender){
			this->AddressSender=AddressSender;
		}
		string getAddressSender(){
			return this->AddressSender;
		}
		
//FOR receiver Address 
		void setAddressReceiver(string AddressReceiver){
			this->AddressReceiver=AddressReceiver;
		}
		string getAddressReceiver(){
			return this->AddressReceiver;
		}
		
//FOR Sender Contact 
		void setContactSender(string ContactSender){
			this->ContactSender=ContactSender;
		}
		string getContactSender(){
			return this->ContactSender;
		}
		
//FOR receiver Contact
		void setContactReceiver(string ContactReceiver){
			this->ContactReceiver=ContactReceiver;
		}
		string getContactReceiver(){
			return this->ContactReceiver;
		}
		
//FOR receiver Name
		void setReceivername(string Receivername){
			this->Receivername=Receivername;
		}
		string getReceivername(){
			return this->Receivername;
		}
		
///////////////////////FUNCTIONS/////////////////
	
		void InvoiceDetail(){
			
			cout<<"INVOICE DETAIL"<<endl;
			cout<<"Receiver Name : "<<this->getReceivername()<<endl;
			cout<<"Weigth: "<<this->getweight()<<endl;
			cout<<"Sender Address: "<<this->getAddressSender()<<endl;
			cout<<"Receiver Address: "<<this->getAddressReceiver()<<endl;
			cout<<"Sender Contact: "<<this->getContactSender()<<endl;
			cout<<"Receiver Contact: "<<this->getContactReceiver()<<endl;
			
		}
		
		
};

/////////////////////ORDER CLASS COMPOSITE WITH CUSTOMER AND INVOICE CLASS/////////////////////////

class Order
{
	int OrderId;
	Customer* c_obj;
	Invoice* i_obj;
	
	public:
		//Constructor
		Order(){
		
			this->c_obj=new Customer;
			this->i_obj=new Invoice;

		}	
		
		//SETTER AND GETTER FOR ORDER ID:
		
		void setOrderId(int OrderId){
			this->OrderId=OrderId;
		}
		int getOrderId(){
			return this->OrderId;
		}
		
		//Destructor
		~Order()
		{
			delete c_obj;
			delete i_obj;

		}
		
};


//*********************************************************************//*********************************************************************//*********************************************************************

class PostalWorker
{
	int WorkerId;
	string WorkerPosition;
			
	public:
		
		PostalWorker(){
			
			WorkerId=0;
			WorkerPosition="\0";
			
		}
		
	//GETTRER AND SETTER 
	
	//FOR WorkerId
		void setWorkerId(int WorkerId){	
			this->WorkerId=	WorkerId;
		}
		
		int getWorkerId(){	
			return this->WorkerId;
		}	
	
	//FOR WorkerPosition
		void setWorkerPosition(string WorkerPosition){	
			this->WorkerPosition=	WorkerPosition;
		}
		
		string getWorkerPosition(){	
			return this->WorkerPosition;
		}	
	
		void WorkerDetail()
		{
			cout<<"Workers Detail\n";
			cout<<"WorkerId: "<<getWorkerId()<<endl;
			cout<<"WorkerPosition: "<<getWorkerPosition()<<endl;
				
		}					
};


class SortingSection : public PostalWorker
{	
	
	public:
		
};


class Clerk : public PostalWorker
{	
	string name;
	string phoneno;
	double parcelweight;
	
	public:
			//Constructor
		Clerk(){
			
			name="\0";
			phoneno="\0";
			parcelweight=0.0;
			
		}
		
		//SETTER AND GETTER
		
		//FOR name
		void setname(string name){
			this->name=name;		
		}
		
		string getname(){
			return this->name;
		}
		
		//For phoneno
			void setphoneno(string phoneno){
			this->phoneno=phoneno;		
		}
		
		string getphoneno(){
			return this->phoneno;
		}
		
		//For Parcelweight
			void setparcelweight(double parcelweight){
			this->parcelweight=parcelweight;		
		}
		
		double getparcelweight(){
			return this->parcelweight;
		}
	
		double Price(double weight){
			
			double stampprice=0;
			if(weight<5){
				
				stampprice = 5; 
			}
			
			else if(weight>4 && weight<10){
				stampprice = 10; 
			}
			
			else if(weight>9 && weight<20){
				stampprice = 20; 
			}
			
			
			else if(weight>19 && weight<50){
				stampprice = 50; 
			}
			
			else
			stampprice=100;
			
			return stampprice;
		}
			
};


class Postman : public PostalWorker
{
	string name;
	string phoneno;
	double noofdeliver;
	
	public:
			//Constructor
		Postman(){
			
			name="\0";
			phoneno="\0";
			noofdeliver=0.0;
			
		}
		
		//SETTER AND GETTER
		
		//FOR name
		void setname(string name){
			this->name=name;		
		}
		
		string getname(){
			return this->name;
		}
		
		//For phoneno
			void setphoneno(string phoneno){
			this->phoneno=phoneno;		
		}
		
		string getphoneno(){
			return this->phoneno;
		}
		
		//For noofdeliver
			void setnoofdeliver(double noofdeliver){
			this->noofdeliver=noofdeliver;		
		}
		
		double getnoofdeliver(){
			return this->noofdeliver;
		}
	
		
		
};


////////////////////////////////////ACCOUNT OFFICER/////////////////////////

class AccountOfficer : public PostalWorker
{
	string name;
	string phoneno;
	double parcelweight;
	
	public:
			//Constructor
		AccountOfficer(){
			
			name="\0";
			phoneno="\0";
			parcelweight=0.0;
			
		}
		
		//SETTER AND GETTER
		
		//FOR name
		void setname(string name){
			this->name=name;		
		}
		
		string getname(){
			return this->name;
		}
		
		//For phoneno
			void setphoneno(string phoneno){
			this->phoneno=phoneno;		
		}
		
		string getphoneno(){
			return this->phoneno;
		}
		
		//For Parcelweight
			void setparcelweight(double parcelweight){
			this->parcelweight=parcelweight;		
		}
		
		double getparcelweight(){
			return this->parcelweight;
		}
	
		double Price(double weight){
			
			double total=0;
			if(weight<5){
				total = 1500; 
			}
			
			else if(weight>4 && weight<10){
				total = 3000; 
			}
			
			else if(weight>9 && weight<20){
				total = 5000; 
			}
			
			
			else if(weight>19 && weight<50){
				total = 10000; 
			}
			
			else
			total=20000;
			
			return total;
		}	
};

class Payment 
{	
	
	double PayAmount;
	AccountOfficer* a_officer;
	
	public:
		
		//Constructor
		Payment(AccountOfficer *aoff){
			a_officer = aoff;
			
		}
		
		//SETTER AND GETTER
		
		void setPayAmount(double PayAmount){
			this->PayAmount=PayAmount;		
		}
		
		double getPayAmount(){
			return this->PayAmount;
		}
		
		//Function for showing Total Amount
		void paymentDetails(){
				
				cout<<"Payment for your Parcel: "<<this->getPayAmount()<<endl;
		}

};

class TransactionRecord
{
	int TransactionId;
	double totalamount;

	
	public:
				//Constructor

		TransactionRecord(){
			
			TransactionId=0;
			totalamount=0;
		}
				//Parametarize Constructor

		TransactionRecord(int TransactionId,double totalamount){
			this->TransactionId=TransactionId;
			this->totalamount=totalamount;
		}
				
		//SETTER AND GETTER
		
		void setTransactionId(int TransactionId){
			this->TransactionId=TransactionId;		
		}
		
		int getTransactionId(){
			return this->TransactionId;
		}
		

};



int main(){
	
		GPO g;
		
	PostOffice pf;
	PostalWorker pw;
	AccountOfficer af;
	Clerk cl;
	Postman ps;

//	Payment *p= new Payment(&AccountOfficer);
	
	cout<<"\n\t\tWELCOME PASKISTAN POST SERVICE"<<endl;
	
	int status,position;
	string username,password;
	
	string gn,gc;
	cout<<"Enter Name of PostOffice: "<<endl;
	getline(cin,gn);
	g.setGPOname(gn);
	
	cout<<"Enter Name of City: "<<endl;
	getline(cin,gc);
	g.setGPOcity(gc);
	
		
	cout<<"\nSelect your status: "<<endl;
	cout<<"1. Employee\n2. Customer"<<endl;
	cin>>status;
	
	
		/////////////////Employee//////////////
	if(status==1)
	{
	//////////////////////////USERNAME AND PASSWORD FILE///////////////////////	
		ofstream Login ("Login.txt", ios::app);
			if (Login.is_open())
		{
	   
	    {
	    	cout<<"LOGIN ACCOUNTS"<<endl;
	    	
	    	cout<<"Enter UserName: "<<endl;
	        cin>>username;
			pf.setusername(username);
	    
	    	cout<<"Enter Password: "<<endl;
			cin>>password;
			pf.setpassword(password);
			
		   Login <<"\nUsername: "<<pf.getusername()<<"\nPassword: "<<pf.getpassword()<<"\n";
	       cout<<"\n";
	    }
			Login.close();
		}
		else
			cout << "Unable to open file";
//	*********************************************************************************
		
		cout<<"Select your Position: "<<endl;
		cout<<"1. Postman.\n2. Clerk.\n3. AccountOfficer."<<endl;
		cin>>position;
		
		switch (position)
		{

////////////////Postman///////////////

			case 1:	
				
				////////////////Postman///////////////

				
				{
				
				string n,pn;
				int weight;
					
				cout<<"Enter Your Name: ";
				cin>>n;
				ps.setname(n);
				
				cout<<"Enter Your Phone No: ";
				cin>>pn;
				ps.setphoneno(pn);
				
				cout<<"Enter Delivered Parcels: ";
				cin>>weight;
				ps.setnoofdeliver(weight);	
					
				//////////////////////////Clerk Record//////////////////////	
				ofstream Postman ("Postman.txt", ios::app);
				if (Postman.is_open())
				{
			   
			    {
				    
			  		Postman <<"\nName: "<<ps.getname()<<"\nPhone No: "<<ps.getphoneno()<<"\nDelivered Parcels in a day: "<<ps.getnoofdeliver()<<"\n";
			  		
		      		cout<<"\n";
			    }
					Postman.close();
				}
				else
				{
					cout << "Unable to open file";
				}	
		//	*********************************************************************************	
					}
				
				
				
					break;

////////////////Clerk///////////////////////////////
		
			case 2:
				
			{
				string n,pn;
				int weight;
					
				cout<<"Enter Your Name: ";
				cin>>n;
				cl.setname(n);
				
				cout<<"Enter Your Phone No: ";
				cin>>pn;
				cl.setphoneno(pn);
				
				cout<<"Enter Parcel Weight: ";
				cin>>weight;
				cl.setparcelweight(weight);	
					
				//////////////////////////Clerk Record//////////////////////	
				ofstream Clerk ("Clerk.txt", ios::app);
				if (Clerk.is_open())
				{
			   
			    {
				    
			  		Clerk <<"\nName: "<<cl.getname()<<"\nPhone No: "<<cl.getphoneno()<<"\nWeight: "<<cl.getparcelweight()<<"\nTotal Price of Stamped: "<<cl.Price(cl.getparcelweight())<<"\n";
			  		
		      		cout<<"\n";
			    }
					Clerk.close();
				}
				else
				{cout << "Unable to open file";
					}	
		//	*********************************************************************************	
					}
						break;
			
////////////////Account officer///////////////
			case 3:
				
			{
					
				string n,pn;
				int weight;
					
				cout<<"Enter Your Name: ";
				cin>>n;
				af.setname(n);
				
				cout<<"Enter Your Phone No: ";
				cin>>pn;
				af.setphoneno(pn);
				
				cout<<"Enter Parcel Weight: ";
				cin>>weight;
				af.setparcelweight(weight);	
				
					
		//////////////////////////Transaction Record//////////////////////	
				ofstream TransactionRecord ("TransactionRecord.txt", ios::app);
				if (TransactionRecord.is_open())
				{
			   
			    {
				    cout<<"TransactionRecord"<<endl;
			  		TransactionRecord <<"\nName: "<<af.getname()<<"\nPhone No: "<<af.getphoneno()<<"\nWeight: "<<af.getparcelweight()<<"\nTotal Price: "<<af.Price(af.getparcelweight())<<"\n";
		      		cout<<"\n";
			    }
					TransactionRecord.close();
				}
				else
				{cout << "Unable to open file";
					}	
		//	*********************************************************************************
		}
					
					break;		
					
					
			default:
			
				cout<<"Enter Correct Option"<<endl;
				break;				
		}
		
		
		
		
		}
 		/////////////////Customer//////////////
	
	else if(status==2){
		
	Address A;
	Customer C;
	
	cout<<"CUSTOMER DETAIL"<<endl;
	ofstream CUSTOMER ("Customer.txt", ios::app);
	
	int h,s,id;
	string c,name,y;
		
	if (CUSTOMER.is_open())
	{
	   
	    {
	    	
	    	
		   cout<< "Enter Customer Id: "<<endl;
	       cin >> id;
	       C.setcust_id(id);
	       
	       	cout<< ""<<endl;
	        getline(cin,y);
	       
		   cout<< "Enter Customer Name: "<<endl;
	       getline(cin,name);
	       C.setcust_name(name);
	       
		   cout<< "Enter House No: "<<endl;
	       cin>>h;
	       A.sethouse_no(h);
	       
		   cout<< "Enter Street No: "<<endl;
	       cin >> s;
	       A.setstreet_no(s);
	       
	       	cout<< ""<<endl;
	        getline(cin,y);
	        
	       cout<< "Enter City: "<<endl;
	       getline(cin,c);
	       A.setcity(c);
	       
		   CUSTOMER <<C.getcust_id()<<"\t"<<C.getcust_name()<<"\t"<< A.gethouse_no()<<"\t"<<A.getstreet_no()<<"\t"<<A.getcity()<<"\n";
	       cout<<"\n";
	   }
	CUSTOMER.close();
	}
	else
	cout << "Unable to open file";
	
	//Order Obj when created and then object of customer or invoice is deleted than order is also deleted.
	
	Order o;
	
	
	
	Invoice I;
	cout<<"INVOICE DETAIL\n"<<endl;
	ofstream Invoice ("Invoice.txt", ios::app);
	
	int order;
	double w;
	string s_add,r_add,s_contact,r_contact,r_name,x;
		
	if (Invoice.is_open())
	{
	   
	    {
	    	cout<"\nINVOICE DETAIL\n";
	    	
	    	cout<<"Enter Order ID: "<<endl;
	        cin>>order;
			o.setOrderId(order);
	    	
			cout<< "Enter Weigth of Parcel in (gram): "<<endl;
	        cin>>w;
	        I.setweight(w);
		   	
		   	cout<< ""<<endl;
	        getline(cin,x);
	        
		   cout<< "Enter Receiver Name: "<<endl;
	       getline(cin,r_name);
	       I.setReceivername(r_name);
   
		   cout<< "Enter Sender Address: "<<endl;
	       getline(cin,s_add);
	       I.setAddressSender(s_add);
	       
		   cout<< "Enter Receiver Address: "<<endl;
	       getline(cin,r_add);
	       I.setAddressReceiver(r_add);
	       
	       cout<< "Enter Sender Contact Number: "<<endl;
	       getline(cin,s_contact);
	       I.setContactSender(s_contact);
	       
	       cout<< "Enter Reciever Contact Number: "<<endl;
	       getline(cin,r_contact);
	       I.setContactReceiver(r_contact);
	       
	
	       
		   Invoice <<"\nReceiver Name: "<<I.getReceivername()<<"\nParcel Weigth: "<<I.getweight()<<"\nSender Address: "<<I.getAddressSender()<<"\nReceiver Address: "<<I.getAddressReceiver()<<"\nSender Contact: "<<I.getContactSender()<<"\nReceiver Contact: "<<I.getContactReceiver()<<"\n";
	       cout<<"\n";
	   }
			Invoice.close();
		}
			else
			cout << "Unable to open file";
	
	}
	
	
	
	
	
	
	//****************************************MAILS MAIN***************************
		Mail m;
	MailService ms;
	int price;
	cout<<"Enter Price of Mail: "<<endl;
	cin>>price;
	ms.setmailprice(price);
	
	int temp=ms.getmailprice();
	cout<<"\nPrice of Mails: "<<ms.CheckMailService(temp)<<endl;
	
	int check;
	
	cout<<"\nWhich your want to check: "<<endl;
	cout<<"\n1. Bounced or Returned mails\n2. Urgent or Regular mails"<<endl;
	cin>>check;
	
if(check==1){

/////////	*********************************CHECKING BOUNCED AND RETURNED MAILS****************************
	srand(time(0));
	int result;
	

	
	if(m.checkmail()==1){
		cout<<"\nBounced Mails: "<<(rand() % 20) + 1<<endl;
	}
	
	
	if(m.checkmail()==2){
		cout<<"\nReturned Mails: "<<(rand() % 20) + 1<<endl;
	}
	
///////////////////////////////////////**************************************//////////////////////////////////	
	
}		
	
if(check==2)
{		
/////////	*********************************CHECKING Urgent AND Regular MAILS****************************

	srand(time(0));
	int r;
	
	if(ms.check()==1){
		cout<<"\nUrgent Mails: "<<(rand() % 20) + 1<<endl;
	}
	
	
	if(ms.check()==2){
		cout<<"\nRegular Mails: "<<(rand() % 20) + 1<<endl;
	}
}
//**************************************MAILS/////////////////////////////////////////////////
	
		
	return 0;
}
