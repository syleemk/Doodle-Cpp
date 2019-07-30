#include <iostream>
#include <string>

using namespace std;

class Image {
public:
	operator string() {//형변환연산자 오버로딩
		return "사진";
	}
};

class Message {
public:
	Message(int sendTime, string sendName) {
		this->sendTime = sendTime;
		this->sendName = sendName;
	}

	int GetSendTime() const { return sendTime; }
	string GetSendName() const { return sendName; }
private:
	int sendTime;
	string sendName;
};

class TextMessage : public Message{
public:
	TextMessage(int sendTime, string sendName, string text) 
	: Message(sendTime, sendName) { //생성자 위임, 부모클래스의 생성자가 여러개 오버로딩 되있는 경우 컴파일러가 어떤 생성자 호출해야할지 모르므로, 생성자를 명시해줘야함
		this->text = text;
	}

	string GetText() const { return text; }

private:
	string text;
};

class ImageMessage : public Message {
public:
	ImageMessage(int sendTime, string sendName, Image * image)
	: Message(sendTime, sendName) { //생성자 위임
		this->image = image;
	}

	Image * GetImage() const { return image; }

private:
	Image * image;

};

int main() {
	Image * p_dogImage = new Image(); //Image자체는 생성자가 없으니 기본생성자 적어준다
	TextMessage * hello = new TextMessage(10, "두들", "안녕");
	ImageMessage *dog = new ImageMessage(20, "두들", p_dogImage);

	cout << "보낸 시간 : " << hello->GetSendTime() << endl;
	cout << "보낸 사람 : " << hello->GetSendName() << endl;
	cout << "  내 용   : " << hello->GetText() << endl;
	cout << endl;

	cout << "보낸 시간 : " << dog->GetSendTime() << endl;
	cout << "보낸 사람 : " << dog->GetSendName() << endl;
	cout << "  내 용   : " << (string)*dog->GetImage() << endl;
	cout << endl;

	delete hello;
	delete dog;
	delete p_dogImage;
}