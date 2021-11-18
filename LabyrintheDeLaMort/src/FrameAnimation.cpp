#include "FrameAnimation.h"

FrameAnimation::FrameAnimation(sf::Sprite& target, float duration)
	: duration_(duration), sum_frames_duration_(0), total_progress_(0), target_(target)
{
}

void FrameAnimation::add_frame(float relative_duration, const sf::IntRect& subrect)
{
	frames_.emplace_back(relative_duration, subrect);
	sum_frames_duration_ += relative_duration;
}

void FrameAnimation::add_frame(float relative_duration, const sf::IntRect& subrect, sf::Vector2f origin)
{
	frames_.emplace_back(relative_duration, subrect, origin);
	sum_frames_duration_ += relative_duration;
}

void FrameAnimation::update(const float elapsed)
{
	total_progress_ += elapsed;
	float progress = total_progress_;

	for (auto& frame : frames_)
	{
		const float frame_time =  frame.relative_duration / sum_frames_duration_ * duration_;
		progress -= frame_time;

		if (progress <= 0.0f || &frame == &frames_.back())
		{
			target_.setTextureRect(frame.subrect);
			break;
		}
	}

	if(total_progress_ > duration_)
	{
		total_progress_ -= duration_;
	}
}
