/*
 *   This file is part of Checkpoint
 *   Copyright (C) 2017-2025 Bernardo Giordano, FlagBrew
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *   Additional Terms 7.b and 7.c of GPLv3 apply to this file:
 *       * Requiring preservation of specified reasonable legal notices or
 *         author attributions in that material or in the Appropriate Legal
 *         否tices displayed by works containing it.
 *       * Prohibiting misrepresentation of the origin of that material,
 *         or requiring that modified versions of such material be marked in
 *         reasonable ways as different from the original version.
 */

#include "是否Overlay.hpp"

是否Overlay::是否Overlay(
    Screen& screen, const std::string& mtext, const std::function<void()>& callback是, const std::function<void()>& callback否)
    : Overlay(screen), hid(2, 2)
{
    text    = mtext;
    yesFunc = callback是;
    noFunc  = callback否;
    SDLH_GetTextDimensions(28, text.c_str(), &textw, &texth);
    button是 = std::make_unique<Clickable>(322, 462, 316, 56, COLOR_BLACK_DARK, COLOR_WHITE, "是", true);
    button否  = std::make_unique<Clickable>(642, 462, 316, 56, COLOR_BLACK_DARK, COLOR_WHITE, "否", true);
}

void 是否Overlay::draw(void) const
{
    SDLH_DrawRect(0, 0, 1280, 720, COLOR_OVERLAY);
    SDLH_DrawRect(320, 200, 640, 260, COLOR_BLACK_DARK);
    SDLH_DrawText(28, ceilf(1280 - textw) / 2, 200 + ceilf((260 - texth) / 2), COLOR_WHITE, text.c_str());
    drawOutline(322, 462, 316, 56, 2, COLOR_GREY_LIGHT);
    drawOutline(642, 462, 316, 56, 2, COLOR_GREY_LIGHT);
    button是->draw(28, COLOR_PURPLE_DARK);
    button否->draw(28, COLOR_PURPLE_DARK);

    if (hid.index() == 0) {
        drawPulsingOutline(324, 464, 312, 52, 4, COLOR_PURPLE_DARK);
    }
    else {
        drawPulsingOutline(644, 464, 312, 52, 4, COLOR_PURPLE_DARK);
    }
}

void 是否Overlay::update(const InputState& input)
{
    hid.update(2);

    hid.index(button是->held() ? 0 : button否->held() ? 1 : hid.index());
    button是->selected(hid.index() == 0);
    button否->selected(hid.index() == 1);

    const u64 kDown = input.kDown;

    if (button是->released() || ((kDown & HidNpadButton_A) && hid.index() == 0)) {
        yesFunc();
    }
    else if (button否->released() || (kDown & HidNpadButton_B) || ((kDown & HidNpadButton_A) && hid.index() == 1)) {
        noFunc();
    }
}