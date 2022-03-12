#if !defined(CARBON_CAR_PANEL_H)
#define CARBIN_CAR_PANEL_H

#include <godot.hpp>
#include <panel.hpp>

namespace minimal
{
    class CarbonCarPanel : public godot::Panel
    {
        GDCLASS(CarbonCarPanel, godot::Panel);

      private:
        static void _bind_methods();

      public:
        CarbonCarPanel();
        ~CarbonCarPanel();
    };

} // namespace minimal

#endif // CARBON_CAR_PANEL_H
