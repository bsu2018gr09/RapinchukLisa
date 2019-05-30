//Горизонтальный чёрно-белый линейный градиент

#include<iostream>
#include<fstream> 
using namespace std;

struct color { unsigned char b; unsigned char g; unsigned char r;} c;

int main() {
	ifstream fin("C:\\1\\file1.bmp", ios::binary); //  ios::binary влияет ТОЛЬКО на endl.
	ofstream fout("C:\\1\\output.bmp", ios::binary);//сюда пишем (поток типа ofstream= output file stream)

	if (!fin) { cout << "No file C:\\1\\file1.bmp"; exit(1); }
	if (!fout) { cout << "   file C:\\1\\output.bmp. Can't create\n"; exit(1); }

	char buf[30];// куда читать байты
	unsigned char r1 = 1, g1 = 25, b1 = 255; //компоненты цвета
	unsigned char r2 = 120, g2 = 47, b2 = 0;
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

	unsigned int step{ 0 };
	cout << '\n';
	cin >> step;

	double sr, sg, sb;
	double s = (double)w / (step);
	

	sr = (double)(r2 - r1) / (w-s);
	sg = (double)(g2 - g1) / (w-s);
	sb = (double)(b2 - b1) / (w-s);

	if (step < w) {
		sr *= s;
		sg *= s;
		sb *= s;
	}

	double tr = (double)r1;
	double tg = (double)g1;
	double tb = (double)b1;

	

	int stepCount = 1;

	for (unsigned int i = 1; i <= h; i++) {
		for (unsigned int j = 1; j <= w; j++) {
			/*Если счётчик меньше шага заливки, наращиваем цвет и затем записываем. Если нет, то просто записываем цвет*/
			if (stepCount < s) {
				c.r = (unsigned char)tr;
				c.g = (unsigned char)tg;
				c.b = (unsigned char)tb;
				stepCount++;
			}
			else {
				tr += sr;
				tg += sg;
				tb += sb;
				c.r = (unsigned char)tr;
				c.g = (unsigned char)tg;
				c.b = (unsigned char)tb;
				stepCount = 1;
			}
			fout.write((char *)&c, 3);
			     //запись сразу всего цвета
		}
		/*Переход на новую строку и обнуление цвета*/
		tr = (double)r1;
		tg = (double)g1;
		tb = (double)b1;
		stepCount = 0;
	}

	fin.close();
	fout.close();
	return 1;
}