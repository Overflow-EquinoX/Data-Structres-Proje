#include "Dictionary.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>//C ye ait k�t�phanelerin tamam�n� kullan�rsam da eklemeyi unutursam, hatam� d���nmek i�in zaman kaybetmeyeyim diye ekledim.
#include "Words.h"
#include <fstream>//Db olarak .txt kulland�m. Onun i�in bu k�t�phaneye ihtiyac�m varm��
#include <cstdlib>
#include <cstring>
#include <strstream>




using namespace std;

Words w1, w2;//Word1 ve Word2 ad�nda 2 tane kelime kullanaca��m 

void Dictionary::TurkishEnglish()
{
	system("cls");
	char word[30];
	bool sonuc = false;
	
	cout << "\n-SEARCH SCREEN- " << endl;
	cout << "Turkish :"; cin >> word;
	
	cout << "\nTurkish\t" << "English" << endl;


	ifstream file("Words.txt");


	while (file.read((char*)&w1, sizeof(w1)) != NULL) {

		if (strcmp(word, w1.Turkish) == 0) {
			sonuc = true;
			cout << w1.Turkish << "\t" << w1.English << endl;
			
		}
		

	}
	file.close();
	if (!sonuc) {
		cout << word << "\nis can not found!" << endl;

	}

	
	cout << "Listing completed successfully" << endl;
	system("pause");
	

	
	

}

void Dictionary::EnglishTurkish()
{
	system("cls");
	char word[30];
	bool sonuc = false;

	cout << "\n-SEARCH SCREEN- " << endl;
	cout << "English :"; cin >> word;

	cout << "\nEnglish\t" << "Turlish" << endl;


	ifstream file("Words.txt");


	while (file.read((char*)&w1, sizeof(w1)) != NULL) {

		if (strcmp(word, w1.English) == 0) {
			sonuc = true;
			cout << w1.English << "\t" << w1.Turkish << endl;

		}


	}
	file.close();
	if (!sonuc) {
		cout << word << "\nis can not found!" << endl;

	}


	cout << "Listing completed successfully" << endl;
	system("pause");
}

void Dictionary::add()
{
	system("cls");
	cout << "\n-ADDING SCREEN- " << endl;
	cout << "Turkish :"; cin >> w1.Turkish;
	cout << "English  :"; cin >> w1.English;

	ofstream file("Words.txt", ios:: app);//Normalde kelimeleri uygulama i�erisine yazsam da olurdu. Ancak C++ db den �ekmeme m�sade ediyor. Ben de ��renmek istedim.

	file.write((char*)&w1, sizeof(w1));
	file.close();
	cout << "Adding completed successfully" << endl;

}

void Dictionary::find() 
{

	int choice = findMenu();
	while (choice != 0) {
		switch (choice)
		{
		case 1: TurkishEnglish(); break;
		case 2: EnglishTurkish(); break;
		
		default: cout << "You made the wrong choice. Please make your choice from the menu!" << endl; break;


		}

		choice = findMenu();//�a��rmaya devam etmek i�in 
	}
	

}

void Dictionary::del()
{
	list();//Numara �zerinden silece�imiz i�in kullan�c� listeyi g�rmeli
	int number;
	cout << "Enter the sequence number of the word you want to delete : "; cin >> number;
	int counter = 0;
	bool sonuc = false;
	cout << "\n-DELETE SCREEN- " << endl;
	


	ifstream file("Words.txt");
	ofstream file2("Backup.txt");//yedek dosya


	while (file.read((char*)&w1, sizeof(w1)) != NULL) {

		counter++;
		if (number == counter) {
			sonuc = true;

		}
		else
			file2.write((char*)&w1, sizeof(w1));
		

	}
	file.close();
	file2.close();

	if (sonuc) {
		remove("Words.txt");
		rename("Backup.txt", "Words.txt");//Kelime dosyas�ndakileri yedek txt ye at�yorum. Kullan�c�n�n yazd��� kelimeler backup dosyas�nda olmayacak. Backup dosyas�n� yeni kelimeler dosyas� yapaca��z. Eski kelimeler dosyas� silinecek. B�ylece yeni kelimeler dosyas�nda istenilen kelimeler silinmi� olacak. Bu takti�i 
		cout << number << "numbered word has deleted" << endl;
	}
	else
	{
		cout << number << "numbered word could not found!!" << endl;

	}
	system("pause");

}

void Dictionary::list()
{
	system("cls");
	int counter = 0;
	cout << "\n-LIST SCREEN- " << endl;
	cout << "Turkish\t" << "English" << endl;
	

	ifstream file("Words.txt");
	 
	
	while (file.read((char*)&w1, sizeof(w1)) != NULL) {
		
		counter++;
		cout << w1.Turkish << "\t" << w1.English << endl;

	}
	file.close();
	
	cout << "Total word count is  :" << counter << endl;
	cout << "Listing completed successfully" << endl;
	system("pause");
}

int Dictionary::menu()
{
	system("cls");//Bu fonksiyon ekran� temizlemek i�in kullan�lmaktad�r.

	int choice;//Burada mal gibi menu(); fonksiyonuyla tan�mlad�m kendi aras�nda menu(); y� d�nd�r�p d�nd�r�p duruyordu. Bu k���k hata 3 saatime mal oldu. 
	
	cout << "TURKISH-ENGLISH Dictionary App" << endl << endl;//Burada uygulamadaki menu k�sm�n� olu�turuyorum. Kullan�c� y�nergelere bakarak uygulamay� kullanabilecek
	cout << "[1]-- Add Word --"<< endl;
	cout << "[2]-- Search Word --" << endl;
	cout << "[3]-- Delete Word --" << endl;
	cout << "[4]-- List Word --" << endl;
	
	cout << "[0]-- Exit --" << endl;//�leride uygulamaya ba�ka se�enekler eklenebilir diye ��k��� "0" a atad�m. B�ylece 4 den sonra se�enekler eklenebilir. Geli�tirilmeye a��k bir uygulama oldu.
	
	cout << "You've choosen  :   ";cin>> choice;
	return choice;
}

int Dictionary::findMenu()
{
	//system("cls");  Normalde bu fonksiyonu kullanacakt�m. Ancak hatal� tu�lama yaz�s� ��kmad��� i�in iptal ettim.

	int choice;
	cout << "\nSEARCHING OPTIONS" << endl << endl;
	cout << "[1]-- TURKISH-ENGLISH --" << endl;
	cout << "[2]-- ENGLISH-TURKISH --" << endl;
	cout << "[0]-- MAIN MENU --" << endl;
	cout << "You've choosen :"; cin >> choice;
	

	

	
	return choice;
}

void Dictionary::giris()
{
	int choice = menu();
	while (choice != 0) {
		switch (choice)
		{
		case 1: add(); break;
		case 2: find(); break;
		case 3: del(); break;
		case 4: list(); break;
		default: cout << "You made the wrong choice. Please make your choice from the menu!" << endl; break;//Kullan�c� case lerden birini se�mezse diye default bir uyar� sistemi olu�turdum. B�ylece caselerden birini se�mese bile program �al��maya devam edecek.


		}

		choice = menu();//�a��rmaya devam etmek i�in 
	}
	cout << "Good bye! Thank you for you've prefered us! -Ekin Gorpeoglu" << endl;//Yukar�da while d�ng�s�n� 0 a basmamak �zere kurduk. E�er 0'a basarsak program sonlan�r ve bu mesaj ��kar. E�er 0'a basmazsak program case lerden biriyle devam eder.
}
