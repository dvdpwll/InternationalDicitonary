// InternationalDictionary.cpp : main project file.
// This program is a German-English, English-German, French-English, 
// English-French, Latin-English, English-Latin, Hebrew-English, 
// English-Hebrew international dictionary

/*
Issues: I could not find a way to print the unicode special characters correctly.
\u00D6 is supposed to print Ö, but instead it prints ╔ which is \u2554
\u00E4 ä becomes /u2211 ∑
etc.
I don't know why this happens but none of the special characters work
*/

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <string>
//#include <io.h> //for setmode but it crashes console
//#include <fcntl.h> //for setmode but it crashes consoel

//using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
//using std::wcout;

using namespace System;

// prototypes
void MainMenuSelect();
char MainMenu();
void CreateWordList();
void CreateGermanWordList();
void CreateFrenchWordList();
void CreateLatinWordList();
void CreateHebrewWordList();
void ForiegnToEnglishSelect();
void EnglishToForiegnSelect();
void SearchPrompt();
void Search(string);
void Quit();
void Sort();

char ForiegnToEnglishMenu();
char GermanToEnglishMenu();
void GermanToEnglishSelect();
void GermanToEnglishNouns();
void GermanToEnglishVerbs();
void GermanToEnglishPrepositions();
void GermanToEnglishAdjectives();
void GermanToEnglishAdverbs();
void GermanToEnglishCardinalNumbers();
void GermanToEnglishAll();

char FrenchToEnglishMenu();
void FrenchToEnglishSelect();
void FrenchToEnglishNouns();
void FrenchToEnglishVerbs();
void FrenchToEnglishPrepositions();
void FrenchToEnglishAdjectives();
void FrenchToEnglishAdverbs();
void FrenchToEnglishCardinalNumbers();
void FrenchToEnglishPronouns();
void FrenchToEnglishAll();

char LatinToEnglishMenu();
void LatinToEnglishSelect();
void LatinToEnglishNouns();
void LatinToEnglishVerbs();
void LatinToEnglishPrepositions();
void LatinToEnglishAdjectives();
void LatinToEnglishAdverbs();
void LatinToEnglishCardinalNumbers();
void LatinToEnglishConjunctions();
void LatinToEnglishPronouns();
void LatinToEnglishAll();

char HebrewToEnglishMenu();
void HebrewToEnglishSelect();
void HebrewToEnglishNouns();
void HebrewToEnglishVerbs();
void HebrewToEnglishPrepositions();
void HebrewToEnglishAdjectives();
void HebrewToEnglishAdverbs();
void HebrewToEnglishCardinalNumbers();
void HebrewToEnglishAll();

char EnglishToForiegnMenu();
char EnglishToGermanMenu();
void EnglishToGermanSelect();
void EnglishToGermanNouns();
void EnglishToGermanVerbs();
void EnglishToGermanPrepositions();
void EnglishToGermanAdjectives();
void EnglishToGermanAdverbs();
void EnglishToGermanCardinalNumbers();
void EnglishToGermanAll();

char EnglishToFrenchMenu();
void EnglishToFrenchSelect();
void EnglishToFrenchNouns();
void EnglishToFrenchVerbs();
void EnglishToFrenchPrepositions();
void EnglishToFrenchAdjectives();
void EnglishToFrenchAdverbs();
void EnglishToFrenchCardinalNumbers();
void EnglishToFrenchPronouns();
void EnglishToFrenchAll();


char EnglishToLatinMenu();
void EnglishToLatinSelect();
void EnglishToLatinNouns();
void EnglishToLatinVerbs();
void EnglishToLatinPrepositions();
void EnglishToLatinAdjectives();
void EnglishToLatinAdverbs();
void EnglishToLatinConjunctions();
void EnglishToLatinPronouns();
void EnglishToLatinAll();

char EnglishToHebrewMenu();
void EnglishToHebrewSelect();
void EnglishToHebrewNouns();
void EnglishToHebrewVerbs();
void EnglishToHebrewPrepositions();
void EnglishToHebrewAdjectives();
void EnglishToHebrewAdverbs();
void EnglishToHebrewCardinalNumbers();
void EnglishToHebrewAll();


struct Word{
	string originalWord;
	string searchWord;
	string partOfSpeech;
	string englishMeaning;
};

// struct arrays to hold words in each language
Word german[25];
Word french[25];
Word latin[25];
Word hebrew[25];

// main
int main(){
	//_setmode(_fileno(stdout), _O_U16TEXT); // supposed to allow the console to use unicode but crashes the console
	// open main menu
	MainMenuSelect();
	return 0;
}//end main

//functions
void MainMenuSelect() {
	for (;;) {
		char choice = MainMenu();
		cout << choice;
		switch (choice) {
		case '1':
			CreateWordList();
			break;
		case '2':
			ForiegnToEnglishSelect();
			break;
		case '3':
			EnglishToForiegnSelect();
			break;
		case '4':
			SearchPrompt();
			break;
		case '0':
			Quit();
			break;
		default:
			cout << "\n\nInvalid choice -- try again." << endl;
			cout << "Hit any key...";
			_getch();
			break;
		}
	}
}

char MainMenu(){
	char choice;
	system("cls");

	//cout << "\u00D6" << endl; //prints wrong character
	//wcout << "\U000000D6" << endl; //prints wrong character
	//std::wcout << L"Ö" << endl; //prints wrong character

	// display menu
	cout << "***MainMenu***" << endl;
	cout << "(1) Create the word lists" << endl;
	cout << "(2) Foriegn to English" << endl;
	cout << "(3) English to Foriegn" << endl;
	cout << "(4) Search" << endl;
	cout << "(0) Quit" << endl;
	cout << "Enter Your Choice: ";
	
	// get user selection
	choice = _getch();
	return choice;
}

void CreateWordList() {
	CreateGermanWordList();
	CreateFrenchWordList();
	CreateLatinWordList();
	CreateHebrewWordList();
	Sort();

	cout << "\n\nYou Chose Create the work list." << endl;
	cout << "Hit any key...";
	_getch();
}

void CreateGermanWordList() {
	// der Mann
	german[0].originalWord = "der Mann";
	german[0].searchWord = "mann";
	german[0].partOfSpeech = "noun";
	german[0].englishMeaning = "man";

	// das Ol ------------------- uses special characer
	german[1].originalWord = "der Ol";
	german[1].searchWord = "ol";
	german[1].partOfSpeech = "noun";
	german[1].englishMeaning = "oil";

	// die Frau
	german[2].originalWord = "die Frau";
	german[2].searchWord = "frau";
	german[2].partOfSpeech = "noun";
	german[2].englishMeaning = "woman";

	// das Fraulein ---------------- uses special characer
	german[3].originalWord = "das Fraulein";
	german[3].searchWord = "fraulein";
	german[3].partOfSpeech = "noun";
	german[3].englishMeaning = "miss";

	// das Madchen ---------------- uses special characer
	german[4].originalWord = "das Madchen";
	german[4].searchWord = "madchen";
	german[4].partOfSpeech = "noun";
	german[4].englishMeaning = "girl";

	// das Kind
	german[5].originalWord = "das Kind";
	german[5].searchWord = "kind";
	german[5].partOfSpeech = "noun";
	german[5].englishMeaning = "child";

	// das Haus
	german[6].originalWord = "das Haus";
	german[6].searchWord = "haus";
	german[6].partOfSpeech = "noun";
	german[6].englishMeaning = "house";

	// die Schule
	german[7].originalWord = "die Schule";
	german[7].searchWord = "schule";
	german[7].partOfSpeech = "noun";
	german[7].englishMeaning = "school";

	// die Tur ---------------- uses special characer
	german[8].originalWord = "die Tur";
	german[8].searchWord = "tur";
	german[8].partOfSpeech = "noun";
	german[8].englishMeaning = "door";

	// kommen
	german[9].originalWord = "kommen";
	german[9].searchWord = "kommen";
	german[9].partOfSpeech = "verb";
	german[9].englishMeaning = "to come";

	// gehen
	german[10].originalWord = "gehen";
	german[10].searchWord = "gehen";
	german[10].partOfSpeech = "verb";
	german[10].englishMeaning = "to go";

	// sehen
	german[11].originalWord = "sehen";
	german[11].searchWord = "sehen";
	german[11].partOfSpeech = "verb";
	german[11].englishMeaning = "to see";

	// wollen
	german[12].originalWord = "wollen";
	german[12].searchWord = "wollen";
	german[12].partOfSpeech = "verb";
	german[12].englishMeaning = "to want";

	// wissen
	german[13].originalWord = "wissen";
	german[13].searchWord = "wissen";
	german[13].partOfSpeech = "verb";
	german[13].englishMeaning = "to know";

	// konnen ------------------ uses special characer
	german[14].originalWord = "konnen";
	german[14].searchWord = "konnen";
	german[14].partOfSpeech = "verb";
	german[14].englishMeaning = "to be able";

	// vor
	german[15].originalWord = "vor";
	german[15].searchWord = "vor";
	german[15].partOfSpeech = "preposition";
	german[15].englishMeaning = "before";

	// nach
	german[16].originalWord = "nach";
	german[16].searchWord = "nach";
	german[16].partOfSpeech = "preposition";
	german[16].englishMeaning = "after";

	// zu
	german[17].originalWord = "zu";
	german[17].searchWord = "zu";
	german[17].partOfSpeech = "preposition";
	german[17].englishMeaning = "to";

	// bis
	german[18].originalWord = "bis";
	german[18].searchWord = "bis";
	german[18].partOfSpeech = "preposition";
	german[18].englishMeaning = "until";

	// ohne
	german[19].originalWord = "ohne";
	german[19].searchWord = "ohne";
	german[19].partOfSpeech = "preposition";
	german[19].englishMeaning = "without";

	// eins
	german[20].originalWord = "eins";
	german[20].searchWord = "eins";
	german[20].partOfSpeech = "cardinal number";
	german[20].englishMeaning = "one";

	// zwei
	german[21].originalWord = "zwei";
	german[21].searchWord = "zwei";
	german[21].partOfSpeech = "cardinal number";
	german[21].englishMeaning = "two";

	// drei
	german[22].originalWord = "drei";
	german[22].searchWord = "drei";
	german[22].partOfSpeech = "cardinal number";
	german[22].englishMeaning = "three";

	// hoch
	german[23].originalWord = "hoch";
	german[23].searchWord = "hoch";
	german[23].partOfSpeech = "adverb";
	german[23].englishMeaning = "high";

	// gut
	german[24].originalWord = "gut";
	german[24].searchWord = "gut";
	german[24].partOfSpeech = "adjective/adverb";
	german[24].englishMeaning = "good";
}

