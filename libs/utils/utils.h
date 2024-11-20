#ifndef UTILS
#define UTILS

void help(){
  printf("\nDaftar perintah\n");
  printf(".logout\t\t keluar dari akun saat ini\n");
  printf(".exit\t\t menghentikan aplikasi\n");
  printf(".cancel\t\t menghentikan proses yang sedang berlangsung\n");
  printf("px cls\t\t Membersihkan layar\n");
  printf("px help\t\t menampilkan daftar perintah\n");
  printf("px show\t\t menampilkan data inventaris\n");
  printf("px search\t mencari data pada inventaris\n");
  printf("px create\t membuat data baru\n");
  printf("px edit\t\t mengedit data\n");
  printf("px delete\t menghapus data\n");
  printf("\n");
}

void clearConsole(){
  system("cls");
}

void stopApp(){
  printf("\nSampai jumpa lagi, teman...\n\n");
  exit(0);
}

#endif