#pragma once
#include "GFxUI.GFxObject.h"
#include "Engine.WorldInfo.h"
#include "UTGame.GFxMinimapHud.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class GFxTrDevices : public GFxObject
	{
	public:
		ADD_BOOL(bNeedsUpdateData, 128, 0x1)
		ADD_OBJECT(WorldInfo, ThisWorld, 124)
		ADD_OBJECT(GFxMinimapHud, HUD, 120)
		void Init(class GFxMinimapHud* H)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrDevices.Init");
			byte params[4] = { NULL };
			*(class GFxMinimapHud**)&params[0] = H;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GFxObject* GetAmmonClip()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrDevices.GetAmmonClip");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[0];
		}
		class GFxObject* GetAmmonPool()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrDevices.GetAmmonPool");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[0];
		}
		void UpdateData()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrDevices.UpdateData");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Update()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrDevices.Update");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_OBJECT
