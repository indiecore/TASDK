#pragma once
#include "Engine__TranslationContext.h"
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GFxUI.GFxObject." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxObject : public Object
	{
	public:
		ADD_VAR(::IntProperty, Value, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'Get'
		// Here lies the not-yet-implemented method 'GetBool'
		// Here lies the not-yet-implemented method 'GetFloat'
		// Here lies the not-yet-implemented method 'GetString'
		// Here lies the not-yet-implemented method 'GetObject'
		// Here lies the not-yet-implemented method 'Set'
		// Here lies the not-yet-implemented method 'SetBool'
		// Here lies the not-yet-implemented method 'SetFloat'
		// Here lies the not-yet-implemented method 'SetString'
		// Here lies the not-yet-implemented method 'SetObject'
		// Here lies the not-yet-implemented method 'SetFunction'
		// Here lies the not-yet-implemented method 'TranslateString'
		// Here lies the not-yet-implemented method 'GetDisplayInfo'
		// Here lies the not-yet-implemented method 'GetPosition'
		// Here lies the not-yet-implemented method 'GetColorTransform'
		// Here lies the not-yet-implemented method 'GetDisplayMatrix'
		// Here lies the not-yet-implemented method 'SetDisplayInfo'
		// Here lies the not-yet-implemented method 'SetPosition'
		// Here lies the not-yet-implemented method 'SetColorTransform'
		// Here lies the not-yet-implemented method 'SetDisplayMatrix'
		// Here lies the not-yet-implemented method 'SetDisplayMatrix3D'
		// Here lies the not-yet-implemented method 'SetVisible'
		// Here lies the not-yet-implemented method 'GetText'
		// Here lies the not-yet-implemented method 'SetText'
		// Here lies the not-yet-implemented method 'GetElement'
		// Here lies the not-yet-implemented method 'GetElementObject'
		// Here lies the not-yet-implemented method 'GetElementBool'
		// Here lies the not-yet-implemented method 'GetElementFloat'
		// Here lies the not-yet-implemented method 'GetElementString'
		// Here lies the not-yet-implemented method 'SetElement'
		// Here lies the not-yet-implemented method 'SetElementObject'
		// Here lies the not-yet-implemented method 'SetElementBool'
		// Here lies the not-yet-implemented method 'SetElementFloat'
		// Here lies the not-yet-implemented method 'SetElementString'
		// Here lies the not-yet-implemented method 'GetElementDisplayInfo'
		// Here lies the not-yet-implemented method 'GetElementDisplayMatrix'
		// Here lies the not-yet-implemented method 'SetElementDisplayInfo'
		// Here lies the not-yet-implemented method 'SetElementDisplayMatrix'
		// Here lies the not-yet-implemented method 'SetElementVisible'
		// Here lies the not-yet-implemented method 'SetElementPosition'
		// Here lies the not-yet-implemented method 'SetElementColorTransform'
		// Here lies the not-yet-implemented method 'GetElementMember'
		// Here lies the not-yet-implemented method 'GetElementMemberObject'
		// Here lies the not-yet-implemented method 'GetElementMemberBool'
		// Here lies the not-yet-implemented method 'GetElementMemberFloat'
		// Here lies the not-yet-implemented method 'GetElementMemberString'
		// Here lies the not-yet-implemented method 'SetElementMember'
		// Here lies the not-yet-implemented method 'SetElementMemberObject'
		// Here lies the not-yet-implemented method 'SetElementMemberBool'
		// Here lies the not-yet-implemented method 'SetElementMemberFloat'
		// Here lies the not-yet-implemented method 'SetElementMemberString'
		// Here lies the not-yet-implemented method 'ActionScriptSetFunction'
		// Here lies the not-yet-implemented method 'ActionScriptSetFunctionOn'
		// Here lies the not-yet-implemented method 'Invoke'
		// Here lies the not-yet-implemented method 'ActionScriptVoid'
		// Here lies the not-yet-implemented method 'ActionScriptInt'
		// Here lies the not-yet-implemented method 'ActionScriptFloat'
		// Here lies the not-yet-implemented method 'ActionScriptString'
		// Here lies the not-yet-implemented method 'ActionScriptObject'
		// Here lies the not-yet-implemented method 'ActionScriptArray'
		// Here lies the not-yet-implemented method 'GotoAndPlay'
		// Here lies the not-yet-implemented method 'GotoAndPlayI'
		// Here lies the not-yet-implemented method 'GotoAndStop'
		// Here lies the not-yet-implemented method 'GotoAndStopI'
		// Here lies the not-yet-implemented method 'CreateEmptyMovieClip'
		// Here lies the not-yet-implemented method 'AttachMovie'
		// Here lies the not-yet-implemented method 'WidgetInitialized'
		// Here lies the not-yet-implemented method 'WidgetUnloaded'
	};
}
#undef ADD_VAR