void CreateFrenchWordList() {
	// le mot
	french[0].originalWord = "le mot";
	french[0].searchWord = "mot";
	french[0].partOfSpeech = "noun";
	french[0].englishMeaning = "word";

	// le garcon ------------------- uses special characer
	french[1].originalWord = "le garcon";
	french[1].searchWord = "garcon";
	french[1].partOfSpeech = "noun";
	french[1].englishMeaning = "boy";

	// jeune
	french[2].originalWord = "jeune";
	french[2].searchWord = "jeune";
	french[2].partOfSpeech = "adjective";
	french[2].englishMeaning = "young";

	// le boulanger
	french[3].originalWord = "le boulanger";
	french[3].searchWord = "boulanger";
	french[3].partOfSpeech = "noun";
	french[3].englishMeaning = "baker";

	// la fille
	french[4].originalWord = "la fille";
	french[4].searchWord = "fille";
	french[4].partOfSpeech = "noun";
	french[4].englishMeaning = "girl";

	// francais ---------------------uses special character
	french[5].originalWord = "francais";
	french[5].searchWord = "francais";
	french[5].partOfSpeech = "adjective";
	french[5].englishMeaning = "French";

	// le livre
	french[6].originalWord = "le livre";
	french[6].searchWord = "livre";
	french[6].partOfSpeech = "noun";
	french[6].englishMeaning = "book";

	// l'ecole ---------------- uses special characer
	french[7].originalWord = "l'ecole";
	french[7].searchWord = "l'ecole";
	french[7].partOfSpeech = "noun";
	french[7].englishMeaning = "school";

	// la maison
	french[8].originalWord = "la maison";
	french[8].searchWord = "maison";
	french[8].partOfSpeech = "noun";
	french[8].englishMeaning = "house";

	// etre -------------------- uses special character
	french[9].originalWord = "etre";
	french[9].searchWord = "etre";
	french[9].partOfSpeech = "verb";
	french[9].englishMeaning = "to be";

	// apres ------------------- uses special character
	french[10].originalWord = "apres";
	french[10].searchWord = "apres";
	french[10].partOfSpeech = "preposition";
	french[10].englishMeaning = "after";

	// voir
	french[11].originalWord = "voir";
	french[11].searchWord = "voir";
	french[11].partOfSpeech = "verb";
	french[11].englishMeaning = "to see";

	// dire
	french[12].originalWord = "dire";
	french[12].searchWord = "dire";
	french[12].partOfSpeech = "verb";
	french[12].englishMeaning = "to say";

	// aller
	french[13].originalWord = "aller";
	french[13].searchWord = "aller";
	french[13].partOfSpeech = "verb";
	french[13].englishMeaning = "to go";

	// bon
	french[14].originalWord = "bon";
	french[14].searchWord = "bon";
	french[14].partOfSpeech = "adjective";
	french[14].englishMeaning = "good";

	// le mardi
	french[15].originalWord = "le mardi";
	french[15].searchWord = "mardi";
	french[15].partOfSpeech = "noun";
	french[15].englishMeaning = "Tuesday";

	// la salle
	french[16].originalWord = "la salle";
	french[16].searchWord = "salle";
	french[16].partOfSpeech = "noun";
	french[16].englishMeaning = "room";

	// elle
	french[17].originalWord = "elle";
	french[17].searchWord = "elle";
	french[17].partOfSpeech = "pronoun";
	french[17].englishMeaning = "she";

	// le jour
	french[18].originalWord = "le jour";
	french[18].searchWord = "jour";
	french[18].partOfSpeech = "noun";
	french[18].englishMeaning = "day";

	// aujourd'hui
	french[19].originalWord = "aujourd'hui";
	french[19].searchWord = "aujourd'hui";
	french[19].partOfSpeech = "adverb";
	french[19].englishMeaning = "today";

	// la pluie
	french[20].originalWord = "la pluie";
	french[20].searchWord = "pluie";
	french[20].partOfSpeech = "noun";
	french[20].englishMeaning = "rain";

	// le cheval
	french[21].originalWord = "le cheval";
	french[21].searchWord = "cheval";
	french[21].partOfSpeech = "noun";
	french[21].englishMeaning = "horse";

	// le moulin
	french[22].originalWord = "le moulin";
	french[22].searchWord = "moulin";
	french[22].partOfSpeech = "noun";
	french[22].englishMeaning = "mill";

	// rouge
	french[23].originalWord = "rouge";
	french[23].searchWord = "rouge";
	french[23].partOfSpeech = "adjective";
	french[23].englishMeaning = "red";

	// la neige
	french[24].originalWord = "la neige";
	french[24].searchWord = "neige";
	french[24].partOfSpeech = "noun";
	french[24].englishMeaning = "snow";
}

void CreateLatinWordList() {
	// puer
	latin[0].originalWord = "puer";
	latin[0].searchWord = "puer";
	latin[0].partOfSpeech = "noun (m)";
	latin[0].englishMeaning = "boy";

	// pistor
	latin[1].originalWord = "pistor";
	latin[1].searchWord = "pistor";
	latin[1].partOfSpeech = "noun (m)";
	latin[1].englishMeaning = "baker";

	// puella
	latin[2].originalWord = "puella";
	latin[2].searchWord = "puella";
	latin[2].partOfSpeech = "noun (f)";
	latin[2].englishMeaning = "girl";

	// bonus
	latin[3].originalWord = "bonus";
	latin[3].searchWord = "bonus";
	latin[3].partOfSpeech = "adjective";
	latin[3].englishMeaning = "good";

	// liber
	latin[4].originalWord = "liber";
	latin[4].searchWord = "liber";
	latin[4].partOfSpeech = "noun (m)";
	latin[4].englishMeaning = "book";

	// schola
	latin[5].originalWord = "schola";
	latin[5].searchWord = "schola";
	latin[5].partOfSpeech = "noun (f)";
	latin[5].englishMeaning = "school";

	// domus
	latin[6].originalWord = "domus";
	latin[6].searchWord = "domus";
	latin[6].partOfSpeech = "noun (f)";
	latin[6].englishMeaning = "house";

	// esse
	latin[7].originalWord = "esse";
	latin[7].searchWord = "esse";
	latin[7].partOfSpeech = "verb";
	latin[7].englishMeaning = "to be";

	// post
	latin[8].originalWord = "post";
	latin[8].searchWord = "post";
	latin[8].partOfSpeech = "preposition";
	latin[8].englishMeaning = "after";

	// illa
	latin[9].originalWord = "illa";
	latin[9].searchWord = "illa";
	latin[9].partOfSpeech = "pronoun";
	latin[9].englishMeaning = "she";

	// conclave
	latin[10].originalWord = "conclave";
	latin[10].searchWord = "conclave";
	latin[10].partOfSpeech = "noun (n)";
	latin[10].englishMeaning = "room";

	// hodie
	latin[11].originalWord = "hodie";
	latin[11].searchWord = "hodie";
	latin[11].partOfSpeech = "adverb";
	latin[11].englishMeaning = "today";

	// pluvia
	latin[12].originalWord = "pluvia";
	latin[12].searchWord = "pluvia";
	latin[12].partOfSpeech = "noun (f)";
	latin[12].englishMeaning = "rain";

	// equus
	latin[13].originalWord = "equus";
	latin[13].searchWord = "equus";
	latin[13].partOfSpeech = "noun (m)";
	latin[13].englishMeaning = "horse";

	// mola
	latin[14].originalWord = "mola";
	latin[14].searchWord = "mola";
	latin[14].partOfSpeech = "noun (f)";
	latin[14].englishMeaning = "mill";

	// ruber
	latin[15].originalWord = "ruber";
	latin[15].searchWord = "ruber";
	latin[15].partOfSpeech = "adjective";
	latin[15].englishMeaning = "red";

	// nix
	latin[16].originalWord = "nix";
	latin[16].searchWord = "nix";
	latin[16].partOfSpeech = "noun (f)";
	latin[16].englishMeaning = "snow";

	// ire
	latin[17].originalWord = "ire";
	latin[17].searchWord = "ire";
	latin[17].partOfSpeech = "verb";
	latin[17].englishMeaning = "to go";

	// oculus
	latin[18].originalWord = "oculus";
	latin[18].searchWord = "oculus";
	latin[18].partOfSpeech = "noun (m)";
	latin[18].englishMeaning = "eye";

	// intro
	latin[19].originalWord = "intro";
	latin[19].searchWord = "intro";
	latin[19].partOfSpeech = "adverb";
	latin[19].englishMeaning = "within";

	// femina
	latin[20].originalWord = "femina";
	latin[20].searchWord = "femina";
	latin[20].partOfSpeech = "noun (f)";
	latin[20].englishMeaning = "woman";

	// homunculus
	latin[21].originalWord = "homunculus";
	latin[21].searchWord = "homunculus";
	latin[21].partOfSpeech = "noun (m)";
	latin[21].englishMeaning = "little man";

	// malum
	latin[22].originalWord = "malum";
	latin[22].searchWord = "malum";
	latin[22].partOfSpeech = "noun (n)";
	latin[22].englishMeaning = "apple";

	// nam
	latin[23].originalWord = "nam";
	latin[23].searchWord = "nam";
	latin[23].partOfSpeech = "conjunction";
	latin[23].englishMeaning = "for";

	// zelus
	latin[24].originalWord = "zelus";
	latin[24].searchWord = "zelus";
	latin[24].partOfSpeech = "noun (m)";
	latin[24].englishMeaning = "zeal";
}

