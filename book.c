#include "header.h"

/*--------------------We create a function that allows us to display all the books that the user has borrowed-------------------*/
void borrowed_book(int user, Book books[], int nbBook){
	int nb = 0; //We create 'nb' to verify if the user has borrowed at least one book.
	printf(COLOR_CYAN "Vous avez emprunté(e) :" COLOR_RESET); //We display a message to the user.
	for (int i = 0;i < nbBook;i++){
		if(user + 2 == books[i].available){
			printf("\n \n	- titre : %s, auteur : %s, numéro d'identification : %s, catégorie : %s. \n \n", books[i].title, books[i].autor, books[i].num, books[i].category); //We display all the books that the user has borrowed.
			nb ++; //We add '1' to 'nb'.
		} 
	}
	if(nb == 0){ //If the user has borrowed none book, we display a message to inform him.
		printf(COLOR_CYAN " Vous n'avez emprunté(e) auncun livre. \n \n" COLOR_RESET); //We display the message to the user.
	}
}

/*--------------------We create a function that allows the user to return a book--------------------*/
void return_book(Book tab[], int nbBook, int user){
	char nb[50]; //We create a string of characters called 'nb', that allows us to recover what the user will enter.
	int check = 0;
	printf(COLOR_GREEN "\nQuel livre voulez-vous rendre ? \nDonner le titre de celui-ci : \n" COLOR_RESET); //We ask to the user which book he want to return.
	scanf("%s", &nb); //We recover what the user has entered.
	for(int i = 0;i < nbBook;i++){ //This loop allows us to see if the name he has entered exist
		if (strcmp(nb,tab[i].title) == 0 && tab[i].available-2 == user){ 
			printf(COLOR_CYAN "Vous avez rendu le livre !\n \n" COLOR_RESET); //We display a message to say that the user has returned the book.
			edit_book(i, "001"); //We change the value of the availability in 'book.txt' beacause it is once again available.
			tab[i].available = 1; //We change to value of 'tab[i].available' beacause it is once again available.
			check = 1; //We change the value 'check' to one.
		}	
	}
	
	if(check == 0){
			printf(COLOR_RED "\nErreur ! Ce livre n'existe pas ou vous ne l'avez pas emprunté(e), veuillez réessayer : \n \n" COLOR_RESET); //If the user enters a title of a book that he didn't borrow or of a book that don't exist, we display an error message.
			return_book(tab, nbBook, user); //We call the function 'return_book' that will allows the user to enter a good value.
		}
}

/*--------------------We create a function that allows the user to choose if he want one of these books--------------------*/
void choose_book(Book tab[], int nbBook, int user){
	char nb[50]; //We create a string of characters called 'nb', that allows us to recover what the user will enter.
	printf(COLOR_GREEN "\nVoulez-vous l'un de ces livres ? \n" COLOR_RESET); //We ask to the user if he want one of these books.
	printf("	1 : Oui \n"); //He need to enter '1' if yes.
	printf("	2 : Non \n"); //He need to enter '2' if no.
	scanf("%s", &nb); //We recover what the user has entered.
	if (strlen(nb) > 1){ //If the user enters more than 1 character, we display an error message and go at the beginning of the function 'choose_book'.
			printf(COLOR_RED "\nErreur ! Valeur non valide, veuillez réessayer : \n \n" COLOR_RESET); //We display an error message.
			choose_book(tab, nbBook, user); //We call the function 'choose_book' that will allows the user to enter a good value.
	}
	else{
		if (nb[0] == '1'){ //If the user enters '1', we go in the function 'search_title'.
			printf(COLOR_GREEN "Quel livre voulez-vous emprunter ?\n" COLOR_RESET); //We ask to the user what he want to do in the function 'search_title'.
			search_title(tab, nbBook, user); //We call the function 'search_title'.
		}	
		else if (nb[0] == '2'){ //If the user enters '2', we go in the function 'borrow_book'.
				borrow_book(tab, nbBook, user); //We call the function 'borrow_book'.
		}
		else{
			printf(COLOR_RED "\nErreur ! Valeur non valide, veuillez réessayer : \n \n" COLOR_RESET); //If the user has entered a value other that '1' or '2', we display an error message.
			choose_book(tab, nbBook, user); //We call the function 'choose_book'.
		}
	}
}

