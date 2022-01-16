#include "bookType.h"

class bookType;

bookType::bookType()
{
  bookTitle = "";
  isbn = "";
  author = "";
  publisher = "";
  dateAdded = "";
  qtyOnHand = 0;
  retail = 0.0;
  wholesale = 0.0;
}
bookType::bookType(string title, string isbn, string author, string publisher,
  string dateAdded, int qtyOnHand, float wholesale, float retail)
{
  bookTitle = title;
  this->isbn = isbn;
  this->author = author;
  this->publisher = publisher;
  this->dateAdded = dateAdded;
  this->qtyOnHand = qtyOnHand;
  this->retail = retail;
  this->wholesale = wholesale;
}

void bookType::setTitle(string str)
{
  bookTitle = str;
}
void bookType::setISBN(string str)
{
  isbn = str;
}
void bookType::setAuthor(string str)
{
  author = str;
}
void bookType::setPub(string str)
{
  publisher = str;
}
void bookType::setDateAdded(string str)
{
  dateAdded = str;
}
void bookType::setQtyOnHand(int amount)
{
  qtyOnHand = amount;
}
void bookType::setWholesale(float dbl)
{
  wholesale = dbl;
}
void bookType::setRetail(float dbl)
{
  retail = dbl;
}

const string bookType::getTitle()
{
  return bookTitle;
}
const string bookType::getISBN()
{
  return isbn;
}
const string bookType::getAuthor()
{
  return author;
}
const string bookType::getPub()
{
  return publisher;
}
const string bookType::getDateAdded()
{
  return dateAdded;
}
const int bookType::getQtyOnHand()
{
  return qtyOnHand;
}
const float bookType::getWholesale()
{
  return wholesale;
}
const float bookType::getRetail()
{
  return retail;
}

const int bookType::getBookCount()
{
  return bookCount;
}
void bookType::incBookCount()
{
  bookCount += 1;
}
void bookType::decBookCount()
{
  bookCount -= 1;
}

void bookType::print()
{
  cout << "\033[2J\033[1;1H";

  cout << "  Serendipity Booksellers" << endl;
  cout << setw(6) << "" << "Book Information" << endl << endl;
  cout << "ISBN: " << isbn << endl;
  cout << "Title: " << bookTitle << endl;
  cout << "Author: " << author << endl;
  cout << "Publisher: " << publisher << endl;
  cout << "Date Added: " << dateAdded << endl;
  cout << "Quantity-On-Hand: " << qtyOnHand << endl;
  cout << "Wholesale Cost: " << wholesale << endl;
  cout << "Retail Price: " << retail << endl;
}
bool bookType::equals(bookType other)
{
  if(this->isbn == other.getISBN())
  {
    return true;
  }
  return false;
}
bool bookType::operator<(const bookType& otherBook) const
{
  if(qtyOnHand < otherBook.qtyOnHand)
  {
    return true;
  }
  return false;
}
bool bookType::operator<=(const bookType& otherBook) const
{
  if(qtyOnHand <= otherBook.qtyOnHand)
  {
    return true;
  }
  return false;
}
bool bookType::operator>=(const bookType& otherBook) const
{
  if(qtyOnHand >= otherBook.qtyOnHand)
  {
    return true;
  }
  return false;
}
bool bookType::operator>(const bookType& otherBook) const
{
  if(qtyOnHand > otherBook.qtyOnHand)
  {
    return true;
  }
  return false;
}
bool bookType::operator==(const bookType& otherBook) const
{
  if(qtyOnHand == otherBook.qtyOnHand)
  {
    return true;
  }
  return false;
}
bool bookType::operator!=(const bookType& otherBook) const
{
  if(qtyOnHand != otherBook.qtyOnHand)
  {
    return true;
  }
  return false;
}
