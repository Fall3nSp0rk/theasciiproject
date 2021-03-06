#pragma once
//
//  WorldMap.h
//  The ASCII Project
//
//  Created by Jonathan Rumion on 2/28/13.
//  Copyright (c) 2013 TAP. All rights reserved.
//

#include "../serialization/Boost_Serialization.h"
#include "TileMap.h"
#include "Tile.h"
#include "EntityMap.h"
#include <vector>



class WorldMap {
    
private:
    
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & X;
        ar & Y;
        ar & Z;
        ar & mapX;
        ar & mapY;
        ar & globalTileMap;
        //ar & globalEntityMap;
    }
    
    // Global Map Dimensions
    int X,Y,Z;
    
    // TileMap Dimensions
    int mapX, mapY;
    
    // Storage Container for TileMaps
    std::vector< std::vector< std::vector<TileMap *> > > globalTileMap;
    
    // Storage Container for EntityMaps
    //std::vector< std::vector< std::vector< std::shared_ptr<EntityMap> > > > globalEntityMap;
    
    void init();
    void initGlobalTileMap();
    void initGlobalEntityMap();
    
    
public:
    
    WorldMap(){};
    WorldMap( int x, int y, int z, int tX, int tY) : X(x), Y(y), Z(z), mapX(tX), mapY(tY){init();};
    
    ~WorldMap(){};
    
    int getX(){return X;};
    int getY(){return Y;};
    int getZ(){return Z;};
    
    TileMap* getTileMap(int x, int y, int z){return globalTileMap.at(x).at(y).at(z);};
    
};
