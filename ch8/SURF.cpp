//#include <iostream>
//#include <vector>
//#include <opencv2/core.hpp>
//#include <opencv2/imgproc.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/xfeatures2d.hpp>
//using namespace cv;
//
//int main()
//{
//	Mat src = imread("C:/Users/lge/Desktop/p3.jpg", 0);
//	if (!src.data)
//		return 0;
//
//	namedWindow("Original image");
//	imshow("Original image", src);
//	
//	// SURF Ư¡ ����� ��ü ����
//	cv::Ptr<cv::xfeatures2d::SurfFeatureDetector> ptrSURF =
//		cv::xfeatures2d::SurfFeatureDetector::create(2000.0);
//
//	std::vector<KeyPoint> keypoints;
//
//	Mat featureImage;
//
//	// Ư¡�� ����
//	ptrSURF->detect(src, keypoints);
//	// Ư¡���� ũ��� ���� ������ �Բ� �׸���
//	drawKeypoints(src,
//		keypoints,
//		featureImage,
//		Scalar(255, 255, 255),
//		DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
//
//
//	namedWindow("SURF");
//	imshow("SURF", featureImage);
//
//	Mat src2 = imread("C:/Users/lge/Desktop/p3.jpg", 0);
//	if (!src.data)
//		return 0;
//
//	
//	// Ư¡�� ����
//	ptrSURF->detect(src2, keypoints);
//	// Ư¡���� ũ��� ���� ������ �Բ� �׸���
//	drawKeypoints(src2,
//		keypoints,
//		featureImage,
//		Scalar(255, 255, 255),
//		DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
//
//	namedWindow("SURF(2)");
//	imshow("SURF(2)", featureImage);
//
//	waitKey();
//	return 0;
//}