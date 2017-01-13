/*
JRV_CaesarCipher.cpp by James R. Vaughan
Purpose: Solve the CaesarCipher and display time taken to solve
*/


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <math.h>

using namespace std;
using std::ofstream;


int _tmain(int argc, _TCHAR* argv[])
{
	string CipherText;
	string PlainText;
	int CipherShift;
	int CipherLength;
	char CipherChar;

	ofstream MyOutput("C:\JRV\PlainText.txt");

	clock_t t;
	time_t StartTime;
	time_t EndTime;

	int Variable;


	//---
	CipherText = "Ty ncjaezrclasj, pyncjaetzy td esp acznpdd zq eclydqzcxtyr tyqzcxletzy (cpqpccpo ez ld awltyepie) fdtyr ly lwrzctesx (nlwwpo ntaspc) ez xlvp te fycplolmwp ez lyjzyp pinpae eszdp azddpddtyr dapntlw vyzhwporp, fdflwwj cpqpccpo ez ld l vpj. Esp cpdfwe zq esp acznpdd td pyncjaepo tyqzcxletzy (ty ncjaezrclasj, cpqpccpo ez ld ntaspcepie).";
	CipherShift = 15; // shift every letter forward by 15 spaces
	CipherLength = CipherText.size();
	PlainText.resize(CipherLength);
	//---

	time(&StartTime);

	cout << "JRV_CaesarCipher" << endl;
	cout << "By James Vaughan" << endl << endl;
	cout << "Our selected ciphertext:" << endl;
	cout << CipherText << endl << endl;
	cout << "Processing ciphertext..." << endl << endl;

	t = clock();
	

	// Converting characters one by one:
	for (int i = 0; i < CipherLength; ++i)
	{
		CipherChar = CipherText[i];

		// Capital letters
		if ( (CipherChar > 64) && (CipherChar < 91) )
		{
			CipherChar = CipherChar - 64;
			CipherChar = (CipherChar + CipherShift) % 26;
			CipherChar = CipherChar + 64;
		};


		// Lowercase letters
		if ((CipherChar > 96) && (CipherChar < 123))
		{
			CipherChar = CipherChar - 96;
			CipherChar = (CipherChar + CipherShift) % 26;
			CipherChar = CipherChar + 96;
		};


		PlainText [i] = CipherChar; // ADD TO PLAINTEXT
	}

	time(&EndTime);

	t = clock() - t;

	cout << "Processing complete." << endl;
	cout << "Decrypted ciphertext:" << endl;
	cout << PlainText << endl << endl;
	cout << "Start time: " << StartTime << endl;
	cout << "End time: " << EndTime << endl;
	cout << "Elapsed time (microseconds): ";
	cout << ((long double)t / CLOCKS_PER_SEC) * 1000000;
	cout << endl;

	MyOutput << PlainText;
	MyOutput.close();

	// End of program:
	cout << endl;
	cout << "To exit the program, press any key followed by the ENTER key";
	cin >> Variable;
	return 0;
}
