//#include <iostream>
//#include <vector>
//#include <opencv2/core/core.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/highgui/highgui.hpp>
//using namespace cv;
//
//int main()
//{
//	Mat src = imread("C:/Users/lge/Desktop/OpenCV/images/church01.jpg", 0);
//	if (!src.data)
//		return 0;
//
//	namedWindow("Original image");
//	imshow("Original image", src);
//
//	// �ظ��� �ڳ� ����
//	Mat cornerStrength;
//	// �Է¿���, �ڳ� ���� ����, �̿� ũ��, ���� ũ��, �ظ��� �Ķ����
//	cornerHarris(src, cornerStrength, 3, 3, 0.01);
//
//	// �ڳ� ������ ��� �� ����
//	Mat harrisCorners, harrisCorners2;
//	double threshold = 0.0001;
//	cv::threshold(cornerStrength, harrisCorners, threshold, 255, THRESH_BINARY);
//
//	namedWindow("Harris");
//	imshow("Harris", harrisCorners);
//
//	cv::threshold(cornerStrength, harrisCorners2, threshold, 255, THRESH_BINARY_INV);
//
//	namedWindow("Harris INV");
//	imshow("Harris INV", harrisCorners2);
//
//	waitKey();
//	return 0;
//}