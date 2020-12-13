#pragma once 

#include <string> 
#include "Route.h" 

/**
 * @brief Routes class 
 * 
 */
class Routes {
public:
    /**
     * @brief 
     * 
     * @return true - Routes are valid  
     * @return false - Routes not valid
     */
    bool isValid() const; 

    /**
     * @brief Retuns Route with shortest total distance
     *        Note: function can be called only if isValid is true - otherwise behavior is undefined
     * 
     * @return const Route& - shortest route in distance 
     */
    const Route& shortestDistance() const;

    /**
     * @brief Retuns fastest Route
     *        Note: function can be called only if isValid is true - otherwise behavior is undefined
     * 
     * @return const Route& - shortest route in time 
     */
    const Route& shortestTime() const;

    // following function can be called only if isValid is false - undefined otherwise
    
    /**
     * @brief Get the Error Message 
     *        Note: function can be called only if isValid is false - otherwise behavior is undefined
     * 
     * @return const std::string& - error message
     */
    const std::string& getErrorMessage() const;
};

