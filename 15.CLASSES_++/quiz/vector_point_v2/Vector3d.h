#pragma once
#include "Point3d.h"			// here we included the Point3d.h file becuase we needed the full declaration to be able to interact with its referred members

class Vector3d
{
	private:
		double m_x {};
		double m_y {};
		double m_z {};

	public:
		Vector3d(double x, double y, double z)
			: m_x { x }
			, m_y { y }
			, m_z { z }
			{}

		void print() const;
		friend void Point3d::moveByVector( const Vector3d& v );		// the member referred to is here.
};
