#pragma once
#include "GFxUI.GFxClikWidget.h"
#include "GFxUI.GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.GFxUI_InventoryButton." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxUI_InventoryButton." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxUI_InventoryButton : public GFxClikWidget
	{
	public:
		ADD_OBJECT(GFxObject, IconMC)
		ADD_VAR(::StrProperty, Content, 0xFFFFFFFF)
		void SetContent(ScriptArray<wchar_t> newContent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUI_InventoryButton.SetContent");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = newContent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetIconMC(class GFxObject* iconClip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUI_InventoryButton.SetIconMC");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = iconClip;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
