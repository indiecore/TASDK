#pragma once
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxUDKFrontEnd_Dialog." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxUDKFrontEnd_Dialog : public GFxUDKFrontEnd_View
	{
	public:
		ADD_OBJECT(GFxClikWidget, AcceptBtn)
		ADD_OBJECT(GFxClikWidget, BackBtn)
		ADD_OBJECT(GFxObject, InfoTxt)
		ADD_OBJECT(GFxObject, TitleTxt)
		ADD_OBJECT(GFxObject, DialogMC)
	};
}
#undef ADD_OBJECT
