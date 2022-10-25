#include "MyFractal.h"

namespace mybitmap {

	MyFractal::MyFractal(int width, int height, int iterations) : 
		m_width(width), 
		m_height(height),
		m_mandelbrot(iterations),
		m_histogram(new int[m_mandelbrot.MAX_ITERATIONS]{ 0 }),
		m_fractal(new int[width * height]{ 0 }),
		m_bitmap(width, height),
		m_zoomList(width, height) {
		
		m_zoomList.add(Zoom(m_width / 2, m_height / 2, 4.0 / m_width));
	}

	void MyFractal::calculateIteration() {

		vector<thread> newThread;

		for (int y = 0; y < m_height; y++) {
			newThread.push_back(thread{ [=]() {
					for (int x = 0; x < m_width; x++) {
						pair<double, double> coords = m_zoomList.doZoom(x, y);

						int iterations = m_mandelbrot.getIterations(coords.first, coords.second);

						m_fractal[y * m_width + x] = iterations;

						if (iterations != m_mandelbrot.MAX_ITERATIONS) {
							m_histogram[iterations]++;
						}
					}
				}
				}
			);
		}

		for (int y = 0; y < this->m_height; y++) {
			newThread[y].join();
		}
	}

	void MyFractal::drawFractal() {
		for (int y = 0; y < m_height; y++) {
			for (int x = 0; x < m_width; x++) {

				uint8_t red = 0;
				uint8_t green = 0;
				uint8_t blue = 0;

				int iterations = m_fractal[y * m_width + x];

				if (iterations != m_mandelbrot.MAX_ITERATIONS) {

					double hue = 0.0;
					for (int i = 0; i <= iterations; i++) {
						hue += ((double)m_histogram[i]) / m_total;
					}

					green = pow(255, hue);
				}

				m_bitmap.setPixel(x, y, red, green, blue);
			}
		}
	}

	void MyFractal::addZoom(const Zoom& zoom) {
		m_zoomList.add(zoom);
	}

	void MyFractal::writeBitmap(string &filename) {
		m_bitmap.write(filename);
	}

	void MyFractal::calculateTotalIterations() {
		for (int i = 0; i < m_mandelbrot.MAX_ITERATIONS; i++) {
			m_total += m_histogram[i];
		}
	}
}