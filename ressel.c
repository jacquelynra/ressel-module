/*
 *      __  __             _      _                 _
 *     |  \/  |           (_)    | |               | |
 *     | \  / | __ _  __ _ _  ___| |     __ _ _ __ | |_ ___ _ __ _ __
 *     | |\/| |/ _` |/ _` | |/ __| |    / _` | '_ \| __/ _ \ '__| '_ \
 *     | |  | | (_| | (_| | | (__| |___| (_| | | | | ||  __/ |  | | | |
 *     |_|  |_|\__,_|\__, |_|\___|______\__,_|_| |_|\__\___|_|  |_| |_|
 *                    __/ |
 *                   |___/
 *    Name: Resolution selector
 *    Author: Jacquelynra
 */

// Including stuff from ML

#include <module.h>
#include <menu.h>

// Taken from movtweaks.c functions ChangeHDMIOutputSizeToVGA and ChangeHDMIOutputSizeToFULLHD [it may not work on all cameras!]

static MENU_SELECT_FUNC(mem_rst_1080)
{
    hdmi_code_array[0] = 5;
    prop_request_change(PROP_HDMI_CHANGE_CODE, hdmi_code_array, 32);
}

static MENU_SELECT_FUNC(mem_rst_480)
{
    hdmi_code_array[0] = 2;
    prop_request_change(PROP_HDMI_CHANGE_CODE, hdmi_code_array, 32);
}

// Making the menu...

static struct menu_entry mem_rst_menu[] =
{
    {
        .name = "Resolution selector",
        .select = menu_open_submenu,
        .submenu_width = 710,
        .children =  (struct menu_entry[]) {
            {
                .priv		= "Force 1080i",
                .display = menu_print,
                .select = mem_rst_1080,
                .help =  "This forces the camera to output FullHD-ish.",
            }
            {
                .priv = "Force 480p",
                .display  = menu_print,
                .select = mem_rst_480,
                .help  = "This forces the camera to output at 480p.",
                .help2  = "... It's already on ML...",
            },
            MENU_EOL,
        }
    }
};

// Initialize and deinitalize!

static unsigned int mem_rst_init()
{
    menu_add("Resolution Selector", mem_rst_menu, COUNT(mem_rst_menu));
    return 0;
}

static unsigned int mem_rst_deinit()
{
    menu_remove("Resolution Selector", mem_rst_menu, COUNT(mem_rst_menu));
    return 0;
}

// End?

MODULE_INFO_START()
    MODULE_INIT(mem_rst_init)
    MODULE_DEINIT(mem_rst_deinit)
MODULE_INFO_END()