void CreateHebrewWordList() {
	// rachok
	hebrew[0].originalWord = "rachok";
	hebrew[0].searchWord = "rachok";
	hebrew[0].partOfSpeech = "adverb (m)";
	hebrew[0].englishMeaning = "far";

	// panim
	hebrew[1].originalWord = "panim";
	hebrew[1].searchWord = "panim";
	hebrew[1].partOfSpeech = "noun (f)";
	hebrew[1].englishMeaning = "face";

	// tapuach
	hebrew[2].originalWord = "tapuach";
	hebrew[2].searchWord = "tapuach";
	hebrew[2].partOfSpeech = "noun (m)";
	hebrew[2].englishMeaning = "apple";

	// ma'afiah
	hebrew[3].originalWord = "ma'afiah";
	hebrew[3].searchWord = "ma'afiah";
	hebrew[3].partOfSpeech = "noun (f)";
	hebrew[3].englishMeaning = "bakery";

	// ayin
	hebrew[4].originalWord = "ayin";
	hebrew[4].searchWord = "ayin";
	hebrew[4].partOfSpeech = "noun (f)";
	hebrew[4].englishMeaning = "eye";

	// adom
	hebrew[5].originalWord = "adom";
	hebrew[5].searchWord = "adom";
	hebrew[5].partOfSpeech = "adjective (m)";
	hebrew[5].englishMeaning = "red";

	// sheleg
	hebrew[6].originalWord = "sheleg";
	hebrew[6].searchWord = "sheleg";
	hebrew[6].partOfSpeech = "noun (m)";
	hebrew[6].englishMeaning = "snow";

	// ochel
	hebrew[7].originalWord = "ochel";
	hebrew[7].searchWord = "ochel";
	hebrew[7].partOfSpeech = "noun (m)";
	hebrew[7].englishMeaning = "food";

	// bari
	hebrew[8].originalWord = "bari";
	hebrew[8].searchWord = "bari";
	hebrew[8].partOfSpeech = "adjective (m)";
	hebrew[8].englishMeaning = "healthy";

	// cham
	hebrew[9].originalWord = "cham";
	hebrew[9].searchWord = "cham";
	hebrew[9].partOfSpeech = "adjective (m)";
	hebrew[9].englishMeaning = "hot";

	// yom shlishi
	hebrew[10].originalWord = "yom shlishi";
	hebrew[10].searchWord = "shlishi";
	hebrew[10].partOfSpeech = "noun (m)";
	hebrew[10].englishMeaning = "Tuesday";

	// tov
	hebrew[11].originalWord = "tov";
	hebrew[11].searchWord = "tov";
	hebrew[11].partOfSpeech = "adjective (m)";
	hebrew[11].englishMeaning = "good";

	// latet
	hebrew[12].originalWord = "latet";
	hebrew[12].searchWord = "latet";
	hebrew[12].partOfSpeech = "verb";
	hebrew[12].englishMeaning = "to give";

	// kan
	hebrew[13].originalWord = "kan";
	hebrew[13].searchWord = "kan";
	hebrew[13].partOfSpeech = "adverb";
	hebrew[13].englishMeaning = "here";

	// juke
	hebrew[14].originalWord = "juke";
	hebrew[14].searchWord = "juke";
	hebrew[14].partOfSpeech = "noun (m)";
	hebrew[14].englishMeaning = "bug";

	// lemala
	hebrew[15].originalWord = "lemala";
	hebrew[15].searchWord = "lemala";
	hebrew[15].partOfSpeech = "adverb";
	hebrew[15].englishMeaning = "up";

	// mitah
	hebrew[16].originalWord = "mitah";
	hebrew[16].searchWord = "mitah";
	hebrew[16].partOfSpeech = "noun (f)";
	hebrew[16].englishMeaning = "bed";

	// kafa'fa
	hebrew[17].originalWord = "kafa'fa";
	hebrew[17].searchWord = "kafa'fa";
	hebrew[17].partOfSpeech = "noun (f)";
	hebrew[17].englishMeaning = "glove";

	// katis ashrei
	hebrew[18].originalWord = "katis ashrei";
	hebrew[18].searchWord = "katis ashrei";
	hebrew[18].partOfSpeech = "noun (m)";
	hebrew[18].englishMeaning = "credit card";

	// zol
	hebrew[19].originalWord = "zol";
	hebrew[19].searchWord = "zol";
	hebrew[19].partOfSpeech = "adjective (m)";
	hebrew[19].englishMeaning = "inexpensive";

	// smartoot
	hebrew[20].originalWord = "smartoot";
	hebrew[20].searchWord = "smartoot";
	hebrew[20].partOfSpeech = "noun (m)";
	hebrew[20].englishMeaning = "rain";

	// sus
	hebrew[21].originalWord = "sus";
	hebrew[21].searchWord = "sus";
	hebrew[21].partOfSpeech = "noun (m)";
	hebrew[21].englishMeaning = "horse";

	// matai
	hebrew[22].originalWord = "matai";
	hebrew[22].searchWord = "matai";
	hebrew[22].partOfSpeech = "adverb";
	hebrew[22].englishMeaning = "when";

	// chatza'it
	hebrew[23].originalWord = "chatza'it";
	hebrew[23].searchWord = "chatza'it";
	hebrew[23].partOfSpeech = "noun (f)";
	hebrew[23].englishMeaning = "skirt";

	// cheshbon
	hebrew[24].originalWord = "cheshbon";
	hebrew[24].searchWord = "cheshbon";
	hebrew[24].partOfSpeech = "noun (m)";
	hebrew[24].englishMeaning = "bill";
}

void ForiegnToEnglishSelect() {
	if (german[0].partOfSpeech != "") {
		for (;;) {
			char choice = ForiegnToEnglishMenu();
			cout << choice;
			switch (choice) {
			case '1':
				GermanToEnglishSelect();
				break;
			case '2':
				FrenchToEnglishSelect();
				break;
			case '3':
				LatinToEnglishSelect();
				break;
			case '4':
				HebrewToEnglishSelect();
				break;
			case '9':
				MainMenuSelect();
				break;
			case '0':
				Quit();
				break;
			default:
				cout << "\n\nInvalid choice -- try again." << endl;
				cout << "Hit any key...";
				_getch();
				break;
			}//end switch
		}//end infinite for loop
	}
	else {
		cout << "\n\nPlease create the word lists first." << endl;
		cout << "Press any key...";
		_getch();
	}	
}

void EnglishToForiegnSelect() {
	if (german[0].partOfSpeech != "") {
		for (;;) {
			char choice = EnglishToForiegnMenu();
			cout << choice;
			switch (choice) {
			case '1':
				EnglishToGermanSelect();
				break;
			case '2':
				EnglishToFrenchSelect();
				break;
			case '3':
				EnglishToLatinSelect();
				break;
			case '4':
				EnglishToHebrewSelect();
				break;
			case '9':
				MainMenuSelect();
				break;
			case '0':
				Quit();
				break;
			default:
				cout << "\n\nInvalid choice -- try again." << endl;
				cout << "Hit any key...";
				_getch();
				break;
			}//end switch
		}//end infinite for loop
	}
	else {
		cout << "\n\nPlease create the word lists first." << endl;
		cout << "Press any key...";
		_getch();
	}
}

void SearchPrompt() {
	if (german[0].partOfSpeech != ""){
		string search;
		cout << "\n\nYou Chose Search." << endl;
		cout << "Enter your search: ";
		getline(cin, search);
		Search(search);
	}
	else{
		cout << "\n\nPlease create the word lists first." << endl;
		cout << "Press any key...";
		_getch();
	}
}

