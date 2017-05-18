#include "../h/WhoDeanApp.h"
#include "../h/Platform.h"
#include <vector>
#ifdef USE_GL
#include <GL\freeglut.h>
#endif
#include <btBulletDynamicsCommon.h>
#include "../h/deanX.h"

#include "../h/Display.h"
#include "../h/Input.h"
#include "../h/sceneSetup.h"
#include "../h/Graphics.h"
#include "../h/cameraControl.h"

namespace WhoDean
{
	

namespace Engine
{

	std::shared_ptr<Context> WhoDeanApp::context;
	std::shared_ptr<GameObject> testobj(new GameObject);
	std::vector <std::shared_ptr<GameObject>> CurrentScene;
	//std::shared_ptr<DCamera> WhoDeanApp::mainCam(new DCamera);
	deanX WhoDeanApp::phyWorld;
	UIcontext WhoDeanApp::name;
	skyBox WhoDeanApp::sky;
	
	void WhoDeanApp::whoDeanInit(int argc, char* argv[])
	{
		
		context.reset(new Context());
		context->running = false;
		Display::DisplayInit(argc,argv);
		Input::inputInit();
		//Graphics::init();

		//Physics start here
		phyWorld.physInit();

		//testobj->addComp<MeshData>();
		sceneSetup::setUptheScene(CurrentScene, phyWorld.getWorld());
		
		//CurrentScene.push_back(std::shared_ptr<GameObject>(new GameObject()));
		//CurrentScene[0]->addComp<MeshData>();

		CurrentScene[0]->addComp<DCamera>();
		std::weak_ptr<DCamera> CamRef = CurrentScene[0]->getComp<DCamera>().lock();
		CamRef.lock()->setPosition(glm::vec3(10.0f, 10.0f, 10.0f) + CurrentScene[0]->getComp<Transform>().lock()->getPos());
		CamRef.lock()->setTarget(glm::vec3(0.0f, -0.5f, -1.0f));
		WhoDeanUI::InitdeanUI();
		for (int i = 0; i < CurrentScene.size(); i++)
		{
			CurrentScene[i]->onStart();
			
		}
		
		btCollisionShape* fallShape = new btCapsuleShape(2.0f,5.0f);
		//mainCam->setPosition(glm::vec3(5.0f, 5.0f, 5.0f) + CurrentScene[0]->getComp<Transform>().lock()->getPos());
		//mainCam->setTarget(glm::vec3(0.0f, -1.0f, -1.0f));
		cameraControl::setMainCam(CamRef);
		sky.genSkybox(*CamRef.lock().get());
		//Graphics::setCam(CamRef.lock());
		//CamRef.lock()->
		//Graphics::setTarget(CurrentScene[0]);
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	}

	

	void WhoDeanApp::idle()
	{
	#ifdef USE_GL
		glutPostRedisplay();
	#endif
		//mainCam->update();
		//testobj->update();

		
		
		phyWorld.getWorld()->stepSimulation(1 / 60.f, 10);
		for (int i = 0; i < CurrentScene.size(); i++)
		{
			CurrentScene[i]->update();
			for (int j = 0; j < CurrentScene.size(); j++)
			{
				std::weak_ptr<Transform> refTrans = CurrentScene[i]->getComp<Transform>();
				
				if (refTrans.lock()->CheckCollision(CurrentScene[j]->getComp<Transform>().lock()) && CurrentScene[j]->getTag() != CurrentScene[i]->getTag())
				{

					CurrentScene[i]->onCollision(CurrentScene[j]->getTag());
				}
			}
		}
		sky.render();
		

		//This is done after all the objects are updated, bound and drawn.
		glutSwapBuffers();
		
	}

	void WhoDeanApp::run()
	{
		if (context->running == true)
		{
			return;
		}

		context->running = true;

		glutMainLoop();

		context->running = false;
	}

	
	
}


}