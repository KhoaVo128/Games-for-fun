#include "EntityManager.h"

EntityManager::EntityManager(){
    
}

void EntityManager::update(){
    for(auto e: m_entitiesToAdd){
        m_entities.push_back(e);
        m_entityMap[e->tag()].push_back(e);
    }

    m_entitiesToAdd.clear();
}

std::shared_ptr<Entity> EntityManager::addEntities(const std::string & tag){
    auto entity = std::shared_ptr<Entity>(new Entity(m_totalEntities++, tag));
    m_entitiesToAdd.push_back(entity); 
    return entity;
}

void EntityManager::removeDeadEntity(){
    
}

const EntityVec & EntityManager::getEntities(){
    return m_entities;
}

const EntityVec & EntityManager::getEntities(const std::string & tag){
    return m_entityMap[tag];
}

