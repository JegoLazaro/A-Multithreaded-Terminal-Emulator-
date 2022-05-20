//ALFONSO, ALESSANDRO K.
//LAZARO, JOSE GABRIEL R.
//CSOPESY - S11 
//SIR ARREN ANTIOQUIA

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <limits.h>
#include <pthread.h>
#include <windows.h>
#define MAX_LEN 100
#define LSIZ 128 
#define RSIZ 10 
#define WORDS 20  
#define _BSD_SOURCE


/*
THIS FUNCTION GETS USER INPUT
*/
int n_input(char *s_ptr) {
	char string[120];
	scanf("%[^\n]%*c", string);
	int size = strlen(string);
	if (size != 0) {
		strcpy(s_ptr, string);
	    return 0;
	} 
}

/*
THIS FUNCTION SLICES THE INPUTTED USER COMMAND AND TEXT INPUT OF THE USER
*/
void slicer(char *command, char *input, char *input2){
	char splitter[] = " ";
	char *s_input;
	
	if(strchr(input, ' ') != NULL){
	    char *copy = (char*) calloc(strlen(input) + 1, sizeof(char));
	    strcpy(copy, input);
		strtok_r (copy, " ", &s_input);
	
	    strcpy(command, copy);
	    strcpy(input2, s_input);
	    free(copy);
	}
  
  	else strcpy(command, input);
  
}

/*
THIS FUNCTION CONVERT A CHARACTER TO AN INTEGER DATA TYPE
*/
int charToInt(char *c){return *c - '0';}

/*
THIS FUNCTION VALIDATES ALL THE COMMANDS OF MyOS AND SET nNum WHICH COMMAND TO EXECUTE
*/
void commands(char *command, int *nNum){
	
	if (!strcmp(command, "say")) 
  		*nNum = 1;
  	else if (!strcmp(command, "cls")) 
  			*nNum = 2;
  		else if (!strcmp(command, "dir")) 
  				*nNum = 3;
  			else if (!strcmp(command, "pwd")) 
  					*nNum = 4;
  				else if (!strcmp(command, "time")) 
  						*nNum = 5;
  					else if (!strcmp(command, "title")) 
  							*nNum = 6;
  						else if (!strcmp(command, "color")) 
  								*nNum = 7;
  							else if (!strcmp(command, "mkfldr")) 
  									*nNum = 8;
  								else if (!strcmp(command, "find")) 
  										*nNum = 9;
  									else if (!strcmp(command, "open")) 
  											*nNum = 10;
  										else if (!strcmp(command, "copy")) 
  												*nNum = 11;
 											 else if (!strcmp(command, "rename")) 
  													*nNum = 12;
  												else if (!strcmp(command, "delete")) 
  														*nNum = 13;
  													else if (!strcmp(command, "sort")) 
  															*nNum = 14;
  														else if (!strcmp(command, "marquee")) 
  																*nNum = 15;
  															else if (!strcmp(command, "exit")) 
  																	*nNum = 16;
}

/*
THIS FUNCTION EXECUTES SLICER AND THE COMMANDS AFTER THE USER INPUT
*/
int execute(char *input, char *command, char *input2, int *nNum) {
  
  slicer(command, input, input2);
  commands(command, nNum);

  return 1;
}

