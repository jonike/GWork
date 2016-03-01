/*
 *  Gwork
 *  Copyright (c) 2010 Facepunch Studios
 *  Copyright (c) 2013-16 Billy Quith
 *  See license in Gwork.h
 */

#pragma once
#ifndef GWK_HOOK_H
#define GWK_HOOK_H

#include <Gwork/Gwork.h>
#include <list>

#if GWK_HOOKSYSTEM

namespace Gwk
{
    namespace Hook
    {
        class GWK_EXPORT BaseHook
        {
        public:

            virtual bool OnControlClicked(Gwk::Controls::Base*, int /*iMouseX*/, int /*iMouseY*/)
            {
                return false;
            }

        };


        typedef std::list<BaseHook*> HookList;

        GWK_EXPORT HookList& GetHookList();

        GWK_EXPORT void AddHook(BaseHook* hook);
        GWK_EXPORT void RemoveHook(BaseHook* hook);

        template <typename fnc>
        bool CallHook(fnc f)
        {
            for (HookList::iterator it = GetHookList().begin(); it != GetHookList().end(); ++it)
            {
                if (((*it)->*f)())
                    return true;
            }

            return false;
        }

        template <typename fnc, typename AA>
        bool CallHook(fnc f, AA a)
        {
            for (HookList::iterator it = GetHookList().begin(); it != GetHookList().end(); ++it)
            {
                if (((*it)->*f)(a))
                    return true;
            }

            return false;
        }

        template <typename fnc, typename AA, typename AB>
        bool CallHook(fnc f, AA a, AB b)
        {
            for (HookList::iterator it = GetHookList().begin(); it != GetHookList().end(); ++it)
            {
                if (((*it)->*f)(a, b))
                    return true;
            }

            return false;
        }

        template <typename fnc, typename AA, typename AB, typename AC>
        bool CallHook(fnc f, AA a, AB b, AC c)
        {
            for (HookList::iterator it = GetHookList().begin(); it != GetHookList().end(); ++it)
            {
                if (((*it)->*f)(a, b, c))
                    return true;
            }

            return false;
        }

    }

}

#endif // if GWK_HOOKSYSTEM
#endif // ifndef GWK_HOOK_H
