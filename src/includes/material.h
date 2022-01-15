#ifndef MATERIAL_H
#define MATERIAL_H

#include "common.h"
#include "hittable.h"

class material
{
public:
    virtual bool scatter(const ray& r_in, const hit_record&rec, color& attenuation, ray& scattered) const = 0;
};

class lambertian : public material
{
public:
    color albedo;

public:
    lambertian(const color& a) : albedo(a) {}

    virtual bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override
    {
        auto scattered_direction = rec.normal + random_unit_vector();

        // Catch degenerate scatter direction 
        // Prevent scattered_direction == 0
        if (scattered_direction.near_zero())
            scattered_direction = rec.normal;

        scattered = ray(rec.p, scattered_direction);
        attenuation = albedo;
        return true;
    }
};

class metal : public material
{
public:
    color albedo;

public:
    metal(const color& a) : albedo(a) {}

    virtual bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override
    {
        vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
        scattered = ray(rec.p, reflected);
        attenuation = albedo;
        return (dot(scattered.direction(), rec.normal) > 0);
    }
};



#endif