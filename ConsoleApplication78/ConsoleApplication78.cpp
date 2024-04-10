#include <iostream>
using namespace std;
/*
	Паттерн проэктирования - шаблон или подход к решению определенной задачи

	1) структурные патерны
	2) поведенческие паттерны
	3) пораждающие паттерны

	single tone (одиночка) - паттерн проэктирования, при котором на основе класса можно создать только один обьект

	1) убрать констурктор в приватную область
	2) создать статичную приватную область
	3) реализовать статический метод возвращающий указатель на обьект


*/

class SingleTone
{
	static SingleTone* obj;
	SingleTone()
	{}
public:
	static SingleTone* GetInstance()
	{
		if (obj == nullptr)
		{
			obj = new SingleTone();
		}
		return obj;
	}
	static void dropInstance()
	{
		if (obj!=nullptr)
		{
			delete obj;
			obj = nullptr;
		}
	}
};

SingleTone* SingleTone::obj{ nullptr };

int main()
{
	SingleTone* s1 = SingleTone::GetInstance();
	SingleTone* s2 = SingleTone::GetInstance();
}