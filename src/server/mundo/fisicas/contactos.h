#ifndef __CONTACTOS_H__
#define __CONTACTOS_H__

#include "Box2D/Box2D.h"

class ContactListener : public b2ContactListener {
    public:
    ContactListener();
    virtual ~ContactListener();
    virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold) override;
    virtual void BeginContact(b2Contact* contact) override;
    virtual void EndContact(b2Contact* contact) override;
    virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse) override;
};

#endif
