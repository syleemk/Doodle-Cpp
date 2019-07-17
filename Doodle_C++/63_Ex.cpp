/*
	1. �Ʒ��� GameWindow Ŭ������ �ڵ忡�� â �ʺ�� ���̸� �Ű������� �޴� ResizeWindow �Լ��� �߰��Ͽ�
	���� ���ǰ� ���� width�� height�� ���� �ٲ� �� �ֵ��� �ϼ���
		- ���� �Ű������� ���� ��ġ�ϵ��� â ũ�⸦ ������ ��.
		- �ʺ� 800���� �۰ų� ���̰� 600���� ���� ���� ���� 800, 600���� ������ ��.

	2. GameWindow::GameWindow(int w, int h) �����ڵ� ���������� 1���� ������ �����ϵ��� �����ϼ���.

	3. �ۼ��� �ڵ忡�� ���ȭ�� ������ �κ��� ��� ���ȭ�ϼ���.
*/

#include <iostream>

using namespace std;

class GameWindow {
public:
	GameWindow();
	GameWindow(const int, const int);

	int GetWidth() const;
	int GetHeight() const;

	void ResizeWindow(const int, const int);
private:
	int width;
	int height;
};

int main() {
	GameWindow mainWindow;
	mainWindow.ResizeWindow(500, 768);
	cout << mainWindow.GetWidth() << "x" << mainWindow.GetHeight() << endl;
}

GameWindow::GameWindow() : width(800), height(600) {}
GameWindow::GameWindow(const int w, const int h) {
	ResizeWindow(w, h);
}

int GameWindow::GetWidth() const{
	return width;
}
int GameWindow::GetHeight() const{
	return height;
}

void GameWindow::ResizeWindow(int w, int h) {
	if (w < 800) w = 800;
	if (h < 600) h = 600;

	width = w;
	height = h;
}