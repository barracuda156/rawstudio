/*
 * Copyright (C) 2006 Anders Brander <anders@brander.dk> and 
 * Anders Kvist <akv@lnxbx.dk>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef RS_MATRIX_H
#define RS_MATRIX_H

#define MATRIX_RESOLUTION (8) /* defined in bits! */

typedef struct {double coeff[3][3]; } RS_MATRIX3;
typedef struct {int coeff[3][3]; } RS_MATRIX3Int;
typedef struct {double coeff[4][4]; } RS_MATRIX4;
typedef struct {int coeff[4][4]; } RS_MATRIX4Int;

void printmat(RS_MATRIX4 *mat);
void matrix4_identity (RS_MATRIX4 *matrix);
void matrix4_to_matrix4int(RS_MATRIX4 *matrix, RS_MATRIX4Int *matrixi);
void matrix4_color_saturate(RS_MATRIX4 *mat, double sat);
void matrix4_color_hue(RS_MATRIX4 *mat, double rot);
void matrix4_color_exposure(RS_MATRIX4 *mat, double exp);
void matrix3_to_matrix3int(RS_MATRIX3 *matrix, RS_MATRIX3Int *matrixi);
void matrix3_identity (RS_MATRIX3 *matrix);
void matrix3_mult(const RS_MATRIX3 *matrix1, RS_MATRIX3 *matrix2);
float matrix3_weight(const RS_MATRIX3 *mat);
void matrix3_affine_invert(RS_MATRIX3 *mat);
void matrix3_affine_scale(RS_MATRIX3 *matrix, double xscale, double yscale);
void matrix3_affine_translate(RS_MATRIX3 *matrix, double xtrans, double ytrans);
void matrix3_affine_rotate(RS_MATRIX3 *matrix, double degrees);
inline void matrix3_affine_transform_point(RS_MATRIX3 *matrix, double x, double y, double *x2, double *y2);

#endif /* RS_MATRIX_H */