void Search(string search) {
	cout << "Searching for '" << search << "'..." << endl;
	for (int i = 0; i < 25; i++){
		if (german[i].originalWord == search ||
			german[i].searchWord == search ||
			german[i].englishMeaning == search){
			cout << "\n\nGerman: " << german[i].originalWord << endl;
			cout << "PartOfSpeech: " << german[i].partOfSpeech << endl;
			cout << "English: " << german[i].englishMeaning << endl;
		}
	}

	for (int i = 0; i < 25; i++) {
		if (french[i].originalWord == search ||
			french[i].searchWord == search ||
			french[i].englishMeaning == search) {
			cout << "\n\nFrench: " << french[i].originalWord << endl;
			cout << "PartOfSpeech: " << french[i].partOfSpeech << endl;
			cout << "English: " << french[i].englishMeaning << endl;
		}
	}

	for (int i = 0; i < 25; i++) {
		if (latin[i].originalWord == search ||
			latin[i].searchWord == search ||
			latin[i].englishMeaning == search) {
			cout << "\n\nLatin: " << latin[i].originalWord << endl;
			cout << "PartOfSpeech: " << latin[i].partOfSpeech << endl;
			cout << "English: " << latin[i].englishMeaning << endl;
		}
	}

	for (int i = 0; i < 25; i++) {
		if (hebrew[i].originalWord == search ||
			hebrew[i].searchWord == search ||
			hebrew[i].englishMeaning == search) {
			cout << "\n\nHebrew: " << hebrew[i].originalWord << endl;
			cout << "PartOfSpeech: " << hebrew[i].partOfSpeech << endl;
			cout << "English: " << hebrew[i].englishMeaning << endl;
		}
	}

	cout << "\n\nSearch complete, press any key to continue...";
	_getch();
}

void Quit() {
	cout << "\n\nYou Chose Quit." << endl;
	cout << "Hit any key...";
	_getch();
	exit(0);
}

void Sort() {
	// sort german list
	Word temp1;
	for (int i = 0; i < 24; i++){
		for (int j = i + 1; j < 25; j++){
			if (german[i].searchWord > german[j].searchWord){
				temp1 = german[i];
				german[i] = german[j];
				german[j] = temp1;
			}
		}
	}

	// sort french list
	Word temp2;
	for (int i = 0; i < 24; i++) {
		for (int j = i + 1; j < 25; j++) {
			if (french[i].searchWord > french[j].searchWord) {
				temp2 = french[i];
				french[i] = french[j];
				french[j] = temp2;
			}
		}
	}

	// sort latin list
	Word temp3;
	for (int i = 0; i < 24; i++) {
		for (int j = i + 1; j < 25; j++) {
			if (latin[i].searchWord > latin[j].searchWord) {
				temp3 = latin[i];
				latin[i] = latin[j];
				latin[j] = temp3;
			}
		}
	}

	// sort hebrew list
	Word temp4;
	for (int i = 0; i < 24; i++) {
		for (int j = i + 1; j < 25; j++) {
			if (hebrew[i].searchWord > hebrew[j].searchWord) {
				temp4 = hebrew[i];
				hebrew[i] = hebrew[j];
				hebrew[j] = temp4;
			}
		}
	}

}

char EnglishToForiegnMenu() {
	char choice;
	system("cls");

	// display menu
	cout << "***English to Foriegn***" << endl;
	cout << "(1) English to German" << endl;
	cout << "(2) English to French" << endl;
	cout << "(3) English to Latin" << endl;
	cout << "(4) English to Hebrew" << endl;
	cout << "(9) MainMenu" << endl;
	cout << "(0) Quit" << endl;
	cout << "Enter Your Choice: ";

	// get user selection
	choice = _getch();
	return choice;
}

char ForiegnToEnglishMenu() {
	char choice;
	system("cls");

	// display menu
	cout << "***Foriegn to English***" << endl;
	cout << "(1) German to English" << endl;
	cout << "(2) French to English" << endl;
	cout << "(3) Latin to English" << endl;
	cout << "(4) Hebrew to English" << endl;
	cout << "(9) MainMenu" << endl;
	cout << "(0) Quit" << endl;
	cout << "Enter Your Choice: ";

	// get user selection
	choice = _getch();
	return choice;
}

//void EnglishToGerman() {
//	cout << "\n\nYou Chose English To German." << endl;
//	cout << "Hit any key...";
//	_getch();
//}

void GermanToEnglishSelect() {
	for (;;) {
		char choice = GermanToEnglishMenu();
		cout << choice;
		switch (choice) {
		case '1':
			GermanToEnglishNouns();
			break;
		case '2':
			GermanToEnglishVerbs();
			break;
		case '3':
			GermanToEnglishPrepositions();
			break;
		case '4':
			GermanToEnglishAdjectives();
			break;
		case '5':
			GermanToEnglishAdverbs();
			break;
		case '6':
			GermanToEnglishCardinalNumbers();
			break;
		case '7':
			GermanToEnglishAll();
			break;
		case '9':
			MainMenuSelect();
			break;
		case '0':
			Quit();
			break;
		default:
			cout << "\n\nInvalid choice -- try again." << endl;
			cout << "Hit any key...";
			_getch();
			break;
		}//end switch
	}//end infinite for loop
}

char GermanToEnglishMenu() {
	char choice;
	system("cls");

	// display menu
	cout << "***German to English***" << endl;
	cout << "(1) German to English Nouns" << endl;
	cout << "(2) German to English Verbs" << endl;
	cout << "(3) German to English Prepositions" << endl;
	cout << "(4) German to English Adjectives" << endl;
	cout << "(5) German to English Adverbs" << endl;
	cout << "(6) German to English Cardinal Numbers" << endl;
	cout << "(7) German to English All" << endl;
	cout << "(9) MainMenu" << endl;
	cout << "(0) Quit" << endl;
	cout << "Enter Your Choice: ";

	// get user selection
	choice = _getch();
	return choice;
}

void GermanToEnglishNouns() {
	for (int i = 0; i < 25; i++) {
		if (german[i].partOfSpeech == "noun") {
			cout << "\n\nGerman: " << german[i].originalWord << endl;
			cout << "PartOfSpeech: " << german[i].partOfSpeech << endl;
			cout << "English: " << german[i].englishMeaning << endl;
		}
	}

	cout << "\n\nYou Chose German to English Nouns." << endl;
	cout << "Hit any key...";
	_getch();
}

void GermanToEnglishVerbs() {
	for (int i = 0; i < 25; i++) {
		if (german[i].partOfSpeech == "verb") {
			cout << "\n\nGerman: " << german[i].originalWord << endl;
			cout << "PartOfSpeech: " << german[i].partOfSpeech << endl;
			cout << "English: " << german[i].englishMeaning << endl;
		}
	}

	cout << "\n\nYou Chose German to English Verbs." << endl;
	cout << "Hit any key...";
	_getch();
}

void GermanToEnglishPrepositions() {
	for (int i = 0; i < 25; i++) {
		if (german[i].partOfSpeech == "preposition") {
			cout << "\n\nGerman: " << german[i].originalWord << endl;
			cout << "PartOfSpeech: " << german[i].partOfSpeech << endl;
			cout << "English: " << german[i].englishMeaning << endl;
		}
	}

	cout << "\n\nYou Chose German to English Prepositions." << endl;
	cout << "Hit any key...";
	_getch();
}

void GermanToEnglishAdjectives() {
	for (int i = 0; i < 25; i++) {
		if (german[i].partOfSpeech == "adjective/adverb") {
			cout << "\n\nGerman: " << german[i].originalWord << endl;
			cout << "PartOfSpeech: " << german[i].partOfSpeech << endl;
			cout << "English: " << german[i].englishMeaning << endl;
		}
	}

	cout << "\n\nYou Chose German to English Adjectives." << endl;
	cout << "Hit any key...";
	_getch();
}

void GermanToEnglishAdverbs() {
	for (int i = 0; i < 25; i++) {
		if (german[i].partOfSpeech == "adjective/adverb" || german[i].partOfSpeech == "adverb") {
			cout << "\n\nGerman: " << german[i].originalWord << endl;
			cout << "PartOfSpeech: " << german[i].partOfSpeech << endl;
			cout << "English: " << german[i].englishMeaning << endl;
		}
	}

	cout << "\n\nYou Chose German to English Adverbs." << endl;
	cout << "Hit any key...";
	_getch();
}

void GermanToEnglishCardinalNumbers() {
	for (int i = 0; i < 25; i++) {
		if (german[i].partOfSpeech == "cardinal number"){
			cout << "\n\nGerman: " << german[i].originalWord << endl;
			cout << "PartOfSpeech: " << german[i].partOfSpeech << endl;
			cout << "English: " << german[i].englishMeaning << endl;
		}
	}

	cout << "\n\nYou Chose German to English Cardinal Numbers." << endl;
	cout << "Hit any key...";
	_getch();
}

void GermanToEnglishAll() {
	for (int i = 0; i < 25; i++){
		cout << "\n\nGerman: " << german[i].originalWord << endl;
		cout << "PartOfSpeech: " << german[i].partOfSpeech << endl;
		cout << "English: " << german[i].englishMeaning << endl;
	}

	cout << "\n\nYou Chose All German to English words." << endl;
	cout << "Hit any key...";
	_getch();
}

void FrenchToEnglishSelect() {
	for (;;) {
		char choice = FrenchToEnglishMenu();
		cout << choice;
		switch (choice) {
		case '1':
			FrenchToEnglishNouns();
			break;
		case '2':
			FrenchToEnglishVerbs();
			break;
		case '3':
			FrenchToEnglishPrepositions();
			break;
		case '4':
			FrenchToEnglishAdjectives();
			break;
		case '5':
			FrenchToEnglishAdverbs();
			break;
		case '6':
			FrenchToEnglishCardinalNumbers();
			break;
		case '7':
			FrenchToEnglishPronouns();
			break;
		case '8':
			FrenchToEnglishAll();
			break;
		case '9':
			MainMenuSelect();
			break;
		case '0':
			Quit();
			break;
		default:
			cout << "\n\nInvalid choice -- try again." << endl;
			cout << "Hit any key...";
			_getch();
			break;
		}//end switch
	}//end infinite for loop
}