/*--------------------We create a function that allows the user to choose how to search the different books--------------------*/
void search_book(Book tab[], int nbBook, int user){
	char nb[50]; //We create a string of characters called 'nb', that allows us to recover what the user will enter.
	printf(COLOR_GREEN "Voulez-vous rechercher un livre selon : \n" COLOR_RESET); //We ask to the user what he want to search.
	printf("	1 : le titre du livre. \n"); //He need to enter '1' to search by title.
	printf("	2 : l'auteur du livre. \n"); //He need to enter '2' to search by autor.
	printf("	3 : le numéro d'identification du livre. \n"); //He need to enter '3' to search by identification number.
	printf("	4 : la catégorie du livre. \n \n"); //He need to enter '4' to search by category.
	printf(COLOR_GREEN "Autres actions possibles : \n" COLOR_RESET); //We display what else can do the user. 
	printf("	5 : Fermer le programme. \n"); //He need to enter '5' to close the program.
	scanf("%s", &nb); //We recover what the user has entered.
	if (strlen(nb) > 1){ //If the user enters more than 1 character, we display an error message and go at the beginning of the function 'search_book'.
		printf(COLOR_RED "\nErreur ! Valeur non valide, veuillez réessayer : \n \n" COLOR_RESET); //We display an error message.
		search_book(tab, nbBook, user); //We call the function 'search_book' that will allows the user to enter a good value.
	}
	else{ //If the user has entered 1 character, we go in this condition.
		if (nb[0] == '1'){ //If the user enters '1', we go in the function 'search_title'.
			search_title(tab, nbBook, user); //We call the function 'search_title'.
		}
		else if (nb[0] == '2'){ //If the user enters '2', we go in the function 'search_autor'.
			search_autor(tab, nbBook, user); //We call the function 'search_autor'.
		}
		else if (nb[0] == '3'){ //If the user enters '3', we go in the function 'search_num'.
			search_num(tab, nbBook, user); //We call the function 'search_num'.
		}
		else if (nb[0] == '4'){ //If the user enters '4', we go in the function 'search_category'.
			search_category(tab, nbBook, user); //We call the function 'search_category'.
		}
		else if (nb[0] == '5'){ //If the user enters '5', we close the program.
			exit(1); //We close the program.
		}
		else{
			printf(COLOR_RED "\nErreur ! Valeur non valide, veuillez réessayer : \n \n" COLOR_RESET); //If the user has entered a value other that '1', '2', '3', '4' or '5', we display an error message.
			search_book(tab, nbBook, user); //We call the function 'search_book'.
		}
	}
}

/*--------------------We create a function that display all the books that have the same autor--------------------*/
void search_autor(Book tab[], int nbBook, int user){
	char autor[50]; //We create a string of characters called 'autor', that allows us to recover what the user will enter.
	int ok = 0; //We create a integer 'ok' equal to 0 that will allows us to display an error message if the user enters a prohibited value.
	printf(COLOR_GREEN "Donner le nom de l'auteur : \n" COLOR_RESET); //We ask to the user the autor of the book he want to borrow.
	scanf("%s", &autor); //We recover what the user has entered.
	for(int i = 0;i < nbBook; i++){
		if(strcmp(autor, tab[i].autor) == 0 && tab[i].available == 1){
			printf("Voici le livre correspondant :\n titre : %s, auteur : %s, numéro d'identification : %s, catégorie : %s. \n \n", tab[i].title, tab[i].autor, tab[i].num, tab[i].category); //We display a message with all the books that have the same autor.
			ok = 1; //We affect tha value '1' to 'ok'.
		}
	}
	if(ok == 0){
			printf(COLOR_RED "\nErreur ! L'auteur n'existe pas ou le livre n'est pas disponible : Veuillez réessayer\n \n" COLOR_RESET); //We display an error message.
			search_autor(tab, nbBook, user); //We call the function 'search_autor' that will allows the user to retry and enter a good value.
	}
	choose_book(tab, nbBook, user); //We call the function 'choose_book'.
}

