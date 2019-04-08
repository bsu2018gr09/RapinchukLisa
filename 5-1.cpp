//Горизонтальный чёрно-белый линейный градиент

#include<iostream>
#include<fstream>  
using namespace std;

struct color { unsigned char r; unsigned char g; unsigned char b; } c;

int main() {
	ifstream fin("C:\\1\\file1.bmp", ios::binary); //  ios::binary влияет ТОЛЬКО на endl.
	ofstream fout("C:\\1\\output.bmp", ios::binary);//сюда пишем (поток типа ofstream= output file stream)

	if (!fin) { cout << "No file C:\\1\\file1.bmp"; exit(1); }
	if (!fout) { cout << "   file C:\\1\\output.bmp. Can't create\n"; exit(1); }

	char buf[30];// куда читать байты
	unsigned char r1 = 100, g1 = 0, b1 = 0; //компоненты цвета
	unsigned char r2 = 255, g2 = 5, b2 = 2;
	color c;
	unsigned int w, h; //надеемся. что тут 4 байта

	fin.read((char *)&buf, 18);   //чтение 18 байт заголовка bmp
	fout.write((char *)&buf, 18);    //запись 18 байт заголовка bmp

	fin.read((char *)&w, 4); cout << "w=" << w;   //чтение width из заголовка bmp
	fin.read((char *)&w, 4); cout << ", h=" << w; //чтение height из заголовка bmp

	w = 256; fout.write((char *)&w, 4);    //запись width в заголовок bmp ( w кратно 4, обязательно для нас, чтобы не делать выравнивание)
	h = 128; fout.write((char *)&h, 4);    //запись height в заголовок bmp

	fin.read((char *)&buf, 28);   //чтение 28 байт заголовка bmp
	fout.write((char *)&buf, 28);    //запись 28 байт заголовка bmp

	int step = 250;  

	float tr = (float)r1;
	float tg = (float)g1;
	float tb = (float)b1;

	float sr = (float)(r2 - r1) / step;
	float sg = (float)(g2 - g1) / step;
	float sb = (float)(b2 - b1) / step;

	int stepCount = 0;

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			/*Если счётчик меньше шага заливки, наращиваем цвет и затем записываем. Если нет, то просто записываем цвет*/
			if (stepCount < step) {
				tr += sr;
				tg += sg;
				tb += sb;
				c.r = (unsigned char)tr;
				c.g = (unsigned char)tg;
				c.b = (unsigned char)tb;
				stepCount++;
			}
			fout.write((char *)&c, 3);     //запись сразу всего цвета
		}
		/*Переход на новую строку и обнуление цвета (возврат к чёрному)*/
		tr = (float)r1;
		tg = (float)g1;
		tb = (float)b1;
		stepCount = 0;
	}

	fin.close();
	fout.close();
	return 1;
}
