/*Task #10:
Design a program that maintains library book records using dynamic arrays.
=> Each row represents a category (e.g., Fiction, Science, History).
=> Each category has a different number of books (use a jagged array).
=> Store book IDs dynamically and allow the user to search for a given book ID.
=> Print whether the book is available and in which category.*/
#include<iostream>
using namespace std;
class Book
{
    string name;
    int id;
    public:
    Book()
    {
        name=" ";
        id=0;
    }
    Book(string name,int id):name(name),id(id){}
    int getid(){return id;}
    string getbookname(){return name;}
};
class Category
{
    string name;
    Book *books;
    int noOfbook;
    public:
    Category()
    {
        name =" ";
        noOfbook=0;
        books = nullptr;
    }
    Category(string name,int noOfbook,Book *b)
    {
     this->name = name;
    this->noOfbook = noOfbook;

    if(noOfbook > 0) {
        books = new Book[noOfbook];
        for(int i = 0; i < noOfbook; i++) {
            books[i] = b[i];  
        }
    } else {
        books = nullptr;
    }   
    }
    // void SearchBookId(int bookid)
    // {

    // }
    int getnoOfbooks(){return noOfbook;}
    string getcatename(){return name;}

     Category(const Category& other)
    {
        name = other.name;
        noOfbook = other.noOfbook;
        if (other.books && noOfbook > 0) {
            books = new Book[noOfbook];
            for (int i = 0; i < noOfbook; ++i) {
                books[i] = other.books[i];
            }
        } else {
            books = nullptr;
        }
    }

    Category& operator=(const Category& other)
    {
        if (this == &other) return *this;

        delete[] books; 

        name = other.name;
        noOfbook = other.noOfbook;
        if (other.books && noOfbook > 0) {
            books = new Book[noOfbook];
            for (int i = 0; i < noOfbook; ++i) {
                books[i] = other.books[i];
            }
        } else {
            books = nullptr;
        }
        return *this;
    }
    ~Category()
    {
        delete[] books;
    }
    friend class Library;
};
class Library
{
    Category *category;
    int noOfcategory;
    public:
    Library()
    {
        noOfcategory=0;
        category=nullptr;
    }
    Library(int noOfcategory)
    {
        this->noOfcategory = noOfcategory;

        if(noOfcategory > 0) 
        {
            category = new Category[noOfcategory];  
        } 
        else 
        {
            category = nullptr;
        }
    }
    void SearchBookId(int bookid)
    {
        for(int i=0;i<noOfcategory;i++){
            for(int j=0;j<category[i].getnoOfbooks();j++){
                if(category[i].books[j].getid()==bookid){
                    cout<<"\n==========================================="<<endl;
                    cout<<"Yes the Book  is Available in "<<endl;
                    cout<<"Id: "<<bookid<<endl;
                    cout<<"Name: "<<category[i].books[j].getbookname()<<endl;
                    cout<<"Category : "<<category[i].getcatename()<<endl;
                    cout<<"==========================================="<<endl;
                    return ;
                }
            }
        }
        cout<<"\n==========================================="<<endl;
        cout<<"Sorry the Book of id "<<bookid<<" is NOT Available"<<endl;
        cout<<"==========================================="<<endl;
    }
    void inputData() {
        for(int i=0; i<noOfcategory; i++) {
            string cname;
            int nBooks;
            cout << "Category "<<i+1<<" name: ";
            cin >> cname;
            cout << "Enter number of books in " << cname << ": ";
            cin >> nBooks;

            Book *b = new Book[nBooks];
            for(int j=0; j<nBooks; j++) {
                string bname;
                int bid;
                cout << "Book " << j+1 << " name: ";
                cin >> bname;
                cout <<"ID: ";
                cin >> bid;
                b[j] = Book(bname, bid);
            }

            category[i] = Category(cname, nBooks, b);
            delete[] b; 
            cout<<"----------------------------------"<<endl;
        }
    }

    ~Library() {
        delete[] category;
    }
};
int main()
{
    int n;
    cout << "Enter number of categories in the library: ";
    cin >> n;

    Library lib(n);
    lib.inputData();

    char choice;
    do {
        int searchId;
        cout << "\nEnter Book ID to search: ";
        cin >> searchId;

        lib.SearchBookId(searchId);

        cout << "\nDo you want to search another book? (y/n): ";
        cin >> choice;
    } while(choice == 'y' || choice == 'Y');
    return 0;
}
