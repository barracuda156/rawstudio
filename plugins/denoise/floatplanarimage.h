/*
* Copyright (C) 2009 Klaus Post
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

#ifndef floatplanarimage_h__
#define floatplanarimage_h__
#include "floatimageplane.h"
#include "jobqueue.h"
#include "fftwindow.h"

// A container and utility class

class FloatPlanarImage
{
public:
  FloatPlanarImage(void);
  FloatPlanarImage( const FloatPlanarImage &img );  // Creates image with similar features

  virtual ~FloatPlanarImage(void);
  void allocate_planes();
  void mirrorEdges();  
  FloatImagePlane **p;
  int nPlanes;
  void unpackInterleaved(const RS_IMAGE16* image);
  void packInterleaved( RS_IMAGE16* image );
  void applySlice(PlanarImageSlice *p);
  void setFilter( int plane, ComplexFilter *f, FFTWindow *window);
  JobQueue* getJobs();
  void unpackInterleaved_RGB_YUV( const RS_IMAGE16* image );
  void packInterleaved_YUV_RGB( RS_IMAGE16* image );
  int bw;  // Block width
  int bh;  // Block height
  int ox;  // Overlap pixels
  int oy;  // Overlap pixels

};
#endif // floatplanarimage_h__

inline guint clampbits(gint x, guint n) { guint32 _y_temp; if( (_y_temp=x>>n) ) x = ~_y_temp >> (32-n); return x;}