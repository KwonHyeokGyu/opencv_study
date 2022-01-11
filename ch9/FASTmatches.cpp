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
//	// Ư¡ ����� ����
//	Ptr<FeatureDetector> ptrDetector; // ���ʸ� �����
//
//	// FAST ����� ����
//	ptrDetector = FastFeatureDetector::create(80);
//
//	// Ư¡�� ����
//	ptrDetector->detect(image1, keypoints1);
//	ptrDetector->detect(image2, keypoints2);
//
//	// �簢�� �̿��� ����
//	const int nsize(11);
//	Rect neighborhood(0, 0, nsize, nsize); // 11*11
//	Mat patch1;
//	Mat patch2;
//
//	// ù ��° ������ ��� Ư¡������
//	// �� ��° ���󿡼� ���� ����(best match)�� ã��
//	Mat result;
//	std::vector<DMatch> matches;
//
//	// ���� 1�� ��� Ư¡�� ���
//	for (int i = 0; i < keypoints1.size(); i++) {
//		// ���� ��ġ ����
//		neighborhood.x = keypoints1[i].pt.x - nsize / 2;
//		neighborhood.y = keypoints1[i].pt.y - nsize / 2;
//
//		// ���� �̿��� ���� �ٱ��� �ִٸ�,
//		// ���� ������ ��� ����
//		if (neighborhood.x < 0 || neighborhood.y < 0 ||
//			neighborhood.x + nsize >= image1.cols ||
//			neighborhood.y + nsize >= image1.rows)
//			continue;
//
//		// ���� 1�� ��ġ
//		patch1 = image1(neighborhood);
//
//		// ���� ������� �� �缳��
//		DMatch bestMatch;
//
//		// ���� 2�� ��� Ư¡�� ���
//		for (int j = 0; j < keypoints2.size(); j++) {
//			// ���� ��ġ ����
//			neighborhood.x = keypoints2[j].pt.x - nsize / 2;
//			neighborhood.y = keypoints2[j].pt.y - nsize / 2;
//
//			// ���� �̿��� ���� �ٱ��� �ִٸ�,
//			// ���� ������ ��� ����
//			if (neighborhood.x < 0 || neighborhood.y < 0 ||
//				neighborhood.x + nsize >= image2.cols ||
//				neighborhood.y + nsize >= image2.rows)
//				continue;
//
//			// ���� 2�� ��ġ
//			patch2 = image2(neighborhood);
//
//			// �� ��ġ ����
//			matchTemplate(patch1, patch2, result, TM_SQDIFF_NORMED);
//
//			// ���� �������� Ȯ��
//			if (result.at<float>(0, 0) < bestMatch.distance) {
//				bestMatch.distance = result.at<float>(0, 0);
//				bestMatch.queryIdx = i;
//				bestMatch.trainIdx = j;
//			}
//		}
//
//		// ���� ���� �߰�
//		matches.push_back(bestMatch);
//	}
//
//	// 25���� ���� ���� ����
//	std::nth_element(matches.begin(), matches.begin() + 25, matches.end());
//	matches.erase(matches.begin() + 25, matches.end());
//
//	// ���� ��� �׸���
//	Mat matchImage;
//	drawMatches(image1, keypoints1,		// ù ��° ����
//				image2, keypoints2,		// �� ��° ����
//				matches,				// ���� ����
//				matchImage,
//				Scalar(255, 255, 255),	// �� �÷�
//				Scalar(255, 255, 255));	// �� �÷�
//
//	namedWindow("Matches");
//	imshow("Matches", matchImage);
//
//	waitKey();
//	return 0;
//}
