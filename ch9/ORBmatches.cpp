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
//	// 특징점 검출기/기술자 정의
//	// ORB 특징 검출기 객체 생성
//	// 약 60개의 특징점 검출
//	Ptr<Feature2D> feature = ORB::create(60);
//
//	// 기술자 추출
//	Mat descriptors1;
//	Mat descriptors2;
//	
//	// 특징점 검출과 기술
//	// ORB 특징 검출
//	feature->detectAndCompute(image1, noArray(), keypoints1, descriptors1);
//	feature->detectAndCompute(image2, noArray(), keypoints2, descriptors2);
//
//	// 정합기(matcher)생성
//	BFMatcher matcher(NORM_HAMMING);
//
//	// 이진 기술자의경우 두 영상 기술자 정함
//	std::vector<DMatch> matches;
//	matcher.match(descriptors1, descriptors2, matches);
//
//	Mat matchImage;
//	
//	drawMatches(image1, keypoints1,		// 첫 번째 영상
//				image2, keypoints2,		// 두 번째 영상
//				matches,				// 정합 벡터
//				matchImage,
//				Scalar(255, 255, 255),	// 선 컬러
//				Scalar(255, 255, 255),	// 점 컬러
//				std::vector< char >(),      // masks if any 
//				DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS | DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
//	namedWindow("ORB Matches");
//	imshow("ORB Matches", matchImage);
//
//	waitKey();
//	return 0;
//}