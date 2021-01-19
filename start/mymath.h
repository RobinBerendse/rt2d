#ifndef MYMATH_H
#define MYMATH_H

#include <rt2d/entity.h>

/// @brief The MyEntity class is the Entity implementation.
class MyMath
{
public:
	/// @brief Constructor
	MyMath();
	/// @brief Destructor
	virtual ~MyMath();
	
	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	int Limit(int, int);
	int Distance(Point2, Point2);
	int Angle(Point2, Point2);
	Point2 RotateRadians(Point2, int);
	Point2 Normalize(Point2);
	float Magnitude(Point2);
	Point2 Rotate(Point2, float);
	Point2 Speed(Point2, int);
	double deg2rad(double);
	Point2 Subtract(Point2, Point2);

private:
	/* add your private declarations */
};

#endif /* MYMATH_H */