//#include <iostream>
//#include <vector>
//#include <opencv2/core.hpp>
//#include <opencv2/imgproc.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/features2d.hpp>
//#include <opencv2/calib3d.hpp>
//#include <opencv2/xfeatures2d.hpp>
//#include <opencv2/stitching.hpp>
//
//int main()
//{
//	cv::Mat image1 = cv::imread("../../images/parliament1.jpg", 0);
//	cv::Mat image2 = cv::imread("../../images/parliament2.jpg", 0);
//	if (!image1.data || !image2.data)
//		return 0;
//
//	cv::namedWindow("Image 1");
//	cv::imshow("Image 1", image1);
//	cv::namedWindow("Image 2");
//	cv::imshow("Image 2", image2);
//
//	std::vector<cv::KeyPoint> keypoints1;
//	std::vector<cv::KeyPoint> keypoints2;
//	cv::Mat descriptors1, descriptors2;
//
//	cv::Ptr<cv::Feature2D> ptrFeature2D = cv::SIFT::create(74);
//
//	ptrFeature2D->detectAndCompute(image1, cv::noArray(), keypoints1, descriptors1);
//	ptrFeature2D->detectAndCompute(image2, cv::noArray(), keypoints2, descriptors2);
//
//	cv::BFMatcher matcher(cv::NORM_L2, true);
//	
//	std::vector<cv::DMatch> matches;
//	matcher.match(descriptors1, descriptors2, matches);
//
//	cv::Mat imageMatches;
//
//	// 특징점을 Point2f로 변환
//	std::vector<cv::Point2f> points1, points2;
//	for (std::vector<cv::DMatch>::const_iterator it = matches.begin();
//		it != matches.end(); ++it) {
//
//		// Get the position of left keypoints
//		float x = keypoints1[it->queryIdx].pt.x;
//		float y = keypoints1[it->queryIdx].pt.y;
//		points1.push_back(cv::Point2f(x, y));
//		// Get the position of right keypoints
//		x = keypoints2[it->trainIdx].pt.x;
//		y = keypoints2[it->trainIdx].pt.y;
//		points2.push_back(cv::Point2f(x, y));
//	}
//
//	std::cout << points1.size() << " " << points2.size() << std::endl;
//
//	// 영상 1과 영상 2 간의 호모그래피 찾기
//	std::vector<char> inliers;
//	cv::Mat homography = cv::findHomography(
//		points1, points2, // 대응점
//		inliers,	     // 결과인 정상치 대입
//		cv::RANSAC,	     // RANSAC 방법
//		1.);	         // 재투영점까지의 최대 거리
//
//	cv::drawMatches(image1, keypoints1, image2, keypoints2, matches, imageMatches,		
//		cv::Scalar(255, 255, 255), cv::Scalar(255, 255, 255), inliers, 
//		cv::DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS | cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
//	
//	cv::namedWindow("Homography inlier points");
//	cv::imshow("Homography inlier points", imageMatches);
//
//	cv::waitKey();
//	return 0;
//}