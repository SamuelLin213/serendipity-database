#ifndef BOOKTYPE_H
#define BOOKTYPE_H

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

class bookType
{
  public:
    bookType();
    bookType(string title, string isbn, string author, string publisher,
      string dateAdded, int qtyOnHand, float wholesale, float retail);

    void setTitle(string str);
    void setISBN(string str);
    void setAuthor(string str);
    void setPub(string str);
    void setDateAdded(string str);
    void setQtyOnHand(int amount);
    void setWholesale(float dbl);
    void setRetail(float dbl);

    const string getTitle();
    const string getISBN();
    const string getAuthor();
    const string getPub();
    const string getDateAdded();
    const int getQtyOnHand();
    const float getWholesale();
    const float getRetail();

    static const int getBookCount();
    static void incBookCount();
    static void decBookCount();

    void print();
    bool equals(bookType other);

    bool operator<(const bookType& otherBook) const;
    bool operator<=(const bookType& otherBook) const;
    bool operator>(const bookType& otherBook) const;
    bool operator>=(const bookType& otherBook) const;
    bool operator==(const bookType& otherBook) const;
    bool operator!=(const bookType& otherBook) const;
  private:
    string bookTitle;
    string isbn;
    string author;
    string publisher;
    string dateAdded;
    int qtyOnHand;
    float wholesale;
    float retail;
    static int bookCount;
};

#endif
