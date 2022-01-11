//#include <iostream>
//#include <vector>
//#include <opencv2/core.hpp>
//#include <opencv2/imgproc.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/features2d.hpp>
//#include <opencv2/calib3d.hpp>
//#include <opencv2/objdetect.hpp>
//#include <opencv2/xfeatures2d.hpp>
//using namespace cv;
//using namespace std;
//
//int main() {
//	Mat image1 = imread("../../images/church01.jpg");
//	Mat image2= imread("../../images/church03.jpg");
//	if (!image1.data || !image2.data)
//		return 0; 
//
//    // Display the images
//	namedWindow("Right Image");
//	imshow("Right Image",image1);
//	namedWindow("Left Image");
//	imshow("Left Image",image2);
//
//	// vector of keypoints and descriptors
//	std::vector<KeyPoint> keypoints1;
//	std::vector<KeyPoint> keypoints2;
//	Mat descriptors1, descriptors2;
//
//	// Construction of the SIFT feature detector 
//	Ptr<Feature2D> ptrFeature2D = SIFT::create(74);
//
//	// Detection of the SURF features
//	ptrFeature2D->detectAndCompute(image1, noArray(), keypoints1, descriptors1);
//	ptrFeature2D->detectAndCompute(image2, noArray(), keypoints2, descriptors2);
//	
//	// Construction of the matcher 
//	BFMatcher matcher(NORM_L2,true);
//
//	// Match the two image descriptors
//	std::vector<DMatch> matches;
//	matcher.match(descriptors1,descriptors2, matches);
//
//	//// Manually select few Matches  
//	//std::vector<DMatch> selMatches;
//
//	//// make sure to double-check if the selected matches are valid
//	//selMatches.push_back(matches[2]);  
//	//selMatches.push_back(matches[5]);
//	//selMatches.push_back(matches[16]);
//	//selMatches.push_back(matches[19]);
//	//selMatches.push_back(matches[14]);
//	//selMatches.push_back(matches[34]);
//	//selMatches.push_back(matches[29]);
//
//	// Draw the selected matches
//	Mat imageMatches;
//	drawMatches(image1,keypoints1,  // 1st image and its keypoints
//		        image2,keypoints2,  // 2nd image and its keypoints
////				selMatches,			// the selected matches
//				matches,			// the matches
//				imageMatches,		// the image produced
//				Scalar(255,255,255),
//				Scalar(255,255,255),
//				std::vector<char>(),
//				DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS | DrawMatchesFlags::DRAW_RICH_KEYPOINTS
//				); // color of the lines
//	namedWindow("Matches");
//	imshow("Matches",imageMatches);
//
//	waitKey();
//	return 0;
//}