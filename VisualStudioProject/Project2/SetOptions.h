#pragma once
#include <iostream>

using namespace std;

class SetOptions{

public:
	string m_filePath;
	int m_width;
	int m_height;

	SetOptions() = default;

	void SayHello() {
		cout << "\t\t$$$$$$_$$$$$___$$$$___$$$$__$$$$$$__$$$$__$$____" << endl;
		cout << "\t\t$$_____$$__$$_$$__$$_$$__$$___$$___$$__$$_$$____" << endl;
		cout << "\t\t$$$$___$$$$$__$$$$$$_$$_______$$___$$$$$$_$$____" << endl;
		cout << "\t\t$$_____$$__$$_$$__$$_$$__$$___$$___$$__$$_$$____" << endl;
		cout << "\t\t$$_____$$__$$_$$__$$__$$$$____$$___$$__$$_$$$$$$" << endl;
		cout << "================================================================================" << endl;
		cout << endl << "INSTRUCTION:" << endl;
		cout << "\t-Mouse wheel for zoom." << endl;
		cout << "\t-Arrow buttons to increase or decrease the number of iterations (the depth and detail of the picture)." << endl << endl;
	}

	void AskUserAboutSize() {
		cout << "Enter the size of window (800x600): ";
		cout << endl << "\tWidth: ";
		cin >> m_width;
		cout << endl << "\tHeight: ";
		cin >> m_height;

		if (m_width <= 0 or m_height <= 0) {
			cout << "Error size of window should be > 0" << endl;
			AskUserAboutSize();
		}
	}

	void AskUserAboutFilePath() {
		cout << "Enter the path and name of image (*.bmp): ";
		cin >> m_filePath;
	}
}; 

