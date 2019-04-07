#include "Animation.h"


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																			  //
//															Animation Class																	  //
//																																			  //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void marcos::AnimationManager::init()
{
	addAnimation("pacmanAnimation.png",4, 32, 32, "pacman_animation_key", 0.1f);
	addAnimation("death.png", 6, 32, 32, "pacman_death_animation_key", 0.1f);

}


//Animation setter, to store the animation frames in the animation cache to be called later
void marcos::AnimationManager::addAnimation(const std::string fileName, const int a_NumFrames, const float a_Width, const float a_Height, const std::string& keyName,
	const float a_Delay)
{
	cocos2d::Vector<cocos2d::SpriteFrame*> m_AnimFrames;

	for (int i = 0; i < a_NumFrames; i++)
	{
		auto frame = cocos2d::SpriteFrame::create(fileName, cocos2d::Rect(a_Width * i, 3, a_Width, a_Height));
		m_AnimFrames.pushBack(frame);
	}

	auto animation = cocos2d::Animation::createWithSpriteFrames(m_AnimFrames, a_Delay);
	addAnimation(animation, keyName);
}

/**
 * @brief This function set the animation from the file and add it onto the animation cache
 */
void marcos::AnimationManager::addAnimation(const std::string fileName, const int a_RowFrames, const int a_rows, const float a_Width, const float a_Height,
	const std::string& keyName, const float a_Delay)
{
	cocos2d::Vector<cocos2d::SpriteFrame*> m_AnimFrames;

	for (int i = 0; i < a_rows; i++)
	{
		for (int j = 0; j < a_RowFrames && j < 8; j++)
		{
			auto frame = cocos2d::SpriteFrame::create(fileName, cocos2d::Rect(a_Width * j, a_Height * i, a_Width, a_Height));
			m_AnimFrames.pushBack(frame);
		}
	}

	auto animation = cocos2d::Animation::createWithSpriteFrames(m_AnimFrames, a_Delay);
	addAnimation(animation, keyName);
}

/**
 *
 */
void marcos::AnimationManager::addAnimation(Animation* animationToAdd, const std::string& animationKey)
{
	AnimationCache::getInstance()->addAnimation(animationToAdd, animationKey);
}



/**
 * This static function will create an animation based on the animation key
 * @param animationKey The name of the key to create animation from
 * 
 * @return Return the cocos2d::Animate pointer
 */
cocos2d::Animate* marcos::AnimationManager::getAnimation(const std::string& animationKey)
{
	return Animate::create(AnimationCache::getInstance()->getAnimation(animationKey));
}

/**
 * This function will create an animation based on the animation key
 * and change the total animation time based on value
 * 
 * @param animationKey The key string for animation
 * @param animationTime The total animation time for the animation
 * 
 * @return Return the cocos2d::Animate pointer
 */
cocos2d::Animate* marcos::AnimationManager::getAnimationWithAnimationTime(const std::string& animationKey,
	const float& animationTime)
{
	const float delay = animationTime/ AnimationCache::getInstance()->getAnimation(animationKey)->getFrames().size();
	AnimationCache::getInstance()->getAnimation(animationKey)->setDelayPerUnit(delay);
	return getAnimation(animationKey);
}


