#pragma once
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
	class Object
	{
	public:
		static const float InvAspectRatio16x9;
		static const float InvAspectRatio5x4;
		static const float InvAspectRatio4x3;
		static const float AspectRatio16x9;
		static const float AspectRatio5x4;
		static const float AspectRatio4x3;
		static const auto INDEX_NONE = -1;
		static const float UnrRotToDeg;
		static const float DegToUnrRot;
		static const float RadToUnrRot;
		static const float UnrRotToRad;
		static const float DegToRad;
		static const float RadToDeg;
		static const float Pi;
		static const auto MaxInt = 0x7fffffff;
		enum EDebugBreakType : byte
		{
			DEBUGGER_NativeOnly = 0,
			DEBUGGER_ScriptOnly = 1,
			DEBUGGER_Both = 2,
			DEBUGGER_MAX = 3,
		};
		enum EAutomatedRunResult : byte
		{
			ARR_Unknown = 0,
			ARR_OOM = 1,
			ARR_Passed = 2,
			ARR_MAX = 3,
		};
		enum EAspectRatioAxisConstraint : byte
		{
			AspectRatio_MaintainYFOV = 0,
			AspectRatio_MaintainXFOV = 1,
			AspectRatio_MajorAxisFOV = 2,
			AspectRatio_MAX = 3,
		};
		enum EInterpCurveMode : byte
		{
			CIM_Linear = 0,
			CIM_CurveAuto = 1,
			CIM_Constant = 2,
			CIM_CurveUser = 3,
			CIM_CurveBreak = 4,
			CIM_CurveAutoClamped = 5,
			CIM_MAX = 6,
		};
		enum EInterpMethodType : byte
		{
			IMT_UseFixedTangentEvalAndNewAutoTangents = 0,
			IMT_UseFixedTangentEval = 1,
			IMT_UseBrokenTangentEval = 2,
			IMT_MAX = 3,
		};
		enum EAxis : byte
		{
			AXIS_NONE = 0,
			AXIS_X = 1,
			AXIS_Y = 2,
			AXIS_BLANK = 3,
			AXIS_Z = 4,
			AXIS_MAX = 5,
		};
		enum ETickingGroup : byte
		{
			TG_PreAsyncWork = 0,
			TG_DuringAsyncWork = 1,
			TG_PostAsyncWork = 2,
			TG_PostUpdateWork = 3,
			TG_EffectsUpdateWork = 4,
			TG_MAX = 5,
		};
		enum EInputEvent : byte
		{
			IE_Pressed = 0,
			IE_Released = 1,
			IE_Repeat = 2,
			IE_DoubleClick = 3,
			IE_Axis = 4,
			IE_MAX = 5,
		};
		enum AlphaBlendType : byte
		{
			ABT_Linear = 0,
			ABT_Cubic = 1,
			ABT_Sinusoidal = 2,
			ABT_EaseInOutExponent2 = 3,
			ABT_EaseInOutExponent3 = 4,
			ABT_EaseInOutExponent4 = 5,
			ABT_EaseInOutExponent5 = 6,
			ABT_MAX = 7,
		};
		class Rotator
		{
		public:
			ADD_STRUCT(int, Pitch, 0)
			ADD_STRUCT(int, Yaw, 4)
			ADD_STRUCT(int, Roll, 8)
		};
		class Vector
		{
		public:
			ADD_STRUCT(float, X, 0)
			ADD_STRUCT(float, Y, 4)
			ADD_STRUCT(float, Z, 8)
		};
		class Guid
		{
		public:
			ADD_STRUCT(int, A, 0)
			ADD_STRUCT(int, B, 4)
			ADD_STRUCT(int, C, 8)
			ADD_STRUCT(int, D, 12)
		};
		class Vector2D
		{
		public:
			ADD_STRUCT(float, X, 0)
			ADD_STRUCT(float, Y, 4)
		};
		class Vector4
		{
		public:
			ADD_STRUCT(float, X, 0)
			ADD_STRUCT(float, Y, 4)
			ADD_STRUCT(float, Z, 8)
			ADD_STRUCT(float, W, 12)
		};
		class LinearColor
		{
		public:
			ADD_STRUCT(float, R, 0)
			ADD_STRUCT(float, G, 4)
			ADD_STRUCT(float, B, 8)
			ADD_STRUCT(float, A, 12)
		};
		class Color
		{
		public:
			ADD_STRUCT(byte, R, 2)
			ADD_STRUCT(byte, G, 1)
			ADD_STRUCT(byte, B, 0)
			ADD_STRUCT(byte, A, 3)
		};
		class Cylinder
		{
		public:
			ADD_STRUCT(float, Radius, 0)
			ADD_STRUCT(float, Height, 4)
		};
		class Quat
		{
		public:
			ADD_STRUCT(float, X, 0)
			ADD_STRUCT(float, Y, 4)
			ADD_STRUCT(float, Z, 8)
			ADD_STRUCT(float, W, 12)
		};
		class BoxSphereBounds
		{
		public:
			ADD_STRUCT(Object::Vector, Origin, 0)
			ADD_STRUCT(Object::Vector, BoxExtent, 12)
			ADD_STRUCT(float, SphereRadius, 24)
		};
		class TwoVectors
		{
		public:
			ADD_STRUCT(Object::Vector, v1, 0)
			ADD_STRUCT(Object::Vector, v2, 12)
		};
		class BoneAtom
		{
		public:
			ADD_STRUCT(Object::Quat, Rotation, 0)
			ADD_STRUCT(Object::Vector, Translation, 16)
			ADD_STRUCT(float, Scale, 28)
		};
		class RenderCommandFence
		{
		public:
			ADD_STRUCT(int, NumPendingFences, 0)
		};
		class Pointer
		{
		public:
			ADD_STRUCT(int, Dummy, 0)
		};
		class RawDistribution
		{
		public:
			ADD_STRUCT(byte, Type, 0)
			ADD_STRUCT(byte, Op, 1)
			ADD_STRUCT(byte, LookupTableNumElements, 2)
			ADD_STRUCT(byte, LookupTableChunkSize, 3)
			ADD_STRUCT(ScriptArray<float>, LookupTable, 4)
			ADD_STRUCT(float, LookupTableTimeScale, 16)
			ADD_STRUCT(float, LookupTableStartTime, 20)
		};
		class Box
		{
		public:
			ADD_STRUCT(Object::Vector, Min, 0)
			ADD_STRUCT(Object::Vector, Max, 12)
			ADD_STRUCT(byte, IsValid, 24)
		};
		class TPOV
		{
		public:
			ADD_STRUCT(Object::Vector, Location, 0)
			ADD_STRUCT(Object::Rotator, Rotation, 12)
			ADD_STRUCT(float, FOV, 24)
		};
		class SHVector
		{
		public:
			ADD_STRUCT(float, V, 0)
			ADD_STRUCT(float, Padding, 36)
		};
		class IntPoint
		{
		public:
			ADD_STRUCT(int, X, 0)
			ADD_STRUCT(int, Y, 4)
		};
		class Array_Mirror
		{
		public:
			ADD_STRUCT(Object::Pointer, Data, 0)
			ADD_STRUCT(int, ArrayNum, 4)
			ADD_STRUCT(int, ArrayMax, 8)
		};
		class IndirectArray_Mirror
		{
		public:
			ADD_STRUCT(Object::Pointer, Data, 0)
			ADD_STRUCT(int, ArrayNum, 4)
			ADD_STRUCT(int, ArrayMax, 8)
		};
		class FColorVertexBuffer_Mirror
		{
		public:
			ADD_STRUCT(Object::Pointer, VfTable, 0)
			ADD_STRUCT(Object::Pointer, VertexData, 4)
			ADD_STRUCT(int, Data, 8)
			ADD_STRUCT(int, Stride, 12)
			ADD_STRUCT(int, NumVertices, 16)
		};
		class RenderCommandFence_Mirror
		{
		public:
			ADD_STRUCT(int, NumPendingFences, 0)
		};
		class UntypedBulkData_Mirror
		{
		public:
			ADD_STRUCT(Object::Pointer, VfTable, 0)
			ADD_STRUCT(int, BulkDataFlags, 4)
			ADD_STRUCT(int, ElementCount, 8)
			ADD_STRUCT(int, BulkDataOffsetInFile, 12)
			ADD_STRUCT(int, BulkDataSizeOnDisk, 16)
			ADD_STRUCT(int, SavedBulkDataFlags, 20)
			ADD_STRUCT(int, SavedElementCount, 24)
			ADD_STRUCT(int, SavedBulkDataOffsetInFile, 28)
			ADD_STRUCT(int, SavedBulkDataSizeOnDisk, 32)
			ADD_STRUCT(Object::Pointer, BulkData, 36)
			ADD_STRUCT(int, LockStatus, 40)
			ADD_STRUCT(Object::Pointer, AttachedAr, 44)
			ADD_STRUCT(int, bShouldFreeOnEmpty, 48)
		};
		class BitArray_Mirror
		{
		public:
			ADD_STRUCT(Object::Pointer, IndirectData, 0)
			ADD_STRUCT(int, InlineData, 4)
			ADD_STRUCT(int, NumBits, 20)
			ADD_STRUCT(int, MaxBits, 24)
		};
		class ThreadSafeCounter
		{
		public:
			ADD_STRUCT(int, Value, 0)
		};
		class Double
		{
		public:
			ADD_STRUCT(int, A, 0)
			ADD_STRUCT(int, B, 4)
		};
		class QWord
		{
		public:
			ADD_STRUCT(int, A, 0)
			ADD_STRUCT(int, B, 4)
		};
		class Plane : public Vector
		{
		public:
			ADD_STRUCT(float, W, 12)
		};
		class InterpCurvePointVector2D
		{
		public:
			ADD_STRUCT(float, InVal, 0)
			ADD_STRUCT(Object::Vector2D, OutVal, 4)
			ADD_STRUCT(Object::Vector2D, ArriveTangent, 12)
			ADD_STRUCT(Object::Vector2D, LeaveTangent, 20)
			ADD_STRUCT(Object::EInterpCurveMode, InterpMode, 28)
		};
		class InterpCurvePointVector
		{
		public:
			ADD_STRUCT(float, InVal, 0)
			ADD_STRUCT(Object::Vector, OutVal, 4)
			ADD_STRUCT(Object::Vector, ArriveTangent, 16)
			ADD_STRUCT(Object::Vector, LeaveTangent, 28)
			ADD_STRUCT(Object::EInterpCurveMode, InterpMode, 40)
		};
		class InterpCurvePointFloat
		{
		public:
			ADD_STRUCT(float, InVal, 0)
			ADD_STRUCT(float, OutVal, 4)
			ADD_STRUCT(float, ArriveTangent, 8)
			ADD_STRUCT(float, LeaveTangent, 12)
			ADD_STRUCT(Object::EInterpCurveMode, InterpMode, 16)
		};
		class Matrix
		{
		public:
			ADD_STRUCT(Object::Plane, XPlane, 0)
			ADD_STRUCT(Object::Plane, YPlane, 16)
			ADD_STRUCT(Object::Plane, ZPlane, 32)
			ADD_STRUCT(Object::Plane, WPlane, 48)
		};
		class TAlphaBlend
		{
		public:
			ADD_STRUCT(float, AlphaIn, 0)
			ADD_STRUCT(float, AlphaOut, 4)
			ADD_STRUCT(float, AlphaTarget, 8)
			ADD_STRUCT(float, BlendTime, 12)
			ADD_STRUCT(float, BlendTimeToGo, 16)
			ADD_STRUCT(Object::AlphaBlendType, BlendType, 20)
		};
		class OctreeElementId
		{
		public:
			ADD_STRUCT(Object::Pointer, Node, 0)
			ADD_STRUCT(int, ElementIndex, 4)
		};
		class InterpCurvePointLinearColor
		{
		public:
			ADD_STRUCT(float, InVal, 0)
			ADD_STRUCT(Object::LinearColor, OutVal, 4)
			ADD_STRUCT(Object::LinearColor, ArriveTangent, 20)
			ADD_STRUCT(Object::LinearColor, LeaveTangent, 36)
			ADD_STRUCT(Object::EInterpCurveMode, InterpMode, 52)
		};
		class InterpCurvePointQuat
		{
		public:
			ADD_STRUCT(float, InVal, 0)
			ADD_STRUCT(Object::Quat, OutVal, 16)
			ADD_STRUCT(Object::Quat, ArriveTangent, 32)
			ADD_STRUCT(Object::Quat, LeaveTangent, 48)
			ADD_STRUCT(Object::EInterpCurveMode, InterpMode, 64)
		};
		class InterpCurvePointTwoVectors
		{
		public:
			ADD_STRUCT(float, InVal, 0)
			ADD_STRUCT(Object::TwoVectors, OutVal, 4)
			ADD_STRUCT(Object::TwoVectors, ArriveTangent, 28)
			ADD_STRUCT(Object::TwoVectors, LeaveTangent, 52)
			ADD_STRUCT(Object::EInterpCurveMode, InterpMode, 76)
		};
		class SHVectorRGB
		{
		public:
			ADD_STRUCT(Object::SHVector, R, 0)
			ADD_STRUCT(Object::SHVector, G, 48)
			ADD_STRUCT(Object::SHVector, B, 96)
		};
		class InlinePointerArray_Mirror
		{
		public:
			ADD_STRUCT(Object::Pointer, InlineData, 0)
			ADD_STRUCT(Object::Array_Mirror, SecondaryData, 4)
		};
		class SparseArray_Mirror
		{
		public:
			ADD_STRUCT(ScriptArray<int>, Elements, 0)
			ADD_STRUCT(Object::BitArray_Mirror, AllocationFlags, 12)
			ADD_STRUCT(int, FirstFreeIndex, 40)
			ADD_STRUCT(int, NumFreeIndices, 44)
		};
		class InterpCurveVector2D
		{
		public:
			ADD_STRUCT(ScriptArray<Object::InterpCurvePointVector2D>, Points, 0)
			ADD_STRUCT(Object::EInterpMethodType, InterpMethod, 12)
		};
		class InterpCurveFloat
		{
		public:
			ADD_STRUCT(ScriptArray<Object::InterpCurvePointFloat>, Points, 0)
			ADD_STRUCT(Object::EInterpMethodType, InterpMethod, 12)
		};
		class InterpCurveVector
		{
		public:
			ADD_STRUCT(ScriptArray<Object::InterpCurvePointVector>, Points, 0)
			ADD_STRUCT(Object::EInterpMethodType, InterpMethod, 12)
		};
		class InterpCurveLinearColor
		{
		public:
			ADD_STRUCT(ScriptArray<Object::InterpCurvePointLinearColor>, Points, 0)
			ADD_STRUCT(Object::EInterpMethodType, InterpMethod, 12)
		};
		class InterpCurveQuat
		{
		public:
			ADD_STRUCT(ScriptArray<Object::InterpCurvePointQuat>, Points, 0)
			ADD_STRUCT(Object::EInterpMethodType, InterpMethod, 12)
		};
		class InterpCurveTwoVectors
		{
		public:
			ADD_STRUCT(ScriptArray<Object::InterpCurvePointTwoVectors>, Points, 0)
			ADD_STRUCT(Object::EInterpMethodType, InterpMethod, 12)
		};
		class Set_Mirror
		{
		public:
			ADD_STRUCT(Object::SparseArray_Mirror, Elements, 0)
			ADD_STRUCT(Object::Pointer, Hash, 48)
			ADD_STRUCT(int, InlineHash, 52)
			ADD_STRUCT(int, HashSize, 56)
		};
		class MultiMap_Mirror
		{
		public:
			ADD_STRUCT(Object::Set_Mirror, Pairs, 0)
		};
		class Map_Mirror
		{
		public:
			ADD_STRUCT(Object::Set_Mirror, Pairs, 0)
		};
		ADD_OBJECT(Object, Outer, 40)
		ADD_STRUCT(ScriptName, Name, 44)
		ADD_STRUCT(Object::Pointer, VfTableObject, 0)
		ADD_STRUCT(int, ObjectInternalInteger, 4)
		ADD_STRUCT(Object::QWord, ObjectFlags, 8)
		ADD_STRUCT(Object::Pointer, HashNext, 16)
		ADD_STRUCT(Object::Pointer, HashOuterNext, 20)
		ADD_STRUCT(Object::Pointer, StateFrame, 24)
		ADD_OBJECT(Object, Linker, 28)
		ADD_STRUCT(Object::Pointer, LinkerIndex, 32)
		ADD_STRUCT(int, NetIndex, 36)
		ADD_OBJECT(ScriptClass, Class, 52)
		ADD_OBJECT(Object, ObjectArchetype, 56)
		int GetBuildChangelistNumber()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetBuildChangelistNumber");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		int GetEngineVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetEngineVersion");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		void GetSystemTime(int& Year, int& Month, int& DayOfWeek, int& Day, int& Hour, int& Min, int& Sec, int& MSec)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetSystemTime");
			byte params[32] = { NULL };
			*(int*)&params[0] = Year;
			*(int*)&params[4] = Month;
			*(int*)&params[8] = DayOfWeek;
			*(int*)&params[12] = Day;
			*(int*)&params[16] = Hour;
			*(int*)&params[20] = Min;
			*(int*)&params[24] = Sec;
			*(int*)&params[28] = MSec;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Year = *(int*)&params[0];
			Month = *(int*)&params[4];
			DayOfWeek = *(int*)&params[8];
			Day = *(int*)&params[12];
			Hour = *(int*)&params[16];
			Min = *(int*)&params[20];
			Sec = *(int*)&params[24];
			MSec = *(int*)&params[28];
		}
		ScriptString* TimeStamp()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.TimeStamp");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		Object::Vector TransformVectorByRotation(Object::Rotator SourceRotation, Object::Vector SourceVector, bool bInverse)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.TransformVectorByRotation");
			byte params[40] = { NULL };
			*(Object::Rotator*)&params[0] = SourceRotation;
			*(Object::Vector*)&params[12] = SourceVector;
			*(bool*)&params[24] = bInverse;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[28];
		}
		ScriptName GetPackageName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetPackageName");
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[0];
		}
		bool IsPendingKill()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.IsPendingKill");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		float ByteToFloat(byte inputByte, bool bSigned)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ByteToFloat");
			byte params[9] = { NULL };
			params[0] = inputByte;
			*(bool*)&params[4] = bSigned;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		byte FloatToByte(float inputFloat, bool bSigned)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.FloatToByte");
			byte params[9] = { NULL };
			*(float*)&params[0] = inputFloat;
			*(bool*)&params[4] = bSigned;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[8];
		}
		float UnwindHeading(float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.UnwindHeading");
			byte params[8] = { NULL };
			*(float*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		float FindDeltaAngle(float A1, float A2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.FindDeltaAngle");
			byte params[12] = { NULL };
			*(float*)&params[0] = A1;
			*(float*)&params[4] = A2;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		float GetHeadingAngle(Object::Vector Dir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetHeadingAngle");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = Dir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		void GetAngularDegreesFromRadians(Object::Vector2D& OutFOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetAngularDegreesFromRadians");
			byte params[8] = { NULL };
			*(Object::Vector2D*)&params[0] = OutFOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutFOV = *(Object::Vector2D*)&params[0];
		}
		float Acos(float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Acos");
			byte params[8] = { NULL };
			*(float*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		void GetAngularFromDotDist(Object::Vector2D& OutAngDist, Object::Vector2D DotDist)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetAngularFromDotDist");
			byte params[16] = { NULL };
			*(Object::Vector2D*)&params[0] = OutAngDist;
			*(Object::Vector2D*)&params[8] = DotDist;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutAngDist = *(Object::Vector2D*)&params[0];
		}
		bool GetAngularDistance(Object::Vector2D& OutAngularDist, Object::Vector Direction, Object::Vector AxisX, Object::Vector AxisY, Object::Vector AxisZ)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetAngularDistance");
			byte params[60] = { NULL };
			*(Object::Vector2D*)&params[0] = OutAngularDist;
			*(Object::Vector*)&params[8] = Direction;
			*(Object::Vector*)&params[20] = AxisX;
			*(Object::Vector*)&params[32] = AxisY;
			*(Object::Vector*)&params[44] = AxisZ;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutAngularDist = *(Object::Vector2D*)&params[0];
			return *(bool*)&params[56];
		}
		bool GetDotDistance(Object::Vector2D& OutDotDist, Object::Vector Direction, Object::Vector AxisX, Object::Vector AxisY, Object::Vector AxisZ)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetDotDistance");
			byte params[60] = { NULL };
			*(Object::Vector2D*)&params[0] = OutDotDist;
			*(Object::Vector*)&params[8] = Direction;
			*(Object::Vector*)&params[20] = AxisX;
			*(Object::Vector*)&params[32] = AxisY;
			*(Object::Vector*)&params[44] = AxisZ;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutDotDist = *(Object::Vector2D*)&params[0];
			return *(bool*)&params[56];
		}
		Object::Vector PointProjectToPlane(Object::Vector Point, Object::Vector A, Object::Vector B, Object::Vector C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.PointProjectToPlane");
			byte params[60] = { NULL };
			*(Object::Vector*)&params[0] = Point;
			*(Object::Vector*)&params[12] = A;
			*(Object::Vector*)&params[24] = B;
			*(Object::Vector*)&params[36] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[48];
		}
		float PointDistToPlane(Object::Vector Point, Object::Rotator Orientation, Object::Vector Origin, Object::Vector& out_ClosestPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.PointDistToPlane");
			byte params[52] = { NULL };
			*(Object::Vector*)&params[0] = Point;
			*(Object::Rotator*)&params[12] = Orientation;
			*(Object::Vector*)&params[24] = Origin;
			*(Object::Vector*)&params[36] = out_ClosestPoint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ClosestPoint = *(Object::Vector*)&params[36];
			return *(float*)&params[48];
		}
		float PointDistToSegment(Object::Vector Point, Object::Vector StartPoint, Object::Vector EndPoint, Object::Vector& OutClosestPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.PointDistToSegment");
			byte params[52] = { NULL };
			*(Object::Vector*)&params[0] = Point;
			*(Object::Vector*)&params[12] = StartPoint;
			*(Object::Vector*)&params[24] = EndPoint;
			*(Object::Vector*)&params[36] = OutClosestPoint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutClosestPoint = *(Object::Vector*)&params[36];
			return *(float*)&params[48];
		}
		float PointDistToLine(Object::Vector Point, Object::Vector Line, Object::Vector Origin, Object::Vector& OutClosestPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.PointDistToLine");
			byte params[52] = { NULL };
			*(Object::Vector*)&params[0] = Point;
			*(Object::Vector*)&params[12] = Line;
			*(Object::Vector*)&params[24] = Origin;
			*(Object::Vector*)&params[36] = OutClosestPoint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutClosestPoint = *(Object::Vector*)&params[36];
			return *(float*)&params[48];
		}
		bool GetPerObjectConfigSections(ScriptClass* SearchClass, ScriptArray<ScriptString*>& out_SectionNames, class Object* ObjectOuter, int MaxResults)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetPerObjectConfigSections");
			byte params[28] = { NULL };
			*(ScriptClass**)&params[0] = SearchClass;
			*(ScriptArray<ScriptString*>*)&params[4] = out_SectionNames;
			*(class Object**)&params[16] = ObjectOuter;
			*(int*)&params[20] = MaxResults;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_SectionNames = *(ScriptArray<ScriptString*>*)&params[4];
			return *(bool*)&params[24];
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
		class Object* FindObject(ScriptString* ObjectName, ScriptClass* ObjectClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.FindObject");
			byte params[20] = { NULL };
			*(ScriptString**)&params[0] = ObjectName;
			*(ScriptClass**)&params[12] = ObjectClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Object**)&params[16];
		}
		class Object* DynamicLoadObject(ScriptString* ObjectName, ScriptClass* ObjectClass, bool MayFail)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.DynamicLoadObject");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = ObjectName;
			*(ScriptClass**)&params[12] = ObjectClass;
			*(bool*)&params[16] = MayFail;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Object**)&params[20];
		}
		ScriptName GetEnum(class Object* E, int I)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetEnum");
			byte params[16] = { NULL };
			*(class Object**)&params[0] = E;
			*(int*)&params[4] = I;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[8];
		}
		void Disable(ScriptName ProbeFunc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Disable");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = ProbeFunc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Enable(ScriptName ProbeFunc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Enable");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = ProbeFunc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = NextStateName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BeginState(ScriptName PreviousStateName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.BeginState");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = PreviousStateName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DumpStateStack()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.DumpStateStack");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PopState(bool bPopAll)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.PopState");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bPopAll;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PushState(ScriptName NewState, ScriptName NewLabel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.PushState");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = NewState;
			*(ScriptName*)&params[8] = NewLabel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptName GetStateName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetStateName");
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[0];
		}
		bool IsChildState(ScriptName TestState, ScriptName TestParentState)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.IsChildState");
			byte params[20] = { NULL };
			*(ScriptName*)&params[0] = TestState;
			*(ScriptName*)&params[8] = TestParentState;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool IsInState(ScriptName TestState, bool bTestStateStack)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.IsInState");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = TestState;
			*(bool*)&params[8] = bTestStateStack;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void GotoState(ScriptName NewState, ScriptName Label, bool bForceEvents, bool bKeepStack)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GotoState");
			byte params[24] = { NULL };
			*(ScriptName*)&params[0] = NewState;
			*(ScriptName*)&params[8] = Label;
			*(bool*)&params[16] = bForceEvents;
			*(bool*)&params[20] = bKeepStack;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsUTracing()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.IsUTracing");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void SetUTracing(bool bShouldUTrace)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.SetUTracing");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bShouldUTrace;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptName GetFuncName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetFuncName");
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[0];
		}
		void DebugBreak(int UserFlags, Object::EDebugBreakType DebuggerType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.DebugBreak");
			byte params[5] = { NULL };
			*(int*)&params[0] = UserFlags;
			*(Object::EDebugBreakType*)&params[4] = DebuggerType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetScriptTrace()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetScriptTrace");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		void ScriptTrace()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ScriptTrace");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* ParseLocalizedPropertyPath(ScriptString* PathName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ParseLocalizedPropertyPath");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = PathName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		ScriptString* Localize(ScriptString* SectionName, ScriptString* KeyName, ScriptString* PackageName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Localize");
			byte params[48] = { NULL };
			*(ScriptString**)&params[0] = SectionName;
			*(ScriptString**)&params[12] = KeyName;
			*(ScriptString**)&params[24] = PackageName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[36];
		}
		void ParseStringIntoArray(ScriptString* BaseString, ScriptArray<ScriptString*>& Pieces, ScriptString* delim, bool bCullEmpty)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ParseStringIntoArray");
			byte params[40] = { NULL };
			*(ScriptString**)&params[0] = BaseString;
			*(ScriptArray<ScriptString*>*)&params[12] = Pieces;
			*(ScriptString**)&params[24] = delim;
			*(bool*)&params[36] = bCullEmpty;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Pieces = *(ScriptArray<ScriptString*>*)&params[12];
		}
		void WarnInternal(ScriptString* S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.WarnInternal");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LogInternal(ScriptString* S, ScriptName Tag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.LogInternal");
			byte params[20] = { NULL };
			*(ScriptString**)&params[0] = S;
			*(ScriptName*)&params[12] = Tag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::LinearColor Subtract_LinearColorLinearColor(Object::LinearColor A, Object::LinearColor B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Subtract_LinearColorLinearColor");
			byte params[48] = { NULL };
			*(Object::LinearColor*)&params[0] = A;
			*(Object::LinearColor*)&params[16] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::LinearColor*)&params[32];
		}
		Object::LinearColor Multiply_LinearColorFloat(Object::LinearColor LC, float Mult)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Multiply_LinearColorFloat");
			byte params[36] = { NULL };
			*(Object::LinearColor*)&params[0] = LC;
			*(float*)&params[16] = Mult;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::LinearColor*)&params[20];
		}
		Object::LinearColor ColorToLinearColor(Object::Color OldColor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ColorToLinearColor");
			byte params[20] = { NULL };
			*(Object::Color*)&params[0] = OldColor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::LinearColor*)&params[4];
		}
		Object::LinearColor MakeLinearColor(float R, float G, float B, float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MakeLinearColor");
			byte params[32] = { NULL };
			*(float*)&params[0] = R;
			*(float*)&params[4] = G;
			*(float*)&params[8] = B;
			*(float*)&params[12] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::LinearColor*)&params[16];
		}
		Object::Color LerpColor(Object::Color A, Object::Color B, float Alpha)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.LerpColor");
			byte params[16] = { NULL };
			*(Object::Color*)&params[0] = A;
			*(Object::Color*)&params[4] = B;
			*(float*)&params[8] = Alpha;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Color*)&params[12];
		}
		Object::Color MakeColor(byte R, byte G, byte B, byte A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MakeColor");
			byte params[8] = { NULL };
			params[0] = R;
			params[1] = G;
			params[2] = B;
			params[3] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Color*)&params[4];
		}
		Object::Color Add_ColorColor(Object::Color A, Object::Color B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Add_ColorColor");
			byte params[12] = { NULL };
			*(Object::Color*)&params[0] = A;
			*(Object::Color*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Color*)&params[8];
		}
		Object::Color Multiply_ColorFloat(Object::Color A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Multiply_ColorFloat");
			byte params[12] = { NULL };
			*(Object::Color*)&params[0] = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Color*)&params[8];
		}
		Object::Color Multiply_FloatColor(float A, Object::Color B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Multiply_FloatColor");
			byte params[12] = { NULL };
			*(float*)&params[0] = A;
			*(Object::Color*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Color*)&params[8];
		}
		Object::Color Subtract_ColorColor(Object::Color A, Object::Color B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Subtract_ColorColor");
			byte params[12] = { NULL };
			*(Object::Color*)&params[0] = A;
			*(Object::Color*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Color*)&params[8];
		}
		Object::Vector2D EvalInterpCurveVector2D(Object::InterpCurveVector2D Vector2DCurve, float InVal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.EvalInterpCurveVector2D");
			byte params[28] = { NULL };
			*(Object::InterpCurveVector2D*)&params[0] = Vector2DCurve;
			*(float*)&params[16] = InVal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector2D*)&params[20];
		}
		Object::Vector EvalInterpCurveVector(Object::InterpCurveVector VectorCurve, float InVal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.EvalInterpCurveVector");
			byte params[32] = { NULL };
			*(Object::InterpCurveVector*)&params[0] = VectorCurve;
			*(float*)&params[16] = InVal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[20];
		}
		float EvalInterpCurveFloat(Object::InterpCurveFloat FloatCurve, float InVal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.EvalInterpCurveFloat");
			byte params[24] = { NULL };
			*(Object::InterpCurveFloat*)&params[0] = FloatCurve;
			*(float*)&params[16] = InVal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[20];
		}
		Object::Vector2D vect2d(float InX, float InY)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.vect2d");
			byte params[16] = { NULL };
			*(float*)&params[0] = InX;
			*(float*)&params[4] = InY;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector2D*)&params[8];
		}
		float GetMappedRangeValue(Object::Vector2D InputRange, Object::Vector2D OutputRange, float Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetMappedRangeValue");
			byte params[24] = { NULL };
			*(Object::Vector2D*)&params[0] = InputRange;
			*(Object::Vector2D*)&params[8] = OutputRange;
			*(float*)&params[16] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[20];
		}
		float GetRangePctByValue(Object::Vector2D Range, float Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetRangePctByValue");
			byte params[16] = { NULL };
			*(Object::Vector2D*)&params[0] = Range;
			*(float*)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		float GetRangeValueByPct(Object::Vector2D Range, float Pct)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetRangeValueByPct");
			byte params[16] = { NULL };
			*(Object::Vector2D*)&params[0] = Range;
			*(float*)&params[8] = Pct;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		Object::Vector2D SubtractEqual_Vector2DVector2D(Object::Vector2D& A, Object::Vector2D B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.SubtractEqual_Vector2DVector2D");
			byte params[24] = { NULL };
			*(Object::Vector2D*)&params[0] = A;
			*(Object::Vector2D*)&params[8] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(Object::Vector2D*)&params[0];
			return *(Object::Vector2D*)&params[16];
		}
		Object::Vector2D AddEqual_Vector2DVector2D(Object::Vector2D& A, Object::Vector2D B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.AddEqual_Vector2DVector2D");
			byte params[24] = { NULL };
			*(Object::Vector2D*)&params[0] = A;
			*(Object::Vector2D*)&params[8] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(Object::Vector2D*)&params[0];
			return *(Object::Vector2D*)&params[16];
		}
		Object::Vector2D DivideEqual_Vector2DFloat(Object::Vector2D& A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.DivideEqual_Vector2DFloat");
			byte params[20] = { NULL };
			*(Object::Vector2D*)&params[0] = A;
			*(float*)&params[8] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(Object::Vector2D*)&params[0];
			return *(Object::Vector2D*)&params[12];
		}
		Object::Vector2D MultiplyEqual_Vector2DFloat(Object::Vector2D& A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MultiplyEqual_Vector2DFloat");
			byte params[20] = { NULL };
			*(Object::Vector2D*)&params[0] = A;
			*(float*)&params[8] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(Object::Vector2D*)&params[0];
			return *(Object::Vector2D*)&params[12];
		}
		Object::Vector2D Divide_Vector2DFloat(Object::Vector2D A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Divide_Vector2DFloat");
			byte params[20] = { NULL };
			*(Object::Vector2D*)&params[0] = A;
			*(float*)&params[8] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector2D*)&params[12];
		}
		Object::Vector2D Multiply_Vector2DFloat(Object::Vector2D A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Multiply_Vector2DFloat");
			byte params[20] = { NULL };
			*(Object::Vector2D*)&params[0] = A;
			*(float*)&params[8] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector2D*)&params[12];
		}
		Object::Vector2D Subtract_Vector2DVector2D(Object::Vector2D A, Object::Vector2D B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Subtract_Vector2DVector2D");
			byte params[24] = { NULL };
			*(Object::Vector2D*)&params[0] = A;
			*(Object::Vector2D*)&params[8] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector2D*)&params[16];
		}
		Object::Vector2D Add_Vector2DVector2D(Object::Vector2D A, Object::Vector2D B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Add_Vector2DVector2D");
			byte params[24] = { NULL };
			*(Object::Vector2D*)&params[0] = A;
			*(Object::Vector2D*)&params[8] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector2D*)&params[16];
		}
		Object::Quat Subtract_QuatQuat(Object::Quat A, Object::Quat B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Subtract_QuatQuat");
			byte params[48] = { NULL };
			*(Object::Quat*)&params[0] = A;
			*(Object::Quat*)&params[16] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Quat*)&params[32];
		}
		Object::Quat Add_QuatQuat(Object::Quat A, Object::Quat B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Add_QuatQuat");
			byte params[48] = { NULL };
			*(Object::Quat*)&params[0] = A;
			*(Object::Quat*)&params[16] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Quat*)&params[32];
		}
		Object::Quat QuatSlerp(Object::Quat A, Object::Quat B, float Alpha, bool bShortestPath)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.QuatSlerp");
			byte params[56] = { NULL };
			*(Object::Quat*)&params[0] = A;
			*(Object::Quat*)&params[16] = B;
			*(float*)&params[32] = Alpha;
			*(bool*)&params[36] = bShortestPath;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Quat*)&params[48];
		}
		Object::Rotator QuatToRotator(Object::Quat A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.QuatToRotator");
			byte params[28] = { NULL };
			*(Object::Quat*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[16];
		}
		Object::Quat QuatFromRotator(Object::Rotator A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.QuatFromRotator");
			byte params[28] = { NULL };
			*(Object::Rotator*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Quat*)&params[16];
		}
		Object::Quat QuatFromAxisAndAngle(Object::Vector Axis, float Angle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.QuatFromAxisAndAngle");
			byte params[32] = { NULL };
			*(Object::Vector*)&params[0] = Axis;
			*(float*)&params[12] = Angle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Quat*)&params[16];
		}
		Object::Quat QuatFindBetween(Object::Vector A, Object::Vector B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.QuatFindBetween");
			byte params[40] = { NULL };
			*(Object::Vector*)&params[0] = A;
			*(Object::Vector*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Quat*)&params[32];
		}
		Object::Vector QuatRotateVector(Object::Quat A, Object::Vector B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.QuatRotateVector");
			byte params[40] = { NULL };
			*(Object::Quat*)&params[0] = A;
			*(Object::Vector*)&params[16] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[28];
		}
		Object::Quat QuatInvert(Object::Quat A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.QuatInvert");
			byte params[32] = { NULL };
			*(Object::Quat*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Quat*)&params[16];
		}
		float QuatDot(Object::Quat A, Object::Quat B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.QuatDot");
			byte params[36] = { NULL };
			*(Object::Quat*)&params[0] = A;
			*(Object::Quat*)&params[16] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[32];
		}
		Object::Quat QuatProduct(Object::Quat A, Object::Quat B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.QuatProduct");
			byte params[48] = { NULL };
			*(Object::Quat*)&params[0] = A;
			*(Object::Quat*)&params[16] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Quat*)&params[32];
		}
		Object::Vector MatrixGetAxis(Object::Matrix TM, Object::EAxis Axis)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MatrixGetAxis");
			byte params[77] = { NULL };
			*(Object::Matrix*)&params[0] = TM;
			*(Object::EAxis*)&params[64] = Axis;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[68];
		}
		Object::Vector MatrixGetOrigin(Object::Matrix TM)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MatrixGetOrigin");
			byte params[76] = { NULL };
			*(Object::Matrix*)&params[0] = TM;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[64];
		}
		Object::Rotator MatrixGetRotator(Object::Matrix TM)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MatrixGetRotator");
			byte params[76] = { NULL };
			*(Object::Matrix*)&params[0] = TM;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[64];
		}
		Object::Matrix MakeRotationMatrix(Object::Rotator Rotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MakeRotationMatrix");
			byte params[76] = { NULL };
			*(Object::Rotator*)&params[0] = Rotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Matrix*)&params[16];
		}
		Object::Matrix MakeRotationTranslationMatrix(Object::Vector Translation, Object::Rotator Rotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MakeRotationTranslationMatrix");
			byte params[88] = { NULL };
			*(Object::Vector*)&params[0] = Translation;
			*(Object::Rotator*)&params[12] = Rotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Matrix*)&params[32];
		}
		Object::Vector InverseTransformNormal(Object::Matrix TM, Object::Vector A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.InverseTransformNormal");
			byte params[88] = { NULL };
			*(Object::Matrix*)&params[0] = TM;
			*(Object::Vector*)&params[64] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[76];
		}
		Object::Vector TransformNormal(Object::Matrix TM, Object::Vector A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.TransformNormal");
			byte params[88] = { NULL };
			*(Object::Matrix*)&params[0] = TM;
			*(Object::Vector*)&params[64] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[76];
		}
		Object::Vector InverseTransformVector(Object::Matrix TM, Object::Vector A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.InverseTransformVector");
			byte params[88] = { NULL };
			*(Object::Matrix*)&params[0] = TM;
			*(Object::Vector*)&params[64] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[76];
		}
		Object::Vector TransformVector(Object::Matrix TM, Object::Vector A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.TransformVector");
			byte params[88] = { NULL };
			*(Object::Matrix*)&params[0] = TM;
			*(Object::Vector*)&params[64] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[76];
		}
		Object::Matrix Multiply_MatrixMatrix(Object::Matrix A, Object::Matrix B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Multiply_MatrixMatrix");
			byte params[192] = { NULL };
			*(Object::Matrix*)&params[0] = A;
			*(Object::Matrix*)&params[64] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Matrix*)&params[128];
		}
		bool NotEqual_NameName(ScriptName A, ScriptName B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.NotEqual_NameName");
			byte params[20] = { NULL };
			*(ScriptName*)&params[0] = A;
			*(ScriptName*)&params[8] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool EqualEqual_NameName(ScriptName A, ScriptName B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.EqualEqual_NameName");
			byte params[20] = { NULL };
			*(ScriptName*)&params[0] = A;
			*(ScriptName*)&params[8] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool IsA(ScriptName ClassName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.IsA");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = ClassName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool ClassIsChildOf(ScriptClass* TestClass, ScriptClass* ParentClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ClassIsChildOf");
			byte params[12] = { NULL };
			*(ScriptClass**)&params[0] = TestClass;
			*(ScriptClass**)&params[4] = ParentClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool NotEqual_InterfaceInterface(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* A, 
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.NotEqual_InterfaceInterface");
			byte params[20] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)&params[0] = A;
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)&params[8] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool EqualEqual_InterfaceInterface(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* A, 
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.EqualEqual_InterfaceInterface");
			byte params[20] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)&params[0] = A;
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)&params[8] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool NotEqual_ObjectObject(class Object* A, class Object* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.NotEqual_ObjectObject");
			byte params[12] = { NULL };
			*(class Object**)&params[0] = A;
			*(class Object**)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool EqualEqual_ObjectObject(class Object* A, class Object* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.EqualEqual_ObjectObject");
			byte params[12] = { NULL };
			*(class Object**)&params[0] = A;
			*(class Object**)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		ScriptString* PathName(class Object* CheckObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.PathName");
			byte params[16] = { NULL };
			*(class Object**)&params[0] = CheckObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptArray<ScriptString*> SplitString(ScriptString* Source, ScriptString* Delimiter, bool bCullEmpty)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.SplitString");
			byte params[40] = { NULL };
			*(ScriptString**)&params[0] = Source;
			*(ScriptString**)&params[12] = Delimiter;
			*(bool*)&params[24] = bCullEmpty;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptArray<ScriptString*>*)&params[28];
		}
		void JoinArray(ScriptArray<ScriptString*> StringArray, ScriptString*& out_Result, ScriptString* delim, bool bIgnoreBlanks)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.JoinArray");
			byte params[40] = { NULL };
			*(ScriptArray<ScriptString*>*)&params[0] = StringArray;
			*(ScriptString**)&params[12] = out_Result;
			*(ScriptString**)&params[24] = delim;
			*(bool*)&params[36] = bIgnoreBlanks;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Result = *(ScriptString**)&params[12];
		}
		ScriptString* GetRightMost(ScriptString* Text)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetRightMost");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = Text;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		ScriptString* ConcatEqual_StrStr(ScriptString*& A, ScriptString* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ConcatEqual_StrStr");
			byte params[36] = { NULL };
			*(ScriptString**)&params[0] = A;
			*(ScriptString**)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(ScriptString**)&params[0];
			return *(ScriptString**)&params[24];
		}
		ScriptString* Split(ScriptString* Text, ScriptString* SplitStr, bool bOmitSplitStr)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Split");
			byte params[40] = { NULL };
			*(ScriptString**)&params[0] = Text;
			*(ScriptString**)&params[12] = SplitStr;
			*(bool*)&params[24] = bOmitSplitStr;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[28];
		}
		ScriptString* Repl(ScriptString* Src, ScriptString* Match, ScriptString* With, bool bCaseSensitive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Repl");
			byte params[52] = { NULL };
			*(ScriptString**)&params[0] = Src;
			*(ScriptString**)&params[12] = Match;
			*(ScriptString**)&params[24] = With;
			*(bool*)&params[36] = bCaseSensitive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[40];
		}
		int Asc(ScriptString* S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Asc");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		ScriptString* Chr(int I)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Chr");
			byte params[16] = { NULL };
			*(int*)&params[0] = I;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptString* Locs(ScriptString* S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Locs");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		ScriptString* Caps(ScriptString* S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Caps");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		ScriptString* Right(ScriptString* S, int I)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Right");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = S;
			*(int*)&params[12] = I;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[16];
		}
		ScriptString* Left(ScriptString* S, int I)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Left");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = S;
			*(int*)&params[12] = I;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[16];
		}
		ScriptString* Mid(ScriptString* S, int I, int J)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Mid");
			byte params[32] = { NULL };
			*(ScriptString**)&params[0] = S;
			*(int*)&params[12] = I;
			*(int*)&params[16] = J;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[20];
		}
		int InStr(ScriptString* S, ScriptString* T, bool bSearchFromRight, bool bIgnoreCase, int StartPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.InStr");
			byte params[40] = { NULL };
			*(ScriptString**)&params[0] = S;
			*(ScriptString**)&params[12] = T;
			*(bool*)&params[24] = bSearchFromRight;
			*(bool*)&params[28] = bIgnoreCase;
			*(int*)&params[32] = StartPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[36];
		}
		int Len(ScriptString* S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Len");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		ScriptString* SubtractEqual_StrStr(ScriptString*& A, ScriptString* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.SubtractEqual_StrStr");
			byte params[36] = { NULL };
			*(ScriptString**)&params[0] = A;
			*(ScriptString**)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(ScriptString**)&params[0];
			return *(ScriptString**)&params[24];
		}
		ScriptString* AtEqual_StrStr(ScriptString*& A, ScriptString* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.AtEqual_StrStr");
			byte params[36] = { NULL };
			*(ScriptString**)&params[0] = A;
			*(ScriptString**)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(ScriptString**)&params[0];
			return *(ScriptString**)&params[24];
		}
		bool ComplementEqual_StrStr(ScriptString* A, ScriptString* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ComplementEqual_StrStr");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = A;
			*(ScriptString**)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool NotEqual_StrStr(ScriptString* A, ScriptString* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.NotEqual_StrStr");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = A;
			*(ScriptString**)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool EqualEqual_StrStr(ScriptString* A, ScriptString* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.EqualEqual_StrStr");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = A;
			*(ScriptString**)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool GreaterEqual_StrStr(ScriptString* A, ScriptString* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GreaterEqual_StrStr");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = A;
			*(ScriptString**)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool LessEqual_StrStr(ScriptString* A, ScriptString* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.LessEqual_StrStr");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = A;
			*(ScriptString**)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool Greater_StrStr(ScriptString* A, ScriptString* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Greater_StrStr");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = A;
			*(ScriptString**)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool Less_StrStr(ScriptString* A, ScriptString* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Less_StrStr");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = A;
			*(ScriptString**)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		ScriptString* At_StrStr(ScriptString* A, ScriptString* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.At_StrStr");
			byte params[36] = { NULL };
			*(ScriptString**)&params[0] = A;
			*(ScriptString**)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[24];
		}
		ScriptString* Concat_StrStr(ScriptString* A, ScriptString* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Concat_StrStr");
			byte params[36] = { NULL };
			*(ScriptString**)&params[0] = A;
			*(ScriptString**)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[24];
		}
		Object::Rotator MakeRotator(int Pitch, int Yaw, int Roll)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MakeRotator");
			byte params[24] = { NULL };
			*(int*)&params[0] = Pitch;
			*(int*)&params[4] = Yaw;
			*(int*)&params[8] = Roll;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[12];
		}
		bool SClampRotAxis(float DeltaTime, int ViewAxis, int& out_DeltaViewAxis, int MaxLimit, int MinLimit, float InterpolationSpeed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.SClampRotAxis");
			byte params[28] = { NULL };
			*(float*)&params[0] = DeltaTime;
			*(int*)&params[4] = ViewAxis;
			*(int*)&params[8] = out_DeltaViewAxis;
			*(int*)&params[12] = MaxLimit;
			*(int*)&params[16] = MinLimit;
			*(float*)&params[20] = InterpolationSpeed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_DeltaViewAxis = *(int*)&params[8];
			return *(bool*)&params[24];
		}
		int ClampRotAxisFromRange(int Current, int Min, int Max)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ClampRotAxisFromRange");
			byte params[16] = { NULL };
			*(int*)&params[0] = Current;
			*(int*)&params[4] = Min;
			*(int*)&params[8] = Max;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		int NormalizeRotAxis(int Angle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.NormalizeRotAxis");
			byte params[8] = { NULL };
			*(int*)&params[0] = Angle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		float FInterpTo(float Current, float Target, float DeltaTime, float InterpSpeed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.FInterpTo");
			byte params[20] = { NULL };
			*(float*)&params[0] = Current;
			*(float*)&params[4] = Target;
			*(float*)&params[8] = DeltaTime;
			*(float*)&params[12] = InterpSpeed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[16];
		}
		int ClampRotAxisFromBase(int Current, int Center, int MaxDelta)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ClampRotAxisFromBase");
			byte params[16] = { NULL };
			*(int*)&params[0] = Current;
			*(int*)&params[4] = Center;
			*(int*)&params[8] = MaxDelta;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		void ClampRotAxis(int ViewAxis, int& out_DeltaViewAxis, int MaxLimit, int MinLimit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ClampRotAxis");
			byte params[16] = { NULL };
			*(int*)&params[0] = ViewAxis;
			*(int*)&params[4] = out_DeltaViewAxis;
			*(int*)&params[8] = MaxLimit;
			*(int*)&params[12] = MinLimit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_DeltaViewAxis = *(int*)&params[4];
		}
		float RSize(Object::Rotator R)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.RSize");
			byte params[16] = { NULL };
			*(Object::Rotator*)&params[0] = R;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		float RDiff(Object::Rotator A, Object::Rotator B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.RDiff");
			byte params[28] = { NULL };
			*(Object::Rotator*)&params[0] = A;
			*(Object::Rotator*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[24];
		}
		Object::Rotator RInterpTo(Object::Rotator Current, Object::Rotator Target, float DeltaTime, float InterpSpeed, bool bConstantInterpSpeed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.RInterpTo");
			byte params[48] = { NULL };
			*(Object::Rotator*)&params[0] = Current;
			*(Object::Rotator*)&params[12] = Target;
			*(float*)&params[24] = DeltaTime;
			*(float*)&params[28] = InterpSpeed;
			*(bool*)&params[32] = bConstantInterpSpeed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[36];
		}
		Object::Rotator RTransform(Object::Rotator R, Object::Rotator RBasis)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.RTransform");
			byte params[36] = { NULL };
			*(Object::Rotator*)&params[0] = R;
			*(Object::Rotator*)&params[12] = RBasis;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[24];
		}
		Object::Rotator RSmerp(Object::Rotator A, Object::Rotator B, float Alpha, bool bShortestPath)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.RSmerp");
			byte params[44] = { NULL };
			*(Object::Rotator*)&params[0] = A;
			*(Object::Rotator*)&params[12] = B;
			*(float*)&params[24] = Alpha;
			*(bool*)&params[28] = bShortestPath;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[32];
		}
		Object::Rotator RLerp(Object::Rotator A, Object::Rotator B, float Alpha, bool bShortestPath)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.RLerp");
			byte params[44] = { NULL };
			*(Object::Rotator*)&params[0] = A;
			*(Object::Rotator*)&params[12] = B;
			*(float*)&params[24] = Alpha;
			*(bool*)&params[28] = bShortestPath;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[32];
		}
		Object::Rotator Normalize(Object::Rotator Rot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Normalize");
			byte params[24] = { NULL };
			*(Object::Rotator*)&params[0] = Rot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[12];
		}
		Object::Rotator OrthoRotation(Object::Vector X, Object::Vector Y, Object::Vector Z)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.OrthoRotation");
			byte params[48] = { NULL };
			*(Object::Vector*)&params[0] = X;
			*(Object::Vector*)&params[12] = Y;
			*(Object::Vector*)&params[24] = Z;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[36];
		}
		Object::Rotator RotRand(bool bRoll)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.RotRand");
			byte params[16] = { NULL };
			*(bool*)&params[0] = bRoll;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[4];
		}
		Object::Vector GetRotatorAxis(Object::Rotator A, int Axis)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetRotatorAxis");
			byte params[28] = { NULL };
			*(Object::Rotator*)&params[0] = A;
			*(int*)&params[12] = Axis;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[16];
		}
		void GetUnAxes(Object::Rotator A, Object::Vector& X, Object::Vector& Y, Object::Vector& Z)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetUnAxes");
			byte params[48] = { NULL };
			*(Object::Rotator*)&params[0] = A;
			*(Object::Vector*)&params[12] = X;
			*(Object::Vector*)&params[24] = Y;
			*(Object::Vector*)&params[36] = Z;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			X = *(Object::Vector*)&params[12];
			Y = *(Object::Vector*)&params[24];
			Z = *(Object::Vector*)&params[36];
		}
		void GetAxes(Object::Rotator A, Object::Vector& X, Object::Vector& Y, Object::Vector& Z)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GetAxes");
			byte params[48] = { NULL };
			*(Object::Rotator*)&params[0] = A;
			*(Object::Vector*)&params[12] = X;
			*(Object::Vector*)&params[24] = Y;
			*(Object::Vector*)&params[36] = Z;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			X = *(Object::Vector*)&params[12];
			Y = *(Object::Vector*)&params[24];
			Z = *(Object::Vector*)&params[36];
		}
		bool ClockwiseFrom_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ClockwiseFrom_IntInt");
			byte params[12] = { NULL };
			*(int*)&params[0] = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		Object::Rotator SubtractEqual_RotatorRotator(Object::Rotator& A, Object::Rotator B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.SubtractEqual_RotatorRotator");
			byte params[36] = { NULL };
			*(Object::Rotator*)&params[0] = A;
			*(Object::Rotator*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(Object::Rotator*)&params[0];
			return *(Object::Rotator*)&params[24];
		}
		Object::Rotator AddEqual_RotatorRotator(Object::Rotator& A, Object::Rotator B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.AddEqual_RotatorRotator");
			byte params[36] = { NULL };
			*(Object::Rotator*)&params[0] = A;
			*(Object::Rotator*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(Object::Rotator*)&params[0];
			return *(Object::Rotator*)&params[24];
		}
		Object::Rotator Subtract_RotatorRotator(Object::Rotator A, Object::Rotator B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Subtract_RotatorRotator");
			byte params[36] = { NULL };
			*(Object::Rotator*)&params[0] = A;
			*(Object::Rotator*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[24];
		}
		Object::Rotator Add_RotatorRotator(Object::Rotator A, Object::Rotator B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Add_RotatorRotator");
			byte params[36] = { NULL };
			*(Object::Rotator*)&params[0] = A;
			*(Object::Rotator*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[24];
		}
		Object::Rotator DivideEqual_RotatorFloat(Object::Rotator& A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.DivideEqual_RotatorFloat");
			byte params[28] = { NULL };
			*(Object::Rotator*)&params[0] = A;
			*(float*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(Object::Rotator*)&params[0];
			return *(Object::Rotator*)&params[16];
		}
		Object::Rotator MultiplyEqual_RotatorFloat(Object::Rotator& A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MultiplyEqual_RotatorFloat");
			byte params[28] = { NULL };
			*(Object::Rotator*)&params[0] = A;
			*(float*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(Object::Rotator*)&params[0];
			return *(Object::Rotator*)&params[16];
		}
		Object::Rotator Divide_RotatorFloat(Object::Rotator A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Divide_RotatorFloat");
			byte params[28] = { NULL };
			*(Object::Rotator*)&params[0] = A;
			*(float*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[16];
		}
		Object::Rotator Multiply_FloatRotator(float A, Object::Rotator B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Multiply_FloatRotator");
			byte params[28] = { NULL };
			*(float*)&params[0] = A;
			*(Object::Rotator*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[16];
		}
		Object::Rotator Multiply_RotatorFloat(Object::Rotator A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Multiply_RotatorFloat");
			byte params[28] = { NULL };
			*(Object::Rotator*)&params[0] = A;
			*(float*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[16];
		}
		bool NotEqual_RotatorRotator(Object::Rotator A, Object::Rotator B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.NotEqual_RotatorRotator");
			byte params[28] = { NULL };
			*(Object::Rotator*)&params[0] = A;
			*(Object::Rotator*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool EqualEqual_RotatorRotator(Object::Rotator A, Object::Rotator B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.EqualEqual_RotatorRotator");
			byte params[28] = { NULL };
			*(Object::Rotator*)&params[0] = A;
			*(Object::Rotator*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool InCylinder(Object::Vector Origin, Object::Rotator Dir, float Width, Object::Vector A, bool bIgnoreZ)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.InCylinder");
			byte params[48] = { NULL };
			*(Object::Vector*)&params[0] = Origin;
			*(Object::Rotator*)&params[12] = Dir;
			*(float*)&params[24] = Width;
			*(Object::Vector*)&params[28] = A;
			*(bool*)&params[40] = bIgnoreZ;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[44];
		}
		float NoZDot(Object::Vector A, Object::Vector B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.NoZDot");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = A;
			*(Object::Vector*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[24];
		}
		Object::Vector ClampLength(Object::Vector V, float MaxLength)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ClampLength");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = V;
			*(float*)&params[12] = MaxLength;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[16];
		}
		Object::Vector VInterpTo(Object::Vector Current, Object::Vector Target, float DeltaTime, float InterpSpeed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.VInterpTo");
			byte params[44] = { NULL };
			*(Object::Vector*)&params[0] = Current;
			*(Object::Vector*)&params[12] = Target;
			*(float*)&params[24] = DeltaTime;
			*(float*)&params[28] = InterpSpeed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[32];
		}
		bool IsZero(Object::Vector A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.IsZero");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		Object::Vector ProjectOnTo(Object::Vector X, Object::Vector Y)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ProjectOnTo");
			byte params[36] = { NULL };
			*(Object::Vector*)&params[0] = X;
			*(Object::Vector*)&params[12] = Y;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[24];
		}
		Object::Vector MirrorVectorByNormal(Object::Vector InVect, Object::Vector InNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MirrorVectorByNormal");
			byte params[36] = { NULL };
			*(Object::Vector*)&params[0] = InVect;
			*(Object::Vector*)&params[12] = InNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[24];
		}
		Object::Vector VRandCone2(Object::Vector Dir, float HorizontalConeHalfAngleRadians, float VerticalConeHalfAngleRadians)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.VRandCone2");
			byte params[32] = { NULL };
			*(Object::Vector*)&params[0] = Dir;
			*(float*)&params[12] = HorizontalConeHalfAngleRadians;
			*(float*)&params[16] = VerticalConeHalfAngleRadians;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[20];
		}
		Object::Vector VRandCone(Object::Vector Dir, float ConeHalfAngleRadians)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.VRandCone");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = Dir;
			*(float*)&params[12] = ConeHalfAngleRadians;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[16];
		}
		Object::Vector VRand()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.VRand");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[0];
		}
		Object::Vector VSmerp(Object::Vector A, Object::Vector B, float Alpha)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.VSmerp");
			byte params[40] = { NULL };
			*(Object::Vector*)&params[0] = A;
			*(Object::Vector*)&params[12] = B;
			*(float*)&params[24] = Alpha;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[28];
		}
		Object::Vector VLerp(Object::Vector A, Object::Vector B, float Alpha)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.VLerp");
			byte params[40] = { NULL };
			*(Object::Vector*)&params[0] = A;
			*(Object::Vector*)&params[12] = B;
			*(float*)&params[24] = Alpha;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[28];
		}
		Object::Vector Normal(Object::Vector A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Normal");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[12];
		}
		float VSizeSq2D(Object::Vector A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.VSizeSq2D");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		float VSizeSq(Object::Vector A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.VSizeSq");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		float VSize2D(Object::Vector A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.VSize2D");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		float VSize(Object::Vector A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.VSize");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		Object::Vector SubtractEqual_VectorVector(Object::Vector& A, Object::Vector B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.SubtractEqual_VectorVector");
			byte params[36] = { NULL };
			*(Object::Vector*)&params[0] = A;
			*(Object::Vector*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(Object::Vector*)&params[0];
			return *(Object::Vector*)&params[24];
		}
		Object::Vector AddEqual_VectorVector(Object::Vector& A, Object::Vector B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.AddEqual_VectorVector");
			byte params[36] = { NULL };
			*(Object::Vector*)&params[0] = A;
			*(Object::Vector*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(Object::Vector*)&params[0];
			return *(Object::Vector*)&params[24];
		}
		Object::Vector DivideEqual_VectorFloat(Object::Vector& A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.DivideEqual_VectorFloat");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = A;
			*(float*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(Object::Vector*)&params[0];
			return *(Object::Vector*)&params[16];
		}
		Object::Vector MultiplyEqual_VectorVector(Object::Vector& A, Object::Vector B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MultiplyEqual_VectorVector");
			byte params[36] = { NULL };
			*(Object::Vector*)&params[0] = A;
			*(Object::Vector*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(Object::Vector*)&params[0];
			return *(Object::Vector*)&params[24];
		}
		Object::Vector MultiplyEqual_VectorFloat(Object::Vector& A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MultiplyEqual_VectorFloat");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = A;
			*(float*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(Object::Vector*)&params[0];
			return *(Object::Vector*)&params[16];
		}
		Object::Vector Cross_VectorVector(Object::Vector A, Object::Vector B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Cross_VectorVector");
			byte params[36] = { NULL };
			*(Object::Vector*)&params[0] = A;
			*(Object::Vector*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[24];
		}
		float Dot_VectorVector(Object::Vector A, Object::Vector B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Dot_VectorVector");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = A;
			*(Object::Vector*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[24];
		}
		bool NotEqual_VectorVector(Object::Vector A, Object::Vector B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.NotEqual_VectorVector");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = A;
			*(Object::Vector*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool EqualEqual_VectorVector(Object::Vector A, Object::Vector B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.EqualEqual_VectorVector");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = A;
			*(Object::Vector*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		Object::Vector GreaterGreater_VectorRotator(Object::Vector A, Object::Rotator B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GreaterGreater_VectorRotator");
			byte params[36] = { NULL };
			*(Object::Vector*)&params[0] = A;
			*(Object::Rotator*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[24];
		}
		Object::Vector LessLess_VectorRotator(Object::Vector A, Object::Rotator B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.LessLess_VectorRotator");
			byte params[36] = { NULL };
			*(Object::Vector*)&params[0] = A;
			*(Object::Rotator*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[24];
		}
		Object::Vector Subtract_VectorVector(Object::Vector A, Object::Vector B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Subtract_VectorVector");
			byte params[36] = { NULL };
			*(Object::Vector*)&params[0] = A;
			*(Object::Vector*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[24];
		}
		Object::Vector Add_VectorVector(Object::Vector A, Object::Vector B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Add_VectorVector");
			byte params[36] = { NULL };
			*(Object::Vector*)&params[0] = A;
			*(Object::Vector*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[24];
		}
		Object::Vector Divide_VectorFloat(Object::Vector A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Divide_VectorFloat");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = A;
			*(float*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[16];
		}
		Object::Vector Multiply_VectorVector(Object::Vector A, Object::Vector B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Multiply_VectorVector");
			byte params[36] = { NULL };
			*(Object::Vector*)&params[0] = A;
			*(Object::Vector*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[24];
		}
		Object::Vector Multiply_FloatVector(float A, Object::Vector B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Multiply_FloatVector");
			byte params[28] = { NULL };
			*(float*)&params[0] = A;
			*(Object::Vector*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[16];
		}
		Object::Vector Multiply_VectorFloat(Object::Vector A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Multiply_VectorFloat");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = A;
			*(float*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[16];
		}
		Object::Vector Subtract_PreVector(Object::Vector A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Subtract_PreVector");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[12];
		}
		float FInterpConstantTo(float Current, float Target, float DeltaTime, float InterpSpeed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.FInterpConstantTo");
			byte params[20] = { NULL };
			*(float*)&params[0] = Current;
			*(float*)&params[4] = Target;
			*(float*)&params[8] = DeltaTime;
			*(float*)&params[12] = InterpSpeed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[16];
		}
		float FPctByRange(float Value, float InMin, float InMax)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.FPctByRange");
			byte params[16] = { NULL };
			*(float*)&params[0] = Value;
			*(float*)&params[4] = InMin;
			*(float*)&params[8] = InMax;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		float RandRange(float InMin, float InMax)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.RandRange");
			byte params[12] = { NULL };
			*(float*)&params[0] = InMin;
			*(float*)&params[4] = InMax;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		float FInterpEaseInOut(float A, float B, float Alpha, float Exp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.FInterpEaseInOut");
			byte params[20] = { NULL };
			*(float*)&params[0] = A;
			*(float*)&params[4] = B;
			*(float*)&params[8] = Alpha;
			*(float*)&params[12] = Exp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[16];
		}
		float FInterpEaseOut(float A, float B, float Alpha, float Exp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.FInterpEaseOut");
			byte params[20] = { NULL };
			*(float*)&params[0] = A;
			*(float*)&params[4] = B;
			*(float*)&params[8] = Alpha;
			*(float*)&params[12] = Exp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[16];
		}
		float FInterpEaseIn(float A, float B, float Alpha, float Exp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.FInterpEaseIn");
			byte params[20] = { NULL };
			*(float*)&params[0] = A;
			*(float*)&params[4] = B;
			*(float*)&params[8] = Alpha;
			*(float*)&params[12] = Exp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[16];
		}
		float FCubicInterp(float P0, float T0, float P1, float T1, float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.FCubicInterp");
			byte params[24] = { NULL };
			*(float*)&params[0] = P0;
			*(float*)&params[4] = T0;
			*(float*)&params[8] = P1;
			*(float*)&params[12] = T1;
			*(float*)&params[16] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[20];
		}
		int FCeil(float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.FCeil");
			byte params[8] = { NULL };
			*(float*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int FFloor(float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.FFloor");
			byte params[8] = { NULL };
			*(float*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int Round(float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Round");
			byte params[8] = { NULL };
			*(float*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		float Lerp(float A, float B, float Alpha)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Lerp");
			byte params[16] = { NULL };
			*(float*)&params[0] = A;
			*(float*)&params[4] = B;
			*(float*)&params[8] = Alpha;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		float FClamp(float V, float A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.FClamp");
			byte params[16] = { NULL };
			*(float*)&params[0] = V;
			*(float*)&params[4] = A;
			*(float*)&params[8] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		float FMax(float A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.FMax");
			byte params[12] = { NULL };
			*(float*)&params[0] = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		float FMin(float A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.FMin");
			byte params[12] = { NULL };
			*(float*)&params[0] = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		float FRand()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.FRand");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		float Square(float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Square");
			byte params[8] = { NULL };
			*(float*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		float Sqrt(float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Sqrt");
			byte params[8] = { NULL };
			*(float*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		float Loge(float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Loge");
			byte params[8] = { NULL };
			*(float*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		float Exp(float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Exp");
			byte params[8] = { NULL };
			*(float*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		float Atan2(float A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Atan2");
			byte params[12] = { NULL };
			*(float*)&params[0] = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		float Atan(float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Atan");
			byte params[8] = { NULL };
			*(float*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		float Tan(float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Tan");
			byte params[8] = { NULL };
			*(float*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		float Cos(float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Cos");
			byte params[8] = { NULL };
			*(float*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		float Asin(float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Asin");
			byte params[8] = { NULL };
			*(float*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		float Sin(float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Sin");
			byte params[8] = { NULL };
			*(float*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		float Abs(float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Abs");
			byte params[8] = { NULL };
			*(float*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		float SubtractEqual_FloatFloat(float& A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.SubtractEqual_FloatFloat");
			byte params[12] = { NULL };
			*(float*)&params[0] = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(float*)&params[0];
			return *(float*)&params[8];
		}
		float AddEqual_FloatFloat(float& A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.AddEqual_FloatFloat");
			byte params[12] = { NULL };
			*(float*)&params[0] = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(float*)&params[0];
			return *(float*)&params[8];
		}
		float DivideEqual_FloatFloat(float& A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.DivideEqual_FloatFloat");
			byte params[12] = { NULL };
			*(float*)&params[0] = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(float*)&params[0];
			return *(float*)&params[8];
		}
		float MultiplyEqual_FloatFloat(float& A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MultiplyEqual_FloatFloat");
			byte params[12] = { NULL };
			*(float*)&params[0] = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(float*)&params[0];
			return *(float*)&params[8];
		}
		bool NotEqual_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.NotEqual_FloatFloat");
			byte params[12] = { NULL };
			*(float*)&params[0] = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool ComplementEqual_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ComplementEqual_FloatFloat");
			byte params[12] = { NULL };
			*(float*)&params[0] = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool EqualEqual_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.EqualEqual_FloatFloat");
			byte params[12] = { NULL };
			*(float*)&params[0] = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool GreaterEqual_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GreaterEqual_FloatFloat");
			byte params[12] = { NULL };
			*(float*)&params[0] = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool LessEqual_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.LessEqual_FloatFloat");
			byte params[12] = { NULL };
			*(float*)&params[0] = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool Greater_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Greater_FloatFloat");
			byte params[12] = { NULL };
			*(float*)&params[0] = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool Less_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Less_FloatFloat");
			byte params[12] = { NULL };
			*(float*)&params[0] = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		float Subtract_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Subtract_FloatFloat");
			byte params[12] = { NULL };
			*(float*)&params[0] = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		float Add_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Add_FloatFloat");
			byte params[12] = { NULL };
			*(float*)&params[0] = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		float Percent_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Percent_FloatFloat");
			byte params[12] = { NULL };
			*(float*)&params[0] = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		float Divide_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Divide_FloatFloat");
			byte params[12] = { NULL };
			*(float*)&params[0] = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		float Multiply_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Multiply_FloatFloat");
			byte params[12] = { NULL };
			*(float*)&params[0] = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		float MultiplyMultiply_FloatFloat(float Base, float Exp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MultiplyMultiply_FloatFloat");
			byte params[12] = { NULL };
			*(float*)&params[0] = Base;
			*(float*)&params[4] = Exp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		float Subtract_PreFloat(float A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Subtract_PreFloat");
			byte params[8] = { NULL };
			*(float*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		ScriptString* ToHex(int A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.ToHex");
			byte params[16] = { NULL };
			*(int*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		int Clamp(int V, int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Clamp");
			byte params[16] = { NULL };
			*(int*)&params[0] = V;
			*(int*)&params[4] = A;
			*(int*)&params[8] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		int Max(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Max");
			byte params[12] = { NULL };
			*(int*)&params[0] = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int Min(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Min");
			byte params[12] = { NULL };
			*(int*)&params[0] = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int Rand(int Max)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Rand");
			byte params[8] = { NULL };
			*(int*)&params[0] = Max;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int SubtractSubtract_Int(int& A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.SubtractSubtract_Int");
			byte params[8] = { NULL };
			*(int*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(int*)&params[0];
			return *(int*)&params[4];
		}
		int AddAdd_Int(int& A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.AddAdd_Int");
			byte params[8] = { NULL };
			*(int*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(int*)&params[0];
			return *(int*)&params[4];
		}
		int SubtractSubtract_PreInt(int& A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.SubtractSubtract_PreInt");
			byte params[8] = { NULL };
			*(int*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(int*)&params[0];
			return *(int*)&params[4];
		}
		int AddAdd_PreInt(int& A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.AddAdd_PreInt");
			byte params[8] = { NULL };
			*(int*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(int*)&params[0];
			return *(int*)&params[4];
		}
		int SubtractEqual_IntInt(int& A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.SubtractEqual_IntInt");
			byte params[12] = { NULL };
			*(int*)&params[0] = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(int*)&params[0];
			return *(int*)&params[8];
		}
		int AddEqual_IntInt(int& A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.AddEqual_IntInt");
			byte params[12] = { NULL };
			*(int*)&params[0] = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(int*)&params[0];
			return *(int*)&params[8];
		}
		int DivideEqual_IntFloat(int& A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.DivideEqual_IntFloat");
			byte params[12] = { NULL };
			*(int*)&params[0] = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(int*)&params[0];
			return *(int*)&params[8];
		}
		int MultiplyEqual_IntFloat(int& A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MultiplyEqual_IntFloat");
			byte params[12] = { NULL };
			*(int*)&params[0] = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(int*)&params[0];
			return *(int*)&params[8];
		}
		int Or_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Or_IntInt");
			byte params[12] = { NULL };
			*(int*)&params[0] = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int Xor_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Xor_IntInt");
			byte params[12] = { NULL };
			*(int*)&params[0] = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int And_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.And_IntInt");
			byte params[12] = { NULL };
			*(int*)&params[0] = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		bool NotEqual_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.NotEqual_IntInt");
			byte params[12] = { NULL };
			*(int*)&params[0] = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool EqualEqual_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.EqualEqual_IntInt");
			byte params[12] = { NULL };
			*(int*)&params[0] = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool GreaterEqual_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GreaterEqual_IntInt");
			byte params[12] = { NULL };
			*(int*)&params[0] = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool LessEqual_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.LessEqual_IntInt");
			byte params[12] = { NULL };
			*(int*)&params[0] = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool Greater_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Greater_IntInt");
			byte params[12] = { NULL };
			*(int*)&params[0] = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool Less_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Less_IntInt");
			byte params[12] = { NULL };
			*(int*)&params[0] = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		int GreaterGreaterGreater_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GreaterGreaterGreater_IntInt");
			byte params[12] = { NULL };
			*(int*)&params[0] = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int GreaterGreater_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.GreaterGreater_IntInt");
			byte params[12] = { NULL };
			*(int*)&params[0] = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int LessLess_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.LessLess_IntInt");
			byte params[12] = { NULL };
			*(int*)&params[0] = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int Subtract_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Subtract_IntInt");
			byte params[12] = { NULL };
			*(int*)&params[0] = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int Add_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Add_IntInt");
			byte params[12] = { NULL };
			*(int*)&params[0] = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int Percent_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Percent_IntInt");
			byte params[12] = { NULL };
			*(int*)&params[0] = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int Divide_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Divide_IntInt");
			byte params[12] = { NULL };
			*(int*)&params[0] = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int Multiply_IntInt(int A, int B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Multiply_IntInt");
			byte params[12] = { NULL };
			*(int*)&params[0] = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int Subtract_PreInt(int A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Subtract_PreInt");
			byte params[8] = { NULL };
			*(int*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int Complement_PreInt(int A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Complement_PreInt");
			byte params[8] = { NULL };
			*(int*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		byte SubtractSubtract_Byte(byte& A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.SubtractSubtract_Byte");
			byte params[2] = { NULL };
			params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = params[0];
			return params[1];
		}
		byte AddAdd_Byte(byte& A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.AddAdd_Byte");
			byte params[2] = { NULL };
			params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = params[0];
			return params[1];
		}
		byte SubtractSubtract_PreByte(byte& A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.SubtractSubtract_PreByte");
			byte params[2] = { NULL };
			params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = params[0];
			return params[1];
		}
		byte AddAdd_PreByte(byte& A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.AddAdd_PreByte");
			byte params[2] = { NULL };
			params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = params[0];
			return params[1];
		}
		byte SubtractEqual_ByteByte(byte& A, byte B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.SubtractEqual_ByteByte");
			byte params[3] = { NULL };
			params[0] = A;
			params[1] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = params[0];
			return params[2];
		}
		byte AddEqual_ByteByte(byte& A, byte B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.AddEqual_ByteByte");
			byte params[3] = { NULL };
			params[0] = A;
			params[1] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = params[0];
			return params[2];
		}
		byte DivideEqual_ByteByte(byte& A, byte B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.DivideEqual_ByteByte");
			byte params[3] = { NULL };
			params[0] = A;
			params[1] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = params[0];
			return params[2];
		}
		byte MultiplyEqual_ByteFloat(byte& A, float B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MultiplyEqual_ByteFloat");
			byte params[6] = { NULL };
			params[0] = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = params[0];
			return params[8];
		}
		byte MultiplyEqual_ByteByte(byte& A, byte B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.MultiplyEqual_ByteByte");
			byte params[3] = { NULL };
			params[0] = A;
			params[1] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = params[0];
			return params[2];
		}
		bool OrOr_BoolBool(bool A, bool B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.OrOr_BoolBool");
			byte params[12] = { NULL };
			*(bool*)&params[0] = A;
			*(bool*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool XorXor_BoolBool(bool A, bool B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.XorXor_BoolBool");
			byte params[12] = { NULL };
			*(bool*)&params[0] = A;
			*(bool*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool AndAnd_BoolBool(bool A, bool B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.AndAnd_BoolBool");
			byte params[12] = { NULL };
			*(bool*)&params[0] = A;
			*(bool*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool NotEqual_BoolBool(bool A, bool B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.NotEqual_BoolBool");
			byte params[12] = { NULL };
			*(bool*)&params[0] = A;
			*(bool*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool EqualEqual_BoolBool(bool A, bool B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.EqualEqual_BoolBool");
			byte params[12] = { NULL };
			*(bool*)&params[0] = A;
			*(bool*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool Not_PreBool(bool A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Object.Not_PreBool");
			byte params[8] = { NULL };
			*(bool*)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
	const float Object::InvAspectRatio16x9 = 0.56249f;
	const float Object::InvAspectRatio5x4 = 0.8f;
	const float Object::InvAspectRatio4x3 = 0.75f;
	const float Object::AspectRatio16x9 = 1.77778f;
	const float Object::AspectRatio5x4 = 1.25f;
	const float Object::AspectRatio4x3 = 1.33333f;
	const float Object::UnrRotToDeg = 0.00549316540360483f;
	const float Object::DegToUnrRot = 182.0444f;
	const float Object::RadToUnrRot = 10430.3783504704527f;
	const float Object::UnrRotToRad = 0.00009587379924285f;
	const float Object::DegToRad = 0.017453292519943296f;
	const float Object::RadToDeg = 57.295779513082321600f;
	const float Object::Pi = 3.1415926535897932f;
}
#undef ADD_STRUCT
#undef ADD_OBJECT
