# Project Semester 1

Program super sederhana untuk mengelola data inventaris

## Creating Data

Menambahkan data ke dalam daftar inventaris, meliputi nama, deskripsi dan jumlah

```bash
px create
```

```bash
px create

Nama Barang   : foo
Deskripsi     : bar
Jumlah        : 123
Data berhasil ditambahkan
```

## Reading Data

Menampilkan seluruh data yang ada pada daftar inventaris

```bash
px show
```

```bash
px show

Data Inventaris

Nama          : foo
Deskripsi     : bar
Jumlah        : 123
```

## Updating Data

Mengubah atau mengedit nilai dari sebuah data, meliputi nama, deskripsi dan jumlah 

```bash
px edit
```

```bash
px edit

Barang yang ingin diedit  : foo
Edit Nama       : ayam
Edit Deskripsi  : ayam rasa ikan balado
Edit Jumlah     : 1945
Edit data telah berhasil
```

## Deleting Data

Menghapus sebuah data dari daftar inventaris

```bash
px delete
```

```bash
px delete

Nama barang yang ingin dihapus  : ayam
Data Berhasil Dihapus
```

## Searching Data

Mencari data spesifik dari daftar inventaris

```bash
px search
```

```bash
px search

Nama Barang : Semangat Belajar
Data tidak ditemukan, kamu mau cari apa sih?
Nama Barang : ayam

Data ditemukan
Nama Barang : ayam
Deskripsi   : ayam rasa ikan balado
Jumlah      : 1945
```

## Sorting Data

Mengurutkan data pada daftar inventaris berdasarkan abjad

```bash
px sort by name
```

```bash
px sort by name

Sorted By Name

Nama        : a
Deskripsi   : aduhai
Jumlah      : 3

Nama        : b
Deskripsi   : aduhai
Jumlah      : 2

Nama        : c
Deskripsi   : aduhai
Jumlah      : 1
```

Mengurutkan data pada daftar inventaris berdasarkan jumlah 

```bash
px sort by stock
```

```bash
px sort by stock

Sorted By Stock

Nama        : c
Deskripsi   : aduhai
Jumlah      : 1

Nama        : b
Deskripsi   : aduhai
Jumlah      : 2

Nama        : a
Deskripsi   : aduhai
Jumlah      : 3
```

## Other Features

Kamu bisa melihat fitur-fitur lainnya dengan perintah dibawah ini:

```bash
px help
```