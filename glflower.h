#ifndef __GLFLOWER_H__
#define __GLFLOWER_H__

#include "glutil.h"

typedef glvec3 glcolor;
typedef unsigned int glcolor_id;

typedef struct _glarc {
	glvec3 c;                                   /* circle center */
	glfloat r;                                  /*  */
	unsigned int from;                          /* angle start */
	unsigned int to;                            /* angle end */
} glarc;

typedef struct _glpetal {
	glfloat m;
	glfloat r1;
	glfloat r2;
	glfloat z;
	glfloat l;
} glpetal;

typedef struct _glcircle {
	glvec3 c;
	glfloat r;
} glcircle;

typedef struct _glflower_obj {
	glangle fa;
	glvec3 ps;
	glvec3 cs;
	glvec3 fm;
	glvec3 pm;
	glcolor_id cf;
} glflower_obj;

typedef struct _glflower_context {
	glprograme pprg;
	glvbo  pvbo;
	size_t pbsize;
	gllocation pvloc_ver;
	gllocation pvloc_mat_s;
	gllocation pvloc_mat_r;
	gllocation pvloc_mat_mf;
	gllocation pvloc_mat_mp;
	gllocation pfloc_lgc;
	gllocation pfloc_lgs;

	glprograme cprg;
	glvbo  cvbo;
	size_t cbsize;
	gllocation cvloc_ver;
	gllocation cvloc_mat_s;
	gllocation cvloc_mat_m;
	gllocation cfloc_rgs;
	gllocation cfloc_rgc;
} glflower_context;

typedef struct _glflower {
	glfloat sp;                                 /* scale for petal */
	glfloat sl;                                 /* scale for len between petal and center */
	glfloat sc;                                 /* scale for center */
	glvec3 p;                                   /* position */
	glangle a;                                  /* angle rotate */
	glcolor_id cf;                              /* color id */
	struct _glflower * next;
} glflower;

typedef struct _glbranch_context {
	glprograme bprg;
	gllocation bvloc_ver;
	gllocation bvloc_mat;
	gllocation bfloc_cor;
} glbranch_context;

typedef struct _glbranch_obj {
	glvbo bvbo;
	size_t bbsize;
	glmat4 m;
	struct _glbranch_obj * next;
} glbranch_obj;

typedef struct _glbranch {
	glfloat rx;
	glfloat ry;
	glfloat wmax;
	glfloat wmin;
	glfloat al;
	glfloat z;

	bool isflip;
	bool ismain;
	glfloat ar;
	glvec3 p;
	struct _glbranch * next;

	glvector * v;
} glbranch;

void glinit_tree_context();
void glrender_tree_context();

#endif //__GLFLOWER_H__
