//#include <iostream>
//#include <vector>
//#include <opencv2/core.hpp>
//#include <opencv2/imgproc.hpp>
//#include <opencv2/highgui.hpp>
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
//	// GFTT ���
//	std::vector<KeyPoint> keypoints;
//
//	// GFTT �����
//	cv::Ptr<cv::GFTTDetector> ptrGFTT =
//		GFTTDetector::create(500, // Ư¡�� �ִ� ����
//							0.01, // ǰ�� ����
//							10);  // �� ���� �ּ� ��� �Ÿ�
//
//	// GFTT ����
//	ptrGFTT->detect(src, keypoints);
//
//	std::vector<KeyPoint>::const_iterator it = keypoints.begin();
//	while (it != keypoints.end()) {
//		cv::circle(src, it->pt, 3, cv::Scalar(255, 255, 255), 1);
//		++it;
//	}
//
//	namedWindow("GFTT");
//	imshow("GFTT", src);
//
//	waitKey();
//	return 0;
//}