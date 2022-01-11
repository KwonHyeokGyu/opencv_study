//#include <iostream>
//#include <vector>
//#include <opencv2/core/core.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/highgui/highgui.hpp>
//using namespace cv;
//
//class HarrisDetector {
//private:
//	// 코너 강도의 32비트 부동소수점 영상
//	Mat cornerStrength;
//	// 경계화된 코너의 32비트 부동소수점 영상
//	Mat cornerTh;
//	// 지역 최대치 영상(내부)
//	Mat localMax;
//	// 미분 스무딩을 위한 이웃 크기
//	int neighbourhood;
//	// 기울기 계산을 위한 직경
//	int aperture;
//	// 해리스 파라미터
//	double k;
//	// 경계 값 계산을 위한 최대 강도
//	double maxStrength;
//	// 계산된 경계값
//	double threshold;
//	// 비최대치 억제(non-maxima suppression)를 위한 이웃 크기
//	int nonMaxSize;
//	// 비최대치 억제를 위한 커널
//	Mat kernel;
//
//public:
//	HarrisDetector() : neighbourhood(3), aperture(3),
//		k(0.01), maxStrength(0.0),
//		threshold(0.001), nonMaxSize(3) {
//
//		// 비 최대치 억제에 사용하는 커널 생성
//		setLocalMaxWindowSize(nonMaxSize);
//	}
//
//	// Create kernel used in non-maxima suppression
//	void setLocalMaxWindowSize(int size) {
//		nonMaxSize = size;
//		kernel.create(nonMaxSize, nonMaxSize, CV_8U);
//	}
//
//	// 해리스 코너 계산
//	void detect(const Mat& image) {
//
//		// 해리스 계산
//		cornerHarris(image, cornerStrength, neighbourhood, aperture, k);
//
//		// 내부 경계 값 계산
//		minMaxLoc(cornerStrength, 0, &maxStrength);
//
//		// 지역 최대치 검출
//		Mat dilated;
//		dilate(cornerStrength, dilated, Mat());
//		compare(cornerStrength, dilated, localMax, CMP_EQ);
//	}
//
//	// 계산한 해리스 값으로부터 코너 맵 얻기
//	Mat getCornerMap(double qualityLevel) {
//
//		Mat cornerMap;
//
//		// 코너 강도를 경계화
//		threshold = qualityLevel * maxStrength;
//		cv::threshold(cornerStrength, cornerTh, threshold,
//			233, THRESH_BINARY);
//
//		// 8비트 영상으로 변환
//		cornerTh.convertTo(cornerMap, CV_8U);
//
//		// 비최대치 억제
//		bitwise_and(cornerMap, localMax, cornerMap);
//
//		return cornerMap;
//
//	}
//
//	void getCorners(std::vector<Point>& points,
//		double qualityLevel) {
//
//		// 코너 맵 얻기
//		Mat cornerMap = getCornerMap(qualityLevel);
//
//		//코너 얻기
//		getCorners(points, cornerMap);
//	}
//
//	// 계산한 코너 맵으로부터 특징점 얻기
//	void getCorners(std::vector<Point>& points,
//		const Mat& cornerMap) {
//		// 모든 특징점을 얻기 위해 화소 순회
//		for (int y = 0; y < cornerMap.rows; y++) {
//			const uchar* rowPtr = cornerMap.ptr<uchar>(y);
//			for (int x = 0; x < cornerMap.cols; x++) {
//				// 특징점이면
//				if (rowPtr[x]) {
//					points.push_back(Point(x, y));
//				}
//			}
//		}
//	}
//
//	// 특징점 위치에서 영상에 원 그리기
//	void drawOnImage(Mat& image,
//		const std::vector<Point>& points,
//		Scalar color = Scalar(255, 255, 255),
//		int radius = 3, int thickness = 1) {
//		std::vector<Point>::const_iterator it = points.begin();
//
//		// 모든 코너에 대해
//		while (it != points.end()) {
//			// 각 코너 위치에서 원 그리기
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
//	// 해리스 검출기 인스턴스 생성
//	HarrisDetector harris;
//
//	// 해리스 값 계산
//	harris.detect(src);
//
//	// 해리스 코너 검출
//	std::vector<Point> pts;
//	harris.getCorners(pts, 0.02);
//
//	// 해리스 코너 그리기
//	harris.drawOnImage(src, pts);
//
//
//	namedWindow("Corners");
//	imshow("Corners", src);
//
//	waitKey();
//	return 0;
//}