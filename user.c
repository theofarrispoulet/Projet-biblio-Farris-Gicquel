#include "header.h"

/*--------------------We create a function that allows the user to connect to the library--------------------*/
int connect(User tab[], int taille, Book books[], int tailleBook){
    char name[50], pw[50]; //We create 2 string of 50 characters that allows us to recover what the user will enter.
	int role; //We create a integer that allows us to recover what the user will enter.
        printf(COLOR_GREEN "Nom d'utilisateur : \n" COLOR_RESET); //We ask to the user to enter his name.
        scanf("%s", name); //We recover the character(s) that the user has entered.
		printf(COLOR_GREEN "Mot de passe : \n" COLOR_RESET); //We ask to the user his password.
		scanf("%s", &pw);  //We recover the character(s) that the user has entered.
	for(int i = 0;i < taille;i++ ){ //This loop allows us to verify if the name that the user has entered exist. We compare what he has entered with all the name that we have in the .txt file 'user'. 
		if(strcmp(name, tab[i].name) == 0){ //If the name that he has entered is equivalentit to one of the name we have in the .txt file 'user', we go in this loop and ask him, his password.
			if(strcmp(tab[i].role, "e") == 0){ //This loop allows us to see if the user is a student or a teacher.
				role = 1; //If the user is a student.
			}
			else{
				role = 2; //If the user is a teacher.
			}
      			if (strcmp(pw, tab[i].pw) != 0){ //This loop allows us to verify if the password is equivalent to his name. If not, we display an error message and go at the beginning of the function 'connect'.
            			//printf(COLOR_RED "\nErreur ! Votre mot de passe ne correspond pas. Veuillez réessayer : \n \n" COLOR_RESET); //We display an error message to prevent him that the password isn't equivalent to his name.
				//connect(tab, taille); //We call the function 'connect'.
			}
			else{ //If his password is equivalent to his name, we go in this loop.
				printf(COLOR_CYAN "\nVous êtes connecté(e). \n" COLOR_RESET); //We display a message to say that he is connected.
           			action(i, books, taille, role, name, tailleBook); //We call the function 'action'.	
			}
		}
		if (i == taille-1){	 //If the name that the user has entered doesn't exist, we display an error message to prevent him and go at the beginning of the function connect.
           		printf(COLOR_RED "\nErreur ! Votre nom d'utilisateur ou mot de passe ne correspond pas. Veuillez réessayer : \n \n" COLOR_RESET); ////We display an error message to prevent him that he has entered a wrong name. 
            		connect(tab, taille,books, tailleBook); //We call the function 'connect'.
		}
	}
	return 0;
}

/*--------------------We create a function that allows to write in a .txt file the different users with their specifications--------------------*/
void write_user(User tab[], int taille){
	FILE* fichier = NULL;
	fichier = fopen("user.txt", "a"); //We open the .txt file named 'user' and we can only write at the end of this file thanks to 'a'.
	if(fichier == NULL) { //If the file doesn't exist, we print an error message.
		printf(COLOR_RED "\nErreur ! Impossible d'ouvrir le fichier ! \n"); //We display an error message.
		printf("Code d'erreur = %d \n", errno);
		printf("Message d'erreur = %s \n" COLOR_RESET, strerror(errno));
		exit(1); //We close the program.
	}
	for(int i = 0;i < taille;i++){ //This loop will work once.
		fprintf(fichier, "\n%s\n", tab[i].name); //We write in the file, the name of the user.
		fprintf(fichier, "%s\n", tab[i].pw); //We write in the file, the password of the user.
		fprintf(fichier, "%s\n", tab[i].role); //We write in the file, the role of the user.
	}
	fclose(fichier); //We close the file.
}

/*--------------------We create a function that allows the user to create an account--------------------*/
int create_user(User tab[], int *taille, Book books[], int tailleBook){
	(*taille)++;
	FILE *fichier = NULL; 
	fichier = fopen("user.txt", "r"); //We open the .txt file named 'user' and we can only read this file thanks to 'r'.
	if(tab == NULL){ //If 'tab' is empty, we allocate the necessary memory.
		tab = malloc(sizeof(User)); //We allocate a memory with the size of the User.
	}else{
		tab = realloc(tab, sizeof(User)*(*taille)); //We allocate more memory with the size of User multiplicate by the number of them.
	}	
	printf(COLOR_GREEN "Quel est votre nom d'utilisateur ? \n" COLOR_RESET); //We ask to the user the name he want to have.
	scanf("%s", tab[(*taille)-1].name); //We recover the name that the user has entered.
	printf(COLOR_GREEN "Quel est votre mot de passe ? \n" COLOR_RESET); //We ask to the user the password he want to have.
	scanf("%s", tab[(*taille)-1].pw); //We recover the password that the user has entered.
	do{
		printf(COLOR_GREEN "Quel est votre role ? \n" COLOR_RESET); //We ask to the user his role.
		printf("	e : étudiant. \n"); //He need to enter '1' if he is a student.
		printf("	p : professeur.\n"); //He need to enter '2' if he is a teacher.
		scanf("%s", tab[(*taille)-1].role); //We recover the character(s) that the user has entered.
	}while(strcmp(tab[(*taille)-1].role, "e") != 0 && strcmp(tab[(*taille)-1].role, "p") != 0); //If the user enter a different value of 'e' or 'p', he need to re-enter a value for his role.
	write_user(tab, *taille); //If the user enters all the good values for his account, we go in the function 'write_user'.
	printf(COLOR_CYAN "\nVotre compte a bien été créé. Veuillez vous connnecter : \n \n" COLOR_RESET);	//We display a message to prevent that the user has succeeded to create his account and to say that he need now to connect.
	connect(tab, *taille, books, tailleBook); //We go in the function 'connect'.
}

/*--------------------We create a function that allows us to know how many users there are--------------------*/
int read_user(User **ptTab){
	FILE* fichier = NULL;
	fichier = fopen("user.txt", "r"); //We open the .txt file named 'user' and we can only read it thanks to 'r'.	
	int nbU = 0; //We create a integer 'nbU' that will allows us to count the number of users.
	int c = fgetc(fichier); //We read the first character.
	while(c != EOF){ //While we're not at the end of this file, we go in this condition.
		if(c == '\n'){ //If the character is a return to the line, we go in.
			c = fgetc(fichier); //We read the following character.
			if(c == '\n'){ //If the character is another return to the line, we go in.
				nbU++; //We add one for the number of users.
			}
		}		
		if(c != EOF){ //If we're not at the end of this file, we continue.
			c = fgetc(fichier); //We read the following character.
		}
	}
	nbU++; //We add one for the number of users.

	User *tab = malloc(nbU*sizeof(User)); //We allocate the necessary memory.
	if (tab == NULL){ //If it's empty, we display an error message.
		printf(COLOR_RED "\nErreur !\n"); //We display an error message.
		printf("Code d'erreur = %d \n", errno);
		printf("Message d'erreur = %s \n" COLOR_RESET, strerror(errno));
	}
	rewind(fichier); //We go back at the start of the file.

	for(int i=0;i<nbU;i++){ //This loop allows us to recover the different information of the users.
		fscanf(fichier, "%s", tab[i].name); //We recover the name written in the file.
		fscanf(fichier, "%s", tab[i].pw); //We recover the pw written in the file.
		fscanf(fichier, "%s", tab[i].role); //We recover the role written in the file.
		fgetc(fichier); //We read the following character.
	}
	*ptTab = tab; //We put a pointer on 'tab'.

	return nbU; //We recover the number of users.
} 
