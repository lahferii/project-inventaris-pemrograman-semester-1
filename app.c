#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// import service yang sudah dibuat
#include "libs/utils/utils.h"
#include "libs/service/service.h"
#include "libs/auth/auth.h"

int main() {
  while(1){
    if(hasLogin == 1){
      char command[30];

      printf("Halo, Selamat Datang\n");
      while(1){
        printf("px ");
        scanf(" %[^\n]", command);

        if(strcmp(command, "show") == 0){
          display();
        } else if(strcmp(command, "create") == 0){
          insertData();
        } else if(strcmp(command, "delete") == 0){
          deleteData();
        } else if(strcmp(command, "edit") == 0){
          updateData();
        } else if(strcmp(command, "search") == 0){
          searchData();
        } else if(strcmp(command, "sort by name") == 0){
          sortData(1);
        } else if(strcmp(command, "sort by stock") == 0){
          sortData(2);
        } else if(strcmp(command, "help") == 0){
          help();
        } else if(strcmp(command, "cls") == 0){
          clearConsole();
        } else if(strcmp(command, ".exit") == 0){
          stopApp();
        } else if(strcmp(command, ".logout") == 0){
          logout();
          break;
        } else {
          printf("Peritah tidak ditemukan!\n\n");
        }
      }
    } else {
      login();
    }
  }
  return 0;
}