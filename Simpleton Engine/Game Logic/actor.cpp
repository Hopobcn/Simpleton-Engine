//
//  actor.cpp
//  Game Engine
//
//  Created by Indi Kernick on 20/11/16.
//  Copyright © 2016 Indi Kernick. All rights reserved.
//

#include "actor.hpp"

Game::MissingComponent::MissingComponent(const char *what)
  : std::runtime_error(what) {}

Game::DuplicateComponent::DuplicateComponent()
  : std::runtime_error("Cannot add more than Component of the same type to an Actor") {}

Game::BadActorPtr::BadActorPtr(const char *what)
  : std::runtime_error(what) {}

Game::Actor::Actor(const Components &newComponents)
  : components(newComponents) {
  setActorPtr();
}

Game::Actor::Actor(Components &&newComponents)
  : components(std::move(newComponents)) {
  setActorPtr();
}

void Game::Actor::flushMessages() {
  try {
    MessageManager<Component::ID>::flushMessages();
  } catch (MissingMessenger &e) {
    throw MissingComponent("Tried to send a message to a component that doesn't exist");
  }
}

void Game::Actor::initComponents() {
  for (auto c = components.cbegin(); c != components.cend(); ++c) {
    (*c)->init();
  }
}

void Game::Actor::quitComponents() {
  for (auto c = components.cbegin(); c != components.cend(); ++c) {
    (*c)->quit();
  }
}

void Game::Actor::updateComponents(const uint64_t delta) {
  for (auto c = components.cbegin(); c != components.cend(); ++c) {
    (*c)->update(delta);
  }
}

void Game::Actor::setActorPtr() {
  for (auto c = components.cbegin(); c != components.cend(); ++c) {
    if (const Component::Ptr comp = *c) {
      comp->actor = this;
    }
  }
}

Game::Messenger<Game::Component::ID> *Game::Actor::getMessenger(const Component::ID compID) const {
  if (compID < components.size()) {
    return components[compID].get();
  } else {
    return nullptr;
  }
}