/*
 *  Gwork
 *  Copyright (c) 2012 Facepunch Studios
 *  Copyright (c) 2015-2016 Billy Quith
 *  See license in Gwork.h
 */

#pragma once
#ifndef GWK_CONTROLS_WINDOWS_BUTTONS_H
#define GWK_CONTROLS_WINDOWS_BUTTONS_H

#include <Gwork/Gwork.h>
#include <Gwork/Controls/Button.h>
#include <Gwork/Skin.h>


namespace Gwk
{
    namespace Controls
    {
        class GWK_EXPORT WindowCloseButton : public Button
        {
            GWK_CONTROL_INLINE(WindowCloseButton, Button)
            {
                m_pWindow = NULL;
                SetSize(31, 31);
                SetText("");
            }

            virtual void Render(Skin::Base* skin) override
            {
                if (!m_pWindow)
                    return;

                skin->DrawWindowCloseButton(this,
                                            IsDepressed() && IsHovered(),
                                            IsHovered() && ShouldDrawHover(),
                                            IsDisabled());
            }

            void SetWindow(Gwk::Controls::Base* p)
            {
                m_pWindow = p;
            }

        protected:

            Controls::Base* m_pWindow;
        };


        class GWK_EXPORT WindowMaximizeButton : public WindowCloseButton
        {
            GWK_CONTROL_INLINE(WindowMaximizeButton, WindowCloseButton)
            {
                m_bMaximized = false;
            }

            virtual void Render(Skin::Base* skin) override
            {
                if (!m_pWindow)
                    return;

                skin->DrawWindowMaximizeButton(this,
                                               IsDepressed() && IsHovered(),
                                               IsHovered() && ShouldDrawHover(),
                                               IsDisabled(),
                                               m_bMaximized);
            }

            virtual void SetMaximized(bool b)
            {
                m_bMaximized = b;
            }

        protected:

            bool m_bMaximized;
        };


        class GWK_EXPORT WindowMinimizeButton : public WindowCloseButton
        {
            GWK_CONTROL_INLINE(WindowMinimizeButton, WindowCloseButton)
            {
            }

            virtual void Render(Skin::Base* skin)
            {
                if (!m_pWindow)
                    return;

                skin->DrawWindowMinimizeButton(this,
                                               IsDepressed() && IsHovered(),
                                               IsHovered() && ShouldDrawHover(),
                                               IsDisabled());
            }

        };


    }
}

#endif // ifndef GWK_CONTROLS_WINDOWS_BUTTONS_H