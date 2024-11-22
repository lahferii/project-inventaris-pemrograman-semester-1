#ifndef AUTH_H
#define AUTH_H

int hasLogin = 0;

int login(){
  char username[6];
  char password[12];

  while(hasLogin == 0){
    printf("username\t: ");
    scanf(" %[^|\n]", username);
  
    printf("password\t: ");
    scanf(" %[^|\n]", password);
    
    if(strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0){
      hasLogin = 1;
      clearConsole();
    } else if(strcmp(username, "pey") == 0 && strcmp(password, "pey123") == 0){
      hasLogin = 2;
      clearConsole();
    } else {
      clearConsole();
      printf("Username atau password tidak valid!\n");
    }
  }
}

void logout(){
  hasLogin = 0;
  clearConsole();
  printf("Logout Berhasil\n");
}

#endif