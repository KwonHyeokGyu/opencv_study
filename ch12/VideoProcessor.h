#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

// 프레임 처리기 인터페이스
class FrameProcessor {

public:
	// 처리 메서드
	virtual void process(cv::Mat& input, cv::Mat& output) = 0;
};

class VideoProcessor {

private:

	// OpenCV 비디오 캡처 객체
	cv::VideoCapture capture;

	// 각 프레임 처리에 필요한 콜백 함수
	void (*process)(cv::Mat&, cv::Mat&);

	// the pointer to the class implementing 
	// the FrameProcessor interface
	FrameProcessor* frameProcessor;
	
	// 처리 콜백 호출 여부를 결정하는 불리언
	bool callIt;

	// 입력 표시창 이름
	std::string windowNameInput;

	// 결과 표시창 이름
	std::string windowNameOutput;

	// 각 프레임 간의 지연
	int delay;

	// 처리한 프레임 번호
	long fnumber;

	// 중지할 프레임 번호
	long frameToStop;

	// 처리 중지
	bool stop;

	// 입력으로 사용하는 영상 파일명의 벡터
	std::vector<std::string> images;

	// 영상 벡터 반복자
	std::vector<std::string>::const_iterator itImg;

	// OpenCV 비디오 작성기 객체
	cv::VideoWriter writer;

	// 결과 파일명
	std::string outputFile;

	// 결과 영상에 대한 현재 첨자
	int currentIndex;
	// 결과 영상 파일의 자릿수
	int digits;
	// 결과 영상의 확장자
	std::string extension;

	// 다음 프레임 얻기
	// 비디오 파일이나 카메라가 될 수 있음
	bool readNextFrame(cv::Mat& frame) {

		if (images.size() == 0)
			return capture.read(frame);
		else {

			if (itImg != images.end()) {

				frame = cv::imread(*itImg);
				itImg++;
				return frame.data != 0;
			}

			return false;
		}
	}

	// 결과 프레임 쓰기 
	// 비디오 파일이나 영상이 될 수 있음
	void writeNextFrame(cv::Mat& frame) {

		if (extension.length()) { // 영상 쓰기

			std::stringstream ss;
			// 결과 파일명 조합
			ss << outputFile << std::setfill('0') << std::setw(digits) << currentIndex++ << extension;
			cv::imwrite(ss.str(), frame);

		}
		else { // 비디오 파일에 쓰기

			writer.write(frame);
		}
	}

public:

	// Constructor setting the default values
	VideoProcessor() : callIt(false), delay(-1),
		fnumber(0), stop(false), digits(0), frameToStop(-1),
		process(0), frameProcessor(0) {}

	// 비디오 파일의 이름 설정
	bool setInput(std::string filename) {
		fnumber = 0;
		
		// VideoCapture 인스턴스와 관련된 자원이 이미 있을 경우
		capture.release();
		images.clear();

		// 비디오 파일 열기
		return capture.open(filename);
	}

	// set the camera ID
	bool setInput(int id) {

		fnumber = 0;
		// In case a resource was already 
		// associated with the VideoCapture instance
		capture.release();
		images.clear();

		// Open the video file
		return capture.open(id);
	}

	// 입력 영상의 벡터 설정
	bool setInput(const std::vector<std::string>& imgs) {

		fnumber = 0;
		
		// VideoCapture 인스턴스와 관련된 자원이 이미 있을 경우
		capture.release();

		// 입력은 이 영상의 벡터가 됨
		images = imgs;
		itImg = images.begin();

		return true;
	}

