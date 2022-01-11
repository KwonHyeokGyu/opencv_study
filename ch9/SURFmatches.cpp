#include <iostream>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/objdetect.hpp>
using namespace cv;

int main()
{
	Mat image1 = imread("C:/Users/lge/Desktop/OpenCV/images/church01.jpg");
	Mat image2 = imread("C:/Users/lge/Desktop/OpenCV/images/church02.jpg");

	std::vector<KeyPoint> keypoints1;
	std::vector<KeyPoint> keypoints2;

	namedWindow("image1");
	imshow("image1", image1);

	namedWindow("image2");
	imshow("image2", image2);

	// 특징 검출기 정의
	Ptr<Feature2D> ptrFeature2D = xfeatures2d::SURF::create(2000.0);

	// 특징점 검출
	ptrFeature2D->detect(image1, keypoints1);
	ptrFeature2D->detect(image2, keypoints2);

	// 기술자 추출
	Mat descriptors1;
	Mat descriptors2;
	ptrFeature2D->compute(image1, keypoints1, descriptors1);
	ptrFeature2D->compute(image2, keypoints2, descriptors2);

	// 정합기(matcher)생성
	BFMatcher matcher(NORM_L2);

	// 두 기술자 정합
	std::vector<DMatch> matches;
	matcher.match(descriptors1, descriptors2, matches);

	// 정합 결과 그리기
	Mat matchImage;
	drawMatches(image1, keypoints1,		// 첫 번째 영상
				image2, keypoints2,		// 두 번째 영상
				matches,				// 정합 벡터
				matchImage,
				Scalar(255, 255, 255),	// 선 컬러
				Scalar(255, 255, 255),	// 점 컬러
				std::vector< char >(),      // masks if any 
				DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS | DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
	
	namedWindow("SURF Matches");
	imshow("SURF Matches", matchImage);

	BFMatcher matcher2(NORM_L2,	// 거리 측정
						true);	// 교차 확인 플래그

	// 두 기술자 정합
	matcher2.match(descriptors1, descriptors2, matches);

	// 정합 결과 그리기
	drawMatches(image1, keypoints1,		// 첫 번째 영상
				image2, keypoints2,		// 두 번째 영상
				matches,				// 정합 벡터
				matchImage,
				Scalar(255, 255, 255),	// 선 컬러
				Scalar(255, 255, 255),	// 점 컬러
				std::vector< char >(),      // masks if any 
				DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS | DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
	
	namedWindow("SURF Matches (width crosscheck)");
	imshow("SURF Matches (width crosscheck)", matchImage);

	// 각 특징점의 최적 두 정합 찾기
	std::vector<std::vector<DMatch>> matches2;
	matcher.knnMatch(descriptors1, descriptors2, matches2, 2);	// k 최적 정합 찾기
	matches.clear();

	// 비판정법 수행
	double ratio = 0.85;
	std::vector<std::vector<DMatch>>::iterator it;

	for (it = matches2.begin(); it != matches2.end(); ++it) {
		// 첫 번째 최적 정합과 두 번째 최적 정합
		if ((*it)[0].distance / (*it)[1].distance < ratio) {
			// 이는 받아들일 수 있는 정합임
			matches.push_back((*it)[0]);
		}
	}

	drawMatches(image1, keypoints1,		// 첫 번째 영상
				image2, keypoints2,		// 두 번째 영상
				matches,				// 정합 벡터
				matchImage,
				Scalar(255, 255, 255),	// 선 컬러
				Scalar(255, 255, 255),	// 점 컬러
				std::vector< char >(),      // masks if any 
				DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS | DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
	
	namedWindow("SURF Matches (ratio check)");
	imshow("SURF Matches (ratio check)", matchImage);

	//반지름 정합(radius match)
	float maxDist = 0.4;
	matches2.clear();

	matcher.radiusMatch(descriptors1, descriptors2, matches2, maxDist);

	cv::drawMatches(image1, keypoints1,		// 첫 번째 영상
		image2, keypoints2,		// 두 번째 영상
		matches,				// 정합 벡터
		matchImage,
		Scalar(255, 255, 255),	// 선 컬러
		Scalar(255, 255, 255),	// 점 컬러
		std::vector< char >(),      // masks if any 
		DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS | DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
	
	namedWindow("SURF Matches (with max radius)");
	imshow("SURF Matches (with max radius)", matchImage);

	waitKey();
	return 0;
}
