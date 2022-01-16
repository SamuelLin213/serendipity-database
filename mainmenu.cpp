#include "functions.h"

int bookType::bookCount = 0;

int main(){
  //book struct
  //bookType books[DB_SIZE];
  bookType **books = new bookType*[DB_SIZE];

  int choice = 0;

  loadBooks(books);

  while(choice != 4){
    do{
      cout << "\033[2J\033[1;1H";

      cout << "  Serendipity Booksellers" << endl;
      cout << setw(8) << "" << "Main Menu" << endl;
      cout << endl << "1. Cashier Module" << endl;
      cout << "2. Inventory Database Module" << endl;
      cout << "3. Report Module" << endl;
      cout << "4. Exit" << endl << endl << "Enter Your Choice: ";

      cin >> choice;

      if(!(choice <= 4 && choice >= 1)){
        cin.ignore();
        cout << endl << "Please enter a number in the range 1 - 4. ";
        cin.get();
      }

    }while(!(choice <= 4 && choice >= 1));


    if(choice == 4){
      break;
    }

    switch(choice)
    {
      case 1:
        cashier(books);
        break;
      case 2:
        invMenu(books);
        break;
      case 3:
        reports(books);
        break;
    }
  }

  saveBooks(books);

  for(int i = 0; i < bookType::getBookCount(); i++)
  {
    delete books[i];
  }
  delete [] books;

}
void loadBooks(bookType **books)
{
  ifstream input;
  string tempTitle;
  string tempIsbn;
  string tempAuthor;
  string tempPublisher;
  string tempDate;
  int tempQty;
  float tempWholesale;
  float tempRetail;

  input.open("database.txt");

  // if(!input.eof())
  // {
  //   cout << "File opened!" << endl;
  //   // cin.ignore();
  //   cin.get();
  // }

  // getline(input, tempTitle);
  // input >> tempIsbn;
  // input.ignore();
  // getline(input, tempAuthor);
  // getline(input, tempPublisher);
  // input >> tempDate;
  // input >> tempQty;
  // input >> tempWholesale;
  // input >> tempRetail;
  //
  // books[0] = new bookType;
  // books[0]->setTitle(tempTitle);
  // books[0]->setISBN(tempIsbn);
  // books[0]->setAuthor(tempAuthor);
  // books[0]->setPub(tempPublisher);
  // books[0]->setDateAdded(tempDate);
  // books[0]->setQtyOnHand(tempQty);
  // books[0]->setWholesale(tempWholesale);
  // books[0]->setRetail(tempRetail);
  //
  // bookType::incBookCount();

  while(!input.eof())
  {
    getline(input, tempTitle);
    input >> tempIsbn;
    input.ignore();
    getline(input, tempAuthor);
    getline(input, tempPublisher);
    input >> tempDate;
    input >> tempQty;
    input >> tempWholesale;
    input >> tempRetail;
    input.ignore();

    books[bookType::getBookCount()] = new bookType;
    books[bookType::getBookCount()]->setTitle(tempTitle);
    books[bookType::getBookCount()]->setISBN(tempIsbn);
    books[bookType::getBookCount()]->setAuthor(tempAuthor);
    books[bookType::getBookCount()]->setPub(tempPublisher);
    books[bookType::getBookCount()]->setDateAdded(tempDate);
    books[bookType::getBookCount()]->setQtyOnHand(tempQty);
    books[bookType::getBookCount()]->setWholesale(tempWholesale);
    books[bookType::getBookCount()]->setRetail(tempRetail);

    bookType::incBookCount();

    if(input.eof())
      break;
  }

  input.close();
}
void saveBooks(bookType **books)
{
  ofstream output;

  output.open("database.txt");

  for(int i = 0; i < bookType::getBookCount(); i++)
  {
    output << books[i]->getTitle() << endl;
    output << books[i]->getISBN() << endl;
    output << books[i]->getAuthor() << endl;
    output << books[i]->getPub() << endl;
    output << books[i]->getDateAdded() << endl;
    output << books[i]->getQtyOnHand() << endl;
    output << books[i]->getWholesale() << endl;
    output << books[i]->getRetail() << endl;
  }

  output.close();
}
