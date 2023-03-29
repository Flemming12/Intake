#pragma once
#include <cstdio> //printf
#include "LDtkLoader/Project.hpp"
#include "player.h"

namespace Tmpl8 {
class CollisionClass {
	public:
		std::vector<std::reference_wrapper<ldtk::Entity>> collision;
	};
class Surface;
class Game
{
public:
	void SetTarget( Surface* surface ) { screen = surface; }
	void Init();
	void Shutdown();
	void Tick( float deltaTime );
	void MouseUp(int button) { mouseUp = button;/* implement if you want to detect mouse button presses */ }
	void MouseDown(int button) { mouseDown = button;/* implement if you want to detect mouse button presses */ }
	void MouseMove(int x, int y) 
	{ 
		mouseX = x;
		mouseY = y;
	}
	void KeyUp( int key ) { /* implement if you want to handle keys */ }
	void KeyDown( int key ) { /* implement if you want to handle keys */ }
private:
	Surface* screen;
	int mouseX;
	int mouseY;
	int mouseUp;
	int mouseDown;
	CollisionClass collisions;
	ldtk::Project ldtk_project;
	Player player;
	Camera camera;
};

}; // namespace Tmpl8