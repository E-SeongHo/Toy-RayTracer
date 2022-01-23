#ifndef CAMERA_H
#define CAMERA_H

#include "common.h"

class camera
{
private:
    point3 origin;
    point3 lower_left_corner;
    vec3 horizontal;
    vec3 vertical;
public:
    camera(point3 lookfrom, point3 lookat, vec3 vup, double vfov, double aspect_ratio) 
    {   // vfov : vertical field-of-view in degree
        auto theta = degrees_to_radians(vfov);
        auto h = tan(theta/2);
        auto viewport_height = 2.0 * h;
        auto viewport_width = viewport_height * aspect_ratio;

        auto w = unit_vector(lookfrom - lookat);
        auto u = unit_vector(cross(vup, w));
        auto v = cross(w, u);

        origin = lookfrom;
        horizontal = viewport_width * u;
        vertical = viewport_height * v;
        lower_left_corner = origin - horizontal/2 - vertical/2 - w;
    }
    ray get_ray(double s, double t) const
    {
        return ray(origin, lower_left_corner + s*horizontal + t*vertical - origin);
    }
};

#endif