#include <iostream>
#include <fstream>

using namespace std;

class shopping  //creating a shopping class for the user & seller 
{
	private: //local variables of the particular product 
		int productcode;
		float price;
		float dis;
		string productname;
		
		public: //functions to be used inside class shopping 
			void menu(); //main menu to select first options to start the system 
			void administrator(); //seller function where buyer can see list of available products in this system 
			void buyer(); 
			void add(); //add the product 
			void edit(); //edit any detail entered 
			void rem(); //delete the product from this system
			void list(); //display all the products available 
			void receipt(); //details of buyer's shopping with its total cost 
			
};

void shopping :: menu() //function to show all main activities user can perform 
{
	m:
	int choice;
	string email;
	string password;
	
	cout<<"\t\t\t\t______________________________________\n";
	cout<<"\t\t\t\t                                      \n";
	cout<<"\t\t\t\t          Supermarket Main Menu       \n";
	cout<<"\t\t\t\t                                      \n";
	cout<<"\t\t\t\t______________________________________\n";
	cout<<"\t\t\t\t                                      \n";
	cout<<"\t\t\t\t|  1) Administrator   |\n";
	cout<<"\t\t\t\t|                     |\n";
	cout<<"\t\t\t\t|  2) Buyer           |\n";
	cout<<"\t\t\t\t|                     |\n";
	cout<<"\t\t\t\t|  3) Exit            |\n";
	cout<<"\t\t\t\t|                     |\n";
	cout<<"\n\t\t\t Please select!";
	cin>>choice;
	
	switch(choice)
	{
		case 1: //enter login details as a seller of products to start this system 
			cout<<"\t\t\t Please Login \n";
			cout<<"\t\t\t Enter Email   \n";
			cin>>email;
			cout<<"\t\t\t Enter Password \n";
			cin>>password;
			
			if(email=="robby@gmail.com" && password=="robby@123")
			{
				administrator();
			}
			else
			{
				cout<<"Invalid email or password!";
			}
			break;
	
	case 2:
		{
			buyer(); //buyer function 
            break;
		}
	
	case 3:
		{
			exit(0); //end the process 
            break;
		}
		
		default :
			{
				cout<< "Please select from the given options";
                break;
			}
			
	
}
goto m; //jump start the function 
}

void shopping:: administrator() //seller function 
{
	m:
	int choice;
	cout<<"\n\n\n\t\t\t Administrator menu";
	cout<<"\n\t\t\t|_____1) Add the product_____|";
	cout<<"\n\t\t\t|                            |";
	cout<<"\n\t\t\t|_____2) Modify the product__|";
	cout<<"\n\t\t\t|                            |";
	cout<<"\n\t\t\t|_____3) Delete the product__|";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|_____4) Back to main menu___|";
    
    cout<<"\n\n\t Please enter your choice: "; //enter your choice as per requirement 
    cin>>choice;
    
    switch(choice) //call the function for respective action to perform 
    {
    	case 1:
    		add();
    		break;
    		
    	case 2:
    		edit();
    		break;
    		
    	case 3:
    		rem();
    		break;
    		
    	case 4:
    		menu();
    		break;
    		
    	default :
    		cout<<"Invalid choice!";
            break;
	}
	goto m; //jump start the function 
}

void shopping:: buyer()  //buyer function 
{
	m:
	int choice;
	cout<<"\t\t\t  Buyer \n";
	cout<<"\t\t\t_____________  \n";
	cout<<"                     \n";
	cout<<"\t\t\t1) Buy product \n";
	cout<<"                     \n";
	cout<<"\t\t\t2) Go back     \n";
	cout<<"\t\t\t Enter your choice: ";
	
	cin>>choice;
	
	switch(choice) //select required choice for the user 
	{
		case 1:
			receipt();
			break;
			
		case 2:
			menu();
            break;
			
		default :
			cout<<"Invalid choice";
            break;
	}
	goto m;
}

void shopping:: add() //this function acts as adding all the products
{
	m:
	fstream data;
	int c;
	int token=0;
	float p;
	float d;
	string n;
	
	cout<<"\n\n\t\t\t Add new product... ";  //add the number of products user wish and fill its details 
	cout<<"\n\n\t Product code of the product: ";
	cin>>productcode;
	cout<<"\n\n\t Name of the product: ";
	cin>>productname;
	cout<<"\n\n\t Price of the product: ";
	cin>>price;
	cout<<"\n\n\t Discount on product: ";
	cin>>dis;
	
	data.open("database.txt",ios::in); //read the file 
	
	if(!data)
	{
		data.open("database.txt", ios::app|ios::out); //append & write into file if it doesn't exist 
		data<<" "<<productcode<<" "<<productname<<" "<<price<<" "<<dis<<"\n"; //display every detail of particular product 
		data.close();
	}
	else
	{
		data>>c>>n>>p>>d;
		
		while(!data.eof()) //read file until end if its matches both the product codes and increment token by 1 
		{
			if(c == productcode)
			{
				token++;
				
			}
			data>>c>>n>>p>>d;
		}
		data.close();
		
	if(token==1) //if token is equal to 1 i.e. record is inserted then jump start the function else create file 
	  goto m;
	else{
		data.open("database.txt", ios::app|ios::out);
		data<<" "<<productcode<<" "<<productname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}
}
	cout<<"\n\n\t\t Record inserted !";
}

