#include "bug.hpp"

void minimal::Bug::_bind_methods()
{
    godot::ClassDB::bind_method(godot::D_METHOD("nextSlide"), &Bug::nextSlide);
}

minimal::Bug::Bug()
{
}

minimal::Bug::~Bug()
{
}

void minimal::Bug::_ready()
{
    _timer = get_node<godot::Timer>("Timer");
    _timer->set_wait_time(2);
    godot::ClassDB::bind_method(godot::D_METHOD("timeout"), &minimal::Bug::nextSlide);
}

void minimal::Bug::nextSlide()
{
    godot::UtilityFunctions::print("Next slide");
}
