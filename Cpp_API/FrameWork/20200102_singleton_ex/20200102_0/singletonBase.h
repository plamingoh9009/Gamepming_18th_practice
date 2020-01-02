#pragma once
// ======================================
// singletonBase (�̰����� �̱����� �����.)
// ======================================

/*
	�̱��� ������ static member�� �ϳ��� �ν��Ͻ��� �����ȴ�.
	���α׷� �ȿ��� ���������� ������ �����ϴ�.

	���������� �����ص� �ϳ��� �ν��Ͻ��� ������ �� �ֱ� ������
	�̱��������� ����ϸ� Ŭ���� �ڽ��� �ڱ��� ������ �ν��Ͻ���
	�����ϴ� ����� ĸ��ȭ�Ͽ� ������ �� �ִ�. ���� ���, ��ü����, �Ҹ�
	�ν��Ͻ� ���� ���� �� Ȱ�뿡 �����ϴ�.

	�ٸ� �ν��Ͻ��� �������� �ʵ��� ó���� �� �ְ�, ���� ��� ���� ������
	�� �� �ִ�.
*/

template <typename T>
class SingletonBase
{
protected:
	// �̱��� �ν��Ͻ� ����
	static T* singleton;

	SingletonBase() {};
	~SingletonBase() {};

public:
	static T* getSingleton();
	void releaseSingleton();
};

// �̱��� �ν��Ͻ� ����
template<typename T>
T* SingletonBase<T>::singleton = nullptr;

// �̱��� ��ü ��������
template<typename T>
T* SingletonBase<T>::getSingleton()
{
	if (!singleton) singleton = new T;

	return singleton;
}

template<typename T>
void SingletonBase<T>::releaseSingleton()
{
	if (singleton)
	{
		delete singleton;
		singleton = nullptr;
	}
}