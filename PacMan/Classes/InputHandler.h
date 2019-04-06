/*
============================================================
	Author:
		- Daniel MacCormick - July 2017
		- Second year UOIT student, not affiliated with Cocos2D

	Updated for use in OOP first year:
		-Marcus Vine - April 2019
		-First Year student, Assignment Group 3

	Input Handler:
		- Simple input handler to wrap up Cocos2D's event based input system
		- Use this to get keyboard and mouse input events
			> Press is only true for the one frame the button is pressed (good for inputting names in textfield)
			> Release is only true for the one frame the button is released (good for general input like jumping -> feels natural to jump when you let the space bar go)
			> The other versions (getKey(), getMouseButton()) are true for every frame the button is held (good for continuous actions like moving a character or shooting a machine gun)
		- Also special 'anyButton' events
			> Same as mouse and keyboard but checks for ANY key and ANY mouse
			> Useful for splash screens and other similar systems where you just want the player to press ANYTHING before they move on

	Usage:
		- You are free to use this class for the case studies and for GDW
		- You are free to edit / overwrite any or all of this class
			> It is simply here to make your life easier
		- You must leave this comment block at the top of the header

	Note:
		- This class uses the Singleton design pattern
			> Do not ever make more than one instance of this class in its current form
			> You don't ever have to call the constructor for this class. Simply start using it and it will build itself
			> There is a macro "INPUTS->" that provides a shortcut for getting the singleton instance
============================================================
*/

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

//3rd Party Libraries
#include "cocos2d.h"

//Namespaces
using namespace cocos2d;


enum InputState
{
	Idle,
	Pressed,
	Released,
	Held
};

//Useful shorthands
#define NUM_MOUSE_BUTTONS (int)cocos2d::EventMouse::MouseButton::BUTTON_8 + 2 //The number of mouse buttons supported by Cocos2D.
#define NUM_KEY_CODES (int)cocos2d::EventKeyboard::KeyCode::KEY_PLAY + 1  //The number of keys supported by Cocos2D.
typedef cocos2d::EventKeyboard::KeyCode KeyCode; //A shortcut for accessing KeyCodes
typedef cocos2d::EventMouse::MouseButton MouseButton; //A shortcut for accessing MouseButtons




class InputHandler : public Node
{
protected:
	//--- Constructor ---//
	InputHandler(); //The constructor is protected so only one instance of this class can ever exist. This is called the singleton pattern.
	
public:
	//--- Destructor ---/
	~InputHandler();
	
	void setExitOnEscape(bool exitOnEscape); //Enable / disable exiting the program when escape is pressed. This is defaulted to true. Only set to false if you really want to use escape as a button in game


	//Keyboard

	bool getKeyPress(KeyCode key) const;

	bool getKeyRelease(KeyCode key) const;

	bool getKey(KeyCode key) const;


	//Any.

	bool getAnyButtonPress() const; 

	bool getAnyButtonRelease() const;

	bool getAnyButton() const;


	//--- Methods ---//

	bool init();

	void update();

	void clearForNextFrame();

	//--- Singleton Instance ---//

	static InputHandler* getInstance(); //Singleton 

private:
	//--- Private Data ---//
	//Cocos Engine
	Size windowDimensions; //The size of the window created at the start of the game. Only used to ensure the mouse position's y-coordinate is flipped properly
	bool exitOnEscape; //If true, the program will exit when escape is pressed. This is the default


	//Keyboard
	InputState keyboardStates[NUM_KEY_CODES]; //States for all of the keycodes in cocos2D
	EventListenerKeyboard* keyboardListener; //The listener for the keyboard events

	//--- Utility Functions ---//
	void initKeyboardListener(); //Set up the keyboard event handling through the listener

	//--- Singleton Instance ---//
	static InputHandler* inst; //The singleton instance. Ie: The only instance of this class that can ever exist
};

#define INPUTS InputHandler::getInstance() //Macro to make using the input handler easier. Automatically gets the singleton instance

#endif
