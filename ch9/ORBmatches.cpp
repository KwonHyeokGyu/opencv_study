//#include <iostream>
//#include <vector>
//#include <opencv2/core.hpp>
//#include <opencv2/imgproc.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/xfeatures2d.hpp>
//#include <opencv2/objdetect.hpp>
//using namespace cv;
//
//int main()
//{
//	Mat image1 = imread("../../images/church01.jpg");
//	Mat image2 = imread("../../images/church02.jpg");
//
//	std::vector<KeyPoint> keypoints1;
//	std::vector<KeyPoint> keypoints2;
//
//	namedWindow("image1");
//	imshow("image1", image1);
//
//	namedWindow("image2");
//	imshow("image2", image2);
//
//	// Ư¡�� �����/����� ����
//	// ORB Ư¡ ����� ��ü ����
//	// �� 60���� Ư¡�� ����
//	Ptr<Feature2D> feature = ORB::create(60);
//
//	// ����� ����
//	Mat descriptors1;
//	Mat descriptors2;
//	
//	// Ư¡�� ����� ���
//	// ORB Ư¡ ����
//	feature->detectAndCompute(image1, noArray(), keypoints1, descriptors1);
//	feature->detectAndCompute(image2, noArray(), keypoints2, descriptors2);
//
//	// ���ձ�(matcher)����
//	BFMatcher matcher(NORM_HAMMING);
//
//	// ���� ������ǰ�� �� ���� ����� ����
//	std::vector<DMatch> matches;
//	matcher.match(descriptors1, descriptors2, matches);
//
//	Mat matchImage;
//	
//	drawMatches(image1, keypoints1,		// ù ��° ����
//				image2, keypoints2,		// �� ��° ����
//				matches,				// ���� ����
//				matchImage,
//				Scalar(255, 255, 255),	// �� �÷�
//				Scalar(255, 255, 255),	// �� �÷�
//				std::vector< char >(),      // masks if any 
//				DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS | DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
//	namedWindow("ORB Matches");
//	imshow("ORB Matches", matchImage);
//
//	waitKey();
//	return 0;
//}