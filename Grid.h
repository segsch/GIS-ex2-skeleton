#pragma once

#include "GISNamedTypes.h"
#include <vector>
#include <unordered_map>
#include <forward_list>


class CellEntities {
	//TODO: consider keeping way's segments seperated from all other enteties
	using EntitiesData = std::forward_list<EntityId>;
	EntitiesData entities;
	
public:
	using const_iterator = EntitiesData::const_iterator; 
	void insertEntity(const EntityId& id) {
		entities.emplace_front(id);	
	}
};

class Grid {
	static constexpr double precision = 0.0001;

    double truncateDecimalCoordinate(double coordinate) const {
    	return std::floor(coordinate / precision) * precision;
    }

    Coordinates truncateCoordinates(const Coordinates& coordinates) const {
        return {Longitude{truncateDecimalCoordinate(coordinates.longitude())}, Latitude{truncateDecimalCoordinate(coordinates.latitude())}};
    }
	
public:
	using GridCell = Coordinates;  
	// This function gets a new Entity and inserts it into all the zones it occupies
	// TODO: This version gets Coordinates and EntityId. 
	//       However, your version might get an object that has an API such as: getCenterCoordinates (what about way??), and isCoordinatesInsideEntityGeometry
	//
	// A new cell is created if this is the first Entity in it 
	//
	// Returns:
	//  all affected cells  
	std::vector<GridCell> setEntitiyOnGrid(const Coordinates& coordinates, const EntityId& id) {
		std::vector<GridCell> cells;
		GridCell grid_cell = truncateCoordinates(coordinates);
		grid[grid_cell].insertEntity(id); 
		cells.emplace_back(grid_cell); 

		// TODO: search all neighboring cells recursively, test whether entity also resides in them 

		return cells;	
	}

private:
        std::unordered_map<GridCell, CellEntities> grid;
};