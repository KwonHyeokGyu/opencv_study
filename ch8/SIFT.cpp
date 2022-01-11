//#include <iostream>
//#include <vector>
//#include <opencv2/core.hpp>
//#include <opencv2/imgproc.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/xfeatures2d.hpp>
//#include <opencv2/features2d.hpp>
//using namespace cv;
//using namespace xfeatures2d;
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
//	// SIFT Æ¯Â¡ °ËÃâ±â °´Ã¼ »ý¼º
//	Ptr<SiftFeatureDetector> ptrSIFT = SiftFeatureDetector::create();
//
//	std::vector<KeyPoint> keypoints;
//
//	// Æ¯Â¡Á¡ °ËÃâ
//	ptrSIFT->detect(src, keypoints);
//
//	drawKeypoints(src, keypoints, featureImage, cv::Scalar(255, 255, 255), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
//
//	// Display the keypoints
//	namedWindow("SIFT");
//	imshow("SIFT", featureImage);
//
//	waitKey();
//	return 0;
//}