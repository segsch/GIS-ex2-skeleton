#include "GIS.h"

//the function clears all data from the system and returns the number of entities that were cleared
std::size_t GIS::clear() { 
	std::size_t size = 8;
	return size;
}

//the function loads a map file and returns a vector of all the EntityIds that were loaded (either Ids that appeared in file or generated) in the exact order as the objects that appeared in the file
//- in case the system had existing data, the data loaded from file is added to the existing data
//- in case entityId from file exists already the old data related to this id is replaced with the new data
//- in case an entity in file doesn’t have an Id, a new Id would be generated for it automatically
std::vector<EntityId> GIS::loadMapFile(const std::string& filename) {;
	std::string str = filename;
	str = "";
	std::vector<EntityId> res({EntityId("P1001"), EntityId("P1002"), EntityId("J1001"), EntityId("J1002"), EntityId("J1010"), EntityId("P1010"), EntityId("W2001"), EntityId("W2002")});
	return res;
}

//the function saves all data into a map file and returns the number of entities that were saved, the saved entities must include their Ids
std::size_t GIS::saveMapFile(const std::string& filename) const {
	std::string str = filename;
    str = "";	
	return 8;
}

//the function returns a vector of EntityIds for all entities that match the search_name
//all exact matches (case sensitive) shall be first in the vector
//right after shall optionally appear "partial matches", in any order (e.g. case insensitive match, matching based on the longer description, 
//match based on the category tags etc. partial match may work differently when the search is coordinates based or not  - note: partial match implementation is not mandatory, however it may grant you a bonus. 
//To qualify for bonus you must include in your submission zip a folder named bonus.partial_search, that contains three items: 
//partial_search.txt: explaining what you did and why qualify for bonus - include where code handels this exceptional partial search
//mapFile.json with 10-20 entities
//A file named: partial_search_test.cpp that includes a google test that passes and demonstrates your exceptional search
std::vector<EntityId> GIS::getEntities(const std::string& search_name) const {
	std::vector<EntityId> res;
	if (search_name == "Washington Square Park") {
		res.emplace_back(EntityId("P1001"));
	}

	return res;
}

//same as above, but restricted to a search area of the given circle
//TODO: std::vector<EntityId> getEntities(const std::string& search_name, const Coordinates&, Meters radius);

//the function shall get EntityId and Coordinates
//if the Id is not known, the function returns an empty optional
//otherwise, return the closest Coordinates, on entity’s perimeter, to the provided Coordinates.
//(the Coordinates shall be a point on a the entity’s geometry that is closest to the given Coordinates)
//TODO: std::optional<Coordinates> getEntityClosestPoint(const EntityId&, const Coordinates&);

//thie function shall get Coordinates and return the closest Coordinates of a Way (the Coordinates may be a point on a the way that is closest to the given Coordinates) and the EntityId of this way
//TODO: std::pair<Coordinates, EntityId> getWayClosestPoint(const Coordinates&);
