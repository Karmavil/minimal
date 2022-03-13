#if !defined(BUG_H)
#define BUG_H

#include <binder_common.hpp>
#include <class_db.hpp>
#include <global_constants.hpp>
#include <node.hpp>
#include <timer.hpp>
#include <utility_functions.hpp>
#include <ref.hpp>
#include <variant.hpp>

namespace minimal
{

    class BugRef : public godot::RefCounted
    {
        GDCLASS(BugRef, godot::RefCounted);

      protected:
        static void _bind_methods()
        {
        }

      public:
        BugRef();
        ~BugRef();
    };

    class Bug : public godot::Node
    {
        GDCLASS(Bug, godot::Node);

      protected:
        static void _bind_methods();

      private:
        godot::Timer *_timer;

      public:
        Bug();
        ~Bug();
        void nextSlide();
        virtual void _ready() override;

        minimal::BugRef *return_extended_ref() const;
        godot::Ref<minimal::BugRef> extended_ref_checks(godot::Ref<minimal::BugRef> p_ref) const;
        godot::Variant varargs_func(const godot::Variant **args, GDNativeInt arg_count, GDNativeCallError &error);
    };

} // namespace minimal

#endif // BUG_H