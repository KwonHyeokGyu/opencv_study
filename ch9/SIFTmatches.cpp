//#include <iostream>
//#include <vector>
//#include <opencv2/core.hpp>
//#include <opencv2/imgproc.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/features2d.hpp>
//#include <opencv2/xfeatures2d.hpp>
//#include <opencv2/objdetect.hpp>
//using namespace cv;
//
//int main()
//{
//	Mat image1 = imread("C:/Users/lge/Desktop/OpenCV/images/church01.jpg");
//	Mat image2 = imread("C:/Users/lge/Desktop/OpenCV/images/church02.jpg");
//	Mat image3 = imread("C:/Users/lge/Desktop/OpenCV/images/church03.jpg");
//
//	std::vector<KeyPoint> keypoints1;
//	std::vector<KeyPoint> keypoints2;
//	std::vector<KeyPoint> keypoints3;
//
//	namedWindow("image1");
//	imshow("image1", image1);
//
//	namedWindow("image2");
//	imshow("image2", image2);
//
//	namedWindow("image3");
//	imshow("image3", image3);
//
//	// Extract the keypoints and descriptors
//	Ptr<Feature2D> ptrFeature2D = SIFT::create(74);
//
//	// Ư¡�� ����
//	ptrFeature2D->detect(image1, keypoints1);
//	ptrFeature2D->detect(image2, keypoints2);
//
//	// ����� ����
//	Mat descriptors1;
//	Mat descriptors2;
//	Mat descriptors3;
//	ptrFeature2D->compute(image1, keypoints1, descriptors1);
//	ptrFeature2D->compute(image2, keypoints2, descriptors2);
//	ptrFeature2D->compute(image3, keypoints3, descriptors3);
//
//	// ���ձ�(matcher)����
//	BFMatcher matcher(NORM_L2);
//
//	// �� ����� ����
//	std::vector<DMatch> matches;
//	matcher.match(descriptors1, descriptors2, matches);
//
//	// ���� ��� �׸���
//	Mat matchImage;
//	drawMatches(image1, keypoints1,		// ù ��° ����
//				image2, keypoints2,		// �� ��° ����
//				matches,				// ���� ����
//				matchImage,
//				Scalar(255, 255, 255),	// �� �÷�
//				Scalar(255, 255, 255),	// �� �÷�
//				std::vector< char >(),      // masks if any 
//				DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS | DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
//	
//	namedWindow("SIFT Matches");
//	imshow("SIFT Matches", matchImage);
//
//	ptrFeature2D->detectAndCompute(image1, noArray(), keypoints1, descriptors1);
//	ptrFeature2D->detectAndCompute(image3, noArray(), keypoints3, descriptors3);
//
//	// Match the two image descriptors
//	matcher.match(descriptors1, descriptors3, matches);
//
//	// extract the 50 best matches
//	std::nth_element(matches.begin(), matches.begin() + 50, matches.end());
//	matches.erase(matches.begin() + 50, matches.end());
//
//	// ���� ��� �׸���
//	drawMatches(image1, keypoints1,		// ù ��° ����
//				image3, keypoints3,		// �� ��° ����
//				matches,				// ���� ����
//				matchImage,
//				Scalar(255, 255, 255),	// �� �÷�
//				Scalar(255, 255, 255),	// �� �÷�
//				std::vector< char >(),      // masks if any 
//				DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS | DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
//	
//	namedWindow("Multi-scale SIFT Matches");
//	imshow("Multi-scale SIFT Matches", matchImage);
//
//	waitKey();
//	return 0;
//}