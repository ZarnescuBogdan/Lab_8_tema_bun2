//
// Created by Bogdan Zarnescu on 14.04.2022.
//

#include "Service.h"

/**
 * Constructor.
 */
Service::Service() = default;

/**
 * Constructor with parameters.
 * @param repo
 */
Service::Service(Repo &repo) {
    this->repo = repo;
}

/**
 * Destructor.
 */
Service::~Service() = default;

/**
 * Create an entity.
 * @param entity entity to be added
 */
void Service::create(Expense &entity) {
    repo.addEntity(entity);
}

/**
 * Update an entity.
 * @param entity entity to be modified
 * @param newEntity entity modified
 */
void Service::update(Expense entity, Expense newEntity) {
    repo.modifyEntity(entity, newEntity);
}

/**
 * Delete an entity.
 * @param entity entity to be deleted
 */
void Service::delete1(Expense entity) {
    repo.deleteEntity(entity.getId());
}

/**
 * Get entity by id.
 * @param id id of entity to be found
 * @return entity with given id
 */
Expense Service::getById(int id) {
    return repo.getEntityById(id);
}

/**
 * Get all entities from repository.
 * @return all entities from repository
 */
vector<Expense> Service::getAll() {
    return this->repo.getAll();
}

Expense Service::getEntityFromPos(int pos) {
    return repo.getEntityFromPos(pos);
}

int Service::getSize() {
    return repo.getSize();
}
