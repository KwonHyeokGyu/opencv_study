//#include <stdio.h>
//#include <opencv2/core.hpp>
//#include <opencv2/imgproc.hpp>
//#include <opencv2/highgui.hpp>
//using namespace cv;
//
//int main() {
//	// ���� ����
//	Mat image = imread("C:/Users/lge/Desktop/OpenCV/images/boldt.jpg");
//
//	namedWindow("Original Image");
//	imshow("Original Image", image);
//
//	// GaussianBlur ����
//	Mat result;
//
//	GaussianBlur(image, result, Size(5, 5), 1.5);
//	
//	namedWindow("Gaussian filtered Image");
//	imshow("Gaussian filtered Image", result);
//	
//	// ����ũ�⸦ 4��� ����� ���� - �߸��� ����
//	Mat image2 = imread("C:/Users/lge/Desktop/OpenCV/images/boldt.jpg", 0);
//	Mat reduced(image2.rows / 4, image2.cols / 4, CV_8U);
//	for (int i = 0; i < reduced.rows; i++) {
//		for (int j = 0; j < reduced.cols; j++) {
//			reduced.at<uchar>(i, j) = image2.at<uchar>(i * 4, j * 4);
//		}
//	}
//
//	// ����ũ��
//	resize(reduced, reduced, Size(image.cols, image.rows));
//	
//	cv::namedWindow("Badly reduced Image");
//	cv::imshow("Badly reduced Image", reduced);
//
//	// ����ũ�⸦ 4��� ����� ����
//	// ������ ���� ����
//	GaussianBlur(image2, image2, cv::Size(11, 11), 2.0);
//	// 4ȭ�Ҹ��� 1ȭ�Ҹ� ����
//	Mat reduced2(image2.rows / 4, image2.cols / 4, CV_8U);
//	for (int i = 0; i < reduced2.rows; i++) {
//		for (int j = 0; j < reduced2.cols; j++) {
//			reduced2.at<uchar>(i, j) = image2.at<uchar>(i * 4, j * 4);
//		}
//	}
//
//	resize(reduced2, reduced2, Size(image.cols, image.rows));
//
//	namedWindow("Reduced Image");
//	imshow("Reduced Image", reduced2);
//	
//	// pyrDown - ������ 2��� ���
//	Mat reducedImage;
//	pyrDown(image, reducedImage);
//	
//	namedWindow("pyrDown");
//	imshow("pyrDown", reducedImage);
//
//	// ���� ���
//	Mat resizedImage;
//	resize(image, resizedImage, Size(image.cols / 4, image.rows / 4));
//
//	namedWindow("ResizedImage");
//	imshow("ResizedImage", resizedImage);
//
//	// ���� ���
//	resize(image, resizedImage, Size(), 1.0 / 4.0, 1.0 / 4.0);
//
//	namedWindow("Resize Image");
//	imshow("Resize Image", resizedImage);
//
//	// �ֱ��� �̿� ������
//	Mat newImage;
//	resize(reduced, newImage, Size(), 3, 3, INTER_NEAREST);
//
//	namedWindow("New Image");
//	imshow("New Image", newImage);
//
//	// �缱�� ������
//	resize(reduced2, newImage, Size(), 3, 3, INTER_LINEAR);
//
//	namedWindow("Bilinear resizing");
//	imshow("Bilinear resizing", newImage);
//
//	// �߰� �� ����
//	medianBlur(image, result, 5);
//
//	namedWindow("Median filtered Image");
//	imshow("Median filtered Image", result);
//
//	// �߰� �� ���� - S&P noise
//	Mat image3 = imread("C:/Users/lge/Desktop/OpenCV/images/salted.bmp", 0);
//	medianBlur(image3, result, 5);
//
//	namedWindow("Median filtered S&P Image");
//	imshow("Median filtered S&P Image", result);
//
//	// ��� �� ���� - S&P noise
//	blur(image3, result, Size(5, 5));
//
//	namedWindow("Mean filtered S&P Image");
//	imshow("Mean filtered S&P Image", result);
//	
//	cv::waitKey();
//	return 0;
//}