char FrenchToEnglishMenu() {
	char choice;
	system("cls");

	// display menu
	cout << "***French to English***" << endl;
	cout << "(1) French to English Nouns" << endl;
	cout << "(2) French to English Verbs" << endl;
	cout << "(3) French to English Prepositions" << endl;
	cout << "(4) French to English Adjectives" << endl;
	cout << "(5) French to English Adverbs" << endl;
	cout << "(6) French to English Cardinal Numbers" << endl;
	cout << "(7) French to English Pronouns" << endl;
	cout << "(8) French to English All" << endl;
	cout << "(9) MainMenu" << endl;
	cout << "(0) Quit" << endl;
	cout << "Enter Your Choice: ";

	// get user selection
	choice = _getch();
	return choice;
}

void FrenchToEnglishNouns() {
	for (int i = 0; i < 25; i++) {
		if (french[i].partOfSpeech == "noun") {
			cout << "\n\nFrench: " << french[i].originalWord << endl;
			cout << "PartOfSpeech: " << french[i].partOfSpeech << endl;
			cout << "English: " << french[i].englishMeaning << endl;
		}
	}

	cout << "\n\nYou Chose French to English Nouns." << endl;
	cout << "Hit any key...";
	_getch();
}

void FrenchToEnglishPronouns() {
	for (int i = 0; i < 25; i++) {
		if (french[i].partOfSpeech == "pronoun") {
			cout << "\n\nFrench: " << french[i].originalWord << endl;
			cout << "PartOfSpeech: " << french[i].partOfSpeech << endl;
			cout << "English: " << french[i].englishMeaning << endl;
		}
	}

	cout << "\n\nYou Chose French to English Pronouns." << endl;
	cout << "Hit any key...";
	_getch();
}

void FrenchToEnglishVerbs() {
	for (int i = 0; i < 25; i++) {
		if (french[i].partOfSpeech == "verb") {
			cout << "\n\nFrench: " << french[i].originalWord << endl;
			cout << "PartOfSpeech: " << french[i].partOfSpeech << endl;
			cout << "English: " << french[i].englishMeaning << endl;
		}
	}

	cout << "\n\nYou Chose French to English Verbs." << endl;
	cout << "Hit any key...";
	_getch();
}

void FrenchToEnglishPrepositions() {
	for (int i = 0; i < 25; i++) {
		if (french[i].partOfSpeech == "preposition") {
			cout << "\n\nFrench: " << french[i].originalWord << endl;
			cout << "PartOfSpeech: " << french[i].partOfSpeech << endl;
			cout << "English: " << french[i].englishMeaning << endl;
		}
	}

	cout << "\n\nYou Chose French to English Prepositions." << endl;
	cout << "Hit any key...";
	_getch();
}

void FrenchToEnglishAdjectives() {
	for (int i = 0; i < 25; i++) {
		if (french[i].partOfSpeech == "adjective") {
			cout << "\n\nFrench: " << french[i].originalWord << endl;
			cout << "PartOfSpeech: " << french[i].partOfSpeech << endl;
			cout << "English: " << french[i].englishMeaning << endl;
		}
	}

	cout << "\n\nYou Chose French to English Adjectives." << endl;
	cout << "Hit any key...";
	_getch();
}

void FrenchToEnglishAdverbs() {
	for (int i = 0; i < 25; i++) {
		if (french[i].partOfSpeech == "adverb") {
			cout << "\n\nFrench: " << french[i].originalWord << endl;
			cout << "PartOfSpeech: " << french[i].partOfSpeech << endl;
			cout << "English: " << french[i].englishMeaning << endl;
		}
	}

	cout << "\n\nYou Chose French to English Adverbs." << endl;
	cout << "Hit any key...";
	_getch();
}

void FrenchToEnglishCardinalNumbers() {
	for (int i = 0; i < 25; i++) {
		if (french[i].partOfSpeech == "cardinal number") {
			cout << "\n\nFrench: " << french[i].originalWord << endl;
			cout << "PartOfSpeech: " << french[i].partOfSpeech << endl;
			cout << "English: " << french[i].englishMeaning << endl;
		}
	}

	cout << "\n\nYou Chose French to English Cardinal Numbers." << endl;
	cout << "Hit any key...";
	_getch();
}

void FrenchToEnglishAll() {
	for (int i = 0; i < 25; i++) {
		cout << "\n\nFrench: " << french[i].originalWord << endl;
		cout << "PartOfSpeech: " << french[i].partOfSpeech << endl;
		cout << "English: " << french[i].englishMeaning << endl;
	}

	cout << "\n\nYou Chose All French to English words." << endl;
	cout << "Hit any key...";
	_getch();
}

void LatinToEnglishSelect() {
	for (;;) {
		char choice = LatinToEnglishMenu();
		cout << choice;
		switch (choice) {
		case '1':
			LatinToEnglishNouns();
			break;
		case '2':
			LatinToEnglishVerbs();
			break;
		case '3':
			LatinToEnglishPrepositions();
			break;
		case '4':
			LatinToEnglishAdjectives();
			break;
		case '5':
			LatinToEnglishAdverbs();
			break;
		case '6':
			LatinToEnglishConjunctions();
			break;
		case '7':
			LatinToEnglishPronouns();
			break;
		case '8':
			LatinToEnglishAll();
			break;
		case '9':
			MainMenuSelect();
			break;
		case '0':
			Quit();
			break;
		default:
			cout << "\n\nInvalid choice -- try again." << endl;
			cout << "Hit any key...";
			_getch();
			break;
		}//end switch
	}//end infinite for loop
}

char LatinToEnglishMenu() {
	char choice;
	system("cls");

	// display menu
	cout << "***Latin to English***" << endl;
	cout << "(1) Latin to English Nouns" << endl;
	cout << "(2) Latin to English Verbs" << endl;
	cout << "(3) Latin to English Prepositions" << endl;
	cout << "(4) Latin to English Adjectives" << endl;
	cout << "(5) Latin to English Adverbs" << endl;
	cout << "(6) Latin to English Conjunctions" << endl;
	cout << "(7) Latin to English Pronouns" << endl;
	cout << "(8) Latin to English All" << endl;
	cout << "(9) MainMenu" << endl;
	cout << "(0) Quit" << endl;
	cout << "Enter Your Choice: ";

	// get user selection
	choice = _getch();
	return choice;
}

void LatinToEnglishNouns() {
	for (int i = 0; i < 25; i++) {
		if (latin[i].partOfSpeech == "noun (m)" || 
			latin[i].partOfSpeech == "noun (f)" || 
			latin[i].partOfSpeech == "noun (n)") {
			cout << "\n\nLatin: " << latin[i].originalWord << endl;
			cout << "PartOfSpeech: " << latin[i].partOfSpeech << endl;
			cout << "English: " << latin[i].englishMeaning << endl;
		}
	}

	cout << "\n\nYou Chose Latin to English Nouns." << endl;
	cout << "Hit any key...";
	_getch();
}

void LatinToEnglishPronouns() {
	for (int i = 0; i < 25; i++) {
		if (latin[i].partOfSpeech == "pronoun") {
			cout << "\n\nLatin: " << latin[i].originalWord << endl;
			cout << "PartOfSpeech: " << latin[i].partOfSpeech << endl;
			cout << "English: " << latin[i].englishMeaning << endl;
		}
	}

	cout << "\n\nYou Chose Latin to English Prnouns." << endl;
	cout << "Hit any key...";
	_getch();
}

void LatinToEnglishConjunctions() {
	for (int i = 0; i < 25; i++) {
		if (latin[i].partOfSpeech == "conjunction") {
			cout << "\n\nLatin: " << latin[i].originalWord << endl;
			cout << "PartOfSpeech: " << latin[i].partOfSpeech << endl;
			cout << "English: " << latin[i].englishMeaning << endl;
		}
	}

	cout << "\n\nYou Chose Latin to English Prnouns." << endl;
	cout << "Hit any key...";
	_getch();
}

void LatinToEnglishVerbs() {
	for (int i = 0; i < 25; i++) {
		if (latin[i].partOfSpeech == "verb") {
			cout << "\n\nLatin: " << latin[i].originalWord << endl;
			cout << "PartOfSpeech: " << latin[i].partOfSpeech << endl;
			cout << "English: " << latin[i].englishMeaning << endl;
		}
	}

	cout << "\n\nYou Chose Latin to English Verbs." << endl;
	cout << "Hit any key...";
	_getch();
}

void LatinToEnglishPrepositions() {
	for (int i = 0; i < 25; i++) {
		if (latin[i].partOfSpeech == "preposition") {
			cout << "\n\nLatin: " << latin[i].originalWord << endl;
			cout << "PartOfSpeech: " << latin[i].partOfSpeech << endl;
			cout << "English: " << latin[i].englishMeaning << endl;
		}
	}

	cout << "\n\nYou Chose Latin to English Prepositions." << endl;
	cout << "Hit any key...";
	_getch();
}

void LatinToEnglishAdjectives() {
	for (int i = 0; i < 25; i++) {
		if (latin[i].partOfSpeech == "adjective") {
			cout << "\n\nLatin: " << latin[i].originalWord << endl;
			cout << "PartOfSpeech: " << latin[i].partOfSpeech << endl;
			cout << "English: " << latin[i].englishMeaning << endl;
		}
	}

	cout << "\n\nYou Chose Latin to English Adjectives." << endl;
	cout << "Hit any key...";
	_getch();
}

