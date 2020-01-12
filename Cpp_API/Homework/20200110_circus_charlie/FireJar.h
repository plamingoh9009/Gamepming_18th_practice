#pragma once
class FireJar
{
private:
	image * _img;

public:
	FireJar();
	~FireJar();

	HRESULT init();
	void release();
	void update();
	void render();
};

