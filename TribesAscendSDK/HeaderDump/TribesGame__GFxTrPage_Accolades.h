#pragma once
#include "TribesGame__GFxTrPage.h"
#include "TribesGame__GFxTrAction.h"
#include "GFxUI__GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_Accolades." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_Accolades : public GFxTrPage
	{
	public:
		ADD_VAR(::IntProperty, AccoladeType, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'SpecialAction'
		// Here lies the not-yet-implemented method 'TakeAction'
		// Here lies the not-yet-implemented method 'ShowModel'
		// Here lies the not-yet-implemented method 'TakeFocus'
		// Here lies the not-yet-implemented method 'FillData'
		// Here lies the not-yet-implemented method 'FillAccolades'
		// Here lies the not-yet-implemented method 'FillAccolade'
		// Here lies the not-yet-implemented method 'GetAccoladeClass'
	};
}
#undef ADD_VAR
