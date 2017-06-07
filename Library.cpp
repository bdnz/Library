
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
class Customer{
	string  name,
		ID;
	int 	booksPurchased;
	float	amountSpent;

public:
	Customer();					//  constructor
	Customer(string name, string ID, int booksPurchased, float amountSpent);					
	void setRecord();			// set the customer record
	void updateRecord();		//	update customer record
	void getRecord();			//	print customer record
	int	 getBooksPurchased();	// get number of books purchased by customer
	float getAmountSpent();		// get amount spent  
	bool matchID(string ID);
	void purchase(float price);
};

class Book{
	string title,					// holds title of book
		publisher,				// holds publisher name
		*aurthors,				// holds names of aurthors of book
		ISBN;					// holds ISBN number of book

	int numOfAurthors,				// holds number of authors of book
		yearOfPublication,			// holds year of publication
		numOfCopies;				// holds number of copies of book in store

	float price;

public:
	Book(); 	
	Book(string name, float price, string aurthor1, string aurthor2, string aurthor3, string aurthor4, string publisher, int year, string ISBN, int books); 		
	Book(string name, float price, string aurthor1, string aurthor2, string aurthor3, string publisher, int year, string ISBN, int books); 		
	Book(string name, float price, string aurthor1, string aurthor2, string publisher, int year, string ISBN, int books); 	
	Book(string name, float price, string aurthor1, string publisher, int year, string ISBN, int books); 	
	void setInfo();		// set info about the book
	void updateInfo();	//	Update info about the book
	void getInfo();		// print information about book
	bool matchTitle(string);	// To determine if a given title is the same as the title of the book.
	bool matchISBN (string);	// To determine is a given ISBN is the same as the ISBN of the book.
	void purchase();			// purchase as non member
	void purchaseAsMember(Customer& member);	// purchase as member
};

Book::Book()
{
	aurthors = NULL;
	title = publisher = ISBN = "";
}
Book::Book(string name, float price, string aurthor1, string aurthor2, string aurthor3, string publisher, int year, string ISBN, int books)
{
	aurthors = new string[3];
	numOfAurthors = 3;
	this->title = name;
	this->price = price;
	this->aurthors[0] = aurthor1;
	this->aurthors[1] = aurthor2;
	this->aurthors[2] = aurthor3;
	this->publisher   = publisher;
	this->yearOfPublication = year;
	this->ISBN = ISBN;
	this->numOfCopies = books;
}

Book::Book(string name, float price, string aurthor1, string aurthor2, string aurthor3, string aurthor4, string publisher, int year, string ISBN, int books) 		// constructor with four aurthors
{
	aurthors = new string[4];
	numOfAurthors = 4;
	this->title = name;
	this->price = price;
	this->aurthors[0] = aurthor1;
	this->aurthors[1] = aurthor2;
	this->aurthors[2] = aurthor3;
	this->aurthors[3] = aurthor4;
	this->publisher   = publisher;
	this->yearOfPublication = year;
	this->ISBN = ISBN;
	this->numOfCopies = books;
}
Book::Book(string name, float price, string aurthor1, string aurthor2, string publisher, int year, string ISBN, int books)
{
	aurthors = new string[2];
	numOfAurthors = 2;
	this->title = name;
	this->price = price;
	this->aurthors[0] = aurthor1;
	this->aurthors[1] = aurthor2;
	this->publisher   = publisher;
	this->yearOfPublication = year;
	this->ISBN = ISBN;
	this->numOfCopies = books;	
}
Book::Book(string name, float price, string aurthor1, string publisher, int year, string ISBN, int books)
{
	aurthors = new string[1];
	numOfAurthors = 1;
	this->title = name;
	this->price = price;
	aurthors[0] = aurthor1;
	this->publisher   = publisher;
	this->yearOfPublication = year;
	this->ISBN = ISBN;
	this->numOfCopies = books;

}

void Book::setInfo()
{
	cout << "Enter title of book: ";
	getline(cin, title);	

	cout << "Enter price of book: ";
	cin  >> price;
	cout << "Enter number of aurthors of book: ";
	do{
		cin  >> numOfAurthors;
		if (numOfAurthors < 0 || numOfAurthors > 4)
			cout << "Please enter a valid number of upto 4 aurthors: ";
	}while (numOfAurthors < 0 || numOfAurthors > 4);

	aurthors = new string[numOfAurthors];

	for (int i = 0; i < numOfAurthors; i++)
	{
		cout << "Enter name of aurthor " << numOfAurthors + 1 << " : ";
		getline(cin, aurthors[i]);
	}

	cout << "Enter name of publisher: ";
	getline (cin, publisher);

	cout << "Enter year of publication: ";
	cin  >> yearOfPublication;

	cout << "Enter ISBN number: ";
	getline(cin, ISBN);

	cout << "Enter number of copies in Stack: ";
	cin  >> numOfCopies;

	cout << "Information Collected successfuly!" << endl<<endl;
}

