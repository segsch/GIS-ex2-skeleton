#pragma once

#include "GISNamedTypes.h"

/**
 * @brief Way class 
 * 
 */
class Way {
public:
    /**
     * @brief Get the Junctions object
     * 
     * @return std::pair<EntityId, EntityId> - <from_junction, to_junction>
     */
    std::pair<EntityId, EntityId> getJunctions() const; 

    /**
     * @brief Get the Length of Way
     * 
     * @return Meters 
     */
    Meters getLength() const; // might be lazily calculated (with a mutable field)
    
    /**
     * @brief 
     * 
     * @return true - Way is Bidirectional
     * @return false - Way is Unidirectional
     */
    bool isBidirectional() const;

    /**
     * @brief Get the Speed Limit set on Way 
     * 
     * @return int 
     */
    int getSpeedLimit() const;

    /**
     * @brief 
     * 
     * @return true - Way is an Highway 
     * @return false - Way is not an Highway
     */
    bool isHighway() const;

    /**
     * @brief 
     * 
     * @return true - Way is a Toll Road 
     * @return false - Way is not a Toll Road
     */
    bool isToll() const;
};

