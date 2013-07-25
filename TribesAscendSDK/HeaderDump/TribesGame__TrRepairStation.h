#pragma once
#include "Engine__Texture2D.h"
#include "TribesGame__TrAnimNodeBlendList.h"
#include "TribesGame__TrStation.h"
#include "Engine__SkelControlSingleBone.h"
#include "Engine__AnimNodeSequence.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrRepairStation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrRepairStation." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrRepairStation : public TrStation
	{
	public:
		ADD_OBJECT(SkelControlSingleBone, m_RepairGunControl)
		ADD_OBJECT(TrAnimNodeBlendList, m_RepairStationBlendList)
		ADD_VAR(::FloatProperty, m_fStationOpenDelay, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bIsStationOpen, 0x1)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRepairStation.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRepairStation.PostInitAnimTree");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnAnimEnd(class AnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRepairStation.OnAnimEnd");
			byte* params = (byte*)malloc(12);
			*(class AnimNodeSequence**)params = SeqNode;
			*(float*)(params + 4) = PlayedTime;
			*(float*)(params + 8) = ExcessTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayStationEnteredEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRepairStation.PlayStationEnteredEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayStationLeftEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRepairStation.PlayStationLeftEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PawnGrabbedRepairTool()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRepairStation.PawnGrabbedRepairTool");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CloseStation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRepairStation.CloseStation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRepairStation.GetMarker");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Texture2D**)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
