#if !defined(RED_CAR_PANEL_H)
#define RED_CAR_PANEL_H

#include <godot.hpp>
#include <panel.hpp>

namespace minimal
{
    class RedCarPanel : public godot::Panel
    {
        GDCLASS(RedCarPanel, godot::Panel);

      private:
        static void _bind_methods();

      public:
        RedCarPanel();
        ~RedCarPanel();
    };

} // namespace minimal

#endif // RED_CAR_PANEL_H
