//
// Created by Bogdan Zarnescu on 07.04.2022.
//

#include "Repo.h"

using namespace std;

/**
 * Constructor.
 */
Repo::Repo() {
    this->noEntities = 0;
}

/**
 * Destructor.
 */
Repo::~Repo() = default;

/**
 * Add an entity to the repository.
 * @param entity entity to be added
 */
void Repo::addEntity(Expense &entity) {
    if(entity.isValid()) {
        this->entities[this->noEntities++] = entity;
    } else {
        throw runtime_error("The entity is not valid!");
    }
}

/**
 * Modify entity from repository.
 * @param entity entity to be modified
 * @param newEntity entity modified
 */
void Repo::modifyEntity(Expense &entity, Expense &newEntity) {
    for(int i = 0; i < noEntities; i++) {
        if(entities[i].getId() == entity.getId()) {
            entities[i] = newEntity;
        }
    }
}

/**
 * Delete an entity.
 * @param id id of entity to be deleted
 */
void Repo::deleteEntity(int id) {
    for(int i = 0; i< noEntities; i++) {
        if(id == entities[i].getId()) {
            for(int j = i; j < noEntities - 1; j++) {
                entities[j] = entities[j + 1];
            }
            noEntities--;
        }
    }

}

/**
 * Get entity by id.
 * @param id id of entity to be found
 * @return entity found
 */
Expense Repo::getEntityById(int id) {
    for (int i = 0; i < noEntities; i++) {
        if (entities[i].getId() == id) {
            return entities[i];
        }
    }
    throw runtime_error("There is no entity with given id!");
}

/**
 * Get entity from given position.
 * @param pos given position
 * @return entity from given position
 */
Expense Repo::getEntityFromPos(int pos) {
    return this->entities[pos];
}

/**
 * Gets size of entities.
 * @return size of entities
 */
int Repo::getSize() {
    return this->noEntities;
}

/**
 * Get all entities.
 * @return all entities
 */
vector<Expense> Repo::getAll() {
    vector<Expense> v;
    for(int i = 0; i < noEntities; i++) {
        v.push_back(this->entities[i]);
    }
    return v;
}

Repo &Repo::operator=(const Repo &repo) {
    if(this != &repo) {
        this->noEntities = repo.noEntities;
        for(int i = 0; i < noEntities; i++) {
            this->entities[i] = repo.entities[i];
        }
    }
    return *this;
}
