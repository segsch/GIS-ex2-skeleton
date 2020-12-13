#pragma once 

#include <vector>
#include "GISNamedTypes.h"

/**
 * @brief Route class
 * 
 */
class Route {
public:
    /**
     * @brief Get the ways constructing the Route and direction per way
     * 
     * @return const std::vector<std::pair<EntityId, Direction>>&
     */
    const std::vector<std::pair<EntityId, Direction>>& getWays() const;

    /**
     * @brief Get the Way's Start Point 
     * 
     * @return const Coordinates& 
     */
    const Coordinates& getWayStartPoint() const;
    
    /**
     * @brief Get the Way's End Point
     * 
     * @return const Coordinates& 
     */
    const Coordinates& getWayEndPoint() const;
    
    /**
     * @brief Get Way's total length
     * 
     * @return Meters 
     */
    Meters totalLength() const;
    
    /**
     * @brief Get Way's estimated duration
     * 
     * @return Minutes 
     */
    Minutes estimatedDuration() const; 
};