	// 기본적으로 입력 비디오에 사용되는 동일한 파라미터로
	// 결과 비디오 파일 설정
	bool setOutput(const std::string& filename, int codec = 0, double framerate = 0.0, bool isColor = true) {

		outputFile = filename;
		extension.clear();

		if (framerate == 0.0)
			framerate = getFrameRate(); // 입력과 동일

		char c[4];
		// 입력과 동일한 코덱 사용
		if (codec == 0) {
			codec = getCodec(c);
		}

		// 결과 비디오 열기
		return writer.open(outputFile,		// 파일명
						   codec,			// 사용할 코덱
						   framerate,		// 비디오 프레임률
						   getFrameSize(),	// 프레임 크기
						   isColor);		// 컬러비디오
	}

	// 결과를 일련의 영상 파일로 저장
	// 확장자는 ".jpg", ".bmp" ...이어야 함
	bool setOutput(const std::string& filename,		// 접두사
				   const std::string& ext,			// 영상 파일 확장자
				   int numberOfDigits = 3,			// 자릿수
				   int startIndex = 0) {			// 시작 첨자

		// 자릿수는 양수이어야 함
		if (numberOfDigits < 0)
			return false;

		// 파일명과 공통 확장자
		outputFile = filename;
		extension = ext;

		// 파일 번호 부여 체계에서의 자릿수
		digits = numberOfDigits;
		// 이 첨자에서 번호 부여 시작
		currentIndex = startIndex;

		return true;
	}

	// 각 프레임마다 호출되는 콜백 함수 설정
	void setFrameProcessor(void (*frameProcessingCallback)(cv::Mat&, cv::Mat&)) {

		// invalidate frame processor class instance
		frameProcessor = 0;
		// this is the frame processor function that will be called
		process = frameProcessingCallback;
		callProcess();
	}

	// FrameProcessor 인터페이스를 구현한 클래스의 인스턴스 설정
	void setFrameProcessor(FrameProcessor* frameProcessorPtr) {

		// 콜백 함수 무효화
		process = 0;

		// 호출할 프레임 처리기 인스턴스
		frameProcessor = frameProcessorPtr;
		callProcess();
	}

	// 이 프레임 번호에서 중지
	void stopAtFrameNo(long frame) {

		frameToStop = frame;
	}

	// 호출될 처리 콜백
	void callProcess() {

		callIt = true;
	}

	// 처리 콜백을 호출하지 않음
	void dontCallProcess() {

		callIt = false;
	}

	// 입력 프레임 표시
	void displayInput(std::string wn) {

		windowNameInput = wn;
		cv::namedWindow(windowNameInput);
	}

	// 처리된 프레임 표시
	void displayOutput(std::string wn) {

		windowNameOutput = wn;
		cv::namedWindow(windowNameOutput);
	}

	// do not display the processed frames
	void dontDisplay() {

		cv::destroyWindow(windowNameInput);
		cv::destroyWindow(windowNameOutput);
		windowNameInput.clear();
		windowNameOutput.clear();
	}

	// 각 프레임 간의 지연 설정
	// 0은 각 프레임에서 대기하고,
	// 음수는 지연이 없다는 것을 의미
	void setDelay(int d) {

		delay = d;
	}

	// a count is kept of the processed frames
	long getNumberOfProcessedFrames() {

		return fnumber;
	}

	// return the size of the video frame
	cv::Size getFrameSize() {

		if (images.size() == 0) {

			// get size of from the capture device
			int w = static_cast<int>(capture.get(cv::CAP_PROP_FRAME_WIDTH));
			int h = static_cast<int>(capture.get(cv::CAP_PROP_FRAME_HEIGHT));

			return cv::Size(w, h);

		}
		else { // if input is vector of images

			cv::Mat tmp = cv::imread(images[0]);
			if (!tmp.data) return cv::Size(0, 0);
			else return tmp.size();
		}
	}

	// 다음 프레임의 번호 반환
	long getFrameNumber() {

		if (images.size() == 0) {

			// 캡처 디바이스로부터 정보 얻기
			long f = static_cast<long>(capture.get(cv::CAP_PROP_POS_FRAMES));
			return f;

		}
		else { // if input is vector of images

			return static_cast<long>(itImg - images.begin());
		}
	}

