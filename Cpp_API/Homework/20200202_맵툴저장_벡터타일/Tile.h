#pragma once
#include "gameNode.h"
class Tile: public gameNode
{
private:
	typedef vector<string> vStrings;
private:
	image * _img;
	RECT _rc;
	string _type;
	int _width;
	int _height;
	// ��� Ÿ�� ������ �̸��� ������ �ִ´�.
	vStrings _sampleNames;
protected:
	template<class Vec>
	DWORD get_vectorSizes(Vec v);
	void init_allSampleNames();
	void draw_samples();
public:
	void setup_tile(string type, int x, int y);
	void setup_tile(string type, int x, int y, bool isCenter);
	vector<string> get_sampleNames() { return _sampleNames; }
	RECT get_rc() { return _rc; }
	string get_type() { return _type; }
	DWORD get_thisSize();
public:
	Tile();
	~Tile();
	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(/*HDC hdc*/);//�׸��°�
};

template<class Vec>
inline DWORD Tile::get_vectorSizes(Vec v)
{
	DWORD totalSize = 0;

	auto iter = v.begin();
	for (;iter != v.end();iter++)
	{
		totalSize += sizeof(*iter);
	}//for: ���͸� �ѹ��� ������.
	return totalSize;
}