void LatinToEnglishAdverbs() {
	for (int i = 0; i < 25; i++) {
		if (latin[i].partOfSpeech == "adverb") {
			cout << "\n\nLatin: " << latin[i].originalWord << endl;
			cout << "PartOfSpeech: " << latin[i].partOfSpeech << endl;
			cout << "English: " << latin[i].englishMeaning << endl;
		}
	}

	cout << "\n\nYou Chose Latin to English Adverbs." << endl;
	cout << "Hit any key...";
	_getch();
}

void LatinToEnglishCardinalNumbers() {
	for (int i = 0; i < 25; i++) {
		if (latin[i].partOfSpeech == "cardinal number") {
			cout << "\n\nLatin: " << latin[i].originalWord << endl;
			cout << "PartOfSpeech: " << latin[i].partOfSpeech << endl;
			cout << "English: " << latin[i].englishMeaning << endl;
		}
	}

	cout << "\n\nYou Chose Latin to English Cardinal Numbers." << endl;
	cout << "Hit any key...";
	_getch();
}

void LatinToEnglishAll() {
	for (int i = 0; i < 25; i++) {
		cout << "\n\nLatin: " << latin[i].originalWord << endl;
		cout << "PartOfSpeech: " << latin[i].partOfSpeech << endl;
		cout << "English: " << latin[i].englishMeaning << endl;
	}

	cout << "\n\nYou Chose All Latin to English words." << endl;
	cout << "Hit any key...";
	_getch();
}

void HebrewToEnglishSelect() {
	for (;;) {
		char choice = HebrewToEnglishMenu();
		cout << choice;
		switch (choice) {
		case '1':
			HebrewToEnglishNouns();
			break;
		case '2':
			HebrewToEnglishVerbs();
			break;
		case '3':
			HebrewToEnglishPrepositions();
			break;
		case '4':
			HebrewToEnglishAdjectives();
			break;
		case '5':
			HebrewToEnglishAdverbs();
			break;
		case '6':
			HebrewToEnglishCardinalNumbers();
			break;
		case '7':
			HebrewToEnglishAll();
			break;
		case '9':
			MainMenuSelect();
			break;
		case '0':
			Quit();
			break;
		default:
			cout << "\n\nInvalid choice -- try again." << endl;
			cout << "Hit any key...";
			_getch();
			break;
		}//end switch
	}//end infinite for loop
}

char HebrewToEnglishMenu() {
	char choice;
	system("cls");

	// display menu
	cout << "***Hebrew to English***" << endl;
	cout << "(1) Hebrew to English Nouns" << endl;
	cout << "(2) Hebrew to English Verbs" << endl;
	cout << "(3) Hebrew to English Prepositions" << endl;
	cout << "(4) Hebrew to English Adjectives" << endl;
	cout << "(5) Hebrew to English Adverbs" << endl;
	cout << "(6) Hebrew to English Cardinal Numbers" << endl;
	cout << "(7) Hebrew to English All" << endl;
	cout << "(9) MainMenu" << endl;
	cout << "(0) Quit" << endl;
	cout << "Enter Your Choice: ";

	// get user selection
	choice = _getch();
	return choice;
}

void HebrewToEnglishNouns() {
	for (int i = 0; i < 25; i++) {
		if (hebrew[i].partOfSpeech == "noun (m)" || hebrew[i].partOfSpeech == "noun (f)") {
			cout << "\n\nHebrew: " << hebrew[i].originalWord << endl;
			cout << "PartOfSpeech: " << hebrew[i].partOfSpeech << endl;
			cout << "English: " << hebrew[i].englishMeaning << endl;
		}
	}

	cout << "\n\nYou Chose Hebrew to English Nouns." << endl;
	cout << "Hit any key...";
	_getch();
}

void HebrewToEnglishVerbs() {
	for (int i = 0; i < 25; i++) {
		if (hebrew[i].partOfSpeech == "verb") {
			cout << "\n\nHebrew: " << hebrew[i].originalWord << endl;
			cout << "PartOfSpeech: " << hebrew[i].partOfSpeech << endl;
			cout << "English: " << hebrew[i].englishMeaning << endl;
		}
	}

	cout << "\n\nYou Chose Hebrew to English Verbs." << endl;
	cout << "Hit any key...";
	_getch();
}

void HebrewToEnglishPrepositions() {
	for (int i = 0; i < 25; i++) {
		if (hebrew[i].partOfSpeech == "preposition") {
			cout << "\n\nHebrew: " << hebrew[i].originalWord << endl;
			cout << "PartOfSpeech: " << hebrew[i].partOfSpeech << endl;
			cout << "English: " << hebrew[i].englishMeaning << endl;
		}
	}

	cout << "\n\nYou Chose Hebrew to English Prepositions." << endl;
	cout << "Hit any key...";
	_getch();
}

void HebrewToEnglishAdjectives() {
	for (int i = 0; i < 25; i++) {
		if (hebrew[i].partOfSpeech == "adjective (m)") {
			cout << "\n\nHebrew: " << hebrew[i].originalWord << endl;
			cout << "PartOfSpeech: " << hebrew[i].partOfSpeech << endl;
			cout << "English: " << hebrew[i].englishMeaning << endl;
		}
	}

	cout << "\n\nYou Chose Hebrew to English Adjectives." << endl;
	cout << "Hit any key...";
	_getch();
}

void HebrewToEnglishAdverbs() {
	for (int i = 0; i < 25; i++) {
		if (hebrew[i].partOfSpeech == "adverb" || hebrew[i].partOfSpeech == "adverb (m)") {
			cout << "\n\nHebrew: " << hebrew[i].originalWord << endl;
			cout << "PartOfSpeech: " << hebrew[i].partOfSpeech << endl;
			cout << "English: " << hebrew[i].englishMeaning << endl;
		}
	}

	cout << "\n\nYou Chose Hebrew to English Adverbs." << endl;
	cout << "Hit any key...";
	_getch();
}

void HebrewToEnglishCardinalNumbers() {
	for (int i = 0; i < 25; i++) {
		if (hebrew[i].partOfSpeech == "cardinal number") {
			cout << "\n\nHebrew: " << hebrew[i].originalWord << endl;
			cout << "PartOfSpeech: " << hebrew[i].partOfSpeech << endl;
			cout << "English: " << hebrew[i].englishMeaning << endl;
		}
	}

	cout << "\n\nYou Chose Hebrew to English Cardinal Numbers." << endl;
	cout << "Hit any key...";
	_getch();
}

void HebrewToEnglishAll() {
	for (int i = 0; i < 25; i++) {
		cout << "\n\nHebrew: " << hebrew[i].originalWord << endl;
		cout << "PartOfSpeech: " << hebrew[i].partOfSpeech << endl;
		cout << "English: " << hebrew[i].englishMeaning << endl;
	}

	cout << "\n\nYou Chose All Hebrew to English words." << endl;
	cout << "Hit any key...";
	_getch();
}

void EnglishToGermanSelect() {
	for (;;) {
		char choice = EnglishToGermanMenu();
		cout << choice;
		switch (choice) {
		case '1':
			EnglishToGermanNouns();
			break;
		case '2':
			EnglishToGermanVerbs();
			break;
		case '3':
			EnglishToGermanPrepositions();
			break;
		case '4':
			EnglishToGermanAdjectives();
			break;
		case '5':
			EnglishToGermanAdverbs();
			break;
		case '6':
			EnglishToGermanCardinalNumbers();
			break;
		case '7':
			EnglishToGermanAll();
			break;
		case '9':
			MainMenuSelect();
			break;
		case '0':
			Quit();
			break;
		default:
			cout << "\n\nInvalid choice -- try again." << endl;
			cout << "Hit any key...";
			_getch();
			break;
		}//end switch
	}//end infinite for loop
}

char EnglishToGermanMenu() {
	char choice;
	system("cls");

	// display menu
	cout << "***English To German***" << endl;
	cout << "(1) English To German Nouns" << endl;
	cout << "(2) English To German Verbs" << endl;
	cout << "(3) English To German Prepositions" << endl;
	cout << "(4) English To German Adjectives" << endl;
	cout << "(5) English To German Adverbs" << endl;
	cout << "(6) English To German Cardinal Numbers" << endl;
	cout << "(7) English To German All" << endl;
	cout << "(9) MainMenu" << endl;
	cout << "(0) Quit" << endl;
	cout << "Enter Your Choice: ";

	// get user selection
	choice = _getch();
	return choice;
}

void EnglishToGermanNouns() {
	for (int i = 0; i < 25; i++) {
		if (german[i].partOfSpeech == "noun") {
			cout << "\n\nEnglish: " << german[i].englishMeaning << endl;
			cout << "German: " << german[i].originalWord << endl;
			cout << "PartOfSpeech: " << german[i].partOfSpeech << endl;
		}
	}

	cout << "\n\nYou Chose English to German Nouns." << endl;
	cout << "Hit any key...";
	_getch();
}

void EnglishToGermanVerbs() {
	for (int i = 0; i < 25; i++) {
		if (german[i].partOfSpeech == "verb") {
			cout << "\n\nEnglish: " << german[i].englishMeaning << endl;
			cout << "German: " << german[i].originalWord << endl;
			cout << "PartOfSpeech: " << german[i].partOfSpeech << endl;
		}
	}

	cout << "\n\nYou Chose English to German Verbs." << endl;
	cout << "Hit any key...";
	_getch();
}

void EnglishToGermanPrepositions() {
	for (int i = 0; i < 25; i++) {
		if (german[i].partOfSpeech == "preposition") {
			cout << "\n\nEnglish: " << german[i].englishMeaning << endl;
			cout << "German: " << german[i].originalWord << endl;
			cout << "PartOfSpeech: " << german[i].partOfSpeech << endl;
		}
	}

	cout << "\n\nYou Chose English to German Prepositions." << endl;
	cout << "Hit any key...";
	_getch();
}

