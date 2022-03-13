#include "bug.hpp"

minimal::BugRef::BugRef()
{
}

minimal::BugRef::~BugRef()
{
}

minimal::Bug::Bug()
{
}

minimal::Bug::~Bug()
{
}

minimal::BugRef *minimal::Bug::return_extended_ref() const
{
    return memnew(minimal::BugRef());
}

godot::Ref<minimal::BugRef> minimal::Bug::extended_ref_checks(godot::Ref<minimal::BugRef> p_ref) const
{
    godot::Ref<minimal::BugRef> ref;
    ref.instantiate();
    // TODO the returned value gets dereferenced too early and return a null object otherwise.
    ref->reference();
    godot::UtilityFunctions::print("Example ref checks called with value: ", p_ref->get_instance_id(),
                                   ", returning value: ", ref->get_instance_id());
    return ref;
}

godot::Variant minimal::Bug::varargs_func(const godot::Variant **args, GDNativeInt arg_count, GDNativeCallError &error)
{
    godot::UtilityFunctions::print("Varargs called with ", godot::String::num((double)arg_count), " arguments");
    return arg_count;
}

void minimal::Bug::_ready()
{
    if (get_child_count()) // When you add the node in the Editor this code will be executed
    {
        if (get_node_or_null("Timer")) // And because it has no childs get a child yet it will thown an error
        {
            _timer = get_node<godot::Timer>("Timer");
            _timer->set_wait_time(2);
            godot::ClassDB::bind_method(godot::D_METHOD("timeout"), &minimal::Bug::nextSlide);
        }
    }
}

void minimal::Bug::nextSlide()
{
    godot::UtilityFunctions::print("Next slide");
}

void minimal::Bug::_bind_methods()
{
    godot::ClassDB::bind_method(godot::D_METHOD("return_extended_ref"), &minimal::Bug::return_extended_ref);
    godot::ClassDB::bind_method(godot::D_METHOD("extended_ref_checks"), &minimal::Bug::extended_ref_checks);
    godot::ClassDB::bind_method(godot::D_METHOD("nextSlide"), &minimal::Bug::nextSlide);
}