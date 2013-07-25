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
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCTFBase.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetBlitzStandActive(bool bActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCTFBase.SetBlitzStandActive");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bActive;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCTFBase.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCTFBase.PostRenderFor");
			byte* params = (byte*)malloc(32);
			*(class PlayerController**)params = PC;
			*(class Canvas**)(params + 4) = Canvas;
			*(Vector*)(params + 8) = CameraPosition;
			*(Vector*)(params + 20) = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCTFBase.PostInitAnimTree");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnFlagComesHome()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCTFBase.OnFlagComesHome");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnFlagTaken()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCTFBase.OnFlagTaken");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnHelpTextCollisionProxy(byte HelpTextType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCTFBase.SpawnHelpTextCollisionProxy");
			byte* params = (byte*)malloc(1);
			*params = HelpTextType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
