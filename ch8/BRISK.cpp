//#include <iostream>
//#include <vector>
//#include <opencv2/core.hpp>
//#include <opencv2/imgproc.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/xfeatures2d.hpp>
//#include <opencv2/features2d.hpp>
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
//	Mat featureImage;
//
//	// BRISK Æ¯Â¡ °ËÃâ±â °´Ã¼ »ý¼º
//	Ptr<BRISK> ptrBRISK = BRISK::create(60, 8);
//
//	std::vector<KeyPoint> keypoints;
//
//	// Æ¯Â¡Á¡ °ËÃâ
//	ptrBRISK->detect(src, keypoints);
//
//	drawKeypoints(src, keypoints, featureImage, cv::Scalar(255, 255, 255), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
//
//	namedWindow("BRISK");
//	imshow("BRISK", featureImage);
//
//	waitKey();
//	return 0;
//}