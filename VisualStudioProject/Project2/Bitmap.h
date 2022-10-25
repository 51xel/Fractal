#pragma once
#include <string>
#include <cstdint>
#include <iostream>

using namespace std;


namespace mybitmap {

	class Bitmap {
	protected:
		int m_width{ 0 };
		int m_height{ 0 };
		unique_ptr<uint8_t[]> m_Pixels{ nullptr };

	public:
		Bitmap(int width, int height);

		bool write(string &filename);
		void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
	};
}
