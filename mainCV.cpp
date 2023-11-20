#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std ; 
using namespace cv ; 

class Camera {
private:
      VideoCapture camera ;

public:
    Camera() {
     
        camera.open(0);

     
        if (!camera.isOpened()) {
            std::cout << "errosr to open camera !!! " << endl;
            exit(-1);
        }
    }

    ~Camera() {
     
        camera.release();
    }

    void displayRGBImage() {
    
          namedWindow("RGB Image", WINDOW_NORMAL);

        while (true) {
            Mat frame, grayscaleFrame;

         
            camera >> frame;
            
           
            imshow("RGB Image", frame);
            cvtColor(frame, grayscaleFrame, COLOR_BGR2GRAY);
            imshow("Grayscale Image", grayscaleFrame);
    
            int key = waitKey(1);

            if (key == 'q')
                break;
        }

         destroyWindow("RGB Image");
    }

    //  //void displayGrayscaleImage() {
    
    //       namedWindow("Grayscale Image", WINDOW_NORMAL);

    //     while (true) {
    //           Mat frame, grayscaleFrame;
              
    //           camera >> frame;

    //           cvtColor(frame, grayscaleFrame, COLOR_BGR2GRAY);

    //           imshow("Grayscale Image", grayscaleFrame);

    //           int key = waitKey(1);

    //         if (key == 'q')
    //             break;
    //     }

    //     destroyWindow("Grayscale Image");
    // }
};

int main() {
    Camera camera;
    // cv::VideoCapture cap(0);
    // cv::Mat frame;
    // while (true) {
    //     cap >> frame;
    //     cv::imshow("s", frame);
    //     if (cv::waitKey(1) == int('q')) {
    //         break;
    //     }
    // }
    camera.displayRGBImage();
    // camera.displayGrayscaleImage();
    cv::destroyAllWindows();
    return 0;
}
