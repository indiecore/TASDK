#pragma once
#include "Core.Object.h"
#include "GFxUI.GFxMoviePlayer.h"
#include "Engine.TranslationContext.h"
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
namespace UnrealScript
{
	class GFxObject : public Object
	{
	public:
		struct ASDisplayInfo
		{
		public:
			ADD_BOOL(hasVisible, 40, 0x800)
			ADD_BOOL(hasAlpha, 40, 0x400)
			ADD_BOOL(hasZScale, 40, 0x200)
			ADD_BOOL(hasYScale, 40, 0x100)
			ADD_BOOL(hasXScale, 40, 0x80)
			ADD_BOOL(hasYRotation, 40, 0x40)
			ADD_BOOL(hasXRotation, 40, 0x20)
			ADD_BOOL(hasRotation, 40, 0x10)
			ADD_BOOL(hasZ, 40, 0x8)
			ADD_BOOL(hasY, 40, 0x4)
			ADD_BOOL(hasX, 40, 0x2)
			ADD_BOOL(Visible, 40, 0x1)
			ADD_STRUCT(float, Alpha, 36)
			ADD_STRUCT(float, ZScale, 32)
			ADD_STRUCT(float, YScale, 28)
			ADD_STRUCT(float, XScale, 24)
			ADD_STRUCT(float, YRotation, 20)
			ADD_STRUCT(float, XRotation, 16)
			ADD_STRUCT(float, Rotation, 12)
			ADD_STRUCT(float, Z, 8)
			ADD_STRUCT(float, Y, 4)
			ADD_STRUCT(float, X, 0)
		};
		struct ASColorTransform
		{
		public:
			ADD_STRUCT(Object::LinearColor, Add, 16)
			ADD_STRUCT(Object::LinearColor, Multiply, 0)
		};
		ADD_STRUCT(ScriptArray<GFxMoviePlayer::GFxWidgetBinding>, SubWidgetBindings, 108)
		ADD_STRUCT(int, Value, 60)
		GFxMoviePlayer::ASValue Get(ScriptString* Member)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30000);
			byte params[36] = { NULL };
			*(ScriptString**)params = Member;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(GFxMoviePlayer::ASValue*)&params[12];
		}
		bool GetBool(ScriptString* Member)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30003);
			byte params[16] = { NULL };
			*(ScriptString**)params = Member;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		float GetFloat(ScriptString* Member)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30006);
			byte params[16] = { NULL };
			*(ScriptString**)params = Member;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		ScriptString* GetString(ScriptString* Member)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30009);
			byte params[24] = { NULL };
			*(ScriptString**)params = Member;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		class GFxObject* GetObject(ScriptString* Member, ScriptClass* Type)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30012);
			byte params[20] = { NULL };
			*(ScriptString**)params = Member;
			*(ScriptClass**)&params[12] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[16];
		}
		void Set(ScriptString* Member, GFxMoviePlayer::ASValue Arg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30016);
			byte params[36] = { NULL };
			*(ScriptString**)params = Member;
			*(GFxMoviePlayer::ASValue*)&params[12] = Arg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBool(ScriptString* Member, bool B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30019);
			byte params[16] = { NULL };
			*(ScriptString**)params = Member;
			*(bool*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFloat(ScriptString* Member, float F)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30022);
			byte params[16] = { NULL };
			*(ScriptString**)params = Member;
			*(float*)&params[12] = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetString(ScriptString* Member, ScriptString* S, class TranslationContext* InContext)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30025);
			byte params[28] = { NULL };
			*(ScriptString**)params = Member;
			*(ScriptString**)&params[12] = S;
			*(class TranslationContext**)&params[24] = InContext;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetObject(ScriptString* Member, class GFxObject* val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30029);
			byte params[16] = { NULL };
			*(ScriptString**)params = Member;
			*(class GFxObject**)&params[12] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFunction(ScriptString* Member, class Object* context, ScriptName fname)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30032);
			byte params[24] = { NULL };
			*(ScriptString**)params = Member;
			*(class Object**)&params[12] = context;
			*(ScriptName*)&params[16] = fname;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* TranslateString(ScriptString* StringToTranslate, class TranslationContext* InContext)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30036);
			byte params[28] = { NULL };
			*(ScriptString**)params = StringToTranslate;
			*(class TranslationContext**)&params[12] = InContext;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[16];
		}
		GFxObject::ASDisplayInfo GetDisplayInfo()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30040);
			byte params[44] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(GFxObject::ASDisplayInfo*)params;
		}
		bool GetPosition(float& X, float& Y)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30042);
			byte params[12] = { NULL };
			*(float*)params = X;
			*(float*)&params[4] = Y;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			X = *(float*)params;
			Y = *(float*)&params[4];
			return *(bool*)&params[8];
		}
		GFxObject::ASColorTransform GetColorTransform()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30046);
			byte params[32] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(GFxObject::ASColorTransform*)params;
		}
		Object::Matrix GetDisplayMatrix()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30048);
			byte params[64] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Matrix*)params;
		}
		void SetDisplayInfo(GFxObject::ASDisplayInfo D)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30050);
			byte params[44] = { NULL };
			*(GFxObject::ASDisplayInfo*)params = D;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPosition(float X, float Y)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30052);
			byte params[8] = { NULL };
			*(float*)params = X;
			*(float*)&params[4] = Y;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetColorTransform(GFxObject::ASColorTransform cxform)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30055);
			byte params[32] = { NULL };
			*(GFxObject::ASColorTransform*)params = cxform;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetDisplayMatrix(Object::Matrix M)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30057);
			byte params[64] = { NULL };
			*(Object::Matrix*)params = M;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetDisplayMatrix3D(Object::Matrix M)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30059);
			byte params[64] = { NULL };
			*(Object::Matrix*)params = M;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetVisible(bool Visible)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30061);
			byte params[4] = { NULL };
			*(bool*)params = Visible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetText()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30063);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		void SetText(ScriptString* Text, class TranslationContext* InContext)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30065);
			byte params[16] = { NULL };
			*(ScriptString**)params = Text;
			*(class TranslationContext**)&params[12] = InContext;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		GFxMoviePlayer::ASValue GetElement(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30068);
			byte params[28] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(GFxMoviePlayer::ASValue*)&params[4];
		}
		class GFxObject* GetElementObject(int Index, ScriptClass* Type)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30071);
			byte params[12] = { NULL };
			*(int*)params = Index;
			*(ScriptClass**)&params[4] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[8];
		}
		bool GetElementBool(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30075);
			byte params[8] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		float GetElementFloat(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30078);
			byte params[8] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		ScriptString* GetElementString(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30081);
			byte params[16] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		void SetElement(int Index, GFxMoviePlayer::ASValue Arg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30084);
			byte params[28] = { NULL };
			*(int*)params = Index;
			*(GFxMoviePlayer::ASValue*)&params[4] = Arg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetElementObject(int Index, class GFxObject* val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30087);
			byte params[8] = { NULL };
			*(int*)params = Index;
			*(class GFxObject**)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetElementBool(int Index, bool B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30090);
			byte params[8] = { NULL };
			*(int*)params = Index;
			*(bool*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetElementFloat(int Index, float F)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30093);
			byte params[8] = { NULL };
			*(int*)params = Index;
			*(float*)&params[4] = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetElementString(int Index, ScriptString* S)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30096);
			byte params[16] = { NULL };
			*(int*)params = Index;
			*(ScriptString**)&params[4] = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		GFxObject::ASDisplayInfo GetElementDisplayInfo(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30099);
			byte params[48] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(GFxObject::ASDisplayInfo*)&params[4];
		}
		Object::Matrix GetElementDisplayMatrix(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30102);
			byte params[68] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Matrix*)&params[16];
		}
		void SetElementDisplayInfo(int Index, GFxObject::ASDisplayInfo D)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30105);
			byte params[48] = { NULL };
			*(int*)params = Index;
			*(GFxObject::ASDisplayInfo*)&params[4] = D;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetElementDisplayMatrix(int Index, Object::Matrix M)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30108);
			byte params[68] = { NULL };
			*(int*)params = Index;
			*(Object::Matrix*)&params[16] = M;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetElementVisible(int Index, bool Visible)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30111);
			byte params[8] = { NULL };
			*(int*)params = Index;
			*(bool*)&params[4] = Visible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetElementPosition(int Index, float X, float Y)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30114);
			byte params[12] = { NULL };
			*(int*)params = Index;
			*(float*)&params[4] = X;
			*(float*)&params[8] = Y;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetElementColorTransform(int Index, GFxObject::ASColorTransform cxform)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30118);
			byte params[36] = { NULL };
			*(int*)params = Index;
			*(GFxObject::ASColorTransform*)&params[4] = cxform;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		GFxMoviePlayer::ASValue GetElementMember(int Index, ScriptString* Member)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30121);
			byte params[40] = { NULL };
			*(int*)params = Index;
			*(ScriptString**)&params[4] = Member;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(GFxMoviePlayer::ASValue*)&params[16];
		}
		class GFxObject* GetElementMemberObject(int Index, ScriptString* Member, ScriptClass* Type)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30125);
			byte params[24] = { NULL };
			*(int*)params = Index;
			*(ScriptString**)&params[4] = Member;
			*(ScriptClass**)&params[16] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[20];
		}
		bool GetElementMemberBool(int Index, ScriptString* Member)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30130);
			byte params[20] = { NULL };
			*(int*)params = Index;
			*(ScriptString**)&params[4] = Member;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		float GetElementMemberFloat(int Index, ScriptString* Member)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30134);
			byte params[20] = { NULL };
			*(int*)params = Index;
			*(ScriptString**)&params[4] = Member;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[16];
		}
		ScriptString* GetElementMemberString(int Index, ScriptString* Member)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30138);
			byte params[28] = { NULL };
			*(int*)params = Index;
			*(ScriptString**)&params[4] = Member;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[16];
		}
		void SetElementMember(int Index, ScriptString* Member, GFxMoviePlayer::ASValue Arg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30142);
			byte params[40] = { NULL };
			*(int*)params = Index;
			*(ScriptString**)&params[4] = Member;
			*(GFxMoviePlayer::ASValue*)&params[16] = Arg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetElementMemberObject(int Index, ScriptString* Member, class GFxObject* val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30146);
			byte params[20] = { NULL };
			*(int*)params = Index;
			*(ScriptString**)&params[4] = Member;
			*(class GFxObject**)&params[16] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetElementMemberBool(int Index, ScriptString* Member, bool B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30150);
			byte params[20] = { NULL };
			*(int*)params = Index;
			*(ScriptString**)&params[4] = Member;
			*(bool*)&params[16] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetElementMemberFloat(int Index, ScriptString* Member, float F)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30154);
			byte params[20] = { NULL };
			*(int*)params = Index;
			*(ScriptString**)&params[4] = Member;
			*(float*)&params[16] = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetElementMemberString(int Index, ScriptString* Member, ScriptString* S)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30158);
			byte params[28] = { NULL };
			*(int*)params = Index;
			*(ScriptString**)&params[4] = Member;
			*(ScriptString**)&params[16] = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ActionScriptSetFunction(ScriptString* Member)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30162);
			byte params[12] = { NULL };
			*(ScriptString**)params = Member;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ActionScriptSetFunctionOn(class GFxObject* Target, ScriptString* Member)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30164);
			byte params[16] = { NULL };
			*(class GFxObject**)params = Target;
			*(ScriptString**)&params[4] = Member;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		GFxMoviePlayer::ASValue Invoke(ScriptString* Member, ScriptArray<GFxMoviePlayer::ASValue> args)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30167);
			byte params[48] = { NULL };
			*(ScriptString**)params = Member;
			*(ScriptArray<GFxMoviePlayer::ASValue>*)&params[12] = args;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(GFxMoviePlayer::ASValue*)&params[24];
		}
		void ActionScriptVoid(ScriptString* method)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30172);
			byte params[12] = { NULL };
			*(ScriptString**)params = method;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int ActionScriptInt(ScriptString* method)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30174);
			byte params[16] = { NULL };
			*(ScriptString**)params = method;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		float ActionScriptFloat(ScriptString* method)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30177);
			byte params[16] = { NULL };
			*(ScriptString**)params = method;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		ScriptString* ActionScriptString(ScriptString* method)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30180);
			byte params[24] = { NULL };
			*(ScriptString**)params = method;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		class GFxObject* ActionScriptObject(ScriptString* Path)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30183);
			byte params[16] = { NULL };
			*(ScriptString**)params = Path;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[12];
		}
		ScriptArray<class GFxObject*> ActionScriptArray(ScriptString* Path)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30186);
			byte params[24] = { NULL };
			*(ScriptString**)params = Path;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptArray<class GFxObject*>*)&params[12];
		}
		void GotoAndPlay(ScriptString* frame)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30190);
			byte params[12] = { NULL };
			*(ScriptString**)params = frame;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GotoAndPlayI(int frame)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30192);
			byte params[4] = { NULL };
			*(int*)params = frame;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GotoAndStop(ScriptString* frame)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30194);
			byte params[12] = { NULL };
			*(ScriptString**)params = frame;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GotoAndStopI(int frame)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30196);
			byte params[4] = { NULL };
			*(int*)params = frame;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GFxObject* CreateEmptyMovieClip(ScriptString* instancename, int Depth, ScriptClass* Type)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30198);
			byte params[24] = { NULL };
			*(ScriptString**)params = instancename;
			*(int*)&params[12] = Depth;
			*(ScriptClass**)&params[16] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[20];
		}
		class GFxObject* AttachMovie(ScriptString* symbolname, ScriptString* instancename, int Depth, ScriptClass* Type)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30203);
			byte params[36] = { NULL };
			*(ScriptString**)params = symbolname;
			*(ScriptString**)&params[12] = instancename;
			*(int*)&params[24] = Depth;
			*(ScriptClass**)&params[28] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[32];
		}
		bool WidgetInitialized(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30209);
			byte params[24] = { NULL };
			*(ScriptName*)params = WidgetName;
			*(ScriptName*)&params[8] = WidgetPath;
			*(class GFxObject**)&params[16] = Widget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		bool WidgetUnloaded(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30214);
			byte params[24] = { NULL };
			*(ScriptName*)params = WidgetName;
			*(ScriptName*)&params[8] = WidgetPath;
			*(class GFxObject**)&params[16] = Widget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
