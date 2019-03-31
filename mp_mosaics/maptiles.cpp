/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>
#include "maptiles.h"
//#include "cs225/RGB_HSL.h"

using namespace std;


Point<3> convertToXYZ(LUVAPixel pixel) {
    return Point<3>( pixel.l, pixel.u, pixel.v );
}

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage>& theTiles)
{
    /**
     * @todo Implement this function!
     */
     vector<Point<3>> pts;
     pts.resize(theTiles.size());
     map<Point<3>,int> pointmap;
     for (unsigned i=0; i<pts.size(); i++)
     	{
     		pts[i]=convertToXYZ(theTiles[i].getAverageColor());

     		pointmap[pts[i]] = i;
     	}
      KDTree<3> tree(pts);
      int num_rows = theSource.getRows();
      int num_columns = theSource.getColumns();
      MosaicCanvas* mosaic = new MosaicCanvas(num_rows, num_columns);
      for (int i=0; i<num_rows; i++){
      for (int j=0; j<num_columns; j++){
        LUVAPixel source_color = theSource.getRegionColor(i, j);
        Point<3> query;
        query=convertToXYZ(source_color);
      
        Point<3> foundpoint = tree.findNearestNeighbor(query);
        int index = pointmap[foundpoint];
        mosaic->setTile(i, j, &theTiles[index]);
      }}


    return mosaic;
}
