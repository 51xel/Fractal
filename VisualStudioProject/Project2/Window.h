#pragma once
#include "MyFractal.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace mybitmap;

class MyWindow {
protected:
	int m_width{ 0 };
	int m_height{ 0 };
	float m_xMouse{ 0 };
	float m_yMouse{ 0 };

	int m_max_iterations_plus{ 100 };

	string filename;

	RenderWindow window;
	Event event;

	Font font;
	Text textForMouseX;
	Text textForMouseY;
	Text textForMaxIterations;

	Texture imagetexture;
	Sprite imagesprite;

	vector<Zoom> zoomList;

public:
	MyWindow(int width, int height, string &filename);
	MyWindow() = default;

	void drawWindow();
	void drawImagie();
	void createFractal();
	void createText();
};