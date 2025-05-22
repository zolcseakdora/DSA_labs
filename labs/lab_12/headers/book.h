//
// Created by Dora on 2025. 05. 15..
//

#ifndef BOOK_H
#define BOOK_H
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct Book{
  char title[50];
  char author[50];
  int publicationYear;
  bool status;
}Book;
void printBook(Book book);
void readBook(Book *book, FILE *in);

#endif //BOOK_H
