#include <iostream>
#include <conio.h>
#include <random>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;
int getValidatedInput() {
    int number;
    while (true) {
        cin >> number;
        if (cin.fail() || number <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak terdefinisi, mohon masukkan bilangan bulat positif: ";
        } else {
            break;
        }
    }
    return number;
}

void sequentialSearch(const vector<int> &nums, int target){
    bool found = false;
    cout << "\nHasil Sequential Search:\n";
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == target) {
            cout << "Angka " << target << " ditemukan di indeks ke-" << i << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Angka " << target << " tidak ditemukan dalam data.\n";
    }
}

void binarySearch(const vector<int> &nums, int target){
    vector<int> sortedNums = nums;
    sort(sortedNums.begin(), sortedNums.end());

    cout << "\nData setelah diurutkan:\n";
    for (int i = 0; i < sortedNums.size(); ++i) {
        cout << "[" << i << "] " << sortedNums[i] << " ";
    }
    cout << "\n";

    int left = 0, right = sortedNums.size() - 1;
    bool found = false;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sortedNums[mid] == target) {
            cout << "Angka " << target << " ditemukan di indeks ke-" << mid << " (setelah sorting)\n";
            found = true;
            break;
        } else if (sortedNums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (!found) {
        cout << "Angka " << target << " tidak ditemukan dalam data.\n";
    }
}

void explain(){
    cout << "\nPerbedaan Sequential Search dan Binary Search:\n";
    cout << "- Sequential Search:\n";
    cout << "  1. memeriksa elemen satu persatu dan bisa dilakukan tanpa memperhatikan urutan data.\n";
    cout << "  2. Memiliki kompleksitas ruang O(1) dan kompleksitas waktu O(1)(waktu terbaik), O(n)(waktu rata - rata), dan O(n)(waktu terburuk).\n";
    cout << "  3. Tidak memerlukan data terurut, cocok untuk data yang teracak, dan bisa digunakan pada jenis data apapun.\n";
    cout << "  4. Cocok digunakan pada data berukuran kecil, data tidak terurut, data yang implementasinya sederhana, dan data yang memerlukan waktu untuk \n     memprosesnya.\n\n";

    cout << "- Binary Search:\n";
    cout << "  1. membandingkan elemen - elemen (divide and conquer) dan bisa dilakukan ketika data telah diurutkan\n";
    cout << "  2. Memiliki kompleksitas ruang O(1)(jika iteratif) dan O(log n)(jika rekursif) dan kompleksitas waktu O(1)(waktu terbaik), O(log n)(waktu rata - rata)\n     , dan O(log n)(waktu terburuk).\n";
    cout << "  3. Memerlukan data yang sudah terurut, tidak cocok untuk data yang acak, dan bisa digunakan pada jenis data apapun selama bisa dibandingkan.\n";
    cout << "  4. Cocok digunakan pada data berukuran besar, data yang telah diurutkan, dan data yang ingin dicari dengan cepat dan efisien. \n\n";
}

void clearScreen(){
    system("cls");
}

int main() {
    int opt, target;
    do {
        cout << "========== MENU ==========\n";
        cout << "1. Sequential Searching\n";
        cout << "2. Binary Searching\n";
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching\n";
        cout << "4. Exit\n";
        cout << "Pilih: ";
        cin >> opt;

        switch (opt) {
            case 1: {
                vector<int> nums(100);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 50);

                for (auto &val: nums) {
                    val = dist(rng);
                }

                cout << "\nData yang dimunculkan:" << endl;
                for (int i = 0; i < nums.size(); ++i) {
                    cout << "[" << i << "] " << nums[i] << " ";
                }
                cout << "\nMasukkan angka yang ingin dicari: ";
                target = getValidatedInput();

                sequentialSearch(nums, target);
                break;
            }

            case 2: {
                int size;
                cout << "Masukkan ukuran vector: ";
                size = getValidatedInput();

                vector<int> nums(size);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 100);

                for (auto &val: nums) {
                    val = dist(rng);
                }

                cout << "\nData yang dimunculkan:" << endl;
                for (int i = 0; i < nums.size(); ++i) {
                    cout << "[" << i << "] " << nums[i] << " ";
                }

                cout << "\nMasukkan angka yang ingin dicari: ";
                target = getValidatedInput();

                binarySearch(nums, target);
                break;
            }

            case 3:
                explain();
                break;

            case 4:
                cout << "\nTERIMA KASIH\n";
                cout << "Program was made by Faisal Tanjung (2410817310012)" << endl;
                break;

            default:
                cout << "Opsi tidak terdefinisi, mohon masukkan ulang opsi" << endl;
                break;
        }

        if (opt != 4) {
            cout << "\nTekan sembarang tombol untuk melanjutkan...";
            getch();
            clearScreen();
        }

    } while (opt != 4);

    return 0;
}
