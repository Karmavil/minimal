#include "bug.hpp"

minimal::Bug::Bug()
{
    _timer = nullptr;
}

minimal::Bug::~Bug()
{
}

void minimal::Bug::_ready()
{
    if (get_child_count()) // When you add the node in the Editor this code will be executed
    {
        if (get_node_or_null("Timer")) // And because it has no childs yet, getting a child node will thrown an error.
        {
            _timer = get_node<godot::Timer>("Timer");
            _timer->set_wait_time(2);
            int error = _timer->connect("timeout", godot::Callable(this, "nextSlide"));
            if (error)
                godot::UtilityFunctions::print(error);
        }
    }
}

void minimal::Bug::nextSlide()
{
    godot::UtilityFunctions::print("Next slide");
}

void minimal::Bug::_bind_methods()
{
    using namespace godot;
    ClassDB::bind_method(D_METHOD("nextSlide"), &minimal::Bug::nextSlide);
}