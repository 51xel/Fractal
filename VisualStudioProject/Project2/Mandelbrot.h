#pragma once

namespace mybitmap {
	class Mandelbrot {
	public:
		 int MAX_ITERATIONS = 500;

	public:
		Mandelbrot(int iteartions);
		Mandelbrot() = default;

		int getIterations(double x, double y);
	};
}