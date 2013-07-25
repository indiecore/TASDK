#pragma once
#include "GFxUI.GFxObject.h"
#include "Engine.WorldInfo.h"
#include "UTGame.GFxMinimapHud.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrDevices." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.GFxTrDevices." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxTrDevices : public GFxObject
	{
	public:
		ADD_VAR(::BoolProperty, bNeedsUpdateData, 0x1)
		ADD_OBJECT(WorldInfo, ThisWorld)
		ADD_OBJECT(GFxMinimapHud, HUD)
		void Init(class GFxMinimapHud* H)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrDevices.Init");
			byte* params = (byte*)malloc(4);
			*(class GFxMinimapHud**)params = H;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class GFxObject* GetAmmonClip()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrDevices.GetAmmonClip");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)params;
			free(params);
			return returnVal;
		}
		class GFxObject* GetAmmonPool()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrDevices.GetAmmonPool");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)params;
			free(params);
			return returnVal;
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
#undef ADD_VAR
#undef ADD_OBJECT
