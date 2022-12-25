#include "vector.h"
#include <stdio.h>
#include <math.h>

int main()
{
    pt_vect3 v_i = {.x = 1, .y = 0.0, .z = 0.0};
    pt_vect3 v_j = {.x = 0.0, .y = 1, .z = 0.0};
    pt_vect3 v_k = {.x = 0.0, .y = 0.0, .z = 1.0};
    pt_vect3 v1 = {.x = INFINITY, .y = NAN, .z = HUGE_VALF};
    pt_vect3 v2 = {.x = 1.1111111111111111, .y = ((float)3)/(2), .z = ((float)5)/(2)};
    
    //Test print
    fprintf(stdout, "Testing Print: \n");
    fprintf(stdout, "i: ");
    pt_vect3_Print(stdout, v_i);
    fprintf(stdout, " - j: ");
    pt_vect3_Print(stdout, v_j);
    fprintf(stdout, " - k: ");
    pt_vect3_Print(stdout, v_k);
    fprintf(stdout, " - v1: ");
    pt_vect3_Print(stdout, v1);
    fprintf(stdout, " - v2: ");
    pt_vect3_Print(stdout, v2);


    //Test cross product
    fprintf(stdout, "\nTesting Cross product: \n");
    pt_vect3_Print(stdout, pt_vect3_Cross_Product(v_i, v_j));
    pt_vect3_Print(stdout, pt_vect3_Cross_Product(v_i, v_i));

    //Test dot product
    fprintf(stdout, "\nTesting Dot product: \n");
    fprintf(stdout, "%f\n", pt_vect3_Dot_Product(v_i, v_j));
    fprintf(stdout, "%f\n", pt_vect3_Dot_Product(pt_vect3_Scale(v_i, 2.0), v_i));

    //Test scale and add
    fprintf(stdout, "\nTesting Add and scale: \n");
    //Produces {3, 4, 0}
    pt_vect3 vv = pt_vect3_Add(pt_vect3_Scale(v_i, 3.0), pt_vect3_Scale(v_j, 4.0));
    pt_vect3_Print(stdout, vv);

    //Test magnitude normalize
    fprintf(stdout, "\nTesting Magnitude, normalize: \n");
    fprintf(stdout, "Magnitude: %f - Normailzed: ", pt_vect3_Magnitude(vv));
    pt_vect3 vvn = pt_vect3_Normalize(vv);
    pt_vect3_Print(stdout, vvn);
    fprintf(stdout, " - normalized magnitude: %f", pt_vect3_Magnitude(vvn));
    fprintf(stdout, "\n");


    return 0;
}