void EnglishToGermanAdjectives() {
	for (int i = 0; i < 25; i++) {
		if (german[i].partOfSpeech == "adjective/adverb") {
			cout << "\n\nEnglish: " << german[i].englishMeaning << endl;
			cout << "German: " << german[i].originalWord << endl;
			cout << "PartOfSpeech: " << german[i].partOfSpeech << endl;
		}
	}

	cout << "\n\nYou Chose English to German Adjectives." << endl;
	cout << "Hit any key...";
	_getch();
}

void EnglishToGermanAdverbs() {
	for (int i = 0; i < 25; i++) {
		if (german[i].partOfSpeech == "adjective/adverb" || german[i].partOfSpeech == "adverb") {
			cout << "\n\nEnglish: " << german[i].englishMeaning << endl;
			cout << "German: " << german[i].originalWord << endl;
			cout << "PartOfSpeech: " << german[i].partOfSpeech << endl;
		}
	}

	cout << "\n\nYou Chose English to German Adverbs." << endl;
	cout << "Hit any key...";
	_getch();
}

void EnglishToGermanCardinalNumbers() {
	for (int i = 0; i < 25; i++) {
		if (german[i].partOfSpeech == "cardinal number") {
			cout << "\n\nEnglish: " << german[i].englishMeaning << endl;
			cout << "German: " << german[i].originalWord << endl;
			cout << "PartOfSpeech: " << german[i].partOfSpeech << endl;
		}
	}

	cout << "\n\nYou Chose English to German Cardinal Numbers." << endl;
	cout << "Hit any key...";
	_getch();
}

void EnglishToGermanAll() {
	for (int i = 0; i < 25; i++) {
		cout << "\n\nEnglish: " << german[i].englishMeaning << endl;
		cout << "German: " << german[i].originalWord << endl;
		cout << "PartOfSpeech: " << german[i].partOfSpeech << endl;
	}

	cout << "\n\nYou Chose All English to German words." << endl;
	cout << "Hit any key...";
	_getch();
}

void EnglishToFrenchSelect() {
	for (;;) {
		char choice = EnglishToFrenchMenu();
		cout << choice;
		switch (choice) {
		case '1':
			EnglishToFrenchNouns();
			break;
		case '2':
			EnglishToFrenchVerbs();
			break;
		case '3':
			EnglishToFrenchPrepositions();
			break;
		case '4':
			EnglishToFrenchAdjectives();
			break;
		case '5':
			EnglishToFrenchAdverbs();
			break;
		case '6':
			EnglishToFrenchCardinalNumbers();
			break;
		case '7':
			EnglishToFrenchPronouns();
			break;
		case '8':
			EnglishToFrenchAll();
			break;
		case '9':
			MainMenuSelect();
			break;
		case '0':
			Quit();
			break;
		default:
			cout << "\n\nInvalid choice -- try again." << endl;
			cout << "Hit any key...";
			_getch();
			break;
		}//end switch
	}//end infinite for loop
}

char EnglishToFrenchMenu() {
	char choice;
	system("cls");

	// display menu
	cout << "***English To French***" << endl;
	cout << "(1) English To French Nouns" << endl;
	cout << "(2) English To French Verbs" << endl;
	cout << "(3) English To French Prepositions" << endl;
	cout << "(4) English To French Adjectives" << endl;
	cout << "(5) English To French Adverbs" << endl;
	cout << "(6) English To French Cardinal Numbers" << endl;
	cout << "(7) English To French Pronouns" << endl;
	cout << "(8) English To French All" << endl;
	cout << "(9) MainMenu" << endl;
	cout << "(0) Quit" << endl;
	cout << "Enter Your Choice: ";

	// get user selection
	choice = _getch();
	return choice;
}

void EnglishToFrenchNouns() {
	for (int i = 0; i < 25; i++) {
		if (french[i].partOfSpeech == "noun") {
			cout << "\n\nEnglish: " << french[i].englishMeaning << endl;
			cout << "French: " << french[i].originalWord << endl;
			cout << "PartOfSpeech: " << french[i].partOfSpeech << endl;
		}
	}

	cout << "\n\nYou Chose English to French Nouns." << endl;
	cout << "Hit any key...";
	_getch();
}

void EnglishToFrenchPronouns() {
	for (int i = 0; i < 25; i++) {
		if (french[i].partOfSpeech == "pronoun") {
			cout << "\n\nEnglish: " << french[i].englishMeaning << endl;
			cout << "French: " << french[i].originalWord << endl;
			cout << "PartOfSpeech: " << french[i].partOfSpeech << endl;
		}
	}

	cout << "\n\nYou Chose English to French Nouns." << endl;
	cout << "Hit any key...";
	_getch();
}

void EnglishToFrenchVerbs() {
	for (int i = 0; i < 25; i++) {
		if (french[i].partOfSpeech == "verb") {
			cout << "\n\nEnglish: " << french[i].englishMeaning << endl;
			cout << "French: " << french[i].originalWord << endl;
			cout << "PartOfSpeech: " << french[i].partOfSpeech << endl;
		}
	}

	cout << "\n\nYou Chose English to French Verbs." << endl;
	cout << "Hit any key...";
	_getch();
}

void EnglishToFrenchPrepositions() {
	for (int i = 0; i < 25; i++) {
		if (french[i].partOfSpeech == "preposition") {
			cout << "\n\nEnglish: " << french[i].englishMeaning << endl;
			cout << "French: " << french[i].originalWord << endl;
			cout << "PartOfSpeech: " << french[i].partOfSpeech << endl;
		}
	}

	cout << "\n\nYou Chose English to French Prepositions." << endl;
	cout << "Hit any key...";
	_getch();
}

void EnglishToFrenchAdjectives() {
	for (int i = 0; i < 25; i++) {
		if (french[i].partOfSpeech == "adjective") {
			cout << "\n\nEnglish: " << french[i].englishMeaning << endl;
			cout << "French: " << french[i].originalWord << endl;
			cout << "PartOfSpeech: " << french[i].partOfSpeech << endl;
		}
	}

	cout << "\n\nYou Chose English to French Adjectives." << endl;
	cout << "Hit any key...";
	_getch();
}

void EnglishToFrenchAdverbs() {
	for (int i = 0; i < 25; i++) {
		if (french[i].partOfSpeech == "adverb") {
			cout << "\n\nEnglish: " << french[i].englishMeaning << endl;
			cout << "French: " << french[i].originalWord << endl;
			cout << "PartOfSpeech: " << french[i].partOfSpeech << endl;
		}
	}

	cout << "\n\nYou Chose English to French Adverbs." << endl;
	cout << "Hit any key...";
	_getch();
}

void EnglishToFrenchCardinalNumbers() {
	for (int i = 0; i < 25; i++) {
		if (french[i].partOfSpeech == "cardinal number") {
			cout << "\n\nEnglish: " << french[i].englishMeaning << endl;
			cout << "French: " << french[i].originalWord << endl;
			cout << "PartOfSpeech: " << french[i].partOfSpeech << endl;
		}
	}

	cout << "\n\nYou Chose English to French Cardinal Numbers." << endl;
	cout << "Hit any key...";
	_getch();
}

void EnglishToFrenchAll() {
	for (int i = 0; i < 25; i++) {
		cout << "\n\nEnglish: " << french[i].englishMeaning << endl;
		cout << "French: " << french[i].originalWord << endl;
		cout << "PartOfSpeech: " << french[i].partOfSpeech << endl;
	}

	cout << "\n\nYou Chose All English to French words." << endl;
	cout << "Hit any key...";
	_getch();
}

void EnglishToLatinSelect() {
	for (;;) {
		char choice = EnglishToLatinMenu();
		cout << choice;
		switch (choice) {
		case '1':
			EnglishToLatinNouns();
			break;
		case '2':
			EnglishToLatinVerbs();
			break;
		case '3':
			EnglishToLatinPrepositions();
			break;
		case '4':
			EnglishToLatinAdjectives();
			break;
		case '5':
			EnglishToLatinAdverbs();
			break;
		case '6':
			EnglishToLatinConjunctions();
			break;
		case '7':
			EnglishToLatinPronouns();
			break;
		case '8':
			EnglishToLatinAll();
			break;
		case '9':
			MainMenuSelect();
			break;
		case '0':
			Quit();
			break;
		default:
			cout << "\n\nInvalid choice -- try again." << endl;
			cout << "Hit any key...";
			_getch();
			break;
		}//end switch
	}//end infinite for loop
}

char EnglishToLatinMenu() {
	char choice;
	system("cls");

	// display menu
	cout << "***English To Latin***" << endl;
	cout << "(1) English To Latin Nouns" << endl;
	cout << "(2) English To Latin Verbs" << endl;
	cout << "(3) English To Latin Prepositions" << endl;
	cout << "(4) English To Latin Adjectives" << endl;
	cout << "(5) English To Latin Adverbs" << endl;
	cout << "(6) English To Latin Conjunctions" << endl;
	cout << "(7) English To Latin Pronouns" << endl;
	cout << "(8) English To Latin All" << endl;
	cout << "(9) MainMenu" << endl;
	cout << "(0) Quit" << endl;
	cout << "Enter Your Choice: ";

	// get user selection
	choice = _getch();
	return choice;
}

