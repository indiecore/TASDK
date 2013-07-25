#pragma once
#include "TribesGame__TrDeployable.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDeployable_BackupGenerator." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDeployable_BackupGenerator : public TrDeployable
	{
	public:
		ADD_OBJECT(TrGameObjective, m_PoweredFriend)
	};
}
#undef ADD_OBJECT
