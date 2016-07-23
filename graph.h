#include <complex.h>

typedef struct extreme_coordinates {
    complex double lower_left;
    complex double upper_right;
} extremes_t;

enum ImageType { CAIRO, GD };

#define NUM_COLORS 4

typedef struct graph {
    enum ImageType image_type;
    union {
        void *gd_image;	    /* gdImagePtr */
        void *cairo_image;	/* cairo_t *  */
    };
    const size_t width;
    const size_t height;
    const complex double center;
    const double range;
    const extremes_t extremes;
    const size_t colormap[NUM_COLORS][3];
} graph_t;

extremes_t get_extreme_coordinates(const size_t, const size_t, const complex double, const double);
graph_t graph_create(const char *, const size_t, const size_t, const complex double, const double);
void graph_destroy(const graph_t);
complex double graph_get_coordinates(graph_t, const size_t, const size_t);
void graph_set_pixel(const graph_t, const size_t, const size_t, const size_t);
void graph_write(const graph_t, const char *);