	// return the position in ms
	double getPositionMS() {

		// undefined for vector of images
		if (images.size() != 0) return 0.0;

		double t = capture.get(cv::CAP_PROP_POS_MSEC);
		return t;
	}

	// return the frame rate
	double getFrameRate() {

		// undefined for vector of images
		if (images.size() != 0) return 0;

		double r = capture.get(cv::CAP_PROP_FPS);
		return r;
	}

	// return the number of frames in video
	long getTotalFrameCount() {

		// for vector of images
		if (images.size() != 0) return images.size();

		long t = capture.get(cv::CAP_PROP_FRAME_COUNT);
		return t;
	}

	// get the codec of input video
	int getCodec(char codec[4]) {

		// undefined for vector of images
		if (images.size() != 0) return -1;

		union {
			int value;
			char code[4];
		} returned;

		returned.value = static_cast<int>(capture.get(cv::CAP_PROP_FOURCC));

		codec[0] = returned.code[0];
		codec[1] = returned.code[1];
		codec[2] = returned.code[2];
		codec[3] = returned.code[3];

		return returned.value;
	}

	// go to this frame number
	bool setFrameNumber(long pos) {

		// for vector of images
		if (images.size() != 0) {

			// move to position in vector
			itImg = images.begin() + pos;
			// is it a valid position?
			if (pos < images.size())
				return true;
			else
				return false;

		}
		else { // if input is a capture device

			return capture.set(cv::CAP_PROP_POS_FRAMES, pos);
		}
	}

	// go to this position
	bool setPositionMS(double pos) {

		// not defined in vector of images
		if (images.size() != 0)
			return false;
		else
			return capture.set(cv::CAP_PROP_POS_MSEC, pos);
	}

	// go to this position expressed in fraction of total film length
	bool setRelativePosition(double pos) {

		// for vector of images
		if (images.size() != 0) {

			// move to position in vector
			long posI = static_cast<long>(pos * images.size() + 0.5);
			itImg = images.begin() + posI;
			// is it a valid position?
			if (posI < images.size())
				return true;
			else
				return false;

		}
		else { // if input is a capture device

			return capture.set(cv::CAP_PROP_POS_AVI_RATIO, pos);
		}
	}

	// 처리 중지
	void stopIt() {

		stop = true;
	}

	// 처리를 중지했는가?
	bool isStopped() {

		return stop;
	}

	// 캡쳐 디바이스를 열었는가?
	bool isOpened() {

		return capture.isOpened() || !images.empty();
	}

	// 시퀀스의 프레임을 잡은 후 처리
	void run() {

		// 현재 프레임
		cv::Mat frame;

		// 결과 프레임
		cv::Mat output;

		// 캡처 디바이스를 설정하지 않았다면
		if (!isOpened())
			return;

		stop = false;

		while (!isStopped()) {

			// 다음 프레임이 있으면 읽기
			if (!readNextFrame(frame))
				break;

			// 입력 프레임 표시
			if (windowNameInput.length() != 0)
				cv::imshow(windowNameInput, frame);

			// 처리 함수 호출
			if (callIt) {

				// 프레임 처리
				if (process)
					process(frame, output);
				else if (frameProcessor)
					frameProcessor->process(frame, output);

				// 프레임 번호 증분
				fnumber++;

			}
			else {	// 처리하지 않음
				output = frame;
			}

			// 결과 시퀀스 쓰기
			if (outputFile.length() != 0)
				writeNextFrame(output);

			// 결과 프레임 표시
			if (windowNameOutput.length() != 0)
				cv::imshow(windowNameOutput, output);

			// 지연 도입
			if (delay >= 0 && cv::waitKey(delay) >= 0)
				stopIt();

			// 중지할지 확인
			if (frameToStop >= 0 && getFrameNumber() == frameToStop)
				stopIt();
		}
	}
};