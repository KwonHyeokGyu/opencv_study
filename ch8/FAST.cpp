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
	
	// 특징점 벡터
	std::vector<KeyPoint> keypoints;
	
	// FAST 특징 검출기 객체를 경계 값 40과 함께 생성
	Ptr<FastFeatureDetector> ptrFAST = 
		FastFeatureDetector::create(40);

	// 특징점 검출
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