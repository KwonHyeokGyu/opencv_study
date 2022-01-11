//#include <iostream>
//#include <opencv2/core.hpp>
//#include <opencv2/imgproc.hpp>
//#include <opencv2/highgui.hpp>
//using namespace cv;
//
//int main() {
//	Mat src = imread("C:/Users/lge/Desktop/OpenCV/images/road.jpg", 0);
//
//	namedWindow("Original Image");
//	imshow("Original Image", src);
//
//	// 수평 필터링
//	Mat sobelX;
//	Sobel(src, sobelX, CV_8U, 1, 0, 3, 0.4, 128);
//	// 수직 필터링
//	Mat sobelY;
//	Sobel(src, sobelY, CV_8U, 0, 1, 3, 0.4, 128);
//
//	// 소벨 놈 계산
//	Sobel(src, sobelX, CV_16S, 1, 0);
//	Sobel(src, sobelY, CV_16S, 0, 1);
//
//	// L1 놈 계산
//	Mat sobel;
//	sobel = abs(sobelX) + abs(sobelY);
//
//	// 소벨 최댓값, 최소값 찾기
//	double sobmin, sobmax;
//	minMaxLoc(sobel, &sobmin, &sobmax);
//	
//	// 8비트 영상으로 반환
//	// sobelImage = -alpha*sobel + 255
//	Mat sobelImage;
//	sobel.convertTo(sobelImage, CV_8U, -255. / sobmax, 255);
//
//	Mat lowthreshold, highthreshold;
//	//threshold(sobelImage, lowthreshold, , 255, THRESH_BINARY);
//
//	namedWindow("Sobel (low threshold)");
//	imshow("Sobel (low threshold)",lowthreshold);
//
//	sobel.convertTo(sobelImage, CV_8U, -255. / sobmax, 255);
//
//	threshold(sobelImage, highthreshold, 150, 255, THRESH_BINARY);
//
//	namedWindow("Sobel (high threshold)");
//	imshow("Sobel (high threshold)", highthreshold);
//
//	waitKey();
//	return 0;
//}