void search_category(Book tab[], int nbBook, int user){
	char category[50]; //We create a string of characters called 'category', that allows us to recover what the user will enter.
	int ok = 0; //We create a integer 'ok' equal to 0 that will allows us to display an error message if the user enters a prohibited value.
	printf(COLOR_GREEN "Donner la categorie du livre : \n" COLOR_RESET); //We ask to the user the category of the book he want to borrow.
	scanf("%s", &category); //We recover what the user has entered.
	for(int i = 0;i < nbBook; i++){
		if(strcmp(category, tab[i].category) == 0 && tab[i].available == 1){
			printf("Voici le livre correspondant :\n titre : %s, auteur : %s, numéro d'identification : %s, catégorie : %s. \n \n", tab[i].title, tab[i].autor, tab[i].num, tab[i].category); //We display a message with all the books that have the same category.
		ok = 1; //We affect tha value '1' to 'ok'.
		}
	}
	if(ok == 0){
			printf(COLOR_RED "\nErreur ! La catégorie n'existe pas ou le livre n'est pas disponible : Veuillez réessayer\n \n" COLOR_RESET); //We display an error message.
			search_category(tab, nbBook, user); //We call the function 'search_category' that will allows the user to retry and enter a good value.
	}
	choose_book(tab, nbBook, user); //We call the function 'choose_book'.
}

void search_num(Book tab[], int nbBook, int user){
	char num[50]; //We create a string of characters called 'num', that allows us to recover what the user will enter.
	int ok = 0; //We create a integer 'ok' equal to 0 that will allows us to display an error message if the user enters a prohibited value.
	printf(COLOR_GREEN "Donner le numéro d'identification : \n" COLOR_RESET); //We ask to the user the identification number of the book he want to borrow.
	scanf("%s", &num); //We recover what the user has entered.
	for(int i = 0;i < nbBook; i++){
		if(strcmp(num, tab[i].num) == 0 && tab[i].available == 1){
			printf("Voici le livre correspondant :\n titre : %s, auteur : %s, numéro d'identification : %s, catégorie : %s. \n \n", tab[i].title, tab[i].autor, tab[i].num, tab[i].category); //We display a message with all the books that have the same identification number.
			ok = 1; //We affect tha value '1' to 'ok'.
		}
	}
	if(ok == 0){
			printf(COLOR_RED "\nErreur ! Le numéro d'identification n'existe pas ou le livre n'est pas disponible : Veuillez réessayer\n \n" COLOR_RESET); //We display an error message.
			search_num(tab, nbBook, user); //We call the function 'search_num' that will allows the user to retry and enter a good value.
	}
	choose_book(tab, nbBook, user); //We call the function 'choose_book'.
}

/*--------------------We create a function that allows the user to choose the book--------------------*/
void search_title(Book tab[], int nbBook, int user){
	char title[50]; //We create a string of characters called 'title', that allows us to recover what the user will enter.
	int ok = 0; //We create a integer 'ok' equal to 0 that will allows us to display an error message if the user enters a prohibited value.
	FILE* fichier = NULL;
	fichier = fopen("book.txt", "r+"); //We open the .txt file named 'book' and we can read and write in thanks to 'r+'.
	printf(COLOR_GREEN "Donner le titre du livre : \n" COLOR_RESET); //We ask to the user the title of the book he want to borrow.
	scanf("%s", title); //We recover what the user has entered.
	for(int i = 0;i < nbBook; i++){ //This loop allows us to display all the books that have this title.
		if(strcmp(title, tab[i].title) == 0 && tab[i].available == 1){
			printf("Voici le livre correspondant :\n titre : %s, auteur : %s, numéro d'identification : %s, catégorie : %s. \n \n", tab[i].title, tab[i].autor, tab[i].num, tab[i].category); //We display the book.
			ok = 1; //We affect tha value '1' to 'ok'.
			printf(COLOR_CYAN "Vous avez emprunté(e) ce livre ! \n \n" COLOR_RESET); //We display a message to say that the user has borrowed the book.
			char temp[3];
			user+=2; //We add '2' to 'user'.
			tab[i].available = user; //We change to value of 'tab[i].available' beacause it is borrowed.
			temp[0] = (user/100)+'0';
			temp[1] = ((user%100)/10)+'0';
			temp[2] = (user%10)+'0';
			edit_book(i, temp); //We change to value of the availability in 'book.txt' beacause it is borrowed.
			user-=2; //We remove '2' to 'user'.
		}
	}
	if(ok == 0){
			printf(COLOR_RED "\nErreur ! Le titre n'existe pas ou le livre n'est pas disponible : Veuillez réessayer\n \n" COLOR_RESET); //We display an error message.
			search_title(tab, nbBook, user); //We call the function 'search_title' that will allows the user to retry and enter a good value.
	}
}