void Book::updateInfo()
{
	int choice;
	cout << "\t\tUpdate Info" << endl;
	cout << "1. Update Title" << endl
		<< "2. Update Price" << endl
		<< "3. Update ISBN" << endl;

	cin  >> choice;
	switch(choice)
	{
	case 1:
		cout << "Enter new title of book: ";
		getline (cin, title);
		break;
	case 2:
		cout << "Enter new price of book: ";
		cin  >> price;
		break;
	case 3:
		cout << "Enter new ISBN of book: ";
		getline(cin, ISBN);
	default:
		cout << "Invalid Choice!" << endl<<endl;
	}
}
void Book::getInfo()
{
	cout << "\t\tBook Information!" << endl;
	cout << "Title: " << title << endl
		<< "Price: " << price << endl
		<< "Number of copies: " << numOfCopies << endl
		<< "ISBN: " << ISBN << endl
		<< "Publisher: " << publisher << endl
		<< "publishing Year: " << yearOfPublication << endl
		<< "Names of Aurthors: " << endl;
	for (int i = 0; i < numOfAurthors; i++)
		cout << "\t" << i+1 << ". " << aurthors[i] << endl; 
}
bool Book::matchTitle(string t)
{
	if (title == t)
		return true;
	else
		return false;
}
bool Book::matchISBN (string isbn)
{
	if (ISBN == isbn)
		return true;
	else
		return false;
}

void Book::purchase()
{
	if(numOfCopies > 0)
	{
		cout << "Book is not avaliable in Stock!" << endl<<endl;
		return;
	}

	
	numOfCopies--;
	cout << "Book purchased on " << price << endl<<endl;
}


void Book::purchaseAsMember(Customer& member)
{
	if(numOfCopies = 0)
	{
		cout << "Book is not avaliable in Stock!" << endl<<endl;
		return;
	}

	// else
	// decreases the number of copies in store
	numOfCopies--;
	member.purchase(price);
}


Customer::Customer()
{
	name = ID = "";
	booksPurchased = amountSpent = 0;
}

Customer::Customer(string name, string ID, int booksPurchased, float amountSpent)
{
	this->name = name;
	this->ID   = ID;
	this->booksPurchased = booksPurchased;
	this->amountSpent = amountSpent; 
}

void Customer::setRecord()
{
	cout << "Enter Customer ID: ";
	getline(cin, ID);
	cout << "Enter customer name: ";
	getline(cin, name);
	cout << "Enter number of books purchased by customer: ";
	cin  >> booksPurchased;
	cout << "Enter amount spent by user: ";
	cin  >> amountSpent;
}

void Customer::updateRecord()
{
	int choice;
	cout << "\t\tUpdate Record!" << endl;
	cout << "1. Update Customer ID" << endl
		<< "2. Update Customer Name" << endl
		<< "3. Update Customer's books purchased " << endl
		<< "4. Update Customer's amount spent " << endl;
	cin >> choice;

	switch(choice)
	{
	case 1:
		cout << "Enter customer's new ID: ";
		getline(cin, ID);
		break;
	case 2:
		cout << "Enter customer's new name: ";
		getline(cin, name);
		break;
	case 3:
		cout << "Enter customer's new number of books purchased: ";
		cin  >> booksPurchased;
		break;
	case 4:
		cout << "Enter customer's new amount spent: ";
		cin  >> amountSpent;
		break;
	default:
		cout << "Please choose a valid value!";
	}
}

void Customer::getRecord()
{
	cout << "\t\tCustomer Information!" << endl
		<< "Name: " << name << endl
		<< "ID: " << ID  << endl
		<< "number of Books Purchased: " <<  booksPurchased << endl
		<< "Total amount Spent: " <<  amountSpent << endl;
}

int Customer::getBooksPurchased()
{
	return booksPurchased;
}
float Customer::getAmountSpent()
{
	return amountSpent;
}

bool Customer::matchID(string ID)
{
	if(this->ID == ID)
		return true;
	else 
		return false;
}

