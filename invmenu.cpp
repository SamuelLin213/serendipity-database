#include "functions.h"

void invMenu(bookType **books){
  int input = 0;

  while(input != 5)
  {
    do{
      cout << "\033[2J\033[1;1H";

      cout << "  Serendipity Booksellers" << endl;
      cout << setw(5) << "" << "Inventory Database" << endl << endl;

      cout << "1.  Look Up a Book" << endl;
      cout << "2.  Add a Book" << endl;
      cout << "3.  Edit a Book's Record" << endl;
      cout << "4.  Delete a Book" << endl;
      cout << "5.  Return to the Main Menu" << endl << endl;

      cout << "Enter Your Choice: ";
      cin >> input;

      if(!(input <= 5 && input >= 1)){
        cin.ignore();
        cout << endl << "Please enter a number in the range 1 - 5. Press any button to continue.";
        cin.get();
      }
    }while(!(input <= 5 && input >= 1));

    switch(input)
    {
      case 1:
        lookUpBook(books, 1, "");
        break;
      case 2:
        addBook(books, 1, 0);
        break;
      case 3:
        editBook(books);
        break;
      case 4:
        deleteBook(books);
        break;
    }
  }
}

int lookUpBook(bookType **books, int code, string key)
{
  string search = "";
  vector<int> indexes;
  char ch = 'z';
  char ch2 = 'q';
  char ch3 = 'x';
  bool done = false;
  int index = 0;

  INFO:if(code != 4)
  {
    cin.ignore();
    cout << endl << "Search for a book: ";
    getline(cin, search);
  }
  else if(code == 4)
  {
    search = key;
  }
  for(int i = 0; i < bookType::getBookCount(); i++)
  {
    if(books[i]->getTitle().find(search) != string::npos || books[i]->getISBN().find(search) != string::npos
    || books[i]->getPub().find(search) != string::npos || books[i]->getAuthor().find(search) != string::npos)
    {
      indexes.push_back(i);
    }
  }

  if(indexes.size() > 0)
  {
    for(int x = 0; x < int(indexes.size()); x++)
    {
      if(code == 4)
      {
        return indexes[index];
      }
      do{
        cout << endl << "Result: " << books[indexes[x]]->getTitle() << ", "
         << books[indexes[x]]->getISBN() << endl;
        cout << "View this book record? <Y/N>: ";
        cin >> ch;

        if(toupper(ch) == 'Y')
        {
          done = true;
          index = x;
          break;
        }
      }while(toupper(ch) != 'Y' && toupper(ch) != 'N');
      if(done)
      {
        books[indexes[index]]->print();
        if(code == 1)
        {
          cin.ignore();
          cin.get();
        }
        else if(code == 2)
        {
          do{
            cout << endl << "Is this the book you want to edit? <Y/N>: ";
            cin >> ch2;
          }while(toupper(ch2) != 'Y' && toupper(ch2) != 'N');
          if(toupper(ch2) == 'Y')
          {
            addBook(books, 2, indexes[index]);
          }
        }
        else if(code == 3)
        {
          do{
            cout << endl << "Is this the book you want to delete? <Y/N>: ";
            cin >> ch3;
          }while(toupper(ch3) != 'Y' && toupper(ch3) != 'N');
          if(toupper(ch3) == 'Y')
          {
            ch3 = 'n';
            cout << "Book deleted." << endl;
            bookType::decBookCount();

            removeBook(books, indexes[index]);

            if(bookType::getBookCount() != 0)
            {
              cout << "Delete another? <Y/N>: ";
              cin >> ch3;
            }
            if(toupper(ch3) == 'Y')
            {
              cout << "\033[2J\033[1;1H";
              cout << "Serendipity Booksellers" << endl;
              cout << " Delete Book" << endl << endl;
              cout << " Database size: " << DB_SIZE << " Current book count: " << bookType::getBookCount()
              << endl;
              goto INFO;
            }
          }
        }
        break;
      }
    }
    if(!done)
    {
      cout << endl << "Sorry. No match found.";
      cin.ignore();
      cin.get();
    }
  }
  else{
    cout << endl << "Sorry. No match found.";
    // cin.ignore();
    cin.get();
  }
  indexes.clear();
  return -1;
}
void addBook(bookType **books, int code, int index){
  if(bookType::getBookCount() < 20)
  {
    string tempTitle = "EMPTY";
    string tempISBN = "EMPTY";
    string tempAuthor = "EMPTY";
    string tempPublisher = "EMPTY";
    string tempDate = "EMPTY";
    int tempQty = 0;
    double tempWholesale = 0.0;
    double tempRetail = 0.0;
    int choice = 10;
    string action;
    bool changed = false;
    bool saved = false;
    bool exit = false;

    if(code == 1)
    {
      action = "Enter";
    }
    else{
      action = "Edit";
      tempTitle = books[index]->getTitle();
      tempISBN = books[index]->getISBN();
      tempAuthor = books[index]->getAuthor();
      tempPublisher = books[index]->getPub();
      tempDate = books[index]->getDateAdded();
      tempQty = books[index]->getQtyOnHand();
      tempWholesale = books[index]->getWholesale();
      tempRetail = books[index]->getRetail();
    }

    while(choice != 0 && !exit)
    {
      do
      {
        cout << "\033[2J\033[1;1H";
        cout << "Serendipity Booksellers" << endl;
        cout << " Add Book" << endl << endl;
        cout << "Database size: " << DB_SIZE << " Current book count: "
        << bookType::getBookCount() << endl;
        cout << setw(36) << " " << "--Pending values" << endl;

        cout << setw(4) << left << "<1>" << setw(5) << action << setw(25) << " book title"
        << "> --" << tempTitle << endl;
        cout << setw(4) << left << "<2>" << setw(5) << action << setw(25) <<" ISBN"
        << "> --" << tempISBN << endl;
        cout << setw(4) << left << "<3>" << setw(5) << action << setw(25) <<" author"
        << "> --" << tempAuthor << endl;
        cout << setw(4) << left << "<4>" << setw(5) << action << setw(25) <<" publisher"
        << "> --" << tempPublisher << endl;
        cout << setw(4) << left << "<5>" << setw(5) << action << setw(25) <<" date added <mm/dd/yyyy>"
        << "> --" << tempDate << endl;
        cout << setw(4) << left << "<6>" << setw(5) << action << setw(25) <<" quantity on hand"
        << "> --" << tempQty << endl;
        cout << setw(4) << left << "<7>" << setw(5) << action << setw(25) <<" wholesale cost"
        << "> --" << tempWholesale << endl;
        cout << setw(4) << left << "<8>" << setw(5) << action << setw(25) <<" retail price"
        << "> --" << tempRetail << endl;
        cout << setw(4) << left << "<9>" << setw(30) << "Save book to database"
        << endl;
        cout << setw(4) << left << "<0>" << setw(30) << "Return to Inventory menu"
        << endl << endl;

        cout << "Choice <0-9>: ";

        cin >> choice;
  			cin.ignore(50, '\n');

        if(choice > 9 || choice < 0)
        {
          cout << endl << "Please enter a number in the range 0 - 9 . Press any button to continue.";
          cin.get();
        }
      }while((choice > 9 || choice < 0));

      switch(choice)
      {
        case 1:
          cout << "Enter book title: ";
          getline(cin, tempTitle);
          changed = true;
          break;
        case 2:
          cout << "Enter ISBN: ";
          getline(cin, tempISBN);
          changed = true;
          break;
        case 3:
          cout << "Enter author: ";
          getline(cin, tempAuthor);
          changed = true;
          break;
        case 4:
          cout << "Enter publisher: ";
          getline(cin, tempPublisher);
          changed = true;
          break;
        case 5:
          cout << "Enter date <mm/dd/yyyy>: ";
          getline(cin, tempDate);
          changed = true;
          break;
        case 6:
          cout << "Enter quantity: ";
          cin >> tempQty;
          changed = true;
          break;
        case 7:
          cout << "Enter wholesale cost: ";
          cin >> tempWholesale;
          changed = true;
          break;
        case 8:
          cout << "Enter retail price: ";
          cin >> tempRetail;
          changed = true;
          break;
        case 9:
          if(bookType::getBookCount() < 20)
          {
            if(code == 1)
            {
              books[bookType::getBookCount()] = new bookType;
              books[bookType::getBookCount()]->setTitle(tempTitle);
              books[bookType::getBookCount()]->setISBN(tempISBN);
              books[bookType::getBookCount()]->setAuthor(tempAuthor);
              books[bookType::getBookCount()]->setPub(tempPublisher);
              books[bookType::getBookCount()]->setDateAdded(tempDate);
              books[bookType::getBookCount()]->setQtyOnHand(tempQty);
              books[bookType::getBookCount()]->setWholesale(tempWholesale);
              books[bookType::getBookCount()]->setRetail(tempRetail);

              cout << "Book added!";
              cin.get();

              bookType::incBookCount();
            }
            else if(code == 2)
            {
              books[index]->setTitle(tempTitle);
              books[index]->setISBN(tempISBN);
              books[index]->setAuthor(tempAuthor);
              books[index]->setPub(tempPublisher);
              books[index]->setDateAdded(tempDate);
              books[index]->setQtyOnHand(tempQty);
              books[index]->setWholesale(tempWholesale);
              books[index]->setRetail(tempRetail);

              cout << "Book saved!";
              cin.get();

              saved = true;
            }
          }
          else
          {
            cout << "Error: database full.";
            cin.get();
          }
          break;
        case 0:
          if(code == 2 && !saved && changed)
          {
            char save;

            cout << "Book not saved! Are you sure you want to exit? <Y/N> ";
            cin >> save;

            if(toupper(save) == 'Y')
            {
              exit = true;
            }
            else
            {
              exit = false;
              choice = 10;
            }
          }
          break;
      }
    }
  }
  else{
    cout << "Error: database full.";
    cin.ignore();
    cin.get();
  }
}
void editBook(bookType **books){
  cout << "\033[2J\033[1;1H";
  cout << "Serendipity Booksellers" << endl;
  cout << " Edit Book" << endl << endl;
  cout << " Database size: " << DB_SIZE << " Current book count: " << bookType::getBookCount()
  << endl;

  lookUpBook(books, 2, "");
}
void deleteBook(bookType **books){
  cout << "\033[2J\033[1;1H";
  cout << "Serendipity Booksellers" << endl;
  cout << " Delete Book" << endl << endl;
  cout << " Database size: " << DB_SIZE << " Current book count: " << bookType::getBookCount()
  << endl;

  lookUpBook(books, 3, "");
}

int isEmpty(bookType **books, int index)
{
  if(books[index]->getTitle().at(0) == '\0')
  {
    return 1;
  }
  return 0;
}
void removeBook(bookType **books, int index)
{
  for(int i = index; i < bookType::getBookCount(); i++)
  {
    books[i]->setTitle(books[i+1]->getTitle());
    books[i]->setISBN(books[i+1]->getISBN());
    books[i]->setAuthor(books[i+1]->getAuthor());
    books[i]->setPub(books[i+1]->getPub());
    books[i]->setDateAdded(books[i+1]->getDateAdded());
    books[i]->setQtyOnHand(books[i+1]->getQtyOnHand());
    books[i]->setWholesale(books[i+1]->getWholesale());
    books[i]->setRetail(books[i+1]->getRetail());
  }
}
