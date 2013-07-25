#pragma once
#include "UTGame__UTCTFBase.h"
#include "Engine__MaterialInstanceConstant.h"
#include "Engine__Canvas.h"
#include "Engine__PlayerController.h"
#include "TribesGame__TrAnimNodeBlendList.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrCTFBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrCTFBase." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrCTFBase : public UTCTFBase
	{
	public:
		ADD_VAR(::BoolProperty, r_bIsActive, 0x1)
		ADD_VAR(::IntProperty, CTFBlitzIndex, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_MarkerMIC)
		ADD_OBJECT(TrAnimNodeBlendList, m_OpenCloseBlendList)
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'SetBlitzStandActive'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'PostRenderFor'
		// Here lies the not-yet-implemented method 'PostInitAnimTree'
		// Here lies the not-yet-implemented method 'OnFlagComesHome'
		// Here lies the not-yet-implemented method 'OnFlagTaken'
		// Here lies the not-yet-implemented method 'SpawnHelpTextCollisionProxy'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
