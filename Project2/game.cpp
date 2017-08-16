

#include "Box2D/Box2D.h"

class gam {

public:
	b2World world;
	b2Vec2 gravity;
	b2CircleShape circle;

	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	b2PolygonShape bar;
	gam() : gravity(0.0f, -9.8f), world(gravity) {
		

		// Construct a world object, which will hold and simulate the rigid bodies.
		
		// Define the ground body.
		b2BodyDef anchorPnt;

		anchorPnt.position.Set(0.0f, 0.0f);
		b2BodyDef groundBodyDef;
		groundBodyDef.type = b2_dynamicBody;
		groundBodyDef.position.Set(0.0f, 0.0f);

		// Call the body factory which allocates memory for the ground body
		// from a pool and creates the ground box shape (also from a pool).
		// The body is also added to the world.
		b2Body* groundBody = world.CreateBody(&groundBodyDef);
		b2Body* anchr = world.CreateBody(&anchorPnt);

		// Define the ground box shape.

		// The extents are the half-widths of the box.
		bar.SetAsBox(50.0f, 5.0f);

		// Add the ground fixture to the ground body.
		groundBody->CreateFixture(&bar, 0.0f);

		// Define the dynamic body. We set its position and call the body factory.
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(0.0f, 4.0f);
		b2Body* body = world.CreateBody(&bodyDef);

		// Define another box shape for our dynamic body.
		circle.m_p.Set(2.0f, 3.0f);
		circle.m_radius = 0.5f;

		// Define the dynamic body fixture.
		b2FixtureDef fixtureDef;
		fixtureDef.shape = &circle;

		// Set the box density to be non-zero, so it will be dynamic.
		fixtureDef.density = 1.0f;

		// Override the default friction.
		fixtureDef.friction = 0.3f;

		// Add the shape to the body.
		body->CreateFixture(&fixtureDef);

		// Prepare for simulation. Typically we use a time step of 1/60 of a
		// second (60Hz) and 10 iterations. This provides a high quality simulation
		// in most game scenarios.
		b2RevoluteJointDef jointDef;
		jointDef.bodyA = anchr;
		jointDef.bodyB = groundBody;
		jointDef.localAnchorA = anchr->GetPosition();
		jointDef.localAnchorB = groundBody->GetLocalCenter();
		b2RevoluteJoint* joint = (b2RevoluteJoint*)world.CreateJoint(&jointDef);


		// This is our little game loop.
	}

};