#if !defined(BUG_H)
#define BUG_H

#include <binder_common.hpp>
#include <class_db.hpp>
#include <global_constants.hpp>
#include <node.hpp>
#include <ref.hpp>
#include <timer.hpp>
#include <utility_functions.hpp>
#include <variant.hpp>

namespace minimal
{
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
    };

} // namespace minimal

#endif // BUG_H