#ifndef __PATHT_VECTOR__
#define __PATHT_VECTOR__

#include <stdio.h>

typedef struct pt_vect3 {
    float x, y, z;
} pt_vect3;

//Performs a dot product operation on two vectors
float pt_vect3_Dot_Product(pt_vect3 v1, pt_vect3 v2);

//Performs a cross product operation on two vectors
pt_vect3 pt_vect3_Cross_Product(pt_vect3 v1, pt_vect3 v2);

//Normalizes a given vector
pt_vect3 pt_vect3_Normalize(pt_vect3 v);

//Scales a vector by a given factor
pt_vect3 pt_vect3_Scale(pt_vect3 v, float factor);

//Adds two vectors together
pt_vect3 pt_vect3_Add(pt_vect3 v1, pt_vect3 v2);

//Computes length of given vector
float pt_vect3_Magnitude(pt_vect3 v);

//Prints a vector through the given file pointer
void pt_vect3_Print(FILE* file, pt_vect3 v);

#endif