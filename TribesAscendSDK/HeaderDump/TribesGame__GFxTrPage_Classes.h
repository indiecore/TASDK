#pragma once
#include "TribesGame__GFxTrPage.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_Classes." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_Classes : public GFxTrPage
	{
	public:
		ADD_VAR(::IntProperty, XPAmount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, GPAmount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PurchasingClass, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FocusedClass, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