void Customer::purchase(float price)
{


	// 5% discount on book for members
	price -= (price * 0.05);
	booksPurchased++;


	// if being purchased is 11th book
	if (booksPurchased % 11 == 0)
	{
		
		// calculate the discount from average of last 10 purhcases
		int discount = amountSpent/10;

		// apply discount from price
		price -= discount;

		// reset the total amount spent to 0
		amountSpent = 0;

		cout << "Book Purchase successful on price " << price << " with discount of average from last 10 books" << endl<<endl;
	}
	else
	{
		amountSpent += price; 
		cout << "Book Purchase successful on price " << price << " with 5% discount" << endl<<endl;
	}
}

int main()
{
	Book books[1000]; // can hold 1000 books


	Customer customers[500];  // can hold 500 customers


	string custID, 
		bookTitle,
		bookISBN;

	int choice,
		bookIndex = 20,
		customerIndex = 10,
		bookMatchIndex,
		customerMatchIndex,
		bookPrice;

	
	bool found;
	books[0] = Book("Book1", 20.93, "Charles Dickens", "Chapman & Hall", 1859, "9780192545220", 12);
	books[1] = Book("Book2", 20.0, "J. R. R. Tolkien", "Mariner Books", 1954,"0618640150", 3);
	books[2] = Book("Book3", 25.4, "J. R. R. Tolkien", "Alan Lee", 1937, "1481172301", 33);
	books[3] = Book("Book4", 15.95, "Tsao Hsueh-Chin ", "Anchor", 1958, "0385093799", 0);
	books[4] = Book("Book5", 6.9, "Agatha Christie", "Mass Market Paperback", 2011, "0062073486", 0);
	books[5] = Book("Book6",15.00, "C. S. Lewis", "Pauline Baynes", "HarperCollins", 2008, "0064404994", 0);
	books[6] = Book("Book7", 5.99, "H. Rider Haggard", "CreateSpace Independent Publishing Platform", 2015, "1515389243", 10 );
	books[7] = Book("Book8", 11.00, " Antoine de Saint-Exupery", "Richard Howard", "Mariner Books", 2000, "0156012197", 10 );
	books[8] = Book("Book9", 9.99, "Dan Brown", "Anchor", 2009, "0307474275", 5);
	books[9] = Book("Book10", 23.56, "Eduardo	Lyons", "Back Bay Books", 2012, "0316769177", 42);
	books[9] = Book("Book11", 13.67, "Elena	Bates","Bernadette	Arnold", "goldenfix", 2007, "0385093712", 31);
	books[10] = Book("Book12", 98.00, "John	Hicks", "Back Bay Books", 2003, "2340093723", 3);
	books[11] = Book("Book13", 134.87, "Emily	Higgins", "Emily	Higgins", "Mariner Books", 2013, "3019093734", 23);
	books[12] = Book("Book14", 78.3, "Nelson	Cortez", "Mass Market Paperback", 2015, "9473093745", 14);
	books[13] = Book("Book15", 12.54, "Maureen	Brown", "Back Bay Books", 1991, "4583093756", 25);
	books[14] = Book("Book16", 15.96, "Patti	Hunter", "Tsao Hsueh-Chin", "Mass Market Paperback", 1996, "9520093767", 23);
	books[15] = Book("Book17", 7.00, "Mitchell	Mckinney", "Back Bay Books", 1890, "5207093778", 74);
	books[16] = Book("Book18", 54.98, "Shawna	Washington", "CreateSpace Independent Publishing Platform", 2005, "4563093789",4);
	books[17] = Book("Book19", 34.43, "Wanda	Hampton", "Back Bay Books", 2004, "7856093798", 12);
	books[18] = Book("Book20", 7.99, "Tommie Goodman", "Indifix", 1962, "4569093652", 0);

	customers[0] = Customer("Deniz", "1234", 2, 18.96);
	customers[1] = Customer("Moha", "1235", 3, 12.85);
	customers[2] = Customer("Samantha", "1236", 12, 45.99);
	customers[3] = Customer("Alison", "1237", 4, 26);
	customers[4] = Customer("Zack", "1238", 5, 25.23);
	customers[5] = Customer("Matthew", "1239", 7, 56.54 );
	customers[6] = Customer("Kang", "1230", 23, 256.23);
	customers[7] = Customer("Ali", "1233", 14, 129.54);
	customers[8] = Customer("Jocelin", "1232", 0, 0);
	customers[9] = Customer("Liana", "1231", 3, 96.34);

	/*Here is the cases, I wrote them down with pseudocode assignment  */

	do{
		system("cls");
		cout << "1. Add a book" << endl
			<< "2. Add a member" << endl
			<< "3. Purchase Book as a member" << endl
			<< "4. Purchase Book as non-member" << endl
			<< "5. Search Book by ISBN" << endl
			<< "6. Search Book by title" << endl;

		cin  >> choice;

		switch(choice)
		{
		case 1:		// add Book



			books[bookIndex++].setInfo();
			break;
		case 2:		// add new customer


			customers[customerIndex++].setRecord();
		
			
			break;



		case 3:		// purchase book as member


			cout << "Enter customer ID: ";
			cin  >> custID;
			found = false;


			// check if member exists or not
			for (int i=0; i < customerIndex && !found; i++)
				if(customers[i].matchID(custID))
				{
					found = true;
					customerMatchIndex = i;
				}

				// customer found
				if (found)
				{

					do{
						
						cout << "1. Search book by Name" << endl
							<< "2. Search book by ISBN" << endl;
						cin  >> choice;

						// if invalid choice entered
						if(choice != 1 && choice != 2)
							cout << "Enter a valid choice" << endl;
					}while (choice != 1 && choice != 2);

					found = false;

					if (choice == 1)

					{// search by title

						cout << "Enter book title: ";
						cin  >> bookTitle;

						

						for (int i=0; i < bookIndex && !found; i++)
							if(books[i].matchTitle(bookTitle))
							{
								found = true;
								bookMatchIndex = i;
							}
					}
					// seach by ISBN 


					else if (choice == 2)
					{
						cout << "Enter ISBN of book: ";
						cin  >> bookISBN;

						// search for book in record

						for (int i=0; i < bookIndex &&
							!found; i++)
							if(books[i].matchISBN(bookISBN))
							{
								found = true;
								bookMatchIndex = i;
							}
							
					}
					// if book found
					if (found)

					{// let user to purchase the book
						// check if book available in stock or not
						// purchase the book and get price in variable

						books[bookMatchIndex].purchaseAsMember(customers[customerMatchIndex]);

						cout << "Book Purchased";

					}
					else // display book not found message
						cout << "Book not found!";

					break;


		case 4:		// purchase book as non member
			do{
				// let customer to search book

				cout << "1. Search book by Name" << endl
					<< "2. Search book by ISBN" << endl;
				cin  >> choice;

				// if incalid choice entered

				if(choice != 1 && choice != 2)
					cout << "Enter a valid choice" << endl;
			}while (choice != 1 && choice != 2);
			if (choice == 1)

			{// search by title

				cout << "Enter book title: ";
				cin  >> bookTitle;
				
				found = false;

				// search for book in record

				for (int i=0; i < bookIndex && !found; i++)
					if(books[i].matchTitle(bookTitle))
					{
						found = true;
						bookMatchIndex = i;
					}
					// if book found
					if (found)

					{
						cout << "Book Purchased"<<endl<<endl;
					}
					else 
						// display book not found message
						cout << "Book not found!"<<endl;
			}

			// seach by ISBN 
			else if (choice == 2)
			{
				cout << "Enter ISBN of book: "<<endl;
				cin  >> bookISBN;
				found = false;

				// search for book

				for (int i=0; i < bookIndex && !found; i++)
					if(books[i].matchISBN(bookISBN))
					{
						found = true;
						bookMatchIndex = i;
					}

					// book found
					if (found)
					{
						cout << "Purchase Book"<<endl;
					}
					else
						cout << "Book not found!"<<endl;
			}
			break;
		case 5:
			cout << "Enter ISBN of book: "<<endl;
			cin  >> bookISBN;
			found = false;
			for (int i=0; i < bookIndex && !found; i++)
				if(books[i].matchISBN(bookISBN))
				{
					found = true;
					bookMatchIndex = i;
				}
				if (found)
					cout << "Book Found!"<<endl;
				else
					cout << "Book not found!"<<endl;
				break;
		case 6:
			cout << "Enter book title: "<<endl;
			cin  >> bookTitle;
			found = false;
			for (int i=0; i < bookIndex && !found; i++)
				if(books[i].matchTitle(bookTitle))
				{
					found = true;
					bookMatchIndex = i;
				}
				if (found)
					cout << "Book Found!"<<endl;
				else
					cout << "Book not found!"<<endl;
				break;
		default:
			cout << "Invalid Choice!"<<endl;
				}
		}
		system("pause");
	}while(true);

	return 0;	
}
