#include "mymath.h"

MyMath::MyMath()
{

}

MyMath::~MyMath()
{

}
// Limits speed
int MyMath::Limit(int speed, int limit) {
	if (speed > limit) {
		speed = limit;
	}
	return speed;
}
// Subtracts 2 point2`s of eachother
Point2 MyMath::Subtract(Point2 P1, Point2 P2) {
	return Point2 (P1.x - P2.x, P1.y - P2.y);
}
// Gets magnitude from point2
float MyMath::Magnitude(Point2 P1) {
	return sqrt((P1.x * P1.x) + (P1.y * P1.y));
}
// Normalize a point2
Point2 MyMath::Normalize(Point2 P1) {
	float length = Magnitude(P1);
	P1.x / length;
	P1.y / length;
	return P1;
}
// Rotation from point2 with degrees
Point2 MyMath::Rotate(Point2 v, float degrees) {
	float xsin = sin(deg2rad(degrees));
	float xcos = cos(deg2rad(degrees));

	float tx = v.x;
	float ty = v.y;
	v.x = (xcos * tx) - (xsin * ty);
	v.y = (xsin * tx) + (xcos * ty);
	return v;
}
// Degrees to radians
double MyMath::deg2rad(double degrees) {
	return degrees * 4.0 * atan(1.0) / 180.0;
}
// Gets angle between 2 Point2`s
int MyMath::Angle(Point2 P1, Point2 P2) {
	double x = atan2(P1.y - P2.y, P1.x - P2.x);
	return x * 180 / 3.141;
}
// Rotate Radians
Point2 MyMath::RotateRadians(Point2 P1, int rot) {
	double ca = cos(rot);
	double sa = sin(rot);
	return Point2(ca * P1.x - sa * P1.y, sa * P1.x + ca * P1.y);
}
// Calculates distance between 2 points.
int MyMath::Distance(Point2 P1, Point2 P2) {
	return sqrt(pow(P2.x - P1.x, 2) + pow(P2.y - P1.y, 2) * 1.0);
}
// Speed
Point2 MyMath::Speed(Point2 P1, int speed) {
	Point2 result = Point2(P1.x * speed, P1.y * speed);
	return result;
}