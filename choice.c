#include "header.h"

/*--------------------We create a function that allows the user to choose what he want to do when he is connected--------------------*/
int action(int user, Book books[], int taille, int role, char *name, int nbBook){
	char nb[50]; //We create a string of 50 characters named 'nb' that will allows us to recover what the user will enter.
	printf(COLOR_CYAN "\n	Bienvenue %s ! \n \n" COLOR_RESET, name); //We display a welcome message with the name of the user.
	borrowed_book(user, books, nbBook); //We display all the books that the user has borrowed.
	if (role == 1){ //If the user is a student, we go in this loop.
		printf(COLOR_GREEN "Que voulez-vous faire ? \n" COLOR_RESET); //we ask to the user what he want to do.
		printf("	1 : Emprunter un nouveau livre. \n"); //He need to enter '1' to borrow a book.
        printf("	2 : Rendre un livre. \n"); //He need to enter '2' to return a book.
		printf("	3 : Se déconnecter et fermer le programme. \n"); //He need to enter '3' to disconnect and close the program.
       		scanf("%s", &nb); //We recover the charater(s) that the user has entered.
		if(strlen(nb) > 1){ //If the student enters more than 1 character, we display an error message and go at the beginning of the function 'action' that will allows the user to retry and enter a good value.
			printf(COLOR_RED "\nErreur ! Valeur non valide, veuillez réessayer : \n \n" COLOR_RESET); //We display an error message to prevent that the student has entered a prohibited value.
			action(user, books, taille, role, name, nbBook); //we call the function 'action'.
		}
		else{ //If the student enters 1 character, we go in this loop.
			if (nb[0] == '1'){ //If the student enters '1', we go in the function 'borrow_book'.				
				borrow_book(books, nbBook, user); //We call the function 'borrow_book'.
			}
			else if (nb[0] == '2'){ //If the student enters '2', we go in the function 'return_book'.
				return_book(books, nbBook, user); //We call the function 'return_book'.
			}
			else if (nb[0] == '3'){ //If the student enters '3', we close the program.
				printf(COLOR_CYAN "\nVous allez quitter le programme. Bonne journée ! \n \n \n" COLOR_RESET); //We display a message to the user before close the program.
        			exit(1); //We close the program.
			}
			else{ //If the teacher enters a value other that '1', '2', or '3', we display an error message and go at the beginning of the function 'action' that will allows the user to retry and enter a good value.
				printf(COLOR_RED "\nErreur ! Valeur non valide, veuillez réessayer : \n \n" COLOR_RESET); //We display an error message to prevent that the student has entered a prohibited value.
				action(user, books, taille, role, name, nbBook); //we call the function 'action'.
			}
		}
	}
	else{ //if the user isn't a student, he had to be a teacher, so we go in this loop.
       	printf(COLOR_GREEN "Que voulez-vous faire ? \n" COLOR_RESET); //we ask to the user what he want to do.
		printf("	1 : Emprunter un nouveau livre. \n"); //He need to enter '1' to borrow a book.
		printf("	2 : Rendre un livre. \n"); //He need to enter '2' to return a book.
		printf("	3 : Créer un livre. \n"); //He need to enter '3' to ateate a book.
		printf("	4 : Se déconnecter et fermer le programme. \n"); //He need to enter '4' to disconnect and close the program.
       		scanf("%s", &nb); //We recover the charater(s) that the user has entered.
		if(strlen(nb) > 1){ //If the teacher enters more than 1 character, we display an error message and go at the beginning of the function 'action' that will allows the user to retry and enter a good value.
			printf(COLOR_RED "\nErreur ! Valeur non valide, veuillez réessayer : \n \n" COLOR_RESET); //We display an error message to prevent that the teacher has entered a prohibited value.
			action(user, books, taille, role, name, nbBook); //we call the function 'action'.
		}
		else{ //If the teacher enters 1 character, we go in this loop.
			if (nb[0] == '1'){ //If the teacher enters '1', we go in the function 'borrow_book'.
				borrow_book(books, nbBook, user); //We call the function 'borrow_book'.
			}
			else if (nb[0] == '2'){ //If the teacher enters '2', we go in the function 'return_book'.
				return_book(books, nbBook, user); //We call the function 'return_book'.
			}
			else if (nb[0] == '3'){ //If the teacher enters '3', we go in the function 'create_book'.
				create_book(books, &nbBook); //We call the function 'create_book'.
			}
			else if (nb[0] == '4'){ //If the teacher enters '4', we close the program.
				printf(COLOR_CYAN "\nVous allez quitter le programme. Bonne journée ! \n \n \n" COLOR_RESET); //We display a message to the user before close the program.
        			exit(1); //We close the program.
			}
			else{ //If the teacher enters a value other that '1', '2', '3', or '4', we display an error message and go at the beginning of the function 'action' that will allows the user to retry and enter a good value.
				printf(COLOR_RED "\nErreur ! Valeur non valide, veuillez réessayer : \n \n" COLOR_RESET); //We display an error message to prevent that the teacher has entered a prohibited value.
			}
			action(user, books, taille, role, name, nbBook); //we call the function 'action'.
		}
	}
}

/*--------------------We create a function that allows the user to choose what he want between connect, create an account or close the program--------------------*/
void start(int *taille){
	User *users = NULL; //We create a pointer on User.
	Book *books = NULL; //We create a pointer on Book.
	int nbUser = read_user(&users), nbBook = read_book(&books); //We create two integers for the books and the users.
   	char n[100]; //We create a string of charaters that allows us to recover what the user will enter.
		printf(COLOR_GREEN "\nQue voulez-vous faire ? \n" COLOR_RESET); //we ask to the user what he want to do.
		printf("	1 : Se connecter. \n"); //He need to enter '1' to connect.
		printf("	2 : Créer un compte. \n"); //He need to enter '2' to create an account.
		printf("	3 : Fermer le programme. \n"); //He need to enter '3' to close the program.
		scanf("%s", &n); //We recover the character(s) that the user has entered.
		if (strlen(n) > 1){ //If the user enters more than 1 character, we display an error message and go at the beginning of the function 'start' that will allows the user to retry and enter a good value.
			printf(COLOR_RED "\nErreur ! Valeur non valide, veuillez réessayer : \n \n" COLOR_RESET); //We display an error message to prevent that the user has entered a prohibited value.
			start(taille); //we call the function 'start'.
		}
		else{ //If the user enters 1 character, we go in this loop.
        		if (n[0] == '1'){  //If the user enters '1', we go in the function 'connect'.
					connect(users, nbUser, books, nbBook); //We call the function 'connect'.
        		}
        		else if (n[0] == '2'){ //If the user enters '2', we go in the function 'create_user'.
        			create_user(users, &nbUser, books, nbBook); //We call the function 'create_user'.
        		}
        		else if (n[0] == '3'){ //If the user enters '3', we close the program.
				printf(COLOR_CYAN "Vous allez quitter le programme. \n \n \n" COLOR_RESET); //We display a message to the user before close the program.
        			exit(1); //We close the program.
        		}
        		else{ //If the user enters a value other that '1', '2', or '3', we display an error message and go at the beginning of the function 'start' that will allows the user to retry and enter a good value.
        			printf(COLOR_RED "\nErreur ! Valeur non valide, veuillez réessayer : \n \n" COLOR_RESET); //We display an error message to prevent that the user has entered a prohibited value.
				start(taille); //we call the function 'start'.
        		}
		}
	if(users != NULL){
		free(users); //It allows to free the memory.	
	}
	if(books != NULL){
		free(books); //It allows to free the memory.
	}
}
