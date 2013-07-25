#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Core.Object." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Core.Object." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Core.Object." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Object
	{
	public:
		ADD_OBJECT(Object, Outer)
		ADD_VAR(::NameProperty, Name, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTableObject'!
		ADD_VAR(::IntProperty, ObjectInternalInteger, 0xFFFFFFFF)
		ADD_STRUCT(::QWordProperty, ObjectFlags, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'HashNext'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'HashOuterNext'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'StateFrame'!
		ADD_OBJECT(Object, Linker)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'LinkerIndex'!
		ADD_VAR(::IntProperty, NetIndex, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, Class)
		ADD_OBJECT(Object, ObjectArchetype)
		int GetBuildChangelistNumber()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetBuildChangelistNumber");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		int GetEngineVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetEngineVersion");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void GetSystemTime(int& Year, int& Month, int& DayOfWeek, int& Day, int& Hour, int& Min, int& Sec, int& MSec)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetSystemTime");
			byte* params = (byte*)malloc(32);
			*(int*)params = Year;
			*(int*)(params + 4) = Month;
			*(int*)(params + 8) = DayOfWeek;
			*(int*)(params + 12) = Day;
			*(int*)(params + 16) = Hour;
			*(int*)(params + 20) = Min;
			*(int*)(params + 24) = Sec;
			*(int*)(params + 28) = MSec;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Year = *(int*)params;
			Month = *(int*)(params + 4);
			DayOfWeek = *(int*)(params + 8);
			Day = *(int*)(params + 12);
			Hour = *(int*)(params + 16);
			Min = *(int*)(params + 20);
			Sec = *(int*)(params + 24);
			MSec = *(int*)(params + 28);
			free(params);
		}
		ScriptArray<wchar_t> TimeStamp()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.TimeStamp");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		Vector TransformVectorByRotation(Rotator SourceRotation, Vector SourceVector, bool bInverse)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.TransformVectorByRotation");
			byte* params = (byte*)malloc(40);
			*(Rotator*)params = SourceRotation;
			*(Vector*)(params + 12) = SourceVector;
			*(bool*)(params + 24) = bInverse;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 28);
			free(params);
			return returnVal;
		}
		ScriptName GetPackageName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetPackageName");
			byte* params = (byte*)malloc(8);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)params;
			free(params);
			return returnVal;
		}
		bool IsPendingKill()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.IsPendingKill");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		float ByteToFloat(byte inputByte, bool bSigned)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ByteToFloat");
			byte* params = (byte*)malloc(9);
			*params = inputByte;
			*(bool*)(params + 4) = bSigned;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		byte FloatToByte(float inputFloat, bool bSigned)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.FloatToByte");
			byte* params = (byte*)malloc(9);
			*(float*)params = inputFloat;
			*(bool*)(params + 4) = bSigned;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 8);
			free(params);
			return returnVal;
		}
		float UnwindHeading(float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.UnwindHeading");
			byte* params = (byte*)malloc(8);
			*(float*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		float FindDeltaAngle(float A1, float A2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.FindDeltaAngle");
			byte* params = (byte*)malloc(12);
			*(float*)params = A1;
			*(float*)(params + 4) = A2;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		float GetHeadingAngle(Vector Dir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetHeadingAngle");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = Dir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		void GetAngularDegreesFromRadians(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void*& OutFOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetAngularDegreesFromRadians");
			byte* params = (byte*)malloc(8);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)params = OutFOV;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutFOV = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)params;
			free(params);
		}
		float Acos(float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Acos");
			byte* params = (byte*)malloc(8);
			*(float*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		void GetAngularFromDotDist(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void*& OutAngDist, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* DotDist)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetAngularFromDotDist");
			byte* params = (byte*)malloc(16);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)params = OutAngDist;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 8) = DotDist;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutAngDist = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)params;
			free(params);
		}
		bool GetAngularDistance(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void*& OutAngularDist, Vector Direction, Vector AxisX, Vector AxisY, Vector AxisZ)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetAngularDistance");
			byte* params = (byte*)malloc(60);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)params = OutAngularDist;
			*(Vector*)(params + 8) = Direction;
			*(Vector*)(params + 20) = AxisX;
			*(Vector*)(params + 32) = AxisY;
			*(Vector*)(params + 44) = AxisZ;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutAngularDist = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)params;
			auto returnVal = *(bool*)(params + 56);
			free(params);
			return returnVal;
		}
		bool GetDotDistance(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void*& OutDotDist, Vector Direction, Vector AxisX, Vector AxisY, Vector AxisZ)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetDotDistance");
			byte* params = (byte*)malloc(60);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)params = OutDotDist;
			*(Vector*)(params + 8) = Direction;
			*(Vector*)(params + 20) = AxisX;
			*(Vector*)(params + 32) = AxisY;
			*(Vector*)(params + 44) = AxisZ;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutDotDist = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)params;
			auto returnVal = *(bool*)(params + 56);
			free(params);
			return returnVal;
		}
		Vector PointProjectToPlane(Vector Point, Vector A, Vector B, Vector C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.PointProjectToPlane");
			byte* params = (byte*)malloc(60);
			*(Vector*)params = Point;
			*(Vector*)(params + 12) = A;
			*(Vector*)(params + 24) = B;
			*(Vector*)(params + 36) = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 48);
			free(params);
			return returnVal;
		}
		float PointDistToPlane(Vector Point, Rotator Orientation, Vector Origin, Vector& out_ClosestPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.PointDistToPlane");
			byte* params = (byte*)malloc(52);
			*(Vector*)params = Point;
			*(Rotator*)(params + 12) = Orientation;
			*(Vector*)(params + 24) = Origin;
			*(Vector*)(params + 36) = out_ClosestPoint;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_ClosestPoint = *(Vector*)(params + 36);
			auto returnVal = *(float*)(params + 48);
			free(params);
			return returnVal;
		}
		float PointDistToSegment(Vector Point, Vector StartPoint, Vector EndPoint, Vector& OutClosestPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.PointDistToSegment");
			byte* params = (byte*)malloc(52);
			*(Vector*)params = Point;
			*(Vector*)(params + 12) = StartPoint;
			*(Vector*)(params + 24) = EndPoint;
			*(Vector*)(params + 36) = OutClosestPoint;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutClosestPoint = *(Vector*)(params + 36);
			auto returnVal = *(float*)(params + 48);
			free(params);
			return returnVal;
		}
		float PointDistToLine(Vector Point, Vector Line, Vector Origin, Vector& OutClosestPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.PointDistToLine");
			byte* params = (byte*)malloc(52);
			*(Vector*)params = Point;
			*(Vector*)(params + 12) = Line;
			*(Vector*)(params + 24) = Origin;
			*(Vector*)(params + 36) = OutClosestPoint;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutClosestPoint = *(Vector*)(params + 36);
			auto returnVal = *(float*)(params + 48);
			free(params);
			return returnVal;
		}
		bool GetPerObjectConfigSections(ScriptClass* SearchClass, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& out_SectionNames, class Object* ObjectOuter, int MaxResults)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetPerObjectConfigSections");
			byte* params = (byte*)malloc(28);
			*(ScriptClass**)params = SearchClass;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = out_SectionNames;
			*(class Object**)(params + 16) = ObjectOuter;
			*(int*)(params + 20) = MaxResults;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_SectionNames = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		void StaticSaveConfig()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.StaticSaveConfig");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SaveConfig()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.SaveConfig");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Object* FindObject(ScriptArray<wchar_t> ObjectName, ScriptClass* ObjectClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.FindObject");
			byte* params = (byte*)malloc(20);
			*(ScriptArray<wchar_t>*)params = ObjectName;
			*(ScriptClass**)(params + 12) = ObjectClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Object**)(params + 16);
			free(params);
			return returnVal;
		}
		class Object* DynamicLoadObject(ScriptArray<wchar_t> ObjectName, ScriptClass* ObjectClass, bool MayFail)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.DynamicLoadObject");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = ObjectName;
			*(ScriptClass**)(params + 12) = ObjectClass;
			*(bool*)(params + 16) = MayFail;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Object**)(params + 20);
			free(params);
			return returnVal;
		}
		ScriptName GetEnum(class Object* E, int I)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetEnum");
			byte* params = (byte*)malloc(16);
			*(class Object**)params = E;
			*(int*)(params + 4) = I;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)(params + 8);
			free(params);
			return returnVal;
		}
		void Disable(ScriptName ProbeFunc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Disable");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = ProbeFunc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Enable(ScriptName ProbeFunc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Enable");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = ProbeFunc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ContinuedState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ContinuedState");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PausedState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.PausedState");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PoppedState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.PoppedState");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PushedState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.PushedState");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EndState(ScriptName NextStateName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.EndState");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = NextStateName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BeginState(ScriptName PreviousStateName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.BeginState");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = PreviousStateName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DumpStateStack()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.DumpStateStack");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PopState(bool bPopAll)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.PopState");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bPopAll;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PushState(ScriptName NewState, ScriptName NewLabel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.PushState");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = NewState;
			*(ScriptName*)(params + 8) = NewLabel;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptName GetStateName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetStateName");
			byte* params = (byte*)malloc(8);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)params;
			free(params);
			return returnVal;
		}
		bool IsChildState(ScriptName TestState, ScriptName TestParentState)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.IsChildState");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = TestState;
			*(ScriptName*)(params + 8) = TestParentState;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool IsInState(ScriptName TestState, bool bTestStateStack)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.IsInState");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = TestState;
			*(bool*)(params + 8) = bTestStateStack;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void GotoState(ScriptName NewState, ScriptName Label, bool bForceEvents, bool bKeepStack)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GotoState");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = NewState;
			*(ScriptName*)(params + 8) = Label;
			*(bool*)(params + 16) = bForceEvents;
			*(bool*)(params + 20) = bKeepStack;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsUTracing()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.IsUTracing");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SetUTracing(bool bShouldUTrace)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.SetUTracing");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bShouldUTrace;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptName GetFuncName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetFuncName");
			byte* params = (byte*)malloc(8);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)params;
			free(params);
			return returnVal;
		}
		void DebugBreak(int UserFlags, byte DebuggerType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.DebugBreak");
			byte* params = (byte*)malloc(5);
			*(int*)params = UserFlags;
			*(params + 4) = DebuggerType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetScriptTrace()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetScriptTrace");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		void ScriptTrace()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ScriptTrace");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptArray<wchar_t> ParseLocalizedPropertyPath(ScriptArray<wchar_t> PathName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ParseLocalizedPropertyPath");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = PathName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> Localize(ScriptArray<wchar_t> SectionName, ScriptArray<wchar_t> KeyName, ScriptArray<wchar_t> PackageName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Localize");
			byte* params = (byte*)malloc(48);
			*(ScriptArray<wchar_t>*)params = SectionName;
			*(ScriptArray<wchar_t>*)(params + 12) = KeyName;
			*(ScriptArray<wchar_t>*)(params + 24) = PackageName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 36);
			free(params);
			return returnVal;
		}
		void ParseStringIntoArray(ScriptArray<wchar_t> BaseString, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Pieces, ScriptArray<wchar_t> delim, bool bCullEmpty)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ParseStringIntoArray");
			byte* params = (byte*)malloc(40);
			*(ScriptArray<wchar_t>*)params = BaseString;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 12) = Pieces;
			*(ScriptArray<wchar_t>*)(params + 24) = delim;
			*(bool*)(params + 36) = bCullEmpty;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Pieces = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 12);
			free(params);
		}
		void WarnInternal(ScriptArray<wchar_t> S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.WarnInternal");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = S;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LogInternal(ScriptArray<wchar_t> S, ScriptName Tag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.LogInternal");
			byte* params = (byte*)malloc(20);
			*(ScriptArray<wchar_t>*)params = S;
			*(ScriptName*)(params + 12) = Tag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void* Subtract_LinearColorLinearColor(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void* A, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Subtract_LinearColorLinearColor");
			byte* params = (byte*)malloc(48);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void**)params = A;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void**)(params + 16) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void**)(params + 32);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void* Multiply_LinearColorFloat(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void* LC, float Mult)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Multiply_LinearColorFloat");
			byte* params = (byte*)malloc(36);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void**)params = LC;
			*(float*)(params + 16) = Mult;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void**)(params + 20);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void* ColorToLinearColor(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* OldColor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ColorToLinearColor");
			byte* params = (byte*)malloc(20);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)params = OldColor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void**)(params + 4);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void* MakeLinearColor(float R, float G, float B, float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MakeLinearColor");
			byte* params = (byte*)malloc(32);
			*(float*)params = R;
			*(float*)(params + 4) = G;
			*(float*)(params + 8) = B;
			*(float*)(params + 12) = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void**)(params + 16);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* LerpColor(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* A, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* B, float Alpha)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.LerpColor");
			byte* params = (byte*)malloc(16);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)params = A;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 4) = B;
			*(float*)(params + 8) = Alpha;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 12);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* MakeColor(byte R, byte G, byte B, byte A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MakeColor");
			byte* params = (byte*)malloc(8);
			*params = R;
			*(params + 1) = G;
			*(params + 2) = B;
			*(params + 3) = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 4);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* Add_ColorColor(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* A, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Add_ColorColor");
			byte* params = (byte*)malloc(12);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)params = A;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 8);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* Multiply_ColorFloat(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Multiply_ColorFloat");
			byte* params = (byte*)malloc(12);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)params = A;
			*(float*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 8);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* Multiply_FloatColor(float A, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Multiply_FloatColor");
			byte* params = (byte*)malloc(12);
			*(float*)params = A;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 8);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* Subtract_ColorColor(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* A, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Subtract_ColorColor");
			byte* params = (byte*)malloc(12);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)params = A;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 8);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* EvalInterpCurveVector2D(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.InterpCurveVector2D'!
void* Vector2DCurve, float InVal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.EvalInterpCurveVector2D");
			byte* params = (byte*)malloc(28);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.InterpCurveVector2D'!
void**)params = Vector2DCurve;
			*(float*)(params + 16) = InVal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 20);
			free(params);
			return returnVal;
		}
		Vector EvalInterpCurveVector(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.InterpCurveVector'!
void* VectorCurve, float InVal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.EvalInterpCurveVector");
			byte* params = (byte*)malloc(32);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.InterpCurveVector'!
void**)params = VectorCurve;
			*(float*)(params + 16) = InVal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 20);
			free(params);
			return returnVal;
		}
		float EvalInterpCurveFloat(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.InterpCurveFloat'!
void* FloatCurve, float InVal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.EvalInterpCurveFloat");
			byte* params = (byte*)malloc(24);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.InterpCurveFloat'!
void**)params = FloatCurve;
			*(float*)(params + 16) = InVal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 20);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* vect2d(float InX, float InY)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.vect2d");
			byte* params = (byte*)malloc(16);
			*(float*)params = InX;
			*(float*)(params + 4) = InY;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 8);
			free(params);
			return returnVal;
		}
		float GetMappedRangeValue(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* InputRange, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* OutputRange, float Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetMappedRangeValue");
			byte* params = (byte*)malloc(24);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)params = InputRange;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 8) = OutputRange;
			*(float*)(params + 16) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 20);
			free(params);
			return returnVal;
		}
		float GetRangePctByValue(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* Range, float Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetRangePctByValue");
			byte* params = (byte*)malloc(16);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)params = Range;
			*(float*)(params + 8) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		float GetRangeValueByPct(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* Range, float Pct)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetRangeValueByPct");
			byte* params = (byte*)malloc(16);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)params = Range;
			*(float*)(params + 8) = Pct;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* SubtractEqual_Vector2DVector2D(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void*& A, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.SubtractEqual_Vector2DVector2D");
			byte* params = (byte*)malloc(24);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)params = A;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 8) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)params;
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 16);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* AddEqual_Vector2DVector2D(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void*& A, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.AddEqual_Vector2DVector2D");
			byte* params = (byte*)malloc(24);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)params = A;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 8) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)params;
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 16);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* DivideEqual_Vector2DFloat(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void*& A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.DivideEqual_Vector2DFloat");
			byte* params = (byte*)malloc(20);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)params = A;
			*(float*)(params + 8) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)params;
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 12);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* MultiplyEqual_Vector2DFloat(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void*& A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MultiplyEqual_Vector2DFloat");
			byte* params = (byte*)malloc(20);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)params = A;
			*(float*)(params + 8) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)params;
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 12);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* Divide_Vector2DFloat(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Divide_Vector2DFloat");
			byte* params = (byte*)malloc(20);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)params = A;
			*(float*)(params + 8) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 12);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* Multiply_Vector2DFloat(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Multiply_Vector2DFloat");
			byte* params = (byte*)malloc(20);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)params = A;
			*(float*)(params + 8) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 12);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* Subtract_Vector2DVector2D(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* A, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Subtract_Vector2DVector2D");
			byte* params = (byte*)malloc(24);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)params = A;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 8) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 16);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* Add_Vector2DVector2D(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* A, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Add_Vector2DVector2D");
			byte* params = (byte*)malloc(24);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)params = A;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 8) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 16);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void* Subtract_QuatQuat(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void* A, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Subtract_QuatQuat");
			byte* params = (byte*)malloc(48);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void**)params = A;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void**)(params + 16) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void**)(params + 32);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void* Add_QuatQuat(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void* A, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Add_QuatQuat");
			byte* params = (byte*)malloc(48);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void**)params = A;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void**)(params + 16) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void**)(params + 32);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void* QuatSlerp(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void* A, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void* B, float Alpha, bool bShortestPath)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.QuatSlerp");
			byte* params = (byte*)malloc(56);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void**)params = A;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void**)(params + 16) = B;
			*(float*)(params + 32) = Alpha;
			*(bool*)(params + 36) = bShortestPath;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void**)(params + 48);
			free(params);
			return returnVal;
		}
		Rotator QuatToRotator(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void* A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.QuatToRotator");
			byte* params = (byte*)malloc(28);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void**)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 16);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void* QuatFromRotator(Rotator A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.QuatFromRotator");
			byte* params = (byte*)malloc(28);
			*(Rotator*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void**)(params + 16);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void* QuatFromAxisAndAngle(Vector Axis, float Angle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.QuatFromAxisAndAngle");
			byte* params = (byte*)malloc(32);
			*(Vector*)params = Axis;
			*(float*)(params + 12) = Angle;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void**)(params + 16);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void* QuatFindBetween(Vector A, Vector B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.QuatFindBetween");
			byte* params = (byte*)malloc(40);
			*(Vector*)params = A;
			*(Vector*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void**)(params + 32);
			free(params);
			return returnVal;
		}
		Vector QuatRotateVector(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void* A, Vector B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.QuatRotateVector");
			byte* params = (byte*)malloc(40);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void**)params = A;
			*(Vector*)(params + 16) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 28);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void* QuatInvert(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void* A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.QuatInvert");
			byte* params = (byte*)malloc(32);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void**)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void**)(params + 16);
			free(params);
			return returnVal;
		}
		float QuatDot(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void* A, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.QuatDot");
			byte* params = (byte*)malloc(36);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void**)params = A;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void**)(params + 16) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 32);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void* QuatProduct(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void* A, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.QuatProduct");
			byte* params = (byte*)malloc(48);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void**)params = A;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void**)(params + 16) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void**)(params + 32);
			free(params);
			return returnVal;
		}
		Vector MatrixGetAxis(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void* TM, byte Axis)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MatrixGetAxis");
			byte* params = (byte*)malloc(77);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void**)params = TM;
			*(params + 64) = Axis;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 68);
			free(params);
			return returnVal;
		}
		Vector MatrixGetOrigin(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void* TM)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MatrixGetOrigin");
			byte* params = (byte*)malloc(76);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void**)params = TM;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 64);
			free(params);
			return returnVal;
		}
		Rotator MatrixGetRotator(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void* TM)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MatrixGetRotator");
			byte* params = (byte*)malloc(76);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void**)params = TM;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 64);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void* MakeRotationMatrix(Rotator Rotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MakeRotationMatrix");
			byte* params = (byte*)malloc(76);
			*(Rotator*)params = Rotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void**)(params + 16);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void* MakeRotationTranslationMatrix(Vector Translation, Rotator Rotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MakeRotationTranslationMatrix");
			byte* params = (byte*)malloc(88);
			*(Vector*)params = Translation;
			*(Rotator*)(params + 12) = Rotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void**)(params + 32);
			free(params);
			return returnVal;
		}
		Vector InverseTransformNormal(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void* TM, Vector A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.InverseTransformNormal");
			byte* params = (byte*)malloc(88);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void**)params = TM;
			*(Vector*)(params + 64) = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 76);
			free(params);
			return returnVal;
		}
		Vector TransformNormal(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void* TM, Vector A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.TransformNormal");
			byte* params = (byte*)malloc(88);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void**)params = TM;
			*(Vector*)(params + 64) = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 76);
			free(params);
			return returnVal;
		}
		Vector InverseTransformVector(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void* TM, Vector A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.InverseTransformVector");
			byte* params = (byte*)malloc(88);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void**)params = TM;
			*(Vector*)(params + 64) = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 76);
			free(params);
			return returnVal;
		}
		Vector TransformVector(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void* TM, Vector A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.TransformVector");
			byte* params = (byte*)malloc(88);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void**)params = TM;
			*(Vector*)(params + 64) = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 76);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void* Multiply_MatrixMatrix(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void* A, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Multiply_MatrixMatrix");
			byte* params = (byte*)malloc(192);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void**)params = A;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void**)(params + 64) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void**)(params + 128);
			free(params);
			return returnVal;
		}
		bool NotEqual_NameName(ScriptName A, ScriptName B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.NotEqual_NameName");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = A;
			*(ScriptName*)(params + 8) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool EqualEqual_NameName(ScriptName A, ScriptName B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.EqualEqual_NameName");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = A;
			*(ScriptName*)(params + 8) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool IsA(ScriptName ClassName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.IsA");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = ClassName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool ClassIsChildOf(ScriptClass* TestClass, ScriptClass* ParentClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ClassIsChildOf");
			byte* params = (byte*)malloc(12);
			*(ScriptClass**)params = TestClass;
			*(ScriptClass**)(params + 4) = ParentClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool NotEqual_InterfaceInterface(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* A, 
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.NotEqual_InterfaceInterface");
			byte* params = (byte*)malloc(20);
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)params = A;
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)(params + 8) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool EqualEqual_InterfaceInterface(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* A, 
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.EqualEqual_InterfaceInterface");
			byte* params = (byte*)malloc(20);
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)params = A;
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)(params + 8) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool NotEqual_ObjectObject(class Object* A, class Object* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.NotEqual_ObjectObject");
			byte* params = (byte*)malloc(12);
			*(class Object**)params = A;
			*(class Object**)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool EqualEqual_ObjectObject(class Object* A, class Object* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.EqualEqual_ObjectObject");
			byte* params = (byte*)malloc(12);
			*(class Object**)params = A;
			*(class Object**)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> PathName(class Object* CheckObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.PathName");
			byte* params = (byte*)malloc(16);
			*(class Object**)params = CheckObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* SplitString(ScriptArray<wchar_t> Source, ScriptArray<wchar_t> Delimiter, bool bCullEmpty)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.SplitString");
			byte* params = (byte*)malloc(40);
			*(ScriptArray<wchar_t>*)params = Source;
			*(ScriptArray<wchar_t>*)(params + 12) = Delimiter;
			*(bool*)(params + 24) = bCullEmpty;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 28);
			free(params);
			return returnVal;
		}
		void JoinArray(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* StringArray, ScriptArray<wchar_t>& out_Result, ScriptArray<wchar_t> delim, bool bIgnoreBlanks)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.JoinArray");
			byte* params = (byte*)malloc(40);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = StringArray;
			*(ScriptArray<wchar_t>*)(params + 12) = out_Result;
			*(ScriptArray<wchar_t>*)(params + 24) = delim;
			*(bool*)(params + 36) = bIgnoreBlanks;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_Result = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
		}
		ScriptArray<wchar_t> GetRightMost(ScriptArray<wchar_t> Text)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetRightMost");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Text;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> ConcatEqual_StrStr(ScriptArray<wchar_t>& A, ScriptArray<wchar_t> B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ConcatEqual_StrStr");
			byte* params = (byte*)malloc(36);
			*(ScriptArray<wchar_t>*)params = A;
			*(ScriptArray<wchar_t>*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *(ScriptArray<wchar_t>*)params;
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 24);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> Split(ScriptArray<wchar_t> Text, ScriptArray<wchar_t> SplitStr, bool bOmitSplitStr)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Split");
			byte* params = (byte*)malloc(40);
			*(ScriptArray<wchar_t>*)params = Text;
			*(ScriptArray<wchar_t>*)(params + 12) = SplitStr;
			*(bool*)(params + 24) = bOmitSplitStr;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 28);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> Repl(ScriptArray<wchar_t> Src, ScriptArray<wchar_t> Match, ScriptArray<wchar_t> With, bool bCaseSensitive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Repl");
			byte* params = (byte*)malloc(52);
			*(ScriptArray<wchar_t>*)params = Src;
			*(ScriptArray<wchar_t>*)(params + 12) = Match;
			*(ScriptArray<wchar_t>*)(params + 24) = With;
			*(bool*)(params + 36) = bCaseSensitive;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 40);
			free(params);
			return returnVal;
		}
		int Asc(ScriptArray<wchar_t> S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Asc");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = S;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> Chr(int I)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Chr");
			byte* params = (byte*)malloc(16);
			*(int*)params = I;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> Locs(ScriptArray<wchar_t> S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Locs");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = S;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> Caps(ScriptArray<wchar_t> S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Caps");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = S;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> Right(ScriptArray<wchar_t> S, int I)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Right");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = S;
			*(int*)(params + 12) = I;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 16);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> Left(ScriptArray<wchar_t> S, int I)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Left");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = S;
			*(int*)(params + 12) = I;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 16);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> Mid(ScriptArray<wchar_t> S, int I, int J)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Mid");
			byte* params = (byte*)malloc(32);
			*(ScriptArray<wchar_t>*)params = S;
			*(int*)(params + 12) = I;
			*(int*)(params + 16) = J;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 20);
			free(params);
			return returnVal;
		}
		int InStr(ScriptArray<wchar_t> S, ScriptArray<wchar_t> T, bool bSearchFromRight, bool bIgnoreCase, int StartPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.InStr");
			byte* params = (byte*)malloc(40);
			*(ScriptArray<wchar_t>*)params = S;
			*(ScriptArray<wchar_t>*)(params + 12) = T;
			*(bool*)(params + 24) = bSearchFromRight;
			*(bool*)(params + 28) = bIgnoreCase;
			*(int*)(params + 32) = StartPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 36);
			free(params);
			return returnVal;
		}
		int Len(ScriptArray<wchar_t> S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Len");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = S;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> SubtractEqual_StrStr(ScriptArray<wchar_t>& A, ScriptArray<wchar_t> B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.SubtractEqual_StrStr");
			byte* params = (byte*)malloc(36);
			*(ScriptArray<wchar_t>*)params = A;
			*(ScriptArray<wchar_t>*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *(ScriptArray<wchar_t>*)params;
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 24);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> AtEqual_StrStr(ScriptArray<wchar_t>& A, ScriptArray<wchar_t> B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.AtEqual_StrStr");
			byte* params = (byte*)malloc(36);
			*(ScriptArray<wchar_t>*)params = A;
			*(ScriptArray<wchar_t>*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *(ScriptArray<wchar_t>*)params;
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 24);
			free(params);
			return returnVal;
		}
		bool ComplementEqual_StrStr(ScriptArray<wchar_t> A, ScriptArray<wchar_t> B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ComplementEqual_StrStr");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = A;
			*(ScriptArray<wchar_t>*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool NotEqual_StrStr(ScriptArray<wchar_t> A, ScriptArray<wchar_t> B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.NotEqual_StrStr");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = A;
			*(ScriptArray<wchar_t>*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool EqualEqual_StrStr(ScriptArray<wchar_t> A, ScriptArray<wchar_t> B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.EqualEqual_StrStr");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = A;
			*(ScriptArray<wchar_t>*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool GreaterEqual_StrStr(ScriptArray<wchar_t> A, ScriptArray<wchar_t> B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GreaterEqual_StrStr");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = A;
			*(ScriptArray<wchar_t>*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool LessEqual_StrStr(ScriptArray<wchar_t> A, ScriptArray<wchar_t> B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.LessEqual_StrStr");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = A;
			*(ScriptArray<wchar_t>*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool Greater_StrStr(ScriptArray<wchar_t> A, ScriptArray<wchar_t> B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Greater_StrStr");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = A;
			*(ScriptArray<wchar_t>*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool Less_StrStr(ScriptArray<wchar_t> A, ScriptArray<wchar_t> B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Less_StrStr");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = A;
			*(ScriptArray<wchar_t>*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> At_StrStr(ScriptArray<wchar_t> A, ScriptArray<wchar_t> B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.At_StrStr");
			byte* params = (byte*)malloc(36);
			*(ScriptArray<wchar_t>*)params = A;
			*(ScriptArray<wchar_t>*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 24);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> Concat_StrStr(ScriptArray<wchar_t> A, ScriptArray<wchar_t> B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Concat_StrStr");
			byte* params = (byte*)malloc(36);
			*(ScriptArray<wchar_t>*)params = A;
			*(ScriptArray<wchar_t>*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 24);
			free(params);
			return returnVal;
		}
		Rotator MakeRotator(int Pitch, int Yaw, int Roll)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MakeRotator");
			byte* params = (byte*)malloc(24);
			*(int*)params = Pitch;
			*(int*)(params + 4) = Yaw;
			*(int*)(params + 8) = Roll;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 12);
			free(params);
			return returnVal;
		}
		bool SClampRotAxis(float DeltaTime, int ViewAxis, int& out_DeltaViewAxis, int MaxLimit, int MinLimit, float InterpolationSpeed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.SClampRotAxis");
			byte* params = (byte*)malloc(28);
			*(float*)params = DeltaTime;
			*(int*)(params + 4) = ViewAxis;
			*(int*)(params + 8) = out_DeltaViewAxis;
			*(int*)(params + 12) = MaxLimit;
			*(int*)(params + 16) = MinLimit;
			*(float*)(params + 20) = InterpolationSpeed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_DeltaViewAxis = *(int*)(params + 8);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		int ClampRotAxisFromRange(int Current, int Min, int Max)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ClampRotAxisFromRange");
			byte* params = (byte*)malloc(16);
			*(int*)params = Current;
			*(int*)(params + 4) = Min;
			*(int*)(params + 8) = Max;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		int NormalizeRotAxis(int Angle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.NormalizeRotAxis");
			byte* params = (byte*)malloc(8);
			*(int*)params = Angle;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		float FInterpTo(float Current, float Target, float DeltaTime, float InterpSpeed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.FInterpTo");
			byte* params = (byte*)malloc(20);
			*(float*)params = Current;
			*(float*)(params + 4) = Target;
			*(float*)(params + 8) = DeltaTime;
			*(float*)(params + 12) = InterpSpeed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 16);
			free(params);
			return returnVal;
		}
		int ClampRotAxisFromBase(int Current, int Center, int MaxDelta)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ClampRotAxisFromBase");
			byte* params = (byte*)malloc(16);
			*(int*)params = Current;
			*(int*)(params + 4) = Center;
			*(int*)(params + 8) = MaxDelta;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		void ClampRotAxis(int ViewAxis, int& out_DeltaViewAxis, int MaxLimit, int MinLimit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ClampRotAxis");
			byte* params = (byte*)malloc(16);
			*(int*)params = ViewAxis;
			*(int*)(params + 4) = out_DeltaViewAxis;
			*(int*)(params + 8) = MaxLimit;
			*(int*)(params + 12) = MinLimit;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_DeltaViewAxis = *(int*)(params + 4);
			free(params);
		}
		float RSize(Rotator R)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.RSize");
			byte* params = (byte*)malloc(16);
			*(Rotator*)params = R;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		float RDiff(Rotator A, Rotator B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.RDiff");
			byte* params = (byte*)malloc(28);
			*(Rotator*)params = A;
			*(Rotator*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 24);
			free(params);
			return returnVal;
		}
		Rotator RInterpTo(Rotator Current, Rotator Target, float DeltaTime, float InterpSpeed, bool bConstantInterpSpeed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.RInterpTo");
			byte* params = (byte*)malloc(48);
			*(Rotator*)params = Current;
			*(Rotator*)(params + 12) = Target;
			*(float*)(params + 24) = DeltaTime;
			*(float*)(params + 28) = InterpSpeed;
			*(bool*)(params + 32) = bConstantInterpSpeed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 36);
			free(params);
			return returnVal;
		}
		Rotator RTransform(Rotator R, Rotator RBasis)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.RTransform");
			byte* params = (byte*)malloc(36);
			*(Rotator*)params = R;
			*(Rotator*)(params + 12) = RBasis;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 24);
			free(params);
			return returnVal;
		}
		Rotator RSmerp(Rotator A, Rotator B, float Alpha, bool bShortestPath)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.RSmerp");
			byte* params = (byte*)malloc(44);
			*(Rotator*)params = A;
			*(Rotator*)(params + 12) = B;
			*(float*)(params + 24) = Alpha;
			*(bool*)(params + 28) = bShortestPath;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 32);
			free(params);
			return returnVal;
		}
		Rotator RLerp(Rotator A, Rotator B, float Alpha, bool bShortestPath)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.RLerp");
			byte* params = (byte*)malloc(44);
			*(Rotator*)params = A;
			*(Rotator*)(params + 12) = B;
			*(float*)(params + 24) = Alpha;
			*(bool*)(params + 28) = bShortestPath;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 32);
			free(params);
			return returnVal;
		}
		Rotator Normalize(Rotator Rot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Normalize");
			byte* params = (byte*)malloc(24);
			*(Rotator*)params = Rot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 12);
			free(params);
			return returnVal;
		}
		Rotator OrthoRotation(Vector X, Vector Y, Vector Z)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.OrthoRotation");
			byte* params = (byte*)malloc(48);
			*(Vector*)params = X;
			*(Vector*)(params + 12) = Y;
			*(Vector*)(params + 24) = Z;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 36);
			free(params);
			return returnVal;
		}
		Rotator RotRand(bool bRoll)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.RotRand");
			byte* params = (byte*)malloc(16);
			*(bool*)params = bRoll;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 4);
			free(params);
			return returnVal;
		}
		Vector GetRotatorAxis(Rotator A, int Axis)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetRotatorAxis");
			byte* params = (byte*)malloc(28);
			*(Rotator*)params = A;
			*(int*)(params + 12) = Axis;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 16);
			free(params);
			return returnVal;
		}
		void GetUnAxes(Rotator A, Vector& X, Vector& Y, Vector& Z)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetUnAxes");
			byte* params = (byte*)malloc(48);
			*(Rotator*)params = A;
			*(Vector*)(params + 12) = X;
			*(Vector*)(params + 24) = Y;
			*(Vector*)(params + 36) = Z;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			X = *(Vector*)(params + 12);
			Y = *(Vector*)(params + 24);
			Z = *(Vector*)(params + 36);
			free(params);
		}
		void GetAxes(Rotator A, Vector& X, Vector& Y, Vector& Z)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetAxes");
			byte* params = (byte*)malloc(48);
			*(Rotator*)params = A;
			*(Vector*)(params + 12) = X;
			*(Vector*)(params + 24) = Y;
			*(Vector*)(params + 36) = Z;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			X = *(Vector*)(params + 12);
			Y = *(Vector*)(params + 24);
			Z = *(Vector*)(params + 36);
			free(params);
		}
		bool ClockwiseFrom_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ClockwiseFrom_IntInt");
			byte* params = (byte*)malloc(12);
			*(int*)params = A;
			*(int*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		Rotator SubtractEqual_RotatorRotator(Rotator& A, Rotator B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.SubtractEqual_RotatorRotator");
			byte* params = (byte*)malloc(36);
			*(Rotator*)params = A;
			*(Rotator*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *(Rotator*)params;
			auto returnVal = *(Rotator*)(params + 24);
			free(params);
			return returnVal;
		}
		Rotator AddEqual_RotatorRotator(Rotator& A, Rotator B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.AddEqual_RotatorRotator");
			byte* params = (byte*)malloc(36);
			*(Rotator*)params = A;
			*(Rotator*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *(Rotator*)params;
			auto returnVal = *(Rotator*)(params + 24);
			free(params);
			return returnVal;
		}
		Rotator Subtract_RotatorRotator(Rotator A, Rotator B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Subtract_RotatorRotator");
			byte* params = (byte*)malloc(36);
			*(Rotator*)params = A;
			*(Rotator*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 24);
			free(params);
			return returnVal;
		}
		Rotator Add_RotatorRotator(Rotator A, Rotator B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Add_RotatorRotator");
			byte* params = (byte*)malloc(36);
			*(Rotator*)params = A;
			*(Rotator*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 24);
			free(params);
			return returnVal;
		}
		Rotator DivideEqual_RotatorFloat(Rotator& A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.DivideEqual_RotatorFloat");
			byte* params = (byte*)malloc(28);
			*(Rotator*)params = A;
			*(float*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *(Rotator*)params;
			auto returnVal = *(Rotator*)(params + 16);
			free(params);
			return returnVal;
		}
		Rotator MultiplyEqual_RotatorFloat(Rotator& A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MultiplyEqual_RotatorFloat");
			byte* params = (byte*)malloc(28);
			*(Rotator*)params = A;
			*(float*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *(Rotator*)params;
			auto returnVal = *(Rotator*)(params + 16);
			free(params);
			return returnVal;
		}
		Rotator Divide_RotatorFloat(Rotator A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Divide_RotatorFloat");
			byte* params = (byte*)malloc(28);
			*(Rotator*)params = A;
			*(float*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 16);
			free(params);
			return returnVal;
		}
		Rotator Multiply_FloatRotator(float A, Rotator B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Multiply_FloatRotator");
			byte* params = (byte*)malloc(28);
			*(float*)params = A;
			*(Rotator*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 16);
			free(params);
			return returnVal;
		}
		Rotator Multiply_RotatorFloat(Rotator A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Multiply_RotatorFloat");
			byte* params = (byte*)malloc(28);
			*(Rotator*)params = A;
			*(float*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 16);
			free(params);
			return returnVal;
		}
		bool NotEqual_RotatorRotator(Rotator A, Rotator B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.NotEqual_RotatorRotator");
			byte* params = (byte*)malloc(28);
			*(Rotator*)params = A;
			*(Rotator*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool EqualEqual_RotatorRotator(Rotator A, Rotator B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.EqualEqual_RotatorRotator");
			byte* params = (byte*)malloc(28);
			*(Rotator*)params = A;
			*(Rotator*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool InCylinder(Vector Origin, Rotator Dir, float Width, Vector A, bool bIgnoreZ)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.InCylinder");
			byte* params = (byte*)malloc(48);
			*(Vector*)params = Origin;
			*(Rotator*)(params + 12) = Dir;
			*(float*)(params + 24) = Width;
			*(Vector*)(params + 28) = A;
			*(bool*)(params + 40) = bIgnoreZ;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 44);
			free(params);
			return returnVal;
		}
		float NoZDot(Vector A, Vector B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.NoZDot");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = A;
			*(Vector*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 24);
			free(params);
			return returnVal;
		}
		Vector ClampLength(Vector V, float MaxLength)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ClampLength");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = V;
			*(float*)(params + 12) = MaxLength;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 16);
			free(params);
			return returnVal;
		}
		Vector VInterpTo(Vector Current, Vector Target, float DeltaTime, float InterpSpeed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.VInterpTo");
			byte* params = (byte*)malloc(44);
			*(Vector*)params = Current;
			*(Vector*)(params + 12) = Target;
			*(float*)(params + 24) = DeltaTime;
			*(float*)(params + 28) = InterpSpeed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 32);
			free(params);
			return returnVal;
		}
		bool IsZero(Vector A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.IsZero");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		Vector ProjectOnTo(Vector X, Vector Y)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ProjectOnTo");
			byte* params = (byte*)malloc(36);
			*(Vector*)params = X;
			*(Vector*)(params + 12) = Y;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 24);
			free(params);
			return returnVal;
		}
		Vector MirrorVectorByNormal(Vector InVect, Vector InNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MirrorVectorByNormal");
			byte* params = (byte*)malloc(36);
			*(Vector*)params = InVect;
			*(Vector*)(params + 12) = InNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 24);
			free(params);
			return returnVal;
		}
		Vector VRandCone2(Vector Dir, float HorizontalConeHalfAngleRadians, float VerticalConeHalfAngleRadians)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.VRandCone2");
			byte* params = (byte*)malloc(32);
			*(Vector*)params = Dir;
			*(float*)(params + 12) = HorizontalConeHalfAngleRadians;
			*(float*)(params + 16) = VerticalConeHalfAngleRadians;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 20);
			free(params);
			return returnVal;
		}
		Vector VRandCone(Vector Dir, float ConeHalfAngleRadians)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.VRandCone");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = Dir;
			*(float*)(params + 12) = ConeHalfAngleRadians;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 16);
			free(params);
			return returnVal;
		}
		Vector VRand()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.VRand");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
		}
		Vector VSmerp(Vector A, Vector B, float Alpha)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.VSmerp");
			byte* params = (byte*)malloc(40);
			*(Vector*)params = A;
			*(Vector*)(params + 12) = B;
			*(float*)(params + 24) = Alpha;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 28);
			free(params);
			return returnVal;
		}
		Vector VLerp(Vector A, Vector B, float Alpha)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.VLerp");
			byte* params = (byte*)malloc(40);
			*(Vector*)params = A;
			*(Vector*)(params + 12) = B;
			*(float*)(params + 24) = Alpha;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 28);
			free(params);
			return returnVal;
		}
		Vector Normal(Vector A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Normal");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 12);
			free(params);
			return returnVal;
		}
		float VSizeSq2D(Vector A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.VSizeSq2D");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		float VSizeSq(Vector A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.VSizeSq");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		float VSize2D(Vector A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.VSize2D");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		float VSize(Vector A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.VSize");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		Vector SubtractEqual_VectorVector(Vector& A, Vector B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.SubtractEqual_VectorVector");
			byte* params = (byte*)malloc(36);
			*(Vector*)params = A;
			*(Vector*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *(Vector*)params;
			auto returnVal = *(Vector*)(params + 24);
			free(params);
			return returnVal;
		}
		Vector AddEqual_VectorVector(Vector& A, Vector B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.AddEqual_VectorVector");
			byte* params = (byte*)malloc(36);
			*(Vector*)params = A;
			*(Vector*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *(Vector*)params;
			auto returnVal = *(Vector*)(params + 24);
			free(params);
			return returnVal;
		}
		Vector DivideEqual_VectorFloat(Vector& A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.DivideEqual_VectorFloat");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = A;
			*(float*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *(Vector*)params;
			auto returnVal = *(Vector*)(params + 16);
			free(params);
			return returnVal;
		}
		Vector MultiplyEqual_VectorVector(Vector& A, Vector B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MultiplyEqual_VectorVector");
			byte* params = (byte*)malloc(36);
			*(Vector*)params = A;
			*(Vector*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *(Vector*)params;
			auto returnVal = *(Vector*)(params + 24);
			free(params);
			return returnVal;
		}
		Vector MultiplyEqual_VectorFloat(Vector& A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MultiplyEqual_VectorFloat");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = A;
			*(float*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *(Vector*)params;
			auto returnVal = *(Vector*)(params + 16);
			free(params);
			return returnVal;
		}
		Vector Cross_VectorVector(Vector A, Vector B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Cross_VectorVector");
			byte* params = (byte*)malloc(36);
			*(Vector*)params = A;
			*(Vector*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 24);
			free(params);
			return returnVal;
		}
		float Dot_VectorVector(Vector A, Vector B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Dot_VectorVector");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = A;
			*(Vector*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 24);
			free(params);
			return returnVal;
		}
		bool NotEqual_VectorVector(Vector A, Vector B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.NotEqual_VectorVector");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = A;
			*(Vector*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool EqualEqual_VectorVector(Vector A, Vector B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.EqualEqual_VectorVector");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = A;
			*(Vector*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		Vector GreaterGreater_VectorRotator(Vector A, Rotator B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GreaterGreater_VectorRotator");
			byte* params = (byte*)malloc(36);
			*(Vector*)params = A;
			*(Rotator*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 24);
			free(params);
			return returnVal;
		}
		Vector LessLess_VectorRotator(Vector A, Rotator B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.LessLess_VectorRotator");
			byte* params = (byte*)malloc(36);
			*(Vector*)params = A;
			*(Rotator*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 24);
			free(params);
			return returnVal;
		}
		Vector Subtract_VectorVector(Vector A, Vector B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Subtract_VectorVector");
			byte* params = (byte*)malloc(36);
			*(Vector*)params = A;
			*(Vector*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 24);
			free(params);
			return returnVal;
		}
		Vector Add_VectorVector(Vector A, Vector B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Add_VectorVector");
			byte* params = (byte*)malloc(36);
			*(Vector*)params = A;
			*(Vector*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 24);
			free(params);
			return returnVal;
		}
		Vector Divide_VectorFloat(Vector A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Divide_VectorFloat");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = A;
			*(float*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 16);
			free(params);
			return returnVal;
		}
		Vector Multiply_VectorVector(Vector A, Vector B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Multiply_VectorVector");
			byte* params = (byte*)malloc(36);
			*(Vector*)params = A;
			*(Vector*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 24);
			free(params);
			return returnVal;
		}
		Vector Multiply_FloatVector(float A, Vector B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Multiply_FloatVector");
			byte* params = (byte*)malloc(28);
			*(float*)params = A;
			*(Vector*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 16);
			free(params);
			return returnVal;
		}
		Vector Multiply_VectorFloat(Vector A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Multiply_VectorFloat");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = A;
			*(float*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 16);
			free(params);
			return returnVal;
		}
		Vector Subtract_PreVector(Vector A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Subtract_PreVector");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 12);
			free(params);
			return returnVal;
		}
		float FInterpConstantTo(float Current, float Target, float DeltaTime, float InterpSpeed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.FInterpConstantTo");
			byte* params = (byte*)malloc(20);
			*(float*)params = Current;
			*(float*)(params + 4) = Target;
			*(float*)(params + 8) = DeltaTime;
			*(float*)(params + 12) = InterpSpeed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 16);
			free(params);
			return returnVal;
		}
		float FPctByRange(float Value, float InMin, float InMax)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.FPctByRange");
			byte* params = (byte*)malloc(16);
			*(float*)params = Value;
			*(float*)(params + 4) = InMin;
			*(float*)(params + 8) = InMax;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		float RandRange(float InMin, float InMax)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.RandRange");
			byte* params = (byte*)malloc(12);
			*(float*)params = InMin;
			*(float*)(params + 4) = InMax;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		float FInterpEaseInOut(float A, float B, float Alpha, float Exp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.FInterpEaseInOut");
			byte* params = (byte*)malloc(20);
			*(float*)params = A;
			*(float*)(params + 4) = B;
			*(float*)(params + 8) = Alpha;
			*(float*)(params + 12) = Exp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 16);
			free(params);
			return returnVal;
		}
		float FInterpEaseOut(float A, float B, float Alpha, float Exp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.FInterpEaseOut");
			byte* params = (byte*)malloc(20);
			*(float*)params = A;
			*(float*)(params + 4) = B;
			*(float*)(params + 8) = Alpha;
			*(float*)(params + 12) = Exp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 16);
			free(params);
			return returnVal;
		}
		float FInterpEaseIn(float A, float B, float Alpha, float Exp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.FInterpEaseIn");
			byte* params = (byte*)malloc(20);
			*(float*)params = A;
			*(float*)(params + 4) = B;
			*(float*)(params + 8) = Alpha;
			*(float*)(params + 12) = Exp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 16);
			free(params);
			return returnVal;
		}
		float FCubicInterp(float P0, float T0, float P1, float T1, float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.FCubicInterp");
			byte* params = (byte*)malloc(24);
			*(float*)params = P0;
			*(float*)(params + 4) = T0;
			*(float*)(params + 8) = P1;
			*(float*)(params + 12) = T1;
			*(float*)(params + 16) = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 20);
			free(params);
			return returnVal;
		}
		int FCeil(float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.FCeil");
			byte* params = (byte*)malloc(8);
			*(float*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		int FFloor(float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.FFloor");
			byte* params = (byte*)malloc(8);
			*(float*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		int Round(float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Round");
			byte* params = (byte*)malloc(8);
			*(float*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		float Lerp(float A, float B, float Alpha)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Lerp");
			byte* params = (byte*)malloc(16);
			*(float*)params = A;
			*(float*)(params + 4) = B;
			*(float*)(params + 8) = Alpha;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		float FClamp(float V, float A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.FClamp");
			byte* params = (byte*)malloc(16);
			*(float*)params = V;
			*(float*)(params + 4) = A;
			*(float*)(params + 8) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		float FMax(float A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.FMax");
			byte* params = (byte*)malloc(12);
			*(float*)params = A;
			*(float*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		float FMin(float A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.FMin");
			byte* params = (byte*)malloc(12);
			*(float*)params = A;
			*(float*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		float FRand()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.FRand");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float Square(float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Square");
			byte* params = (byte*)malloc(8);
			*(float*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		float Sqrt(float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Sqrt");
			byte* params = (byte*)malloc(8);
			*(float*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		float Loge(float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Loge");
			byte* params = (byte*)malloc(8);
			*(float*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		float Exp(float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Exp");
			byte* params = (byte*)malloc(8);
			*(float*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		float Atan2(float A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Atan2");
			byte* params = (byte*)malloc(12);
			*(float*)params = A;
			*(float*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		float Atan(float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Atan");
			byte* params = (byte*)malloc(8);
			*(float*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		float Tan(float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Tan");
			byte* params = (byte*)malloc(8);
			*(float*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		float Cos(float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Cos");
			byte* params = (byte*)malloc(8);
			*(float*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		float Asin(float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Asin");
			byte* params = (byte*)malloc(8);
			*(float*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		float Sin(float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Sin");
			byte* params = (byte*)malloc(8);
			*(float*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		float Abs(float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Abs");
			byte* params = (byte*)malloc(8);
			*(float*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		float SubtractEqual_FloatFloat(float& A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.SubtractEqual_FloatFloat");
			byte* params = (byte*)malloc(12);
			*(float*)params = A;
			*(float*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *(float*)params;
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		float AddEqual_FloatFloat(float& A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.AddEqual_FloatFloat");
			byte* params = (byte*)malloc(12);
			*(float*)params = A;
			*(float*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *(float*)params;
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		float DivideEqual_FloatFloat(float& A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.DivideEqual_FloatFloat");
			byte* params = (byte*)malloc(12);
			*(float*)params = A;
			*(float*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *(float*)params;
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		float MultiplyEqual_FloatFloat(float& A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MultiplyEqual_FloatFloat");
			byte* params = (byte*)malloc(12);
			*(float*)params = A;
			*(float*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *(float*)params;
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		bool NotEqual_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.NotEqual_FloatFloat");
			byte* params = (byte*)malloc(12);
			*(float*)params = A;
			*(float*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool ComplementEqual_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ComplementEqual_FloatFloat");
			byte* params = (byte*)malloc(12);
			*(float*)params = A;
			*(float*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool EqualEqual_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.EqualEqual_FloatFloat");
			byte* params = (byte*)malloc(12);
			*(float*)params = A;
			*(float*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool GreaterEqual_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GreaterEqual_FloatFloat");
			byte* params = (byte*)malloc(12);
			*(float*)params = A;
			*(float*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool LessEqual_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.LessEqual_FloatFloat");
			byte* params = (byte*)malloc(12);
			*(float*)params = A;
			*(float*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool Greater_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Greater_FloatFloat");
			byte* params = (byte*)malloc(12);
			*(float*)params = A;
			*(float*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool Less_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Less_FloatFloat");
			byte* params = (byte*)malloc(12);
			*(float*)params = A;
			*(float*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		float Subtract_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Subtract_FloatFloat");
			byte* params = (byte*)malloc(12);
			*(float*)params = A;
			*(float*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		float Add_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Add_FloatFloat");
			byte* params = (byte*)malloc(12);
			*(float*)params = A;
			*(float*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		float Percent_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Percent_FloatFloat");
			byte* params = (byte*)malloc(12);
			*(float*)params = A;
			*(float*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		float Divide_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Divide_FloatFloat");
			byte* params = (byte*)malloc(12);
			*(float*)params = A;
			*(float*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		float Multiply_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Multiply_FloatFloat");
			byte* params = (byte*)malloc(12);
			*(float*)params = A;
			*(float*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		float MultiplyMultiply_FloatFloat(float Base, float Exp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MultiplyMultiply_FloatFloat");
			byte* params = (byte*)malloc(12);
			*(float*)params = Base;
			*(float*)(params + 4) = Exp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		float Subtract_PreFloat(float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Subtract_PreFloat");
			byte* params = (byte*)malloc(8);
			*(float*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> ToHex(int A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ToHex");
			byte* params = (byte*)malloc(16);
			*(int*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		int Clamp(int V, int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Clamp");
			byte* params = (byte*)malloc(16);
			*(int*)params = V;
			*(int*)(params + 4) = A;
			*(int*)(params + 8) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		int Max(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Max");
			byte* params = (byte*)malloc(12);
			*(int*)params = A;
			*(int*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int Min(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Min");
			byte* params = (byte*)malloc(12);
			*(int*)params = A;
			*(int*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int Rand(int Max)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Rand");
			byte* params = (byte*)malloc(8);
			*(int*)params = Max;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		int SubtractSubtract_Int(int& A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.SubtractSubtract_Int");
			byte* params = (byte*)malloc(8);
			*(int*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *(int*)params;
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		int AddAdd_Int(int& A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.AddAdd_Int");
			byte* params = (byte*)malloc(8);
			*(int*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *(int*)params;
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		int SubtractSubtract_PreInt(int& A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.SubtractSubtract_PreInt");
			byte* params = (byte*)malloc(8);
			*(int*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *(int*)params;
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		int AddAdd_PreInt(int& A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.AddAdd_PreInt");
			byte* params = (byte*)malloc(8);
			*(int*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *(int*)params;
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		int SubtractEqual_IntInt(int& A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.SubtractEqual_IntInt");
			byte* params = (byte*)malloc(12);
			*(int*)params = A;
			*(int*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *(int*)params;
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int AddEqual_IntInt(int& A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.AddEqual_IntInt");
			byte* params = (byte*)malloc(12);
			*(int*)params = A;
			*(int*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *(int*)params;
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int DivideEqual_IntFloat(int& A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.DivideEqual_IntFloat");
			byte* params = (byte*)malloc(12);
			*(int*)params = A;
			*(float*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *(int*)params;
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int MultiplyEqual_IntFloat(int& A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MultiplyEqual_IntFloat");
			byte* params = (byte*)malloc(12);
			*(int*)params = A;
			*(float*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *(int*)params;
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int Or_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Or_IntInt");
			byte* params = (byte*)malloc(12);
			*(int*)params = A;
			*(int*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int Xor_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Xor_IntInt");
			byte* params = (byte*)malloc(12);
			*(int*)params = A;
			*(int*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int And_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.And_IntInt");
			byte* params = (byte*)malloc(12);
			*(int*)params = A;
			*(int*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		bool NotEqual_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.NotEqual_IntInt");
			byte* params = (byte*)malloc(12);
			*(int*)params = A;
			*(int*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool EqualEqual_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.EqualEqual_IntInt");
			byte* params = (byte*)malloc(12);
			*(int*)params = A;
			*(int*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool GreaterEqual_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GreaterEqual_IntInt");
			byte* params = (byte*)malloc(12);
			*(int*)params = A;
			*(int*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool LessEqual_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.LessEqual_IntInt");
			byte* params = (byte*)malloc(12);
			*(int*)params = A;
			*(int*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool Greater_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Greater_IntInt");
			byte* params = (byte*)malloc(12);
			*(int*)params = A;
			*(int*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool Less_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Less_IntInt");
			byte* params = (byte*)malloc(12);
			*(int*)params = A;
			*(int*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		int GreaterGreaterGreater_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GreaterGreaterGreater_IntInt");
			byte* params = (byte*)malloc(12);
			*(int*)params = A;
			*(int*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int GreaterGreater_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GreaterGreater_IntInt");
			byte* params = (byte*)malloc(12);
			*(int*)params = A;
			*(int*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int LessLess_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.LessLess_IntInt");
			byte* params = (byte*)malloc(12);
			*(int*)params = A;
			*(int*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int Subtract_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Subtract_IntInt");
			byte* params = (byte*)malloc(12);
			*(int*)params = A;
			*(int*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int Add_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Add_IntInt");
			byte* params = (byte*)malloc(12);
			*(int*)params = A;
			*(int*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int Percent_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Percent_IntInt");
			byte* params = (byte*)malloc(12);
			*(int*)params = A;
			*(int*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int Divide_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Divide_IntInt");
			byte* params = (byte*)malloc(12);
			*(int*)params = A;
			*(int*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int Multiply_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Multiply_IntInt");
			byte* params = (byte*)malloc(12);
			*(int*)params = A;
			*(int*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int Subtract_PreInt(int A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Subtract_PreInt");
			byte* params = (byte*)malloc(8);
			*(int*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		int Complement_PreInt(int A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Complement_PreInt");
			byte* params = (byte*)malloc(8);
			*(int*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		byte SubtractSubtract_Byte(byte& A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.SubtractSubtract_Byte");
			byte* params = (byte*)malloc(2);
			*params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *params;
			auto returnVal = *(params + 1);
			free(params);
			return returnVal;
		}
		byte AddAdd_Byte(byte& A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.AddAdd_Byte");
			byte* params = (byte*)malloc(2);
			*params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *params;
			auto returnVal = *(params + 1);
			free(params);
			return returnVal;
		}
		byte SubtractSubtract_PreByte(byte& A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.SubtractSubtract_PreByte");
			byte* params = (byte*)malloc(2);
			*params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *params;
			auto returnVal = *(params + 1);
			free(params);
			return returnVal;
		}
		byte AddAdd_PreByte(byte& A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.AddAdd_PreByte");
			byte* params = (byte*)malloc(2);
			*params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *params;
			auto returnVal = *(params + 1);
			free(params);
			return returnVal;
		}
		byte SubtractEqual_ByteByte(byte& A, byte B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.SubtractEqual_ByteByte");
			byte* params = (byte*)malloc(3);
			*params = A;
			*(params + 1) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *params;
			auto returnVal = *(params + 2);
			free(params);
			return returnVal;
		}
		byte AddEqual_ByteByte(byte& A, byte B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.AddEqual_ByteByte");
			byte* params = (byte*)malloc(3);
			*params = A;
			*(params + 1) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *params;
			auto returnVal = *(params + 2);
			free(params);
			return returnVal;
		}
		byte DivideEqual_ByteByte(byte& A, byte B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.DivideEqual_ByteByte");
			byte* params = (byte*)malloc(3);
			*params = A;
			*(params + 1) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *params;
			auto returnVal = *(params + 2);
			free(params);
			return returnVal;
		}
		byte MultiplyEqual_ByteFloat(byte& A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MultiplyEqual_ByteFloat");
			byte* params = (byte*)malloc(6);
			*params = A;
			*(float*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *params;
			auto returnVal = *(params + 8);
			free(params);
			return returnVal;
		}
		byte MultiplyEqual_ByteByte(byte& A, byte B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MultiplyEqual_ByteByte");
			byte* params = (byte*)malloc(3);
			*params = A;
			*(params + 1) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			A = *params;
			auto returnVal = *(params + 2);
			free(params);
			return returnVal;
		}
		bool OrOr_BoolBool(bool A, bool B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.OrOr_BoolBool");
			byte* params = (byte*)malloc(12);
			*(bool*)params = A;
			*(bool*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool XorXor_BoolBool(bool A, bool B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.XorXor_BoolBool");
			byte* params = (byte*)malloc(12);
			*(bool*)params = A;
			*(bool*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool AndAnd_BoolBool(bool A, bool B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.AndAnd_BoolBool");
			byte* params = (byte*)malloc(12);
			*(bool*)params = A;
			*(bool*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool NotEqual_BoolBool(bool A, bool B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.NotEqual_BoolBool");
			byte* params = (byte*)malloc(12);
			*(bool*)params = A;
			*(bool*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool EqualEqual_BoolBool(bool A, bool B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.EqualEqual_BoolBool");
			byte* params = (byte*)malloc(12);
			*(bool*)params = A;
			*(bool*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool Not_PreBool(bool A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Not_PreBool");
			byte* params = (byte*)malloc(8);
			*(bool*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
