#pragma once
#include "Engine.Pawn.h"
#include "Engine.InterpData.h"
#include "Engine.SequenceObject.h"
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.SequenceVariable.h"
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
	class SequenceOp : public SequenceObject
	{
	public:
		class SeqOpInputLink
		{
		public:
			ADD_BOOL(bHasImpulse, 12, 0x1)
			ADD_STRUCT(int, OverrideDelta, 44)
			ADD_BOOL(bClampedMin, 40, 0x4)
			ADD_BOOL(bClampedMax, 40, 0x2)
			ADD_BOOL(bMoving, 40, 0x1)
			ADD_STRUCT(float, ActivateDelay, 36)
			ADD_BOOL(bHidden, 32, 0x1)
			ADD_STRUCT(int, DrawY, 28)
			ADD_OBJECT(SequenceOp, LinkedOp, 24)
			ADD_BOOL(bDisabledPIE, 20, 0x2)
			ADD_BOOL(bDisabled, 20, 0x1)
			ADD_STRUCT(int, QueuedActivations, 16)
			ADD_STRUCT(ScriptString*, LinkDesc, 0)
		};
		class SeqVarLink
		{
		public:
			ADD_STRUCT(ScriptArray<class SequenceVariable*>, LinkedVariables, 4)
			ADD_STRUCT(int, OverrideDelta, 68)
			ADD_BOOL(bClampedMin, 64, 0x8)
			ADD_BOOL(bClampedMax, 64, 0x4)
			ADD_BOOL(bMoving, 64, 0x2)
			ADD_BOOL(bAllowAnyType, 64, 0x1)
			ADD_OBJECT(Property, CachedProperty, 60)
			ADD_STRUCT(int, DrawX, 56)
			ADD_STRUCT(int, MaxVars, 52)
			ADD_STRUCT(int, MinVars, 48)
			ADD_BOOL(bHidden, 44, 0x8)
			ADD_BOOL(bModifiesLinkedObject, 44, 0x4)
			ADD_BOOL(bSequenceNeverReadsOnlyWritesToThisVar, 44, 0x2)
			ADD_BOOL(bWriteable, 44, 0x1)
			ADD_STRUCT(ScriptName, PropertyName, 36)
			ADD_STRUCT(ScriptName, LinkVar, 28)
			ADD_STRUCT(ScriptString*, LinkDesc, 16)
			ADD_OBJECT(ScriptClass, ExpectedType, 0)
		};
		class SeqEventLink
		{
		public:
			ADD_STRUCT(ScriptArray<class SequenceEvent*>, LinkedEvents, 4)
			ADD_STRUCT(int, OverrideDelta, 36)
			ADD_BOOL(bClampedMin, 32, 0x8)
			ADD_BOOL(bClampedMax, 32, 0x4)
			ADD_BOOL(bMoving, 32, 0x2)
			ADD_BOOL(bHidden, 32, 0x1)
			ADD_STRUCT(int, DrawX, 28)
			ADD_STRUCT(ScriptString*, LinkDesc, 16)
			ADD_OBJECT(ScriptClass, ExpectedType, 0)
		};
		class SeqOpOutputInputLink
		{
		public:
			ADD_STRUCT(int, InputLinkIdx, 4)
			ADD_OBJECT(SequenceOp, LinkedOp, 0)
		};
		class SeqOpOutputLink
		{
		public:
			ADD_STRUCT(ScriptArray<SequenceOp::SeqOpOutputInputLink>, Links, 0)
			ADD_STRUCT(int, OverrideDelta, 44)
			ADD_BOOL(bClampedMin, 40, 0x8)
			ADD_BOOL(bClampedMax, 40, 0x4)
			ADD_BOOL(bMoving, 40, 0x2)
			ADD_BOOL(bHidden, 40, 0x1)
			ADD_STRUCT(int, DrawY, 36)
			ADD_STRUCT(float, ActivateDelay, 32)
			ADD_OBJECT(SequenceOp, LinkedOp, 28)
			ADD_BOOL(bDisabledPIE, 24, 0x4)
			ADD_BOOL(bDisabled, 24, 0x2)
			ADD_BOOL(bHasImpulse, 24, 0x1)
			ADD_STRUCT(ScriptString*, LinkDesc, 12)
		};
		ADD_STRUCT(ScriptArray<SequenceOp::SeqOpInputLink>, InputLinks, 144)
		ADD_STRUCT(ScriptArray<SequenceOp::SeqOpOutputLink>, OutputLinks, 156)
		ADD_STRUCT(ScriptArray<SequenceOp::SeqVarLink>, VariableLinks, 168)
		ADD_STRUCT(ScriptArray<SequenceOp::SeqEventLink>, EventLinks, 180)
		ADD_STRUCT(int, SearchTag, 204)
		ADD_STRUCT(int, ActivateCount, 200)
		ADD_STRUCT(byte, GamepadID, 196)
		ADD_STRUCT(int, PlayerIndex, 192)
		ADD_BOOL(bPendingOutputConnectorRecalc, 140, 0x100)
		ADD_BOOL(bPendingInputConnectorRecalc, 140, 0x80)
		ADD_BOOL(bPendingVarConnectorRecalc, 140, 0x40)
		ADD_BOOL(bHaveMovingOutputConnector, 140, 0x20)
		ADD_BOOL(bHaveMovingInputConnector, 140, 0x10)
		ADD_BOOL(bHaveMovingVarConnector, 140, 0x8)
		ADD_BOOL(bAutoActivateOutputLinks, 140, 0x4)
		ADD_BOOL(bLatentExecution, 140, 0x2)
		ADD_BOOL(bActive, 140, 0x1)
		void GetObjectVars(ScriptArray<class Object*>& objVars, ScriptString* inDesc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceOp.GetObjectVars");
			byte params[24] = { NULL };
			*(ScriptArray<class Object*>*)&params[0] = objVars;
			*(ScriptString**)&params[12] = inDesc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			objVars = *(ScriptArray<class Object*>*)&params[0];
		}
		bool HasLinkedOps(bool bConsiderInputLinks)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceOp.HasLinkedOps");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bConsiderInputLinks;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void GetLinkedObjects(ScriptArray<class SequenceObject*>& out_Objects, ScriptClass* ObjectType, bool bRecurse)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceOp.GetLinkedObjects");
			byte params[20] = { NULL };
			*(ScriptArray<class SequenceObject*>*)&params[0] = out_Objects;
			*(ScriptClass**)&params[12] = ObjectType;
			*(bool*)&params[16] = bRecurse;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Objects = *(ScriptArray<class SequenceObject*>*)&params[0];
		}
		void GetInterpDataVars(ScriptArray<class InterpData*>& outIData, ScriptString* inDesc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceOp.GetInterpDataVars");
			byte params[24] = { NULL };
			*(ScriptArray<class InterpData*>*)&params[0] = outIData;
			*(ScriptString**)&params[12] = inDesc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			outIData = *(ScriptArray<class InterpData*>*)&params[0];
		}
		void GetBoolVars(ScriptArray<byte>& boolVars, ScriptString* inDesc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceOp.GetBoolVars");
			byte params[24] = { NULL };
			*(ScriptArray<byte>*)&params[0] = boolVars;
			*(ScriptString**)&params[12] = inDesc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			boolVars = *(ScriptArray<byte>*)&params[0];
		}
		void LinkedVariables(ScriptClass* VarClass, class SequenceVariable*& OutVariable, ScriptString* inDesc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceOp.LinkedVariables");
			byte params[20] = { NULL };
			*(ScriptClass**)&params[0] = VarClass;
			*(class SequenceVariable**)&params[4] = OutVariable;
			*(ScriptString**)&params[8] = inDesc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutVariable = *(class SequenceVariable**)&params[4];
		}
		bool ActivateOutputLink(int OutputIdx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceOp.ActivateOutputLink");
			byte params[8] = { NULL };
			*(int*)&params[0] = OutputIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ActivateNamedOutputLink(ScriptString* LinkDesc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceOp.ActivateNamedOutputLink");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = LinkDesc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
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
			byte params[8] = { NULL };
			*(int*)&params[0] = OldVersion;
			*(int*)&params[4] = NewVersion;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = TheActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Pawn**)&params[4];
		}
		class Controller* GetController(class Actor* TheActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceOp.GetController");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = TheActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Controller**)&params[4];
		}
		void ForceActivateInput(int InputIdx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceOp.ForceActivateInput");
			byte params[4] = { NULL };
			*(int*)&params[0] = InputIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ForceActivateOutput(int OutputIdx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceOp.ForceActivateOutput");
			byte params[4] = { NULL };
			*(int*)&params[0] = OutputIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
