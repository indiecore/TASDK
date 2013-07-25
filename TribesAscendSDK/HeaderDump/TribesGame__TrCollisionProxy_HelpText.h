#pragma once
#include "TribesGame__TrCollisionProxy.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrCollisionProxy_HelpText." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrCollisionProxy_HelpText." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrCollisionProxy_HelpText : public TrCollisionProxy
	{
	public:
		ADD_VAR(::ByteProperty, m_HelpTextType, 0xFFFFFFFF)
		ADD_OBJECT(Pawn, m_LocalPawn)
		ADD_VAR(::FloatProperty, m_fHelpTextRemovalTime, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'ShouldShowHelpText_Delegate'
		// Here lies the not-yet-implemented method 'OnPawnAdded'
		// Here lies the not-yet-implemented method 'RequestHelpText'
		// Here lies the not-yet-implemented method 'TryTraceAgainTimer'
		// Here lies the not-yet-implemented method 'OnPawnRemoved'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
