//#include <iostream>
//#include <vector>
//#include <opencv2/core/core.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/highgui/highgui.hpp>
//using namespace cv;
//
//class HarrisDetector {
//private:
//	// �ڳ� ������ 32��Ʈ �ε��Ҽ��� ����
//	Mat cornerStrength;
//	// ���ȭ�� �ڳ��� 32��Ʈ �ε��Ҽ��� ����
//	Mat cornerTh;
//	// ���� �ִ�ġ ����(����)
//	Mat localMax;
//	// �̺� �������� ���� �̿� ũ��
//	int neighbourhood;
//	// ���� ����� ���� ����
//	int aperture;
//	// �ظ��� �Ķ����
//	double k;
//	// ��� �� ����� ���� �ִ� ����
//	double maxStrength;
//	// ���� ��谪
//	double threshold;
//	// ���ִ�ġ ����(non-maxima suppression)�� ���� �̿� ũ��
//	int nonMaxSize;
//	// ���ִ�ġ ������ ���� Ŀ��
//	Mat kernel;
//
//public:
//	HarrisDetector() : neighbourhood(3), aperture(3),
//		k(0.01), maxStrength(0.0),
//		threshold(0.001), nonMaxSize(3) {
//
//		// �� �ִ�ġ ������ ����ϴ� Ŀ�� ����
//		setLocalMaxWindowSize(nonMaxSize);
//	}
//
//	// Create kernel used in non-maxima suppression
//	void setLocalMaxWindowSize(int size) {
//		nonMaxSize = size;
//		kernel.create(nonMaxSize, nonMaxSize, CV_8U);
//	}
//
//	// �ظ��� �ڳ� ���
//	void detect(const Mat& image) {
//
//		// �ظ��� ���
//		cornerHarris(image, cornerStrength, neighbourhood, aperture, k);
//
//		// ���� ��� �� ���
//		minMaxLoc(cornerStrength, 0, &maxStrength);
//
//		// ���� �ִ�ġ ����
//		Mat dilated;
//		dilate(cornerStrength, dilated, Mat());
//		compare(cornerStrength, dilated, localMax, CMP_EQ);
//	}
//
//	// ����� �ظ��� �����κ��� �ڳ� �� ���
//	Mat getCornerMap(double qualityLevel) {
//
//		Mat cornerMap;
//
//		// �ڳ� ������ ���ȭ
//		threshold = qualityLevel * maxStrength;
//		cv::threshold(cornerStrength, cornerTh, threshold,
//			233, THRESH_BINARY);
//
//		// 8��Ʈ �������� ��ȯ
//		cornerTh.convertTo(cornerMap, CV_8U);
//
//		// ���ִ�ġ ����
//		bitwise_and(cornerMap, localMax, cornerMap);
//
//		return cornerMap;
//
//	}
//
//	void getCorners(std::vector<Point>& points,
//		double qualityLevel) {
//
//		// �ڳ� �� ���
//		Mat cornerMap = getCornerMap(qualityLevel);
//
//		//�ڳ� ���
//		getCorners(points, cornerMap);
//	}
//
//	// ����� �ڳ� �����κ��� Ư¡�� ���
//	void getCorners(std::vector<Point>& points,
//		const Mat& cornerMap) {
//		// ��� Ư¡���� ��� ���� ȭ�� ��ȸ
//		for (int y = 0; y < cornerMap.rows; y++) {
//			const uchar* rowPtr = cornerMap.ptr<uchar>(y);
//			for (int x = 0; x < cornerMap.cols; x++) {
//				// Ư¡���̸�
//				if (rowPtr[x]) {
//					points.push_back(Point(x, y));
//				}
//			}
//		}
//	}
//
//	// Ư¡�� ��ġ���� ���� �� �׸���
//	void drawOnImage(Mat& image,
//		const std::vector<Point>& points,
//		Scalar color = Scalar(255, 255, 255),
//		int radius = 3, int thickness = 1) {
//		std::vector<Point>::const_iterator it = points.begin();
//
//		// ��� �ڳʿ� ����
//		while (it != points.end()) {
//			// �� �ڳ� ��ġ���� �� �׸���
//			circle(image, *it, radius, color, thickness);
//			++it;
//		}
//	}
//
//};
//
//int main()
//{
//	Mat src = imread("C:/Users/lge/Desktop/OpenCV/images/church01.jpg", 0);
//	if (!src.data)
//		return 0;
//
//	namedWindow("Original image");
//	imshow("Original image", src);
//
//	// �ظ��� ����� �ν��Ͻ� ����
//	HarrisDetector harris;
//
//	// �ظ��� �� ���
//	harris.detect(src);
//
//	// �ظ��� �ڳ� ����
//	std::vector<Point> pts;
//	harris.getCorners(pts, 0.02);
//
//	// �ظ��� �ڳ� �׸���
//	harris.drawOnImage(src, pts);
//
//
//	namedWindow("Corners");
//	imshow("Corners", src);
//
//	waitKey();
//	return 0;
//}