#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
#include "Stereo.h"

using namespace cv;
using namespace std;

int main() {
	Mat image1 = imread("../../images/brebeuf1.jpg");
	Mat image2 = imread("../../images/brebeuf2.jpg");

	if (!image1.data || !image2.data)
		return 0;

	// Prepare the matcher (with default parameters)
	// here SIFT detector and descriptor
	RobustMatcher rmatcher(SIFT::create(250));

	// Match the two images
	vector<DMatch> matches;

	vector<KeyPoint> keypoints1, keypoints2;
	Mat fundamental = rmatcher.match(image1, image2, matches,
		keypoints1, keypoints2);

	// draw the matches
	Mat imageMatches;
	drawMatches(image1, keypoints1,  // 1st image and its keypoints
		image2, keypoints2,  // 2nd image and its keypoints
		matches,			// the matches
		imageMatches,		// the image produced
		Scalar(255, 255, 255),  // color of the lines
		Scalar(255, 255, 255),  // color of the keypoints
		vector<char>(),
		DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS | DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
	namedWindow("Matches");
	imshow("Matches", imageMatches);

	// Convert keypoints into Point2f	
	vector<Point2f> points1, points2;

	for (vector<DMatch>::const_iterator it = matches.begin();
		it != matches.end(); ++it) {

		// Get the position of left keypoints
		float x = keypoints1[it->queryIdx].pt.x;
		float y = keypoints1[it->queryIdx].pt.y;
		points1.push_back(keypoints1[it->queryIdx].pt);
		// Get the position of right keypoints
		x = keypoints2[it->trainIdx].pt.x;
		y = keypoints2[it->trainIdx].pt.y;
		points2.push_back(keypoints2[it->trainIdx].pt);
	}

	// Compute homographic rectification
	Mat h1, h2;
	stereoRectifyUncalibrated(points1, points2, fundamental, image1.size(), h1, h2);

	// Rectify the images through warping
	Mat rectified1;
	warpPerspective(image1, rectified1, h1, image1.size());
	Mat rectified2;
	warpPerspective(image2, rectified2, h2, image1.size());
	// Display the images
	namedWindow("Left Rectified Image");
	imshow("Left Rectified Image", rectified1);
	namedWindow("Right Rectified Image");
	imshow("Right Rectified Image", rectified2);

	points1.clear();
	points2.clear();
	for (int i = 20; i < image1.rows - 20; i += 20) {

		points1.push_back(Point(image1.cols / 2, i));
		points2.push_back(Point(image2.cols / 2, i));
	}

	// Draw the epipolar lines
	vector<Vec3f> lines1;
	computeCorrespondEpilines(points1, 1, fundamental, lines1);

	for (vector<Vec3f>::const_iterator it = lines1.begin();
		it != lines1.end(); ++it) {

		line(image2, Point(0, -(*it)[2] / (*it)[1]),
			Point(image2.cols, -((*it)[2] + (*it)[0] * image2.cols) / (*it)[1]),
			Scalar(255, 255, 255));
	}

	vector<Vec3f> lines2;
	computeCorrespondEpilines(points2, 2, fundamental, lines2);

	for (vector<Vec3f>::const_iterator it = lines2.begin();
		it != lines2.end(); ++it) {

		line(image1, Point(0, -(*it)[2] / (*it)[1]),
			Point(image1.cols, -((*it)[2] + (*it)[0] * image1.cols) / (*it)[1]),
			Scalar(255, 255, 255));
	}

	// Display the images with epipolar lines
	namedWindow("Left Epilines");
	imshow("Left Epilines", image1);
	namedWindow("Right Epilines");
	imshow("Right Epilines", image2);

	// draw the pair
	drawMatches(image1, keypoints1,  // 1st image 
		image2, keypoints2,              // 2nd image 
		vector<DMatch>(),
		imageMatches,		             // the image produced
		Scalar(255, 255, 255),
		Scalar(255, 255, 255),
		vector<char>(),
		DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS | DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
	namedWindow("A Stereo pair");
	imshow("A Stereo pair", imageMatches);

	// Compute disparity
	Mat disparity;
	Ptr<StereoMatcher> pStereo = StereoSGBM::create(0,   // minimum disparity
		32,  // maximum disparity
		5);  // block size
	pStereo->compute(rectified1, rectified2, disparity);

	// draw the rectified pair
	/*
	warpPerspective(image1, rectified1, h1, image1.size());
	warpPerspective(image2, rectified2, h2, image1.size());
	drawMatches(rectified1, keypoints1,  // 1st image
		rectified2, keypoints2,              // 2nd image
		vector<DMatch>(),
		imageMatches,		                // the image produced
		Scalar(255, 255, 255),
		Scalar(255, 255, 255),
		vector<char>(),
		2);
	namedWindow("Rectified Stereo pair");
	imshow("Rectified Stereo pair", imageMatches);
	*/

	double minv, maxv;
	disparity = disparity * 64;
	minMaxLoc(disparity, &minv, &maxv);
	cout << minv << "+" << maxv << endl;
	// Display the disparity map
	namedWindow("Disparity Map");
	imshow("Disparity Map", disparity);

	/*namedWindow("");
	imshow("", );*/

	waitKey();
	return 0;
}
