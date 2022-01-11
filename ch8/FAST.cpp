#include <iostream>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/features2d.hpp>
using namespace cv;

int main()
{
	Mat src = imread("C:/Users/lge/Desktop/p3.jpg", 0);
	if (!src.data)
		return 0;

	namedWindow("Original image");
	imshow("Original image", src);
	
	// Ư¡�� ����
	std::vector<KeyPoint> keypoints;
	
	// FAST Ư¡ ����� ��ü�� ��� �� 40�� �Բ� ����
	Ptr<FastFeatureDetector> ptrFAST = 
		FastFeatureDetector::create(40);

	// Ư¡�� ����
	ptrFAST->detect(src, keypoints);

	drawKeypoints(src, 
				keypoints, 
				src, 
				Scalar(255, 255, 255),
		DrawMatchesFlags::DRAW_OVER_OUTIMG);

	namedWindow("FAST");
	imshow("FAST", src);

	waitKey();
	return 0;
}