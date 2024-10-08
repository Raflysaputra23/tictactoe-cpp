#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <limits>
#include <algorithm>
using namespace std;


int cekWinner(int user[], char role) {
	int win = 0;
	int winner[8][3] = {{1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9},{1,5,9},{3,5,7}};
	int length = sizeof(winner) / sizeof(winner[0]); 

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length - 4; j++) {
			if (winner[i][j] == user[0]) {
				win++;
			}
			if (winner[i][j] == user[1]) {
				win++;
			}
			if (winner[i][j] == user[2]) {
				win++;
			}
			if (winner[i][j] == user[3]) {
				win++;
			}
			if (winner[i][j] == user[4]) {
				win++;
			}
		}
	}
	if (win == 3) {
		cout << role << " menang" << endl;
		return 0;
	} else {
		return 1;
	}
}

int main() {
	srand(time(0));
	int baris, kolom, pilihan, pilRole, end = 1;
	int a = 2, b = 4, c = 6, k = 0, i = 0, j = 0, u1 = 0, u2 = 0, cek = 1;
	int cekPilihan[9] = {0};
	int user1[5] = {10,10,10,10,10}, user2[5] = {10,10,10,10,10};
	char start = 'X', role, xo[9];
	baris = kolom = 7;

	cout << "=========== Selamat Datang di game tictactoe ===========" << endl << endl;
	do {

		cout << "Silahkan pilih player (1: O atau 2: X)" << endl
			 << "Pilih sesuai dengan opsi diatas: ";
		cin >> pilRole;
		cout << endl << endl;

		// MENGECEK ROLE
		if (pilRole == 1 || pilRole == 2) {
			cek = 0;
			role = (pilRole == 1) ? 'O' : 'X';
		} else {
			cout << "Masukkan 1 atau 2 sesuai opsinya!!" << endl << endl;
			cek = 1;
		}

	} while(cek);

	// INISIALISASI XOXO
	for (int i = 0; i < 9; i++){
		xo[i] = '0' + (i + 1);
	}

	// MENENTUKAN SIAPA YANG MAIN DULUAN
	start = (rand() % 2 == 0) ? 'X' : 'O';

	do {
		k = 0;
		cek = 1;

		// SORTING DATA
		sort(user1, user1 + 5);
		sort(user2, user2 + 5);


		// TENTUKAN SIAPA YANG MENANG
		if (start == 'X') {
			if (user2[2] != 10) {
				end = cekWinner(user2, start);
			}
		} else {
			if (user1[2] != 10) {
				end = cekWinner(user1, start);
			}
		}

		// PAPAN BOARD TICTACTOE
		for (i = 1; i <= baris; i++){
			for (j = 1; j <= kolom; ++j){
				if (i % 2 == 1){
					if(j <= 3) cout << " " << "---";
				} else {
					if(j % 2 == 1) {
						cout << "|";
					} else {
						cout << " " << xo[k] << " ";
						k++;
					}
				}
			}
			cout << endl;
		}
		cout << endl;

		cout << endl << endl;
		if (role == start) {
			cout << "Giliran anda: " << start << endl;
		} else {
			cout << "Giliran: " << start << endl;
		}
		cout << "Pilih sesuai dengan angka dikotak: ";
		cin >> pilihan;

		// CEK PILIHAN
		for (int i = 0; i < 9; i++) {
			if (cekPilihan[i] == pilihan) {
				cek = 0;
			}
		}

		// MEMASUKKAN PILIHAN USER KE PAPAN BOARD
		if (cek) {
			switch(pilihan) {
				case 1:
					cekPilihan[0] = 1;
					xo[0] = start;
					if (start == 'O') {
						user1[u1] = 1;
						u1++;
					} else {
						user2[u2] = 1;
						u2++;
					}
				break;
				case 2:
					cekPilihan[1] = 2;
					xo[1] = start;
					if (start == 'O') {
						user1[u1] = 2;
						u1++;
					} else {
						user2[u2] = 2;
						u2++;
					}
				break;
				case 3:
					cekPilihan[2] = 3;
					xo[2] = start;
					if (start == 'O') {
						user1[u1] = 3;
						u1++;
					} else {
						user2[u2] = 3;
						u2++;
					}
				break;
				case 4:
					cekPilihan[3] = 4;
					xo[3] = start;
					if (start == 'O') {
						user1[u1] = 4;
						u1++;
					} else {
						user2[u2] = 4;
						u2++;
					}
				break;
				case 5:
					cekPilihan[4] = 5;
					xo[4] = start;
					if (start == 'O') {
						user1[u1] = 5;
						u1++;
					} else {
						user2[u2] = 5;
						u2++;
					}
				break;
				case 6:
					cekPilihan[5] = 6;
					xo[5] = start;
					if (start == 'O') {
						user1[u1] = 6;
						u1++;
					} else {
						user2[u2] = 6;
						u2++;
					}
				break;
				case 7:
					cekPilihan[6] = 7;
					xo[6] = start;
					if (start == 'O') {
						user1[u1] = 7;
						u1++;
					} else {
						user2[u2] = 7;
						u2++;
					}
				break;
				case 8:
					cekPilihan[7] = 8;
					xo[7] = start;
					if (start == 'O') {
						user1[u1] = 8;
						u1++;
					} else {
						user2[u2] = 8;
						u2++;
					}
				break;
				case 9:
					cekPilihan[8] = 9;
					xo[8] = start;
					if (start == 'O') {
						user1[u1] = 9;
						u1++;
					} else {
						user2[u2] = 9;
						u2++;
					}
				break;
				default:
					cout << "Pilih yang sesuai dengan angka yang di box!!" << endl;
			}
		}

		// CEK BOX
		if (cek == 0) cout << endl << "Box itu sudah dipilih!!" << endl;

		// PENGGANTIAN ROLE
		if (start == 'X' && cek) {
			start = 'O';
		} else if(start == 'O' && cek) {
			start = 'X';
		}
		
		cout << endl << endl;
	} while(end == 1);

	return 0;
}