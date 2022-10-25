#include "Window.h"

MyWindow::MyWindow(int width, int height, string& filename) : 
	m_width(width), 
	m_height(height), 
	filename(filename), 
	window(VideoMode(width + 200, height), "Fractal"){
}

void MyWindow::drawWindow() {
	drawImagie();

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}

			if (event.type == sf::Event::MouseMoved){
				if (event.mouseMove.x <= m_width and event.mouseMove.y <= m_height) {
					m_xMouse = event.mouseMove.x;
					m_yMouse = event.mouseMove.y;
				}
			}

			if (event.type == sf::Event::MouseWheelScrolled && event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel){
				if (event.mouseWheelScroll.delta > 0) {
					zoomList.push_back(Zoom(m_xMouse, m_height - m_yMouse, 0.5));

					drawImagie();
				}
				else {
					zoomList.pop_back();

					drawImagie();
				}
			}

			if (event.type == sf::Event::KeyPressed)
				if (event.key.code == sf::Keyboard::Up) {
					m_max_iterations_plus += 100;

					drawImagie();
				}
				if (event.key.code == sf::Keyboard::Down) {
					if (m_max_iterations_plus - 100 != 0) {
						m_max_iterations_plus -= 100;

						drawImagie();
					}
				}
		}

		createText();

		window.clear(Color(250, 250, 250, 0));

		window.draw(textForMouseX);
		window.draw(textForMouseY);
		window.draw(textForMaxIterations);
		window.draw(imagesprite);
		window.display();
	}
}

void MyWindow::drawImagie() {
	createFractal();

	imagetexture.loadFromFile(filename);
	imagesprite.setTexture(imagetexture);
	imagesprite.setPosition(0, 0);
}

void MyWindow::createFractal() {
	MyFractal fractalCreator(m_width, m_height, m_max_iterations_plus);

	cout << "+Starting rendering" << endl;
	cout << "\tAdding zoom" << endl;
	for (int i = 0; i < zoomList.size(); i++) {
		fractalCreator.addZoom(zoomList[i]);
	}

	cout << "\tCalculating iterations" << endl;
	fractalCreator.calculateIteration();
	cout << "\tCalculating total iterations" << endl;
	fractalCreator.calculateTotalIterations();
	cout << "\tDrawing fractal" << endl;
	fractalCreator.drawFractal();
	cout << "\tSaving" << endl;
	fractalCreator.writeBitmap(filename);

	cout << "+Rendered" << endl;
}

void MyWindow::createText() {
	string tmpString;

	font.loadFromFile("BanderaPro.ttf");

	tmpString = "Mouse X: " + to_string(m_xMouse);

	textForMouseX.setFont(font);
	textForMouseX.setString(tmpString.substr(0, tmpString.find_last_not_of('0')));
	textForMouseX.setCharacterSize(20);
	textForMouseX.setFillColor(sf::Color::Black);
	textForMouseX.setPosition(m_width + 20, 50);

	tmpString = "Mouse Y: " + to_string(m_yMouse);

	textForMouseY.setFont(font);
	textForMouseY.setString(tmpString.substr(0, tmpString.find_last_not_of('0')));
	textForMouseY.setCharacterSize(20);
	textForMouseY.setFillColor(sf::Color::Black);
	textForMouseY.setPosition(m_width + 20, 70);

	tmpString = "Iterations: " + to_string(m_max_iterations_plus);

	textForMaxIterations.setFont(font);
	textForMaxIterations.setString(tmpString);
	textForMaxIterations.setCharacterSize(20);
	textForMaxIterations.setFillColor(sf::Color::Black);
	textForMaxIterations.setPosition(m_width + 20, 90);
}