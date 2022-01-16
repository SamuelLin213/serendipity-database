#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "bookType.h"
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;

class bookType;

const int DB_SIZE = 125;

void loadBooks(bookType **books);
void saveBooks(bookType **books);

void cashier(bookType **books);
void invMenu(bookType **books);
void reports(bookType **books);

//invmenu signatures
int lookUpBook(bookType **books, int code, string key);
void addBook(bookType **books, int code, int index);
void editBook(bookType **books);
void deleteBook(bookType **books);

//reports signatures
void repListing(bookType **books);
void repWholesale(bookType **books);
void repRetail(bookType **books);
void repQty(bookType **books);
void repCost(bookType **books);
void repAge(bookType **books);

//misc functions
int isEmpty(bookType **books, int index);
void removeBook(bookType **books, int index);

template <typename T>
void sortQty(T** books);

template <typename T>
void sortCost(T** books);

template <typename T>
void sortAge(T** books);

#endif
