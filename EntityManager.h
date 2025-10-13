#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include "Entity.h"
#include<memory>
#include<vector>
#include<map>
//vector of entity pointer
typedef std::vector<std::shared_ptr<Entity>> EntityVec;

//mapping tags with entity vectors
typedef std::map <std::string, EntityVec> EntityMap;

class EntityManager
{
private:
    EntityVec m_entitiesToAdd;
    EntityVec m_entities;
    EntityMap m_entityMap; 

    size_t m_totalEntities = 0;

    void removeDeadEntities(Entity & vec);

public:
    EntityManager();

    void update();

    std::shared_ptr<Entity> addEntities(const std::string & tag);

    void EntityManager::removeDeadEntity();

    const EntityVec & getEntities();

    const EntityVec & getEntities(const std::string & tag);


};
#endif

