//#include <iostream>
//#include <vector>
//#include <opencv2/core.hpp>
//#include <opencv2/imgproc.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/features2d.hpp>
//#include <opencv2/objdetect.hpp>
//#include <opencv2/xfeatures2d.hpp>
//using namespace cv;
//
//int main()
//{
//	// image matching
//
//	// 1. Read input images
//	Mat image1 = imread("../../images/church01.jpg");
//	Mat image2 = imread("../../images/church02.jpg");
//
//	// 2. Define keypoint vectors and descriptors
//	std::vector<KeyPoint> keypoints1;
//	std::vector<KeyPoint> keypoints2;
//	Mat descriptors1;
//	Mat descriptors2;
//	Mat descriptors3;
//	Mat descriptors4;
//
//	// 3. Define feature detector/descriptor
//	// Construct the ORB feature object
//	Ptr<Feature2D> feature = BRISK::create(80);
//	
//	//for (size_t i = 0; i < keypoints1.size(); ++i) {
//	//	std::cout << keypoints1.at(i) << "; " << "dddddd" << std::endl;
//	//}
//	std::cout << descriptors1.rows << std::endl;
//	
//	feature->detectAndCompute(image1, noArray(), keypoints1, descriptors3);
//	feature->detectAndCompute(image2, noArray(), keypoints2, descriptors4);
//	
//
//	////Mat featureImage;
//	////drawKeypoints(image1, keypoints1, featureImage, Scalar(255, 255, 255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
//
//	//// to describe with FREAK (use with BRISK)
//	feature = xfeatures2d::FREAK::create();
//	feature->compute(image1, keypoints1, descriptors1);
//	feature->compute(image1, keypoints2, descriptors2);
//
//   // Construction of the matcher 
//	BFMatcher matcher(
//		NORM_HAMMING); // always use hamming norm
//						   // for binary descriptors
//	// Match the two image descriptors
//	std::vector<DMatch> matches;
//	matcher.match(descriptors1, descriptors2, matches);
//
//	// draw matches
//	Mat imageMatches;
//	drawMatches(
//		image1, keypoints1, // 1st image and its keypoints
//		image2, keypoints2, // 2nd image and its keypoints
//		matches,           // the matches
//		imageMatches,      // the image produced
//		Scalar(255, 255, 255),  // color of lines
//		Scalar(255, 255, 255),  // color of points
//		std::vector< char >(),    // masks if any 
//		DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS | DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
//
//	namedWindow("FREAK Matches");
//	imshow("FREAK Matches", imageMatches);
//
//	waitKey();
//	return 0;
//}