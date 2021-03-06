/*!The Graphic Box Library
 * 
 * GBox is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 * 
 * GBox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with GBox; 
 * If not, see <a href="http://www.gnu.org/licenses/"> http://www.gnu.org/licenses/</a>
 * 
 * Copyright (C) 2014 - 2015, ruki All rights reserved.
 *
 * @author      ruki
 * @file        arc.h
 * @ingroup     core
 *
 */
#ifndef GB_CORE_IMPL_ARC_H
#define GB_CORE_IMPL_ARC_H

/* //////////////////////////////////////////////////////////////////////////////////////
 * includes
 */
#include "prefix.h"

/* //////////////////////////////////////////////////////////////////////////////////////
 * extern
 */
__tb_extern_c_enter__

/* //////////////////////////////////////////////////////////////////////////////////////
 * macros
 */

// tan(pi/8) * 4 / 3
#ifdef GB_CONFIG_FLOAT_FIXED
#   define GB_ARC_MAKE_CUBIC_FACTOR     (36195)
#else
#   define GB_ARC_MAKE_CUBIC_FACTOR     (0.5522847498f)
#endif

/* //////////////////////////////////////////////////////////////////////////////////////
 * types
 */

/* the arc quad func type
 * 
 * @param ctrl      the ctrl point, the point is first if be null
 * @param point     the point 
 * @param priv      the user private data
 */
typedef tb_void_t   (*gb_arc_quad_func_t)(gb_point_ref_t ctrl, gb_point_ref_t point, tb_cpointer_t priv);

/* //////////////////////////////////////////////////////////////////////////////////////
 * interfaces
 */

/* make the quad curves for the arc
 *
 * @param arc       the arc
 * @param func      the make func
 * @param priv      the make func private data for user
 */
tb_void_t           gb_arc_make_quad(gb_arc_ref_t arc, gb_arc_quad_func_t func, tb_cpointer_t priv);

/* make the quad curves for the arc
 *
 * @param start     the start unit vector
 * @param stop      the stop unit vector
 * @param matrix    the user matrix
 * @param func      the make func
 * @param priv      the make func private data for user
 */
tb_void_t           gb_arc_make_quad2(gb_vector_ref_t start, gb_vector_ref_t stop, gb_matrix_ref_t matrix, tb_size_t direction, gb_arc_quad_func_t func, tb_cpointer_t priv);

/* //////////////////////////////////////////////////////////////////////////////////////
 * extern
 */
__tb_extern_c_leave__

#endif


