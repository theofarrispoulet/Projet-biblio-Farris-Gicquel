#include "header.h"

/*--------------------We create the main function, display a welcome message to the user and call the function 'start'--------------------*/ 
int main(){
	int *taille;
	printf("______ _ _     _ _       _   _    ____            \n"); //these 8 lines display a welcome message that say 'bibliothèque' when the user open the program.
	printf("| ___ (_) |   | (_)     | | | |   \\___\\                 \n");
	printf("| |_/ /_| |__ | |_  ___ | |_| |__   ___  __ _ _   _  ___  \n");
	printf("| ___ \\ |  _ \\| | |/ _ \\| __|  _ \\ / _ \\/ _\\ | | | |/ _ \\ \n");
	printf("| |_/ / | |_) | | | (_) | |_| | | |  __/ (_| | |_| |  __/ \n");
	printf("\\____/|_|____/|_|_|\\___/ \\__|_| |_|\\___|\\___ |\\____|\\___| \n");
	printf("                                           | |           \n");
	printf("                                           |_|           \n");
	start(taille); //we call the function 'start'.
	return 0;
}
