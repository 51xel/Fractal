#include "Window.h"
#include "SetOptions.h"

using namespace mybitmap;

int main() {
	SetOptions setoptions;

	setoptions.SayHello();
	setoptions.AskUserAboutSize();
	setoptions.AskUserAboutFilePath();

	MyWindow window(setoptions.m_width, setoptions.m_height, setoptions.m_filePath);

	window.drawWindow();

	return 0;
}