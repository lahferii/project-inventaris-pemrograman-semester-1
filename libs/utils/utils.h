#ifndef UTILS
#define UTILS

void help(){
  if(hasLogin == 1){
    printf("\nDaftar perintah\n");
    printf("px show\t\t\t menampilkan data inventaris\n");
    printf("px search\t\t mencari data pada inventaris\n");
    printf("px create\t\t membuat data baru\n");
    printf("px edit\t\t\t mengedit data\n");
    printf("px delete\t\t menghapus data\n");
    printf("px publish\t\t membuat website untuk menampilkan data inventaris\n");
    printf("px sort by name\t\t mengurutkan data sesuai abjad\n");
    printf("px sort by stock\t mengurutkan data sesuai jumlah stok\n");
    printf("px cls\t\t\t Membersihkan layar\n");
    printf("px help\t\t\t menampilkan daftar perintah\n");
    printf(".logout\t\t\t keluar dari akun saat ini\n");
    printf(".exit\t\t\t menghentikan aplikasi\n");
    printf(".cancel\t\t\t menghentikan proses yang sedang berlangsung\n");
    printf("\n");
  } else if(hasLogin == 2){
    printf("\nDaftar perintah\n");
    printf("px show\t\t\t menampilkan data inventaris\n");
    printf("px search\t\t mencari data pada inventaris\n");
    printf("px sort by name\t\t mengurutkan data sesuai abjad\n");
    printf("px sort by stock\t mengurutkan data sesuai jumlah stok\n");
    printf("px cls\t\t\t Membersihkan layar\n");
    printf("px help\t\t\t menampilkan daftar perintah\n");
    printf(".logout\t\t\t keluar dari akun saat ini\n");
    printf(".exit\t\t\t menghentikan aplikasi\n");
    printf(".cancel\t\t\t menghentikan proses yang sedang berlangsung\n");
    printf("\n");
  }
}

void clearConsole(){
  system("cls");
}

void stopApp(){
  printf("\nSampai jumpa lagi, teman...\n\n");
  exit(0);
}

#endif