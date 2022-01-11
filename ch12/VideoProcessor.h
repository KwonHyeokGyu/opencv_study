#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

// ������ ó���� �������̽�
class FrameProcessor {

public:
	// ó�� �޼���
	virtual void process(cv::Mat& input, cv::Mat& output) = 0;
};

class VideoProcessor {

private:

	// OpenCV ���� ĸó ��ü
	cv::VideoCapture capture;

	// �� ������ ó���� �ʿ��� �ݹ� �Լ�
	void (*process)(cv::Mat&, cv::Mat&);

	// the pointer to the class implementing 
	// the FrameProcessor interface
	FrameProcessor* frameProcessor;
	
	// ó�� �ݹ� ȣ�� ���θ� �����ϴ� �Ҹ���
	bool callIt;

	// �Է� ǥ��â �̸�
	std::string windowNameInput;

	// ��� ǥ��â �̸�
	std::string windowNameOutput;

	// �� ������ ���� ����
	int delay;

	// ó���� ������ ��ȣ
	long fnumber;

	// ������ ������ ��ȣ
	long frameToStop;

	// ó�� ����
	bool stop;

	// �Է����� ����ϴ� ���� ���ϸ��� ����
	std::vector<std::string> images;

	// ���� ���� �ݺ���
	std::vector<std::string>::const_iterator itImg;

	// OpenCV ���� �ۼ��� ��ü
	cv::VideoWriter writer;

	// ��� ���ϸ�
	std::string outputFile;

	// ��� ���� ���� ���� ÷��
	int currentIndex;
	// ��� ���� ������ �ڸ���
	int digits;
	// ��� ������ Ȯ����
	std::string extension;

	// ���� ������ ���
	// ���� �����̳� ī�޶� �� �� ����
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

	// ��� ������ ���� 
	// ���� �����̳� ������ �� �� ����
	void writeNextFrame(cv::Mat& frame) {

		if (extension.length()) { // ���� ����

			std::stringstream ss;
			// ��� ���ϸ� ����
			ss << outputFile << std::setfill('0') << std::setw(digits) << currentIndex++ << extension;
			cv::imwrite(ss.str(), frame);

		}
		else { // ���� ���Ͽ� ����

			writer.write(frame);
		}
	}

public:

	// Constructor setting the default values
	VideoProcessor() : callIt(false), delay(-1),
		fnumber(0), stop(false), digits(0), frameToStop(-1),
		process(0), frameProcessor(0) {}

