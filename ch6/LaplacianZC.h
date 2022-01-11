#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;

class LaplacianZC {
private:
	//라플라시안
	cv::Mat laplace;
	//라플라시안 커널의 구경 크기
	int aperture;

public:
	LaplacianZC() : aperture(3) {}

	//커널의 구경 크기 설정
	void setAperture(int a) {
		aperture = a;
	}

	//라플라시안을 부동 소수점으로 계산
	cv::Mat computeLaplacian(const cv::Mat & image){
		// 라플라시안 계산
		cv::Laplacian(image, laplace, CV_32F, aperture);
		return laplace;
	}

	//라플라시안 결과를 8비트 영상으로 얻기
	//0은 그레이레벨 128에 대응
	//scale은 제공하지 않으면 최댓값을 명도 255로 조정
	//이 메소드를 호출하기 전에 computreLaplacian를 호출해야 함
	Mat getLaplacianImage(double scale = -1.0) {
		if (scale < 0) {
			double lapmin, lapmax;

			//라플라시안 최솟값과 최댓값 얻기
			minMaxLoc(laplace, &lapmin, &lapmax);

			//라플라시안을 127로 조정
			scale = 127 / std::max(-lapmin, lapmax);
		}

		//그레이레벨 영상
		Mat laplaceImage;
		laplace.convertTo(laplaceImage, CV_8U, scale, 128);
		return laplaceImage;
	}

	Mat getZeroCrossings(Mat laplace) {
		
		//0에서 경계화
		//음수 값은 검은색
		//양수 값은 흰색
		Mat signImage;
		threshold(laplace, signImage, 0, 255, THRESH_BINARY);

		// +/ -영역의 이진 영상을 팽창
		Mat binary;
		signImage.convertTo(binary, CV_8U);

		// +/- 영역의 이진 영상을 팽창
		Mat dilated;
		dilate(binary, dilated, Mat());

		//영교차 외곽선 반환
		return dilated - binary;
	}

};