void shopping:: edit() //modify any detail if its wrong or update it
{
	fstream data, data1;
	int pkey; //product key for that product user wish to edit 
	int token=0;
	int c;
	float p;
	float d;
	string n;
	
	cout<<"\n\t\t\t Modify the record....";
	cout<<"\n\t\t\t Product code: ";
	cin>>pkey;
	
	data.open("database.txt",ios::in); //read file 
	if(!data)
	{
		cout<<"\n\nFile doesn't exist! ";
	}
	else{
		
		data1.open("database1.txt", ios::app|ios::out); // append & write in file 
		
		data>>productcode>>productname>>price>>dis;
		while(!data.eof()) //read the file & if product code and product key i.e. code only matches for the edit then write new details 
		{
			if(pkey == productcode)
			{
				cout<<"\n\t\t Product new code: ";
				cin>>c;
				cout<<"\n\t\t Name of the product: ";
				cin>>n;
				cout<<"\n\t\t Price: ";
				cin>>p;
				cout<<"\n\t\t Discount: ";
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\n\t\t Record edited !!";
				token++;
			}
			else
			{
				data1<<" "<<productcode<<" "<<productname<<" "<<price<<" "<<dis<<"\n"; //show all the products as before when not edited 
				
			}
			data>>productcode>>productname>>price>>dis;
		}
		data.close();
		data1.close();
		
		remove("database.txt"); //remove original file  
		rename("database1.txt","database.txt"); //rename temporary file used to edit a detail/s in file as original one 
		
		if(token==0) //if token is 0 i.e. false then no record is found on that product code that user entered 
		{
			cout<<"\n\n Record not found sorry!";
		}
	}	
}
void shopping:: rem() //delete a product from the file 
{
	
	fstream data, data1;
	int pkey;
	int token=0; //a boolean flag to know entered data is deleted or not 
	cout<<"\n\n\t Delete product...";
	cout<<"\n\n\t Product code: "; //enter the code for product user wish to delete from list 
	cin>>pkey;
	data.open("database.txt", ios::in); //read from file 
	if(!data)
	{
		cout<<"File doesnt exist";
		
	}
	
	else{
		data1.open("database1.txt",ios::app|ios::out); //append & write file function 
		data>>productcode>>productname>>price>>dis;
		while(!data.eof())
		{
			if(productcode == pkey) //if the product code that is entered one and one present already in the list matches then delete that product 
			{                       //increment the token by 1 
				cout<<"\n\n\t Product deleted succesfully";
				token++;
			}
			else
			{
				data1<<" "<<productcode<<" "<<productname<<" "<<price<<" "<<dis<<"\n"; //show all product list in temporary file 
				
			}
			data>>productcode>>productname>>price>>dis;
		}
		data.close();
		data1.close();
		remove("database.txt"); //remove original file 
		rename("database1.txt","database.txt"); //rename temporary file with all the products except deleted into original file 
		
		if(token==0) //if its 0 no product present in the file 
		{
			cout<<"\n\n Record not found";
		}
	}
}

void shopping:: list() //show all the available products with its details in the file 
{
	fstream data;
	data.open("database.txt",ios::in); //read from file 
	cout<<"\n\n|___________________________________________________________\n";
	cout<<"ProNo\t\tName\t\tPrice\n";
	cout<<"\n\n|___________________________________________________________\n";
	data>>productcode>>productname>>price>>dis; //display every product 
	while(!data.eof()) //read till end and show all the products 
	{
		cout<<productcode<<"\t\t"<<productname<<"\t\t"<<price<<"\n";
		data>>productcode>>productname>>price>>dis;
		
	}
	data.close();
}

void shopping:: receipt() 
	{
		system("cls");
		fstream data;
		//local variables 
		int arrcode[100], arrquantity[100]; //two arrays to store all codes and quantity of each product 
		char choice;
		int c=0;
		float amount=0;
		float dis=0;
		float total=0;
		cout<<"\n\n\t\t\t Receipt... ";
		data.open("database.txt",ios::in); //read from file all product information 
		if(!data)
		{
			cout<<"\n\n Empty database";
		}
		else
		{
			data.close();                                   
			list(); //call the list function to display all products 
			cout<<"\n____________________________\n";
			cout<<"\n|                            |";
			cout<<"\n|    Please place the order  |";
			cout<<"\n|____________________________|\n";
			do
			{
				m:
				cout<<"\n\n Product Code: ";
				cin>>arrcode[c];
				cout<<"\n Product Quantity: ";
				cin>>arrquantity[c];
				for(int i=0;i<c;i++)
				{
					if(arrcode[c] == arrcode[i]) //if the code already present in file and code entered by user are same then its duplicacy
					{
						cout<<"\n\n Duplicate Product Code. Please try again!";
						goto m;
					}
				}
				c++;    //increment the counter (product code)            
				cout<<"\n\n Want to buy another product? Press y for yes and n for no: ";
				cin>>choice;	
			}
			
			while(choice == 'y'); //until user selects y the system will ask for a new product to enter 
			system("cls");
			
			cout<<"\n\n\t\t\t__________RECEIPT______________\n";
			cout<<"\nProduct Num.\tProduct Name\tQuantity \tPrice \tAmount \tAmount with discount\n"; //display the receipt 
			
			
			for(int i=0;i<c;i++)  //iterate through all counter (product codes) into the file 
			{
				data.open("database.txt",ios::in); //read from file 
				data>>productcode>>productname>>price>>dis;
				while(!data.eof()) //reach until end of file 
				{
					if(productcode == arrcode[i])    //if both the codes match then calculate its price, discount & total after discount on each product
					{
						amount = price * arrquantity[i];
						dis = amount - (amount * dis / 100);
						total = total + dis;
						cout<<"\n"<<productcode<<"\t\t"<<productname<<"\t\t"<<arrquantity[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;	
					}
					   data>>productcode>>productname>>price>>dis;   //show all products 
				}
				data.close();
			}
			cout<<"\n\n----------------------------------------";
			cout<<"\n Total Amount: "<<total;
		}
	}
int main()
{
	shopping s; //call the shopping class object by menu function 
	s.menu();
}

