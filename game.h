#pragma once
#include <cstdio> //printf
#include "LDtkLoader/Project.hpp"
#include "player.h"
#include "surface.h"
#include <fstream>
#include <strstream>

#include <Audio/Sound.hpp>
#include <Audio/Device.hpp>

namespace Tmpl8 {
class CollisionClass {
	public:
		std::vector<std::reference_wrapper<ldtk::Entity>> collision;
	};
class Surface;
class Game
{
public:
	Game();
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
	void KeyDown( int key ) 
	{ 
		keyDown = key;
	}
private:
	Surface* screen;
	int mouseX;
	int mouseY;
	int mouseUp;
	int mouseDown;
	int keyDown;
	int gameTimer;
	int gameTimerMinutes;
	int gameTimerSeconds;
	int gameTimerMilliseconds;
	int highscoreMinutes;
	int highscoreSeconds;
	int highscoreMilliseconds;


	CollisionClass collisions;
	ldtk::Project ldtk_project;
	Player player;
	Camera camera;
	Sprite startButton;
	Sprite quitButton;
	Sprite background;
	Sprite playerSprite;
	Sprite continueButton;
	Sprite menuButton;
	Sprite controlsButton;
	Sprite backButton;
	Sprite controlMenu;
	Sprite finishScreen;
	Sprite timerBackground;

	std::string timerString;

	int backgroundWidth;
	int backgroundHeight;
	float scale;
	int scaleWidth;
	int scaleHeight;
	int offset;
	int playerWidth;
	int playerHeigth;
	int highscore;

	bool isGrounded;
	bool click;
	bool startMenu;
	bool pauseMenu;
	bool controlsMenu;
	bool finished;
	bool hitboxes;

	std::fstream myFile;

	Audio::Sound slime{ "assets/Audio/slime.wav", Audio::Sound::Type::Sound };
	Audio::Sound bounce{ "assets/Audio/bounce.wav", Audio::Sound::Type::Sound };
};

}; // namespace Tmpl8