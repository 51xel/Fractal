#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include <fstream>

using namespace mybitmap;

namespace mybitmap {

	Bitmap::Bitmap(int width, int height) : m_width(width), m_height(height), m_Pixels(new uint8_t[width * height * 3]{}) {}

	bool Bitmap::write(string &filename) {
		BitmapFileHeader File;
		BitmapInfoHeader Info;

		File.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + (m_width * m_height * 3);
		File.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

		Info.width = m_width;
		Info.height = m_height;

		ofstream fileToWrite;

		fileToWrite.open(filename, ios::out|ios::binary);

		if (!fileToWrite) {
			return false;
		}

		fileToWrite.write((char *)&File, sizeof(File));
		fileToWrite.write((char*)&Info, sizeof(Info));
		fileToWrite.write((char*)m_Pixels.get(), m_width * m_height * 3);

		fileToWrite.close();

		return true;
	}

	void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
		uint8_t* Pixel = m_Pixels.get();

		Pixel += (y * 3) * m_width + (x * 3);

		Pixel[0] = blue;
		Pixel[1] = green;
		Pixel[2] = red;
	}

}