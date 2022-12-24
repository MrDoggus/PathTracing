#include "vector.h"
#include <math.h>
#include <stdint.h>

//Performs a dot product operation on two vectors
float pt_vect3_Dot_Product(pt_vect3 v1, pt_vect3 v2)
{
    //Compute and return dot product
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

//Performs a cross product operation on two vectors
pt_vect3 pt_vect3_Cross_Product(pt_vect3 v1, pt_vect3 v2)
{
    //Compute and return cross product
    pt_vect3 v;
    v.x = v1.y * v2.z - v1.z * v2.y;
    v.y = v1.z * v2.x - v1.x * v2.z;
    v.z = v1.x * v2.y - v1.y * v2.x;

    return v;
}

//Normalizes a given vector
pt_vect3 pt_vect3_Normalize(pt_vect3 v)
{
    //Length squared
    float length_sq = v.x * v.x + v.y * v.y + v.z * v.z;

    //Modified Fast inverse square root from Quake 3
    union {
		float    f;
		uint32_t i;
	} conv = { .f = length_sq };
	conv.i  = 0x5f3759df - (conv.i >> 1);
	conv.f *= 1.5F - (length_sq * 0.5F * conv.f * conv.f);
	length_sq = conv.f; //Length_sq is now the inverse of the length

    //Divide individual components by the vector's length
    v.x = v.x * length_sq;
    v.y = v.y * length_sq;
    v.z = v.z * length_sq;

    return v;
}

pt_vect3 pt_vect3_Add(pt_vect3 v1, pt_vect3 v2)
{
    v1.x += v2.x;
    v1.y += v2.y;
    v1.z += v2.z;

    return v1;
}

pt_vect3 pt_vect3_Scale(pt_vect3 v, float factor)
{
    v.x *= factor;
    v.y *= factor;
    v.z *= factor;

    return v;
}

//Computes length of given vector
float pt_vect3_Length(pt_vect3 v)
{
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

//Prints a vector through the given file pointer
void pt_vector3_Print(FILE* file, pt_vect3 v)
{
    fprintf(file, "{%f, %f, %f}", v.x, v.y, v.z);
}