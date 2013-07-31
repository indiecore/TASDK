#pragma once
#include "TribesGame.TrGame_TRCTF.h"
#include "TribesGame.TrCTFBase_DiamondSword.h"
#include "TribesGame.TrCTFBase_BloodEagle.h"
#include "TribesGame.TrCTFBase.h"
#include "Engine.Controller.h"
#include "TribesGame.TrFlagBase.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrGame_TrCTFBlitz : public TrGame_TRCTF
	{
	public:
		ADD_BOOL(m_bRotateBothFlagsOnCapture, 1508, 0x1)
		ADD_OBJECT(TrCTFBase_DiamondSword, DiamondSwordFlagStands, 1488)
		ADD_OBJECT(TrCTFBase_BloodEagle, BloodEagleFlagStands, 1468)
		void ApplyServerSettings()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90692);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RegisterFlagBase(class TrCTFBase* FlagBase)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90695);
			byte params[4] = { NULL };
			*(class TrCTFBase**)params = FlagBase;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ScoreFlag(class Controller* Scorer, class TrFlagBase* theFlag)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90697);
			byte params[8] = { NULL };
			*(class Controller**)params = Scorer;
			*(class TrFlagBase**)&params[4] = theFlag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RotateFlag(class TrFlagBase* theFlag)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90700);
			byte params[4] = { NULL };
			*(class TrFlagBase**)params = theFlag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_OBJECT