	// ���� ������ �̸� ����
	bool setInput(std::string filename) {
		fnumber = 0;
		
		// VideoCapture �ν��Ͻ��� ���õ� �ڿ��� �̹� ���� ���
		capture.release();
		images.clear();

		// ���� ���� ����
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

	// �Է� ������ ���� ����
	bool setInput(const std::vector<std::string>& imgs) {

		fnumber = 0;
		
		// VideoCapture �ν��Ͻ��� ���õ� �ڿ��� �̹� ���� ���
		capture.release();

		// �Է��� �� ������ ���Ͱ� ��
		images = imgs;
		itImg = images.begin();

		return true;
	}

	// �⺻������ �Է� ������ ���Ǵ� ������ �Ķ���ͷ�
	// ��� ���� ���� ����
	bool setOutput(const std::string& filename, int codec = 0, double framerate = 0.0, bool isColor = true) {

		outputFile = filename;
		extension.clear();

		if (framerate == 0.0)
			framerate = getFrameRate(); // �Է°� ����

		char c[4];
		// �Է°� ������ �ڵ� ���
		if (codec == 0) {
			codec = getCodec(c);
		}

		// ��� ���� ����
		return writer.open(outputFile,		// ���ϸ�
						   codec,			// ����� �ڵ�
						   framerate,		// ���� �����ӷ�
						   getFrameSize(),	// ������ ũ��
						   isColor);		// �÷�����
	}

	// ����� �Ϸ��� ���� ���Ϸ� ����
	// Ȯ���ڴ� ".jpg", ".bmp" ...�̾�� ��
	bool setOutput(const std::string& filename,		// ���λ�
				   const std::string& ext,			// ���� ���� Ȯ����
				   int numberOfDigits = 3,			// �ڸ���
				   int startIndex = 0) {			// ���� ÷��

		// �ڸ����� ����̾�� ��
		if (numberOfDigits < 0)
			return false;

		// ���ϸ�� ���� Ȯ����
		outputFile = filename;
		extension = ext;

		// ���� ��ȣ �ο� ü�迡���� �ڸ���
		digits = numberOfDigits;
		// �� ÷�ڿ��� ��ȣ �ο� ����
		currentIndex = startIndex;

		return true;
	}

	// �� �����Ӹ��� ȣ��Ǵ� �ݹ� �Լ� ����
	void setFrameProcessor(void (*frameProcessingCallback)(cv::Mat&, cv::Mat&)) {

		// invalidate frame processor class instance
		frameProcessor = 0;
		// this is the frame processor function that will be called
		process = frameProcessingCallback;
		callProcess();
	}

	// FrameProcessor �������̽��� ������ Ŭ������ �ν��Ͻ� ����
	void setFrameProcessor(FrameProcessor* frameProcessorPtr) {

		// �ݹ� �Լ� ��ȿȭ
		process = 0;

		// ȣ���� ������ ó���� �ν��Ͻ�
		frameProcessor = frameProcessorPtr;
		callProcess();
	}

	// �� ������ ��ȣ���� ����
	void stopAtFrameNo(long frame) {

		frameToStop = frame;
	}

	// ȣ��� ó�� �ݹ�
	void callProcess() {

		callIt = true;
	}

	// ó�� �ݹ��� ȣ������ ����
	void dontCallProcess() {

		callIt = false;
	}

	// �Է� ������ ǥ��
	void displayInput(std::string wn) {

		windowNameInput = wn;
		cv::namedWindow(windowNameInput);
	}

	// ó���� ������ ǥ��
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

	// �� ������ ���� ���� ����
	// 0�� �� �����ӿ��� ����ϰ�,
	// ������ ������ ���ٴ� ���� �ǹ�
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

	// ���� �������� ��ȣ ��ȯ
	long getFrameNumber() {

		if (images.size() == 0) {

			// ĸó ����̽��κ��� ���� ���
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

	// ó�� ����
	void stopIt() {

		stop = true;
	}

	// ó���� �����ߴ°�?
	bool isStopped() {

		return stop;
	}

	// ĸ�� ����̽��� �����°�?
	bool isOpened() {

		return capture.isOpened() || !images.empty();
	}

	// �������� �������� ���� �� ó��
	void run() {

		// ���� ������
		cv::Mat frame;

		// ��� ������
		cv::Mat output;

		// ĸó ����̽��� �������� �ʾҴٸ�
		if (!isOpened())
			return;

		stop = false;

		while (!isStopped()) {

			// ���� �������� ������ �б�
			if (!readNextFrame(frame))
				break;

			// �Է� ������ ǥ��
			if (windowNameInput.length() != 0)
				cv::imshow(windowNameInput, frame);

			// ó�� �Լ� ȣ��
			if (callIt) {

				// ������ ó��
				if (process)
					process(frame, output);
				else if (frameProcessor)
					frameProcessor->process(frame, output);

				// ������ ��ȣ ����
				fnumber++;

			}
			else {	// ó������ ����
				output = frame;
			}

			// ��� ������ ����
			if (outputFile.length() != 0)
				writeNextFrame(output);

			// ��� ������ ǥ��
			if (windowNameOutput.length() != 0)
				cv::imshow(windowNameOutput, output);

			// ���� ����
			if (delay >= 0 && cv::waitKey(delay) >= 0)
				stopIt();

			// �������� Ȯ��
			if (frameToStop >= 0 && getFrameNumber() == frameToStop)
				stopIt();
		}
	}
};