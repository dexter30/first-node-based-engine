#include "../h/deanPhysics.h"
#include "../h/MeshData.h"
namespace WhoDean {
	namespace Engine{
		
		deanPhysics::deanPhysics()
		{

			phyShape.reset(new btCapsuleShape(box.x/2,box.y));
			mass = 25;
		}

		deanPhysics::deanPhysics(std::string _shape)
		{
			shapeName = _shape;
			if (_shape == "box")
			{
			
				phyShape.reset(new btBoxShape(btVector3(50.0f, 50.0f, 50.0f)));
				
				mass = 0;
			}
			else
			{
				phyShape.reset(new btCapsuleShape(1.0, 1.0f));
				

				mass = 10;
			}
			model = _shape;

		}

		void deanPhysics::onStart()
		{
			glm::vec3 box = parent->getComp<MeshData>().lock()->getBounds();
			
				glm::vec3 reftrans = parent->getComp<Transform>().lock()->getScale();
				glm::mat4 scaleb = glm::scale(glm::mat4(1.0f), reftrans);
				box = glm::vec4(box.x, box.y, box.z, 1.0f) * scaleb;
				
				phyShape.reset(new btBoxShape(btVector3(box.x/2, box.y/2, box.z/2)));// *btVector3(reftrans.x, reftrans.y, reftrans.z)));
			
			//TODO: fix fall motion crap
			//btCollisionShape *caps = new btCapsuleShape(1.0, 1.0f);
			transformRef = parent->getComp<Transform>();
			btVector3 pos = btVector3(transformRef.lock()->getPos().x, transformRef.lock()->getPos().y, transformRef.lock()->getPos().z);
			fallMotion.reset(new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(pos))));

			fallInertia = btVector3(0, 0, 0);

			if (mass > 0)
			{
				phyShape->calculateLocalInertia(mass, fallInertia);
			}

			
			fallRigidBody = new btRigidBody(btRigidBody::btRigidBodyConstructionInfo(mass, fallMotion.get(), phyShape.get(), fallInertia));
			deanX::getWorld()->addRigidBody(fallRigidBody);
			//deanX::getWorld()->removeRigidBody(fallRigidBody);
			//deanX::instance().getWorld()->addRigidBody(fallRigidBody);
			transformRef = parent->getComp<Transform>();
			fallRigidBody->setRestitution(0.01f);
			//fallRigidBody->setLinearFactor(btVector3(0, 1, 0));
			fallRigidBody->setAngularFactor(btVector3(0, 1, 0));

		}

		void deanPhysics::update()
		{
			fallRigidBody->getMotionState()->getWorldTransform(position);
			
			transformRef.lock()->newPos(glm::vec3(position.getOrigin().getX(), position.getOrigin().getY(), position.getOrigin().getZ()));
			btTransform test1;
			btVector3 testMin;
			btVector3 testMax;
			/*fallRigidBody->getCollisionShape()->getAabb(test1, testMin, testMax);
			glBegin(GL_TRIANGLES);
			glColor3f(1.0f, 0.0f, 1.0f);
			glVertex3d(testMin.x(), testMin.y(), testMin.z());
			glColor3f(1.0f, 0.0f, 1.0f);
			glVertex3d(testMax.x(), testMax.y(), testMax.z());
			glEnd();*/
	

		//	std::cout <<model<< ": pos: x:" << position.getOrigin().getX() <<" y: "<< position.getOrigin().getY() <<" z: "<< position.getOrigin().getZ() << "\n";
		
		}

		btRigidBody* deanPhysics::getRigid()
		{
			return fallRigidBody;
		}
		void deanPhysics::setShape()
		{
		
		}

		void deanPhysics::applyForce(glm::vec3 force)
		{
			//btTransform trans;
			//fallRigidBody->getMotionState()->getWorldTransform(trans);
			fallRigidBody->activate();
			fallRigidBody->applyForce(btVector3(force.x, force.y, force.z), position.getOrigin());
			
			//fallRigidBody->getMotionState()->getWorldTransform(position);
		}

	}
}