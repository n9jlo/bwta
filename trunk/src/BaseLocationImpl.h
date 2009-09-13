#pragma once
#include <BWAPI.h>
#include <BWTA/BaseLocation.h>
#include <vector>
namespace BWTA
{
  class BaseLocationImpl : public BaseLocation
  {
  public:
    BaseLocationImpl();
    BaseLocationImpl(const BWAPI::TilePosition &tp);

    virtual BWAPI::Position getPosition() const;
    virtual BWAPI::TilePosition getTilePosition() const;

    virtual Region* getRegion() const;

    virtual const std::set<BWAPI::Unit*> &getMinerals();
    virtual const std::set<BWAPI::Unit*> &getGeysers() const;

    virtual double getGroundDistance(BaseLocation* other) const;
    virtual double getAirDistance(BaseLocation* other) const;

    virtual bool isIsland() const;
    virtual bool isMineralOnly() const;
    virtual bool isStartLocation() const;

    //-----------------------------------------------------------

    Region* region;
    bool island;
    bool start;
    std::set<BWAPI::Unit*> geysers;
    std::set<BWAPI::Unit*> minerals;
    std::map<BaseLocation*, double > ground_distances;
    std::map<BaseLocation*, double > air_distances;
    BWAPI::TilePosition tilePosition;
    BWAPI::Position position;
  };
}