#include "Dictionary.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>//C ye ait kütüphanelerin tamamýný kullanýrsam da eklemeyi unutursam, hatamý düþünmek için zaman kaybetmeyeyim diye ekledim.
#include "Words.h"
#include <fstream>//Db olarak .txt kullandým. Onun için bu kütüphaneye ihtiyacým varmýþ
#include <cstdlib>
#include <cstring>
#include <strstream>




using namespace std;

Words w1, w2;//Word1 ve Word2 adýnda 2 tane kelime kullanacaðým 

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

	ofstream file("Words.txt", ios:: app);//Normalde kelimeleri uygulama içerisine yazsam da olurdu. Ancak C++ db den çekmeme müsade ediyor. Ben de öðrenmek istedim.

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

		choice = findMenu();//Çaðýrmaya devam etmek için 
	}
	

}

void Dictionary::del()
{
	list();//Numara üzerinden sileceðimiz için kullanýcý listeyi görmeli
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
		rename("Backup.txt", "Words.txt");//Kelime dosyasýndakileri yedek txt ye atýyorum. Kullanýcýnýn yazdýðý kelimeler backup dosyasýnda olmayacak. Backup dosyasýný yeni kelimeler dosyasý yapacaðýz. Eski kelimeler dosyasý silinecek. Böylece yeni kelimeler dosyasýnda istenilen kelimeler silinmiþ olacak. Bu taktiði 
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
	system("cls");//Bu fonksiyon ekraný temizlemek için kullanýlmaktadýr.

	int choice;//Burada mal gibi menu(); fonksiyonuyla tanýmladým kendi arasýnda menu(); yü döndürüp döndürüp duruyordu. Bu küçük hata 3 saatime mal oldu. 
	
	cout << "TURKISH-ENGLISH Dictionary App" << endl << endl;//Burada uygulamadaki menu kýsmýný oluþturuyorum. Kullanýcý yönergelere bakarak uygulamayý kullanabilecek
	cout << "[1]-- Add Word --"<< endl;
	cout << "[2]-- Search Word --" << endl;
	cout << "[3]-- Delete Word --" << endl;
	cout << "[4]-- List Word --" << endl;
	
	cout << "[0]-- Exit --" << endl;//Ýleride uygulamaya baþka seçenekler eklenebilir diye çýkýþý "0" a atadým. Böylece 4 den sonra seçenekler eklenebilir. Geliþtirilmeye açýk bir uygulama oldu.
	
	cout << "You've choosen  :   ";cin>> choice;
	return choice;
}

int Dictionary::findMenu()
{
	//system("cls");  Normalde bu fonksiyonu kullanacaktým. Ancak hatalý tuþlama yazýsý çýkmadýðý için iptal ettim.

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
		default: cout << "You made the wrong choice. Please make your choice from the menu!" << endl; break;//Kullanýcý case lerden birini seçmezse diye default bir uyarý sistemi oluþturdum. Böylece caselerden birini seçmese bile program çalýþmaya devam edecek.


		}

		choice = menu();//Çaðýrmaya devam etmek için 
	}
	cout << "Good bye! Thank you for you've prefered us! -Ekin Gorpeoglu" << endl;//Yukarýda while döngüsünü 0 a basmamak üzere kurduk. Eðer 0'a basarsak program sonlanýr ve bu mesaj çýkar. Eðer 0'a basmazsak program case lerden biriyle devam eder.
}
