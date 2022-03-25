#include "stdafx.h"
#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

/*** 
Author: Walysson Carlos dos Santos Oliveira
***/

void mostrar(String nome, Mat img);
map<int, Point3_<uchar>* > paletaCores(Mat img);
void printPoint3(Point3_<uchar>* p);

int main()
{
	Mat imgLenaRGB = imread("lena.jpg", IMREAD_COLOR);
	mostrar("imgLena", imgLenaRGB);

	int indice_da_cor_na_paleta = 70;

	map<int, Point3_<uchar>*> paleta = paletaCores(imgLenaRGB);
	Point3_<uchar>* cor = paleta.find(indice_da_cor_na_paleta)->second;
	printPoint3(cor);

	waitKey(0);
	return 0;
}

void mostrar(String nome, Mat img) {
	namedWindow(nome, WINDOW_NORMAL);
	imshow(nome, img);
}

void printPoint3(Point3_<uchar>* p) {
	cout << "R: " << unsigned(p->z) << " ";
	cout << "G: " << unsigned(p->y) << " ";
	cout << "B: " << unsigned(p->x) << endl;
}

map<int, Point3_<uchar>* > paletaCores(Mat img) {
	map<int, Point3_<uchar>*> paleta;
	int index = 0;

	for (int x = 0; x < img.rows; x++) {
		for (int y = 0; y < img.cols; y++) {
			Point3_<uchar>* pixel = img.ptr<Point3_<uchar> >(x, y);
			paleta.insert(make_pair(index, pixel));
			index++;
		}
	}

	return paleta;
}
