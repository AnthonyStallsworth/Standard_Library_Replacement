/* Macro function to make adding to void pointers less painful. */
#ifndef vp_add(vp, bytes)
#define vp_add(vp, bytes) ((void*) (((char*) vp) + bytes))
#endif