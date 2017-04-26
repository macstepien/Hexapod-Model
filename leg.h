#ifndef LEG_H
#define LEG_H

///klasa nogi z implementacja kinematyki odwrotnej opartej na
///https://oscarliang.com/inverse-kinematics-and-trigonometry-basics/
///https://oscarliang.com/inverse-kinematics-implementation-hexapod-robots/

#include <opencv2/core/core.hpp>
#include "util.h"

class Leg
{
    private:
        joints legJoints; //joint A - przy podstawie, nastepne po koleji
        cv::Point3f legEnd;
        cv::Point3f angles;//katy na zgieciach x - kat przy polaczeniu A, y przy B, z przy C
        cv::Point3f initAngles;
        cv::Point3f lengths;//dlugosci poszczegolnych czesci nog x-AB y-BC z-CD
        cv::Mat R; //macierz obrotu taka jak robota

        cv::Point3f signals;
        void calculateJointPoints(cv::Point3f angl);
        void calculateServoSignals();
    public:
        Leg(){};
        Leg(cv::Point3f joint1, cv::Point3f angles1, cv::Point3f lengths1, cv::Point3f signals1);

        void initJointPoints();
        void setJointA(cv::Point3f joint1);
        void setAgnles(cv::Point3f angles1);
        void setLengths(cv::Point3f lengths1);
        void setR(cv::Mat R1);
        int calculateAngles(cv::Point3f angl);
        void setSignals(cv::Point3f sig);
        joints getJoints(){return legJoints;};
};

#endif // LEG_H
