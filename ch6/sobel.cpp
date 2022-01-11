//#include <stdio.h>
//#include <opencv2/core.hpp>
//#include <opencv2/imgproc.hpp>
//#include <opencv2/highgui.hpp>
//using namespace cv;
//
//int main() {
//	// ���� ����
//	Mat src = imread("C:/Users/lge/Desktop/OpenCV/images/boldt.jpg", 0);
//
//	namedWindow("Original Image");
//	imshow("Original Image", src);
//	// �Һ����� - ����
//	Mat sobelX;
//	Sobel(src, sobelX, CV_8U, 1, 0, 3, 0.4, 128);
//
//	namedWindow("Sobel X Image");
//	imshow("Sobel X Image", sobelX);
//	// �Һ����� - ����
//	Mat sobelY;
//	Sobel(src, sobelY, CV_8U, 0, 1, 3, 0.4, 128);
//
//	namedWindow("Sobel Y Image");
//	imshow("Sobel Y Image", sobelY);
//
//	// �Һ� �� ���
//	Sobel(src, sobelX, CV_16S, 1, 0);
//	Sobel(src, sobelY, CV_16S, 0, 1);
//	// L1 �� ���
//	Mat sobel;
//	sobel = abs(sobelX) + abs(sobelY);
//	// �Һ� �ּҰ�, �ִ밪 ã��
//	double sobmin, sobmax;
//	minMaxLoc(sobel, &sobmin, &sobmax);
//	// 8��Ʈ �������� ��ȯ
//	Mat sobelImage;
//	sobel.convertTo(sobelImage, CV_8U, -255./sobmax, 255);
//
//	namedWindow("Sobel Image");
//	imshow("Sobel Image", sobelImage);
//
//	Mat sobelThresholdedL;
//	threshold(sobelImage, sobelThresholdedL, 225, 255, THRESH_BINARY);
//
//	namedWindow("Binary Sobel Image(Low)");
//	imshow("Binary Sobel Image(Low)", sobelThresholdedL);
//
//	Mat sobelThresholdedH;
//	threshold(sobelImage, sobelThresholdedH, 190, 255, THRESH_BINARY);
//
//	namedWindow("Binary Sobel Image(High)");
//	imshow("Binary Sobel Image(High)", sobelThresholdedH);
//
//	Mat scharrX;
//	Scharr(src, scharrX, CV_16S, 1, 0, 3);
//
//	namedWindow("ScharrX");
//	imshow("ScharrX", scharrX);
//
//	cv::waitKey();
//	return 0;
//}
//
