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
	Canny(src,		// 그레이레벨 영상
		  contours, // 결과 외곽선
		  125,		// 낮은 경계 값
		  350);		// 높은 경계 값

	namedWindow("Canny Contours");
	imshow("Canny Contours", 255 - contours);

	waitKey();
	return 0;
}