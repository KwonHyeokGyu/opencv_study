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

	// Ư¡ ����� ����
	Ptr<Feature2D> ptrFeature2D = xfeatures2d::SURF::create(2000.0);

	// Ư¡�� ����
	ptrFeature2D->detect(image1, keypoints1);
	ptrFeature2D->detect(image2, keypoints2);

	// ����� ����
	Mat descriptors1;
	Mat descriptors2;
	ptrFeature2D->compute(image1, keypoints1, descriptors1);
	ptrFeature2D->compute(image2, keypoints2, descriptors2);

	// ���ձ�(matcher)����
	BFMatcher matcher(NORM_L2);

	// �� ����� ����
	std::vector<DMatch> matches;
	matcher.match(descriptors1, descriptors2, matches);

	// ���� ��� �׸���
	Mat matchImage;
	drawMatches(image1, keypoints1,		// ù ��° ����
				image2, keypoints2,		// �� ��° ����
				matches,				// ���� ����
				matchImage,
				Scalar(255, 255, 255),	// �� �÷�
				Scalar(255, 255, 255),	// �� �÷�
				std::vector< char >(),      // masks if any 
				DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS | DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
	
	namedWindow("SURF Matches");
	imshow("SURF Matches", matchImage);

	BFMatcher matcher2(NORM_L2,	// �Ÿ� ����
						true);	// ���� Ȯ�� �÷���

	// �� ����� ����
	matcher2.match(descriptors1, descriptors2, matches);

	// ���� ��� �׸���
	drawMatches(image1, keypoints1,		// ù ��° ����
				image2, keypoints2,		// �� ��° ����
				matches,				// ���� ����
				matchImage,
				Scalar(255, 255, 255),	// �� �÷�
				Scalar(255, 255, 255),	// �� �÷�
				std::vector< char >(),      // masks if any 
				DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS | DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
	
	namedWindow("SURF Matches (width crosscheck)");
	imshow("SURF Matches (width crosscheck)", matchImage);

	// �� Ư¡���� ���� �� ���� ã��
	std::vector<std::vector<DMatch>> matches2;
	matcher.knnMatch(descriptors1, descriptors2, matches2, 2);	// k ���� ���� ã��
	matches.clear();

	// �������� ����
	double ratio = 0.85;
	std::vector<std::vector<DMatch>>::iterator it;

	for (it = matches2.begin(); it != matches2.end(); ++it) {
		// ù ��° ���� ���հ� �� ��° ���� ����
		if ((*it)[0].distance / (*it)[1].distance < ratio) {
			// �̴� �޾Ƶ��� �� �ִ� ������
			matches.push_back((*it)[0]);
		}
	}

	drawMatches(image1, keypoints1,		// ù ��° ����
				image2, keypoints2,		// �� ��° ����
				matches,				// ���� ����
				matchImage,
				Scalar(255, 255, 255),	// �� �÷�
				Scalar(255, 255, 255),	// �� �÷�
				std::vector< char >(),      // masks if any 
				DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS | DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
	
	namedWindow("SURF Matches (ratio check)");
	imshow("SURF Matches (ratio check)", matchImage);

	//������ ����(radius match)
	float maxDist = 0.4;
	matches2.clear();

	matcher.radiusMatch(descriptors1, descriptors2, matches2, maxDist);

	cv::drawMatches(image1, keypoints1,		// ù ��° ����
		image2, keypoints2,		// �� ��° ����
		matches,				// ���� ����
		matchImage,
		Scalar(255, 255, 255),	// �� �÷�
		Scalar(255, 255, 255),	// �� �÷�
		std::vector< char >(),      // masks if any 
		DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS | DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
	
	namedWindow("SURF Matches (with max radius)");
	imshow("SURF Matches (with max radius)", matchImage);

	waitKey();
	return 0;
}
