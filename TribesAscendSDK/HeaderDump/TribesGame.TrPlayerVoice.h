#pragma once
#include "TribesGame.TrDevice.h"
#include "TribesGame.TrPlayerController.h"
#include "TribesGame.TrVGSCommandList.h"
#include "Engine.SoundCue.h"
#include "Engine.PlayerReplicationInfo.h"
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
	class TrPlayerVoice : public TrDevice
	{
	public:
		class VGSCommandToVoiceMap
		{
		public:
			ADD_OBJECT(SoundCue, Sound, 4)
			ADD_STRUCT(TrVGSCommandList::VGSCommandType, Command, 0)
		};
		class VGSContextCommandToVoiceMap
		{
		public:
			ADD_OBJECT(SoundCue, Sound, 8)
			ADD_BOOL(bIsEnemyLocation, 4, 0x1)
			ADD_STRUCT(TrVGSCommandList::EVGSContextLocation, ContextLocation, 1)
			ADD_STRUCT(TrVGSCommandList::EVGSContextActor, ContextActor, 0)
		};
		ADD_STRUCT(ScriptArray<TrPlayerVoice::VGSCommandToVoiceMap>, m_VGSCommandToVoiceMap, 2148)
		ADD_STRUCT(ScriptArray<class SoundCue*>, m_VGSSampleMap, 2160)
		ADD_STRUCT(ScriptArray<TrPlayerVoice::VGSContextCommandToVoiceMap>, m_VGSContextCommandToVoiceMap, 2172)
		void PlaySoundEx(TrVGSCommandList::VGSCommandType Command, class TrPlayerController* TrPC, class PlayerReplicationInfo* InstigatorPRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerVoice.PlaySoundEx");
			byte params[9] = { NULL };
			*(TrVGSCommandList::VGSCommandType*)&params[0] = Command;
			*(class TrPlayerController**)&params[4] = TrPC;
			*(class PlayerReplicationInfo**)&params[8] = InstigatorPRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlaySoundContext(class TrPlayerController* TrPC, TrVGSCommandList::EVGSContextActor ContextActor, TrVGSCommandList::EVGSContextLocation ContextLocation, bool bEnemyLocation, class PlayerReplicationInfo* InstigatorPRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerVoice.PlaySoundContext");
			byte params[14] = { NULL };
			*(class TrPlayerController**)&params[0] = TrPC;
			*(TrVGSCommandList::EVGSContextActor*)&params[4] = ContextActor;
			*(TrVGSCommandList::EVGSContextLocation*)&params[5] = ContextLocation;
			*(bool*)&params[8] = bEnemyLocation;
			*(class PlayerReplicationInfo**)&params[12] = InstigatorPRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayRandomSample(class TrPlayerController* TrPC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerVoice.PlayRandomSample");
			byte params[4] = { NULL };
			*(class TrPlayerController**)&params[0] = TrPC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
