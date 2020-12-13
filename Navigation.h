#pragma once 

#include "NavigationGIS.h"

/**
 * @brief Navigation class
 * 
 */
class Navigation {
public:
    /**
     * @brief Construct a new Navigation object
     * 
     * @param gis - Note: you get a const ref of NavigationGIS
     */
    Navigation(const NavigationGIS& gis); 

    /**
     * @brief Get the Routes object
     * 
     * @param start 
     * @param end 
     * @return Routes 
     */
    Routes getRoutes(const Coordinates& start, const Coordinates& end) const;
    
    /**
     * @brief Get the Routes object
     *        Note: bonus method - not mandatory
     * 
     * @param start 
     * @param end 
     * @param res - Restricted Ways
     * @return Routes 
     */
    Routes getRoutes(const Coordinates& start, const Coordinates& end, const Restrictions& res) const;
};

