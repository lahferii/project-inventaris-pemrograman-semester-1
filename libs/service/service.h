#ifndef SERVICE_H
#define SERVICE_H

typedef struct Product {
  char name[15];
  char description[50];
  int stock;
} Product;

Product datas[10];
int datasCurrentSize = 0;

void insertData(){
  char name[15], desc[50];
  int stock = 0, inputNameLoop = 0;

  while(inputNameLoop == 0){
    printf("Nama Barang\t: ");
    scanf(" %[^\n]", name);
    
    if(strcmp(name, ".cancel") == 0){
      printf("Proses dihentikan\n");
      return;
    }

    if(datasCurrentSize > 0){
      for(int i = 0; i < datasCurrentSize; i++){
        if(strcmp(name, datas[i].name) == 0){
          printf("Barang sudah terdaftar!\n");
          inputNameLoop = 0; // loop lagi
          break;
        } else {
          inputNameLoop = 1; // keluar dari loop
        }
      }
    } else {
      inputNameLoop = 1; // keluar dari loop
    }
  }
  
  printf("Deskripsi\t: ");
  scanf(" %[^\n]", desc);
  if(strcmp(desc, ".cancel") == 0){
    printf("Proses dihentikan\n");
    return;
  }

  while(stock <= 0){
    printf("Jumlah\t\t: ");
    scanf("%d", &stock);
    while (getchar() != '\n');
  }

  strcpy(datas[datasCurrentSize].name, name);
  strcpy(datas[datasCurrentSize].description, desc);
  datas[datasCurrentSize].stock = stock;

  printf("Data berhasil ditambahkan\n");
  datasCurrentSize++;
}

void display(){
  if(datasCurrentSize == 0){
    printf("Inventaris kamu kosong ^_^\n");
  } else {
    printf("\nData Inventaris\n");
    for(int i = 0; i < datasCurrentSize; i++){
      printf("Nama      : %s\n", datas[i].name);
      printf("Deskripsi : %s\n", datas[i].description);
      printf("Jumlah    : %d\n\n", datas[i].stock);
    }
  }
}

void updateData(){
  char target[15], newName[15], newDesc[50];
  int newStock, isStopped = 0, selected = -1;

  while(isStopped == 0){
    printf("Barang yang ingin diedit\t: ");
    scanf(" %[^\n]", target);
    if(strcmp(target, ".cancel") == 0){
      isStopped = 1;
    } else {
      for(int i = 0; i < datasCurrentSize; i++){
      // mencari index dari barang yang ingin diedit
        if(strcmp(target, datas[i].name) == 0){
          selected = i;
          break;
        } else {
          selected = -2;
        }
      }
      // handle jika data ditemukan
      if(selected != -2){
        // input data yang baru
        printf("Edit Nama\t: ");
        scanf(" %[^\n]", newName);
        printf("Edit Deskripsi\t: ");
        scanf(" %[^\n]", newDesc);
        while(newStock <= 0){
          printf("Edit Jumlah\t: ");
          scanf("%d", &newStock);
          while(getchar() != '\n');
        }

        // mengganti nilai pada datas[selected] dengan data yang baru
        strcpy(datas[selected].name, newName);
        strcpy(datas[selected].description, newDesc);
        datas[selected].stock = newStock;

        printf("Edit data telah berhasil\n");
        isStopped = 1;
      } else {
        printf("Data tidak valid, kamu mau hapus apa sih?\n");
      }
    }
  }
}

void deleteData(){
  char target[50];
  int selected = 0, isStopped = 0, isValid = 0;

  while(isStopped == 0){
    printf("Nama barang yang ingin dihapus\t: ");
    scanf(" %[^\n]", target);
    if(strcmp(target, ".cancel") == 0){
      isStopped = 1;
    } else {
      // menemukan index dari nama barang yang diberikan
      for(int i = 0; i < datasCurrentSize; i++){
        if(strcmp(target, datas[i].name) == 0){
          selected = i;
          isValid = 1;
          break;
        }
      }

      // menggeser seluruh index di atas selected
      if(isValid == 1){
        for(int i = selected; i < datasCurrentSize; i++){
          datas[i] = datas[i + 1];
        }

        // mengosongkan nilai index terakhir
        datas[datasCurrentSize - 1].name[0] = '\0';
        datas[datasCurrentSize - 1].description[0] = '\0';
        datas[datasCurrentSize - 1].stock = 0;

        printf("Data Berhasil Dihapus\n");
        datasCurrentSize--;
        isStopped = 1;
      } else {
        printf("Data tidak valid, kamu mau hapus apa sih?\n");
      }
    }
  }
}

#endif