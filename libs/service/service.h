#ifndef SERVICE_H
#define SERVICE_H

typedef struct Product {
  char name[15];
  char description[50];
  int stock;
} Product;

Product datas[10];
int datasCurrentSize = 0;

// untuk menghitung jumlah file html
int totalFileCounter = 0;

void insertData(){
  if(hasLogin == 1){
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
  } else if(hasLogin == 2){
    printf("Maaf ya, kamu gapunya akses\n\n");
  }
}

void displayData(){
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
  if(hasLogin == 1){
    char target[15], newName[15], newDesc[50];
    int newStock = -1, selected, isValid = 0;

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
  } else if(hasLogin == 2){
    printf("Maaf ya, kamu gapunya akses\n\n");
  }
}

void deleteData(){
  if(hasLogin == 1){
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
  } else if(hasLogin == 2){
    printf("Maaf ya, kamu gapunya akses\n\n");
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
    // jika variabel mode bernilai 1, urutkan barang berdasarkan nama
    // jika variabel mode bernilai 2, urutkan barang berdasarkan stok
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

void publishData(){
  if(hasLogin == 1){
    if(datasCurrentSize == 0){
      printf("\nMaaf, publikasi tidak dapat dibuat karena inventaris kamu kosong\n\n");
    } else {
      char baseFolder[] = "public";
      char folderName[50], fileName[50];

      // mendapatkan tanggal hari ini
      time_t t = time(NULL);
      struct tm tm = *localtime(&t);

      // membuat nama folder menjadi tanggal hari ini
      snprintf(folderName, sizeof(folderName), "%s\\%04d-%02d-%02d", baseFolder, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

      // membuat folder
      if(_mkdir(folderName) == 0){
        totalFileCounter = 0;
      }

      // membuat nama file
      totalFileCounter++;
      snprintf(fileName, sizeof(fileName), "%s\\inventaris_%d.html", folderName, totalFileCounter);

      // membuat file html
      FILE* f = fopen(fileName, "w");
      if(f){
        fprintf(f, "<!DOCTYPE html>\n");
        fprintf(f, "<html lang=\"en\">\n");
        fprintf(f, "<head>\n");
        fprintf(f, "  <meta charset=\"UTF-8\">\n");
        fprintf(f, "  <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n");
        fprintf(f, "  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n");
        fprintf(f, "  <script src=\"https://cdn.tailwindcss.com\"></script>\n");
        fprintf(f, "  <title>Inventaris</title>");
        fprintf(f, "</head>\n");
        fprintf(f, "<body class=\"selection:bg-emerald-700 selection:text-white\">\n");
        fprintf(f, "  <main class=\"px-5 py-20 lg:px-0 max-w-5xl mx-auto\">\n");
        fprintf(f, "    <article class=\"mb-10\">\n");
        fprintf(f, "      <h1 class=\"text-3xl tracking-wide mb-2 text-gray-600\">Inventaris</h1>\n");
        fprintf(f, "      <p class=\"text-gray-600 tracking-wider leading-relaxed\">Lorem ipsum dolor sit amet consectetur adipisicing elit. Laudantium, doloremque!</p>\n");
        fprintf(f, "    </article>\n");
        fprintf(f, "    <div class=\"overflow-x-auto mb-10\">\n");
        fprintf(f, "      <table class=\"min-w-full divide-y divide-gray-200\">\n");
        fprintf(f, "        <thead>\n");
        fprintf(f, "          <tr>\n");
        fprintf(f, "            <th class=\"px-6 py-3 whitespace-nowrap text-start font-medium text-gray-600\">No</th>\n");
        fprintf(f, "            <th class=\"px-6 py-3 whitespace-nowrap text-start font-medium text-gray-600 uppercase\">Nama Barang</th>\n");
        fprintf(f, "            <th class=\"px-6 py-3 whitespace-nowrap text-start font-medium text-gray-600 uppercase\">Jumlah</th>\n");
        fprintf(f, "            <th class=\"px-6 py-3 whitespace-nowrap text-start font-medium text-gray-600 uppercase\">Deskripsi</th>\n");
        fprintf(f, "          </tr>\n");
        fprintf(f, "        </thead>\n");
        fprintf(f, "        <tbody class=\"divide-y divide-gray-200\">\n");

        for(int i = 0; i < datasCurrentSize; i++){
          fprintf(f, "          <tr>\n");
          fprintf(f, "            <th class=\"px-6 py-3 whitespace-nowrap text-start font-medium text-gray-600\">%d</th>\n", i + 1);
          fprintf(f, "            <th class=\"px-6 py-3 whitespace-nowrap text-start font-medium text-gray-600\">%s</th>\n", datas[i].name);
          fprintf(f, "            <th class=\"px-6 py-3 whitespace-nowrap text-start font-medium text-gray-600\">%d</th>\n", datas[i].stock);
          fprintf(f, "            <th class=\"px-6 py-3 text-start font-medium text-gray-600\">%s</th>\n", datas[i].description);
          fprintf(f, "          </tr>\n");
        }
        
        fprintf(f, "        </tbody>\n");
        fprintf(f, "      </table>\n");
        fprintf(f, "    </div>\n");
        fprintf(f, "  </main>\n");
        fprintf(f, "  <footer class=\"text-center py-10 absolute bottom-0 w-full\">\n");
        fprintf(f, "    <p class=\"text-gray-600 tracking-wider font-medium text-sm\">Developed with <span class=\"animate-pulse\">❤</span> by Peri Nurjaman</p>\n");
        fprintf(f, "  </footer>\n");
        fprintf(f, "</body>\n");
        fprintf(f, "</html>\n");
        
        fclose(f);

        printf("Publikasi berhasil!\n");
        printf("Anda dapat melihatnya pada public\\%04d-%02d-%02d\\inventaris_%d.html\n\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, totalFileCounter);
      } else {
        printf("gagal bikin file");
      }     
    }
    
  } else if(hasLogin == 2){
    printf("Maaf ya, kamu gapunya akses\n\n");
  }
}

#endif