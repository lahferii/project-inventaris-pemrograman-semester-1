#ifndef UTILS
#define UTILS

void help(){
  printf(".logout\t\t keluar dari akun saat ini\n");
  printf(".exit\t\t menghentikan aplikasi\n");
  printf(".cancel\t\t menghentikan proses yang sedang berlangsung\n");
  printf("px cls\t\t Membersihkan layar\n");
  printf("px help       \t menampilkan daftar perintah\n");
  printf("px show data  \t menampilkan data inventaris\n");
  printf("px create data\t membuat data baru\n");
  printf("px edit data\t mengedit data\n");
  printf("px edit data\t menghapus data\n");
}

void clearConsole(){
  printf("\e[1;1H\e[2J");
}

void stopApp(){
  printf("Sampai jumpa lagi, teman...");
  exit(0);
}

#endif