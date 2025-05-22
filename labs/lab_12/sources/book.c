//
// Created by Dora on 2025. 05. 15..
//

#include "../headers/book.h"
#include <stdio.h>

#include "binary_search_tree.h"
#include "../headers/contans.h"
void printBook(Book book){
  printf("\n%s: ", book.title);
  printf("\n\tAuthor: %s: ", book.author);
  printf("\n\tPublication Year: %i", book.publicationYear);
  printf("\n\t Is borrowed : %s ", (book.status)?("Yes"):("No"));
}
void readBook(Book *book, FILE *in){
    fscanf(in,"%[^\n]\n",book->title);
    fscanf(in,"%[^\n]",book->author);
    fscanf(in,"%d",&book->publicationYear);
    int borrowed;
    fscanf(in,"%d\n",&borrowed);
    book->status=borrowed;
}
