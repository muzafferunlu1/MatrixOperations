#include <iostream>

using namespace std;
// Kullanýcý Arayüzü
void userMenu() {
	cout << "\n Congratulations :) Make your choice now" << endl << endl;
	cout << "Choice 1 --> Addition: '+' " << endl;
	cout << "Choice 2 --> Subtraction: '-' " << endl;
	cout << "Choice 3 --> Multiplication: '*' " << endl;
	cout << "Choice 4 --> Transposition: 't' " << endl;
	cout << "Choice 4 --> Quit: 'q' " << endl << "Enter Your Choice: ";
}
// Matris Toplam Ýþlemi Fonksiyonu
void matrixAdd(int** matrix1, int** matrix2, int** resultMatrix, int size) {
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++) {
			resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
		}
}
// Matris Çýkarma Ýþlemi Fonksiyonu
void matrixSub(int** matrix1, int** matrix2, int** resultMatrix, int size) {
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++) {
			resultMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
		}
}
// Matris Çarpma Ýþlemi Fonksiyonu
void matrixMulti(int** matrix1, int** matrix2, int** resultMatrix, int size) {
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++) {
			resultMatrix[i][j] = 0;
			for(int k=0;k<size;k++) {
				resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
			}	
		}
}
// Matris Tanspoz Ýþlemi Fonksiyonu
void matrixTranspos(int** matrix1, int** matrix2, int size) {
	cout << endl <<"||| Matrix1 |||" << endl;
	for(int i=0;i<size;i++) {
		for(int j=0;j<size;j++) {
			cout << matrix1[j][i] << " ";
		}
		cout << endl;
	}
	cout << "||| Matrix2 |||" << endl;
	for(int i=0;i<size;i++) {
		for(int j=0;j<size;j++) {
			cout << matrix2[j][i] << " ";
		}
		cout << endl;
	}
}
// Sonuç Yazdýrma Fonksiyonu
void putResult(int** resultMatrix,int size) {
	cout << endl <<"||| Result Matrix |||" << endl;
	for(int i=0;i<size;i++) {
		for(int j=0;j<size;j++) {
			cout << resultMatrix[i][j] << "  ";
		}
		cout << endl;
	}
}

int main() {
	
	int size;
	char choice;
	
	cout << "-----------------------------------------------------------\n";
	cout << "-------------------- Matrix Operations --------------------\n";
	cout << "-----------------------------------------------------------\n\n";
	
	cout << "Please enter the dimensions of the square matrix (ex:nxn): " ;
	cin >> size;
	
	//int matrix1[size][size] , matrix2[size][size] , resultMatrix[size][size]; // Bunun yerine dinamik bellek ayýrmayý kullandým
	// Dinamin Bellek Ayýrma
	int** matrix1 = new int*[size];
    int** matrix2 = new int*[size];
    int** resultMatrix = new int*[size];

    for (int i = 0; i < size; i++) {
        matrix1[i] = new int[size];
        matrix2[i] = new int[size];
        resultMatrix[i] = new int[size];
    }
	
	// Kullanýcýdan Matris Elamanlarýný Alma
	cout << "||| Matrix1 |||" << endl;
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++) {
			cout << "[" << i+1 << "]" << "[" << j+1 << "]: " ;
			cin >> matrix1[i][j];
		}
	
	cout << "||| Matrix2 |||" <<endl;
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++) {
			cout << "[" << i+1 << "]" << "[" << j+1 << "]: " ;
			cin >> matrix2[i][j];
		}
		
	//Matris iþlemleri Seçim Kýsmý
	do {
		userMenu();
		cin >> choice;
		
		switch(choice) {
			case '+':
				matrixAdd(matrix1,matrix2,resultMatrix,size);
				putResult(resultMatrix,size);
				break;
			case '-':
				matrixSub(matrix1,matrix2,resultMatrix,size);
				putResult(resultMatrix,size);
				break;
			case '*':
				matrixMulti(matrix1,matrix2,resultMatrix,size);
				putResult(resultMatrix,size);
				break;
			case 't':
				matrixTranspos(matrix1,matrix2,size);
				break;
			case 'q':
				break;
			default:
				cout << "Invalid choice, please try again !!!\n";
		}
	} while(choice != 'q');
	
	
	return 0;
}
