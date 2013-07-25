#pragma once
#include "Engine__SequenceObject.h"
#include "Engine__Actor.h"
#include "Engine__SequenceVariable.h"
#include "Engine__Controller.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SequenceOp." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SequenceOp : public SequenceObject
	{
	public:
		ADD_VAR(::IntProperty, SearchTag, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ActivateCount, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, GamepadID, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PlayerIndex, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bPendingOutputConnectorRecalc, 0x100)
		ADD_VAR(::BoolProperty, bPendingInputConnectorRecalc, 0x80)
		ADD_VAR(::BoolProperty, bPendingVarConnectorRecalc, 0x40)
		ADD_VAR(::BoolProperty, bHaveMovingOutputConnector, 0x20)
		ADD_VAR(::BoolProperty, bHaveMovingInputConnector, 0x10)
		ADD_VAR(::BoolProperty, bHaveMovingVarConnector, 0x8)
		ADD_VAR(::BoolProperty, bAutoActivateOutputLinks, 0x4)
		ADD_VAR(::BoolProperty, bLatentExecution, 0x2)
		ADD_VAR(::BoolProperty, bActive, 0x1)
		void GetObjectVars(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& objVars, ScriptArray<wchar_t> inDesc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceOp.GetObjectVars");
			byte* params = (byte*)malloc(24);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = objVars;
			*(ScriptArray<wchar_t>*)(params + 12) = inDesc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			objVars = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		bool HasLinkedOps(bool bConsiderInputLinks)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceOp.HasLinkedOps");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bConsiderInputLinks;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void GetLinkedObjects(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& out_Objects, ScriptClass* ObjectType, bool bRecurse)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceOp.GetLinkedObjects");
			byte* params = (byte*)malloc(20);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = out_Objects;
			*(ScriptClass**)(params + 12) = ObjectType;
			*(bool*)(params + 16) = bRecurse;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_Objects = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		void GetInterpDataVars(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& outIData, ScriptArray<wchar_t> inDesc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceOp.GetInterpDataVars");
			byte* params = (byte*)malloc(24);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = outIData;
			*(ScriptArray<wchar_t>*)(params + 12) = inDesc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			outIData = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		void GetBoolVars(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& boolVars, ScriptArray<wchar_t> inDesc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceOp.GetBoolVars");
			byte* params = (byte*)malloc(24);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = boolVars;
			*(ScriptArray<wchar_t>*)(params + 12) = inDesc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			boolVars = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		void LinkedVariables(ScriptClass* VarClass, class SequenceVariable*& OutVariable, ScriptArray<wchar_t> inDesc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceOp.LinkedVariables");
			byte* params = (byte*)malloc(20);
			*(ScriptClass**)params = VarClass;
			*(class SequenceVariable**)(params + 4) = OutVariable;
			*(ScriptArray<wchar_t>*)(params + 8) = inDesc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutVariable = *(class SequenceVariable**)(params + 4);
			free(params);
		}
		bool ActivateOutputLink(int OutputIdx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceOp.ActivateOutputLink");
			byte* params = (byte*)malloc(8);
			*(int*)params = OutputIdx;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool ActivateNamedOutputLink(ScriptArray<wchar_t> LinkDesc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceOp.ActivateNamedOutputLink");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = LinkDesc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void Activated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceOp.Activated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Deactivated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceOp.Deactivated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void VersionUpdated(int OldVersion, int NewVersion)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceOp.VersionUpdated");
			byte* params = (byte*)malloc(8);
			*(int*)params = OldVersion;
			*(int*)(params + 4) = NewVersion;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PopulateLinkedVariableValues()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceOp.PopulateLinkedVariableValues");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PublishLinkedVariableValues()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceOp.PublishLinkedVariableValues");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceOp.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Pawn* GetPawn(class Actor* TheActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceOp.GetPawn");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = TheActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Pawn**)(params + 4);
			free(params);
			return returnVal;
		}
		class Controller* GetController(class Actor* TheActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceOp.GetController");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = TheActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Controller**)(params + 4);
			free(params);
			return returnVal;
		}
		void ForceActivateInput(int InputIdx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceOp.ForceActivateInput");
			byte* params = (byte*)malloc(4);
			*(int*)params = InputIdx;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ForceActivateOutput(int OutputIdx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceOp.ForceActivateOutput");
			byte* params = (byte*)malloc(4);
			*(int*)params = OutputIdx;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
