#ifndef BSPTYPES_H
#define BSPTYPES_H

#define MAX_TEXTURES 1000				// The maximum amount of textures to load
#define FACE_POLYGON	1

// This is our basic 3D point/vector class
class CVector3
{
public:
	
	// A default constructor
	CVector3() {}

	// This is our constructor that allows us to initialize our data upon creating an instance
	CVector3(float X, float Y, float Z) 
	{ 
		x = X; y = Y; z = Z;
	}

	// Here we overload the + operator so we can add vectors together 
	CVector3 operator+(CVector3 vVector)
	{
		// Return the added vectors result.
		return CVector3(vVector.x + x, vVector.y + y, vVector.z + z);
	}

	// Here we overload the - operator so we can subtract vectors 
	CVector3 operator-(CVector3 vVector)
	{
		// Return the subtracted vectors result
		return CVector3(x - vVector.x, y - vVector.y, z - vVector.z);
	}
	
	// Here we overload the * operator so we can multiply by scalars
	CVector3 operator*(float num)
	{
		// Return the scaled vector
		return CVector3(x * num, y * num, z * num);
	}

	// Here we overload the / operator so we can divide by a scalar
	CVector3 operator/(float num)
	{
		// Return the scale vector
		return CVector3(x / num, y / num, z / num);
	}

	float x, y, z;						
};


/////// * /////////// * /////////// * NEW * /////// * /////////// * /////////// *

// This is our basic 2D point class.  This will be used to store the UV coordinates.
class CVector2 
{
public:

		// A default constructor
	CVector2() {}

	// This is our constructor that allows us to initialize our data upon creating an instance
	CVector2(float X, float Y) 
	{ 
		x = X; y = Y;
	}

	// Here we overload the + operator so we can add vectors together 
	CVector2 operator+(CVector2 vVector)
	{
		// Return the added vectors result.
		return CVector2(vVector.x + x, vVector.y + y);
	}

	// Here we overload the - operator so we can subtract vectors 
	CVector2 operator-(CVector2 vVector)
	{
		// Return the subtracted vectors result
		return CVector2(x - vVector.x, y - vVector.y);
	}
	
	// Here we overload the * operator so we can multiply by scalars
	CVector2 operator*(float num)
	{
		// Return the scaled vector
		return CVector2(x * num, y * num);
	}

	// Here we overload the / operator so we can divide by a scalar
	CVector2 operator/(float num)
	{
		// Return the scale vector
		return CVector2(x / num, y / num);
	}

	float x, y;
};
#endif