/*--------------------We create a function that allows the user to display the books--------------------*/
void display_book(Book tab[], int nbBook, int user){
	printf("Voici les livres correspondants : \n"); //We display a message.
	for(int i = 0;i < nbBook; i++){ //This loop allows us to display the number 'nbBook' of books that we have in the .txt 'book'.
			if(tab[i].available == 1){
				printf(" titre : %s, auteur : %s, numéro d'identification : %s, catégorie : %s. \n \n", tab[i].title, tab[i].autor, tab[i].num, tab[i].category); //We display all the books.
				}
	}
	search_book(tab, nbBook, user); //We call the function 'search_book' that will allows the user to search and choose which book he want to borrow.
}

/*--------------------We create a function that allows the user to choose if he want to search a book, or if he want to display the books available--------------------*/
void borrow_book(Book tab[], int nbBook, int user){
	char nb[50]; //We create a string of characters called 'nb', that allows us to recover what the user will enter.
	printf(COLOR_GREEN "Que voulez-vous faire ? \n" COLOR_RESET); //We ask to the user what he want to do.
	printf("	1 : rechercher un livre. \n"); //He need to enter '1' to search a book.
	printf("	2 : afficher les livres disponibles. \n"); //He need to enter '2' to display the books.
	printf(COLOR_GREEN "Autres actions possibles : \n" COLOR_RESET); //We display what else can do the user.
	printf("	3 : Fermer le programme. \n"); //He need to enter '3' to close the program.
	scanf("%s",&nb); //We recover the character(s) that the user has entered.
	if (strlen(nb) > 1){ //If the user enters more than 1 character, we display an error message and go at the beginning of the function 'action'.
		printf(COLOR_RED "\nErreur ! Valeur non valide, veuillez réessayer :\n \n" COLOR_RESET); //We display an error message to prevent that the student has entered a prohibited value.
		borrow_book(tab, nbBook, user); //We call the function 'borrow_book' that will allows the user to retry and enter a good value.
	}
	else{ // If the user enters 1 character, we go in this condition..
		if (nb[0] == '1'){ //If the user enters '1', we go in the function 'search_book'.
			search_book(tab, nbBook, user); //We call the function 'search_book'.
		}
		else if (nb[0] == '2'){ //If the user enters '2', we go in the function 'display_book'.
			display_book(tab, nbBook, user); //We call the function 'display_book'.
		}
		else if (nb[0] == '3'){ //If the user enters '3', we close the program.
			exit(1); //We close the program.
		}
		else{
			printf(COLOR_RED "\nErreur ! Valeur non valide, veuillez réessayer : \n \n" COLOR_RESET); //We display an error message to prevent that the student has entered a prohibited value.
			borrow_book(tab, nbBook, user); //We call the function 'borrow_book' that will allows the user to retry and enter a good value.
		}
	}

}

