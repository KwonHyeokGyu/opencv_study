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
//	Mat image1 = imread("C:/Users/lge/Desktop/OpenCV/images/church01.jpg");
//	Mat image2 = imread("C:/Users/lge/Desktop/OpenCV/images/church02.jpg");
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
//	// 특징 검출기 정의
//	Ptr<FeatureDetector> ptrDetector; // 제너릭 검출기
//
//	// FAST 검출기 선택
//	ptrDetector = FastFeatureDetector::create(80);
//
//	// 특징점 검출
//	ptrDetector->detect(image1, keypoints1);
//	ptrDetector->detect(image2, keypoints2);
//
//	// 사각형 이웃의 정의
//	const int nsize(11);
//	Rect neighborhood(0, 0, nsize, nsize); // 11*11
//	Mat patch1;
//	Mat patch2;
//
//	// 첫 번째 영상의 모든 특징점마다
//	// 두 번째 영상에서 최적 정합(best match)을 찾음
//	Mat result;
//	std::vector<DMatch> matches;
//
//	// 영상 1의 모든 특징점 대상
//	for (int i = 0; i < keypoints1.size(); i++) {
//		// 영상 패치 정의
//		neighborhood.x = keypoints1[i].pt.x - nsize / 2;
//		neighborhood.y = keypoints1[i].pt.y - nsize / 2;
//
//		// 점의 이웃이 영상 바깥에 있다면,
//		// 다음 점으로 계속 진행
//		if (neighborhood.x < 0 || neighborhood.y < 0 ||
//			neighborhood.x + nsize >= image1.cols ||
//			neighborhood.y + nsize >= image1.rows)
//			continue;
//
//		// 영상 1의 배치
//		patch1 = image1(neighborhood);
//
//		// 최적 상관관계 값 재설정
//		DMatch bestMatch;
//
//		// 영상 2의 모든 특징점 대상
//		for (int j = 0; j < keypoints2.size(); j++) {
//			// 영상 패치 정의
//			neighborhood.x = keypoints2[j].pt.x - nsize / 2;
//			neighborhood.y = keypoints2[j].pt.y - nsize / 2;
//
//			// 점의 이웃이 영상 바깥에 있다면,
//			// 다음 점으로 계속 진행
//			if (neighborhood.x < 0 || neighborhood.y < 0 ||
//				neighborhood.x + nsize >= image2.cols ||
//				neighborhood.y + nsize >= image2.rows)
//				continue;
//
//			// 영상 2의 패치
//			patch2 = image2(neighborhood);
//
//			// 두 패치 정합
//			matchTemplate(patch1, patch2, result, TM_SQDIFF_NORMED);
//
//			// 최적 정합인지 확인
//			if (result.at<float>(0, 0) < bestMatch.distance) {
//				bestMatch.distance = result.at<float>(0, 0);
//				bestMatch.queryIdx = i;
//				bestMatch.trainIdx = j;
//			}
//		}
//
//		// 최적 정합 추가
//		matches.push_back(bestMatch);
//	}
//
//	// 25개의 최적 정합 추출
//	std::nth_element(matches.begin(), matches.begin() + 25, matches.end());
//	matches.erase(matches.begin() + 25, matches.end());
//
//	// 정합 결과 그리기
//	Mat matchImage;
//	drawMatches(image1, keypoints1,		// 첫 번째 영상
//				image2, keypoints2,		// 두 번째 영상
//				matches,				// 정합 벡터
//				matchImage,
//				Scalar(255, 255, 255),	// 선 컬러
//				Scalar(255, 255, 255));	// 점 컬러
//
//	namedWindow("Matches");
//	imshow("Matches", matchImage);
//
//	waitKey();
//	return 0;
//}
