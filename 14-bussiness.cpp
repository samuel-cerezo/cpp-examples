// time.cpp, Maggie Johnson
// Description:
/*
Your college book store needs your help in estimating its business for next year.
Experience has shown that sales depend greatly on whether a book is required for a
course or just optional, and whether or not it has been used in the class before. 
A new, required textbook will sell to 90% of prospective enrollment, but if it has been used in
the class before, only 65% will buy. Similarly, 40% of prospective enrollment will buy a
new, optional textbook, but if it has been used in the class before only 20% will buy.
(Note that "used" here does not mean second-hand books.)

Write a program that accepts as input a series of books (until the user enters a
sentinel). 
For each book ask for: 
    - a code for the book
    - the single copy cost for the book
    - the current number of books on hand
    - the prospective class enrollment
    - data that indicates if the book is required/optional, new/used in past. 

As output, show all the input information in a nicely formatted screen along with how many books 
must be ordered (if any, note that only new books are ordered), the total cost of each
order.
Then, after all input is complete, show the total cost of all book orders, and the
expected profit if the store pays 80% of list price. Since we have not yet discussed any
ways of dealing with a large set of data coming into a program (stay tuned!), just
process one book at a time and show the output screen for that book. Then, when the
user has finished entering all the data, your program should output the total and profit
values.
*/

#include <iostream>
#include <list>

using namespace std;
int codigo,numberOnHands,prospectiveEnrollment, finalOrder,required_int,nuevo_int;
double costOfCopy, costOfOrder;
bool required, nuevo;
double TotalAllOrders;

list<int> BooksCodes = {};
list<double> BooksCostCopies = {};
list<int> BooksNumberOnHands = {};
list<int> PerspectiveEnrollments = {};
list<bool> BooksRequired = {};
list<bool> BooksNew = {};


class Book {
    // list of attributes
    private:
        int code_;
        double copyCost_;
        int numberOnHands_;
        int prospectiveEnrollment_;
        bool required_;
        bool new_;
        int finalOrder_;    //(if any, note that only new books are ordered)
        double costOrder_;
        double percentageEnrollment_;
    // list of behavours or actions that this objects can do
    public:
        void Display();
        void New(int code, double cost, int NumberOnHands, int ProspectiveEnrollment, bool required, bool nuevo);
        void Order();
};

/*
***************************************************
Book: 1221
Price: $69.95
Inventory: 30
Enrollment: 150
This book is required and used.
*/

void Book::Order(){
    percentageEnrollment_ = 0.9*required_*new_ + 0.65*required_*(!new_) + 0.4*new_*(!required_) + 0.2*(!new_)*(!required_);
    finalOrder_ = int (prospectiveEnrollment_ * percentageEnrollment_) - numberOnHands_;
    costOrder_ = copyCost_ * finalOrder_;
    cout << "***************************************************" << endl;
    cout << "Need to order: " << finalOrder_ << endl;
    cout << "Total Cost: €" << costOrder_ << endl;
    TotalAllOrders += costOrder_;
}

void Book::Display(){
    cout << "***************************************************" << endl;
    cout << "Book: " << code_ << endl;
    cout << "Price: €" << copyCost_ << endl;
    cout << "Inventory: " << numberOnHands_ << endl;
    cout << "Enrollment: " << prospectiveEnrollment_ << endl;
    if(required_){
        cout << "The book is required ";
    }else{
        cout << "The book is optional ";
    }
    if(new_){
        cout << "and new." << endl;
    }else{
        cout << "and used." << endl;
    }
    cout << "***************************************************" << endl;

}

void Book::New(int code, double cost, int NumberOnHands, int ProspectiveEnrollment, bool required, bool nuevo){
    code_ = code;
    copyCost_ = cost;
    numberOnHands_ = NumberOnHands;
    prospectiveEnrollment_ = ProspectiveEnrollment;
    required_ = required;
    new_ = nuevo;
    // we add the new book to the list
    BooksCodes.push_back(code_);
    BooksCostCopies.push_back(copyCost_);
    BooksNumberOnHands.push_back(numberOnHands_);
    PerspectiveEnrollments.push_back(prospectiveEnrollment_);
    BooksRequired.push_back(required_);
    BooksNew.push_back(new_);
}



void introduction(){
    cout << "Hi! this programm will show you how many books must be ordered" << endl;
}



void enterData(){

    cout << "\nPlease enter the book code: ";
    cin >> codigo;
    cout << "single copy price: ";
    cin >> costOfCopy;
    cout << "number on hand: ";
    cin >> numberOnHands;
    cout << "prospective enrollment: ";
    cin >> prospectiveEnrollment;
    cout << "1 for reqd/0 for optional: ";
    cin >> required_int;
    if(required_int==1){
        required = true;
    }else{
        required = false;
    }
    cout << "1 for new/0 for used: ";
    cin >> nuevo_int;
    if(nuevo_int==1){
        nuevo = true;
    }else{
        nuevo = false;
    }
}

int main(){
    char next;
    int NumberOfBooks;
    introduction();
    // std::list<Type> list_name = {value1, value2, ...};

    do{
        Book book1;
        enterData();
        book1.New(codigo,costOfCopy,numberOnHands,prospectiveEnrollment,required,nuevo);
        book1.Display();
        book1.Order();
        cout << "Another book? (y/n): ";
        cin >> next;
        NumberOfBooks++;

    }while(next != 'n');

    cout << "***************************************************" << endl;
   // display the modified list
   cout << "Books entered: " << BooksCodes.size() << endl;
   cout << "Codes entered: ";
   cout << "[";
    for(int i : BooksCodes) {
        cout << i << ", ";
    }
    cout << "]";
    cout << "\nTotal for all orders: €";
    cout << TotalAllOrders << endl;
    return 0;

}