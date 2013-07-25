#pragma once
#include "TribesGame__TrCTFBase_BloodEagle.h"
#include "TribesGame__TrGame_TRCTF.h"
#include "Engine__Controller.h"
#include "TribesGame__TrCTFBase_DiamondSword.h"
#include "TribesGame__TrCTFBase.h"
#include "TribesGame__TrFlagBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrGame_TrCTFBlitz." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrGame_TrCTFBlitz." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrGame_TrCTFBlitz : public TrGame_TRCTF
	{
	public:
		ADD_VAR(::BoolProperty, m_bRotateBothFlagsOnCapture, 0x1)
		ADD_OBJECT(TrCTFBase_DiamondSword, DiamondSwordFlagStands)
		ADD_OBJECT(TrCTFBase_BloodEagle, BloodEagleFlagStands)
		void ApplyServerSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCTFBlitz.ApplyServerSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RegisterFlagBase(class TrCTFBase* FlagBase)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCTFBlitz.RegisterFlagBase");
			byte* params = (byte*)malloc(4);
			*(class TrCTFBase**)params = FlagBase;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ScoreFlag(class Controller* Scorer, class TrFlagBase* theFlag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCTFBlitz.ScoreFlag");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = Scorer;
			*(class TrFlagBase**)(params + 4) = theFlag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RotateFlag(class TrFlagBase* theFlag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCTFBlitz.RotateFlag");
			byte* params = (byte*)malloc(4);
			*(class TrFlagBase**)params = theFlag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
