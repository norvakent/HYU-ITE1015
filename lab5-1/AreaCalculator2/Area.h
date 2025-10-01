#ifndef AREA_H
#define AREA_H

#include <iostream>
#include <string>
using namespace std;

class Area {
	private:
		int width;
		int height;
		float area;
		string shape;
	
	public:
		Area(int w, int h);
		Area(int size);
		Area(const string& i_shape, int w, int h);
		void calculate();
		void print() const;
};

#endif
