#pragma once
#include <stdio.h>
#include <vector>
#include <array>
#include "triangle.h"

using Point = std::array<TRI_REAL, 2>;
using Points = std::vector<Point>;

using Segment = std::array<int, 2>;
using Segments = std::vector<Segment>;

triangulateio create(const Points& pnts, const Segments& segments)
{
    triangulateio in;
    {
        auto size = pnts.size();
        in.numberofpoints = size;
        in.pointlist = (TRI_REAL*)malloc(in.numberofpoints * 2 * sizeof(TRI_REAL));

        for (int i{ 0 }; i < in.numberofpoints; ++i)
        {
            const auto& p = pnts[i];
            in.pointlist[i * 2    ] = p[0];
            in.pointlist[i * 2 + 1] = p[1];
        }
    }
    {
        in.numberofpointattributes = 1;
        in.pointattributelist = (TRI_REAL*)malloc(in.numberofpoints * in.numberofpointattributes * sizeof(TRI_REAL));

        for (int pngId = 0; pngId < in.numberofpoints; pngId++)
        {
            in.pointattributelist[pngId] = pngId; //属性即是点在LineString下的索引
        }
    }

    {
        in.numberofsegments = segments.size();
        in.segmentlist = (int*)(malloc)(in.numberofsegments * 2 * sizeof(TRI_REAL));

        for (int i{ 0 }; i < in.numberofsegments; ++i)
        {
            const auto& seg = segments[i];
            in.segmentlist[i * 2] = seg[0];
            in.segmentlist[i * 2 + 1] = seg[1];
        }
    }

    return in;
}

void report(struct triangulateio* io,
    bool markers = true,
    bool reporttriangles = true,
    bool reportneighbors = true,
    bool reportsegments = true,
    bool reportedges = true,
    bool reportnorms = true)
{
    int i, j;

    for (i = 0; i < io->numberofpoints; i++) {
        printf("Point %4d:", i);
        for (j = 0; j < 2; j++) {
            printf("  %.6g", io->pointlist[i * 2 + j]);
        }
        if (io->numberofpointattributes > 0) {
            printf("   attributes");
        }
        for (j = 0; j < io->numberofpointattributes; j++) {
            printf("  %.6g",
                io->pointattributelist[i * io->numberofpointattributes + j]);
        }
        if (markers && io->pointmarkerlist) {
            printf("   marker %d\n", io->pointmarkerlist[i]);
        }
        else {
            printf("\n");
        }
    }
    printf("\n");

    if (reporttriangles || reportneighbors) {
        for (i = 0; i < io->numberoftriangles; i++) {
            if (reporttriangles) {
                printf("Triangle %4d points:", i);
                for (j = 0; j < io->numberofcorners; j++) {
                    printf("  %4d", io->trianglelist[i * io->numberofcorners + j]);
                }
                if (io->numberoftriangleattributes > 0) {
                    printf("   attributes");
                }
                for (j = 0; j < io->numberoftriangleattributes; j++) {
                    printf("  %.6g", io->triangleattributelist[i *
                        io->numberoftriangleattributes + j]);
                }
                printf("\n");
            }
            if (reportneighbors && io->neighborlist) {
                printf("Triangle %4d neighbors:", i);
                for (j = 0; j < 3; j++) {
                    printf("  %4d", io->neighborlist[i * 3 + j]);
                }
                printf("\n");
            }
        }
        printf("\n");
    }

    if (reportsegments) {
        for (i = 0; i < io->numberofsegments; i++) {
            printf("Segment %4d points:", i);
            for (j = 0; j < 2; j++) {
                printf("  %4d", io->segmentlist[i * 2 + j]);
            }
            if (markers && io->segmentmarkerlist) {
                printf("   marker %d\n", io->segmentmarkerlist[i]);
            }
            else {
                printf("\n");
            }
        }
        printf("\n");
    }

    if (reportedges && io->edgelist) {
        for (i = 0; i < io->numberofedges; i++) {
            printf("Edge %4d points:", i);
            for (j = 0; j < 2; j++) {
                printf("  %4d", io->edgelist[i * 2 + j]);
            }
            if (reportnorms && (io->edgelist[i * 2 + 1] == -1)) {
                for (j = 0; j < 2; j++) {
                    printf("  %.6g", io->normlist[i * 2 + j]);
                }
            }
            if (markers && io->edgemarkerlist) {
                printf("   marker %d\n", io->edgemarkerlist[i]);
            }
            else {
                printf("\n");
            }
        }
        printf("\n");
    }
}