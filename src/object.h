#ifndef __PATHT_OBJ__
#define __PATHT_OBJ__

#include <stdlib.h>
#include "vector.h"


typedef struct pt_obj {
    pt_tri* triangles;
    pt_vect3* verticies;
    long triangle_count;
} pt_obj;

typedef struct pt_tri {
    pt_vect3* vert1, vert2, vert3;
    pt_vect3 normal_vector;
} pt_tri;

pt_obj pt_obj_Sphere(pt_vect3 pos, pt_vect3 rot, pt_vect3 scale, int segments, int rings);

pt_obj pt_obj_Square(pt_vect3 pos, pt_vect3 rot, pt_vect3 scale);

//Generate sphere
//Generate square

#endif