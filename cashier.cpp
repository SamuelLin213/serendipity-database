#include "functions.h"

void cashier(bookType **books){
  string date;
  int qty = 0;
  string isbn;
  string title;
  double price = 0.0;
  double total = 0.0;
  double tax = 0.0;
  double subtotal = 0.0;
  char ch = 'n';
  int index = -1;
  char another = 'z';
  bool repeat = false;
  int repeatIndex = -1;
  char purchase = 'n';

  vector<int> quantities;
  vector<int> indexes;
  vector<double> prices;

  do{
    if(toupper(ch) == 'Y')
    {
      total = 0.0;
      tax = 0.0;
      subtotal = 0.0;
    }

    ADD:cout << "\033[2J\033[1;1H";

    cout << "Serendipity Booksellers" << endl;
    cout << "  Cashier Module" << endl << endl;

    cout << "Date: ";
    cin >> date;
    cout << "Quantity of Book: ";
    cin >> qty;
    cout << "ISBN: ";
    cin >> isbn;
    cout << "Title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Price: ";
    cin >> price;

    cout << endl;
    index = lookUpBook(books, 4, isbn);

    if(index < 0)
    {
      cin.get();
    }
    else if(index != -1)
    {
      repeat = false;
      for(int i = 0; i < (int)indexes.size(); i++)
      {
        if(books[indexes[i]]->getISBN() == isbn)
        {
          repeatIndex = i;
          repeat = true;
          break;
        }
      }
      if(repeat)
      {
        quantities[repeatIndex] += qty;
      }
      else{
        quantities.push_back(qty);
        indexes.push_back(index);
        prices.push_back(price);
      }

      //books[index]->qtyOnHand -= qty;

      cout << "Do you want to add another book to this purchase? <y/n> ";
      another = 'z';
      while(toupper(another) != 'Y' && toupper(another) != 'N')
      {
        cin >> another;
        if(toupper(another) == 'Y')
        {
          another = 'z';
          goto ADD;
        }
      }

      cout << "\033[2J\033[1;1H";

      time_t now = time(0);
      tm *ltm = localtime(&now);

      cout << "Serendipity Book Sellers" << endl << endl;
      cout << "Date: " << date << "    Time: " << 5+ltm->tm_hour << ":"
      << 30+ltm->tm_min << ":" << ltm->tm_sec << endl << endl;
      cout << setw(4) << left << "Qty" << setw(14) << "ISBN" << setw(30) << "Title"
      << setw(15) << "Price" << setw(7) << "Total" << endl;
      cout << setw(70) << setfill('-') << "" << setfill(' ') << endl;

      for(int i = 0; i < (int)indexes.size(); i++)
      {
        total = quantities[i] * prices[i];
        subtotal += total;

        cout << setw(4) << left << quantities[i] << setw(14) << books[indexes[i]]->getISBN()
        << setw(30) << books[indexes[i]]->getTitle() << "$" << right << setw(6)
        << fixed << setprecision(2) << prices[i] << " " << setw(8) << "$" << setw(6) << fixed
        << setprecision(2) << right << total << endl;
      }
      // cout << setw(4) << left << qty << setw(14) << books[index]->isbn << setw(30) << books[index]->title
      // << "$" << right << setw(6) << price << " " << setw(8) << "$" << setw(6)
      // << fixed << setprecision(2) << right << total << endl;

      tax = 0.06* subtotal;

      cout << endl << endl;

      cout << left << setw(13) << "" << setw(8) << "Subtotal" << right << setw(42)
      << "" << "$" << setw(6) << fixed << setprecision(2) << subtotal << endl;
      cout << left << setw(13) << "" << setw(8) << "Tax" << right << setw(42)
      << "" << "$" << setw(6) << fixed << setprecision(2) << tax << endl;
      cout << left << setw(13) << "" << setw(8) << "Total" << right << setw(42)
      << "" << "$" << setw(6) << fixed << setprecision(2) << (tax + subtotal) << endl;

      cout << endl << "Confirm purchase? <y/n> ";
      cin >> purchase;

      if(toupper(purchase) == 'Y')
      {
        cout << endl << "Thank you for Shopping at Serendipity!" << endl;
        purchase = 'n';
        for(int i = 0; i < (int)indexes.size(); i++)
        {
          books[indexes[i]]->setQtyOnHand(books[indexes[i]]->getQtyOnHand() - quantities[i]);
        }
      }

      cout << endl <<  "Enter another transaction?(y/n) ";

      cin.ignore();
      cin >> ch;

      if(toupper(ch) == 'Y')
      {
        quantities.clear();
        indexes.clear();
        prices.clear();
      }
    }
  }while(ch != 'n' && ch != 'N');
}
