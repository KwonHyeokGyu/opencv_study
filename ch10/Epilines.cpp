#include <iostream>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/xfeatures2d.hpp>
using namespace cv;
using namespace std;

int main() {
	Mat image1 = imread("../../images/church01.jpg", 0);
	Mat image2 = imread("../../images/church03.jpg", 0);
	if (!image1.data || !image2.data)
		return 0; 

    namedWindow("Image1");
	imshow("Image1",image1);
	namedWindow("Image2");
	imshow("Image2",image2);

	vector<KeyPoint> keypoints1;
	vector<KeyPoint> keypoints2;
	Mat descriptors1, descriptors2;

	// SIFT 검출기
	Ptr<Feature2D> ptrFeature2D = SIFT::create(74);

	// 특징점 추출
	ptrFeature2D->detectAndCompute(image1, noArray(), keypoints1, descriptors1);
	ptrFeature2D->detectAndCompute(image2, noArray(), keypoints2, descriptors2);
	
	// Construction of the matcher 
	BFMatcher matcher(NORM_L2, true);

	// Match the two image descriptors
	vector<DMatch> matches;
	matcher.match(descriptors1, descriptors2, matches);

	// Manually select few Matches  
	vector<DMatch> selMatches;

	// make sure to double-check if the selected matches are valid
	selMatches.push_back(matches[0]);
	selMatches.push_back(matches[1]);
	selMatches.push_back(matches[5]);
	selMatches.push_back(matches[14]);
	selMatches.push_back(matches[16]);
	selMatches.push_back(matches[18]);
	selMatches.push_back(matches[20]);

	// keypoint를 Point2f로 변환
	vector <int> pointIndexes1, pointIndexes2;
	for (vector<DMatch>::const_iterator it = selMatches.begin();
		it != selMatches.end(); ++it) {

		// Get the indexes of the selected matched keypoints
		pointIndexes1.push_back(it->queryIdx);
		pointIndexes2.push_back(it->trainIdx);
	}

	vector <Point2f> selPoints1, selPoints2;
	KeyPoint::convert(keypoints1, selPoints1, pointIndexes1);
	KeyPoint::convert(keypoints2, selPoints2, pointIndexes2);
	
	// check by drawing the points 
	vector<Point2f>::const_iterator it = selPoints1.begin();
	while (it != selPoints1.end()) {

		// draw a circle at each corner location
		circle(image1, *it, 3, Scalar(255, 255, 255), 2);
		++it;
	}

	it = selPoints2.begin();
	while (it != selPoints2.end()) {

		// draw a circle at each corner location
		circle(image2, *it, 3, Scalar(255, 255, 255), 2);
		++it;
	}

	// 7개 정합으로부터 F 행렬 계산
	Mat fundamental = findFundamentalMat(selPoints1, selPoints2, FM_7POINT);

	Mat fund(fundamental, Rect(0, 0, 3, 3));

	// 오른쪽 영상에서 에피폴라 선에 대응하는 왼쪽 점을 그림
	vector<Vec3f> lines1;
	computeCorrespondEpilines(selPoints1, 1, fund, lines1);

	// 모든 에피폴라 선에 대해
	for (vector<Vec3f>::const_iterator it = lines1.begin(); it != lines1.end(); ++it) {
		// 첫 열과 마지막 열 사이에 선을 그림
		line(image2,
			Point(0, -(*it)[2] / (*it)[1]),
			Point(image2.cols, -((*it)[2] + (*it)[0] * image2.cols) / (*it)[1]),
			Scalar(255, 255, 255));
	}

	// 왼 쪽 영상에서 에피폴라 선에 대응하는 오른쪽 점을 그림
	vector<Vec3f> lines2;
	computeCorrespondEpilines(Mat(selPoints2), 2, fund, lines2);

	// 모든 에피폴라 선에 대해
	for (vector<Vec3f>::const_iterator it = lines2.begin(); it != lines2.end(); ++it) {
		// 첫 열과 마지막 열 사이에 선을 그림
		line(image1,
			Point(0, -(*it)[2] / (*it)[1]),
			Point(image1.cols, -((*it)[2] + (*it)[0] * image1.cols) / (*it)[1]),
			Scalar(255, 255, 255));
	}

	Mat both(image1.rows, image1.cols + image2.cols, CV_8U);
	image1.copyTo(both.colRange(0, image1.cols));
	image2.copyTo(both.colRange(image1.cols, image1.cols + image2.cols));

	namedWindow("Epilines");
	imshow("Epilines", both);

	waitKey();
	return 0;
}