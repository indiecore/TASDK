#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.GFxUDKFrontEnd_MainMenu." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxUDKFrontEnd_MainMenu." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxUDKFrontEnd_MainMenu : public GFxUDKFrontEnd_Screen
	{
	public:
		ADD_OBJECT(GFxClikWidget, ListMC)
		ADD_VAR(::ByteProperty, LastSelectedIndex, 0xFFFFFFFF)
		ADD_OBJECT(GFxObject, UserNameTxt)
		ADD_OBJECT(GFxObject, UserLabelTxt)
		ADD_OBJECT(GFxObject, ListDataProvider)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
