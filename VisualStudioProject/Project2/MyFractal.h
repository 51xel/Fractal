#pragma once
#include <iostream>
#include <cstdint>
#include <memory>
#include <thread>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"

using namespace std;


namespace mybitmap {
	class MyFractal {
	protected:
		int m_width{0};
		int m_height{0};
		int m_total{0};
		Mandelbrot m_mandelbrot;
		unique_ptr<int[]> m_histogram;
		unique_ptr<int[]> m_fractal;
		Bitmap m_bitmap;
		ZoomList m_zoomList;

	public:
		MyFractal(int width, int height, int iterations);

		void calculateIteration();
		void drawFractal();
		void addZoom(const Zoom&);
		void writeBitmap(string &filename);
		void calculateTotalIterations();
	};
}