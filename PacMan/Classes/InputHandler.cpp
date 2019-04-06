#include "InputHandler.h"

//--- Static Variables ---//
InputHandler* InputHandler::inst = 0;


//--- Constructor and Destructor ---//
InputHandler::InputHandler()
	: Node()
{
	//Init the engine variables
	exitOnEscape = true;

}

InputHandler::~InputHandler()
{
	//Delete the singleton instance
	if (inst)
		delete inst;

	//Clean up the singleton instance pointer
	inst = nullptr;

	//Tell the event dispatcher to clean up the mouse and keyboard event handlers 
	_eventDispatcher->removeAllEventListeners();

	//Clean up the mouse and keyboard listener pointers
	keyboardListener = nullptr;
}



//--- Setters and Getters ---//
//Engine
void InputHandler::setExitOnEscape(bool _exitOnEscape) 
{
	//Set the flag that determines if the program should exit when escape is pressed. If true, pressing escape will automatically exit the program
	exitOnEscape = _exitOnEscape;
}


//Keyboard
bool InputHandler::getKeyPress(KeyCode key) const
{
	//If the key requested is set to pressed, it was pressed this exact frame
	return (keyboardStates[(int)key] == InputState::Pressed);
}

bool InputHandler::getKeyRelease(KeyCode key) const
{
	//If the key requested is set to released, it was released this exact frame
	return (keyboardStates[(int)key] == InputState::Released);
}

bool InputHandler::getKey(KeyCode key) const
{
	//If the key requested is set to pressed OR set to held, it is currently down and so should return true
	return (keyboardStates[(int)key] == InputState::Pressed || keyboardStates[(int)key] == InputState::Held);
}


//Any 
bool InputHandler::getAnyButtonPress() const
{
	//If no mouse buttons were pressed, move to checking the keyboard. If any key was pressed, immediately return true
	for (unsigned int i = 0; i < NUM_KEY_CODES; i++)
	{
		//Immediately return true upon finding a single button that was pressed
		if (keyboardStates[i] == InputState::Pressed)
			return true;
	}

	//Return false if absolutely no buttons were pressed and so it reached this point
	return false;
}

bool InputHandler::getAnyButtonRelease() const
{

	//If no mouse buttons were pressed, move to checking the keyboard. If any key was released, immediately return true
	for (unsigned int i = 0; i < NUM_KEY_CODES; i++)
	{
		//Immediately return true upon finding a single button that was released
		if (keyboardStates[i] == InputState::Released)
			return true;
	}

	//Return false if absolutely no buttons were released and so it reached this point
	return false;
}

bool InputHandler::getAnyButton() const
{

	//If no mouse buttons were pressed, move to checking the keyboard. If any key is down, immediately return true
	for (unsigned int i = 0; i < NUM_KEY_CODES; i++)
	{
		//Immediately return true upon finding a single button that was released
		if (keyboardStates[i] == InputState::Released || keyboardStates[i] == InputState::Held)
			return true;
	}

	//Return false if absolutely no buttons are down and so it reached this point
	return false;
}



//--- Methods ---//
bool InputHandler::init()
{
	//Ensure the parent class was init first
	if (!Node::init())
		return false;


	//Set up the keyboard callbacks
	initKeyboardListener();

	//Indicate the init worked properly
	return true;
}

void InputHandler::update()
{
	//Loop through the keyboard buttons and update their states. If they were pressed last frame, they are now held. If they were released last frame, they are now idle.
	for (int i = 0; i < NUM_KEY_CODES; i++)
	{
		if (keyboardStates[i] == InputState::Idle)
			continue;

		if (keyboardStates[i] == InputState::Pressed)
			keyboardStates[i] = InputState::Held;
		else if (keyboardStates[i] == InputState::Released)
			keyboardStates[i] = InputState::Idle;
	}
}

void InputHandler::clearForNextFrame()
{
	//Loop through the keyboard buttons and update their states. If they were pressed last frame, they are now held. If they were released last frame, they are now idle.
	for (unsigned int i = 0; i < NUM_KEY_CODES; i++)
	{
		//Ignore the keys that are currently not being pressed. This will be true the large majority of the time, saving the two if checks afterwards
		if (keyboardStates[i] == InputState::Idle)
			continue;

		//If they button was pressed last frame, it is now considered held. If it was released last frame, is now considered idle
		if (keyboardStates[i] == InputState::Pressed)
			keyboardStates[i] = InputState::Held;
		else if (keyboardStates[i] == InputState::Released)
			keyboardStates[i] = InputState::Idle;
	}
}



//--- Utility Functions ---//

void InputHandler::initKeyboardListener()
{
	//Create the keyboard listener
	keyboardListener = EventListenerKeyboard::create();


	//On Key Pressed
	keyboardListener->onKeyPressed = [&](EventKeyboard::KeyCode keyCode, Event* event)
	{
		//Set the appropriate key to be considered pressed
		keyboardStates[(int)keyCode] = InputState::Pressed;

		//Exit if the escape key was pressed and the flag is set to true
		if (exitOnEscape && keyCode == KeyCode::KEY_ESCAPE)
			Director::getInstance()->end();
	};


	//On Key Released
	keyboardListener->onKeyReleased = [&](EventKeyboard::KeyCode keyCode, Event* event)
	{
		//Set the appropriate key to be considered released
		keyboardStates[(int)keyCode] = InputState::Released;
	};


	//Add the keyboard listener to the dispatcher
	_eventDispatcher->addEventListenerWithFixedPriority(keyboardListener, 1);
}



//--- Singleton Instance ---//
InputHandler* InputHandler::getInstance()
{
	//Generate the singleton if it hasn't been created yet
	if (!inst)
		inst = new InputHandler();
	
	//Return the singleton
	return inst;
}