void EnglishToLatinNouns() {
	for (int i = 0; i < 25; i++) {
		if (latin[i].partOfSpeech == "noun (m)" ||
			latin[i].partOfSpeech == "noun (f)" ||
			latin[i].partOfSpeech == "noun (n)") {
			cout << "\n\nEnglish: " << latin[i].englishMeaning << endl;
			cout << "Latin: " << latin[i].originalWord << endl;
			cout << "PartOfSpeech: " << latin[i].partOfSpeech << endl;
		}
	}

	cout << "\n\nYou Chose English to Latin Nouns." << endl;
	cout << "Hit any key...";
	_getch();
}

void EnglishToLatinPronouns() {
	for (int i = 0; i < 25; i++) {
		if (latin[i].partOfSpeech == "pronoun") {
			cout << "\n\nEnglish: " << latin[i].englishMeaning << endl;
			cout << "Latin: " << latin[i].originalWord << endl;
			cout << "PartOfSpeech: " << latin[i].partOfSpeech << endl;
		}
	}

	cout << "\n\nYou Chose English to Latin Nouns." << endl;
	cout << "Hit any key...";
	_getch();
}

void EnglishToLatinVerbs() {
	for (int i = 0; i < 25; i++) {
		if (latin[i].partOfSpeech == "verb") {
			cout << "\n\nEnglish: " << latin[i].englishMeaning << endl;
			cout << "Latin: " << latin[i].originalWord << endl;
			cout << "PartOfSpeech: " << latin[i].partOfSpeech << endl;
		}
	}

	cout << "\n\nYou Chose English to Latin Verbs." << endl;
	cout << "Hit any key...";
	_getch();
}

void EnglishToLatinPrepositions() {
	for (int i = 0; i < 25; i++) {
		if (latin[i].partOfSpeech == "preposition") {
			cout << "\n\nEnglish: " << latin[i].englishMeaning << endl;
			cout << "Latin: " << latin[i].originalWord << endl;
			cout << "PartOfSpeech: " << latin[i].partOfSpeech << endl;
		}
	}

	cout << "\n\nYou Chose English to Latin Prepositions." << endl;
	cout << "Hit any key...";
	_getch();
}

void EnglishToLatinAdjectives() {
	for (int i = 0; i < 25; i++) {
		if (latin[i].partOfSpeech == "adjective") {
			cout << "\n\nEnglish: " << latin[i].englishMeaning << endl;
			cout << "Latin: " << latin[i].originalWord << endl;
			cout << "PartOfSpeech: " << latin[i].partOfSpeech << endl;
		}
	}

	cout << "\n\nYou Chose English to Latin Adjectives." << endl;
	cout << "Hit any key...";
	_getch();
}

void EnglishToLatinAdverbs() {
	for (int i = 0; i < 25; i++) {
		if (latin[i].partOfSpeech == "adverb") {
			cout << "\n\nEnglish: " << latin[i].englishMeaning << endl;
			cout << "Latin: " << latin[i].originalWord << endl;
			cout << "PartOfSpeech: " << latin[i].partOfSpeech << endl;
		}
	}

	cout << "\n\nYou Chose English to Latin Adverbs." << endl;
	cout << "Hit any key...";
	_getch();
}

void EnglishToLatinConjunctions() {
	for (int i = 0; i < 25; i++) {
		if (latin[i].partOfSpeech == "conjunction") {
			cout << "\n\nEnglish: " << latin[i].englishMeaning << endl;
			cout << "Latin: " << latin[i].originalWord << endl;
			cout << "PartOfSpeech: " << latin[i].partOfSpeech << endl;
		}
	}

	cout << "\n\nYou Chose English to Latin Cardinal Numbers." << endl;
	cout << "Hit any key...";
	_getch();
}

void EnglishToLatinAll() {
	for (int i = 0; i < 25; i++) {
		cout << "\n\nEnglish: " << latin[i].englishMeaning << endl;
		cout << "Latin: " << latin[i].originalWord << endl;
		cout << "PartOfSpeech: " << latin[i].partOfSpeech << endl;
	}

	cout << "\n\nYou Chose All English to Latin words." << endl;
	cout << "Hit any key...";
	_getch();
}






void EnglishToHebrewSelect() {
	for (;;) {
		char choice = EnglishToHebrewMenu();
		cout << choice;
		switch (choice) {
		case '1':
			EnglishToHebrewNouns();
			break;
		case '2':
			EnglishToHebrewVerbs();
			break;
		case '3':
			EnglishToHebrewPrepositions();
			break;
		case '4':
			EnglishToHebrewAdjectives();
			break;
		case '5':
			EnglishToHebrewAdverbs();
			break;
		case '6':
			EnglishToHebrewCardinalNumbers();
			break;
		case '7':
			EnglishToHebrewAll();
			break;
		case '9':
			MainMenuSelect();
			break;
		case '0':
			Quit();
			break;
		default:
			cout << "\n\nInvalid choice -- try again." << endl;
			cout << "Hit any key...";
			_getch();
			break;
		}//end switch
	}//end infinite for loop
}

char EnglishToHebrewMenu() {
	char choice;
	system("cls");

	// display menu
	cout << "***English To Hebrew***" << endl;
	cout << "(1) English To Hebrew Nouns" << endl;
	cout << "(2) English To Hebrew Verbs" << endl;
	cout << "(3) English To Hebrew Prepositions" << endl;
	cout << "(4) English To Hebrew Adjectives" << endl;
	cout << "(5) English To Hebrew Adverbs" << endl;
	cout << "(6) English To Hebrew Cardinal Numbers" << endl;
	cout << "(7) English To Hebrew All" << endl;
	cout << "(9) MainMenu" << endl;
	cout << "(0) Quit" << endl;
	cout << "Enter Your Choice: ";

	// get user selection
	choice = _getch();
	return choice;
}

void EnglishToHebrewNouns() {
	for (int i = 0; i < 25; i++) {
		if (hebrew[i].partOfSpeech == "noun (m)" ||
			hebrew[i].partOfSpeech == "noun (f)") {
			cout << "\n\nEnglish: " << hebrew[i].englishMeaning << endl;
			cout << "Hebrew: " << hebrew[i].originalWord << endl;
			cout << "PartOfSpeech: " << hebrew[i].partOfSpeech << endl;
		}
	}

	cout << "\n\nYou Chose English to Hebrew Nouns." << endl;
	cout << "Hit any key...";
	_getch();
}

void EnglishToHebrewVerbs() {
	for (int i = 0; i < 25; i++) {
		if (hebrew[i].partOfSpeech == "verb") {
			cout << "\n\nEnglish: " << hebrew[i].englishMeaning << endl;
			cout << "Hebrew: " << hebrew[i].originalWord << endl;
			cout << "PartOfSpeech: " << hebrew[i].partOfSpeech << endl;
		}
	}

	cout << "\n\nYou Chose English to Hebrew Verbs." << endl;
	cout << "Hit any key...";
	_getch();
}

void EnglishToHebrewPrepositions() {
	for (int i = 0; i < 25; i++) {
		if (hebrew[i].partOfSpeech == "preposition") {
			cout << "\n\nEnglish: " << hebrew[i].englishMeaning << endl;
			cout << "Hebrew: " << hebrew[i].originalWord << endl;
			cout << "PartOfSpeech: " << hebrew[i].partOfSpeech << endl;
		}
	}

	cout << "\n\nYou Chose English to Hebrew Prepositions." << endl;
	cout << "Hit any key...";
	_getch();
}

void EnglishToHebrewAdjectives() {
	for (int i = 0; i < 25; i++) {
		if (hebrew[i].partOfSpeech == "adjective (m)") {
			cout << "\n\nEnglish: " << hebrew[i].englishMeaning << endl;
			cout << "Hebrew: " << hebrew[i].originalWord << endl;
			cout << "PartOfSpeech: " << hebrew[i].partOfSpeech << endl;
		}
	}

	cout << "\n\nYou Chose English to Hebrew Adjectives." << endl;
	cout << "Hit any key...";
	_getch();
}

void EnglishToHebrewAdverbs() {
	for (int i = 0; i < 25; i++) {
		if (hebrew[i].partOfSpeech == "adverb" || hebrew[i].partOfSpeech == "adverb (m)") {
			cout << "\n\nEnglish: " << hebrew[i].englishMeaning << endl;
			cout << "Hebrew: " << hebrew[i].originalWord << endl;
			cout << "PartOfSpeech: " << hebrew[i].partOfSpeech << endl;
		}
	}

	cout << "\n\nYou Chose English to Hebrew Adverbs." << endl;
	cout << "Hit any key...";
	_getch();
}

void EnglishToHebrewCardinalNumbers() {
	for (int i = 0; i < 25; i++) {
		if (hebrew[i].partOfSpeech == "cardinal number") {
			cout << "\n\nEnglish: " << hebrew[i].englishMeaning << endl;
			cout << "Hebrew: " << hebrew[i].originalWord << endl;
			cout << "PartOfSpeech: " << hebrew[i].partOfSpeech << endl;
		}
	}

	cout << "\n\nYou Chose English to Hebrew Cardinal Numbers." << endl;
	cout << "Hit any key...";
	_getch();
}

void EnglishToHebrewAll() {
	for (int i = 0; i < 25; i++) {
		cout << "\n\nEnglish: " << hebrew[i].englishMeaning << endl;
		cout << "Hebrew: " << hebrew[i].originalWord << endl;
		cout << "PartOfSpeech: " << hebrew[i].partOfSpeech << endl;
	}

	cout << "\n\nYou Chose All English to Hebrew words." << endl;
	cout << "Hit any key...";
	_getch();
}