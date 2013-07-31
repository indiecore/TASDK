#pragma once
#include "UTGame.UTCTFBase.h"
#include "TribesGame.TrAnimNodeBlendList.h"
#include "Engine.MaterialInstanceConstant.h"
#include "Engine.PlayerController.h"
#include "Engine.Canvas.h"
#include "Core.Object.h"
#include "TribesGame.TrHelpTextManager.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrCTFBase : public UTCTFBase
	{
	public:
		ADD_BOOL(r_bIsActive, 1128, 0x1)
		ADD_STRUCT(int, CTFBlitzIndex, 1124)
		ADD_OBJECT(MaterialInstanceConstant, m_MarkerMIC, 1120)
		ADD_OBJECT(TrAnimNodeBlendList, m_OpenCloseBlendList, 1116)
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78248);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBlitzStandActive(bool bActive)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78250);
			byte params[4] = { NULL };
			*(bool*)params = bActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78252);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78255);
			byte params[32] = { NULL };
			*(class PlayerController**)params = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Vector*)&params[8] = CameraPosition;
			*(Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78265);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFlagComesHome()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78267);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnFlagTaken()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78268);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnHelpTextCollisionProxy(TrHelpTextManager::EHelpTextType HelpTextType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78269);
			byte params[1] = { NULL };
			*(TrHelpTextManager::EHelpTextType*)params = HelpTextType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
