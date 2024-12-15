#pragma once

#ifndef BUILD_STATIC
# if defined(SOLVER_LIB)
#  define SOLVER_EXPORT __declspec(dllexport)
# else
#  define SOLVER_EXPORT __declspec(dllimport)
# endif
#else
# define ALGO_EXPORT
#endif