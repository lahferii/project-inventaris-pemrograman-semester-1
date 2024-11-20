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

  printf("\n");
  while(inputNameLoop == 0){
    printf("Nama Barang\t: ");
    scanf(" %14[^\n]", name);
    
    if(strcmp(name, ".cancel") == 0){
      printf("Proses dihentikan\n\n");
      return;
    }

    if(datasCurrentSize > 0){
      for(int i = 0; i < datasCurrentSize; i++){
        if(strcmp(name, datas[i].name) == 0){
          printf("Barang sudah terdaftar!\n\n");
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
    printf("Proses dihentikan\n\n");
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

  printf("Data berhasil ditambahkan\n\n");
  datasCurrentSize++;
}

void display(){
  if(datasCurrentSize == 0){
    printf("\nInventaris kamu kosong ^_^\n\n");
  } else {
    printf("\nData Inventaris\n\n");
    for(int i = 0; i < datasCurrentSize; i++){
      printf("Nama      : %s\n", datas[i].name);
      printf("Deskripsi : %s\n", datas[i].description);
      printf("Jumlah    : %d\n\n", datas[i].stock);
    }
  }
}

void updateData(){
  char target[15], newName[15], newDesc[50];
  int newStock, selected, isValid = 0;

  printf("\n");
  while(1){
    printf("Barang yang ingin diedit\t: ");
    scanf(" %[^\n]", target);
    if(strcmp(target, ".cancel") == 0){
      printf("Proses dihentikan\n\n");
      return;
    } else {
      for(int i = 0; i < datasCurrentSize; i++){
      // mencari index dari barang yang ingin diedit
        if(strcmp(target, datas[i].name) == 0){
          selected = i;
          isValid = 1;
          break;
        }
      }
      // handle jika data ditemukan
      if(isValid == 1){
        // input data yang baru
        printf("Edit Nama\t: ");
        scanf(" %[^\n]", newName);
        if(strcmp(newName, ".cancel") == 0){
          printf("Proses dihentikan\n\n");
          return;
        }
        
        printf("Edit Deskripsi\t: ");
        scanf(" %[^\n]", newDesc);
        if(strcmp(newDesc, ".cancel") == 0){
          printf("Proses dihentikan\n\n");
          return;
        }

        while(newStock <= 0){
          printf("Edit Jumlah\t: ");
          scanf("%d", &newStock);
          while(getchar() != '\n');
        }

        // mengganti nilai pada datas[selected] dengan data yang baru
        strcpy(datas[selected].name, newName);
        strcpy(datas[selected].description, newDesc);
        datas[selected].stock = newStock;

        printf("Edit data telah berhasil\n\n");
        return;
      } else {
        printf("Data tidak valid, kamu mau edit apa sih?\n\n");
      }
    }
  }
}

void deleteData(){
  char target[50];
  int selected = 0, isValid = 0;

  while(1){
    printf("Nama barang yang ingin dihapus\t: ");
    scanf(" %[^\n]", target);

    if(strcmp(target, ".cancel") == 0){
      printf("Proses dihentikan\n\n");
      return;
    } else {
      // mencari index dari nama barang yang diberikan
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

        datasCurrentSize--;
        printf("Data Berhasil Dihapus\n\n");
        return;
      } else {
        printf("Data tidak valid, kamu mau hapus apa sih?\n\n");
      }
    }
  }
}

void searchData(){
  char searched[15];
  int found = -1;

  while(1){
    printf("Nama Barang\t: ");
    scanf("%s", searched);
    if(strcmp(searched, ".cancel") == 0){
      printf("Proses dihentikan\n\n");
      return;
    }
    
    for(int i = 0; i < datasCurrentSize; i++){
      if(strcmp(searched, datas[i].name) == 0){
        found = i;
        break;
      }
    }

    if(found >= 0){
      printf("\nData Ditemukan\n");
      printf("Nama Barang\t: %s\n", datas[found].name);
      printf("Deskripsi\t: %s\n", datas[found].description);
      printf("Jumlah\t\t: %d\n\n", datas[found].stock);
      return;
    } else {
      printf("Data Tidak Ditemukan, kamu mau cari apa sih?\n");
    }
  }
}

void sortData(int mode){
  Product sorted[datasCurrentSize];
  Product temp[1];

  for(int i = 0; i < datasCurrentSize; i++){
    sorted[i] = datas[i];
  }

  if(datasCurrentSize == 0){
    printf("\nInventaris kamu kosong ^_^\n\n");
  } else {
    // jika mode bernilai 1, urutkan barang berdasarkan nama
    // jika mode bernilai 2, urutkan barang berdasarkan stok
    if(mode == 1){
      printf("\nSorted By Name\n\n");

      for(int i = 0; i < datasCurrentSize; i++){
        for(int j = 0; j < datasCurrentSize - i - 1; j++){
          if(strcmp(sorted[j].name, sorted[j + 1].name) > 0){
            temp[0] = sorted[j];
            sorted[j] = sorted[j + 1];
            sorted[j + 1] = temp[0];
          }
        }
      }
    } else if(mode == 2){
      printf("\nSorted By Stock\n\n");

      for(int i = 0; i < datasCurrentSize; i++){
        for(int j = 0; j < datasCurrentSize - i - 1; j++){
          if(sorted[j].stock > sorted[j + 1].stock){
            temp[0] = sorted[j];
            sorted[j] = sorted[j + 1];
            sorted[j + 1] = temp[0];
          }
        }
      }
    }

    for(int i = 0; i < datasCurrentSize; i++){
      printf("Nama        : %s\n", sorted[i].name);
      printf("Deskripsi   : %s\n", sorted[i].description);
      printf("Stock       : %d\n\n", sorted[i].stock);
    }
  }
}

#endif