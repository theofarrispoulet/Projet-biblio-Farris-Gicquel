#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<stdbool.h>
#include<stdint.h>
#include<errno.h>
#define TAILLE 1
#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_CYAN "\x1b[36m"
#define COLOR_RESET "\x1b[0m"

/*--------------------We create a structure named 'User'--------------------*/
typedef struct { 
	char name[50]; //We create a string of 50 characters for the name of the user.
	char pw[50]; //We create a string of 50 characters for the password of the user.
	char role[50]; //We create a string of 50 characters for the role of the user.
}User; //User is the name of the structure for the users (students and teachers).

/*--------------------We create a structure named 'Book'--------------------*/
typedef struct {
	char title[100]; //We create a string of 100 characters for the title of the book.
	char autor[50]; //We create a string of 50 characters for the autor of the book.
	char num[50]; //We create a string of 50 characters for the identification number of the book.
	char category[50]; //We create a string of 50 characters for the categorie of the book.
	int available; //We create a variable which define the book's availability.
}Book; //Book is the name of the structure for the books.

void borrowed_book(int user, Book books[], int nbBook);
void edit_book(int index, char *value);
void choose_book(Book tab[], int nbBook, int user);
void return_book(Book tab[], int nbBook, int user);
void search_autor(Book tab[], int nbBook, int user);
void search_title(Book tab[], int nbBook, int user);
void search_category(Book tab[], int nbBook, int user);
void search_num(Book tab[], int nbBook, int user);
void display_book(Book tab[], int nbBook, int user);
void search_book(Book tab[], int nbBook, int user);
void borrow_book(Book tab[], int nbBook, int user);
void write_book(Book tab[], int taille);
int create_book(Book tab[], int *taille);
int action(int user, Book books[], int taille, int test, char *name, int nbBook);
int connect(User tab[], int taille, Book books[], int tailleBook);
void write_user(User tab[], int taille);
int create_user(User tab[], int *taille, Book books[], int tailleBook);
int read_book(Book **ptTab);
int read_user(User **ptTab);
void start(int *taille);
