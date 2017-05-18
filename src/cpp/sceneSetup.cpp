#include "../h/sceneSetup.h"

namespace WhoDean
{

	namespace Engine
	{

		void sceneSetup::setUptheScene(std::vector<std::shared_ptr<GameObject>>& Scene, std::shared_ptr<btDiscreteDynamicsWorld> _physicsWorld)
		{
			Scene.push_back(std::shared_ptr<GameObject>(new GameObject()));
			std::weak_ptr<MeshData> refMesh = Scene[0]->addComp<MeshData>();
			//std::weak_ptr<MeshData> refMesh = Scene[0]->addComp<MeshData>(std::shared_ptr<MeshData>(new MeshData("Woo!")));

			
			refMesh.lock()->LoadAsset("res/Snak222");
			Scene.push_back(std::shared_ptr<GameObject>(new GameObject()));
			refMesh = Scene[1]->addComp<MeshData>();
			
			refMesh.lock()->LoadAsset("res/checker");
			
			
			//Scene.push_back(std::shared_ptr<GameObject>(new GameObject()));
			 //refMesh = Scene[1]->addComp<MeshData>();
			//refMesh.lock()->LoadAsset("res/Laughing_Octopus.obj");

			
			Scene.push_back(std::shared_ptr<GameObject>(new GameObject()));
			refMesh = Scene[2]->addComp<MeshData>();
			refMesh.lock()->LoadAsset("res/barrel_obj");
			Scene.push_back(std::shared_ptr<GameObject>(new evilBlock));
			for (std::shared_ptr<GameObject> obj : Scene)
			{
				obj->onAwake();
			}
			std::weak_ptr<Transform> refTrans = Scene[1]->getComp<Transform>();
			refTrans.lock()->setPos(glm::vec3(0.0f, 0.0f, 0.0f));
			//refTrans.lock()->setScale(glm::vec3(0.5f, 0.5f, 0.5f));
			 refTrans = Scene[0]->getComp<Transform>();
			std::weak_ptr<Player> refPlayer = Scene[0]->addComp<Player>();
			Scene[0]->getComp<Transform>().lock()->setPos(glm::vec3(0.0f, 100.0f, 30.0f));
			Scene[0]->getComp<Transform>().lock()->setScale(glm::vec3(0.5f, 0.5f, 0.5f));
			Scene[0]->getComp<Transform>().lock()->setRad(10.0f);
			Scene[2]->getComp<Transform>().lock()->setPos(glm::vec3(5.0f, 52.0f, 00.0f));
			Scene[2]->getComp<Transform>().lock()->setScale(glm::vec3(0.05f, 0.05f, 0.05f));

			Scene[0]->addComp<deanPhysics>();
			Scene[1]->addComp<deanPhysics>(std::shared_ptr<deanPhysics>(new deanPhysics("box")));
			Scene[2]->addComp<UIcontext>(std::shared_ptr<UIcontext>(new UIcontext("res/barrelTextScript")));
			Scene[0]->setTag("player");
			//Scene[2]->getComp<UIcontext>().lock()->onCollision("player");
		}

		void sceneSetup::update()
		{

		}

	}
}