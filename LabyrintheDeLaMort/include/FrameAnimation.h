#pragma once
#include "Frame.h"

#include <vector>

#include <SFML/Graphics/Sprite.hpp>

// Inspired by https://bromeon.ch/libraries/thor/index.html

class FrameAnimation
{
private:
	std::vector<Frame> frames_;
	float duration_;
	float sum_frames_duration_;
	float total_progress_;
	sf::Sprite& target_;

public:
	explicit FrameAnimation(sf::Sprite& target, float duration);

	void add_frame(float relative_duration, const sf::IntRect& subrect);
	void add_frame(float relative_duration, const sf::IntRect& subrect, sf::Vector2f origin);
	void update(float elapsed);
};