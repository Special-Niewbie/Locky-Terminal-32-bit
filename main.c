/*
Locky Terminal 32-bit

Copyright (C) 2023 Special-Niewbie Softwares

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation version 3.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#include <windows.h>

#define MIN_PASSWORD_LEN 4
#define MAX_PASSWORD_LEN 120

// Allowed characters for passwords
char allowed_chars[256];
int allowed_chars_len = 0;

// Function declaration to check if the filename is valid
int is_valid_filename(const char *filename);

char *generate_password(const char *username, size_t len, bool include_lowercase, bool include_uppercase, bool include_numbers, bool include_symbols){
	
    const char lowercase_chars[] = "abcdefghijklmnopqrstuvwxyz";
    const char uppercase_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char number_chars[] = "0123456789";
	const char symbol_chars[] = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
	int allowed_chars_len = 0;
	int password_len = 0;
	char password[MAX_PASSWORD_LEN + 1];
	

if (include_lowercase) {
for (int i = 0; i < strlen(lowercase_chars); i++) {
allowed_chars[(allowed_chars_len)++] = lowercase_chars[i];
}
}
if (include_uppercase) {
for (int i = 0; i < strlen(uppercase_chars); i++) {
allowed_chars[(allowed_chars_len)++] = uppercase_chars[i];
}
}
if (include_numbers) {
for (int i = 0; i < strlen(number_chars); i++) {
allowed_chars[(allowed_chars_len)++] = number_chars[i];
}
}
if (include_symbols) {
for (int i = 0; i < strlen(symbol_chars); i++) {
allowed_chars[(allowed_chars_len)++] = symbol_chars[i];
}
}

// Include random characters at the end of the password
while (password_len < len) {
password[password_len++] = allowed_chars[rand() % allowed_chars_len];
}

password[password_len] = '\0';

// Shuffle the characters in the password
for (int i = 0; i < password_len; i++) {
int j = rand() % password_len;
char temp = password[i];
password[i] = password[j];
password[j] = temp;
}

char *res = malloc((password_len + 1) * sizeof(char));
strcpy(res,password);
return res;
}

int main(int argc, char *argv[]) {
                                                                                
printf("LOCKY TERMINAL 32-bit  ver. 1.0\n");
printf("\t              by \n");
printf("\t    @@@@@        Special-Niewbie \n");
printf("\t  &@@@  *@@@. \n");
printf("\t /@@      .@@@@@@@@@@@@* \n");
printf("\t .@@      ,@@(((@@@&@@(  \n");
printf("\t  *@@@@(@@@@    &@@%@@   \n");
printf("\t     *@@@.          @/   \n");
printf("\t                         \n\n");
                                                                                
printf("*****************************************************************\n");
printf("* I truly appreciate you using my products and if you find      *\n"); 
printf("* them useful for your privacy needs or daily usage, a small    *\n"); 
printf("* donation as a friendly gesture would greatly help me to       *\n");
printf("* continue improving and providing valuable privacy tools in    *\n");
printf("* my mission for the future. I am grateful for your belief and  *\n");
printf("* for choosing to support me. For more info on how to Donate    *\n");
printf("* through PayPal or Ko-fi, please visit my GitHub profile at:   *\n");
printf("*          --- https://github.com/Special-Niewbie ---           *\n");
printf("*****************************************************************\n\n");
start:
	srand(time(0));
	char username[256];
	char input[256];
	int len;
   // Ask the user to enter the username
   printf(" Write a Username: ");
   fgets(username, 256, stdin);
   // Remove the newline character from the input string
   username[strcspn(username, "\r\n")] = 0;
   // Declaration for the while loop
   bool valid_input = false;

// Ask the user to enter the desired length of the password
while (!valid_input) {
    printf("\n Write the length of the Password (from %d to %d): ", MIN_PASSWORD_LEN, MAX_PASSWORD_LEN);
    fgets(input, 256, stdin);
    len = atoi(input);
    if (len >= MIN_PASSWORD_LEN && len <= MAX_PASSWORD_LEN) {
        valid_input = true;
    }
    else {
        printf(" !!! The Password length is invalid. Please, insert a number from 4 to 120! \n");
    }
}
    
bool include_lowercase = false;
bool include_uppercase = false;
bool include_numbers = false;
bool include_symbols = false;

// Ask the user to choose which characters to include in the password
valid_input = false;
printf("\n Include lowercase characters in password? (Y/n): ");
while (!valid_input) {
    fgets(input, 4, stdin);
    input[strcspn(input, "\n")] = 0;
    if (strcmp(input, "Y") == 0) {
    	printf("\t\t\tOK lowercase\n");
        include_lowercase = true;
        valid_input = true;
    } else if (strcmp(input, "n") == 0) {
    	printf("\t\t\tno lowercase\n");
        include_lowercase = false;
        valid_input = true;
    } else {
        printf(" !!! Invalid input. Insert 'Y'(yes) or 'n'(no): ");
    }
}
valid_input = false;
printf(" Include UPPERCASE characters in password? (Y/n): ");
while (!valid_input) {
    fgets(input, 4, stdin);
    input[strcspn(input, "\n")] = 0;
    if (strcmp(input, "Y") == 0) {
    	printf("\t\t\tOK UPPERCASE\n");
        include_uppercase = true;
        valid_input = true;
    } else if (strcmp(input, "n") == 0) {
    	printf("\t\t\tno UPPERCASE\n");
        include_uppercase = false;
        valid_input = true;
    } else {
        printf(" !!! Invalid input. Insert 'Y'(yes) or 'n'(no): ");
    }
}
valid_input = false;
printf(" Include Numbers in Password? (Y/n): ");
while (!valid_input) {
    fgets(input, 4, stdin);
    input[strcspn(input, "\n")] = 0;
    if (strcmp(input, "Y") == 0) {
    	printf("\t\t\tOK Numbers\n");
        include_numbers = true;
        valid_input = true;
    } else if (strcmp(input, "n") == 0) {
    	printf("\t\t\tno Numbers\n");
        include_numbers = false;
        valid_input = true;
    } else {
        printf(" !!! Invalid input. Insert 'Y'(yes) or 'n'(no): ");
    }
}
valid_input = false;
printf(" Include Symbols in password? (Y/n): ");
while (!valid_input) {
    fgets(input, 4, stdin);
    input[strcspn(input, "\n")] = 0;
    if (strcmp(input, "Y") == 0) {
    	printf("\t\t\tOK Symbols\n");
        include_symbols = true;
        valid_input = true;
    } else if (strcmp(input, "n") == 0) {
    	printf("\t\t\tno Symbols\n");
        include_symbols = false;
        valid_input = true;
    } else {
        printf(" !!! Invalid input. Insert 'Y'(yes) or 'n'(no): ");
    }
}

char *password = generate_password(username, len, include_lowercase, include_uppercase, include_numbers, include_symbols);
// Use a while loop to continue asking the user for a valid password length until they do
if (password) {
    printf("\n\n ---- Generated Password: %s", password);
}
// Ask the user if they want to save the password in a file
printf("\n\n Do you want to save the password in a file? (Y/n): ");
char save_choice[3];
scanf("%s", save_choice);
int c;
while ((c = getchar()) != '\n' && c != EOF);
if (strcmp(save_choice, "Y") != 0 && strcmp(save_choice, "n") != 0) {
    printf(" !!! Please, enter valid input 'Y'(yes) or 'n'(no): ");
    scanf("%s", save_choice);
    while ((c = getchar()) != '\n' && c != EOF);
}
// Option in case of NO selection
char opzione[6];
if (strcmp(save_choice, "n") == 0) {
    printf("\n\n Do you want to close the program or generate a new Username and Password? 'N'(new) or 'c'(close): ");
    do {
    // Clear the buffer for "opzione" before reading user input
    memset(opzione, 0, sizeof(opzione));
    scanf("%s", opzione);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    if (strcmp(opzione, "c") != 0 && strcmp(opzione, "N") != 0) {
        printf(" !!! Invalid input. Insert 'N'(new) or 'c'(close): ");
    }
} while (strcmp(opzione, "c") != 0 && strcmp(opzione, "N") != 0);

// Close the program or generate a new username and password based on the user's choice
if (strcmp(opzione, "c") == 0) {
    return 0;
} else if (strcmp(opzione, "N") == 0) {
	printf("\n");
    goto start;
}
// Free the memory allocated for the password
free(password);

return 0;
}
else{
  (strcmp(save_choice, "Y") == 0);
  printf(" Enter the file name: ");
  char filename[265];
  fgets(filename, 265, stdin);
  
  // Remove the newline character from the filename
  filename[strcspn(filename, "\n")] = 0;

  // Check if the filename is valid
  if (!is_valid_filename(filename) && strcmp(strrchr(filename, '.'), ".txt")) {
    fprintf(stderr, " !!! Invalid filename. Enter a valid name:\n");
    return 1;
  }

// Open the file in write mode
  char filename_with_ext[265];
  sprintf(filename_with_ext, "%s.txt", filename);
  FILE *file = fopen(filename_with_ext, "w+");
  if (file == NULL) {
    perror(" Error opening file");
    return 1;
  }

  fprintf(file, "Username: \n%s\n\nPassword: \n%s", username, password);

  fclose(file);

  printf("\n\n ###############  C o n g r a t u l a t i o n  ###############\n\n Username and Password saved in the file: `%s`\n", filename_with_ext);
  
  // Ask the user if they want to close the program or generate a new username and password
  printf("\n\nDo you want to close the program or generate a new Username and Password? 'N'(new) or 'c'(close): ");
char opzione[6];

do {
    // Clear the buffer for "opzione" before reading user input
    memset(opzione, 0, sizeof(opzione));
    scanf("%s", opzione);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    if (strcmp(opzione, "c") != 0 && strcmp(opzione, "N") != 0) {
        printf(" !!! Invalid input. Insert 'N'(new) or 'c'(close):  ");
    }
} while (strcmp(opzione, "c") != 0 && strcmp(opzione, "N") != 0);

// Close the program or generate a new username and password based on the user's choice
if (strcmp(opzione, "c") == 0) {
    return 0;
} else if (strcmp(opzione, "N") == 0) {
	printf("\n");
    goto start;
}
// Free the memory allocated for the password
free(password);

return 0;
	}

}

int is_valid_filename(const char *filename) {
    // Check that the filename is not too long
    if (strlen(filename) > 260) {
        return 0;
    }
    // Check that the filename does not contain invalid characters
    for (size_t i = 0; i < strlen(filename); i++) {
        if (!isalnum(filename[i]) && !isspace(filename[i]) && filename[i] != '.') {
            return 0;
        }
    }
    return 1;
}
