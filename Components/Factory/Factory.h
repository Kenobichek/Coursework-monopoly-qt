#pragma once
#include <memory>

#include "../Cells/Business.h"
#include "../Cells/Cell.h"
#include "../Cells/Portal.h"
#include "../Cells/Question.h"

class CellFactory {
public:
    virtual std::shared_ptr<Cell> createField() const = 0;
};

class PortalFactory : public CellFactory {
public:
    std::shared_ptr<Cell> createField() const {
        return std::make_shared<Portal>();
    }
};

class BusinessFactory : public CellFactory {
public:
    std::shared_ptr<Cell> createField() const {
        return std::make_shared<Business>();
    }
};

class QuestionFactory : public CellFactory {
public:
    std::shared_ptr<Cell> createField() const {
        return std::make_shared<Question>();
    }
};

