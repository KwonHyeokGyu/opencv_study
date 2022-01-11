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
//	// SURF 특징 검출기 객체 생성
//	cv::Ptr<cv::xfeatures2d::SurfFeatureDetector> ptrSURF =
//		cv::xfeatures2d::SurfFeatureDetector::create(2000.0);
//
//	std::vector<KeyPoint> keypoints;
//
//	Mat featureImage;
//
//	// 특징점 검출
//	ptrSURF->detect(src, keypoints);
//	// 특징점을 크기와 방향 정보와 함께 그리기
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
//	// 특징점 검출
//	ptrSURF->detect(src2, keypoints);
//	// 특징점을 크기와 방향 정보와 함께 그리기
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