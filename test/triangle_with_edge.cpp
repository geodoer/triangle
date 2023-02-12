#include "doctest/doctest.h"

#include <cstdlib>
#include "triangle.h"
#include "utils.hpp"

//带边约束三角化
TEST_CASE("Edge constraint triangulation") 
{
#if 1
    std::vector<Point> points
    {
        {4,4},
        {-4,4},
        {-4,-4},
        {4,-4},
        {2,4},
        {0,0},
        {2,-2},
        {1,-4}
    };
    std::vector<Segment> segments
    {
        //四边形的四条边
        {0,1},
        {1,2},
        {2,3},
        {3,0},
        //切割线
        {4,5},
        {5,6},
        {6,7}
    };
#else
    std::vector<Point> points
    {
        {4,4},
        {-4,4},
        {-4,-4},
        {4,-4},
        {2,4},
        {0,0},
        {2,-2},
        {1,-4}
    };
    //用切割线把四边形进行打断
    std::vector<Segment> segments
    {
        {0,4},
        {4,1},
        {1,2},
        {2,7},
        {7,3},
        {3,0},
        {4,5},
        {5,6},
        {6,7}
    };
#endif

    auto in = create(points, segments);
    printf("Input point set:\n\n");
    report(&in);

    struct triangulateio triangles;

    triangulate("jpzQYY", &in, &triangles);

    printf("triangles: \n\n");
    report(&triangles);

    /* Free all allocated arrays, including those allocated by Triangle. */
    trifree(in);
    trifree(triangles);
}