/*--------------------We create a function that allows to write in a .txt file the different books with their specifications--------------------*/
void write_book(Book tab[], int taille){
	FILE* fichier = NULL;
	fichier = fopen("book.txt", "a"); //We open the .txt file named 'book' and we can only write at the end of this file thanks to 'a'.
	if(fichier == NULL) { //If the file doesn't exist, we print an error message.
		printf(COLOR_RED "\nErreur ! Impossible d'ouvrir le fichier ! \n"); //We display an error message.
		printf("Code d'erreur = %d \n", errno);
		printf("Message d'erreur = %s \n"  COLOR_RESET, strerror(errno));
		exit(1); //We close the program.
	}
	for(int i=0;i<taille;i++){ //This loop allows us to print the number of books that the user has entered in the function 'create_book'.
		fprintf(fichier, "\n%s \n", tab[i].title); //We write in the file, the title of the book.
		fprintf(fichier, "%s \n", tab[i].autor); //We write in the file, the autor of the book.
		fprintf(fichier, "%s \n", tab[i].num); //We write in the file, the identification number of the book.
		fprintf(fichier, "%s \n", tab[i].category); //We write in the file, the category of the book.
		fprintf(fichier, "%s \n", tab[i].available); //We write in the file, the availability of the book.
	}
	fclose(fichier); //We close the file.	
} 

void edit_book(int index, char *value){
	int count = 0;
	FILE* fichier = NULL;
	fichier = fopen("book.txt", "r+"); //We open the .txt file named 'book' and we can only write at the end of this file thanks to 'a'.
	if(fichier == NULL) { //If the file doesn't exist, we print an error message.
		printf(COLOR_RED "\nErreur ! Impossible d'ouvrir le fichier ! \n"); //We display an error message.
		printf("Code d'erreur = %d \n", errno);
		printf("Message d'erreur = %s \n"  COLOR_RESET, strerror(errno));
		exit(1); //We close the program.
	}
	while(count != (index * 6) + 5){ //While
		if (fgetc(fichier) == '\n'){
			count++; //We add '1' to 'count'.
		}
	}
	fprintf(fichier, "%c", value[0]); //These 3 lines allows us to print in the .txt 'book', the value of the user that borrowed the book.
	fprintf(fichier, "%c", value[1]);
	fprintf(fichier, "%c", value[2]);
	fclose(fichier); //We close the file.
}

/*--------------------We create a function that allows the user to enter the number of books that he want to create and allows also him to create these books--------------------*/	
int create_book(Book tab[], int *taille){
	int nb; //We create the integer 'nb'.
	char input[50] = {0}; //We create a string of 50 characters.
	FILE *fichier = NULL; 
	fichier = fopen("book.txt", "r"); //We open the .txt file named 'book' and we can only read it thanks to 'r'.
	do{
		printf(COLOR_GREEN "Combien de livres voulez-vous ajouter ? \n" COLOR_RESET); //We ask to the user how many books he want to create.
		printf("	Choisissez entre 1 et 9. \n"); //We ask to the user to enter a number between 1 and 9.
		scanf("%s", &input); //We recover the character(s) that the user has entered.
	}while(strlen(input) > 1 || ('1' > input[0] || input[0] > '9')); //This loop allows to avoid the user to enter a value other than one between 1 and 9.
	nb = input[0] - '0'; //We transform the ASCII value to a int value. 

	*taille = (*taille) + nb;
	if (tab == NULL){ //If 'tab' is empty, we allocate the necessary memory.
		tab = malloc(sizeof(Book)*(*taille)); //We allocate a memory with the size of the number of books.
	}else{
		tab = realloc(tab, sizeof(Book)*(*taille)); //We re-allocate a memory with the size of the number of books.
	}
	if(tab == NULL){
		printf(COLOR_RED "\nErreur de mémoire ! Impossible de créer / modifier le tableau de livre. \n \n" COLOR_RESET); //We display an error message.
		exit(1); //We close the program.
	}
	for(int i = (*taille)-nb;i < (*taille);i++){ //This loop allows the user to enter the number of books that he has entered in the start of this function.
		int check = 0;
		do{ //This loop alllows the user to don't create a book with the same title as another one.
			printf(COLOR_GREEN "Quel est le nom du livre ? \n" COLOR_RESET); //We ask to the user the title of the book.
			scanf("%s", tab[i].title); //We recover the name of the book that the user has entered.
			check = 1;
		for(int k = 0; k < (*taille)-nb; k++){
				if(strcmp(tab[i].title, tab[k].title) == 0){
					check = 0;
				}
			}
			if(check == 0){
				printf(COLOR_RED "\nErreur ! Impossible de créer ce livre car ce titre existe déjà, veuillez réessayer. \n \n" COLOR_RESET); //We display an error message.
			}
		}while(check == 0);
		printf(COLOR_GREEN "Quel est l'auteur ? \n" COLOR_RESET); //We ask to the user the autor of the book.
		scanf("%s", tab[i].autor); //We recover the autor of the book that the user has entered.
		printf(COLOR_GREEN "Quel est le numero d'identification ? \n" COLOR_RESET); //We ask to the user the identification number of the book.
		scanf("%s", tab[i].num); //We recover the identification number of the book that the user has entered.
		do{
			printf(COLOR_GREEN "Quel est la categorie ? \n" COLOR_RESET); //We ask to the user the category of the book.
			printf("	a : litterature; \n"); //He need to enter 'a' for 'literature'.
			printf("	b : sciences; \n"); //He need to enter 'b' 'sciences'.
			printf("	c : arts; \n"); //He need to enter 'c' for 'art'.
			printf("	d : scolaires; \n"); //He need to enter 'd' for 'school'.
			printf("	e : tourismes et voyages. \n"); //He need to enter 'e' for 'tourism and trip'.
			scanf("%s", tab[i].category);//We recover the category of the book that the user has entered.
		}while(strcmp(tab[i].category, "a") != 0 && strcmp(tab[i].category, "b") != 0 && strcmp(tab[i].category, "c") != 0 && strcmp(tab[i].category, "d") != 0 && strcmp(tab[i].category, "e") != 0); //If the user enter a different value of 'a', 'b', 'c', 'd', or 'e', he need to re-enter a value for the category.
		tab[i].available=001; //We initialize this integer to '1' that means it is available.
	}
	write_book(tab, *taille); //If the user enters all the good values for the book, we go in the function 'write_book'.
}