/*
THIS FUNCTION CONTAINS ALL THE COMMANDS IN MyOS
*/
void command_handler(int nNum, char *input) {
  char cwd[PATH_MAX];
  char filename[100], title[100],  fname[100];
  char* folder[100];
  
  FILE *fptr = NULL; 
  FILE *f = NULL;
  int nLinesToSort = 0, numLines = 0, i = 0, j, tot = 0, checker;
  char line[WORDS][MAX_LEN];
  
  	if(nNum == 1){	// SAY COMMAND
  		if(!strlen(input)) printf("Invalid");
      	else printf("%s\n", input);
	}
	
	  else if(nNum == 2){	// CLS COMMAND
		printf("cls executing...");
  		system("cls");	
	}
	
	else if(nNum == 3){ 	// DIR COMMAND
		struct dirent *currDir;
      	struct stat acc;
		DIR *dr = opendir(".");
		
		if(dr){
      		while ((currDir = readdir(dr)) != NULL){
        		stat(currDir->d_name, &acc);
	        	printf("Filename: %s\n", currDir->d_name);
	        	printf("File size: %d Bytes\n", acc.st_size);
	        	printf("Created on: %s\n\n", ctime(&acc.st_mtime));
     	 	}
  		}
  		else if(dr == NULL){
        	printf("Directory cannot be opened." );
      	}
      closedir(dr);
	}
	  
	else if(nNum == 4){ 	// PWD COMMAND
			if (getcwd(cwd, sizeof(cwd)) != NULL) {
        		printf("Current working dir: %s\n", cwd);
      		} 
		 	else {
        		perror("getcwd() error");
      		}
	}
	
	else if(nNum == 5){ 	// TIME COMMAND
  			time_t rawtime;
      		struct tm * timeinfo;
      		time ( &rawtime );
      		timeinfo = localtime ( &rawtime );
      		printf ( "Current local time and date: %s", asctime (timeinfo) );
	}
	
	else if(nNum == 6){	// TITLE COMMAND
		HANDLE handleConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTitle(input);
		while(1){
			printf("Window title successful changed to %s\n", input);
			break;
		}
	}
	
	else if(nNum == 7){ 	// COLOR COMMAND
		char str[100];//color1
		char *str2;//color2
	    
		strcpy(str, input);
		strtok_r(str, " ", &str2);
	    
	    char x[15] = "color ";
	    x[6] = '\0';
	    x[7] = '\0';
	    
	    if(!strcmp(str, "black"))
			x[6] = '0';
	    else if(!strcmp(str, "blue"))
		    x[6] = '1';
	    else if(!strcmp(str, "green"))
		  	x[6] = '2';
	    else if(!strcmp(str, "aqua")) 
		  	x[6] = '3';
	    else if(!strcmp(str, "red"))  
		  	x[6] = '4';
	    else if(!strcmp(str, "purple"))  
		  	x[6] = '5';
	    else if(!strcmp(str, "yellow"))  
		  	x[6] = '6';
	    else if(!strcmp(str, "white"))  
		  	x[6] = '7';
	    else if(!strcmp(str, "gray")) 
		  	x[6] = '8';
		  	
	 	fflush(stdin);
	 		
	    if(!strcmp(str2, "black"))
			x[7] = '0';
	    else if(!strcmp(str2, "blue"))  
			x[7] = '1';
	    else if(!strcmp(str2, "green")) 
			x[7] = '2';
	    else if(!strcmp(str2, "aqua"))  
			x[7] = '3';
	    else if(!strcmp(str2, "red"))  
			x[7] = '4';
	    else if(!strcmp(str2, "purple"))  
			x[7] = '5';
	    else if(!strcmp(str2, "yellow"))  
			x[7] = '6';
	    else if(!strcmp(str2, "white"))  
			x[7] = '7';
	    else if(!strcmp(str2, "gray")) 
			x[7] = '8';
			
	    system(x);
	}
	
	else if(nNum == 8){		// MKFLDR COMMAND
		mkdir(input);
		printf("%s folder successfully created\n", input);
	}
	else if(nNum == 9){	
	  	struct dirent *currDir;
      	struct stat acc;
		DIR *dr = opendir(".");
		
		if(dr){
      		while ((currDir = readdir(dr)) != NULL){
      			if(strcmp(currDir->d_name, input) == 0){
		        	stat(currDir->d_name, &acc);
		        	printf("Filename: %s\n", currDir->d_name);
		        	printf("File size: %d bytes\n", acc.st_size);
		        	printf("Created on: %s\n\n", ctime(&acc.st_mtime));
		        	break;
	        }
     		}
  		}
  		else if(dr == NULL){
        	printf("Directory cannot be opened." );
      	}
      	closedir(dr);

	}
	
	else if(nNum == 10){		// OPEN COMMAND
		fptr = fopen(input, "r");
		if(fptr == NULL){
			printf("Error! Filename does not exist");                
		}
	
		while(fgets(line[i], MAX_LEN, fptr)) {
			line[i][strlen(line[i]) - 1] = '\0';
    		i++;
		}

		tot = i;    
		for(i = 0; i < tot; ++i){
  			printf(" %s\n", line[i]);
		}
		
		printf("\n");
		fclose(fptr);
	}
	
	else if (nNum == 11){ 	// COPY COMMAND !!!! MISSING FEATURE !!!!!!
		char file_1[128];
	    char *file_2;
	    char line[RSIZ][LSIZ];
				
		//SPLIT FNAME INTO 2
		strcpy (file_1, input);
		strtok_r (file_1, " ", &file_2);
		fptr = fopen(file_1, "r");
		
		while(fgets(line[i], MAX_LEN, fptr)) {
			line[i][strlen(line[i]) - 1] = '\0';
    		i++;
		}
		tot = i; 
		fclose(fptr);
		//!!!!---- UPDATED ----!!!!
		fptr = fopen(file_2, "r");
		
		if(fptr == NULL){
			printf("ERROR! No filename named '%s' in directory\n", file_2);
			fclose(fptr);
		}
		else {
			fptr = fopen(file_2, "w");
			   
			for(i = 0; i < tot; ++i){
	  			fprintf(fptr,"%s\n", line[i]);
			}
			
			fclose(fptr);
		
	      
	  		printf("File copied successfully.\n");
	  	}
	  	//!!!!---- UPDATED ----!!!!
	}
	
	else if(nNum == 12){ 	// RENAME COMMAND 	
		char oldname[128];
	    char *newname;
				
		//SPLIT FNAME INTO 2
		strcpy (oldname, input);
		strtok_r (oldname, " ", &newname);
			
		if(rename(oldname, newname) == 0){
			printf("Successfully renamed %s to %s\n",oldname, newname);
		}
		
		else{
			printf("Failed to rename %s\n", oldname);
		}
	
	}
	else if(nNum == 13){ 	// DELETE COMMAND
		if(remove(input) == 0){
			printf("File successfully removed\n");
		}
		else{
			printf("File not removed\n");
		}	
	}
	
	else if(nNum == 14){		// SORT COMMAND
	    char sort[50];
	    char *nLines;
		char line[RSIZ][LSIZ];

		strtok_r (input, " ", &nLines);
		
		i = 0;
		int n = charToInt(nLines);
		fptr = fopen(input, "r");
		
		while(fgets(line[i], MAX_LEN, fptr) && i != n) {
			line[i][strlen(line[i]) - 1] = '\0';
	    	i++;
		}
	  
		nLinesToSort = i;  
		for(i = 0; i < nLinesToSort; i++){
	    	printf("%s\n", line[i]);
		}
		printf("\n");
		fclose(fptr);
		f = fopen(input, "w");
	
		char temp[50];
	
		for(i = 0; i < nLinesToSort; i++){
			for(j = 0; j < nLinesToSort-1-i; j++){
	     	 if(strcmp(line[j], line[j+1]) > 0){
	        	strcpy(temp, line[j]);
	        	strcpy(line[j], line[j+1]);
	        	strcpy(line[j+1], temp);
	      	}
	   	 }
		}
		for(i = 0; i < nLinesToSort; i++){
	   	 	printf("%s\n", line[i]);
	    	fprintf(f,"%s\n", line[i]);
		}
	  
		fclose(fptr);		 
	}
	

	else if(nNum == 15){ 	// MARQUEE COMMAND
        char space[1000] = "                                                                                                            ";
		char sort[50];
	    char *nLines;
	    
		strcpy (sort, input);
        size_t s_word = strlen(input), space_size = strlen(space), i_size = s_word + space_size;

        size_t position = 0, i; 

        while (1){
                for (i = 0u; i < (space_size - 1u); i++)
                        space[i] = space[i + 1u];
                        
                space[space_size - 1u] = position < s_word ? input[position] : ' ';

                position = (position + 1u) % i_size;
                fprintf(stderr, "           \r%s", space);
                usleep(50000);
        }
	}
	  
	else if(nNum == 16){ 	// EXIT COMMAND
	  	printf("Thank you for using MyOS. Goodbye.");
	  	exit(0);
	}

}

int main() {
  char input[120] = "Temporary", command[120] = "Temporary", input2[120] = "Temporary";
  
  int n_execute = 0, n = 0;
 
  do{
	    printf("MyOS> ");
	    if(n_input(input)) continue;
	    n_execute = execute(input, command, input2, &n);
	    command_handler(n, input2);
  	}while(1);
  
  return 0;
}
