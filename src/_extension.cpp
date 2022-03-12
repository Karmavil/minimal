#include "_extension.hpp"

void register_extension_types()
{
    godot::ClassDB::register_class<minimal::Bug>();
    godot::ClassDB::register_class<minimal::RedCarPanel>();
    godot::ClassDB::register_class<minimal::CarbonCarPanel>();
}

void unregister_extension_types()
{
}

extern "C"
{

    // Initialization.

    GDNativeBool GDN_EXPORT minimal_library_init(const GDNativeInterface *p_interface,
                                                 const GDNativeExtensionClassLibraryPtr p_library,
                                                 GDNativeInitialization *r_initialization)
    {
        godot::GDExtensionBinding::InitObject init_obj(p_interface, p_library, r_initialization);

        init_obj.register_scene_initializer(register_extension_types);
        init_obj.register_scene_terminator(unregister_extension_types);

        return init_obj.init();
    }
}
