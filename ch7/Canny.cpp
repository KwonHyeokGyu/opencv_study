#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;

int main() {
	Mat src = imread("C:/Users/lge/Desktop/OpenCV/images/road.jpg", 0);

	namedWindow("Original Image");
	imshow("Original Image", src);

	Mat contours;
	Canny(src,		// �׷��̷��� ����
		  contours, // ��� �ܰ���
		  125,		// ���� ��� ��
		  350);		// ���� ��� ��

	namedWindow("Canny Contours");
	imshow("Canny Contours", 255 - contours);

	waitKey();
	return 0;
}