/*--------------------We create a function that allows us to know how many books there are--------------------*/
int read_book(Book **ptTab){
	FILE* fichier = NULL;
	fichier = fopen("book.txt", "r"); //We open the .txt file named 'book' and we can only read it thanks to 'r'.
	int nbB = 0; //We create a integer 'nbB' that will allows us to count the number of books.
	int c = fgetc(fichier); //We read the first character.
	while(c != EOF){ //While we're not at the end of this file, we go in this condition.
		if(c == '\n'){ //If the character is a return to the line, we go in.
			c = fgetc(fichier); //We read the following character.
			if(c == '\n'){ //If the character is another return to the line, we go in.
				nbB++; //We add one for the number of books.
			}
		}		
		if(c != EOF){ //If we're not at the end of this file, we continue.
			c = fgetc(fichier); //We read the following character.
		}
	}
	nbB++; //We add one for the number of books.

	Book *tab = malloc(nbB*sizeof(Book)); //We allocate the necessary memory.
	if (tab == NULL){ //If it's empty, we display an error message.
		printf(COLOR_RED "\nErreur !\n"); //We display an error message.
		printf("Code d'erreur = %d \n", errno);
		printf("Message d'erreur = %s \n" COLOR_RESET, strerror(errno));
	}
	rewind(fichier); //We go back at the start of the file.
	
	char temp[3] = {0};	
	for(int i=0;i<nbB;i++){ //This loop allows us to recover the different information of the books.
		fscanf(fichier, "%s", tab[i].title); //We recover the title written in the file.
		fscanf(fichier, "%s", tab[i].autor); //We recover the autor written in the file.
		fscanf(fichier, "%s", tab[i].num); //We recover the num written in the file.
		fscanf(fichier, "%s", tab[i].category); //We category the name written in the file.
		fscanf(fichier, "%s", temp); //We available the name written in the file.
		tab[i].available = atoi(temp);
		getc(fichier); //We read the following character.
	}
	*ptTab = tab; //We put a pointer on 'tab'.

	return nbB; //We recover the number of books.
} 
